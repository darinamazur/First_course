#include <iostream>
#include <cmath>

using namespace std;
/*For28. ƒано вещественное число X (|X| < 1) и целое число N (> 0). Ќайти значе-
ние выражени€
1 + X/2 Ц 1ЈX2/(2Ј4) + 1Ј3ЈX3/(2Ј4Ј6) Ц Е +
+ (Ц1)NЦ1Ј1Ј3ЈЕЈ(2ЈNЦ3)ЈXN/(2Ј4ЈЕЈ(2ЈN)).*/

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
