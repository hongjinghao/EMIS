#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "tools.h"
#include "employee.h"

class Department
{
    int m_iId;
    string m_strName;
    vector<Employee> empArr;
public:
    Department(const string& name="");
    void setId(int id);
    void setName(const string& name);
    int getId(void);
    const string& getName(void);
    vector<Employee>& getEmpArr(void);
    friend ostream& operator<<(ostream& os,const Department& dept);
    friend istream& operator>>(istream& is,Department& dept);
};

ostream& operator<<(ostream& os,const Department& dept);
istream& operator>>(istream& is,Department& dept);

#endif//DEPARTMENT_H