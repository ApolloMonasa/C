///9.14 输出格式
//printf（）可以定制占位符的输出格式
//9.14.1限定宽度
//printf允许限定占位符的最小宽度。值得注意的是%lf和%f默认小数点后打印六位
//如printf("%5d",123)输出结果是“  123”（会在前面以空格的方式凑够5位，即默认右对齐）
//如何左对齐？？
//#include <stdio.h>
//int main()
//{
//	printf("%-6dxxx", 123);
//	return 0;
//}


//%f ：用于格式化  float  或  double  类型的浮点数。
//%lf ：专门用于格式化  double  类型的浮点数（在  printf  和  scanf  中）。