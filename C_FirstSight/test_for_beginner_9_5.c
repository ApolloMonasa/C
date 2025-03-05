//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
///第13讲 深入理解指针（3）
/// 【1.0】字符指针变量
/// 我们其实已经很清楚这个概念
//int main()
//{
//	char ch = 'w';
//	char* pch = &ch;
//
//	char* ps = "abcdef";//这种赋值是把字符串中首字母的地址赋值给ps
//	//这不是把这个字符串存进指针变量了，如何理解？
//	char arr[] = "abcdef";
//	char* p = arr;
//	//那这个能理解吗？
//	//arr数组是连续的空间，并且数组是可变的
//	//常量字符串abcdef\0存在内存中也是连续的，但是不可修改
//	//我们完全可以把常量字符串理解成一个字符数组
//	printf("%c", arr[2]);
//	printf("%c", "abcdef"[2]);
//	//但是呢，这种写法并不严谨，有可能造成写入访问冲突，不能修改常量字符串
//
//	return 0;
//}

//判断结果：
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//
//	const char* str3 = "hello bit.";
//	const char* str4 = "hello bit.";
//
//	if (str1 == str2)
//		printf("str1_andstr2 are same\n");
//	else
//		printf("str1_and_str2 are not same\n");
//
//	if (str3 == str4)
//	{
//		printf("str3_andstr4 are same\n");
//	}
//	else
//		printf("str3_and_str4 are not same\n");
//	return 0;
//}

/// 【2.0】数组指针变量
/// 【2.1】是什么？
/// 我们来类比：
/// 字符指针变量--变量---存放的是字符指针
/// 整型指针变量--变量---存放的是整型指针
/// 数组指针变量--变量---存放的是数组指针
//int main()
//{
//	int arr[10] = { 0 };
//	int (*parr)[10] = &arr;//数组的地址，parr就是数组指针变量，这句话声明了一个指针parr，它指向一个包含10个整型的数组
//	//[注意][]里面的10不能省略，这个指针指向多大的数组必须清清楚楚
//	//通过(*parr)[i]可以访问数组的元素，其中i是索引
//	char ch[20] = { 0 };
//	char (*pch)[20] = &ch;
//
//	int* arr2[6];
//	int* (*parr2)[6]= &arr2;
//	///【最终解释】：p先和*结合，以说明p是一个指针变量，然后指针指向的是一个大小为10个整型的数组。（分三部分：指向数组元素类型+（*指针变量名）+[数组元素个数]）所有p是一个指针，指向一个数组，叫做数组指针
//	//这里要注意：[]的优先级要高于*，所以必须加上（）来保证o先和*结合
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int (*p)[10] = &arr;
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *((int*)p + i));
//		//我们用强制类型转换配合指针+-整数来打印全部元素。
//		printf("%d ", (*p)[i]);
//		//这一层理解：*p==arr,解引用之后相当于数组名--->非常有用
//		//到此处，你会发现这种用法特别僵硬，脱了裤子放屁，那究竟怎么自然地使用起来呢，接下来在二维数组传参中解答。
//	}
//	return 0;
//}

/// 【3.0】二维数组传参的本质
/// 

//void Print(int arr[3][5], int r, int c)
//{
//	int i = 0, j = 0;
//	for (; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
//	Print(arr, 3, 5);
//	return 0;
//}

///二维数组传参，实参也是数组名，数组名是数组首元素的地址，既然实参传过去的是地址，形参就可以写成指针变量
/// 可是我们应该知道二维数组的首元素是谁？答案是其第一行数组int arr[5]

//void Print(int (*p)[5], int r, int c)
//{
//	int i = 0, j = 0;
//	for (; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", p[i][j]);
//			printf("%d ", *(*(p + i) + j));
//			//这里基于数组指针的解引用相当于数组名，数组名相当于其首元素地址，[]相当于*（ + ）
//			//p[i]理解成了第i+1行的数组名，又被[]操作符取首元素地址加j后解引用，就达到了访问数组元素的效果。
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
//	Print(arr, 3, 5);
//	return 0;
//}
///【总结】二维数组传参，形参的部分可以写成数组，也可以写成指针形式。

/// 【4.0】函数指针变量
/// 【4.1】创建
/// 什么是函数指针变量呢，根据类别我们不难得出：函数指针变量应该是用来存放函数地址的，未来通过地址能够调用函数。
/// 那么函数是否有地址呢？
/// 我们做个测试：
//int test(int x ,int y)
//{
//	return x + y;
//}
//int main()
//{
//	printf("%p\n", &test);
//	printf("%p\n", test);
//	return 0;
//}
///看来函数确实还是有地址的 ，并且，打印取地址函数名和函数名拿到的都是其地址。
//int test(int x ,int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int (*p)(int x,int y) = &test;//xy可以不写
//	//这种写法很像数组指针变量类型的写法
//	return 0;
//}

