#include "pch.h"
#include "CCore.h"
#include "CObject.h"
//CCore* CCore::g_pInst = nullptr;



CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_hBit(0)
	, m_memDC(0)
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}

CObject g_obj;

int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	
	// 해상도에 맞게 윈도우 조절

	//2. 그래서 미리 조절 해야함!
	RECT rt = {0, 0, m_ptResolution.x, m_ptResolution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);

	//1. 그리는 영역 + 기타 영역 포함
	SetWindowPos(_hWnd, nullptr, 200, 200, rt.right - rt.left, rt.bottom - rt.top, 0);

	// DC초기화
	m_hDC = GetDC(m_hWnd);

	// double buffering
	// 비트맵 만들어서 거기에 그린다!
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	// 비트맵(1x1짜리 비트맵)에 대한 DC 만들기
	m_memDC = CreateCompatibleDC(m_hDC);
	// DC와 비트맵을 연결한다.
	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	// Manager 초기화
	CTimeMgr::GetInst()->init();
	
	g_obj.SetPos( Vec2((float)(m_ptResolution.x / 2), (float)(m_ptResolution.y / 2)) );
	g_obj.SetScale(Vec2( 100, 100 ));
	return S_OK;
}



void CCore::progress()
{
	//static int callCount = 0;
	//++callCount;
	//static int iPrevCount = GetTickCount();
	//int iCurCount = GetTickCount();
	//if (iCurCount - iPrevCount > 1000)
	//{
	//	callCount;
	//	iPrevCount = iCurCount;
	//	callCount = 0;
	//}

	CTimeMgr::GetInst()->update();

	update();

	render();



}

void CCore::update()
{

	Vec2 vPos = g_obj.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 200.f * fDT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 200.f * fDT;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		vPos.y -= 200.f * fDT;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		vPos.y += 200.f * fDT;
	}



	g_obj.SetPos(vPos);
}

void CCore::render()
{
	// 화면 덮기
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();

	// 그리기 작업
	Rectangle(m_memDC,
			(int)(vPos.x - vScale.x / 2.f),
			(int)(vPos.y - vScale.y / 2.f),
			(int)(vPos.x + vScale.x / 2.f),
			(int)(vPos.y + vScale.y / 2.f));

	// 옮기기
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);
}
