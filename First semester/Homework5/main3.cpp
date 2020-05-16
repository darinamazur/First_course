#include <iostream>

using namespace std;
/*Array41. Дан массив размера N. Найти два соседних элемента, сумма которых максимальна,
 и вывести эти элементы в порядке возрастания их индексов.*/
void input(int n,int *a)
{
    for(int i(1);i<=n;i++)
    cin>>a[i];
}
void output_2elements_summax(int n, int *a)
{
    int summax=0;
    int sum,c1,c2;
    for(int i(1);i<=n;i++)
    {
        if(i+1<=n)
            {
        sum=a[i]+a[i+1];
        if (sum>summax)
        {
            summax=sum;
            c1=i;c2=i+1;
        }
            }
    }
    cout<<a[c1]<<" "<<a[c2];
}
int main()
{
    int n;cin>>n;
    int a[10];
    input(n,&a[n]);
    output_2elements_summax(n,&a[n]);
    return 0;
}
