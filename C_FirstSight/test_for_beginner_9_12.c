//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//#include <Windows.h>
//#include <math.h>
//

///第19讲 自定义类型：结构体
/// 【1.0】结构体类型的声明
/// 【1.1】结构体回顾
/// 结构是一些值的集合，这些值称为成员变量，结构的每个成员可以是不同类型的变量
/// 【1.1.1】结构的声明
//struct As
//{
//	member_list;
//}variable_list;
// 
// 
//struct Stu
//{
//	char name[20];
//	int age;
//}s1,s2,s3;
//int main()
//{
//	struct Stu s1 = { "ZhangSan",18 };
//	struct Stu* ps = &s1;
//	printf("%s", s1.name);
//	return 0;
//}
///【1.2】特殊声明
/// 匿名结构体,只能用一次，声明的同时才能创建变量
//struct
//{
//	char c;
//	int i;
//	double d;
//}s,t;
//
//struct
//{
//	char c;
//	int i;
//	double d;
//}* p;
//
//int main()
//{
//	t.i = 200;
//	printf("%d\n", t.i);
//	s.i = 100;
//	printf("%d", s.i);
//	p = &s;//会警告，编译器认为这是两种不同的类型
//	return 0;
//}
///【1.3】结构的自引用
/// 【错误示范】
//struct Node
//{
//	int date;//大小是4
//	struct Node n;//大小不一定
//};
///直接把同类型结构体往结构体里面放是不行的
//struct Node
//{
//	int date;
//	struct Node* next;//存放下一个结点的地址
//};
///但是在一个结构体中包含一个指向同类型的结构体的指针变量是可以的
///【typedef】
//typedef struct Node
//{
//	int date;
//	Node* next;
//}Node;
//重命名产生的新名字不能在重命名时使用
/// 【2.0】结构体变量的创建和初始化
/// 
/// 【3.0】结构体成员访问操作符
/// 在C语言中，结构体是一种用户自定义的数据类型，它允许你将多个不同或相同类型的数据项组合成一个单一的数据结构。结构体成员访问操作符是 . （点操作符）和 -> （箭头操作符），它们用于访问结构体中的成员。
//1. 点操作符（ .）
//点操作符用于访问结构体变量的成员。它的使用格式如下：
//struct_name.variable_name;
//这里， struct_name 是结构体变量的名称， variable_name 是结构体中的成员。
//示例代码：
//#include <stdio.h>
//
//// 定义一个结构体
//struct Student {
//    char name[50];
//    int age;
//    float marks;
//};
//
//int main() {
//    // 创建结构体变量
//    struct Student student1;
//
//    // 使用点操作符访问成员
//    student1.name = "John Doe";
//    student1.age = 20;
//    student1.marks = 92.5;
//
//    // 打印结构体成员
//    printf("Name: %s\n", student1.name);
//    printf("Age: %d\n", student1.age);
//    printf("Marks: %.2f\n", student1.marks);
//
//    return 0;
//}
//2. 箭头操作符（ ->）
//箭头操作符用于访问指向结构体的指针所指向的结构体的成员。它的使用格式如下：
//pointer_name->variable_name;
//这里， pointer_name 是指向结构体的指针， variable_name 是结构体中的成员。
//示例代码：
//#include <stdio.h>
//
//// 定义一个结构体
//struct Student {
//    char name[50];
//    int age;
//    float marks;
//};
//
//int main() {
//    // 创建结构体变量
//    struct Student student1;
//    struct Student* ptr;
//
//    // 初始化指针
//    ptr = &student1;
//
//    // 使用箭头操作符访问成员
//    ptr->name = "John Doe";
//    ptr->age = 20;
//    ptr->marks = 92.5;
//
//    // 打印结构体成员
//    printf("Name: %s\n", ptr->name);
//    printf("Age: %d\n", ptr->age);
//    printf("Marks: %.2f\n", ptr->marks);
//
//    return 0;
//}
//在这两个示例中，我们定义了一个 Student 结构体，并通过点操作符和箭头操作符访问了其成员。记住，使用箭头操作符时，必须确保指针已经被正确初始化，指向一个有效的结构体实例。
//
/// 【4.0】结构体内存对齐
/// 我们已经掌握了结构体的基本使⽤了。
/// 现在我们深⼊讨论⼀个问题：计算结构体的⼤⼩。
/// 这也是⼀个特别热⻔的考点:结构体内存对⻬
/// 【4.1】对齐规则
/// 1.结构体的第一个成员对齐到和结构体变量起始位置偏移量为0的地址处
/// 2.其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处
/// 对齐数==编译器默认的一个对齐数 与 该成员变量大小的较小值
/// VS中的默认值是8
/// Linux中gcc没有默认的对齐数，对齐数就是成员变量本身的大小
/// 3.[结构体总大小为最大对齐数的整数倍]****易错
/// 4. 如果嵌套了结构体的情况，嵌套的结构体成员对⻬到⾃⼰的成员中最⼤对⻬数的整数倍处，结构体的整体⼤⼩就是所有最⼤对⻬数（含嵌套结构体中成员的对⻬数）的整数倍。

//struct S1
//{
//	char c1;//1
//	char c2;//1
//	int n;//4
//	//1+1+（1+1）+4=8
//};
//
//struct S2
//{
//	char c1;//
//	int n;//4
//	char c2;//1
//	//1+（3）+4+1==9
//	///那为什么不是9呢？
//	//因为总大小为最大对齐数的整数倍，所以就是8+4==12
//};
//
//int main()
//{
//	printf("%zd\n", sizeof(struct S1));
//	printf("%zd\n", sizeof(struct S2));
//	printf("%zd\n", sizeof(struct S3));
//	return 0;
//}

