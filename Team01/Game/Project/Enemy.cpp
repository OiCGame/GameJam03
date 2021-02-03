#include "Enemy.h"

CEnemy::CEnemy() :
    m_HP(3),
	m_MaxHP(3),
    m_Speed(0.0f),
    m_Dir(90.0f),
    m_FastBulletNo(-1),
    m_bDrow(true),
    m_MoveType(0),
    m_MoveTypeOnPinch(0),
    m_PinchHPRatio(0.0f) {
}

CEnemy::~CEnemy() {
}

void CEnemy::Move(void) {
    m_Move.y = sin(MOF_ToRadian(m_Dir)) * m_Speed;
    m_Move.x = cos(MOF_ToRadian(m_Dir)) * m_Speed;

    m_Pos += m_Move;

    m_Dir += 0.0f;
}


void CEnemy::Move(int type) {
    switch (type) {
        case 0:
            this->Move();
            break;
        case 1:
            m_Pos.x++;
            break;
        case 2:
            m_Pos.y++;
            break;
        case 3:
            this->MoveOutOfWindow();
            break;
        default:
            break;
    } // switch
}

void CEnemy::MoveOutOfWindow(void) {
    auto pos = m_Pos;
    auto size = Mof::CVector2(::g_pFramework->GetWindow()->GetWidth(),
                              ::g_pFramework->GetWindow()->GetHeight());

    float distance = 0.0f;
    float length = size.Length();
    Mof::CVector2 escape_point;

    {
        auto top = Mof::CVector2(pos.x, 0.0f);
        length = Mof::CVector2Utilities::Distance(pos, top);
        if (distance < length) {
            distance = length;
            escape_point = top;
        } // if
    }

    {
        auto bottom = Mof::CVector2(pos.x, size.y);
        length = Mof::CVector2Utilities::Distance(pos, bottom);
        if (distance < length) {
            distance = length;
            escape_point = bottom;
        } // if
    }


    {
        auto left = Mof::CVector2(0.0f, pos.y);
        length = Mof::CVector2Utilities::Distance(pos, left);
        if (distance < length) {
            distance = length;
            escape_point = left;
        } // if
    }

    {
        auto right = Mof::CVector2(size.x, pos.y);
        length = Mof::CVector2Utilities::Distance(pos, right);
        if (length < distance) {
            distance = length;
            escape_point = right;
        } // if
    }

    return;
    /*
    if (m_Pos.x <= escape_point.x) {
        m_Pos.x++;
    } // if
    else if (escape_point.x <= m_Pos.x) {
        m_Pos.x--;
    } // else if
    else if (m_Pos.y <= escape_point.y) {
        m_Pos.y++;
    } // else if
    else if (escape_point.y <= m_Pos.y) {
        m_Pos.y--;
    } // else if
    */

}

Mof::CVector2 CEnemy::GetPosition(void) const {
    return this->m_Pos;
}
void CEnemy::Initialize(const InitParam& param) {
    this->Initialize(param.position, param.move_type, param.move_type_on_pinch, param.pinch_hp_ratio,
                     param.bullet_column, param.bullet_amount, param.amount_set, param.hp_max);
}

void CEnemy::Initialize(Vector2 pos, int move_type, int pinch_move, float ratio, int column, int amount, int set, int hp) {
    m_Pos = pos;
	m_MaxHP = hp;
    m_HP = m_MaxHP;
    m_MoveType = move_type;
    m_MoveTypeOnPinch = pinch_move;
    m_PinchHPRatio = ratio;


    //	m_BulletColumn = rand() % 32;
    m_BulletColumn = column;
    //	m_BulletAmount = rand() % 5 + 1;
    m_BulletAmount = amount;
    //	m_BulletSetAmount = rand() % 5 + 5;
    m_BulletSetAmount = set;

    m_BulletCount = m_BulletColumn * m_BulletAmount * m_BulletSetAmount;

    m_Bullet = new CEnemyBullet[m_BulletCount];


    int dirpat = 360 / m_BulletColumn;
    float dirSplit = rand() % dirpat;

    float dir = 270 - (m_BulletColumn - 1) * dirSplit / 2;

    for (int i = 0; i < m_BulletCount; i++) {
        int dp = i % m_BulletColumn;
        m_Bullet[i].Initialize(dir + dp * dirSplit);
    }

    m_BulletNo = 0;
    m_BulletSetNo = 0;
    m_BulletRemGap = 0;
    m_BulletSetRemGap = 0;
}

