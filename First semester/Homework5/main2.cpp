#include <iostream>
/*Array29. Дан массив A размера N. Найти максимальный элемент из его элемен-тов с нечетными номерами: A1, A3, A5, … .*/

using namespace std;
void input(int n,int *a)
{
    for(int i(1);i<=n;i++)
    cin>>a[i];
}
void outputmax(int n,int * a)
{
    int max=0;
    for(int i(1);i<=n;i++)
    {
        if(i%2!=0)
        {
            if(a[i]>max)
                max=a[i];
        }
    }
    cout<<max;
}
int main()
{
    int n;cin>>n;
    int a[10];
    input(n,&a[n]);
    outputmax(n,&a[n]);
    return 0;
}

