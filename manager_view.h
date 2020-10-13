#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

// 管理子系统界面接口类
class ManagerView
{
public:
    virtual ~ManagerView(void) {}
    // 登录管理子系统
    virtual void loginManager(void) = 0;
    // 登录运营子系统
    virtual void loginService(void) = 0;
    // 管理子系统功能菜单
    virtual void menuMgr(void) = 0;
    // 添加管理
    virtual void addMgr(void) = 0;
    // 删除管理员
    virtual void delMgr(void) = 0;
    // 列出所有管理员
    virtual void listMgr(void) = 0;
};
#endif//MANAGER_VIEW_H