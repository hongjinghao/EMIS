#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include <vector>
#include <cstring>
#include <typeinfo>
using namespace std;

#define ID_PATH "id.dat"

// �Զ�����һ��id
int get_id(const type_info& type);

// ��ȡָ��
char get_cmd(char start,char end);

// ���������
void anykey_continue(void);

// ��ʾ��ʾ��Ϣ
void show_msg(const char* msg,float sec);

#endif//TOOLS_H