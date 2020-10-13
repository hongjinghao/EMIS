#ifndef SERVICE_CTRL_H
#define SERVICE_CTRL_H
#include "department.h"
#include "employee.h"
#include "tools.h"

class ServiceCtrl
{
public:
    virtual ~ServiceCtrl(void) {}
    virtual bool addDept(Department& dept) = 0;
    virtual int delDept(int deptId) = 0;
    virtual vector<Department>& listDept(void) = 0;
    virtual bool addEmp(int deptId,Employee& emp) = 0;
    virtual bool delEmp(int empId) = 0;
    virtual bool modEmp(int empId,Employee& emp) = 0;
    virtual Department* listEmp(int deptId) = 0;
    virtual vector<Department>& listAllEmp(void) = 0;
};

#endif//SERVICE_CTRL_H