#include <iostream>
#include <cmath>

using namespace std;
/*Series28. ���� ����� ����� N � ����� �� N ������������ �����: A1, A2, �, AN.
������� ��������� �����:
(A1)^N, (A2)^(N�1), �, (AN�1)^2, AN.*/

int main()
{
    int n,a,temp;
    cin>>n; temp=n;
        for(int i=0;i<n;i++)
            {
            cin>>a;
            a=pow(a,temp);
            temp--;
            cout<<a<<" ";
            }
    return 0;
}
