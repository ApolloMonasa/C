//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
///第八讲 VS实用调试技巧
/// Debug是调试版本，这样编译产生的是debug版本的可执行程序，其中包含调试信息，是可以直接调试的。
/// release称为发布版本，往往进行了各种优化，这个版本是用户使用的，无需也不能调试，不包含调试信息，往往同一个文件产生的release版本的可执行程序更小。
/// Debug文件夹放的是Debug版本的程序，Release同理。
/// 通常，测试工程师测的应该是Release版本
/// 【****调试快捷键****】
/// 【F9】创建断点和取消断点，断点还可以设置条件，右键就可以设置
/// 断点的作用是可以在程序的任意位置设置断点，打上断点就可以使得程序执行到想要的位置时暂停执行，接下来我们就可以使用【F10】【F11】这些快捷键，观察代码执行的小细节；
/// 【F5】启动调试，经常用来直接跳到下一个断点处(可能同一个断点会停留多次，即在循环中)，一般和【F9】配合使用
/// 【F10】逐过程，通常用来处理一个过程，可以是一次函数调用，或者是一条语句。
/// 【F11】逐语句，就是每次都执行一条语句，但是这个快捷键可以让我们的执行逻辑进入函数内部，在函数调用的地方，想进入函数观察细节，必须使用【F11】，如果用【F10】就会直接完成函数的调用
/// 【Ctrl+F5】开始执行不调试，如果你想让程序直接运行起来而不调试就可以直接使用。
/// VS更多快捷键了解：  https://blog.csdn.net/mrlisky/artical/details/72622009
/// 
///【实验代码】
//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = 10 - i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

///【***监视和内存观察***】
///
//int main()
//{
//	int arr[10];
//	int num = 100;
//	char c = 'w';
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//
// 		arr[i] = i;
//	}
//	return 0;
//}

//int facterial(int num)
//{
//	if (num == 0)
//		return 1;
//	else
//	{
//		return facterial(num - 1) * num;
//	}
//}
//int main()
//{
//	int sum = 0;
//	for (int i = 1; i <= 10; i++)
//	{
//		printf("%d\n", facterial(i));
//		sum += facterial(i);
//
//	}
//	printf("+++=\n%d\n", sum);
//}

//在VS2022，debug，x86环境下执行以下代码,会进入死循环，原因是，在给arr[12]赋值为0的时候，把i也赋值为0了，这是因为，arr[12]和i的地址一样，i永远无法超过12
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;//这里是i就会崩溃，会报错：Stack around the variable 'arr' was corrupted.//就是说，arr周围的堆栈被损坏，原因是，内存越界
//
//		printf("hehe ");
//	}
//	return 0;
//}

//【补充】默认x86情况下(x64和releasse版本相反)，栈区的使用习惯是，先使用高地址处的空间，再使用地址处的空间，而数组随着下标的增长，地址是由低到高的。 而正好，在这个环境下，i和arr地址刚刚就是距离那么远（2int），刚刚好就是这样，这个代码是设计出来的
//VC6.0是连续的；gcc是空2int(这种真在笔试里面考过)
//上面这题出自于《C陷阱和缺陷》

//监视二维数组board,11才能看完11行，只有数组名只能看到每一行第一个元素，观察一维数组，在进行传参调试进入函数内部时，无法读取，写上【数组名，数字】才能读取。

///【编程中常见的错误】
/// 1.编译错误：编译期间发生，一般都是语法错误，双击错误可以光标定位
/// 2.链接错误：链接期间发生，代码LNK---link，一般是头文件未包括，函数未定义就被调用，函数名字拼写错误，双击无反应
/// 3.运行时错误：调试解决
///
/// 
/// 
/// 第九讲  【********函数递归*********】
/// 【1.0】.递归是什么---大事化小
/// 
/// 递归是学习C语言的时候绕不开的一个话题，什么是递归？
/// "递归"这个词来源于拉丁语"recursus"，意味着"跑回来"或"返回"。在数学和计算机科学中，递归的概念指的是一种方法或过程，它重复地应用自身来解决问题。这个名字的含义反映了递归函数调用自身的特性，就像一个循环一样，但与循环不同的是，递归有一个明确的退出条件，以避免无限循环。
///递归这个名字准确地描述了递归函数的行为：它“跑回来”或“返回”到自身，通过重复相同的操作来逐步解决问题。递归通常用于处理可以自然分解为相似子问题的问题，例如树的遍历、排序算法、图的搜索等。
/// 递归其实是一种解决问题的方法，也是一种编程技术，它允许函数调用自身来解决问题，递归函数有两个主要部分，【1】基本情况base case【2】递归步骤recursive step
/// 【史上最简单的递归】
//int main()
//{
//	printf("hehe\n");//Stack overflow 栈溢出了
//	main();
//	return 0;
//}
/// 
/// 【2.0】.递归的限制条件
/// 
///就是有base case和recursive step两个部分，其中每次递归之后都更加接近base case 
/// 
/// 【3.0】.递归的举例
/// 
///【1】 阶乘
//int facterial(int num)
//{
//	if (num == 0)
//		return 1;
//	else
//	{
//		return facterial(num - 1) * num;
//	}
//}
//int main()
//{
//	int sum = 0;
//	for (int i = 1; i <= 10; i++)
//	{
//		printf("%d\n", facterial(i));
//		sum += facterial(i);
//
//	}
//	printf("+++=\n%d\n", sum);
//}
///【补充】在C语言中，每一次函数调用，都要为这次函数调用在栈区申请一块内存空间，用来为这次函数调用存放信息，这一块空间叫做：【运行时堆栈】/【函数栈帧空间】,这个过程涉及函数栈帧的创建和销毁，会因编译器不同而有差异
/// 【2】顺序打印一个正整数的每一位

//void Print(int m)
//{
//	if (m > 9)
//	{
//		Print(m / 10);
//	}
//	printf("%d ", m % 10);
//}
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	Print(m);
//	return 0;
//}
/// 如果采用递归的方式完成代码，递归层次非常深，会占用太多的栈帧空间，可能会溢出，但好处是简洁方便。

/// 【4.0】.递归与迭代
/// 如果不想采用递归，就通常采用迭代，一般以循环方式实现
/// 【斐波那契数列】

//【递归】
//int count = 0;
//Fib(int i)
//{
//	switch (i)
//	{
//	case 1:
//	case 2:
//		return 1;
//		break;
//	case 3:
//		count++;
//		return 2;
//		break;
//	default:
//		return Fib(i - 2) + Fib(i - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Fib(n));
//	printf("count=%d\n", count);
//	return 0;
//}
//这样算，会进行大量重复计算，导致运算效率低下，运算时间过长。

//【迭代】
//int Fib(int i)
//{
//	int a = 1, b = 1, c = 0;
//	if (i <= 2)
//		return 1;
//	while (i > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		i--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", Fib(n));
//
//	return 0;
//}

///【拓展学】青蛙跳台阶问题
/// 一只青蛙一次可以跳1/2个台阶，这只青蛙跳到第n个台阶，有多少跳法？发现没？依旧是斐波那契
///【拓展学】汉诺塔问题 比特大博哥
//#include <stdio.h>
//int main()
//{
//
//	return 0;
//}