#pragma once

// 링커에서 찾아 쓰기
class CObject;

class CScene
{
private:
	// void* 와 비슷하게 CObject*를 사용
	// CObject의 자식들 모두를 가르킬 수 있다.
	// 그룹별로 나누기
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];
	wstring m_strName;

protected:
	// 부모 맴버 접근을 함수를 통해서 하면
	// 콜스텍을 찾아서 디버깅하기 편리하다.
	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName;  }
	

	void update();
	void render(HDC _dc);

	// 상속 받아서 정의할 수 있게 순수 가상 함수로 선언
	// 씬 진입시
	virtual void Enter() = 0;
	// 씬 전환시
	virtual void Exit() = 0;
public:
	CScene();
	// 파생된 씬들은 CScene*으로 가르키는데
	// 파생된 씬들도 소멸 시켜야 하므로
	// 가상 함수로 선언해서
	// 가상함수 테이블에서 찾아가게 만들자
	virtual ~CScene();
};

