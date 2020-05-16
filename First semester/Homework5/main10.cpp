#include <iostream>

using namespace std;
/*Array119. Дан целочисленный массив размера N. Преобразовать массив, увеличив каждую его серию на один элемент.*/
void input(int n, int*a)
{
    for(int i(0);i<n;i++)
        cin>>a[i];
}
void output(int n, int*a)
{
    for(int i(0);i<n;i++)
        cout<<a[i]<<" ";
}
void increment_series(int n, int *a,int*temp)
{
    for (int i=0;i<n;i++)
    {
        if(i+1<n)
            {
        if(a[i+1]!=a[i])
        {
            for(int j(n);j>i+1;j--)
                a[j]=a[j-1];
                a[i+1]=a[i];
                i++;n++;
        }
            }
    }
    a[n]=a[n-1];
    *temp=n;
}
int main()
{
    int n,ntemp;
    int a[20];
    cin>>n;
    input(n,&a[n]);
    increment_series(n,&a[n],&ntemp);
    output(ntemp+1,&a[n]);
    return 0;
}
