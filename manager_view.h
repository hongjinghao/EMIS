#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

// ������ϵͳ����ӿ���
class ManagerView
{
public:
    virtual ~ManagerView(void) {}
    // ��¼������ϵͳ
    virtual void loginManager(void) = 0;
    // ��¼��Ӫ��ϵͳ
    virtual void loginService(void) = 0;
    // ������ϵͳ���ܲ˵�
    virtual void menuMgr(void) = 0;
    // ��ӹ���
    virtual void addMgr(void) = 0;
    // ɾ������Ա
    virtual void delMgr(void) = 0;
    // �г����й���Ա
    virtual void listMgr(void) = 0;
};
#endif//MANAGER_VIEW_H