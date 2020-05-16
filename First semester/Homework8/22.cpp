#include <iostream>
#include <cstdio>
/*File5. Дано имя файла целых чисел.
Найти количество элементов, содержащих-ся в данном файле. Если файла с таким именем не существует, то вывес-ти –1.*/
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

