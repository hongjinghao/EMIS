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

// ��¼������ϵͳ
void ManagerViewImpl::loginManager(void)
{
    string name,pwd;
    cout << "�������û�����";
    cin >> name;
    cout << "���������룺";
    cin >> pwd;
    
    if(name=="zzxx" && pwd == "1324")
        menuMgr();
    else
        show_msg("�û�����������������µ�¼��",2); 
}

// ��¼��Ӫ��ϵͳ
void ManagerViewImpl::loginService(void)
{
    string name,pwd;
    cout << "�������û�����";
    cin >> name;
    cout << "���������룺";
    cin >> pwd;

    vector<Manager>& mgrArr = mgrCtrl->listMgr();
    for(size_t i=0; i<mgrArr.size(); i++)
    {
       if(name == mgrArr[i].getName())
       {
            if(MD5(pwd).toStr() == mgrArr[i].getPwd())
                srcView->menuSrc();
            else
                show_msg("��¼ʧ�ܣ��û������������",2);
            
            return;
       }
    }
    show_msg("���û������ڣ����飡",2);
    
}

// ������ϵͳ���ܲ˵�
void ManagerViewImpl::menuMgr(void)
{
    while (true)
    {
        //system("cls");
        cout << "1����ӹ���Ա" << endl;
        cout << "2��ɾ������Ա" << endl;
        cout << "3���г����й���Ա" << endl;
        cout << "4��������һ��" << endl;
        cout << "-----------------" << endl;
        cout << "������ָ��";
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

// ��ӹ���
void ManagerViewImpl::addMgr(void)
{
    string name,pwd,repwd;
    cout << "�������û�����";
    cin >> name;
    cout << "���������룺";
    cin >> pwd;
    cout << "���ٴ��������룺";
    cin >> repwd;
    
    if(pwd != repwd)
    {
        show_msg("������������벻�������ʧ�ܣ�",1.5);
        return;
    }

    Manager mgr(name.c_str(),pwd.c_str());
    if(mgrCtrl->addMgr(mgr))
        show_msg("��ӳɹ���",1.5);
    else
        show_msg("���ʧ�ܣ����û����Ѿ����ڣ�",2);
}

// ɾ������Ա
void ManagerViewImpl::delMgr(void)
{
    int id = 0;
    cout << "������Ҫɾ���Ĺ���Աid��";
    cin >> id;
    
    if(mgrCtrl->delMgr(id))
        show_msg("ɾ���ɹ���",1.5);
    else
        show_msg("ɾ��ʧ�ܣ��������Աid��",2);
}

// �г����й���Ա
void ManagerViewImpl::listMgr(void)
{
    vector<Manager>& mgrArr = mgrCtrl->listMgr();
    for (size_t i = 0; i < mgrArr.size(); i++)
    {
        cout << mgrArr[i] << endl;
    }   
    anykey_continue();
}