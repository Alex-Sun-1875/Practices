#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

class String {
  public:
    String(char* str = nullptr);
    String(const String& str);

    ~String();

    String& operator=(char* other);
    String& operator=(const String& other);

    String operator+(const String& other);
    friend String operator+(const String& s1, const String& s2);

    String& operator+=(const String& other);

    char& operator[](unsigned int index);
    const char& operator[](unsigned int index) const;

    bool operator==(const String& other);

    friend std::ostream& operator<<(std::ostream& out, const String& str);

    const char* data() const { return str_; }
    const unsigned int length() const { return length_; }

  private:
    char* str_;
    int length_;
};

String::String(char* str) {
  if (nullptr == str) {
    str_ = new char[1];
    str_[0] = '\0';
    length_ = 0;
  } else {
    length_ = strlen(str);
    str_ = new char[length_ + 1];
    strcpy(str_, str);
  }
}

String::String(const String& str) {
  length_ = str.length();
  str_ = new char[length_ + 1];
  strcpy(str_, str.data());
}


String::~String() {
  delete[] str_;
  str_ = nullptr;
  length_ = 0;
}

String& String::operator=(char* other) {
  delete[] str_;
  length_ = strlen(other);
  str_ = new char[length_ + 1];
  memset(str_, 0, length_ + 1);
  strcpy(str_, other);

  return *this;
}

String& String::operator=(const String& other) {
  if (this == &other)
    return *this;

  delete[] str_;
  length_ = other.length();
  str_ = new char[length_ + 1];
  memset(str_, 0, length_ + 1);
  strcpy(str_, other.data());

  return *this;
}

String String::operator+(const String& other) {
  String tmp(*this);
  tmp += other;
  return tmp;
}

String operator+(const String& s1, const String& s2) {
  String tmp(s1);
  tmp += s2;
  return tmp;
}

String& String::operator+=(const String& other) {
  int len = this->length() + other.length();
  char* new_str = new char[len + 1];
  memset(new_str, 0, len + 1);
  strcpy(new_str, str_);
  strcat(new_str, other.data());

  delete[] str_;
  str_ = nullptr;
  str_ = new char[len + 1];
  memset(str_, 0, len + 1);
  strcpy(str_, new_str);

  delete[] new_str;
  return *this;
}

char& String::operator[](unsigned int index) {
  return const_cast<char&>(static_cast<const String&>(*this)[index]);
}

const char& String::operator[](unsigned int index) const {
  return str_[index];
}

bool String::operator==(const String& other) {
  return strcmp(this->data(), other.data()) == 0;
}

std::ostream& operator<<(std::ostream& out, const String& str) {
  out << str.data();
  return out;
}


int main(int argc, char* argv[]) {
  String str1;
  std::cout << "str1 = " << str1 << ", 1111" << std::endl;

  str1 = "Hello";
  std::cout << "str1 = " << str1 << ", 2222" << std::endl;

  String str2(" World!!!");
  std::cout << "str2 = " << str2 << ", 3333" << std::endl;

  String str3 = str1 + str2;
  std::cout << "str3 = " << str3 << ", 4444" << std::endl;

  std::cout << "str3[6] = " << str3[6] << ", 5555" << std::endl;
  return 0;
}
