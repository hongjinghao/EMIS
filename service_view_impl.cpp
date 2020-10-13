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
        cout << "1、添加部门" << endl;
        cout << "2、删除部门" << endl;
        cout << "3、列出部门" << endl;
        cout << "4、添加员工" << endl;
        cout << "5、删除员工" << endl;
        cout << "6、修改员工信息" << endl;
        cout << "7、显示部门员工" << endl;
        cout << "8、显示所有员工" << endl;
        cout << "9、返回上一级" << endl;
        cout << "-----------------" << endl;
        cout << "请输入指令";

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
    cout << "请输入部门名：";
    cin >> name;
    Department dept(name);
    
    if(srcCtrl->addDept(dept))
        show_msg("添加部门成功！",1.5);
    else
        show_msg("添加部门失败，该部门已经存在！",2);
}

void ServiceViewImpl::delDept(void)
{
    int id = 0;
    cout <<"请输入要删除的部门ID：";
    cin >> id;
    switch(srcCtrl->delDept(id))
    {
        case 1:
            show_msg("删除部门成功！",1.5); break;
        case 2:
            show_msg("该部门还有员工，请处理！",2); break;
        case 3:
            show_msg("删除部门失败，请检查部门ID!",2); break;
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
    cout << "请输入员工的姓名、性别、年龄、部门ID：";
    cin >> name >> sex >> age >> id;
    Employee emp(name,sex,age);
    if(srcCtrl->addEmp(id,emp))
        show_msg("添加员工成功！",1.5);
    else   
        show_msg("添加员工失败，请检查部门ID！",2);
}

void ServiceViewImpl::delEmp(void)
{
    int id;
    cout << "请输入要删除的员工ID：";
    cin >> id;
    if(srcCtrl->delEmp(id))
        show_msg("删除员工成功！",1.5);
    else
        show_msg("删除员工失败，请检查员工ID！",2);
}

void ServiceViewImpl::modEmp(void)
{
    string name;
    char sex;
    int age;
    int id;
    cout << "请输入修改的员工ID、姓名、性别、年龄：";
    cin >> id >> name >> sex >> age;
    Employee emp(name,sex,age);
    if(srcCtrl->modEmp(id,emp))
        show_msg("修改员工信息成功！",1.5);
    else   
        show_msg("修改员工信息失败，请检查员工ID！",2);
}

void ServiceViewImpl::listEmp(void)
{
    int id;
    cout << "请输入要显示的部门ID：";
    cin >> id;
    Department* dept = srcCtrl->listEmp(id);
    if(NULL == dept)
        show_msg("该部门不存在，请检查！",2);
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