//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
////5.0 switch语句
//除了if语句之外，C语言还提供了switch语句来实现分支结构。
//switch语句是一种特殊形式的if...else结构，【用于判断条件有多个结果的情况】。它把多重的else if改成更易用、可读性更好的形式。
//【写法】
//switch(expresion){
// case value1:
//     statement;
// case value2:
//     statement;
// default:
//     statement;
// }
//上面的代码中，根据表达式expresion不同的值，执行相应的case。如果找不到相应的值，就执行default分支。
//【注】switch后面的expresion必须是【整型表达式】；case后面的值必须是【整型常量表达式】。
///5.1 if语句和switch语句的对比
//【例子】输入任意一个整数值，计算除3之后的余数
//【if】
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n % 3 == 0)
//		printf("余数是0");
//	else if (n % 3 == 1)
//		printf("余数是1");
//	else
//		printf("余数是2");
//	return 0;
//}
//【switch】///【注意】不在分支末尾加上break会出问题，会从这个地方一直执行到底，即所谓的贯穿效应（fall-through）,只有加上才可以跳出这个switch语句
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	switch (n % 3)
//	{
//	case 0:
//		printf("余数是0");
//		break;
//	case 1:
//		printf("余数是1");
//		break;
//	default:
//		printf("余数是2");
//		break;
//	}
//	return 0;
//}
//【练习】输入数字输出对应的星期几
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	switch (n)
//	{
//	case 1:printf("星期一");
//		break;
//	case 2:printf("星期二");
//		break;
//	case 3:printf("星期三");
//		break;
//	case 4:printf("星期四");
//		break;
//	case 5:printf("星期五");
//		break;
//	case 6:printf("星期六");
//		break;
//	case 7:printf("星期日");
//		break;
//
//	}
//
//	return 0;
//}
//【变式】工作日和休息日//利用贯穿效应
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	switch (n)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:printf("工作日");
//		break;
//	case 6:
//	case 7:printf("休息日");
//		break;
//	default:printf("输入错误");
//	}
//
//	return 0;
//}
//【注意】switch中的分句default随便放哪里都可以，分支之间没有顺序要求。



//三种循环   while  for  do...while

////6.0 while循环
//while语句和if语句非常相似
//【形式】while（表达式）{循环体}//不用大括号时候与if一样只管一句
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//可以试试把if改成while
//	if (n > 0)
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}
//【例子】在屏幕上打印1到10
//int main()
//{
//	int n = 1;
//	while (n<=10)
//	{
//		printf("%d\n", n);
//		n++;
//	}
//	return 0;
//}
//【练习】输入一个正的整数，逆序打印这个整数的每一位
//int main()
//{
//	int num,a = 0;
//	scanf("%d", &num);
//	while (num != 0)
//	{
//		a = num % 10;
//		printf("%d ", a);
//		num = num / 10;//n /= 10也可以
//	}
//	return 0;
//}
//【那么如何顺序打印呢？】

////7.0 for循环
//for循环是三种循环中使用最多的，for循环的语法形式如下
//for(表达式1；表达式2；表达式3）
//   语句；//如果循环体想包含更多的语句加大括号
//【表达式1】用于循环变量的初始化
//【表达式2】用于循环结束条件的判断
//【表达式3】用于循环变量的调整
//使用for循环打印1到10
//int main()
//{
//	for (int a = 1; a < 11; a++)
//		printf("%d", a);
//	return 0;
//}