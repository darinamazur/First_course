#include <iostream>

using namespace std;
/*Series16�. ���� ����� ����� K � ����� ��������� ����� �����; ������� ��� ��-
�������� � ����� 0. ������� ����� ���������� ����� � ������, ������-
�� K. ���� ����� ����� ���, �� ������� 0.*/

int main()
{
    int k;
    cin>>k;
    int a=1,numtemp=0,number=0;
        while (a!=0)
        {
            cin>>a;
            numtemp++;
            if(a>k)
            number=numtemp;
        }
    cout<<number;
    return 0;
}