void CEnemy::SetTexture(Mof::CTexture* ptr) {
    m_pTexture = ptr;
}

void CEnemy::Update() {
    float ratio = m_HP / m_MaxHP;
    if (m_PinchHPRatio <= ratio) {
        this->Move(m_MoveType);
    } // if
    else {
        this->Move(m_MoveTypeOnPinch);
    } // else


    for (int i = 0; i < m_BulletNo; i++) {
        m_Bullet[i].Update();
    }

    if (m_BulletNo >= m_BulletCount) { return; }
    if (m_BulletSetRemGap > 0) {
        m_BulletSetRemGap--;
        return;
    }
    if (m_BulletRemGap > 0) {
        m_BulletRemGap--;
        return;
    }
    for (int i = 0; i < m_BulletColumn; i++) {
        m_Bullet[m_BulletNo].Generation(m_Pos);
        m_BulletNo++;
    }
    m_BulletRemGap = m_BulletGap;
    m_BulletSetNo++;
    if (m_BulletSetNo >= m_BulletAmount) {
        m_BulletSetNo = 0;
        m_BulletSetRemGap = m_BulletSetGap;
    }
}

int CEnemy::CollitionBullet(CRectangle prec) {
    int col = 0;
    for (int i = 0; i < m_BulletCount; i++) {
        col += m_Bullet[i].Collition(prec);
    }
    return col;
}

void CEnemy::Render() {
#ifdef _DEBUG
    ::CGraphicsUtilities::RenderRect(
        this->GetCollisionRectangle(),
        MOF_ARGB(100, 100, 100, 100)
    );

    auto pos = m_Pos;
    auto size = Mof::CVector2(::g_pFramework->GetWindow()->GetWidth(),
                              ::g_pFramework->GetWindow()->GetHeight());
    auto top = Mof::CVector2(pos.x, 0.0f);
    auto bottom = Mof::CVector2(pos.x, size.y);
    auto left = Mof::CVector2(0.0f, pos.y);
    auto right = Mof::CVector2(size.x, pos.y);
    std::vector<Mof::CVector2> points = {
        top, bottom, left, right
    };

    for (auto& point : points) {
        int color = MOF_ARGB(200, 0, 100, 100);
        ::CGraphicsUtilities::RenderFillCircle(
            Mof::Circle(point, 10), color);
    } // for




#endif // _DEBUG






    m_pTexture->Render(m_Pos.x - m_pTexture->GetWidth() / 2, m_Pos.y - m_pTexture->GetHeight() / 2);
    
	
	

	if (m_HP != m_MaxHP) {
		float hpw = m_pTexture->GetWidth();
		float hpper = m_HP;
		hpper /= m_MaxHP;
		hpw *= hpper;
		CGraphicsUtilities::RenderFillRect(m_Pos.x - m_pTexture->GetWidth() / 2 - 2, m_Pos.y + m_pTexture->GetHeight() / 2 + 2, m_Pos.x + m_pTexture->GetWidth() / 2 + 2, m_Pos.y + m_pTexture->GetHeight() / 2 + 6, MOF_XRGB(0, 0, 0));
		CGraphicsUtilities::RenderFillRect(m_Pos.x - m_pTexture->GetWidth() / 2, m_Pos.y + m_pTexture->GetHeight() / 2 + 3, m_Pos.x - m_pTexture->GetWidth() / 2 + hpw, m_Pos.y + m_pTexture->GetHeight() / 2 + 5, MOF_XRGB(0, 255, 0));
	}

	for (int i = 0; i < m_BulletCount; i++) {
		m_Bullet[i].Render();
	}


	
	for (int i = 0; i < m_BulletCount; i++) {
        m_Bullet[i].Render();
    }
}

void CEnemy::Release() {
    if (m_Bullet) {
        delete[] m_Bullet;
        m_Bullet = NULL;
    }
}

Mof::CRectangle CEnemy::GetCollisionRectangle(void) const {
    auto rect = Mof::CRectangle(0.0f, 0.0f,
                                m_pTexture->GetWidth(), m_pTexture->GetHeight());
    auto size = Vector2(m_pTexture->GetWidth() * 0.5f, m_pTexture->GetHeight() * 0.5f);
    auto pos = m_Pos;
    rect.Translation(m_Pos - size);
    return rect;
}

bool CEnemy::Damage(void) {
    m_HP--;
    if (m_HP <= 0) {
        m_bDrow = false;
        return true;
    } // if
    return false;
}