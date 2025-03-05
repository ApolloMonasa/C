//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>


///第20讲 自定义类型：联合和枚举
///【1.0】联合体类型的声明
/// 像结构体一样，联合体也是由一个或多个成员构成，这些成员可以是不同的类型。
/// 但是编译器只为最大的成员分配足够的内存空间。联合体的特点是所有成员共用同一块内存空间，所以联合体也叫做：共用体。
/// 给联合体其中一个成员赋值，其他成员的值也跟着变化。

//struct S
//{
//	char n;
//	int j;
//}s;
//
//union U
//{
//	char c;
//	int i;
//}u;
//
//int main()
//{
//	printf("%zd\n", sizeof(s));
//	printf("%zd\n", sizeof(u));
//
//	u.c = 97;
//	printf("%c %d\n", u.c,u.i);
//	printf("&u.i==%p\n", &u.i);
//	printf("&u.c==%p\n", &u.c);
//	return 0;
//}

/// 【1.2】联合体的特点
/// 共用空间,可以用来节省空间，用于某些特有信息的记录
/// 【1.3】相同成员的联合体和结构体对比
/// 内存利用程度不同，联合体不会浪费空间
/// 【1.4】联合体大小计算
/// 联合体的大小至少是最大成员的大小
/// 当最大成员大小不是最大对齐数的整数倍时，就要对齐到最大对齐数整数倍处

//union U
//{
//	char c[5];//5------最大对齐数1
//	int i;//4----------最大对齐数4
//}u;
//
//int main()
//{
//	printf("%zd\n", sizeof(u));
//	return 0;
//}

/// 【1.5】练习
/// 【大小端判断】

//union U
//{
//	int i;
//	char c;
//}u;
//
//int main()
//{
//	u.i = 1;
//	if (u.c == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}

/// 【2.0】枚举类型 
/// 顾名思义就是把可能的取值一一列举

//enum Sex
//{
//	//枚举的可能值
//	MALE,//枚举常量
//	MIDDLE,
//	FEMALE=4,
//	SECRET
//};
//
//int main()
//{
//	printf("%d\n", MALE);
//	printf("%d\n", MIDDLE);
//	printf("%d\n", FEMALE);
//	printf("%d\n", SECRET);
//	return 0;
//}

/// 【2.1】枚举类型的声明
/// 【2.2】枚举类型的特点
/// 【2.3】枚举类型的使用