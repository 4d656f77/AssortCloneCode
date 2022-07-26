#pragma once

class CObject;

class CScene
{
private:
	// 오브젝트 넣어줄 벡터 선언
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];
	wstring m_strName;

protected:
	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName;  }
	// 씬 진입시에 호출하기
	virtual void Enter() = 0;
	// 씬 전환시에 호출하기
	virtual void Exit() = 0;
public:
	CScene();
	virtual ~CScene();
};

