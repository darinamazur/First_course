#include <iostream>
#include <cstdio>
#include <windows.h>//<3
#include <conio.h>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;

const int Size = 50,for_hash=7;
struct data
{
	char day[Size];
	char month[Size];
	char year[Size];
};
struct information
{
	char title[Size];
	char country[Size];
	char colour[Size];
	char price[Size];
	data was_made;
	char weight[Size];
	char warranty[Size];
	char id[Size];
	bool existance;
};
struct fullName{
char name[Size];
char surname[Size];
};
struct authorization{
  char login[Size];
  char password[Size];
};
struct user{
  fullName person;
  authorization inform;
  data birthday;
  char country[Size];
  char city[Size];
  char is_administration[Size];
  information basket[5*Size];
  int counter_basket;
  int price;
};
struct file{
    char buy[Size/5];
    time_t now = time(0);
    char* dt = ctime(&now);
};
int admin_menu(),getChar(char s[]),registration_menu(),user_menu(),basket_menu(),in_basket_menu(),form_menu();
void gotoxy(int x, int y)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position={x,y};
    SetConsoleCursorPosition(handle,position);
}
void output(information product),
changeUser(user now,information*products,int a),Hash(char*s),output_string(char*s),antiHash(char*s);
char* combine_string(char*s1,char*s2,char*s3);
information getProduct();
user getUser(); authorization get_registr();



