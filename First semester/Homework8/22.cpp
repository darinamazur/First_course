#include <iostream>
#include <cstdio>
/*File5. ���� ��� ����� ����� �����.
����� ���������� ���������, ����������-�� � ������ �����. ���� ����� � ����� ������ �� ����������, �� �����-�� �1.*/
using namespace std;

int main()
{
FILE*my=fopen("my.txt","r");
int counter=0;
char c;
bool b=true;
if(my==NULL) cout<<"error";
else
    do
    {
    c = fgetc(my);
    if(c>'0' && c<'9')
    {
        if(b)
      {counter++;b=false;}
        else b=true;
    }
    }
    while(c!=EOF);
cout<<counter;
return 0;
}

