#include "emis.h"
#include "manager_view_impl.h"

EMIS EMIS::emis;

EMIS::EMIS(void)
{
    mgrView = new ManagerViewImpl;
}
EMIS::~EMIS(void)
{
    delete mgrView;
}

EMIS& EMIS::getOBJ(void)
{
    return emis;
}

void EMIS::emisMenu(void)
{
    while(true)
    {
        system("cls");
        cout << "***欢迎使用指针企业信息管理系统***" << endl;
        cout << "1、登录管理子系统" << endl;
        cout << "2、登录运营子系统" << endl;
        cout << "3、退出" << endl;
        cout << "-----------------" << endl;
        cout << "请输入指令";
        switch(get_cmd('1','3'))
        {
            case '1': mgrView->loginManager(); break;
            case '2': mgrView->loginService(); break;
            case '3': return;
        }
    }
}