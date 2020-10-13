#include <fstream>
#include "manager_mode_impl.h"

// ���ļ���������
void ManagerModeImpl::load(vector<Manager> &mgrArr)
{
    ifstream ifs(MGR_PATH);
    if (!ifs)
    {
        show_msg("����ǵ�һ��ִ�У������Ա�����ļ���ʧ��", 2);
        return;
    }

    Manager mgr;
    while ((ifs>>mgr).good())
    {
        mgrArr.push_back(mgr);
    }
    
    ifs.close();
}

// ���ļ���������
void ManagerModeImpl::save(vector<Manager> &mgrArr)
{
    ofstream ofs(MGR_PATH);
    if(!ofs)
    {
        show_msg("�����ļ�ʧ�ܣ������ļ�·����", 2);
        return;
    }

    for(size_t i=0; i<mgrArr.size(); i++)
    {
        ofs << mgrArr[i] << endl;
    }
    ofs.close();
}