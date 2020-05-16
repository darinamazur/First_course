#include <iostream>
#include <cmath>

using namespace std;
/*Proc4∞. ќписать процедуру TrianglePS(a, P, S), вычисл€ющую по стороне a
равностороннего треугольника его периметр P = 3Јa и площадь S = a2 3 / 4
(a Ч входной, P и S Ч выходные параметры; все параметры €вл€ютс€ ве-
щественными). — помощью этой процедуры найти периметры и площади
трех равносторонних треугольников с данными сторонами.*/
    void triangleps(float a,float *p,float *s)
    {
        *p=3*a;
        *s=((a*a)*sqrt(3))/4;
    }

int main()
{
    float a,p,s;
    int const c=3;
    for(int i=0;i<c;i++)
    {
         cin>>a;
         triangleps(a,&p,&s);
         cout<<p<<" "<<s;
    }

    return 0;
}
