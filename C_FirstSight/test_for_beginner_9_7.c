//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

///****最难的一节****
///第14讲 深入理解指针（4）
///函数指针有一种非常特殊的用途就是实现回调函数；
/// 
///【1.0】回调函数是什么？
/// 回调函数就是一个通过指针调用函数的函数。
/// 如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，被调用的函数就是回调函数。回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。
////回调函数简单举例
//int Add(int x, int y)
//{
//	return x + y;
//}
//void test(int (*pf)(int, int))
//{
//	int ret = (*pf)(4, 5);
//	printf("%d", ret);
//}
//int main()
//{
//	test(Add);
//	return 0;
//}
////【实用案例】计算器简化
//int input = 0, x = 0, y = 0, ret = 0;
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
//void calc(int (*pf)(int, int))
//{
//	printf("请输入两个操作数：\n");
//	scanf("%d %d", &x, &y);
//	ret = pf(x, y);
//	printf("%d\n", ret);
//
//}
//
//int main()
//{
//	
//	do
//	{
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
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

///q---quick,sort---排序
/// 我们之前学过冒泡排序，但是有一个问题，并不是所有类型的数据都能用<>来比较大小，如结构体，字符串等等。
/// 而且数据交换的时候，临时变量到底应该创建什么类型也是不好整的，这些问题都可以用现成的qsort函数解决。
///【2.0】qsort使用举例
/// 【2.1】使用qsort函数排序整型数据
/// qsort函数的使用者得实现一个比较函数
/// 头文件<cstdlib>
/// 接下来来学习一下如何使用：
//void qsort(void* base, size_t num, size_t size,int (*compar)(const void*, const void*));
//四个参数：
// base:指向要排序的数组的第一个对象的指针，转换为 .void*
// num:指向的数组中的元素数。是无符号整型。basesize_t
// size:数组中每个元素的大小（以字节为单位）。是无符号整型。size_t
// compar:指向比较两个元素的函数的指针。此函数被重复调用以比较两个元素。它应遵循以下原型：qsort：int compar(const void* p1, const void* p2);
//如果p1指向的元素小于p2指向的元素，那么函数返回<0的数；
//相等则返回零；
//如果p1指向的元素大于p2指向的元素，返回>0的数。


/// <summary>
/// 实际上，我们使用者在使用时，需要关注比较的对象，比较的标准，比较的顺序。
/// </summary>
//
//struct stu
//{
//	char name[20];
//	int age;
//};
//int arr[10] = { 3,1,9,8,5,4,0,2,7,6 };
//struct stu s[3] = { {"zhangsan",18},{"wangwu",15},{"lisi",25} };
//int s_sz = sizeof(s) / sizeof(s[0]);
//
//int cmp_int(const void* p1, const void* p2)
//{
//	//void*类型的指针不能直接解引用，一般是用来存放地址，函数实现者也不知道是哪种类型，所以就搞成了void*，使用者需要进行强制类型转换之后才能解引用。
//	return  *((int*)p1) - *((int*)p2);
//}
//int cmp_s_age(const void* e1, const void* e2)
//{
//	//这个地方e1应该指向结构体，我们就要强制类型转换成结构体指针。
//	return (*(struct stu*)e1).age - (*(struct stu*)e2).age;
// }
/////注意：名字是字符串，不能直接><比较
/////应该使用strcmp（字符串1，字符串2）
///// 如果字符串1 > 字符串2，就输出>0
//int cmp_name(const void* e1, const void* e2)
//{
//	return strcmp((*(struct stu*)e1).name, (*(struct stu*)e2).name);
//}
//void Print(int arr[10])
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void test1()
//{
//	//qsort默认升序，如果要反序只要反置比较逻辑就行
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//使用qsort排序整型数组arr
//	qsort(arr, sz, sizeof(arr[0]),cmp_int);
//}
//
//void test2()
//{
//	qsort(s, s_sz, sizeof(s[0]), cmp_name);
//}
//int main()
//{
//
//	test1();
//	Print(arr);
//	test2();
//	return 0;
//}
///【出现的问题】
///此处不知道为什么用age排序的时候就是看不到s内部，可能这个工程有问题，在其他工程里面就能看到
///然后在name排序的时候又能看到了

///
///【3.0】qsort函数的模拟实现
/// 在冒泡排序的基础上，改造一个模拟函数来效仿qsort

//int cmp_int(const void* e1, const void* e2)
//{
//	//void*类型的指针不能直接解引用，一般是用来存放地址，函数实现者也不知道是哪种类型，所以就搞成了void*，使用者需要进行强制类型转换之后才能解引用。
//	return  *((int*)e1) - *((int*)e2);
//}
//
//swap(char* buf1, char* buf2, size_t width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{//一个字节一个字节地交换
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//void bubble_sort(void* base, size_t num,size_t width,int (*cmp)(const void* e1,const void* e2))
//{
//	int i = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			//if (arr[j] > arr[j + 1])
//			if(cmp((char*)base + j * width, (char*)base + (j + 1) * width)>0)//升序，>0
//				//函数内部给第四个参数指向的函数传参
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
//			}
//		}
//	}
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
////测试这个函数排序整型数组
//void test3()
//{
//	int arr[10] = { 3,4,5,6,2,1,8,9,7,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//
//}
//int main()
//{
//	test3();
//}
/// 【总结】我认为应该理解的还是各个参数的作业和代码中的精妙之处，比较出乎我意料的是，一个字节一个字节的交换方式。这就是泛型编程