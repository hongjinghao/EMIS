#include "service_view_impl.h"

ServiceViewImpl::ServiceViewImpl(void)
{
    srcCtrl = new ServiceCtrlImpl;
}

ServiceViewImpl::~ServiceViewImpl(void)
{
    delete srcCtrl;
}

void ServiceViewImpl::menuSrc(void)
{
    while (true)
    {
        system("cls");
        cout << "1����Ӳ���" << endl;
        cout << "2��ɾ������" << endl;
        cout << "3���г�����" << endl;
        cout << "4�����Ա��" << endl;
        cout << "5��ɾ��Ա��" << endl;
        cout << "6���޸�Ա����Ϣ" << endl;
        cout << "7����ʾ����Ա��" << endl;
        cout << "8����ʾ����Ա��" << endl;
        cout << "9��������һ��" << endl;
        cout << "-----------------" << endl;
        cout << "������ָ��";

        switch(get_cmd('1','9'))
        {
            case '1': addDept(); break;
            case '2': delDept(); break;
            case '3': listDept(); break;
            case '4': addEmp(); break;
            case '5': delEmp(); break;
            case '6': modEmp(); break;
            case '7': listEmp(); break;
            case '8': listAllEmp(); break;
            case '9': return;
        }
    }
    
}

void ServiceViewImpl::addDept(void)
{
    string name;
    cout << "�����벿������";
    cin >> name;
    Department dept(name);
    
    if(srcCtrl->addDept(dept))
        show_msg("��Ӳ��ųɹ���",1.5);
    else
        show_msg("��Ӳ���ʧ�ܣ��ò����Ѿ����ڣ�",2);
}

void ServiceViewImpl::delDept(void)
{
    int id = 0;
    cout <<"������Ҫɾ���Ĳ���ID��";
    cin >> id;
    switch(srcCtrl->delDept(id))
    {
        case 1:
            show_msg("ɾ�����ųɹ���",1.5); break;
        case 2:
            show_msg("�ò��Ż���Ա�����봦��",2); break;
        case 3:
            show_msg("ɾ������ʧ�ܣ����鲿��ID!",2); break;
    }
}

void ServiceViewImpl::listDept(void)
{
    vector<Department>& deptArr = srcCtrl->listDept();
    for(size_t i=0; i<deptArr.size(); i++)
    {
        cout << deptArr[i].getId() << " " << deptArr[i].getName() << endl;
    }
    anykey_continue();
}

void ServiceViewImpl::addEmp(void)
{
    string name;
    char sex;
    int age;
    int id;
    cout << "������Ա�����������Ա����䡢����ID��";
    cin >> name >> sex >> age >> id;
    Employee emp(name,sex,age);
    if(srcCtrl->addEmp(id,emp))
        show_msg("���Ա���ɹ���",1.5);
    else   
        show_msg("���Ա��ʧ�ܣ����鲿��ID��",2);
}

void ServiceViewImpl::delEmp(void)
{
    int id;
    cout << "������Ҫɾ����Ա��ID��";
    cin >> id;
    if(srcCtrl->delEmp(id))
        show_msg("ɾ��Ա���ɹ���",1.5);
    else
        show_msg("ɾ��Ա��ʧ�ܣ�����Ա��ID��",2);
}

void ServiceViewImpl::modEmp(void)
{
    string name;
    char sex;
    int age;
    int id;
    cout << "�������޸ĵ�Ա��ID���������Ա����䣺";
    cin >> id >> name >> sex >> age;
    Employee emp(name,sex,age);
    if(srcCtrl->modEmp(id,emp))
        show_msg("�޸�Ա����Ϣ�ɹ���",1.5);
    else   
        show_msg("�޸�Ա����Ϣʧ�ܣ�����Ա��ID��",2);
}

void ServiceViewImpl::listEmp(void)
{
    int id;
    cout << "������Ҫ��ʾ�Ĳ���ID��";
    cin >> id;
    Department* dept = srcCtrl->listEmp(id);
    if(NULL == dept)
        show_msg("�ò��Ų����ڣ����飡",2);
    else
        cout << *dept << endl;
    anykey_continue();
}

void ServiceViewImpl::listAllEmp(void)
{
    vector<Department>& deptArr = srcCtrl->listDept();
    for(size_t i=0; i<deptArr.size(); i++)
    {
        cout << deptArr[i] << endl;
    }
    anykey_continue();
}