#include "pch.h"
#include "CkeyMgr.h"
#include "CCore.h"


//Virtual Key
int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,

};


CKeyMgr::CKeyMgr()
{
}
CKeyMgr::~CKeyMgr()
{
}
void CKeyMgr::init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}
}

void CKeyMgr::update()
{
	
	HWND hMainWnd = CCore::GetInst()->GetMainHwnd();

	// ���� ������ ��Ŀ�� ����
	HWND hWnd = GetFocus();
	
	if (nullptr != hWnd)
	{

	// tap(�ȴ��� -> ���� ����), hold(���� -> ���� ����), away(���� -> �ȴ��� ����), none(�ȴ��� -> �ȴ��� ����)
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
		{
			if (m_vecKey[i].bPrevPush)
			{
				m_vecKey[i].eState = KEY_STATE::HOLD;
			}
			else
			{
				m_vecKey[i].eState = KEY_STATE::TAP;
			}
			m_vecKey[i].bPrevPush = true;
		}
		else
		{
			if (m_vecKey[i].bPrevPush)
			{
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
			m_vecKey[i].bPrevPush = false;
		}
	}
	}
	else
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_vecKey[i].bPrevPush = false;
			if (KEY_STATE::TAP == m_vecKey[i].eState || KEY_STATE::HOLD == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else if (KEY_STATE::AWAY == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
		}
	}
}
