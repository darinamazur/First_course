#include <iostream>

using namespace std;

int main()
{
    float A1,B1,C1,D,A2,B2,C2,x,y;
    cin >> A1>>B1>>C1>>A2>>B2>>C2;
    D=(A1*B2-A2*B1);
    x=((C1*B2-C2*B1)/D);
    y=((A1*C2-A2*C1)/D);
    cout << "x=" << x << " "  <<"y=" << y;
    return 0;
}
