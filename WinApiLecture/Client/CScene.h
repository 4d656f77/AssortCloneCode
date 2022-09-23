#pragma once

// ��Ŀ���� ã�� ����
class CObject;

class CScene
{
private:
	// void* �� ����ϰ� CObject*�� ���
	// CObject�� �ڽĵ� ��θ� ����ų �� �ִ�.
	// �׷캰�� ������
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];
	wstring m_strName;

protected:
	// �θ� �ɹ� ������ �Լ��� ���ؼ� �ϸ�
	// �ݽ����� ã�Ƽ� ������ϱ� ���ϴ�.
	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName;  }
	

	void update();
	void render(HDC _dc);

	// ��� �޾Ƽ� ������ �� �ְ� ���� ���� �Լ��� ����
	// �� ���Խ�
	virtual void Enter() = 0;
	// �� ��ȯ��
	virtual void Exit() = 0;
public:
	CScene();
	// �Ļ��� ������ CScene*���� ����Ű�µ�
	// �Ļ��� ���鵵 �Ҹ� ���Ѿ� �ϹǷ�
	// ���� �Լ��� �����ؼ�
	// �����Լ� ���̺��� ã�ư��� ������
	virtual ~CScene();
};

