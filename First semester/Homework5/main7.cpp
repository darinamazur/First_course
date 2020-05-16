#include <iostream>

using namespace std;
/*Array89. ��� ������ ������� N, ��� �������� ��������, ����� ������, ����������� �� ��������.
������� ������ �������������, ���������� �������, ���������� ���������������, �� ����� �������.*/
//��� ������������� �� ��������
void input(int n, int *a)
{
    for(int i(0);i<n;i++)
        cin>>a[i];
}
void output(int n, int *a)
{
    for(int i(0);i<n;i++)
        cout<<a[i]<<" ";
}
void swap (int *a, int *b)
{
    int temp=*a; *a=*b;*b=temp;
}
void streamline(int n, int *a)
{
    for (int i(0);i<n;i++)
    {
        if(i+1<n && i>=0)
    {
        if(a[i]<a[i+1])
        {
            swap(&a[i+1],&a[i]);
            i-=2;
        }
    }
}
}
int main()
{
    int n;cin>>n;
    int a[20];
    input(n,&a[n]);
    streamline(n,&a[n]);
    output(n,&a[n]);
    return 0;
}

