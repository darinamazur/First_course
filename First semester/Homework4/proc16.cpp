#include <iostream>

using namespace std;
/*Proc16. ������� ������� Sign(X) ������ ����, ������������ ��� ���������-
���� ����� X ��������� ��������:
�1, ���� X < 0; 0, ���� X = 0; 1, ���� X > 0.
� ������� ���� ������� ����� �������� ��������� Sign(A) + Sign(B) ���
������ ������������ ����� A � B.*/
    int sign(float x)
    {
        if(x>0) return 1;
        if (x==0) return 0;
        else return -1;
    }

int main()
{
    float a,b;
    cin >>a>>b;
    cout<<(sign(a)+sign(b));

    return 0;
}
