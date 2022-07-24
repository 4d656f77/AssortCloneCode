#pragma once
#include "pch.h"
#include <vector>
// 1. ���� �����ӿ� ���� ������ ������ �־����
// 2. Ű �Է� �̺�Ʈ
// tap(�ȴ��� -> ���� ����), hold(���� -> ���� ����), away(���� -> �ȴ��� ����), none(�ȴ��� -> �ȴ��� ����)

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

