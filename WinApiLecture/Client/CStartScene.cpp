
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
	// ��ü �߰�
	CObject* pObj = new CObject;
	AddObject(pObj, GROUP_TYPE::DEFAULT);
}

void CStartScene::Exit()
{
}

