#include "pch.h"
#include "CSceneMgr.h"
#include "CStartScene.h"

CSceneMgr::CSceneMgr()
	: m_arrScene{}
	, m_pCurScene(nullptr)

{

}
CSceneMgr::~CSceneMgr()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void CSceneMgr::init()
{
	// 스타트 씬 생성
	m_arrScene[(UINT)SCENE_TYPE::START] = new CStartScene;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");
	//m_arrScene[(UINT)SCENE_TYPE::TOOL] = new CToolScene;

	// 여기에서 모든 씬이 생성되어야 한다.

	// 현재 씬 설정
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurScene->Enter();
}

void CSceneMgr::update()
{
	m_pCurScene->update();
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}
