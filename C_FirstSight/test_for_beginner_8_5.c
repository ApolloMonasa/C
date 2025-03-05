//#include <stdio.h>

	//\b可以删除字母，虽然之前说的是回退但不删
//int main()
//{
//	printf("abcdef\b");
//	return 0;
//}

//C语言代码是由一条一条的语句构成的，有五类语句
//1、空语句，一般出现在应该有一个不做事情的语句的地方
//   ；
//2、表达式语句，即表达式的后面出现分号
// a=2；
//3、函数调用语句
// printf（）；
// 4、复合语句，函数的大括号里面的代码构成复合语句，就是代码块
// 5、控制语句用于控制程序的执行流程，以实现程序的各种结构方式（C语言支持三种结构：顺序结构、选择结构、循环结构）
// 他们有特定的语句定义符构成，C语言有9种控制语句。
// 可以分为以下三类：
// （1）条件判断语句也叫分支语句：if语句  switch语句
// （2）循环执行语句：do while语句   while语句     for语句
// （3）转向语句：break语句   goto语句   continue语句   return语句
// C是一种   结构化   的程序设计语言
// 


//注释的俩形式,写注释反映的是一个程序员的基本素质,注释也许在编译时会被替换为1空格
//int main()
//{
//	int a = 10;//创建整型类型的变量，名字叫a，并赋值为10（单行注释）
//	int b = 20;/*创建整型类型的变量，名字叫a，
//	并赋值为20*///（内部可以分行）(不能嵌套)
//	return 0;
//}




////第二讲   C中的数据类型和变量
//1.0数据类型介绍
//C语言提供了丰富的数据类型来描述生活中的各种数据。
//使用整型类型来描述整数，使用浮点型类型来描述小数，使用字符类型来描述字符。
//所谓“类型”，就是相似的数据所拥有的共同特征，编译器只有知道了数据的类型，才知道怎么操作数据。
//1）内置类型（C本身就有的）：a、字符型 b、整型 c、浮点型 d、布尔类型
//2）自定义类型（自创的）：a、数组 b、结构体-struct c、枚举-enum d、联合体-union
///1.1字符型
//char     即character
//[signed] char  有符号的
//unsigned char  无符号的
///1.2整型
//1）短整型short [int]
//[signed] short [int]
//unsigned short [int]
//2）整型
//int
//[signed] int
//unsigned int
//3）长整型
//long [int]
//4）更长的整型（C99引入）
//long long [int]
////////////////////[]中的可以省略
///1.3浮点型(小数也叫浮点数)
//1）float  单精度
//2）double  双精度
//3）long double   C99
///1.4布尔类型(C99)		C语言原来并没有为布尔值单独设置一个类型，而是用整数0表示假，非0值表示真。
//_Bool   表示真假的变量   注意下划线   头文件<stdbool.h>    布尔类型变量取值是：ture or false

//#include <stdio.h>
//#include <stdbool.h>
//#define bool _Bool一个定义，让小写b也可以
//#define false 0
//#define true
//int main()
//{
//	_Bool flag = false;
//	_bool flag2 = true;
//	if (flag)
//		printf("hehe");//false不会打印//true会打印
//	return 0;
//}
///1.5各种数据类型的长度
//每一种数据类型都有自己的长度，使用不同的数据类型，能够创建出长度不同的变量，变量的长度不同，储存的数据范围就有所差异。
//1）sizeof操作符
//sizeof是一个关键字，也是操作符，专门是用来计算sizeof的操作符数的类型长度的，单位是字节byte。
//sizeof的操作数可以是类型，也可以是变量 或者表达式。计算结果是size_t类型的
//sizeof(类型)
//sizeof 表达式
/////////////C规定sizeof(long)>=sizeof(int)   long可能是4可能是8，取决于编译器
//#include <stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(long double));
//	printf("%d\n", sizeof(double));
//  printf("%d\n", sizeof(_Bool));
//  printf("%d\n", sizeof(int));
//
//
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	printf("%zd\n", sizeof(int));
//	printf("%zd\n", sizeof(a));	
//	printf("%zd\n", sizeof a);
//
//	return 0;
//}
//解释size_t来源：sizeof运算符的返回值，C中只规定是无符号整数（0和正整数），并没有规定具体的类型，而是留给系统自己去解决
//不同的系统不一样，这样不利于程序的可移植性。于是C提供了一个解决办法，创造了一个类型别名size_t用来统一表示该类型。
//#include <stdio.h>
//int main()
//{
//	short s = 2;
//	int b = 10;
//	
//	printf("%zd\n", sizeof(s = b + 1));
//
//	printf("s = %d\n", s);
//	return 0;// 验证sizeof 放表达式不会计算表达式规定的计算
//}
////2.0   Introduction to signed and unsigned
// signed关键字，表示一个类型带有正负号，包含负值；
//unsigned关键字，表示该类型不带有正负号，只能表示非负数。
//对于int，默认带正负号，等同于前者。
//int main()
//{
//	signed int a = 1000;
//		a = -200;
//		unsigned int b = 0;
//		b = -200;//会出问题
//
//	return 0;
//}
//char到底有没有符号？？？！取决于编译器，大部分编译器上：char===signed char
//对于有符号的整数打印用%d
//对于无符号的整数打印用%u
//#include <stdio.h>
//int main()
//{
//	signed int num = -100;
//	printf("%d\n", num);
//	printf("%u\n", num);
//
//	return 0;
//}
