#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    FILE* my=fopen("my.txt","r");
    FILE*my_new=fopen("my_new.txt","w");
    if(my == NULL)
        {
        perror("ошибка открытия");
    while(!feof(my))
    {
        char a=fgetc(my);
        if(a=='!'||a==','||a=='.'||a==':'||a==';'||a=='?')
            fputc(a,my_new);
    }
        }
    fclose(my);
    fclose(my_new);
    return 0;
}
