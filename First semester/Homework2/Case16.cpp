#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n;
    cin>>n;
    switch(n/10)

   {
        case 2: cout << "�������� ";
            break;
        case 3: cout <<"�������� ";
            break;
        case 4: cout <<"����� ";
            break;
        case 5: cout <<"�������� ";
            break;
        case 6: cout<<"��������� ";
    }
    switch (n%10)
    {
    case 1: cout << "���� ";
        break;
    case 2:cout << "��� ";
        break;
    case 3:cout << "��� ";
        break;
    case 4:cout << "������ ";
        break;
    case 5:cout << "���� ";
        break;
    case 6:cout << "����� ";
        break;
    case 7:cout << "���� ";
        break;
    case 8:cout << "������ ";
        break;
    case 9:cout << "������ ";
    }
    switch (n%10)
    {
       case 1: cout<< "���";
        break;
       case 2:
       case 3:
       case 4:
        cout << "����";
        break;
       case 5:
       case 6:
       case 7:
       case 8:
       case 9:
        cout << "���";
    }

    return 0;
}
/*Case16. ���� ����� ����� � ��������� 20�69, ������������ ������� (� �����).
������� ������-�������� ���������� ��������, ��������� ���������� ��-
���������� ����� �� ������ ����, ��������: 20 � ��������� ���, 32 �
��������� ��� ����, 41 � ������ ���� ���.*/
