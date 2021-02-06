#pragma once
#include	"Mof.h"
#include	"PlayerBullet.h"

//SceneGame‚ÉItem‚Ì”z—ñ‚È‚Ç‚ðì‚Á‚Ä
//SceneGame“à‚ÌUpdate‚É‚ÄItemCollisionCheck()‚ðŒÄ‚Ño‚µ‚ÄŽg‚Á‚Ä‚­‚¾‚³‚¢

enum ItemType
{
	ITEM_LIFE
};


class CItem
{
private:
	CTexture*		m_Texture;
	CVector2		m_Position;

	ItemType		type;
public:
	bool			m_bShow;

	void Initialize(const CVector2& pos, ItemType type = ItemType::ITEM_LIFE);
	void Update();
	void Render();

	bool IsShow() const { return m_bShow; }

	CVector2 GetPostion() const { return m_Position; }
	CCircle GetCircle() const{
		float width = m_Texture->GetWidth() * 0.5f;
		float height = m_Texture->GetHeight() * 0.5f;
		return CCircle(this->GetRectangle().GetCenter(), min(width, height));
	}
	CRectangle GetRectangle() const {
		return CRectangle(m_Position.x, m_Position.y, m_Position.x + m_Texture->GetWidth(), m_Position.y + m_Texture->GetHeight());
	}
	ItemType GetItemType() const { return type; }
};

