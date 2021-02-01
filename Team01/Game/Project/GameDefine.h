#pragma once
#include <Mof.h>
class GameDefine
{
};

class CInputManager {
private:
	CXGamePad pad[2];

	struct Key {
		float Horizontal;
		float Vertical;

		bool now[10];
		bool prev[10];
	};
	Key key;

	CInputManager() {
		XGAMEPADCREATEINFO cinfo;
		cinfo.No = 0;
		pad[0].Create(&cinfo);
		cinfo.No = 1;
		pad[1].Create(&cinfo);
	}
public:
	float GetHorizontal() {
		return key.Horizontal;
	}

	float GetVertical() {
		return key.Vertical;
	}

	bool GetHold(int btnno) {
		return key.now[btnno];
	}

	bool GetPush(int btnno) {
		return !key.prev[btnno] && key.now[btnno];
	}

	bool GetPull(int btnno) {
		return key.prev[btnno] && !key.now[btnno];
	}

	void Refresh()
	{
		for (int i = 0; i < 2; i++)
		{
			pad[i].RefreshKey();
			key.Horizontal = 0;
			key.Vertical = 0;
			for (int j = 0; j < 10; j++)
			{
				key.prev[j] = key.now[j];
				key.now[j] = false;
			}

			if (pad[i].IsKeyHold(XINPUT_DP_LEFT))
			{
				key.Horizontal = -1;
			}
			else if (pad[i].IsKeyHold(XINPUT_DP_RIGHT))
			{
				key.Horizontal = 1;
			}
			else
			{
				key.Horizontal = pad[i].GetStickHorizontal();
			}

			if (pad[i].IsKeyHold(XINPUT_DP_UP))
			{
				key.Vertical = 1;
			}
			else if (pad[i].IsKeyHold(XINPUT_DP_DOWN))
			{
				key.Vertical = -1;
			}
			else
			{
				key.Vertical = pad[i].GetStickVertical();
			}

			key.now[0] = pad[i].IsKeyHold(XINPUT_A);
			key.now[1] = pad[i].IsKeyHold(XINPUT_B);
			key.now[2] = pad[i].IsKeyHold(XINPUT_X);
			key.now[3] = pad[i].IsKeyHold(XINPUT_Y);
			key.now[4] = pad[i].IsKeyHold(XINPUT_L_BTN);
			key.now[5] = pad[i].IsKeyHold(XINPUT_R_BTN);
			key.now[6] = pad[i].IsKeyHold(XINPUT_LS_PUSH);
			key.now[7] = pad[i].IsKeyHold(XINPUT_RS_PUSH);
			key.now[8] = pad[i].IsKeyHold(XINPUT_START);
			key.now[9] = pad[i].IsKeyHold(XINPUT_BACK);

			if (i == 0)
			{
				if (g_pInput->IsKeyHold(MOFKEY_LEFT))
				{
					key.Horizontal = -1;
				}
				else if (g_pInput->IsKeyHold(MOFKEY_RIGHT))
				{
					key.Horizontal = 1;
				}

				if (g_pInput->IsKeyHold(MOFKEY_UP))
				{
					key.Vertical = 1;
				}
				else if (g_pInput->IsKeyHold(MOFKEY_DOWN))
				{
					key.Vertical = -1;
				}
				if (g_pInput->IsKeyHold(MOFKEY_X))
				{
					key.now[0] = true;
				}
				if (g_pInput->IsKeyHold(MOFKEY_Z))
				{
					key.now[1] = true;
				}
				if (g_pInput->IsKeyHold(MOFKEY_A))
				{
					key.now[2] = true;
				}
				if (g_pInput->IsKeyHold(MOFKEY_S))
				{
					key.now[3] = true;
				}
				if (g_pInput->IsKeyHold(MOFKEY_D))
				{
					key.now[4] = true;
				}
				if (g_pInput->IsKeyHold(MOFKEY_C))
				{
					key.now[5] = true;
				}
				if (g_pInput->IsKeyHold(MOFKEY_LSHIFT))
				{
					key.now[6] = true;
				}
				if (g_pInput->IsKeyHold(MOFKEY_CAPSLOCK))
				{
					key.now[7] = true;
				}
				if (g_pInput->IsKeyHold(MOFKEY_RETURN))
				{
					key.now[8] = true;
				}
				if (g_pInput->IsKeyHold(MOFKEY_SPACE))
				{
					key.now[9] = true;
				}
			}
		}
	}

	static CInputManager& GetInstance()
	{
		static CInputManager obj;
		return obj;
	}
};
