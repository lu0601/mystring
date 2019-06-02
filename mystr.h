#ifndef STR_H
#define STR_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class String
{
public:
    friend std::ostream &operator << (std::ostream &os, const String &output);
    friend std::istream &operator >> (std::istream &is, String &input);
    String(const char *input=" ");//有一個const char* 參數的constructor
    String(const String &input);//copy constructor
    ~String()
    {
        delete [] str_;
    }
    const size_t size();
    const size_t capacity();
    const char* c_str()const;
    const char& operator [](size_t index)const;
    char& operator [](size_t index);
    String& operator += (const String &new_str);
    String operator + (const String &r_str);
    String& operator  = (const String &new_str);
    String& operator = (const char c);
    void swap(String &input);
    void clear();
private:
    size_t capacity_ = 0;
    size_t size_ =0;
    char *str_ = nullptr;
};
bool operator == (const String &l_str, const String &r_str);
bool operator != (const String &l_str, const String &r_str);
bool operator < (const String &l_str, const String &r_str);
bool operator <= (const String &l_str, const String &r_str);
bool operator > (const String &l_str, const String &r_str);
bool operator >= (const String &l_str, const String &r_str);
ostream & operator << (ostream &os, const String &output);
istream & operator >> (istream &is, String &input);
#endif // STR_H
