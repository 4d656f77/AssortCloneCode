#pragma once
class CObject
{
public:
	static CObject* GetInst()
	{
		static CObject mgr;
		return &mgr;
	}

public:
	CObject();
	~CObject(); 

public:
	Vec2 m_vPos;
	Vec2 m_vScale;

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }


};

