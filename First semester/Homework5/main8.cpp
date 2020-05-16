#include <iostream>

using namespace std;
/*Array95. Дан целочисленный массив размера N.
Удалить из массива все соседние одинаковые элементы, оставив их первые вхождения.*/
void input(int n,int *a)
{
    for(int i(0);i<n;i++)
        cin>>a[i];
}
void output(int n,int *a)
{
    for(int i(0);i<n;i++)
        cout<<a[i]<<" ";
}
void delete_the_same(int n, int *a,int *temp)
{
     for (int i(0);i<n;i++)
    {
        if(i+1<n)
        {
        if (a[i]==a[i+1])
        {
            n--;
            for (int j(i+1);j<n;j++)
            a[j]=a[j+1];
            i--;
        }
        }
    }
  *temp=n;
}
int main()
{
    int n,ntemp;cin>>n;
    int a[20];
    input(n,&a[n]);
    delete_the_same(n,&a[n],&ntemp);
    output(ntemp,&a[n]);
    return 0;
}
