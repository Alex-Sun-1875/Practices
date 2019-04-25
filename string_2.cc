#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

class String {
  public:
    String(const char* str = nullptr);
    String(const String& str);
    ~String();

    String& operator=(const String& str);
    String operator+(const String& str) const;
    String& operator+=(const String& str);
    bool operator==(const String& str) const;
    const char& operator[](int index) const;

    inline const size_t size() const { return length_; }
    inline const char* c_str() const{ return data_; }

    friend std::istream& operator>>(std::istream& is, String& str);
    friend std::ostream& operator<<(std::ostream& os, const String& str);

  private:
    char* data_;
    int length_;
};

String::String(const char* str) { // 通用构造函数
  if (nullptr == str) {
    length_ = 0;
    data_ = new char[1];
    data_[0] = '\0';
  } else {
    length_ = strlen(str);
    data_ = new char[length_ + 1];
    strcpy(data_, str);
  }
}

// 拷贝构造函数需要进行深拷贝
String::String(const String& str) { // 拷贝构造函数
  length_ = str.size();
  data_ = new char[length_ + 1];
  strcpy(data_, str.c_str());
}

// 析构函数需要进行内存的释放以及长度归零
String::~String() { // 析构函数
  delete[] data_;
  length_ = 0;
}

// 重载字符串赋值运算符,这个运算符会改变原有字符串的值,为了避免内存泄露,这里
// 释放了原先申请的内存再重新申请一块适当大小的内存存放新的字符串
String& String::operator=(const String& str) { // 重载=
  if (this == &str)
    return *this;

  delete[] data_;
  length_ = str.size();
  data_ = new char[length_ + 1];
  strcpy(data_, str.c_str());

  return *this;
}

// 利用 += 来重载 + 运算符
String String::operator+(const String& str) const {
  String new_string(*this);
  new_string += str;

  return new_string;
}

String& String::operator+=(const String& str) {
  unsigned int len = length_ + str.size();
  char* new_str = new char[len + 1];
  strcpy(new_str, data_);
  strcat(new_str, str.c_str());

  delete[] data_;
  length_ = strlen(new_str);
  data_ = new char[length_ + 1];
  strcpy(data_, new_str);

  return *this;
}

bool String::operator==(const String& str) const{
  return strcmp(data_, str.c_str()) == 0;
}

// 重载字符串索引运算符，进行了一个简单的错误处理，当长度太大时自动读取最后一个字符。
const char& String::operator[](int index) const {
  if (index >= length_)
    return data_[length_ - 1];
  return data_[index];
}

// 重载输入运算符，先申请一块足够大的内存用来存放输入字符串，再进行新字符串的生成。
// 这是一个比较简单朴素的实现，网上很多直接is>>str.data的方法是错误的，因为不能确
// 定str.data的大小和即将输入的字符串的大小关系。
std::istream& operator>>(std::istream& is, String& str) {
  char temp[1000];
  is >> temp;

  delete[] str.data_;
  str.length_ = strlen(temp);
  str.data_ = new char(str.length_ + 1);
  strcpy(str.data_, temp);

  return is;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
  os << str.c_str();

  return os;
}

int main(int argc, char* argv[]) {
  String str_1("hello");
  std::cout << "str_1 = " << str_1 << std::endl;

  String str_2("world");
  std::cout << "str_2 = " << str_2 << std::endl;

  String str_3;
  str_3 = str_1 + str_2;
  std::cout << "str_3 = " << str_3 << std::endl;

  String str_4(str_1);
  std::cout << "str_4 == str_1? " << (str_4 == str_1 ? " true" : " false") << std::endl;

  std::cout << "str_1[0] = " << str_1[0] << ", str_1[10] = " << str_1[10] << std::endl;

  std::cout << "read some thing to str_2: " << std::endl;
  std::cin >> str_2;
  std::cout << "str_2 = " << str_2 << std::endl;
  std::cout << "strlen(str_1) = " << strlen(str_2.c_str()) << std::endl;

  return 0;
}
