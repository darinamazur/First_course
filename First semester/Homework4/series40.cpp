#include <iostream>
#include <clocale>

using namespace std;
/*Series40. ���� ����� ����� K, � ����� K ������� ��������� ����� �����. ��-
���� ����� �������� �� ����� ���� ���������, ��������� ��� ����������
�������� ����� 0. ��� ������� ������ ��������� ��������� ��������: ��-
�� ����� �������� ������������ (��. ������� Series23), �� ������� ����-
������ ��� ���������; � ��������� ������ ������� ����� ������� ������-
��, ������� �� �������� ������.*/

int main()
{
    int k;
    cin>>k;
    for (int i(0);i<k;i++)
    {
    int a1,a2,a=1,counter=2;
    bool b=true;
    cin>>a1>>a2;
    while(a!=0)
    {
        cin>>a; counter++;
        if (((a1<a2)&&(a<a2))||((a1>a2)&&(a>a2)))
        {
            a1=a2;
            a2=a;
        }
        else
        {
            b=false;cout<<a<<endl; break;

        }
    }

    if (b) cout<<(counter-1)<<endl;
        }
    return 0;
}
