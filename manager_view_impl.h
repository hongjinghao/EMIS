#ifndef MANAGER_VIEW_IMPL_H
#define MANAGER_VIEW_IMPL_H
#include "manager_view.h"
#include "manager_ctrl_impl.h"
#include "service_view_impl.h"

// 管理子系统界面实现类
class ManagerViewImpl:public ManagerView
{
    ManagerCtrl* mgrCtrl;
    ServiceView* srcView;
public:
    ManagerViewImpl(void);
    ~ManagerViewImpl(void);
    // 登录管理子系统
    void loginManager(void);
    // 登录运营子系统
    void loginService(void);
    // 管理子系统功能菜单
    void menuMgr(void);
    // 添加管理
    void addMgr(void);
    // 删除管理员
    void delMgr(void);
    // 列出所有管理员
    void listMgr(void);
};
#endif//MANAGER_VIEW_IMPL_H