int main()
{
    setlocale(0, "Russian");
    system("COLOR F5");
    char dir1[7]="users/";
    char dir2[6]="text/";
    char extension[]=".txt";
    char dir3[]="history/";
    int first_answer,a,admin;user _user,now;
    information products[Size],product;
    do
    {
     system("cls");
     first_answer=registration_menu();
     switch(first_answer)
     {
    case 0:
        {
            system("cls");
            cout<<"********************�����������********************"<<endl;
            int code=_getch();
            if(code==8) break;
            else{
            _user=getUser();
            FILE*users=fopen(combine_string(dir1,_user.inform.login,extension),"w");
            fwrite(&_user,sizeof(user),1,users);
            fclose(users);
            getch();
            break;}
        }
    case 1:
        {
            system("cls");
             authorization odd;
            cout<<"********************����********************"<<endl;
                   odd = get_registr();
                   FILE*users =fopen(combine_string(dir1,odd.login,extension), "r");
                   if(users==NULL) {perror("������������ �� ������, �������� �����������");
                   cout<<endl<<endl;getch();}
                   else{
                   fread(&_user, sizeof(user), 1, users);
				   system("cls");
                   cout << "**************************����� ������������**************************" << endl<<endl;
                   cout << "������������ ������. ��� : " << _user.person.name<<" "<<_user.person.surname<< endl; getch();
			       now=_user;if(now.is_administration[0]=='+') admin=1; else admin=2;
        }

				   fclose(users);

				  if(admin==1){
             int answer;
    do
	{
		system("cls");
		answer = admin_menu();
		switch (answer)
		{
		case 0:{
				  cout << "*********************************������*********************************" << endl;
				  cout << "\t��� ��������� ���������� � ������ ������� �����,\n\t      ��� ������������� ������ ����� �������" << endl << endl;
                  int count(0);information products[Size];
                  for(int i(0);i<Size*100;i++)
                  {
                      char*str=new char[Size];
                      FILE*my=fopen(combine_string(dir2,itoa(i,str,10),extension),"r");
                      if(my==NULL) continue;
                      else{
                    fread(&products[count],sizeof(information),1,my);cout<<"("<<count+1<<")"<<products[count].title<<endl;count++;}
                    fclose(my);
                  }
                  cout << "\n\t\t����� : ";
				  char s[Size];
				  cin.getline(s, Size);
				  if (*s != '\0')
				  {
					  int a = getChar(s);
					  system("cls");
					  cout << "*********************************������*********************************" << endl;
					  output(products[a - 1]);
				  }
                  getch();
				  break;
		}
		case 1:{

				  cout << "********************************������� ������*********************************" << endl;
				  information prod = getProduct();
				  FILE*my = fopen(combine_string(dir2,prod.id,extension), "w");
				  prod.existance = true;
				  fwrite(&prod, sizeof(information), 1, my);
				  fclose(my);
				  getch();
				  break;
		}
        case 2:{
				   char s1[Size], s2[Size];
				   cout << "*******************************�������� ������*******************************" << endl;
				   cout << "                       �������� : \t";
				   cin.getline(s1, Size);
				   cout << "                       �����    : \t";
				   cin.getline(s2, Size);
				   FILE*my=fopen(combine_string(dir2,s2,extension),"r");
				    if(my==NULL) {perror("���� ������ ������");getch();}
                    else {fclose(my);remove(combine_string(dir2,s2,extension));}

				   break;
        }
        case 3:{
                   char s1[Size], s2[Size];
				   cout << "*********************�������������� ���������� � ������*********************" << endl;
				   cout << "                  �������� : \t";
				   cin.getline(s1, Size);
				   cout << "                     ����� : \t";
				   cin.getline(s2, Size);
				   FILE*my=fopen(combine_string(dir2,s2,extension),"rw");
				   if(my==NULL) {perror("���� ������ ������"); getch();}
				    else {system("cls");product=getProduct();
				    FILE*New=fopen(combine_string(dir2,product.id,extension),"w"); fwrite(&product,sizeof(information),1,New);
				    fclose(New);fclose(my);
				    remove(combine_string(dir2,s2,extension));
				    }
				    break;
                 }
        case 4:{
				   information odd,product[Size];
				   cout << "*********************************������*********************************" << endl<<endl;
				   cout<<"          ������� �������� ������:\t";
				   cin.getline(odd.title,Size);
				   system("cls");
				   int count(1),k=0;
                  for(int i(0);i<Size;i++)
                  {
                      char*str=new char[Size];
                      FILE*my=fopen(combine_string(dir2,itoa(i,str,10),extension),"r");
                      if(my==NULL) continue;
                      else{fread(&product[k],sizeof(information),1,my);
                      if(!strcmp(product[k].title,odd.title)){product[count-1]=product[k];cout<<"("<<count<<")"<<product[count-1].title<<endl;count++;k++;} else k++;}
                      fclose(my);
                  }
                cout << "\t��� ��������� ���������� � ������ ������� �����,\n\t      ��� ������������� ������ ����� �������" << endl << endl;
                  cout << "\n\t\t����� : ";
				  char s[Size];
				  cin.getline(s, Size);
				  if (*s != '\0')
				  {
					  int a = getChar(s);
					  system("cls");
					  output(product[a-1]);
				  }
                  getch();

				   break;
		}
		case 5:break;
		}
	}
        while(answer!=5);
                   }


        else if (admin==2)
        {

          int answer1; information product[Size];
    do{
        answer1=user_menu();
		system("cls");

		switch (answer1)
		{
		   case 0:{ int a;
		   cout << "*********************************������*********************************" << endl;
				  cout << "\t��� ��������� ���������� � ������ ������� �����,\n\t      ��� ������������� ������ ����� �������" << endl << endl;
                  int count(0);information products[Size];
                  for(int i(0);i<Size*100;i++)
                  {
                      char*str=new char[Size];
                      FILE*my=fopen(combine_string(dir2,itoa(i,str,10),extension),"r");
                      if(my==NULL) continue;
                      else{
                    fread(&products[count],sizeof(information),1,my);cout<<"("<<count+1<<")"<<products[count].title<<endl;count++;}
                    fclose(my);
                  }
                  cout << "\n\t\t����� : ";
				  char s[Size];
				  cin.getline(s, Size);
				  if (*s != '\0')
				  {
					  a = getChar(s);
					  system("cls");
					  cout << "*********************************������*********************************" << endl;
					  output(products[a - 1]);
					  getchar();

				  system("cls");
				  int answer2;
				  do{
                    answer2=basket_menu();
                    switch(answer2)
                    {
                        case 0:{
                        //output_string(products[a-1].title); cout<<endl;
                        now.basket[now.counter_basket]=products[a-1];
                        now.counter_basket++;
                        FILE*New=fopen(combine_string(dir1,now.inform.login,extension),"w");
                        fwrite(&now,sizeof(user),1,New);
                        //cout<<now.counter_basket<<endl;
                        fclose(New);
                        cout<<"����� ������� �������� � �������..."<<endl; getch();
                        break;
                               }
                        case 1: break;
                    }
				  }while(answer2!=1);
                   }
                }

                  system("pause");
				  break;
           case 1:{
                information odd,product[Size];
				   cout << "*********************************������*********************************" << endl<<endl;
				   cout<<"          ������� �������� ������:\t";
				   cin.getline(odd.title,Size);
				   system("cls");
				   int count(1),k=0;
                  for(int i(0);i<Size*100;i++)
                  {
                      char*str=new char[Size];
                      FILE*my=fopen(combine_string(dir2,itoa(i,str,10),extension),"r");
                      if(my==NULL) continue;
                      else{fread(&product[k],sizeof(information),1,my);
                      if(!strcmp(product[k].title,odd.title)){product[count-1]=product[k];cout<<"("<<count<<")"<<product[count-1].title<<endl;count++;k++;} else k++;}
                      fclose(my);
                  }
                  if(count!=1){
                cout << "\t��� ��������� ���������� � ������ ������� �����,\n\t      ��� ������������� ������ ����� �������" << endl << endl;
                  cout << "\n\t\t����� : ";
				  char s[Size];
				  cin.getline(s, Size);
				  if (*s != '\0')
				  {
					  int a = getChar(s);
					  system("cls");
					  output(product[a-1]);
				 getchar();

				  system("cls");
				  int answer2;
				  do{
                    answer2=basket_menu();
                    switch(answer2)
                    {
                        case 0:{
                        //output_string(products[a-1].title); cout<<endl;
                        now.basket[now.counter_basket]=product[a-1];
                        now.counter_basket++;
                        FILE*New=fopen(combine_string(dir1,now.inform.login,extension),"w");
                        fwrite(&now,sizeof(user),1,New);
                        //cout<<now.counter_basket<<endl;
                        fclose(New);
                        cout<<"����� ������� �������� � �������..."<<endl; getch();
                        break;
                               }
                        case 1: break;
                    }
				  }while(answer2!=1);
				  }
				   break;}
				   else {cout<<"����� ������� �� �������";getch(); break;}
            }
           case 2:{
                int i(0);
                cout<<"********************��� �������*********************"<<endl<<endl;
                now.price=0;
                for(;i<now.counter_basket;i++)
                {cout<<"("<<i+1<<")"<<now.basket[i].title<<endl;
                now.price+=atoi(now.basket[i].price);}
                cout<<"�����: "<<now.price<<endl<<endl;
                FILE*my=fopen(combine_string(dir1,now.inform.login,extension),"w");
                //output_string(now.inform.login);cout<<endl;
                fwrite(&now,sizeof(user),1,my); fclose(my);
                if(i!=0){
                cout << "\t��� ��������� ���������� � ������ ������� �����,\n\t      ��� ������������� ������ ����� �������" << endl << endl;
                  cout << "\n\t\t����� : ";
				  char s[Size];
				  cin.getline(s, Size);
				  if (*s != '\0')
				  {
					  int a = getChar(s);
					  system("cls");
					  output(now.basket[a-1]);
					  getch();
                system("cls");
				  int answer3;
				  do{
                    answer3=in_basket_menu();
                    switch(answer3)
                    {
                        case 0:{
                        for(int i(a-1);i<now.counter_basket-1;i++)
                            now.basket[i]=now.basket[i+1];
                        now.counter_basket--; now.price-=atoi(now.basket[a-1].price);
                        FILE*m=fopen(combine_string(dir1,now.inform.login,extension),"w");
                        fwrite(&now,sizeof(user),1,m); fclose(m);
                       cout<<"����� ������� ������..."<<endl;
                       getch(); break;
                               }
                        case 1: break;
                    }
				  }while(answer3!=1);
				  }}
				  else cout<<"              ������� �����"<<endl;
                system("pause");
                break;
           }
           case 3:{
               cout<<"********************���������� ������*********************"<<endl<<endl;
                //file basket; for(int i(0);i<now.counter_basket;i++) basket.buy[i]=now.basket[i].title;
               // FILE*save=fopen(combine_string(dir3,antiHash(now.inform.login),extension),"a");
                //fwrite(&basket,sizeof(file),1,save);
                //fclose(save);
                now.counter_basket=0;
                FILE*my=fopen(combine_string(dir1,now.inform.login,extension),"w");
                fwrite(&now,sizeof(user),1,my);
                fclose(my);
                cout<<"������� �� ������� �� ����� "<<now.price<<", ��������� ���!"<<endl; getch();
                break;
           }
           case 4: break;
		}
        }while(answer1!=4);
     }

        }
     case 2: break;
     }
     }while(first_answer!=2);
    return 0;
}

