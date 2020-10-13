#ifndef MANAGER_CTRL_IMPL_H
#define MANAGER_CTRL_IMPL_H
#include "manager_ctrl.h"
#include "manager_mode_impl.h"

// ������ϵͳ����ʵ����
class ManagerCtrlImpl:public ManagerCtrl
{
    vector<Manager> mgrArr;
    ManagerMode* mgrMode;
public:
    ManagerCtrlImpl(void);
    ~ManagerCtrlImpl(void);
    // ��ӹ���Ա
    bool addMgr(Manager& mgr);
    // ɾ������Ա
    bool delMgr(int id);
    // �г����й���Ա
    vector<Manager>& listMgr(void);
};
#endif//MANAGER_CTRL_IMPL_H