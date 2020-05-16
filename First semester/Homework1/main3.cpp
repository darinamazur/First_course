#include <iostream>

using namespace std;

int main()
{
    long double A, A1, A2;
    cin >> A;
    A1=A*A;
    cout << A1 << '\n';
    A2=A1*A;
    cout << A2 << '\n';
    A2*=A1;
    cout << A2 << '\n';
    A1= A2*A2;
    cout << A1 << '\n';
    A2*=A1;
    cout << A2 << '\n';
    return 0;
}