void output(information product)
{
    cout << "                �������� : \t" << product.title << endl;
	cout << "     ������ ������������ : \t" << product.country << endl;
	cout << "                    ���� : \t" << product.colour << endl;
	cout << "                     ����: \t" << product.price << endl;
	cout << "        ���� ������������: \n";
	cout << "                -  ����� : \t" << product.was_made.day << endl;
	cout << "                -  ����� : \t" << product.was_made.month << endl;
	cout << "                -    ��� : \t" << product.was_made.year << endl;
	cout << "                     ��� : \t" << product.weight << endl;
	cout << "                �������� : \t" << product.warranty << endl;
	cout << "            ����� ������ : \t" << product.id<<endl;
}
int admin_menu()
{
    int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 6) % 6;
		if (key == 0) cout << "-> ����������� ������ �������" << endl;
		else cout << "\t����������� ������" << endl;
		if (key == 1) cout << "-> �������� �����" << endl;
		else cout << "\t�������� �����" << endl;
		if (key == 2) cout << "-> ������� �����" << endl;
		else cout << "\t������� �����" << endl;
		if (key == 3) cout << "-> ������������� ������ � ������" << endl;
		else cout << "\t������������� ������ � ������" << endl;
		if (key == 4) cout << "-> ������" << endl;
		else cout << "\t������" << endl;
		if (key == 5) cout << "-> �����" << endl;
		else cout << "\t�����" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int getChar(char s[])
{
	int a = s[0] - 48;
	for (int i = 1; i < strlen(s); i++)
	{
		a = a * 10 + s[i] - 48;
	}
	return a;
}
information getProduct()
{
	information product;
	cout << "                   �������� : \t";
	cin.getline(product.title, Size);

	cout << "        ������ ������������ : \t";
	cin.getline(product.country, Size);

	cout << "                       ���� : \t";
	cin.getline(product.colour, Size);

	cout << "                       ���� : \t";
	cin.getline(product.price, Size);

	cout << "          ���� ������������ : \n";
	cout << "                   -  ����� : \t";
	cin.getline(product.was_made.day, Size);

	cout << "                   -  ����� : \t";
	cin.getline(product.was_made.month, Size);

	cout << "                   -  ���   : \t";
	cin.getline(product.was_made.year, Size);

	cout << "                        ��� : \t";
	cin.getline(product.weight, Size);

	cout << "                   �������� : \t";
	cin.getline(product.warranty, Size);

	cout << "               ����� ������ : \t";
	cin.getline(product.id, Size);

	return product;
}

