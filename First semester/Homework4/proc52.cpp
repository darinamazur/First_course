#include <iostream>

using namespace std;
/*Proc52. ������� ������� IsLeapYear(Y) ����������� ����, ������� ����������
True, ���� ��� Y (����� ������������� �����) �������� ����������, �
False � ��������� ������. ������� �������� ������� IsLeapYear ��� ����
������ �������� ��������� Y. ���������� ��������� ���, ��������� �� 100 � �� ������� �� 400.*/

    bool isleepyear(int y)
    {
        if ((y%4==0)||((y%100==0)&&(y%400!=0)))
            return true;
        else return false;
    }
int main()
{
    int y;
    const int k=5;
    for (int i=0;i<k;i++)
    {
        cin>>y;
        if (isleepyear(y))
            cout<<"true";
        else cout<<"false";
    }

    return 0;
}
