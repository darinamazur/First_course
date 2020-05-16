#include <iostream>
#include <cmath>

using namespace std;
/*Proc28. Описать функцию IsPrime(N) логического типа, возвращающую True,
если целый параметр N (> 1) является простым числом, и False в против-
ном случае (число, большее 1, называется простым, если оно не имеет по-
ложительных делителей, кроме 1 и самого себя). Дан набор из 10 целых
чисел, больших 1. С помощью функции IsPrime найти количество простых
чисел в данном наборе.*/

 bool isprime (int a)
 {
   if (a==1) return false;
   for (int i(2);i<=sqrt(a); i++)
        if (a%i==0) return false;
   return true;
 }
int main()
{
    const int c=10;
    int a,counter=0;
    for(int i(0);i<c;i++)
    {
        cin>>a;
        if(isprime(a)) counter++;
    }
    cout<<counter;
    return 0;
}
