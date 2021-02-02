
#include	"Block.h"

CBlock::CBlock() {
}

CBlock::~CBlock() {
}

bool CBlock::Load(void) {
	if (!g_Block.Load("UI/ÉQÅ[ÉÄñ{ï“/éläp.png")) {
		return false;
	}
	if (!g_UpRect.Load("UI/ÉQÅ[ÉÄñ{ï“/è„òg.png")) {
		return false;
	}
	return true;
}

void CBlock::Initialize(void) {
	g_UpPos = Vector2(0, 0);
	timer = 0;
	for (int i = 0; i < SHOW; i++) {
		g_Show[i] = false;
	}
}

void CBlock::BlockSet(int i) {
	g_Show[i] = true;
	g_BlPos[i].y = 0 - 600/*g_Block.GetHeight()*/;
	g_BlPos[i].x = CUtilities::Random(RANDOM);
	rad[i] = CUtilities::Random(RADIAN);
}

void CBlock::Update(void) {
	timer++;
	t = (timer * timer) % SHOW;
	if (!g_Show[t]) {
		BlockSet(t);
		timer = 0;
	}
	for (int i = 0; i < SHOW; i++) {
		if (g_Show[i]) {
			rad[i]++;
			g_BlPos[i].y += SPEED;
			if (g_BlPos[i].y > BOTTOM) {
				g_Show[i] = false;
			}
		}
	}
}

void CBlock::Render(void) {
	g_UpRect.Render(g_UpPos.x, g_UpPos.y);
}

void CBlock::RenderBlock(void) {
	for (int i = 0; i < SHOW; i++) {
		if (g_Show[i]) {
			g_Block.RenderRotate(g_BlPos[i].x, g_BlPos[i].y, MOF_ToRadian(rad[i] % 360), TEXALIGN_CENTERCENTER);
		}
	}
}

void CBlock::Release(void) {
	g_Block.Release();
	g_UpRect.Release();
}