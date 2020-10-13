#include "service_ctrl_Impl.h"

ServiceCtrlImpl::ServiceCtrlImpl(void)
{
    srcMode = new ServiceModeImpl;
    srcMode->load(deptArr);
}

ServiceCtrlImpl::~ServiceCtrlImpl(void)
{
    srcMode->save(deptArr);
    //delete srcMode;
}

bool ServiceCtrlImpl::addDept(Department& dept)
{
    for(size_t i=0; i<deptArr.size(); i++)
    {
        if(dept.getName() == deptArr[i].getName())
        {
            return false;
        }
    }

    dept.setId(get_id(typeid(Department)));
    deptArr.push_back(dept);
    return true;
}

int ServiceCtrlImpl::delDept(int deptId)
{
    vector<Department>::iterator it;
    for(it = deptArr.begin(); it!=deptArr.end(); it++)
    {
        if(it->getId() == deptId)
        {
            if(0 == it->getEmpArr().size())
            {
                deptArr.erase(it);
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    return 3;
}

vector<Department>& ServiceCtrlImpl::listDept(void)
{
    return deptArr;
}

bool ServiceCtrlImpl::addEmp(int deptId,Employee& emp)
{
    for(size_t i=0; i<deptArr.size(); i++)
    {
        if(deptId == deptArr[i].getId())
        {
            emp.setId(get_id(typeid(Employee)));
            deptArr[i].getEmpArr().push_back(emp);
            return true;
        }
    }
    return false;
}

bool ServiceCtrlImpl::delEmp(int empId)
{
    for(size_t i=0; i<deptArr.size(); i++)
    {
        vector<Employee>& empArr = deptArr[i].getEmpArr();
        vector<Employee>::iterator it;
        for(it=empArr.begin(); it!=empArr.end(); it++)
        {
            if(empId == it->getId())
            {
                empArr.erase(it);
                return true;
            }
        }
    }
    return false;
}

bool ServiceCtrlImpl::modEmp(int empId,Employee& emp)
{
    for(size_t i=0; i<deptArr.size(); i++)
    {
        vector<Employee>& empArr = deptArr[i].getEmpArr();
        vector<Employee>::iterator it;
        for(it=empArr.begin(); it!=empArr.end(); it++)
        {
            if(empId == it->getId())
            {
                emp.setId(empId);
                *it = emp;
                return true;
            }
        }
    }
    return false;
}

Department* ServiceCtrlImpl::listEmp(int deptId)
{
    for(size_t i=0; i<deptArr.size(); i++)
    {
        if(deptId == deptArr[i].getId())
        {
            return &deptArr[i];
        }
    }
    return NULL;
}

vector<Department>& ServiceCtrlImpl::listAllEmp(void)
{
    return deptArr;
}