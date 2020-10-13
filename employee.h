#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "tools.h"

class Employee
{
    int m_iId;
    int m_iAge;
    string m_strName;
    char m_cSex;
public:
    Employee(const string& name="",char sex='w',int age=18);
    void setId(int id);
    void setAge(int age);
    void setName(const string& name);
    void setSex(char sex);
    int getId(void);
    int getAge(void);
    const string& getName(void);
    char getSex(void);
    friend ostream& operator<<(ostream& os,const Employee& emp);
    friend istream& operator>>(istream& is,Employee& emp);
};

ostream& operator<<(ostream& os,const Employee& emp);
istream& operator>>(istream& is,Employee& emp);

#endif//EMPLOYEE_H