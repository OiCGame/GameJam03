#include "Enemy.h"

#include "Character.h"


constexpr float kPi = 3.14f;
static float GenerateRandomF(const float min, const float max) {
	std::random_device seed;
	std::mt19937 engine(seed());
	std::uniform_real_distribution<> random(min, max);
	return static_cast<float>(random(engine));
}
inline void Rotate(float& x, float& y, const float angle,
	const float center_x, const float center_y) {
	float rad = kPi * angle / 180.0f;

	float axis_x = x - center_x;
	float axis_y = y - center_y;

	float translate_x = (axis_x)* std::cosf(rad) - (axis_y)* std::sinf(rad);
	float translate_y = (axis_x)* std::sinf(rad) + (axis_y)* std::cosf(rad);

	x = center_x + translate_x;
	y = center_y + translate_y;
};

CEnemy::CEnemy() :
	m_HP(3),
	m_MaxHP(3),
	m_Speed(0.0f),
	m_Dir(90.0f),
	m_FastBulletNo(-1),
	m_bDrow(true),
	m_MoveType(0),
	m_MoveTypeOnPinch(0),
	m_PinchHPRatio(0.0f),
	m_Target(),
	m_StartPositionY(GenerateRandomF(384.0f, 576.0f)),

	m_MoveWaveAmplitudeCount(0.0f),
	m_MoveWaveAmplitudeCountMax(360.0f),
	m_MoveWaveAmplitude(5.0f) {
}

CEnemy::~CEnemy() {
}

void CEnemy::Chase(Mof::CVector2 target) {
	Mof::CVector2 direction = target - m_Pos;
	direction.Normal(direction);

	m_Move += direction;
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
		if (m_StartPositionY < m_Pos.y) {
			m_MoveTypeOnPinch = 5;
			if (m_Pos.x < 512.0f) {
				m_WaveDirection = 270.0f;
			} // if
			else {
				m_WaveDirection = 90.0f;
			} // else
		} // if
		break;
	case 3:
		this->MoveOutOfWindow();
		break;
	case 4:
		this->MoveAssault();
		break;
	case 5:
		this->MoveWave();
		break;
	default:
		break;
	} // switch
}

void CEnemy::MoveOutOfWindow(void) {
	auto pos = m_Pos;
	auto size = Mof::CVector2(::g_pFramework->GetWindow()->GetWidth(),
		::g_pFramework->GetWindow()->GetHeight());

	float distance = size.Length();
	float length;
	Mof::CVector2 escape_point;

	auto top = Mof::CVector2(pos.x, 0.0f);
	length = Mof::CVector2Utilities::Distance(pos, top);
	if (length < distance) {
		distance = length;
		escape_point = top;
	} // if

	auto bottom = Mof::CVector2(pos.x, size.y);
	length = Mof::CVector2Utilities::Distance(pos, bottom);
	if (length < distance) {
		distance = length;
		escape_point = bottom;
	} // if

	auto left = Mof::CVector2(0.0f, pos.y);
	length = Mof::CVector2Utilities::Distance(pos, left);
	if (length < distance) {
		distance = length;
		escape_point = left;
	} // if

	auto right = Mof::CVector2(size.x, pos.y);
	length = Mof::CVector2Utilities::Distance(pos, right);
	if (length < distance) {
		distance = length;
		escape_point = right;
	} // if


	this->Chase(escape_point);
	return;
}

void CEnemy::MoveAssault(void) {
	this->Chase(m_Target);
}

void CEnemy::MoveWave(void) {
	//float direction = 90.0f;

	float accel = 1.0f;

	m_Move.x = std::cosf(m_MoveWaveAmplitudeCount* kPi / 180.0f) * m_MoveWaveAmplitude;
	m_Move.y = accel;
	auto angle = m_WaveDirection;

	Rotate(m_Move.x, m_Move.y,
		angle,
		0, 0);

	m_MoveWaveAmplitudeCount += 5;
	if (m_MoveWaveAmplitudeCount > m_MoveWaveAmplitudeCountMax) {
		m_MoveWaveAmplitudeCount = 0.0f;
	} // if
}

