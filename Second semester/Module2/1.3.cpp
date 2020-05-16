#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
int const Size=100;
int index=0;
using namespace std;
struct node{
string info;
int number;
bool flag=false;
node*right=nullptr;
node*left=nullptr;};
bool IS_Brackets(string current),IS_Oper(string current);int Prior(string current);
void Create_array(string*&arr,int&arr_counter,char*original),Input_Matrix(int counter,int**Matrix),write_variables(char*s);
char*different_var(char*s);
void Output_Matrix(int counter,int**Matrix);
int evaluateTree(node*node,int x,int y,int z);
void solve(stack<node*>&nodes,stack<node*>&oper);
node*Create_node(string info);
node*Prefix_form(string*arr,int arr_counter);
void viz(node*node,FILE*my);
void graph(node*node,FILE*my);
int main()
{
    int counter=0;
    char*original=new char[Size];
    gets(original);
    int columns=strlen(different_var(original)),rows=pow(2,columns);
    int**Matrix=new int*[rows];
      for(int i(0);i<rows;i++)
        Matrix[i]=new int[columns+1];
     Input_Matrix(columns,Matrix);
    string*arr=new string[strlen(original)];
    Create_array(arr,counter,original);
    node*ExpressionTree=Prefix_form(arr,counter);
    FILE *f = fopen("expression.txt", "w");
	viz(ExpressionTree, f);
	fclose(f);
    int x,y,z;
    char*str=different_var(original);
    if(columns!=0){
    for(int i(0);i<rows;i++){
    if(columns==3){x=Matrix[i][0];y=Matrix[i][1];z=Matrix[i][2];}
    else if(columns==2){if(str[0]=='x'&&str[1]=='y'){x=Matrix[i][0];y=Matrix[i][1];}
    else if(str[0]=='x'&&str[1]=='z'){x=Matrix[i][0];z=Matrix[i][1];}
    else {y=Matrix[i][0];z=Matrix[i][1];}}
    else {if(str[0]=='x')x=Matrix[i][0];if(str[0]=='y')y=Matrix[i][0];else z=Matrix[i][0];}
    cout<<"Steps for "<<i+1<<" vector: "<<endl;
    Matrix[i][columns]=evaluateTree(ExpressionTree,x,y,z);
    }
    write_variables(original);
    Output_Matrix(columns,Matrix);}
    else{   cout<<"Steps: "<<endl;
            int result = evaluateTree(ExpressionTree,x,y,z);
	cout << "Result= "<<result<<endl;}
    for(int i(0);i<rows;i++)
        delete Matrix[i];
     delete Matrix; delete original;
    return 0;
}
char*different_var(char*s){
    char*res=new char[3];
    int x=0,y=0,z=0;
    for(int i(0);i<strlen(s);i++){
            if(s[i]=='x')x++;
            else if(s[i]=='y')y++;
            else if(s[i]=='z')z++;
    }
    int i(0);
    if(x>0) res[i++]='x';if(y>0) res[i++]='y';if(z>0) res[i]='z';
    if (i==0)res="";
    return res;
}
bool IS_Brackets(string current)
{
	if (current=="("||current==")")return true;else return false;
}
bool IS_Oper(string current)
{
	if (current=="!"||current=="&"||current=="|") return true;else return false;
}
int Prior(string current) {
    if (current=="|")return 1;else
    if (current=="&")return 2;else
    if(current=="!") return 3;
    else return 0;
}
void Create_array(string*&arr,int&arr_counter,char*original) {
    int i=0;
	for (;i <strlen(original);i++)
	{
		arr[i]=original[i];
	}
	arr_counter=i;
}
void Input_Matrix(int counter,int**Matrix)
{
   for (int i=0; i<pow(2,counter); i++)
   {
    for (int k=0; k<counter; k++)
    Matrix[i][k] = (i >> (counter-k-1)) & 1;
    Matrix[i][counter]=0;
   }
}
void write_variables(char*s)
{
    char*res=different_var(s);
      for(int i(0);i<strlen(res);i++)
        cout<<res[i]<<"|";cout<<"f|";
     cout<<endl;
}
void Output_Matrix(int counter,int**Matrix)
{
    for(int i(0);i<pow(2,counter);i++)
    {
        for(int j(0);j<=counter;j++)
            cout<<Matrix[i][j]<<"|";
        cout<<endl;
    }
}
node*Prefix_form(string*arr,int arr_counter) {
    stack<node*> operators;
	stack<node*> treenodes;
	string token;
	for (int i = 0; i <arr_counter; i++) {
		token = arr[i];
		if (IS_Oper(token)) {
			if (!(operators.empty())) {
				while ((Prior(operators.top()->info)>=Prior(token))&&(operators.top()->info!="(")) {
                     solve(treenodes,operators);
					if (operators.empty()) break;}}
			operators.push(Create_node(token));
		}
		else if (token == "(") operators.push(Create_node(token));
		else if (token == ")") {
			while (operators.top()->info!= "(") {
				solve(treenodes, operators);
				if (operators.empty()) break;}
			if (!operators.empty()) operators.pop();
			else break;}
		else treenodes.push(Create_node(token));
	}
	while (!operators.empty()){
		if (IS_Brackets(operators.top()->info))
			break;
		solve(treenodes, operators);
	}
	return treenodes.top();
}
node*Create_node(string info) {
	node*current=new node();
	current->info=info;current->number=index++;
	current->right=NULL;current->left=NULL;
	return current;
}
void solve(stack<node*>&nodes,stack<node*>&oper){
    node*current=oper.top();
	if (oper.top()->info=="!") {
        oper.pop();
		current->right=nodes.top();
		nodes.pop();
		current->left=NULL;
		nodes.push(current);
	} else {
	    oper.pop();
		current->right=nodes.top();
		nodes.pop();
		current->left=nodes.top();
		nodes.pop();
		nodes.push(current);
	}
}
int evaluateTree(node*node,int x,int y,int z) {
	double left,right,res;
	if (IS_Oper(node->info)&&node->info!="!") {
		left=evaluateTree(node->left,x,y,z);
		right=evaluateTree(node->right,x,y,z);
		cout<<left<<node->info<<right<<endl;
		if (node->info=="&")
			return(left&&right);
		else if (node->info=="|")
			return(left||right);}
    if (node->info=="!")
        {right=evaluateTree(node->right,x,y,z);
        cout<<node->info<<right<<endl;
			return(1-right);}
	else  {
		if (node->info=="x")
			return x;
        if (node->info=="y")
			return y;
        if (node->info=="z")
			return z;
		else {
			return atoi(node->info.c_str());
		}
	}
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
