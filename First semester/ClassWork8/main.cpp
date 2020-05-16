#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
const int Size=100;
void Output_String(char*S,int N);
int Size_of_String(char*str);
int count_word(char*str,int n);
int count_longest(char*s,int n,int word);
void change_Big(char*s,int n);
void input_matrix(char**matrix,char*s,int c,int n);
void Output_matrix(int M,int N,char**matrix);
void by_alphabet(char**matrix,int r,int c);
void Swap (char*x,char*y);
void matrix_to_string(char**matrix,char*s,int r);
int main()
{

    char*str=new char[Size];
    FILE *my = fopen("my.txt", "r");
    if (my == NULL) perror("error");
    else
      fgets(str, Size, my);

    int s=Size_of_String(str);
    char*s_help=new char[s];
    change_Big(str,s);
    int words=count_word(str,s);
    int letters=count_longest(str,s,words);
    Output_String(str,s);
    cout<<endl;

     char**matrix=new char*[words];
      for(int i(0);i<words;i++)
        matrix[i]=new char[letters];

    input_matrix(matrix,str,letters,s);
    //Output_matrix(words,letters,matrix);
    cout<<endl;
    by_alphabet(matrix,words,letters);
    //Output_matrix(words,letters,matrix);
    matrix_to_string(matrix,s_help,words);
    Output_String(s_help,s);

    for(int i(0);i<words;i++)
        delete matrix[i];
     delete matrix;
    fclose(my);
    return 0;
}

void Output_String(char*S,int N)
{
    for (int i(0);i<N;i++)
        cout<<S[i];
}
int Size_of_String(char*str)
{
    int Size=0;
    while(str[Size]!='\0')
    {
        Size++;
    }
    return Size;
}

int count_word(char*s,int n)
{
    int counter=0;
    bool b=true;
    for(int i(0);i<n;i++)
    {
        if(isalpha(s[i]))
        {
            if(b){
            counter++;
            b=false;}
        }
        else b=true;
    }
    return counter;
}
int count_longest(char*s,int n,int word)
{
   int sum=0,summax=0;
   for(int i(0);i<n;i++)
   {
       if(isalpha(s[i]))
       {
           sum++;
       }
       else if(s[i]==' ')
       {
           if(sum>summax)
            summax=sum;
           sum=0;
       }
   }
   return summax;
}

void change_Big(char*s,int n)
{
    for (int i(0);i<n;i++)
    {
        if((int)s[i]>=65 && (int)s[i]<=90)
            s[i]=(char)((int)s[i]+32);
    }
}

void input_matrix(char**matrix,char*s,int c,int n)
{
   int im=0,jm=0;
       for(int i(0);i<n;i++)
       {
           if(s[i]!=' ')
           {matrix[im][jm]=s[i];jm++;}
           else {im++;jm=0;}
       }
}

void Output_matrix(int r,int c,char**matrix)
{
    for(int i(0);i<r;i++)
    {
        for(int j(0);j<c;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

void Swap (char*x,char*y)
{
    char t=*x; *x=*y; *y=t;
}

void by_alphabet(char**matrix,int r,int c)
{

    for(int k(0);k<r;k++)
    {
         for(int i(0);i<r;i++)
         {
             if(i+1<r)
                 {
                     int j=0;
                     if((int)(matrix[i][j])>(int)(matrix[i+1][j]))
                 for(int g(0);g<c;g++)
                    Swap(&matrix[i][g],&matrix[i+1][g]);
                  if((int)matrix[i][j]==(int)matrix[i+1][j])
                   {
                     while((int)(matrix[i][j])==(int)(matrix[i+1][j]))
                        j++;
                     if((int)(matrix[i][j])>(int)(matrix[i+1][j]))
                        for(int g(0);g<c;g++)
                            Swap(&matrix[i][g],&matrix[i+1][g]);
                    }
                     else j=0;
                 }
         }
    }
}
void matrix_to_string(char**matrix,char*s,int r)
{
    int k=0;
    for(int i(0);i<r;i++)
    {
        int j=0;
        while(isalpha(matrix[i][j]))
        {
            s[k]=matrix[i][j];
            k++;j++;
        }
        s[k]=' ';
        k++;
        j=0;
    }
}








