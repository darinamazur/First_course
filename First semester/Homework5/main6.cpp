#include <iostream>

using namespace std;
/*Array77. ƒан массив размера N.
¬озвести в квадрат все его локальные минимумы (то есть числа, меньшие своих соседей).*/
void input(int n, int *a)
{
    for(int i(0);i<n;i++)
        cin>>a[i];
}
void square_local_minimum(int n, int *a)
{
    for (int i(0);i<n;i++)
    {
        if(i+1<n)
        {
        if (a[i+1]<a[i] && a[i+1]<a[i+2])
            a[i+1]*=a[i+1];
        i++;
        }
    }
}
void output(int n, int *a)
{
    for(int i(0);i<n;i++)
        cout<<a[i]<<" ";
}
int main()
{
    int n;cin>>n;
    int a[20];
    input(n,&a[n]);
    square_local_minimum(n,&a[n]);
    output(n,&a[n]);
    return 0;
}

