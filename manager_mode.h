#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H
#include "manager.h"
#define MGR_PATH "mgr.txt"

// ������ϵͳģ�ͽӿ���
class ManagerMode
{
public:
    // ���ļ���������
    virtual void load(vector<Manager> & mgrArr) = 0;
    // ���ļ���������
    virtual void save(vector<Manager> & mgrArr) = 0;
};

#endif//MANAGER_MODE_H