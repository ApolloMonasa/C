//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <ctype.h>
//#include <assert.h>
//#include <string.h>
//#include <errno.h>


///第16讲 字符函数和字符串函数
/// 【1.0】字符分类函数
/// C语言中有一类函数是专门做字符分类的头文件<ctype.h>
/// 以下函数的参数如果是对应类型，就会返回真
/// iscntrl：任何控制字符
/// isspace：空白字符
/// isdigit：10进制数字'0'-'9'字符
/// isxdigit：十六进制数字字符
/// islower：小写字母
/// isupper：大写字母
/// isalpha：字母
/// isalnum：数字或者字母
/// ispunct：标点符号，任何不属于数字和字母的图像字符（可打印）
/// isgraph：任何图像字符
/// isprint：任何可打印字符，包括图形字符和空白字符

//int main()
//{
//	char m = 'A';
//	if (islower(m))
//		printf("yes");
//	else
//		printf("no");
//	return 0;
//}

///【练习】将小写字母转换为大写

//'a'--97
//'A'--65
//int main()
//{
//	char arr[30] = "Hi,I am a Student.";
//	int i = 0;
//	while (arr[i])
//	{
//		if (islower(arr[i]))
//		{
//			arr[i] -= 32;
//		}
//		i++;
//	}
//	printf("%s", arr);
//	return 0;
//}

/// 【2.0】字符转换函数
/// C语言提供了两个字符转换函数
/// int tolower(int c);将参数传进去的大写字母转小写
/// int toupper(int c);将参数传进去的小写字母转大写

//int main()
//{
//	char arr[30] = "Hi,I am a Student.";
//	int i = 0;
//	while (arr[i])
//	{
//		if (islower(arr[i]))
//		{
//			arr[i] = toupper(arr[i]);
//		}
//		i++;
//	}
//	printf("%s", arr);
//	return 0;
//}

///【头文件】<string.h>
/// 【3.0】strlen的使用和模拟实现
/// size_t（无符号整型） strlen(const char* str)
/// 字符串以'\0'作为结束标志，这就是strlen的判断标志，它会从给的指针位置开始，计算出'\0'之前的字符个数
/// 【易错点】size_t无符号,相减还是size_t,还是无符号
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abc";
//	if ((size_t)strlen(arr2) - (size_t)strlen(arr1)>0)
//		printf(">\n");
//	else
//		printf("<=\n");
//	printf("%d", strlen(arr2) - strlen(arr1));
//	return 0;
//}
///这里我发现：VS中strlen的返回类型不是size_t，而是int
/// 【3.1】模拟实现
///1】计数器
/// 2】指针-指针
/// 3】递归（没讲过）

//size_t my_strlen1(const char* str)
//{
//	assert(str != NULL);
//	size_t count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//
//}
//
//size_t my_strlen2(const char* str)
//{
//	assert(str != NULL);
//	char* start = str;
//	while (*str)
//	{
//		str++;
//	}
//	return str-start;
//
//}
//
//size_t my_strlen3(const char* str)
//{
//	assert(str != NULL);
//	if (*str == 0)
//		return 0;
//	else
//		return 1 + my_strlen3(str + 1);
//
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int ret = my_strlen3(arr);
//	printf("%d\n", ret);
//	return 0;
//}

/// 【4.0】strcpy的使用和模拟实现
/// char * strcpy ( char * destination, const char * source );
/// 字符串拷贝函数，将 source 指向的 C 字符串复制到 destination 指向的数组中，包括终止 null 字符（并在该点停止）
/// 【易错】逐个字符地初始化，会导致没有终止符号，极可能报错。
///为避免溢出，destination 指向的数组的大小应足够长（有人大小省略，然后还只初始化个0，这大小怎么够），以包含与 source 相同的 C 字符串（包括终止 null （'\0'）字符），并且不应在内存中与 source 重叠，而且必须可以修改(有的人拿个指针装常量字符串，改不了啊)，大小并不能省略。

