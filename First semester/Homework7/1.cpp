#include <iostream>
#include <cstdio>
using namespace std;
/*String19. ���� ������. ���� ��� ������������ ����� ������ ������ �����, �� ������� 1,
���� ������������� (� ������� ������) � ������� 2; ���� ������ ������ ������������� � �����, �� ������� 0.
�������, ��� ������� ����� ������������� ����� ���������� �� ��� ����� ����� ���������� ���-��� �.�.*/
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
