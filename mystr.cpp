#include "mystr.h"
constexpr int basic_len = 10;
//constexpr int buf_size = 10000;
String::String(const char *input)
{
    int len = basic_len;
    int input_len = strlen(input);
    //cout << input_len << endl;
    while(len<=input_len)
    {
        len*=2;
        //printf("**%d\n",len);
    }
    str_ = new char [len+1];
    strcpy(str_, input);
    capacity_ = len;
    size_ = strlen(input);
}
String::String(const String &cop)
{
    str_ = new char [cop.size_+1];
    strcpy(str_, cop.str_);
    size_ = cop.size_;
    capacity_ = cop.size_;
}
const size_t String::size()
{
    return size_;
}
const size_t String::capacity()
{
    return capacity_;
}
String& String::operator += (const String &new_str)
{
    /*this->capacity_+=new_str.capacity_;
    this->size_+=new_str.size_;
    this->str_[this->size_] = '\0';這一行不確定會發生什麼事
    strcat(this->str_, new_str.str_);
    cout << "\n**************"<<endl;
    return *this;*/
    size_t new_len = size_+new_str.size_;
    bool give_space = (capacity_>new_len);
    if(give_space)
    {
        strcat(str_, new_str.str_);
        size_ = new_len;
        return *this;
    }
    else
    {
        while(!give_space)
        {
            capacity_*=2;
            give_space = (capacity_>new_len);
        }
    }
    char *new_ = new char [capacity_+1];
    strcpy(new_, str_);
    strcat(new_, new_str.str_);
    delete[] str_;
    size_= new_len;
    str_ = new_;
    return *this;
}
const char& String::operator[](size_t index)const
{
    return str_[index];
}
char& String ::operator[](size_t index)
{
    return str_[index];
}
String& String::operator = (const String &new_str)
{
    if(this == &new_str)
    {
        return *this;
    }
    else
    {
        capacity_ = basic_len;
        if(capacity_ > new_str.size_)
        {
            //printf("C:%d and c:%d",capacity_, new_str.capacity_);
            //system("pause");
            size_ = new_str.size_;
            strcpy(str_, new_str.str_);
        }
        else
        {
            //system("pause");
            while(capacity_ <= new_str.capacity_)
            {
                capacity_*=2;
            }
            //system("pause");
            delete [] str_;
            //printf("pause here.\n");
            //system("pause");
            str_ = new char [capacity_+1];
            strcpy(str_, new_str.str_);
            size_ = new_str.size_;
        }
        return *this;
    }
}
String String::operator + (const String &r_str)
{
    String baby(*this);
    baby += r_str;
    return baby;
}
bool operator == (const String &l_str, const String &r_str)
{
    if(strcmp(l_str.c_str(), r_str.c_str())==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator != (const String &l_str, const String &r_str)
{
    return !(l_str==r_str);
}
bool operator < (const String &l_str, const String &r_str)
{
    if(strcmp(l_str.c_str(),r_str.c_str())==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator <= (const String &l_str, const String &r_str)
{
    if(l_str<r_str || l_str==r_str)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator > (const String &l_str, const String &r_str)
{
    return !(l_str<=r_str);
}
bool operator >= (const String &l_str, const String &r_str)
{
    return !(l_str<r_str);
}
istream & operator >> (istream &is, String &input)
{
    input.clear();
    char temp;
    while(is.get(temp) && temp!='\n' && temp!='\t' && temp!=' ')
    {
        char two[2];
        two[0] = temp;
        two[1] = '\0';
        input+=two;
    }
    return is;
}
ostream & operator << (ostream &os, const String &output)
{
    os << output.str_;
    return os;
}
const char* String::c_str()const
{
    return str_;
}
void String::clear()
{
    *this = "";
}
void String::swap(String &input)
{
    String temp(input);
    input = *this;
    *this = temp;
}
