#pragma once
#include "define.h"

// Sigleton Pattern
// ��ü�� ������ 1���� ����
// ��𼭵� ���ٰ����ؾ���
// extern���� ����� ���? ���������� ����� �ִ�.
// ������ �����
// ������ ��� ����? �ɹ��Լ����ؼ� ��������.
// �ɹ��Լ��� ȣ���Ϸ���? ��ü�� �־����..
// 
// ��ü�� ��� ȣ�Ⱑ���� ����? static
// this�� ����. static�� �ɹ� ������ ���� �Ұ���.. 
// static �ɹ��� ���� ����!


// �������� "�����Ϳ���"
// �Լ��ȿ��� ���� �� ��� �Լ������� ���ٰ���
// ���Ͽ��� ���� �� ��� ���Ͽ����� ���ٰ���
// ���������� ���Ͽ��� ��ġ�� �ȵ�..
// Ŭ���� �ȿ��� ���� ��� Ŭ���� �ȿ����� ���ٰ���
//class CCore
//{
//private:
//	static CCore* g_pInst;
//public:
//	static CCore* GetInstance()
//	{
//		// ���� ȣ�� �Ȱ��
//		// �����Ҵ� ������� �����ϴ� ���
//		if (nullptr == g_pInst)
//		{
//			g_pInst = new CCore;
//		}
//		return g_pInst;
//	}
//	static void Release()
//	{
//		if (nullptr != g_pInst)
//		{
//			delete g_pInst;
//			g_pInst = nullptr;
//		}
//	}
//
//private:
//	CCore();
//	~CCore();
//
//};

class CCore
{
	SINGLE(CCore)
//public:
//	static CCore* GetInst()
//	{
//		// �ּҸ� ���ؼ� ���ٰ����ϴϱ� static���� �����ص� ����!
//		// �޸� ������ �Ű澵 �ʿ䰡 ����.
//		// ������ ���� ��(���α׷� ���� �߿�) ������ �� ����.
//		static CCore core;
//		return &core;
//	}
private:
	HWND m_hWnd;			// ���� ������ �ڵ�
	POINT m_ptResolution;	// ���� ������ �ػ�
	HDC m_hDC;				//���� �����쿡 �׸� DC

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	void update();
	void render();

public:
	HWND GetMainHwnd() { return m_hWnd; }

};