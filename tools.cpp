#include <fstream>
#include <windows.h>
#include <conio.h>
#include "tools.h"
#include "manager.h"
#include "department.h"
#include "employee.h"

// 自动生成一个id
int get_id(const type_info& type)
{
    int arr[3] = {1001,2002,3001} , id = 0;
    fstream fs(ID_PATH,ios::in|ios::out|ios::binary);

    if(fs)
    {
        fs.read((char*)&arr,sizeof(arr));
        fs.seekp(0);
    }
    else
    {
        fs.open(ID_PATH,ios::out);
    }

   if(type == typeid(Manager))
       id = arr[0]++;
   else if(type == typeid(Department))
       id = arr[1]++;
   else if(type == typeid(Employee))
       id = arr[2]++;

    fs.write((char*)&arr,sizeof(arr));
    fs.close();

    return id;
}

// 获取指令
char get_cmd(char start,char end)
{
    while(true)
    {
        char cmd = getch();
        if(start <= cmd && cmd <= end)
        {
            cout << cmd << endl;
            return cmd;
        }
    }
}

// 任意键继续
void anykey_continue(void)
{
    cout << "请输入任意键继续......" << endl;
    getch();
}

// 显示提示信息
void show_msg(const char* msg,float sec)
{
    cout << msg << endl;
    Sleep(sec*1000);
}
