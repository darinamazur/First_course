#include <iostream>
#include <cmath>

using namespace std;
/*Proc28. ������� ������� IsPrime(N) ����������� ����, ������������ True,
���� ����� �������� N (> 1) �������� ������� ������, � False � ������-
��� ������ (�����, ������� 1, ���������� �������, ���� ��� �� ����� ��-
����������� ���������, ����� 1 � ������ ����). ��� ����� �� 10 �����
�����, ������� 1. � ������� ������� IsPrime ����� ���������� �������
����� � ������ ������.*/

 bool isprime (int a)
 {
   if (a==1) return false;
   for (int i(2);i<=sqrt(a); i++)
        if (a%i==0) return false;
   return true;
 }
int main()
{
    const int c=10;
    int a,counter=0;
    for(int i(0);i<c;i++)
    {
        cin>>a;
        if(isprime(a)) counter++;
    }
    cout<<counter;
    return 0;
}
