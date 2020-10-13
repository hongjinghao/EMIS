#include <fstream>
#include "manager_mode_impl.h"

// 从文件加载数据
void ManagerModeImpl::load(vector<Manager> &mgrArr)
{
    ifstream ifs(MGR_PATH);
    if (!ifs)
    {
        show_msg("如果非第一次执行，则管理员数据文件丢失！", 2);
        return;
    }

    Manager mgr;
    while ((ifs>>mgr).good())
    {
        mgrArr.push_back(mgr);
    }
    
    ifs.close();
}

// 向文件保存数据
void ManagerModeImpl::save(vector<Manager> &mgrArr)
{
    ofstream ofs(MGR_PATH);
    if(!ofs)
    {
        show_msg("保存文件失败，请检查文件路径！", 2);
        return;
    }

    for(size_t i=0; i<mgrArr.size(); i++)
    {
        ofs << mgrArr[i] << endl;
    }
    ofs.close();
}