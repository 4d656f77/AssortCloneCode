#pragma once
#include "pch.h"
#include <vector>
// 1. 같은 프레임에 같은 정보를 가지고 있어야함
// 2. 키 입력 이벤트
// tap(안눌림 -> 눌림 상태), hold(눌림 -> 눌림 상태), away(눌림 -> 안눌림 상태), none(안눌림 -> 안눌림 상태)

enum class KEY_STATE: int
{
	NONE,
	TAP,
	HOLD,
	AWAY,
};

enum class KEY: int
{
	LEFT,
	RIGHT,
	UP,
	DOWN,

	LAST,

};

struct tKeyInfo
{
	KEY_STATE eState;
	bool bPrevPush;
};

class CKeyMgr
{
	SINGLE(CKeyMgr);

private:
	std::vector<tKeyInfo> m_vecKey;

public:
	void init();
	void update();

public:
	KEY_STATE GetKeyState(KEY _eKey)
	{
		return m_vecKey[(int)_eKey].eState;
	}
};

