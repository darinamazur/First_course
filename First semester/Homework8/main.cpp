#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    FILE *fp;
    char const *str = "������\n";
    fp = fopen("my.txt", "a");
    if(fp == NULL) {
        perror("������ ��������");
    }
    else
    fwrite(str, strlen(str), 1, fp);
    fclose(fp);
    return 0;
}
