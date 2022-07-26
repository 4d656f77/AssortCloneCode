
#include "CScene.h"
class CStartScene :
    public CScene
{

public:
    virtual void Enter();
    virtual void Exit();

public:
    CStartScene();
    ~CStartScene();
};
