#include <iostream>

using namespace std;

int main()
{
    int k,d;
    cin >> k;
    d=(5+(k%7))%7;
    cout << d;
    return 0;
}
