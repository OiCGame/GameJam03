#pragma once


#include "Character.h"

#include "EnemyBullet.h"


class CEnemy {
    using super = CCharacter;
public:
    struct InitParam {
        Mof::CVector2 position;
        int move_type;
        int move_type_on_pinch;
        float pinch_hp_ratio;
        float spawn_time;
        int bullet_column;
        int bullet_amount;
        int amount_set;
        int hp_max;
        InitParam(Mof::CVector2 pos, int move, int pinch_move, float ratio, float time, int column, int amount, int set, int hp) :
            position(pos), move_type(move), move_type_on_pinch(pinch_move), pinch_hp_ratio(ratio), spawn_time(time), bullet_column(column), bullet_amount(amount), amount_set(set), hp_max(hp) {
        }
    };
private:
    int m_HP;
    int m_MaxHP;
    Vector2 m_Pos;
    Vector2 m_Move;
    float m_Dir;
    float m_Speed;
    CTexture* m_pTexture;
    bool m_bDrow;
    int m_FastBulletNo;
    //! ˆÚ“®ƒ^ƒCƒv
    int m_MoveType;
    int m_MoveTypeOnPinch;
    float m_PinchHPRatio;

    /// <summary>
    /// ˆÚ“®
    /// </summary>
    /// <param name=""></param>
    virtual void Move(void);
    void Move(int type);
    void MoveOutOfWindow(void);


    CEnemyBullet* m_Bullet;
    int m_BulletColumn;
    int m_BulletAmount;
    int m_BulletSetAmount;
    int m_BulletCount;

    int m_BulletNo;
    int m_BulletSetNo;

    int m_BulletGap = 10;
    int m_BulletRemGap;
    int m_BulletSetGap = 60;
    int m_BulletSetRemGap;

public:

    CEnemy();
    ~CEnemy();

    Mof::CVector2 GetPosition(void) const;
    bool IsShow() { return m_bDrow; }

    void Initialize(const InitParam& param);
    void Initialize(Vector2 pos, int move_type, int pinch_move, float ratio, int column, int amount, int set, int hp);
    void SetTexture(Mof::CTexture* ptr);
    void Update();
    int CollitionBullet(CRectangle prec);
    void Render();
    void Release();

    /// <summary>
    /// Ž€–S‚µ‚½‚çtrue‚ð•Ô‚·
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Damage();
    int GetFastBulletNo() { return m_FastBulletNo; }
    void SetFastBulletNo(int no) { m_FastBulletNo = no; }
    Mof::CRectangle GetCollisionRectangle(void) const;
};