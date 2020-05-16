#include <iostream>
#include <cstdio>
using namespace std;
/*String33. Даны строки S и S0.
Удалить из строки S первую подстроку, совпа-дающую с S0.
Если совпадающих подстрок нет, то вывести строку S без изменений.*/
int Size_of_String(char*str);
void Output_String(char*S,int N);
void Delete_S0(char*S,char*S0,int Size_S,int Size_S0);
int main()
{
    int Size_S,Size_S0;
    char*S=new char[500];
    char*S0=new char[500];
    gets(S);
    gets(S0);
    Size_S=Size_of_String(S);
    Size_S0=Size_of_String(S0);
    if(Size_S>=Size_S0)
    Delete_S0(S,S0,Size_S,Size_S0);
    return 0;
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

void Output_String(char*S,int N)
{
    for (int i(0);i<N;i++)
        cout<<S[i];
}

void Delete_S0(char*s,char*s0,int Size_s,int Size_s0)
{
   int temp=0,start,s0_temp=0;
   for(int i(0);i<Size_s;i++)
   {
       if(s[i]==s0[s0_temp])
        {temp=i; start=i;}
       else break;
       while (s[temp]==s[s0_temp])
       {
           temp++;s0_temp++;
       }
       if (s0_temp==Size_s0)
       {
        for(int j(start);j<temp;j++)
        {
            if(j+1<temp)
            s[j]=s[j+1];
        }
        Size_s-=Size_s0;
       }
        else i=start++;

    }
    Output_String(s,Size_s);
}


