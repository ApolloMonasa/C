////9.0 scanf和printf介绍
///9.11 printf基本语法
//printf( )的作用是将参数文本输出到屏幕。它名字里的f代表format（格式化），表示可以定制输出文本的格式。
//printf这个函数是头文件stdio.h定义的，使用之前必须引入头文件 
//#include <stdio.h>
//int main(void)
//{
//	printf("Hello Worlld!\nfuckkkkkkk");//\n 是换行符
//	return 0;
//}
///9.12占位符
//printf可以在输出文本中指定占位符。所谓占位符就是这个位置可以用其他值代入
//#include <stdio.h>
//int main(void)
//{
//	printf("There are %d apples\n", 3);
//	printf("%s and %s will come tonight\n", "李四","王五");
//	return 0;
//}
//上述例子中，“”里面的是输出文本，里面的%d就是占位符，表示这个位置要用其他值来代替。
//占位符的第一个字符一律是%，后面的字符表示类型。
//当一个语句中出现多个占位符，后面引用内容要以相同顺序排列。
//printf函数的参数和占位符是一一对应的关系，如果有N个占位符，那么参数就有N+1个（字符串算一个参数）
//如果参数个数少于对应的占位符，printf可能会输出内存中的任意值
///9.13占位符列举
//占位符与数据类型相对应
// %a 十六进制浮点数，字母输出为小写
// %A 十六进制浮点数，字母输出为大写
// %c 字符
// %d 十进制整数。//int
// %e 使用科学计数法的浮点数，指数部分的e为小写
// %E 使用科学计数法的浮点数，指数部分的E为大写
// %i 整数，基本等同于%d
// %f 小数（包含float类型 和double类型）。//float---%f  double---%lf
// %g 六个有效数字的浮点数。整数部分一旦超过六位，就会自动转换为科学计数法，指数部分的e为小写
// %G 与%g的 区别是指数部分E是大写
// %hd 十进制的short int类型
// %ho 八进制的short int类型 
// %hx 十六进制的short int类型
// %hu unsigned short int类型
// %ld 十进制long int类型
// %lo 八进制long int类型
// %lx 十六进制long int类型
// %lu unsigned long int类型
// %lld 十进制的long long int类型
// %llo 八进制
// %llx 十六进制
// %llu unsigned
// %Le 科学计数法表示的 long double类型浮点数
// %Lf long double类型浮点数
// %n 已输出的字符串数量。该占位符本身不输出，只将值储存在指定变量中
// %o 八进制整数 
// %p 指针（用来打印地址）
// %s 字符串
// %u 无符号整数
// %x 十六进制整数
// %zd size_t类型
// %% 输出一个百分号
