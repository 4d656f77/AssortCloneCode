#pragma once



class CTimeMgr
{

	SINGLE(CTimeMgr)
private:
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llFrequency;
	// Delta Time
	// 1frame 당 시간
	double			m_dDT;
	double			m_dAcc;
	// FPS 카운팅하려고
	UINT			m_iCallCount;
	UINT			m_iFPS;


	


public:
	void init();
	void update();
	
public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};

