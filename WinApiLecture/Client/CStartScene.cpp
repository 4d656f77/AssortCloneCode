
#include "pch.h"
#include "CStartScene.h"
#include "CObject.h"

CStartScene::CStartScene()
{
}

CStartScene::~CStartScene()
{
}

void CStartScene::Enter()
{
	// °´Ã¼ Ãß°¡
	CObject* pObj = new CObject;

	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));


	AddObject(pObj, GROUP_TYPE::DEFAULT);
	CObject* pObj2 = new CObject;
	pObj2->SetPos(Vec2(300.f, 300.f));
	pObj2->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj2, GROUP_TYPE::DEFAULT);
}

void CStartScene::Exit()
{
}

