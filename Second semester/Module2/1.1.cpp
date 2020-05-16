#include <iostream>
#include <cstdio>
using namespace std;
struct node{
int info;
node*left=nullptr;
node*right=nullptr;
int number;};
void read(node*&tree,int&index),viz(node*node,FILE*my),graph(node*node,FILE*my),treeprint(node*tree);
node*add(node*tree,int current,int&index),*Swapping(node*&tree);
int main()
{
    int index=0;
    node*tree=NULL;
    read(tree,index);
    FILE*v=fopen("viz.txt","w");//визуализация начального дерева
    viz(tree,v);
    fclose(v);
    treeprint(tree);cout<<endl;//вывод ЛКП
    Swapping(tree);
    treeprint(tree);//вывод ЛКП
    FILE*swapv=fopen("swapviz.txt","w");//визуализация конечного дерева
    viz(tree,swapv);
    fclose(swapv);
    return 0;
}
node*Swapping(node*&tree){
    if(tree)
    {
        Swapping(tree->left);
        Swapping(tree->right);
        if  (tree->left&&tree->right)
        {
           int temp=tree->right->info;
           tree->right->info=tree->left->info;
           tree->left->info=temp;
        }
    }
return tree;
}
void treeprint(node*tree){
    if (tree!=NULL) {
    treeprint(tree->left);
    cout<<tree->info<<" ";
    treeprint(tree->right);
  }
}
void read(node*&tree,int&index){
    FILE*my=fopen("file.txt","r");
    if(my==NULL) perror("error");
    else
        while(!feof(my)){
        int current;
        fscanf(my,"%d",&current);
        tree=add(tree,current,index);
        }
    fclose(my);
}
node*add(node*tree,int current,int&index){
    if (tree==NULL)
    {
        tree=new node;
        tree->info=current;
        tree->number=index++;
    }
    else if (current<tree->info)
        tree->left=add(tree->left,current,index);
    else tree->right=add(tree->right,current,index);
return tree;
}
void graph(node*node,FILE*my)
{
    static int nullcount = 0;
	if (node->left)
	{
		fprintf(my, "%d [label=\"%d\"];\n",node->number, node->info);
		fprintf(my, "%d -> %d;\n", node->number, node->left->number);
		graph(node->left,my);
	}
	else
		{
		    nullcount++;
		    fprintf(my, "null%d [shape=point];\n", nullcount);
	        fprintf(my, "%d [label=\"%d\"];\n", node->number, node->info);
	        fprintf(my, "%d -> null%d;\n", node->number, nullcount);
		}

	if (node->right)
	{
		fprintf(my, "%d [label=\"%d\"];\n", node->number, node->info);
		fprintf(my, "%d -> %d;\n", node->number, node->right->number);
		graph(node->right,my);
	}
	else
		{
		    nullcount++;
		    fprintf(my, "null%d [shape=point];\n", nullcount);
	        fprintf(my, "%d [label=\"%d\"];\n", node->number, node->info);
	        fprintf(my, "%d -> null%d;\n", node->number, nullcount);
		}
}

void viz(node*node,FILE*my)
{
	fprintf(my,"digraph \"GRAPH\"{\n");
	if (node==NULL)
		fprintf(my, "\n");
	else if (!node->right&&!node->left) {
		 fprintf(my, "%d [label=\"%d\"];\n",0,node->info);
		 fprintf(my, "null%d [shape=point];\n", 0);
		 fprintf(my, "null%d [shape=point];\n", 1);
         fprintf(my, "%d -> null%d;\n",0,1);
         fprintf(my, "%d -> null%d;\n",0,0);
	}
	else
		graph(node,my);

	fprintf(my, "}\n");
}
