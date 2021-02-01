#pragma once


#include <unordered_map>
#include <string>

#include "rapidjson/document.h"

#include <Mof.h>

#include "Helper.h"


struct SpriteMotionData {
    std::vector<Mof::SpriteAnimationCreate> anims;
    std::unordered_map<int, std::string> motion_map;
    bool Load(const char* path) {
        rapidjson::Document document;
        if (!ParseJsonDocument(path, document)) {
            return false;
        } // if

        if (!document.HasMember("animations")) {
            return false;
        } // if
        std::vector<Mof::SpriteAnimationCreatePattern> pattern_table;
        const auto& pattern_data = document["pattern"];
        _ASSERT_EXPR(pattern_data.IsArray(),
                     L"pattern type is not string");
        auto m = pattern_data.Size();
        for (size_t j = 0; j < m; j++) {
            auto pattern = Mof::SpriteAnimationCreatePattern();
            // frame
            if (pattern_data[j].HasMember("frame")) {
                const auto& frame = pattern_data[j]["frame"];
                _ASSERT_EXPR(frame.IsInt(),
                             L"frame type is not int");
                pattern.Wait = frame.GetInt();
            } // if
            // no
            if (pattern_data[j].HasMember("no")) {
                const auto& no = pattern_data[j]["no"];
                _ASSERT_EXPR(no.IsInt(),
                             L"no type is not int");
                pattern.No = no.GetInt();
            } // if
            // step
            if (pattern_data[j].HasMember("step")) {
                const auto& step = pattern_data[j]["step"];
                _ASSERT_EXPR(step.IsInt(),
                             L"step type is not int");
                pattern.Step = step.GetInt();
            } // if

            pattern_table.push_back(pattern);
        } // for



        if (!document.HasMember("animations")) {
            return false;
        } // if
        const auto& animations_data = document["animations"];
        _ASSERT_EXPR(animations_data.IsArray(),
                     L"animations type is not array");

        for (size_t i = 0; i < animations_data.Size(); i++) {
            auto anim = Mof::SpriteAnimationCreate();
            auto motion_key = std::string();
            // name
            if (animations_data[i].HasMember("name")) {

                const auto& name_data = animations_data[i]["name"];
                _ASSERT_EXPR(name_data.IsString(),
                             L"name type is not string");
                anim.Name = name_data.GetString();
                motion_key = std::string(name_data.GetString());
            } // if
            motion_map.emplace(i, motion_key);

            // x
            if (animations_data[i].HasMember("offset_x")) {
                const auto& offset_x = animations_data[i]["offset_x"];
                _ASSERT_EXPR(offset_x.IsInt(),
                             L"offset_x type is not int");
                anim.OffsetX = offset_x.GetInt();
            } // if
            // y
            if (animations_data[i].HasMember("offset_y")) {
                const auto& offset_y = animations_data[i]["offset_y"];
                _ASSERT_EXPR(offset_y.IsInt(),
                             L"offset_y type is not int");
                anim.OffsetY = offset_y.GetInt();
            } // if

            // width
            if (animations_data[i].HasMember("width")) {
                const auto& width = animations_data[i]["width"];
                _ASSERT_EXPR(width.IsInt(),
                             L"width type is not int");
                anim.Width = width.GetInt();
            } // if
            // height
            if (animations_data[i].HasMember("height")) {
                const auto& height = animations_data[i]["height"];
                _ASSERT_EXPR(height.IsInt(),
                             L"height type is not int");
                anim.Height = height.GetInt();
            } // if


            // loop
            if (animations_data[i].HasMember("loop")) {
                const auto& loop = animations_data[i]["loop"];
                _ASSERT_EXPR(loop.IsInt(),
                             L"loop type is not int");
                anim.bLoop = loop.GetInt() == 1 ? true : false;
            } // if

            // pattern
            if (animations_data[i].HasMember("pattern")) {
                const auto& pattern_data = animations_data[i]["pattern"];
                _ASSERT_EXPR(pattern_data.IsArray(),
                             L"pattern type is not string");
                std::vector<Mof::SpriteAnimationCreatePattern> patterns;
                for (size_t j = 0; j < pattern_data.Size(); j++) {
                    const auto& index = pattern_data[j];
                    _ASSERT_EXPR(index.IsInt(),
                                 L"index type is not int");
                    anim.Pattern[j] = pattern_table.at(index.GetInt());
                } // for
            } // if
            anims.push_back(std::move(anim));
        } // for
        return true;
    }
};
class CEffect {
private:
    //! テクスチャ
    Mof::CTexture* _texture;
    //! モーション
    Mof::CSpriteMotionController _motion;
    //! 表示
    bool _show;
    //! 位置
    Mof::CVector2 _position;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CEffect();
    /// <summary>
    /// デストラクタ
    /// </summary> 
    ~CEffect();
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    Mof::CRectangle GetCollisionRectangle(void) const;
    /// <summary>
    /// 判定
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool IsShow(void) const;
    /// <summary>
    /// 読み込み
    /// </summary>
    /// <returns></returns>
    bool Load(Mof::CTexture* texture, SpriteMotionData& anim);
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Update(void);
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Render(void);
    /// <summary>
    /// 開始
    /// </summary>
    bool Start(Mof::CVector2 pos);
};