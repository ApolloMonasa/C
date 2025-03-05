//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
////第三讲 分支与循环
///1 If语句
//1.1 if and else
//【语法】if(表达式)
//           语句
//【else与之同理】
//【规则】表达式成立（为真）则语句执行；反之则不执行。C中0为假非0为真
//【练习1】输入一个整数，判断是否为奇数。
//int main()
//{
//	printf("请输入一个整数：");
//	int num = 0;
//	scanf("%d", &num);
//	if (num % 2 == 1)//【注意】=是赋值符==是判断相等；if语句后面不加；因为这个句子还没完
//		printf("%d是一个奇数", num);
//	else
//		printf("%d是一个偶数", num);
//	return 0;
//}
//【练习2】判断是否成年
//int main()
//{
//	int age = 0;
//	printf("请输入你的年龄：");
//	scanf("%d", &age);
//	if (age >= 18)
//		printf("你已经成年！");
//	else
//		printf("你未成年！");
//
//	return 0;
//}
//1.2 分支中包含多条语句
//【问题引发】默认在if和else语句中都只控制一条语句
//【解决方案】像main函数一样，用{}//这一坨，叫做程序块（代码块）也叫复合语句
//example
//int main()
//{
//	int age = 0;
//	printf("请输入你的年龄：");
//	scanf("%d", &age);
//	if (age >= 18)
//	{
//		printf("你已经成年了，");
//		printf("可以谈恋爱啦！");
//	}
//	else
//	{
//		printf("你未成年，");
//		printf("不可谈恋爱！");
//	}
//
//	return 0;
//}
//1.3  嵌套if
//在if else语句中，else可以与另一个if语句连用，构成多层判断。//事实上if或者else的{}当中也可嵌套if
//【例子】要求输入一个整数，判断输入的整数是0还是正数或者负数。
//int main()
//{
//	int num = 0;
//	printf("请输入一个整数：\n");
//	scanf("%d", &num);
//	if (num == 0)
//		printf("%d是0\n", num);
//	else if (num > 0)
//		printf("%d是正数\n", num);
//	else
//		printf("%d是负数\n", num);
//
//	return 0;
//}
//1.4 悬空else问题
//如果有多个if和else，可以记住这样一条规则，else总是和最接近的if匹配。
//我们首先从下面的代码开始
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//	else printf("haha\n");
//
//	return 0;
//}