int registration_menu()
{
    int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 3) % 3;
		if (key == 0) cout << "-> �����������" << endl;
		else cout << "\t�����������" << endl;
		if (key == 1) cout << "-> ����" << endl;
		else cout << "\t����" << endl;
		if (key == 2) cout << "-> �����" << endl;
		else cout << "\t�����" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	return key;
	system("cls");
}

user getUser()
{
    user user;
    cout<<"                     ���:\t";
    cin.getline(user.person.name, Size);
    cout<<"                 �������:\t";
    cin.getline(user.person.surname, Size);
    cout<<"                   �����:\t";
    cin.getline(user.inform.login, Size);
   Hash(user.inform.login);
    cout<<"                  ������:\t";
    cin.getline(user.inform.password, Size);
    Hash(user.inform.password);
    cout<<"           ���� ��������:\n";
    cout<<"                    ����:\t";
    cin.getline(user.birthday.day, Size);
    cout<<"                   �����:\t";
    cin.getline(user.birthday.month, Size);
    cout<<"                     ���:\t";
    cin.getline(user.birthday.year, Size);
    cout<<"                  ������:\t";
    cin.getline(user.country, Size);
    cout<<"                   �����:\t";
    cin.getline(user.city, Size);
    cout<<"      �������������(+/-):\t";
    cin.getline(user.is_administration, Size);
    user.counter_basket=0; user.price=0;
    return user;
}

