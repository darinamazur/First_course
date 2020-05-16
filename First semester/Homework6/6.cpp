#include <iostream>

using namespace std;
/*Matrix65. Дана матрица размера M × N.
Удалить ее первый столбец, содержащий только положительные элементы.
Если требуемых столбцов нет, то вывести матрицу без изменений.*/
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
bool Is_Positive_column(int j,int M,int**Matrix)
{
    for(int i(0);i<M;i++)
        if(Matrix[i][j]<=0)
        {
            return false;
            break;
        }
}
int First_positive_column(int M, int N, int**Matrix)
{
    int First_pos;
    for(int j(0);j<N;j++)
    {
        if(Is_Positive_column(j,M,Matrix))
        {
             First_pos=j;
             break;
        }
    }
    return First_pos;
}
int Existing_of_positive_column(int N,int M,int**Matrix)
{
    int Result=0;
    for (int j(0);j<N;j++)
    {
        if(Is_Positive_column(j,M,Matrix))
        {
            Result=1;
            break;
        }
    }
    return Result;
}
void Delete_column(int M,int N,int**Matrix)
{
    int j=First_positive_column(M,N,Matrix);
    for(int k(j);k<N;k++)
        for(int i(0);i<M;i++)
        Matrix[i][k]=Matrix[i][k+1];
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
     if(Existing_of_positive_column(N,M,Matrix))
     {
     Delete_column(M,N,Matrix);
     N--;
     }
     Output_Matrix(M,N,Matrix);
    for(int i(0);i<M;i++)
        delete Matrix[i];
     delete Matrix;
    return 0;
    return 0;
}
