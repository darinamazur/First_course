#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;
struct node{
int info;
node*left=nullptr;
node*right=nullptr;
int number;
int level=0;};
int height(node*tree);
void read(node*&tree,int&index,int counter),viz(node*node,FILE*my),graph(node*node,FILE*my);
node*add(node*tree,int current,int&index,int counter);node*DeleteNode(node*tree,int c),*DeleteLevel(node*&tree, int level);
int main()
{
    setlocale(0,"rus");
    int index=0,temporary=0;
    node*tree=NULL;
    read(tree,index,temporary);
    index=0;
    FILE*v=fopen("viz.txt","w");//визуализация начального дерева
    viz(tree,v);
    fclose(v);
    int h=height(tree);
    cout<<"Высота дерева: "<<h<<endl;
    tree=DeleteLevel(tree,h/2);
    FILE*v1=fopen("viz1.txt","w");//визуализация конечного дерева
    viz(tree,v1);
    fclose(v1);
    return 0;
}
node*DeleteLevel(node*&tree, int level) {
    if (tree!=NULL) {
        DeleteLevel(tree->left,level-1);  // С помощью рекурсии посещаем левое поддерево
        if (level==0) {
            // level будет равен нулю на нужной глубине, так как при каждом рекурсивном вызове значение level уменьшается на один
            if(height(tree->right)==height(tree->left))tree=DeleteNode(tree,tree->info);  //delete element, если он на нужном нам уровне and conditional is true
            }
        DeleteLevel(tree->right,level-1);  // С помощью рекурсии посещаем правое поддерево
    }
return tree;
}

node*DeleteNode(node*tree,int c){
    if(tree==NULL)
        return tree;
    if(c==tree->info){
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
      else {tree->left=DeleteNode(tree->left,c);
      tree->right=DeleteNode(tree->right,c);}
    return tree;
}
void read(node*&tree,int&index,int counter){
    FILE*my=fopen("file.txt","r");
    if(my==NULL) perror("error");
    else
        while(!feof(my)){
        int current;
        fscanf(my,"%d",&current);
        tree=add(tree,current,index,counter);
        }
    fclose(my);
}
node*add(node*tree,int current,int&index,int counter){
    if (tree==NULL)
    {
        tree=new node;
        tree->info=current;
        tree->number=index++;
        tree->level=counter;
    }
    else if (current<tree->info)
        tree->left=add(tree->left,current,index,counter);
    else tree->right=add(tree->right,current,index,counter);
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
int height(node*tree)
{
    if (!tree) return -1;

    return 1 + max(height(tree->left), height(tree->right));
}
