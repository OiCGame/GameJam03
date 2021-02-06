#include	"Item.h"
#include	"ResourceManager.h"

void CItem::Initialize(const CVector2 & pos, ItemType type)
{
	m_Position = pos;

	switch (type)
	{
	case ITEM_LIFE:
		//Texture�̎擾
		m_Texture = &CResourceManager::Singleton().GetTextureList()->at("ItemLife");
		break;
	}

	m_bShow = true;
}

void CItem::Update()
{
	m_Position.y += 3;
}

void CItem::Render()
{
	if (!m_bShow) {
		return;
	}

	m_Texture->Render(m_Position.x, m_Position.y);
}
