#include <fstream>
#include "service_mode_impl.h"

void ServiceModeImpl::load(vector<Department>& deptArr)
{
    ifstream ifs(SRC_PATH);
    if (!ifs)
    {
        show_msg("����ǵ�һ��ִ�У������Ա�����ļ���ʧ��", 2);
        return;
    }

    Department dept;
    while ((ifs>>dept).good())
    {
        deptArr.push_back(dept);
        dept.getEmpArr().clear();
    }
    
    ifs.close();
}

void ServiceModeImpl::save(vector<Department>& deptArr)
{
    ofstream ofs(SRC_PATH);
    if(!ofs)
    {
        show_msg("�����ļ�ʧ�ܣ������ļ�·����", 2);
        return;
    }

    for(size_t i=0; i<deptArr.size(); i++)
    {
        ofs << deptArr[i];
    }
    ofs.close();
}