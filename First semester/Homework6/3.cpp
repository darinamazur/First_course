#include <iostream>

using namespace std;
/*Matrix41. Дана целочисленная матрица размера M × N.
Найти номер первого из ее столбцов, содержащих максимальное количество одинаковых элементов.*/
void Input_Matrix(int M,int N,int**Matrix)
{
    for(int i(0);i<M;i++)
    {
        for(int j(0);j<N;j++)
            cin>>Matrix[i][j];
    }
}
int Max_Amount_the_Same_Elements(int*j,int M,int**Matrix)
{
    int Amount=0,Max_Amount=0;int i_temp;

    for(i_temp=0;i_temp<M;i_temp++)
    {  int Temp=Matrix[i_temp][*j];
        for(int i(1);i<M;i++)
        {
       if(Matrix[i][*j]==Temp)
            Amount++;
        }
        if(Amount>Max_Amount)
            Max_Amount=Amount;
    }
    return Max_Amount;
}
int Max_Amount_of_Columns(int M,int N,int**Matrix)
{
    int Max_j,Max=0;
    for(int j(0);j<N;j++)
    {
        if (Max_Amount_the_Same_Elements(&j,M,Matrix)>Max)
        {
            Max=Max_Amount_the_Same_Elements(&j,M,Matrix);
            Max_j=j;
        }
    }
    return Max_j;
}
int main()
{
    int N,M;
    cin>>M>>N;
   int**Matrix=new int*[M];
      for(int i(0);i<M;i++)
        Matrix[i]=new int[N];
    Input_Matrix(M,N,Matrix);
    cout<<Max_Amount_of_Columns(M,N,Matrix);
    for(int i(0);i<M;i++)
        delete Matrix[i];
     delete Matrix;
 return 0;
}
