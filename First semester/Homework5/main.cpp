#include <iostream>

using namespace std;
/*Array17. ƒан массив A размера N. ¬ывести его элементы в следующем пор€дке:
A1, A2, AN, ANЦ1, A3, A4, ANЦ2, ANЦ3, Е .*/
void input(int n,int *a)
{
    for(int i(1);i<=n;i++)
    cin>>a[i];
}
void output(int n, int *a)
{
  int c=n;
  for(int i(1);i<=n;i++)
    {
        if((i+1<=n)&&(c-1>=1))
        {
            cout<<a[i]<<" "<<a[i+1]<<" "<<a[c]<<" "<<a[c-1]<<" ";
        c--;
    }
        }
}
int main()
{   int a[10];
    int n;cin>>n;
    input(n,&a[n]);
    output(n,&a[n]);
    return 0;
}
