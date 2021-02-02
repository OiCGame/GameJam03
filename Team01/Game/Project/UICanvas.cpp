#include "UICanvas.h"

#include <string>


UICanvas::UICanvas() :
	m_Font(),
	m_Score() {
}
UICanvas::~UICanvas() {
}
bool UICanvas::Initialize(void) {
	m_Font.Create(64, "メイリオ");
	return true;
}
bool UICanvas::Update(void) {
	// 非表示のものは削除
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
	auto text = std::string("スコア : ");
	text += std::to_string(m_RenderedScore);
	m_Font.RenderString(0.0f, 0.0f, MOF_ARGB(255, 255, 0,0), text.c_str());

	for (auto& label : m_Labels) {
		label.Render();
	} // for

	for (auto& image : m_Images) {
		image.Render();
	} // for

	return true;
}

void UICanvas::AddScore(uint32_t value) {
	m_Score += value;
}

void UICanvas::AddText(const std::string& text, Mof::CVector2 position, int exist) {
	m_Labels.push_back(UILabel(text, position, exist, &m_Font));
}

void UICanvas::AddImage(const char* name, Mof::CTexture* texture, Mof::CVector2 pos){
	m_Images.push_back(UIImage(name, texture, pos));
}
void UICanvas::RemoveImage(const std::string& name){
	auto it = std::remove_if(
		m_Images.begin(),
		m_Images.end(),
		[&](UIImage image) {
		return image.GetName() == name;
	});
	m_Images.erase(it, m_Images.end());
}