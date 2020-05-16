#include <iostream>
#include <cstdio>
#include <clocale>
using namespace std;
/*String47. Дана строка, состоящая из русских слов, разделенных пробелами (од-ним или несколькими).
Вывести строку, содержащую эти же слова, разде-ленные одним символом «.» (точка). В конце строки точку не ставить.*/
void Output_String(char*S,int N);
void Change_to_dots(char*S,int N);
int Size_of_String(char*str);
void Delete_dots_is_near(char*s,int N);
int main()
{
    setlocale(LC_CTYPE, "Rus");
    char*in_string=new char[500];
    gets(in_string);
    int Size=Size_of_String(in_string);
    Change_to_dots(in_string,Size);
    Delete_dots_is_near(in_string,Size);
    Output_String(in_string,Size);
    return 0;
}
void Output_String(char*S,int N)
{
    for (int i(0);i<N;i++)
        cout<<S[i];
}
void Change_to_dots(char*S,int N)
{
    for(int i(0);i<N;i++)
        if(S[i]==' ')
            S[i]='.';
}
int Size_of_String(char*str)
{
    int Size=0;
    while(str[Size]!='\0')
    {
        Size++;
    }
    return Size;
}
void Delete_dots_is_near(char*s,int N)
{
    for(int i(0);i< N;i++)
        if((s[i]=='.')&&(s[i+1]=='.'))
           for(int k(i);k<N;k++)
          {
            s[k]=s[k+1];
            i--;
          }
}
