//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
///【结构体补充】
//struct S
//{
//	int arr[1000];
//	int n;
//};
//
//void set_stu(struct S t)
//{
//	t.n = 200;
//	t.arr[0] = -1;
//	t.arr[1] = -2;
//}
//void Print(struct S t)
//{
//	printf("n=%d\n", t.n);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", t.arr[i]);
//	}
//}
//int main()
//{
//	struct S s = { {1,2,3,4,5,6,7},100 };
//	//写一个函数来改变s
//	set_stu(s);
//	Print(s);
//}
///问题出在哪里呢？
//struct S
//{
//	int arr[1000];
//	int n;
//};
//
//void set_stu(struct S* t)
//{
//	//(*t).n = 200;这是一种写法，还有一种：
//	t->n = 200;
//
//	(*t).arr[0] = -1;
//	(*t).arr[1] = -2;
//}
//void Print(struct S* t)
//{
//	printf("n=%d\n", (*t).n);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", (*t).arr[i]);
//	}
//}
//int main()
//{
//	struct S s = { {1,2,3,4,5,6,7},100 };
//	//写一个函数来改变s
//	set_stu(&s);
//	Print(&s);
//	return 0;
//}
///【总结】结构体指针变量->成员名=欲更改值
///如果只是打印的话，只传值也行，但是还是建议传址，这样可以节省时间和空间。

///第15讲 深入理解指针（5）
/// 【1.0】sizeof和strlen的对比
/// sizeof计算变量所占空间大小，单位是字节，如果操作数是类型的话，计算的是使用类型创建的变量的大小。
/// 即：操作数既可以是变量，也可以是类型，区别是：当操作数是变量的时候，括号可以省略
/// 而strlen是C语言库<string.h>函数，可以计算字符串长度,统计的是\0之前的字符个数,如果没有或提前都会出错，没有就会越界，提前就会少数。
//int main()
//{
//	char ch[] = "abc\0def";
//	printf("%zd", strlen(ch));
//}
/// 【2.0】数组和指针笔试题解析
/// 【1】
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	
//	printf("%zd\n", sizeof(a));
//	printf("%zd\n", sizeof(a+0));
//	printf("%zd\n", sizeof(*a));
//	printf("%zd\n", sizeof(a+1));
//	printf("%zd\n", sizeof(a[1]));
//	printf("%zd\n", sizeof(&a));
//	printf("%zd\n", sizeof(*&a));
//	printf("%zd\n", sizeof(&a+1));
//	printf("%zd\n", sizeof(&a[0]));
//	printf("%zd\n", sizeof(&a[0]+1));
//}
///那上面的函数换成strlen呢？
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	//【须知】strlen参数类型是const char*，字符数组存单个字符的时候结尾不会加\0
//	printf("%zd\n", strlen(arr));//字符数组中不包含\0，所以就会越界往后找\0,随机值
//	printf("%zd\n", strlen(arr+0));//arr是首元素地址，+0不变，等效
//	//printf("%zd\n", strlen(*arr));//arr是首元素地址，解引用之后就是首元素，'a'，值是97，把97作为地址，空间不一定属于当前程序，可能访问冲突
//	//printf("%zd\n", strlen(arr[1]));//98
//	printf("%zd\n", strlen(&arr));//整个数组的地址，在这个程序里面和前面等效，随机值
//	printf("%zd\n", strlen(&arr+1));//随机值
//	printf("%zd\n", strlen(&arr[0]+1));//随机值
//}
//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };//易错点，这里用的(逗号表达式)
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);
//
//	return 0;
//}
/// 【3.0】指针运算笔试题解析
/// 
///  有意思【难题】
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}

//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);//*pa拿到的是"at"中a的地址
//
//
//	return 0;
//}

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n",**++cpp);
//	printf("%s\n",*--*++cpp+3);
//	printf("%s\n",*cpp[-2]+3);
//	printf("%s\n",cpp[-1][-1]+1);
//	return 0;
//}