#include <iostream>
#include <cstdio>
using namespace std;
/*String61. Дана строка, содержащая полное имя файла. Выделить из этой строки название последнего каталога (без символов «\»).
Если файл содержится в корневом каталоге, то вывести символ «\».*/
/*Если файлы в примере на этой странице находятся на устройстве Е:, то полное имя файла «фото с собакой» будет таким:
Е:\Мои путешествия\На море\Лена\фото с собакой.jpg*/
int Size_of_String(char*str);
void Output_String(char*S,int N);
void Name_of_last_catalog(char*s,int n);
int Symbols_between(char*s,int n);
int main()
{
    char*String=new char[500];
    gets(String);
    int Size=Size_of_String(String);
    Name_of_last_catalog(String,Size);
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
void Name_of_last_catalog(char*s,int n)
{
   int i,Size=Symbols_between(s,n),k=0;
   char*String_result=new char[500];
   for(i=n-1;i>=0;i--)
   {
        if((int)s[i]==92)
        {
             if((int)s[i-1]==58)
            cout<<char(92);
        else
                for(int j(i-1);j>n-(i-1+Size);j--)
                {
                    String_result[k]=s[j];
                    k++;
                }
        }
    break;
   }
   Output_String(String_result,Size);
}
int Symbols_between(char*s,int n)
{
    int counter=0,i;
    for(i=n-1;i>=0;i--)
    if((int)s[i]==92)
        break;
    i--;
    while((int)s[i]!=92)
    {
        i--;
        counter++;
    }

   return counter;
}
