#include <iostream>
#include <cmath>

//переведення числа n деякоъ системи числення m в десяткову

using namespace std;

int counter (int a) //рахує кількість цифр в числі
{
    int c=0;
    while (a>0)
    {
        a/=10;
        c++;
    }
            return c;
}

int main()
{
    int n,m,result,c;
    const int t=10;
    cin>>n>>m;
    result=0;
    c=counter(n);
    if (m<t)
    {
        for (int i=0; i<c; i++)
        {
                                            //розкладаємо число за базисом
            result+=(n%10)*pow(m,i);
            n=n/10;
        }
    }
    cout<<result;
    return 0;
}