//int main()
//{
//	char arr[] = "hello world";
//	char srr[30] = "xxxxxxxxxxxxxxxxxxxx";
//	//把arr拷贝到srr里面
//	//我们想当然的这样：srr=arr，可是这样是不行的，地址是常量，不可修改
//	strcpy(srr, arr);
//	printf("%s\n", srr);
//	return 0;
//}

///【4.1】模拟实现
//void my_strcpy1(char* desti, const char* source)
//{
//	while (*(source))
//	{
//		*desti = *source;
//		source++;
//		desti++;
//	}
//}
//
//void my_strcpy1pro(char* desti, const char* source)
//{
//	assert(desti != NULL);
//	assert(desti && source);
//	while (*desti++ = *source++);
//}
//
//char* my_strcpy1prop(char* desti, const char* source)
//{
//	char* rett = desti;
//	assert(desti != NULL);
//	assert(desti && source);
//	while (*desti++ = *source++);
//	return rett;
//}

/// <summary>
/// 为什么strcpy函数的返回值类型是char*，其实是返回了目标空间的起始地址
/// </summary>
/// <returns></returns>
//int main()
//{
//	char arr[] = "hello world";
//	char srr[30] = "xxxxxxxxxxxxxxxxxxxx";
//	//把arr拷贝到srr里面
//	//我们想当然的这样：srr=arr，可是这样是不行的，地址是常量，不可修改
//	my_strcpy1pro(srr, arr);
//	printf("%s\n", srr);
//	return 0;
//}

//int main()
//{
//	char arr[] = "hello world";
//	char srr[30] = "xxxxxxxxxxxxxxxxxxxx";
//	char* ret = my_strcpy1prop(srr, arr);
//	printf("%s\n", ret);
//	return 0;
//}

/// 【5.0】strcat的使用和模拟实现
/// 连接字符串
/// char * strcat ( char * destination, const char * source );destination 返回。
///将源字符串的副本附加到目标字符串。destination 中终止的 null 字符将被 source 的第一个字符覆盖，并且 null 字符包含在 destination 中由两者串联形成的新字符串的末尾。
/// destination指向空间必须足够大，可修改
/// 源字符串和目标字符串必须有\0
///destination 和 source 不得重叠。
//int main()
//{
//	char arr1[20] = "hello ";
//	strcat(arr1, "world");
//	printf("%s\n", arr1);
//	return 0;
//}
///【5.1】模拟实现

//char* my_strcat(char* desti, const char* source)
//{
//	assert(desti && source);
//	char* ret = desti;
//	//找到目标中的\0
//	while (*desti != '\0')
//		desti++;
//	//while (*desti++);是不行的
//	//拷贝数据
//	while (*desti++ = *source++);
//	return ret;
//}
/// <summary>
/// 不能给自己追加，会死循环直到访问越界，但库函数某些时候可以，自己给自己追加一般用strncat
/// </summary>
/// <returns></returns>
//int main()
//{
//	char arr1[20] = "hello ";
//	my_strcat(arr1,"world");
//	printf("%s\n", arr1);
//	return 0;
//}

/// 【6.0】strcmp的使用和模拟实现
/// int strcmp ( const char * str1, const char * str2 );
/// [比较规则]对应位置上的字符比较ASCII码值，从左到右，先大的大，先小的小
/// 返回值：<0 =0 >0,分别对应1和2的大小情况，而且在大多数编译器里面是返回+-1和0
//int main()
//{
//	char arr1[] = "abcde";
//	char arr2[] = "vb";
//	printf("%d", strcmp(arr1, arr2));
//
//	return 0;
//}
///【6.1】模拟实现

//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == 0)
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;//或者作差也行
//	
//}
//
//int main()
//{
//	char arr1[] = "abcde";
//	char arr2[] = "vb";
//	printf("%d", my_strcmp(arr1, arr2));
//
//	return 0;
//}

