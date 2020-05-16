#include <iostream>
#include "lib.h"
using namespace std;
/*Matrix93. ƒана квадратна€ матрица пор€дка M.
ќбнулить элементы матрицы, лежащие одновременно выше главной диагонали и ниже побочной диаго-нали.*/

int main()
{
    int M;
    cin>>M;
    int**Matrix=new int*[M];
      for(int i(0);i<M;i++)
        Matrix[i]=new int[M];
     Input_Matrix(M,Matrix);
     cout<<endl;
     Zeroing(M,Matrix);
     Output_Matrix(M,Matrix);
    for(int i(0);i<M;i++)
        delete Matrix[i];
     delete Matrix;
    return 0;
}
