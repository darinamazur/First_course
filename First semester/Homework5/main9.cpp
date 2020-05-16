#include <iostream>

using namespace std;
/*Array107. Дан массив размера N.
 Утроить в нем вхождения всех элементов с нечетными номерами (1, 3, …)*/
int const c=2;
void input(int n,int *a)
{
    for(int i(0);i<n;i++)
        cin>>a[i];
}
void output(int n,int*a)
{
    for(int i(0);i<n;i++)
        cout<<a[i];
}
void three_of_elements(int n, int*a,int *temp)
{
    for (int i(0);i<n;i++)
    {
        if(i%2!=0)
        for (int j=0; j<c;j++)//два раза вставить
        {
            for(int k=n; k>i;k--)
            a[k]=a[k-1];
            n++; i++;
        }
    }
    *temp=n;
}
int main()
{
    int n,ntemp; cin>>n;
    int a[20];
    input(n,&a[n]);
    three_of_elements(n,&a[n],&ntemp);
    output(ntemp,&a[n]);
    return 0;
}

