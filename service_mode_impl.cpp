#include <fstream>
#include "service_mode_impl.h"

void ServiceModeImpl::load(vector<Department>& deptArr)
{
    ifstream ifs(SRC_PATH);
    if (!ifs)
    {
        show_msg("如果非第一次执行，则管理员数据文件丢失！", 2);
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
        show_msg("保存文件失败，请检查文件路径！", 2);
        return;
    }

    for(size_t i=0; i<deptArr.size(); i++)
    {
        ofs << deptArr[i];
    }
    ofs.close();
}