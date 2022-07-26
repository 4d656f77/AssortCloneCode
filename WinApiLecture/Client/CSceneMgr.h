#pragma once

class CScene;

class CSceneMgr
{
	SINGLE(CSceneMgr);

private:
	// ¾À ¸ñ·Ï
	CScene* m_arrScene[(UINT)SCENE_TYPE::END];
	// ÇöÀç ¾À
	CScene* m_pCurScene;
public:
	void init();
	void update();
	void render(HDC _dc);

};

