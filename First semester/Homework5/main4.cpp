#include <iostream>

using namespace std;
/*Array53. ���� ��� ������� A � B ����������� ������� N.
������������ ����� ������ C ���� �� �������,
������ ������� �������� ����� ������������� �� ��������� �������� A � B � ��� �� ��������.*/
void input(int n,int *a)
{
    for(int i(1);i<=n;i++)
    cin>>a[i];
}
void new_mas_maxelement(int n, int* a, int* b, int* c)
{
   for(int i(1);i<=n;i++)
    {
        if(a[i]>b[i])
            c[i]=a[i];
        else c[i]=b[i];
    }
}
void output(int n, int *a)
{
    for(int i(1);i<=n;i++)
        cout<<a[i]<<" ";
}
int main()
{
    int n;cin>>n;
    int a[10],b[10],c[10];
    input(n,&a[n]);
    cout<<endl;
    input(n,&b[n]);
    cout<<endl;
    new_mas_maxelement(n,&a[n],&b[n],&c[n]);
    output(n,&c[n]);
    return 0;
}
