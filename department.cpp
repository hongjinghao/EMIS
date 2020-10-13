#include "department.h"

Department::Department(const string& name)
{
    m_strName = name;
}

void Department::setId(int id)
{
    cout << "set id = " << id << endl;
    m_iId = id;
}

void Department::setName(const string& name)
{
    m_strName = name;
}

int Department::getId(void)
{
    return m_iId;
}

 const string&  Department::getName(void)
{
    return m_strName;
}

vector<Employee>& Department::getEmpArr(void)
{
    return empArr;
}

ostream& operator<<(ostream& os,const Department& dept)
{
    os << dept.m_iId << " " << dept.m_strName << " " << dept.empArr.size() << endl;
    for(size_t i=0; i<dept.empArr.size(); i++)
    {
        os << dept.empArr[i] << endl;
    }
    return os;
}

istream& operator>>(istream& is,Department& dept)
{
    int empSize = 0;
    is >> dept.m_iId >> dept.m_strName >> empSize;
    Employee emp;

    for(int i=0; i<empSize; i++)
    {
        is >> emp;
        dept.empArr.push_back(emp);
    }

    return is;
}