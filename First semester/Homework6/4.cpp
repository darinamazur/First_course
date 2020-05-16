#include <iostream>

using namespace std;
/*Matrix53. Дана матрица размера M × N. Поменять местами столбец с номером 1 и последний из столбцов,
содержащих только положительные элементы. Если требуемых столбцов нет, то вывести матрицу без изменений.*/
void Input_Matrix(int M,int N,int**Matrix)
{
    for(int i(0);i<M;i++)
    {
        for(int j(0);j<N;j++)
            cin>>Matrix[i][j];
    }
}
void Output_Matrix(int M,int N,int**Matrix)
{
    for(int i(0);i<M;i++)
    {
        for(int j(0);j<N;j++)
            cout<<Matrix[i][j]<<" ";
        cout<<endl;
    }
}
bool Checking_the_signs_of_elements(int j,int M,int**Matrix)
{
    for(int i(0);i<M;i++)
        if((Matrix[i][j])<=0)
        {
            return false;
            break;
        }
}
int Last_column_of_positive_numbers(int M,int N,int**Matrix)
{
    int Last_j=0;
    for(int j(0);j<N;j++)
        {
        if(Checking_the_signs_of_elements(j,M,Matrix))
            Last_j=j;
        }
    return Last_j;
}
void Swap (int*x,int*y)
{
    int t=*x; *x=*y; *y=t;
}
void Swap_columns(int M,int N,int**Matrix)
{
    int Last_column=Last_column_of_positive_numbers(M,N,Matrix);
    for(int i(0);i<M;i++)
    {
        Swap(&Matrix[i][0],&Matrix[i][Last_column]);
    }
}
int main()
{
    int M,N;
    cin>>M>>N;
    int**Matrix=new int*[M];
      for(int i(0);i<M;i++)
        Matrix[i]=new int[N];
     Input_Matrix(M,N,Matrix);
     cout<<endl;
     Swap_columns(M,N,Matrix);
     Output_Matrix(M,N,Matrix);
    for(int i(0);i<M;i++)
        delete Matrix[i];
     delete Matrix;
    return 0;
}