//第四条
//struct S1
//{
//	char c1;//1
//	char c2;//1
//	int n;//4
//	//1+1+（1+1）+4=8
//};
//
//struct S2
//{
//	char c1;//1
//	int n;//4
//};
//
//struct S3
//{
//	char c1;//1
//	int n;//4
//	char c2;//1
//	struct S2 s;//8(4)
//	//1+(3)+4+1+(3)+8==20
//};
//
//int main()
//{
//	printf("%zd\n", sizeof(struct S1));
//	printf("%zd\n", sizeof(struct S2));
//	printf("%zd\n", sizeof(struct S3));
//	return 0;
//}

///【4.2】 为什么存在内存对⻬?
//⼤部分的参考资料都是这样说的：
//1. 平台原因(移植原因)：
//不是所有的硬件平台都能访问任意地址上的任意数据的；某些硬件平台只能在某些地址处取某些特定
//类型的数据，否则抛出硬件异常。
//2. 性能原因：
//数据结构(尤其是栈)应该尽可能地在⾃然边界上对⻬。原因在于，为了访问未对⻬的内存，处理器需要
//作两次内存访问；⽽对⻬的内存访问仅需要⼀次访问。假设⼀个处理器总是从内存中取8个字节，则地
//址必须是8的倍数。如果我们能保证将所有的double类型的数据的地址都对⻬成8的倍数，那么就可以
//⽤⼀个内存操作来读或者写值了。否则，我们可能需要执⾏两次内存访问，因为对象可能被分放在两
//个8字节内存块中。
///总之：就是用空间换取效率或者说时间
///那么在设计结构体的时候，就可以利用这个性质实现空间最大化利用

///【4.3】修改默认对齐数
/// #pragma 这个预处理指令，可以改变编译器的默认对⻬数。

//#include <stdio.h>
//#pragma pack(1)//设置默认对⻬数为1
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()//取消设置的对⻬数，还原为默认
//
//int main()
//{
//	//输出的结果是什么？
//	printf("%zd\n", sizeof(struct S));
//	return 0;
//}

/// 【5.0】结构体传参

//struct S
//{
//	int data[1000];
//	int num;
// };
//struct S s = { {1,2,3,4}, 1000 };
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s);
//	print2(&s); 
//	return 0;
//}

///两个打印函数哪个更好呢？
/// 答案是：print2
/// 原因：
//函数传参的时候，参数是需要压栈，会有时间和空间上的系统开销。
//如果传递⼀个结构体对象的时候，结构体过⼤，参数压栈的的系统开销⽐较⼤，所以会导致性能的下降。
///结论：结构体传参最好传地址

/// 【6.0】结构体实现位段
///结构体讲完就得讲讲结构体实现【位段】的能力
/// 【6.1】什么是位段
/// 位段的声明和结构是类似的，有两个不同：
/// 1.位段的成员必须是：int unsignedint signedint，在C99中也可是其他
/// 2.位段的成员后边有一个冒号和一个数字

//struct A
//{
//	int _a : 2;//+4
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;//+4
//	//数字代表所占比特位
//	//2+5+10+30==47
//	//还是不对，那就还要了解位段的内存分配
//}s;
//
//int main()
//{
//		s._a = 10;//1010-截断-10
//		s._b = 12;//1100
//		s._c = 3;//0011
//		s._d = 4;//0100
//		///  0000 0000   0000 0000   0000 0001   1011 0010     0000 0000   0000 0000   0000 0000   0000 0100 
//		///  00 08 01 b2 00 00 00 04
//	printf("%zd", sizeof(struct A));
//	return 0;
//}
/// 【6.2】位段的内存分配
/// 1. 位段的成员可以是int，unsigned ，signed int或者是char等类型
///2. 位段的空间上是按照需要以4个字节（int）或者1个字节（char）的⽅式来开辟的。
///3. 位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使⽤位段。
/// 
//struct A
//	{
//		char _a : 3;
//		char _b : 4;
//		char _c : 5;
//		char _d : 4;
//	}s;
//	
//	int main()
//	{
//		//下面探究分配方法
//		struct A a = { 0 };
//		s._a = 10;//1010-截断-010
//		s._b = 12;//1100
//		s._c = 3;//0011
//		s._d = 4;//0100
//		///按照假设，-栈区先用高位再用低位，存储放置由低到高，内存应该是这样的：
//		///01100010 00000011 00000100
//		/// 62        03        04
//
//
//		printf("%zd\n", sizeof(struct A));
//		printf("%zd\n", sizeof(a));
//		return 0;
//	}
///【6.3】位段的跨平台问题
///int位段被当成有符号数还是无符号数是不确定的
/// 位段中最大位的数目不能确定。（16位机器最大16，32位机器最大32）
/// 位段中的成员在内存中从高向低还是从低到高分配标准尚未定义
/// 当一个结构包含两个位段，第二个位段成员比较大，无法容纳于第一个位段剩余的位时，是舍弃剩余的位还是利用是不确定的
/// 【6.4】位段的应用
/// 网络协议中，IP数据报的格式，很多属性只需要几个bit位就能描述
/// 【6.5】位段注意事项
/// 位段的⼏个成员共有同⼀个字节，这样有些成员的起始位置并不是某个字节的起始位置，那么这些位置处是没有地址的。内存中每个字节分配⼀个地址，⼀个字节内部的bit位是没有地址的。
///所以不能对位段的成员使⽤& 操作符，这样就不能使⽤scanf直接给位段的成员输⼊值，只能是先输⼊放在⼀个变量中，然后赋值给位段的成员