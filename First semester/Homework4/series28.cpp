#include <iostream>
#include <cmath>

using namespace std;
/*Series28. ƒано целое число N и набор из N вещественных чисел: A1, A2, Е, AN.
¬ывести следующие числа:
(A1)^N, (A2)^(NЦ1), Е, (ANЦ1)^2, AN.*/

int main()
{
    int n,a,temp;
    cin>>n; temp=n;
        for(int i=0;i<n;i++)
            {
            cin>>a;
            a=pow(a,temp);
            temp--;
            cout<<a<<" ";
            }
    return 0;
}
