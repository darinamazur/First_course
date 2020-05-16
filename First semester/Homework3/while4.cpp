#include <iostream>
#include <cmath>
using namespace std;
/*While4°. Дано целое число N (> 0). Если оно является степенью числа 3, то вы-
вести True, если не является — вывести False.*/

int main()
{
    int n;
    cin>>n;
    int const k=3;
    int d=0;
        while (n%k==0)
         n/=k;
       if(n==1) cout<<"true";
       else cout<<"false";
    return 0;
}
