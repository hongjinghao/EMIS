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
        cout << "***��ӭʹ��ָ����ҵ��Ϣ����ϵͳ***" << endl;
        cout << "1����¼������ϵͳ" << endl;
        cout << "2����¼��Ӫ��ϵͳ" << endl;
        cout << "3���˳�" << endl;
        cout << "-----------------" << endl;
        cout << "������ָ��";
        switch(get_cmd('1','3'))
        {
            case '1': mgrView->loginManager(); break;
            case '2': mgrView->loginService(); break;
            case '3': return;
        }
    }
}