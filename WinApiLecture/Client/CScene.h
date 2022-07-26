#pragma once

class CObject;

class CScene
{
private:
	// ������Ʈ �־��� ���� ����
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
	// �� ���Խÿ� ȣ���ϱ�
	virtual void Enter() = 0;
	// �� ��ȯ�ÿ� ȣ���ϱ�
	virtual void Exit() = 0;
public:
	CScene();
	virtual ~CScene();
};

