#include "manager.h"
#include "md5.h"

Manager::Manager(const string& name,const string& pwd)
{
    m_strName = name;
    m_strPwd = MD5(pwd).toStr();
}

int Manager::getId(void) const
{
    return m_iId;
}

const string& Manager::getName(void) const
{
    return m_strName;
}

const string& Manager::getPwd(void) const
{
    return m_strPwd;
}

void Manager::setId(int id)
{
    m_iId = id;
}

void Manager::setName(const string& name)
{
    m_strName = name;
}

void Manager::setPwd(const string& pwd)
{
    m_strPwd = pwd;
}

ostream& operator<<(ostream& os,const Manager& mgr)
{
    return os << mgr.m_iId << " " << mgr.m_strName << " " << mgr.m_strPwd;
}

istream& operator>>(istream& is,Manager& mgr)
{
    return is >> mgr.m_iId >> mgr.m_strName >> mgr.m_strPwd;
}