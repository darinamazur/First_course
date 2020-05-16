#include <iostream>

using namespace std;

int main()
{
    int n, min;
    cin >> n;
    min = (n%3600)/60;
    cout << min;
    return 0;
}
