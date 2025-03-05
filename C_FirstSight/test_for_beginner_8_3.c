//#include <stdio.h>
//std-standard-标准
// i-input-输入
// o-output-输出
// 
//int main()
//{
//	printf("Hello bit");
//	return 0;
//}
//main函数的多种写法
//void maim()//1古老
//{
//	printf("hehe\n");
//
//}
//int main(void)//2参数部分多了void表示无参数
//{
//	return 0;
//}
//3其实main函数是有参数的。他的参数是有特殊意义的，如果你想使用其参数，那就写上
//int main(int argc, char* argv[])
//{
//	return 0;
//}
//
//printf是函数-是C语言的标准库中提供的现成的函数()库函数
//print format-按照格式来打印信息
//""括起来的一串字符叫"字符串"
//\n是换行
//int main()
//{
//	printf("hello,bit\n");
//	printf("haha");
//	printf("翠花");
//	return 0; 
//}
//%d打印整数
//%c打印字符
//%f打印小数（默认小数点后打印六位）
//%lf双精度浮点数
//%s 打印字符串（鸡肋）
//这些都是占位符，会被后面的字符代替
//
// int main()
//{
//	printf("%d\n", 100);
//	printf("%c\n", 'q');//''单引号括起来表示字符
//	printf("%lf",3.14);
//	return 0;
//}
//int main()
//{
//	printf("%c","a",'a');//单符双串
//
//	return 0;
//}
//int return 等等被称为保留字或者关键字
//程序员自己创建标识符的时候不可以和关键字重复
//自己不能创建关键字
//关键字是留给C使用的,共32个
//int main()
//{
	//32-127
	//循环
//	int i = 0;
//	for (i = 32; i <= 127; i++)
//	{
//		printf("%c ", i);
//		if (i % 16 == 15)
//		printf("\n");
//	}
//	return 0;
//}

//字符串可以存放在字符数组中
//#include <string.h>
//int main()
//{
//	char  arr1[] = "abcdef";
//	char  arr2[] = { 'a','b','c','d','e','f' };//arr2中没有\0
//	printf("%s\n", arr2);
//	printf("%zd\n", strlen(arr2));//?
//
//}
//C语言字符串中有一个冷知识，在字符串的末尾隐藏着一个\0字符，是字符串的结束标志。strlen函数和printf函数若没有就会打出乱码
//strlen 返回的值是size_t类型的，应该使用%zd
//#转义字符-转变原来意义
//在支持三字母词的编译器上   ??)-->]    ??)-->[
//?前面加\可以防止
// \'用于表示字符常量
//int main()
//{
//	printf("%c\n",'\'');
//	return 0;
//}
//  \t可以补够8个空格
// \ddd表示一到三位八进制数
//  \xdd表示的是两个十六进制数字
//所有转义字符视为一个字符
// 【补充】0是八进制数前缀，0x是16进制数前缀，A-F表示10-15
//#include <stdio.h>
//int main()
//{
//	printf("%c\n",'\x36');
//	printf("%c\n", '\130');
//
//
//	return 0;
//}
//#include <string.h>
//int main()
//{
//	printf("%zd", strlen("C:\test\bit\118\test1\t"));
//	return 0;
//}
