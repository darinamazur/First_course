#include <iostream>
#include <cmath>

using namespace std;
For18. ���� ������������ ����� A � ����� ����� N (> 0). ��������� ���� ����,
����� �������� ���������
1 � A + A2 � A3 + � + (�1)N�AN.

int main()
{
    int n;
    float a;
    int const k = -1;
    cin>>n>>a;
    float sum=0;
        for(int i=0;i<=n;i++)
            sum+=(pow(k,i)*pow(a,i));
        cout<<sum;
    return 0;
}
