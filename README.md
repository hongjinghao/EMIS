﻿知识点：

​	MCV架构

​		Mode 数据模型层

​		Ctrl 访问控制层

​		View 视图界面层

​	单例模式：

​		静态成员、静态成员函数、私有化构造、拷贝构造、饿汉模式

​	接口技术：

​		继承、虚函数、纯虚函数-》多态

​	运算符重载：

​		输入输出运算符重载为全局函数，友元

​	IO流的二进制、文本输入输出

​		Windows系统的二进制与文件有明显的区别，Linux系统则无所谓。

​		文本模式输入输出时可以借助重载的输入输出运算符

​	vector容器

​		顺序表，可以自动调整空间

​		push_back size [] erase iterator begin end

​	MD5验证

​		是一种单向不可逆的加密算法，明文 -》MD5 -》32位的密文，用户密码验证、文件完整性验证。

遇到的问题：

​	二进制读写时成员有string类型，写入到文件中没有意义。

实现层的析构函数调用问题：

​	接口层的析构函数声明为虚函数


