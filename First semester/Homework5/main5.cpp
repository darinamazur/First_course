#include <iostream>

using namespace std;
/*Array65. Дан массив A размера N и целое число K (0 ≤ K < N).
Преобразовать массив, увеличив каждый его элемент на исходное значение элемента AK*/
void input(int n,int*a,int *c,int k)
{
    for(int i(0);i<n;i++)
        cin>>a[i];
    *c=a[k];
}
void pluselement(int n,int c,int *a)
{
    for(int i(0);i<n;i++)
        a[i]+=c;
}
void output(int n, int *a)
{
    for(int i(0);i<n;i++)
        cout<<a[i]<<" ";
}
    int main()
{
    int n,k,c;
    int a[20];
    cin>>n>>k;
        input(n,&a[n],&c,k);
        pluselement(n,c,&a[n]);
        output(n,&a[n]);
    return 0;
}

