#include <iostream>

using namespace std;
/*For40. ƒаны целые числа A и B (A < B). ¬ывести все целые числа от A до B
включительно; при этом число A должно выводитьс€ 1 раз, число A + 1
должно выводитьс€ 2 раза и т. д.*/

int main()
{
    int a,b;
    cin>>a>>b;
     int c=0;
     int j;
     for (int i=a;i<=b;i++)
     {
     c++;
         for (int j=0;j<c;j++)
         {
             cout<<i<<" ";
         }
     }
    return 0;
}
