#include <iostream>
#include <cmath>

using namespace std;
/*For28. ���� ������������ ����� X (|X| < 1) � ����� ����� N (> 0). ����� �����-
��� ���������
1 + X/2 � 1�X2/(2�4) + 1�3�X3/(2�4�6) � � +
+ (�1)N�1�1�3���(2�N�3)�XN/(2�4���(2�N)).*/

int main()
{
    int n, x;
    cin>>n>>x;
    int const k = -1;
        if (abs(x)>1)
            cout<<"error";
        else
        {
        float sum=1, res1=1,res2=1,power=1;
            for(int i=1;i<=n;i++)
            {
                res1*=2*i-3;
                res2*=2*i;
                power*=k*x;
                sum+=res1*power/res2;
            }

        cout<<sum;
        }
    return 0;
}
