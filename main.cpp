#include "mystr.h"
using namespace std;
bool beq(String l_str, String r_str)
{
    if(l_str == r_str)
    {
        printf("l==r\n");
        return true;
    }
    else
    {
        return false;
    }
}
bool isbigger(String l_str, String r_str)
{
    if(l_str>r_str)
    {
        printf("l>r\n");
        return true;
    }
    else
    {
        return false;
    }
}
bool notsmaller(String l_str, String r_str)
{
    if(l_str>=r_str)
    {
        printf("l>=r\n");
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    //char str[100]={'\0'};
    String test = "test.cpptest.cpptest.cpptest.cpptest.cpptest.cpp";
    //printf(" = is right.\n");
    //cout << test;
    String input;
    cin >> input;
    /*for(int i=10;i<input.size();i+=1)
    {
        input[i]='*';
    }*/
    //input[1]='i';
    //printf("%d",input<test);
    //beq(input,test);
    //isbigger(input, test);
    //notsmaller(input, test);
    //getline(cin, input);
    //input+=test;
    //cout << input+test << endl;
    //cout << input[input.size()-1]<<endl;
    //printf("%c\n",input[1]);
    cout << input;
    return 0;
}