Mof::CVector2 CEnemy::GetPosition(void) const {
	return this->m_Pos;
}

std::vector<std::weak_ptr<CEffect>>& CEnemy::GetCollisionedEffects(void) {
	return this->m_CollisionedEffects;
}
void CEnemy::AddCollisionedEffect(const std::shared_ptr<CEffect>& ptr) {
	m_CollisionedEffects.push_back(ptr);
}

void CEnemy::Initialize(const InitParam& param) {
	this->Initialize(param.position, param.move_type, param.move_type_on_pinch, param.pinch_hp_ratio,
		param.bullet_column, param.bullet_amount, param.reflect_count, param.amount_set, param.hp_max);
}

void CEnemy::Initialize(Vector2 pos, int move_type, int pinch_move, float ratio, int column, int amount, int set, int reflect, int hp) {
	m_Pos = pos;
	m_MaxHP = hp;
	m_HP = m_MaxHP;
	m_MoveType = move_type;
	m_MoveTypeOnPinch = pinch_move;
	m_PinchHPRatio = ratio;


	//	m_BulletColumn = rand() % 1 + 1;
	m_BulletColumn = column;
	//	m_BulletAmount = rand() % 1 + 1;
	m_BulletAmount = amount;
	//	m_BulletSetAmount = rand() % 1 + 6;
	m_BulletSetAmount = set;

	m_BulletCount = m_BulletColumn * m_BulletAmount * m_BulletSetAmount;

	m_Bullet = new CEnemyBullet[m_BulletCount];


	int dirpat = 360 / m_BulletColumn;
	float dirSplit = rand() % dirpat;

	float dir = 90 - (m_BulletColumn - 1) * dirSplit / 2;

	for (int i = 0; i < m_BulletCount; i++) {
		int dp = i % m_BulletColumn;
		m_Bullet[i].Initialize(dir + dp * dirSplit,reflect);
	}

	m_BulletNo = 0;
	m_BulletSetNo = 0;
	m_BulletRemGap = 0;
	m_BulletSetRemGap = 0;
	m_BulletShowCount = 0;
}

void CEnemy::SetTexture(Mof::CTexture* ptr) {
	m_pTexture = ptr;
}

void CEnemy::SetTarget(Mof::CVector2 pos) {
	int range = 100;

	auto temp = pos;
	temp.y = ::g_pFramework->GetWindow()->GetHeight();
	temp.x += GenerateRandom(-range, range);

	m_Target = temp;
}

void CEnemy::Update(bool end) {
	m_Move.x = 0.0f;
	m_Move.y = 0.0f;

	m_BulletShowCount = 0;
	for (int i = 0; i < m_BulletNo; i++) {
		if (!m_Bullet[i].IsShow()) { continue; }
		if (end)
			m_Bullet[i].PopUpdate();
		else
			m_Bullet[i].Update();
		m_BulletShowCount++;
	}


	if (!m_bDrow) { return; }

	float ratio = m_HP / m_MaxHP;
	if (m_PinchHPRatio <= ratio) {
		this->Move(m_MoveType);
	} // if
	else {
		this->Move(m_MoveTypeOnPinch);
	} // else
	m_Pos += m_Move;

	if (m_Pos.x > g_pGraphics->GetTargetWidth() || m_Pos.x +m_pTexture->GetWidth() < 0)
	{
		m_bDrow = false;
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

int CEnemy::CollisionBullet(CRectangle prec) {
	int col = 0;
	for (int i = 0; i < m_BulletCount; i++) {
		col += m_Bullet[i].Collision(prec);
	}
	return col;
}

void CEnemy::Render(bool end) {
	for (int i = 0; i < m_BulletCount; i++) {
		if (end)
			m_Bullet[i].PopRender();
		else
			m_Bullet[i].Render();
	}
	if (!m_bDrow) { return; }
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

bool CEnemy::Damage(int damage_value) {
	m_HP -= damage_value;
	if (m_HP <= 0) {
		m_bDrow = false;
		return true;
	} // if
	return false;
}