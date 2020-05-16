#include <iostream>
#include <cmath>

using namespace std;
For18. ƒано вещественное число A и целое число N (> 0). »спользу€ один цикл,
найти значение выражени€
1 Ц A + A2 Ц A3 + Е + (Ц1)NЈAN.

int main()
{
    int n;
    float a;
    int const k = -1;
    cin>>n>>a;
    float sum=0;
        for(int i=0;i<=n;i++)
            sum+=(pow(k,i)*pow(a,i));
        cout<<sum;
    return 0;
}