///到这里我们就必须理解一个东西了,关于*,我们必须明确是给变量名准备的
//int main()
//{
//	int* p, q;
//	//可以看到，这里p是指针，q是整型
//	return 0;
//}

///那么问题来了，这玩意怎么用呢？无非就是*p==函数，没什么好举例的。
/// 其实不解引用也是可以的，即:p==函数，而且因为这个设计，乱写都可以，比如：（*****p)==函数
/// 
/// 【写法说明】int (*p)(int,int)
/// 其中：int 声明函数的返回类型，p是指针变量名，int, int是函数参数和个数的交代
/// 
/// 【4.2】使用
/// 其实已经讲到
/// 【4.3】两段有趣的代码
/// 均出自《C陷阱和缺陷》
//int main()
//{
//	(*(void(*)())0)();
//	//理解：void(*)()是一个函数指针类型，这段代码是将0强制类型转换成函数指针类型，然后解引用，最后那个()是函数调用操作符
//	void (*signal(int,  void(*)(int) ) )(int);
//	//signal是函数名，这句代码是signal的函数声明，它有俩参数，第一个是int类型，第二个是void(*)(int)这样的函数指针类型，该函数指针能够指向的函数参数是int类型，返回类型是void
//	//signal的返回类型也是这样的函数指针类型。
//
//	return 0;
//}
/// 【4.3.1】typedef关键字
/// 这是用来类型重命名的，可以将复杂的类型简单化。
/// 比如，你觉得unsigned int，写起来不方便，如果写成uint就方便多了，那么就可以这样写
//typedef unsigned int unit;
//那么指针类型也能重命名
//typedef int* ptr_t;
//并且和原来的写法有功能上的差异
//ptr_t p1, p2;
//这两个都是int*类型
//typedef int(* pr)[];
//到这里想必已经理解数组指针名就要放在*后面了吧
//pr p = 0;
//函数指针变量重命名也类似
/// 那么用这个关键字就可以把前面那个复杂的声明给极大程度地简化。
/// 【5.0】函数指针数组
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int (*pa)(int, int) = &Add;
//	int (*ps)(int, int) = &Sub;
//	//函数指针数组：存放函数指针数组
//	int(*parr[5])(int, int) = { &Add,&Sub };
//	//parr先和[]结合说明是数组，内容是什么 呢？是int(*)()类型的函数指针
//
//}

///函数指针数组的应用
/// 【案例项目】写一个计算器，能完成整数的：加减乘除
//void menu()
//{
//	printf("*************************\n");
//	printf("**** 1.add     2.sub ****\n");
//	printf("**** 3.mul     4.div ****\n");
//	printf("****      0.exit     ****\n");
//	printf("*************************\n");
//
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//
//int main()
//{
//	int input = 0, x = 0, y = 0,ret=0;
//	do
//	{
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret=Add(x, y);
//			printf("%d\n", ret);
//
//			break;
//		case 2:
//			printf("请输入两个操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret = Sub(x, y);
//			printf("%d\n", ret);
//
//			break;
//		case 3:
//			printf("请输入两个操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret = Mul(x, y);
//			printf("%d\n", ret);
//
//			break;
//		case 4:
//			printf("请输入两个操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret = Div(x, y);
//			printf("%d\n", ret);
//
//			break;
//		case 0:
//			printf("退出计算机\n");
//			break;
//		default:
//			printf("选择错误，重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//void menu()
//{
//	printf("*************************\n");
//	printf("**** 1.add     2.sub ****\n");
//	printf("**** 3.mul     4.div ****\n");
//	printf("****      0.exit     ****\n");
//	printf("*************************\n");
//
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
///// <summary>
///// 【改造】
///// </summary>
///// <returns></returns>
//
//int main()
//{
//	int input = 0, x = 0, y = 0, ret = 0;
//	int(*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div };//下标对应选项
//	do
//	{
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret = pfArr[input](x,y);
//			printf("%d\n", ret);
//
//		}
//		else if (input == 0)
//		{
//			printf("退出计算机\n");
//			break;
//		}
//		else
//		{
//			printf("选择错误,重新选择：\n");
//		}
//	} while (input);
//	return 0;
//}

///这样的写法只需要在数组里面加函数，然后进行少量修改，就可以跑起来了，大大减少了代码数量
/// 这样的方式可以替代switch提供跳转的功能，我们叫它转移表。
/// 【6.0】转移表
