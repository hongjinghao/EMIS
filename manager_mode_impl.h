#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H
#include "manager_mode.h"

// ������ϵͳģ��ʵ����
class ManagerModeImpl:public ManagerMode
{
public:
    // ���ļ���������
    void load(vector<Manager> & mgrArr);
    // ���ļ���������
    void save(vector<Manager> & mgrArr);
};

#endif//MANAGER_MODE_IMPL_H