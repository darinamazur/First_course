#include <iostream>

using namespace std;
/*For40. ���� ����� ����� A � B (A < B). ������� ��� ����� ����� �� A �� B
������������; ��� ���� ����� A ������ ���������� 1 ���, ����� A + 1
������ ���������� 2 ���� � �. �.*/

int main()
{
    int a,b;
    cin>>a>>b;
     int c=0;
     int j;
     for (int i=a;i<=b;i++)
     {
     c++;
         for (int j=0;j<c;j++)
         {
             cout<<i<<" ";
         }
     }
    return 0;
}