///以上三种都是长度不受限制的字符串函数，下面介绍三种长度受限制的字符串函数
/// 【7.0】strncpy的使用
/// char * strncpy ( char * destination, const char * source, size_t num );
/// 从字符串中复制字符
///将源的前 number 个字符复制到目标。如果在复制 num 个字符之前找到源 C 字符串的末尾（由 null 字符表示），则目标将填充\0，直到写入总数 num 个字符为止。
///如果 source 长于 num，则不会在 destination 的末尾隐式附加 null 字符。因此，在这种情况下， destination 不应被视为以 null 结尾的 C 字符串（因此读取它会溢出）
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[20] = { 0 };
//	strncpy(arr2, arr1, 5);
//	//strncpy(arr2, arr1, 19);
//	printf("%s\n", arr2);
//
//	char arr3[] = "abc";
//	char arr4[20] = "xxxxxxxxxxxxxxxx";
//	strncpy(arr4, arr3, 5);
//	//strncpy(arr2, arr1, 19);
//	printf("%s\n", arr4);
//	return 0;
//}
/// 【8.0】strncat的使用
/// char * strncat ( char * destination, const char * source, size_t num );
/// 从字符串附加字符
///将 source 的前 num 个字符附加到 destination，外加一个终止 null 字符。
///如果 source 中 C 字符串的长度小于 num，则仅复制终止 null 字符之前的内容。
/// 我追加完之后还会附加\0

//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "xxxxxx";
//	strncat(arr1, arr2, 5);
//	printf("%s", arr1);
//	return 0;
//}

/// 【9.0】strncmp的使用
/// int strncmp ( const char * str1, const char * str2, size_t num );
/// 比较两个字符串的字符
//比较 C 字符串 str1 的字符数与 C 字符串 str2 的字符数。
//此函数开始比较每个字符串的第一个字符。如果它们彼此相等，则继续处理以下对，直到字符不同，直到到达终止 null 字符，或者直到两个字符串中的 num 个字符匹配，以先发生者为准。
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abbbbbcdef";
//	int ret = strcmp(arr1, arr2);
//	printf("%d\n", ret);
//	int ret1 = strncmp(arr1, arr2, 2);
//	printf("%d", ret1);
//
//	return 0;
//}
/// 【10.0】strstr的使用和模拟实现
/// 
/// 【用处】在一个字符串中，找一个子字符串，返回它第一次出现的位置地址
/// const char * strstr ( const char * str1, const char * str2 );
///或char* strstr(char* str1, const char* str2);
/// 可移植性
///在 C 语言中，此函数仅声明为：
///char* strstr （ const char* ， const char* ）;
///而不是 C++ 中提供的两个重载版本。
/// 
/// 查找子字符串
///返回指向 str1 中第一次出现的 str2 的指针，如果 str2 不是 str1 的一部分，则返回 null 指针。
///匹配过程不包括终止 null 字符，但会在此处停止。
/// 返回值
///指向 str2 中指定的整个字符序列在 str1 中首次出现的指针，如果 str1 中不存在该序列，则指向 null 指针。

//int main()
//{
//	char arr1[] = "abcdefabcdeff";
//	char arr2[] = "def";
//	char* ret = strstr(arr1, arr2);
//	if (ret == NULL)
//		printf("找不到\n");
//	else
//		printf("找到了,%s\n",ret);
//
//	return 0;
//}
///【10.1】模拟实现

//char* my_strstr(const char* str1,const char* str2)
//{
//	assert(str1 && str2);
//	char* s1 = str1;
//	char* s2 = str2;
//
//	const char* cur = str1;//记录可能开始匹配的位置
//
//	if (*str2 == '\0')
//		return str1;
//	while (*cur)
//	{
//		//完成一次匹配
//		s1 = cur;
//		s2 = str2;
//
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//			return cur;
//		cur++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char arr1[] = "abcdbefabcdeff";
//	char arr2[] = "def";
//	char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//		printf("找不到\n");
//	else
//		printf("找到了,%s\n",ret);
//
//	return 0;
//}
 
