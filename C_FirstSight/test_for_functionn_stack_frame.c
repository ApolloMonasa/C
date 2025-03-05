#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

///【1.0】寄存器
/// eax
/// ebx
/// ecx
/// edx
/// 上面的我们以前提到过，而下面这俩没提到过的才是理解函数栈帧的关键，他们存放的是地址，用以维护函数栈帧
/// ebp:存高端点地址（栈底地址）
/// esp:存低端点地址（栈顶地址）
/// 每个函数调用都要在栈区上创建函数栈帧

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	//lea==load effective adress
//	//push==压栈：向栈顶放一个元素
//	//pop==出栈：栈顶拿走一个元素
//	int a = 10;
//	int b = 20;
//	int c = 0;
//
//	c = Add(a, b);
//
//	printf("%d\n", c);
//	return 0;
//}
///在VS2013中main函数也被其他函数调用
/// 
/// 