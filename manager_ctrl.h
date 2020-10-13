#ifndef MANAGER_CTRL_H
#define MANAGER_CTRL_H
#include "manager.h"

// ������ϵͳ���ƽӿ���
class ManagerCtrl
{
public:
    virtual ~ManagerCtrl(void) {}
    // ��ӹ���Ա
    virtual bool addMgr(Manager& mgr) = 0;
    // ɾ������Ա
    virtual bool delMgr(int id) = 0;
    // �г����й���Ա
    virtual vector<Manager>& listMgr(void) = 0;
};

#endif//MANAGER_CTRL_H