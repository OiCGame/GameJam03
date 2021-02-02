#include "UICanvas.h"

#include <string>


UICanvas::UICanvas() :
    m_Font(),
    m_Score(),
    m_FontMap(),
    m_FontTexture() {

    auto size = Mof::CVector2(37.0f, 60.0f);
    for (int i = 0; i < 10; i++) {
        m_FontMap.emplace(std::string(std::to_string(i)),
                          Mof::CRectangle(size.x * i, 0.0f,
                                          size.x * i + size.x, size.y));
    } // for

    std::string alpha = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < alpha.size(); i++) {
        auto str = alpha.substr(i , 1);
        m_FontMap.emplace(str,
                          Mof::CRectangle(size.x * i, 60.0f,
                                          size.x * i + size.x,60.0f + size.y));
    } // for


}

UICanvas::~UICanvas() {
}

bool UICanvas::Initialize(void) {
    if (!m_Font.Create(64, "ƒƒCƒŠƒI")) {
        return false;
    } // if
    if (!m_FontTexture.Load("font.png")) {
        return false;
    } // if
    return true;
}

bool UICanvas::Update(void) {
    // ”ñ•\Ž¦‚Ì‚à‚Ì‚Ííœ
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
    for (auto& label : m_Labels) {
        label.Update();
    } // for

    return true;
}
bool UICanvas::Render(void) {
    auto text = std::string("score");
    text += std::to_string(m_RenderedScore);
    m_Font.RenderString(0.0f, 0.0f, MOF_ARGB(255, 255, 0, 0), text.c_str());


    for (int i = 0; i < 10; i++) {
        auto uv = m_FontMap.at(std::to_string(i));
        m_FontTexture.Render(400.0f + 35 * i, 400.0f, uv);
    } // for
    for (int i = 0; i < text.size() - 1; i++) {
        auto key  = text.substr(i, 1);
        auto uv = m_FontMap.at(key);
        m_FontTexture.Render(400.0f + 35 * i, 500.0f, uv);
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
    m_FontTexture.Release();
    return true;
}

void UICanvas::AddScore(uint32_t value) {
    m_Score += value;
}

void UICanvas::AddText(const std::string& text, Mof::CVector2 position, int exist) {
    m_Labels.push_back(UILabel(text, position, exist, &m_Font));
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