#include <iostream>
#include <cstdio>
using namespace std;
bool Is_empty(char*s);
int main()
{
   const int Size=20;
   int counter=0;
   char*str=new char[Size];
   FILE*my=fopen("my.txt","r");
   if(my == NULL) {
        perror("ошибка открытия");
    }
   else
    {
        while(!feof)
        {
            fgets(str,Size,my);
            if(Is_empty(str))
            {
                    counter++;
            do
                fgets(str,Size,my);
            while(Is_empty(str));
            }
        }
    }
   cout<<counter;
    return 0;
}
bool Is_empty(char*s)
{
    if(s[0]=='\n') return true;
    else return false;
}
