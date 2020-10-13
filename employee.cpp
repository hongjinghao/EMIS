#include "employee.h"

Employee::Employee(const string& name,char sex,int age)
{
    m_strName = name;
    m_cSex = sex;
    m_iAge = age;
}

void Employee::setId(int id)
{
    m_iId = id;
}

void Employee::setAge(int age)
{
    m_iAge = age;
}

void Employee::setName(const string& name)
{
    m_strName = name;
}

void Employee::setSex(char sex)
{
    m_cSex = sex;
}

int Employee::getId(void)
{
    return m_iId;
}

int Employee::getAge(void)
{
    return m_iAge;
}

const string& Employee::getName(void)
{
    return m_strName;
}

char Employee::getSex(void)
{
    return m_cSex;
}

ostream& operator<<(ostream& os,const Employee& emp)
{
    return os << emp.m_iId << " " << emp.m_strName << " " << emp.m_cSex << " " << emp.m_iAge;
}

istream& operator>>(istream& is,Employee& emp)
{
    return is >> emp.m_iId >> emp.m_strName >> emp.m_cSex >> emp.m_iAge;
}