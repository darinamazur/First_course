#include <iostream>
#include <cmath>
using namespace std;
/*While4�. ���� ����� ����� N (> 0). ���� ��� �������� �������� ����� 3, �� ��-
����� True, ���� �� �������� � ������� False.*/

int main()
{
    int n;
    cin>>n;
    int const k=3;
    int d=0;
        while (n%k==0)
         n/=k;
       if(n==1) cout<<"true";
       else cout<<"false";
    return 0;
}
