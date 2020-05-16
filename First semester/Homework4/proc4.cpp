#include <iostream>
#include <cmath>

using namespace std;
/*Proc4�. ������� ��������� TrianglePS(a, P, S), ����������� �� ������� a
��������������� ������������ ��� �������� P = 3�a � ������� S = a2 3 / 4
(a � �������, P � S � �������� ���������; ��� ��������� �������� ��-
�����������). � ������� ���� ��������� ����� ��������� � �������
���� �������������� ������������� � ������� ���������.*/
    void triangleps(float a,float *p,float *s)
    {
        *p=3*a;
        *s=((a*a)*sqrt(3))/4;
    }

int main()
{
    float a,p,s;
    int const c=3;
    for(int i=0;i<c;i++)
    {
         cin>>a;
         triangleps(a,&p,&s);
         cout<<p<<" "<<s;
    }

    return 0;
}