authorization get_registr()
{
    authorization odd;
    cout<<"                   �����:\t";
    cin.getline(odd.login, Size);
    cout<<"                  ������:\t";
    cin.getline(odd.password, Size);
    Hash(odd.login),Hash(odd.password);
    return odd;
}

int user_menu()
{
    int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) cout << "-> ����������� ������ �������" << endl;
		else cout << "\t����������� ������" << endl;
		if (key == 1) cout << "-> ������" << endl;
		else cout << "\t������" << endl;
		if (key == 2) cout << "-> ��� �������" << endl;
		else cout << "\t��� �������" << endl;
		if (key == 3) cout << "-> ���������� ������" << endl;
		else cout << "\t���������� ������" << endl;
		if (key == 4) cout << "-> �����" << endl;
		else cout << "\t�����" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

void Hash(char*s)
{
    for(int i(0);i<strlen(s);i++)
        s[i]+=for_hash;
}
void antiHash(char*s)
{
     for(int i(0);i<strlen(s);i++)
        s[i]+=for_hash;
}
int basket_menu()
{
 int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 2) % 2;
		if (key == 0) cout << "-> �������� � �������" << endl;
		else cout << "\t�������� � �������" << endl;
		if (key == 1) cout << "-> ���������� �������" << endl;
		else cout << "\t���������� �������" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	return key;
	system("cls");
}

void changeUser(user now,information*products,int a)
{
    now.basket[now.counter_basket]=products[a-1];
}

int in_basket_menu()
{
  int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 2) % 2;
		if (key == 0) cout << "-> ������� �� �������" << endl;
		else cout << "\t������� �� �������" << endl;
		if (key == 1) cout << "-> ���������" << endl;
		else cout << "\t���������" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	return key;
	system("cls");
}

int form_menu()
{
   int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 2) % 2;
		if (key == 0) cout << "-> �������� �����" << endl;
		else cout << "\t�������� �����" << endl;
		if (key == 1) cout << "-> �����" << endl;
		else cout << "\t�����" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	return key;
	system("cls");
}

char* combine_string(char*s1,char*s2,char*s3)
{
    int lng = strlen(s1) + strlen(s2) + strlen(s3) + 1;
    char * filename = new char[lng];
    strcpy(filename, s1);
    strcat(filename, s2);
    strcat(filename, s3);
    return filename;
}
void output_string(char*s)
{
    for(int i(0);i<strlen(s);i++)
        cout<<s[i];
}
