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

86、请你谈谈你是如何使用 return 语句的。

【参考答案】
（1）return 语句不可返回指向“栈内存”的“指针”或者“引用” ，因为该内存在函数体结束时被自动销毁。
（2）要搞清楚返回的究竟是“值”、“指针”还是“引用” 。
（3）如果函数返回值是一个对象，要考虑 return 语句的效率

89、下列程序输出结果是？

inline void max_out( int val1, int val2 ) {
  cout << ( val1 > val2 ) ? val1 : val2;
}

int main() {
    int ix = 10, jx = 20;
    cout << "The larger of " << ix;
    cout << ", " << jx << " is ";
    max_out( ix, jx );
    cout << endl;
}

【标准答案】
The larger of 10, 20 is 0 ，
为什么不是20呢？问题在于输出操作符的优先级高于条件操作符 所以输出 val1 和 val2 比较结果的 true/false

90、下面两个声明算函数重载？还是重复声明？
int max( int *ia, int sz );
int max( int *, int = 10 );

【标准答案】
如果在两个函数的参数表中只有缺省实参不同则第二个声明被视为第一个的重复声明 。

1. 定义一个二维数组,必须指定第二维的数量,也就是列的数量.假如初始化的数量少于第二维的值,那么这个二维数组的第一维的维度为1,并且未初始化的全部为0

2. 对象属于某个已知的类,是类的实例,对象之间的通信实际上就是通过函数传递的信息,封装是把数据和操作结合在一起,继承是对类的方法的改变和补充,重载是多态性之一

3. scanf 遇到空格停止输入

4. ++i 返回 i 本身, i++ 返回一个临时变量

5. c++ 中 setw是默认是右对齐,c语言中加了宽度如(%10d)默认也是右对齐
