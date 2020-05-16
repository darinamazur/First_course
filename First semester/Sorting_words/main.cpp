#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int Size=100;
int index=0,Counter=0;
struct node{
string info;
int number=0;
int counter=0;
node*right=nullptr;
node*left=nullptr;};
string*read_from_file(FILE*my,int&counter);
node*Sort_by_alpha(string current,node*tree),*Sort_by_length(string current,node*tree),*Sort_by_freq(node*tree),*DeleteNode(node*tree,int c,string*words);;
void viz(node*node,FILE*my),graph(node*node,FILE*my),treeprint_alpha(node*tree),treeprint_freq(node*tree,int n),treeprint(node*tree);
int Max(int a,int b),maxVal(node*tree);
int main()
{
   setlocale(0,"Rus");
   int counter=0;string*arr=new string[Size];
   FILE*my=fopen("my.txt","r");
    if(my==NULL) perror("error");
   else arr=read_from_file(my,counter);
   fclose(my);
   cout<<"--->  Входные слова:"<<endl;
   for(int i(0);i<counter;i++)
    cout<<arr[i]<<" ";
   cout<<endl<<endl;
   cout<<"--->  Количество слов в тексте "<<counter<<endl;
   node*tree=NULL;
   for(int i(0);i<counter;i++)
    {tree=Sort_by_alpha(arr[i],tree);}
    cout<<endl<<endl;
	cout<<"--->  Cлова, отсортированные по алфавиту:"<<endl;
    treeprint_alpha(tree);
    cout<<endl<<endl;
    cout<<"--->  Частота слов в тексте:"<<endl;
    treeprint_freq(tree,counter);
    cout<<endl<<endl;
	string*words=new string[counter];
	while(tree){
    int a=maxVal(tree);
	tree=DeleteNode(tree,a,words);}
	cout<<"--->  Слова, отсортированные по частоте:"<<endl;
	for(int i(0);i<Counter;i++)
        cout<<words[i]<<" ";
    cout<<endl<<endl;
    node*Tree=NULL;
    for(int i(0);i<counter;i++)
    {Tree=Sort_by_length(arr[i],Tree);}
    cout<<"--->  Слова, отсортированные по длине:"<<endl;
    treeprint(Tree);
    cout<<endl<<endl;
    return 0;
}

node*DeleteNode(node*tree,int c,string*words){
    if(tree==NULL)
        return tree;
    if(c==tree->counter){
        words[Counter++]=tree->info;
        node*tmp;
        if(tree->right==NULL)
            tmp=tree->left;
        else {
            node*ptr=tree->right;
            if(ptr->left==NULL){
                ptr->left=tree->left;
                tmp=ptr;
            }
           else {
                node*pmin=ptr->left;
                while(pmin->left!=NULL){
                    ptr=pmin;
                    pmin=ptr->left;
                }
                ptr->left=pmin->right;
                pmin->left=tree->left;
                pmin->right=tree->right;
                tmp=pmin;
            }
        }

        delete tree;
        return tmp;
    }
      else {tree->left=DeleteNode(tree->left,c,words);
      tree->right=DeleteNode(tree->right,c,words);}
    return tree;
}

int Max(int a,int b)
{
    return((a<=b)?b:a);
}

int maxVal(node*tree)
{
    if ((tree->left==NULL)&&(tree->right==NULL))
           return tree->counter;
    else
        if (tree->left==NULL)
            return Max(tree->counter,maxVal(tree->right));
    else
        if (tree->right==NULL)
            return Max(tree->counter,maxVal(tree->left));
    else
            return Max(tree->counter,Max(maxVal(tree->left),maxVal(tree->right)));

}
void treeprint(node*tree){
    if (tree!=NULL) {
    treeprint(tree->left);
    cout<<tree->info<<" ";
    treeprint(tree->right);
  }
}
node*Sort_by_length(string current,node*tree){
    if (tree==NULL)
    {
        tree=new node;
        tree->info=current;
        tree->number=index++;
    }
    else if ((current.size()<=tree->info.size())) tree->left=Sort_by_length(current,tree->left);
    else tree->right=Sort_by_length(current,tree->right);
return tree;
}
void treeprint_freq(node*tree,int n){
    if (tree!=NULL) {
    treeprint_freq(tree->left,n);
    cout<<tree->info<<"("<<((double)tree->counter/n)*100<<"%)"<<endl;
    treeprint_freq(tree->right,n);
  }
}
void treeprint_alpha(node*tree)
{
  if (tree!=NULL) {
    treeprint_alpha(tree->left);
    for(int i(0);i<tree->counter;i++)
    cout << tree->info << " ";
    treeprint_alpha(tree->right);
  }
}
string*read_from_file(FILE*my,int&counter)
{
    string*arr=new string[Size];
    string help="";
        while(!feof(my)){
            char a=fgetc(my);
            if(a=='\n') break;
            if(a!=' ')help+=a;
            else {arr[counter]=help;counter++;help="";}
        }
    if(help!="")
    arr[counter]=help;counter++;
    return arr;
}
node*Sort_by_alpha(string current,node*tree){
if (tree==NULL)
    {
        tree=new node;
        tree->info=current;
        tree->counter++;
        tree->number=index++;
    }
    else if (strcmp(current.c_str(),tree->info.c_str())<0)
        tree->left=Sort_by_alpha(current,tree->left);
    else if(strcmp(current.c_str(),tree->info.c_str())==0)tree->counter++;
    else tree->right=Sort_by_alpha(current,tree->right);
return tree;
}
void graph(node*node,FILE*my)
{
    static int nullcount = 0;
	if (node->left)
	{
		fprintf(my, "%d [label=\"%s\"];\n", node->number, node->info.c_str());
		fprintf(my, "%d -> %d;\n", node->number, node->left->number);
		graph(node->left,my);
	}
	else
		{
		    nullcount++;
		    fprintf(my, "null%d [shape=point];\n", nullcount);
	        fprintf(my, "%d [label=\"%s\"];\n", node->number, node->info.c_str());
	        fprintf(my, "%d -> null%d;\n", node->number, nullcount);
		}

	if (node->right)
	{
		fprintf(my, "%d [label=\"%s\"];\n", node->number, node->info.c_str());
		fprintf(my, "%d -> %d;\n", node->number, node->right->number);
		graph(node->right,my);
	}
	else
		{
		    nullcount++;
		    fprintf(my, "null%d [shape=point];\n", nullcount);
	        fprintf(my, "%d [label=\"%s\"];\n", node->number, node->info.c_str());
	        fprintf(my, "%d -> null%d;\n", node->number, nullcount);
		}
}

void viz(node*node,FILE*my)
{
	fprintf(my,"digraph \"GRAPH\"{\n");
	if (node==NULL)
		fprintf(my, "\n");
	else if (!node->right&&!node->left) {
		 fprintf(my, "%d [label=\"%s\"];\n",0,node->info.c_str());
		 fprintf(my, "null%d [shape=point];\n", 0);
		 fprintf(my, "null%d [shape=point];\n", 1);
         fprintf(my, "%d -> null%d;\n",0,1);
         fprintf(my, "%d -> null%d;\n",0,0);
	}
	else
		graph(node,my);

	fprintf(my, "}\n");
}
