#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include <vector>
#include <cstring>
#include <typeinfo>
using namespace std;

#define ID_PATH "id.dat"

// 自动生成一个id
int get_id(const type_info& type);

// 获取指令
char get_cmd(char start,char end);

// 任意键继续
void anykey_continue(void);

// 显示提示信息
void show_msg(const char* msg,float sec);

#endif//TOOLS_H