#include <iostream>
#include <cstdio>
using namespace std;
/*String19. ƒана строка. ≈сли она представл€ет собой запись целого числа, то вывести 1,
если вещественного (с дробной частью) Ч вывести 2; если строку нельз€ преобразовать в число, то вывести 0.
—читать, что дробна€ часть вещественного числа отдел€етс€ от его целой части дес€тичной точ-кой Ђ.ї.*/
void Result_of_String(char*srt,int Size);
int Size_of_String(char*str);
int main()
{
   char*str=new char[500];
    gets(str);
    int Size=Size_of_String(str);
    Result_of_String(str,Size);
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
void Result_of_String(char*str,int Size)
{
     int Result=1;
     for (int i(0);i<Size;i++)
     {
         if(((int)(str[i]))>=48 && ((int)(str[i]))<=57)
            continue;
         if(((int)(str[i]))==46)
            Result=2;
         else {Result=0; break;}
     }
     cout<<Result;
}
