#pragma once
#include "define.h"

// Sigleton Pattern
// 객체의 생성을 1개로 제한
// 어디서든 접근가능해야함
// extern으로 만드는 경우? 지역변수로 만들수 있다.
// 생성자 숨기기
// 생성자 어떻게 접근? 맴버함수통해서 접근하자.
// 맴버함수를 호출하려면? 객체가 있어야함..
// 
// 객체가 없어도 호출가능한 것은? static
// this가 없다. static은 맴버 변수에 접근 불가능.. 
// static 맴버는 접근 가능!


// 정적변수 "데이터영역"
// 함수안에서 선언 된 경우 함수에서만 접근가능
// 파일에서 선언 된 경우 파일에서만 접근가능
// 전역변수는 파일에서 겹치면 안됨..
// 클래스 안에서 선언 경우 클래스 안에서만 접근가능
//class CCore
//{
//private:
//	static CCore* g_pInst;
//public:
//	static CCore* GetInstance()
//	{
//		// 최초 호출 된경우
//		// 동적할당 방식으로 유지하는 경우
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
//		// 주소를 통해서 접근가능하니깐 static으로 유지해도 좋다!
//		// 메모리 해제를 신경쓸 필요가 없다.
//		// 하지만 원할 때(프로그램 실행 중에) 해제할 수 없다.
//		static CCore core;
//		return &core;
//	}
private:
	HWND m_hWnd;			// 메인 윈도우 핸들
	POINT m_ptResolution;	// 메인 윈도우 해상도
	HDC m_hDC;				//메인 윈도우에 그릴 DC

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	void update();
	void render();

public:
	HWND GetMainHwnd() { return m_hWnd; }

};