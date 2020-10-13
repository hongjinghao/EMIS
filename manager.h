#ifndef MANAGER_H
#define MANAGER_H
#include "tools.h"

// 管理子系统逻辑对象
class Manager
{
    int m_iId;
    string m_strName;
    string m_strPwd;
public:
    Manager(const string& name="",const string& pwd="");
    int getId(void) const;
    const string& getName(void) const;
    const string& getPwd(void) const;
    void setId(int id);
    void setName(const string& name);
    void setPwd(const string& pwd);
    friend ostream& operator<<(ostream& os,const Manager& mgr);
    friend istream& operator>>(istream& is,Manager& mgr);
};

/*
ostream& operator<<(ostream& os,const Manager& mgr);
istream& operator>>(ostream& is,Manager& mgr);
*/

#endif//MANAGER_H