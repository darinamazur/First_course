#include <iostream>

using namespace std;

int main()
{
    int k,n,d;
    cin >> n >> k;
    d=(n-1+(k%7))%7;
    cout<<d;
    return 0;
}
