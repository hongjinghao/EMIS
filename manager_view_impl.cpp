#include "manager_view_impl.h"
#include "tools.h"
#include "md5.h"

ManagerViewImpl::ManagerViewImpl(void)
{
    mgrCtrl = new ManagerCtrlImpl;
    srcView = new ServiceViewImpl;
}

ManagerViewImpl::~ManagerViewImpl(void)
{
    delete mgrCtrl;
    delete srcView;
}

// 登录管理子系统
void ManagerViewImpl::loginManager(void)
{
    string name,pwd;
    cout << "请输入用户名：";
    cin >> name;
    cout << "请输入密码：";
    cin >> pwd;
    
    if(name=="zzxx" && pwd == "1324")
        menuMgr();
    else
        show_msg("用户名或密码错误，请重新登录！",2); 
}

// 登录运营子系统
void ManagerViewImpl::loginService(void)
{
    string name,pwd;
    cout << "请输入用户名：";
    cin >> name;
    cout << "请输入密码：";
    cin >> pwd;

    vector<Manager>& mgrArr = mgrCtrl->listMgr();
    for(size_t i=0; i<mgrArr.size(); i++)
    {
       if(name == mgrArr[i].getName())
       {
            if(MD5(pwd).toStr() == mgrArr[i].getPwd())
                srcView->menuSrc();
            else
                show_msg("登录失败，用户名或密码错误！",2);
            
            return;
       }
    }
    show_msg("该用户不存在，请检查！",2);
    
}

// 管理子系统功能菜单
void ManagerViewImpl::menuMgr(void)
{
    while (true)
    {
        //system("cls");
        cout << "1、添加管理员" << endl;
        cout << "2、删除管理员" << endl;
        cout << "3、列出所有管理员" << endl;
        cout << "4、返回上一级" << endl;
        cout << "-----------------" << endl;
        cout << "请输入指令";
        switch (get_cmd('1', '4'))
        {
        case '1':
            addMgr();
            break;
        case '2':
            delMgr();
            break;
        case '3':
            listMgr();
            break;
        case '4':
            return;
        }
    }
}

// 添加管理
void ManagerViewImpl::addMgr(void)
{
    string name,pwd,repwd;
    cout << "请输入用户名：";
    cin >> name;
    cout << "请输入密码：";
    cin >> pwd;
    cout << "请再次输入密码：";
    cin >> repwd;
    
    if(pwd != repwd)
    {
        show_msg("两次输入的密码不符，添加失败！",1.5);
        return;
    }

    Manager mgr(name.c_str(),pwd.c_str());
    if(mgrCtrl->addMgr(mgr))
        show_msg("添加成功！",1.5);
    else
        show_msg("添加失败，该用户名已经存在！",2);
}

// 删除管理员
void ManagerViewImpl::delMgr(void)
{
    int id = 0;
    cout << "请输入要删除的管理员id：";
    cin >> id;
    
    if(mgrCtrl->delMgr(id))
        show_msg("删除成功！",1.5);
    else
        show_msg("删除失败！请检查管理员id！",2);
}

// 列出所有管理员
void ManagerViewImpl::listMgr(void)
{
    vector<Manager>& mgrArr = mgrCtrl->listMgr();
    for (size_t i = 0; i < mgrArr.size(); i++)
    {
        cout << mgrArr[i] << endl;
    }   
    anykey_continue();
}