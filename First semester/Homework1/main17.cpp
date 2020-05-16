#include <iostream>

using namespace std;

int main()
{
    int x,y,x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2>>x>>y;
    cout<<(x1<=x<=x2 && y2<=y<=y1);
    return 0;
}
