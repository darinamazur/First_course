#include <iostream>

using namespace std;
/*For16�. ���� ������������ ����� A � ����� ����� N (> 0). ��������� ����
����, ������� ��� ����� ������� ����� A �� 1 �� N.*/

int main()
{
    int a,n,res=1;
    cin>>a>>n;
        for (int i=0;i<n;i++)
            res*=a;
        cout<<res;
    return 0;
}
