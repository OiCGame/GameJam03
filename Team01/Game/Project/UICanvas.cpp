#include "UICanvas.h"

#include <string>


UICanvas::UICanvas() :
    m_Font(),
    m_Score(),
    m_RenderedScore(0),
    m_FontMap() {

    auto size = Mof::CVector2(37.0f, 60.0f);
    for (int i = 0; i < 10; i++) {
		m_FontMap.uvs.emplace(std::string(std::to_string(i)),
                          Mof::CRectangle(size.x * i, 0.0f,
                                          size.x * i + size.x, size.y));
    } // for

    std::string alpha = "abcdefghijklmnopqrstuvwxyz ";
    for (int i = 0; i < alpha.size(); i++) {
        auto str = alpha.substr(i , 1);
		m_FontMap.uvs.emplace(str,
                          Mof::CRectangle(size.x * i, 60.0f,
                                          size.x * i + size.x,60.0f + size.y));
    } // for


}

UICanvas::~UICanvas() {
}

uint32_t UICanvas::GetScore(void) const {
	return this->m_Score;
}

bool UICanvas::Initialize(void) {
    if (!m_Font.Create(64, "ƒƒCƒŠƒI")) {
        return false;
    } // if
    if (!m_FontMap.texture.Load("font.png")) {
        return false;
    } // if
    return true;
}

bool UICanvas::Update(void) {
    // ”ñ•\¦‚Ì‚à‚Ì‚Ííœ
    auto it = std::remove_if(
        m_Labels.begin(),
        m_Labels.end(),
        [](UILabel& label) {
        return label.IsExist() == false;
    });
    m_Labels.erase(it, m_Labels.end());


    if (m_RenderedScore < m_Score) {
        m_RenderedScore++;
    } // if
	else if (m_Score < m_RenderedScore) {
		m_RenderedScore--;
	} // else if


    for (auto& label : m_Labels) {
        label.Update();
    } // for

    return true;
}
bool UICanvas::Render(void) {
//    auto text = std::string("score " + std::to_string(m_RenderedScore));
	auto text = std::string("score " + std::to_string(m_Score));

	auto pos = Mof::CVector2(0.0f, 0.0f);
	for (int i = 0; i < text.size() ; i++) {
		auto key = text.substr(i, 1);
		m_FontMap.texture.Render(pos.x, pos.y, m_FontMap.uvs.at(key));
		pos.x += 40.0f;
	} // for

    for (auto& label : m_Labels) {
        label.Render();
    } // for

    for (auto& image : m_Images) {
        image.Render();
    } // for

    return true;
}

bool UICanvas::Release(void) {
	m_Labels.clear();
	m_Images.clear();
	m_FontMap.texture.Release();
//    m_FonMap .Release();
    return true;
}

void UICanvas::AddScore(uint32_t value) {
    m_Score += value;
}

void UICanvas::SubtractScore(uint32_t value) {
	m_Score -= value;
}

void UICanvas::AddText(const std::string& text, Mof::CVector2 position, int exist) {
    m_Labels.push_back(UILabel(text, position, exist, &m_FontMap));
}

void UICanvas::AddImage(const char* name, Mof::CTexture* texture, Mof::CVector2 pos) {
    m_Images.push_back(UIImage(name, texture, pos));
}
void UICanvas::RemoveImage(const std::string& name) {
    auto it = std::remove_if(
        m_Images.begin(),
        m_Images.end(),
        [&](UIImage image) {
        return image.GetName() == name;
    });
    m_Images.erase(it, m_Images.end());
}