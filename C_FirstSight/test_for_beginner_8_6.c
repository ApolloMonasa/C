//整数变量声明为unsigned的好处是，同样的长度的内存能够表示的最大整数值增大了一倍。
//比如16位的digned short int的取值范围是-32768---32767；而unsigned short int 的取值范围是0---65535.32位的signed int 的取
//值可以参看limits.h中给出的定义。


////3.0数据类型的取值范围
//如果要查看当前系统上数据类型的极限值：
//limits.h这个头文件中说明了整型类型的取值范围
//float.h这个头文件中说明了浮点型类型的取值范围
//为了代码的可移植性，需要知道某种整数类型的极限值时，应该尽量使用这些变量
//SCHAR_MIN,,ACHAR_MAX   signed char的最值
//SHRT_MIN,SHRT_MAX   short的最值
//INT_MIN,INT_MAX
//LONG_MIN,LONG_MAX
//LLONG_MIN,LLONG_MAX
//UCHAR_MAX//你其实会发现U开头的都只有最大值
//USHRT_MAX
//UINT_MAX
//ULONG_MAX
//ULLONG_MAX


////4.0变量
///4.1变量的创建
//什么是变量？C中把经常变化的值称为变量，不变的值称为常量。
//变量创建的语法形式是这样的：
//data_type name
//    |      |
//数据类型 变量名
//int age
//char ch
//double weight
//变量在创建的时候给一个值叫做初始化，不初始化就不能拿来用（在一些严格的编译器中）
//#include <stdio.h>
//int main()
//{
//	unsigned int age = 10;//初始化
//	age = 20;//赋值
//
//	printf("%u\n", age);
//
//	char ch = 'q';
//	float score = 3.14f;//f的作用是改变数据类型，从double改为float
//	double weight = 4.1;
//
//	return 0;
//}

///4.2变量的分类
//1）全局变量：大括号之外，可以在整个工程中使用
//2）局部变量：大括号之内，只能在所属大括号内使用
//int main()
//{
//	{
//		int num = 100;
//		printf("%d\n", num);
//
//	}
//	printf("%d\n", num);//报错了
//	return 0;
//}
//如果全局变量和局部变名字相同会怎么样？？就近原则：局部优先
//全局变量和局部变量在内存中储存在哪里？？
//学习语言我们会关注内存中的三个区域：栈区  堆区  静态区
//栈区储存局部变量函数参数   堆区用来动态内存管理，malloc，calloc，realloc，free
//静态区储存全局变量，静态变量