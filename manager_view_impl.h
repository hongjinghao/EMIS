#ifndef MANAGER_VIEW_IMPL_H
#define MANAGER_VIEW_IMPL_H
#include "manager_view.h"
#include "manager_ctrl_impl.h"
#include "service_view_impl.h"

// ������ϵͳ����ʵ����
class ManagerViewImpl:public ManagerView
{
    ManagerCtrl* mgrCtrl;
    ServiceView* srcView;
public:
    ManagerViewImpl(void);
    ~ManagerViewImpl(void);
    // ��¼������ϵͳ
    void loginManager(void);
    // ��¼��Ӫ��ϵͳ
    void loginService(void);
    // ������ϵͳ���ܲ˵�
    void menuMgr(void);
    // ��ӹ���
    void addMgr(void);
    // ɾ������Ա
    void delMgr(void);
    // �г����й���Ա
    void listMgr(void);
};
#endif//MANAGER_VIEW_IMPL_H