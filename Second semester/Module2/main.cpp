#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
enum  Colour_name{white,grey};
int Size;
void read_from_file(int**&Matrix),Output_Matrix(int**Matrix),graph(int**Matrix),dfs(int v,int*used,int**Matrix,bool&flag);
int main()
{
 setlocale(0,"Rus");
 FILE*my=fopen("file.txt","r");
 fscanf(my,"%d",&Size);fclose(my);
 int**Matrix=new int*[Size];
      for(int i(0);i<Size;i++)
        Matrix[i]=new int[Size];
    read_from_file(Matrix);
    graph(Matrix);
 int*colour=new int[Size];
 memset(colour,white,Size);
 bool flag=false;
  for(int i(0);i<Size;i++)
    if (colour[i]==white){
      dfs(i,colour,Matrix,flag);
    }
delete colour;
for(int i(0);i<Size;i++)
        delete Matrix[i];
     delete Matrix;
    if(flag) cout<<"Цикл найден"<<endl;
    else cout<<"Цикл не найден"<<endl;
    return 0;
}
void dfs(int v,int*colour,int**Matrix,bool&flag)//поиск в глубину
{
    colour[v]=grey;
    for(int i=0;i<Size;i++)
    if (Matrix[v][i]==1){
        if(colour[i]==grey) {flag=true;break;}
        else dfs(i,colour,Matrix,flag);
    }
}
void graph(int**Matrix){
    FILE*my=fopen("graph.txt","w");
    fprintf(my,"digraph \"GRAPH\"{\n");
     for(int i(0);i<Size;i++)
    for(int j(0);j<Size;j++){
        if(Matrix[i][j]==1)
		fprintf(my, "%d -> %d;\n",i,j);
		else fprintf(my, "%d;%d;\n",i,j);
    }
    fprintf(my, "}\n");
    fclose(my);
}

void read_from_file(int**&Matrix){
    FILE*my=fopen("file.txt","r");
	if (!my){
		cout << "File not found.\n";
		system("pause");
		return;
	}
	else{
    fscanf(my,"%d",&Size);
    for(int i(0);i<Size;i++)
    for(int j(0);j<Size;j++)
    fscanf(my,"%d",&Matrix[i][j]);
    fclose(my);}
}