///kmp算法
/// 【11.0】strtok的使用
/// char * strtok ( char * str, const char * delimiters );
/// delimiters指向一个字符串，定义了用作分隔符的字符集合
/// str指定一个字符串，它包含了0个或者多个由delimiters集合字符串中一个或多个分隔符分割的标记。
/// 函数会找到str中的下一个标记，并将其用\0替代，返回一个指向这个标记位置的指针。（所以函数会改变被操作的字符串，所以被函数切分的字符串一般都是被临时拷贝并且可修改的内容）
/// 在第一次调用时，该函数需要一个 C 字符串作为 str 的参数，其第一个字符用作扫描标记的起始位置。在后续调用中，该函数需要一个 null 指针，并使用最后一个标记结束后的位置作为扫描的新起始位置。
///为了确定令牌的开头和结尾，该函数首先从起始位置扫描分隔符中未包含的第一个字符（该字符将成为令牌的开头）。然后从令牌的开头开始扫描分隔符中包含的第一个字符，该字符将成为令牌的结尾。如果找到终止 null 字符，扫描也会停止。
///令牌的此结尾将自动替换为 null 字符，令牌的开头由函数返回。
///在对 strtok 的调用中找到 str 的终止 null 字符后，对此函数的所有后续调用（以 null 指针作为第一个参数）都将返回 null 指针。
///找到最后一个令牌的点由函数在内部保留，以便在下次调用时使用（不需要特定的库实现以避免数据竞争）。
/// 
//int main()
//{
//	char arr1[] = "zpengwei@yeah.net";
//	char sep[] = "@.";
//
//	char* p = strtok(arr1, sep);
//	printf("%s\n", p);
//	printf("%d\n", strlen(p)+1);
//
//	p = strtok(NULL, sep);
//	printf("%s\n", p);
//
//	p = strtok(NULL, sep);
//	printf("%s\n", p);
//
//	p = strtok(NULL, sep);
//	printf("%s\n", p);
//
//
//	return 0;
//}

///【正常代码】
//int main()
//{
//	char arr1[] = "zpengwei@yeah.net";
//	char sep[] = "@.";
//	char buf[30] = { 0 };
//	strcpy(buf, arr1);
//
//	char* p = NULL;
//	for (p = strtok(buf, sep); p != NULL;p=strtok(NULL,sep))
//	{
//		printf("%s\n", p);
//	}
//	return 0;
//}

/// 【12.0】strerror的使用
///char * strerror ( int errnum );
/// 获取指向错误消息字符串的指针
///解释 errnum 的值，生成一个字符串，其中包含一条消息，该消息描述错误条件，就像由库的函数设置为 errno 一样。
///返回的指针指向静态分配的字符串，该程序不得修改该字符串。对此函数的进一步调用可能会覆盖其内容（不需要特定的库实现来避免数据竞争）。
///strerror 生成的错误字符串可能特定于每个系统和库实现。
/// 【补充】在不同的系统和C语言标准库的实现中都规定了一些错误码，一般放在errno.h这个头文件里面说明，C语言程序启动时，就会使用一个全局变量error来记录程序的当前错误，只不过程序启动的时候error是0，表示没有错误，当我们在使用标准库中的函数时发生了某种错误，就会将对应的错误码存放在error中。
//int main()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d:%s\n", i,strerror(i));
//	}
//	return 0;
//}

///【实际应用】
//int main()
//{
//	//打开文件
//	FILE* pf=fopen("test.txt","r");
//	if (pf == NULL)
//		printf("文件打开失败，原因是：%s", strerror(errno));
//	//打开成功.....
//	//关闭文件
//	assert(pf != NULL);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

///当然也可以了解以下perror，可以直接打印：错误信息 
//int main()
//{
//	//打开文件
//	FILE* pf=fopen("test.txt","r");
//	if (pf == NULL)
//		perror("文件打开失败，原因是");
//	//打开成功.....
//	//关闭文件
//	assert(pf != NULL);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
