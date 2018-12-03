76、以下三条输出语句分别输出什么？

char str1[]       = "abc";
char str2[]       = "abc";
const char str3[] = "abc";
const char str4[] = "abc";
const char* str5  = "abc";
const char* str6  = "abc";
cout << boolalpha << ( str1==str2 ) << endl; // 输出什么？
cout << boolalpha << ( str3==str4 ) << endl; // 输出什么？
cout << boolalpha << ( str5==str6 ) << endl; // 输出什么?

复制代码

【参考答案】
分别输出 false,false,true。
str1和str2都是字符数组，每个都有其自己的存储区，它们的值则是各存储区首地址，不等；
str3和str4同上，只是按const语义，它们所指向的数据区不能修改。
str5和str6并非数组而是字符指针，并不分配存储区，其后的“abc”以常量形式存于静态数据区，而它们自己仅是指向该区首地址的指针，相等。

78、以下代码能够编译通过吗，为什么？

unsigned int const size1 = 2;
char str1[ size1 ];
unsigned int temp = 0;
cin >> temp;
unsigned int const size2 = temp;
char str2[ size2 ];

【标准答案】
str2定义出错，size2非编译器期间常量，而数组定义要求长度必须为编译期常量。

79、以下代码中的输出语句输出0吗，为什么？

struct CLS {
  int m_i;
  CLS( int i ) : m_i(i) {}
  CLS()
  {
    CLS(0);
  }
};

CLS obj;

cout << obj.m_i << endl;

复制代码

【标准答案】
不能。在默认构造函数内部再调用带参的构造函数属用户行为而非编译器行为，亦即仅执行函数调用，而不会执行其后的初始化表达式。
只有在生成对象时，初始化表达式才会随相应的构造函数一起调用

84、一个栈的入栈序列是 A，B，C，D，E，则栈的不可能的输出序列是？

A、EDCBA；
B、DECBA；
C、DCEAB；
D、ABCDE
【标准答案】C

85、写出判断ABCD四个表达式的是否正确, 若正确, 写出经过表达式中 a 的值。

int a = 4;

(A)、a += (a++);
(B)、a += (++a) ;
(C)、(a++) += a;
(D)、(++a) += (a++);

a = ?

复制代码

【参考答案】
C错误，左侧不是一个有效变量，不能赋值，可改为 (++a) += a; 改后答案依次为 9,10,10,11