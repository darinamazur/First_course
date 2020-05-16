#include <iostream>
#include <cstdio>
#include <windows.h>//<3
#include <conio.h>
#include <cstring>
#include <string>
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

int menu(),getChar(char s[]),choose(), registration_menu(),menu1(),menu2(),menu3(),menu4();

void output(information product),findContact(FILE *my, information product, information odd, int i),
findProduct(FILE *my,FILE*users, information product, information odd, user _user,user&now, int i,information*products), changeUser(user now,information*products,int a),
Hash(char*s);

information getProduct(),changeProduct(information product);

bool compare(information product, information odd),compare_us(user _user,authorization odd);
user getUser(); authorization get_registr();user findUser(FILE *users, user _user, authorization odd,int i,int&admin,user&now);



int main()
{
    setlocale(0, "Russian");
     system("COLOR F5");
    int first_answer,a; FILE *users; user _user,now;
    now.counter_basket=0;
    now.price=0;
    information products[Size];
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
            users=fopen("users.txt","ab");
            _user=getUser();
            fwrite(&_user, sizeof(user), 1, users);
            fclose(users);
            system("pause");
            break;
        }
    case 1:
        {
            system("cls");
             authorization odd;
            cout<<"********************����********************"<<endl;
                   users =fopen("users.txt", "rb");
				   odd = get_registr();
				   fread(&_user, sizeof(user), 1, users);
				   int i(0);int admin;
				   findUser(users, _user, odd, i,admin,now);
				   fclose(users);
				   system("pause");


				   if(admin==1)
                   {



                       int answer, count(0); FILE *my; information product;
    do
	{
		system("cls");
		answer = menu();
		switch (answer)
		{
		case 0:
		{
				  cout << "*********************************������*********************************" << endl;
				  cout << "\t��� ��������� ���������� � ������ ������� �����,\n\t      ��� ������������� ������ ����� �������" << endl << endl;
				  my = fopen("text.txt", "rb");
				  int count(0);
				  fread(&products[count], sizeof(information), 1, my);
				  do
				  {
					  count++;
					  fread(&products[count], sizeof(information), 1, my);

				  } while (!feof(my));
				  fclose(my);
				  for (int i = 0; i < count; i++)
					  cout << "(" << i + 1 << ")" << products[i].title<<endl;
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
				  else { system("pause"); break; }
				  system("pause"); break;
		}
		case 1:
		{
				  my = fopen("text.txt", "ab");
				  cout << "********************************������� ������*********************************" << endl;
				  product = getProduct();
				  // system("pause");
				  product.existance = true;
				  fwrite(&product, sizeof(information), 1, my);
				  fclose(my);
				  system("pause");
				  break;
		}
        case 2:{
             my = fopen("text.txt", "rb+");
				   char s1[Size], s2[Size];
				   cout << "*******************************�������� ������*******************************" << endl;
				   cout << "                       �������� : \t";
				   cin.getline(s1, Size);
				   cout << "                       ����     : \t";
				   cin.getline(s2, Size);
				   int i(0); bool change = false;
				   fread(&product, sizeof(information), 1, my);
				   do
				   {
					   if ((strncmp(product.title, s1, strlen(product.title)) == 0) && (strncmp(product.price, s2, strlen(product.price)) == 0))
					   {
						   product.existance = false;
						   change = true;
						   break;
					   }
					   else { i++; }
					   fread(&product, sizeof(information), 1, my);
				   } while (!feof(my));
				   if (!change) cout << "                       ���� ������ ������" << endl;
				   else
				   {
					   fseek(my, (i)*sizeof(information), SEEK_SET);
					   fwrite(&product, sizeof(information), 1, my);
				   }

				   system("pause");
				   // system("pause");
				   fclose(my);

				   break;
        }
        case 3:{ char s1[Size], s2[Size]; bool change = false; int i(0);
				   my = fopen("text.txt", "rb+");
				   cout << "*********************�������������� ���������� � ������*********************" << endl;
				   cout << "                  �������� : \t";
				   cin.getline(s1, Size);
				   cout << "       ������ ������������ : \t";
				   cin.getline(s2, Size);
				   fread(&product, sizeof(information), 1, my);
				   // system("pause");
				   do
				   {
					   if ((strncmp(product.title, s1, strlen(product.title)) == 0) && (strncmp(product.country, s2, strlen(product.country))) == 0)
					   {
						   change = true;
						   break;
					   }
					   else { i++; }
					   fread(&product, sizeof(information), 1, my);
				   } while (!feof(my));
				   if (!change) cout << "                    ���� ������ ������" << endl;
				   else
				   {
					   system("cls");
					   cout << "****************************�������������� ������****************************" << endl;
					   fseek(my, (i)*sizeof(information), SEEK_SET);
					   fread(&product, sizeof(information), 1, my);
					   product = changeProduct(product);
					   fseek(my, (i)*sizeof(information), SEEK_SET);
					   fwrite(&product, sizeof(information), 1, my);
				   }
				   fclose(my);
				   system("pause");   break; }
        case 4:{
				   my = fopen("text.txt", "rb"); information odd;
				   cout << "*********************************����� ������*********************************" << endl;
				   odd = getProduct();
				   system("cls");
				   fread(&product, sizeof(information), 1, my);
				   int i(0);
				   findProduct(my,users, product, odd, _user,now, i,products);
				   fclose(my);
				   break;
		}
		case 5:{
				   my = fopen("text.txt", "rb"); information odd; information products[Size];
				   cout << "*********************************������*******************************" << endl;
				   odd = getProduct();
				   system("cls");
				   cout << "*********************************������******************************" << endl;
				   cout << "\t��� ��������� ���������� � ������ ������� �����,\n\t      ��� ������������� ������ ����� �������" << endl << endl;
				   bool find = false; int i(0);
				   // system("pause");
				   fread(&products[i], sizeof(information), 1, my);
				   do
				   {
					   if (compare(products[i], odd))
					   {
						   i++; find = true;
						   cout << "(" << i << ")" << " " << products[i - 1].title <<endl;
					   }
					   fread(&products[i], sizeof(information), 1, my);
				   } while (!feof(my));
				   if (!find) cout << "                   ���� ����� �������" << endl;
				   else
				   {
					   char s[Size];
					   cout << "\t\t ����� : ";
					   cin.getline(s, Size);
					   if (*s != '\0')
					   {
						   system("cls");
						   cout << "*********************************������******************************" << endl;
						   int a = getChar(s);
						   output(products[a - 1]);
					   }
				   }
				   fclose(my); system("pause");
				   break; }
        case 6:{ FILE *nw = fopen("new.txt", "wb");
			my = fopen("text.txt", "rb");
			cout << "***************************���������� ����������****************************";
			fread(&product, sizeof(information), 1, my);
			do
			{
				if (product.existance)
				{
					fwrite(&product, sizeof(information), 1, nw);
				}
				fread(&product, sizeof(information), 1, my);

			} while (!feof(my));
			cout << endl << "\t\t\t �������� ������� ��������� " << endl << endl;
			fclose(nw);
			fclose(my);
			remove("text.txt");
			// system("pause");
			rename("new.txt", "text.txt");
			system("pause");
			break; }
		case 7: break;
		}
	} while (answer != 7);
                   }



        else if(admin==2)
        {
        int answer1; FILE *my; information product;
    do
	{
		system("cls");
		answer1 = menu1();
		// system("pause");
		switch (answer1)
		{
		   case 0:
		{
				  cout << "*********************************������*********************************" << endl;
				  cout << "\t��� ��������� ���������� � ������ ������� �����,\n\t      ��� ������������� ������ ����� �������" << endl << endl;
				  my = fopen("text.txt", "rb");
				  int count(0); information products[Size];
				  fread(&products[count], sizeof(information), 1, my);
				  do
				  {
					  count++;
					  fread(&products[count], sizeof(information), 1, my);

				  } while (!feof(my));
				  fclose(my);
				  for (int i = 0; i < count; i++)
					  cout << "(" << i + 1 << ")" << products[i].title<<endl;
				  cout << "\n\t\t����� : ";
				  char s[Size];
				  cin.getline(s, Size);
				  if (*s != '\0')
				  {
					  a = getChar(s);
					  system("cls");
					  cout << "*********************************������*********************************" << endl;
					  output(products[a - 1]);
					  system("pause");
                    int answer2;
					  do
                  {
                       answer2=menu2();
                       switch(answer2)
                       {
                       case 0:
                        {
                            now.basket[now.counter_basket]=products[a-1];
                            now.counter_basket++;
                            cout<<"����� "<<now.basket[now.counter_basket-1].title<<" ������� ��������"<<endl;
                            char s1[Size], s2[Size]; bool change = false; int i(0);
				   users = fopen("users.txt", "rb+");
				   fread(&_user, sizeof(user), 1, users);
				   do
				   {
					   if (strncmp(_user.person.name,now.person.name, strlen(now.person.name)) == 0)
					   {
						   change = true;
						   break;
					   }
					   else { i++; }
					   fread(&_user, sizeof(user), 1, users);
				   } while (!feof(users));
					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   fread(&_user, sizeof(user), 1, users);
					   // system("pause");
					   // system("pause");
					   changeUser(now,products,a);
					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   fwrite(&now, sizeof(user), 1, users);
					   fclose(users);
				   }
                    system("pause");

                       case 1:
				   break; }

                        break;
                       }
				 while (answer2!=1);
				  }
				  else  break;

				  break;
		}

          case 1:{
				   my = fopen("text.txt", "rb"); information odd;
				   cout << "*********************************����� ������*********************************" << endl;
				   odd = getProduct();
				   system("cls");
				   // system("pause");
				   fread(&product, sizeof(information), 1, my);
				   int i(0);
				   findProduct(my,users, product, odd,_user,now, i,products);
				   fclose(my);
				   break;
		}
		  case 2:{
				   my = fopen("text.txt", "rb"); information odd; information products[Size];
				   cout << "*********************************������*******************************" << endl;
				   odd = getProduct();
				   system("cls");
				   // system("pause");
				   // system("pause");
				   cout << "*********************************������******************************" << endl;
				   cout << "\t��� ��������� ���������� � ������ ������� �����,\n\t      ��� ������������� ������ ����� �������" << endl << endl;
				   bool find = false; int i(0);
				   fread(&products[i], sizeof(information), 1, my);
				   do
				   {
					   if (compare(products[i], odd))
					   {
						   i++; find = true;
						   cout << "(" << i << ")" << " " << products[i - 1].title <<endl;
					   }
					   fread(&products[i], sizeof(information), 1, my);
				   } while (!feof(my));
				   if (!find) cout << "                   ���� ����� �������" << endl;
				   else
				   {
					   char s[Size];
					   cout << "\t\t ����� : ";
					   cin.getline(s, Size);
					   if (*s != '\0')
					   {
						   system("cls");
						   cout << "*********************************������******************************" << endl;
						   int a = getChar(s);
						   output(products[a - 1]);
						   system("pause");
						       int answer2;
					  do
                  {
                       answer2=menu2();
                       switch(answer2)
                       {
                       case 0:
                        {
                            now.basket[now.counter_basket]=products[a-1];
                            now.counter_basket++;
                            cout<<"����� "<<now.basket[now.counter_basket-1].title<<" ������� ��������"<<endl;
                            char s1[Size], s2[Size]; bool change = false; int i(0);
				   users = fopen("users.txt", "rb+");
				   fread(&_user, sizeof(user), 1, users);
				   do
				   {
					   if (strncmp(_user.person.name,now.person.name, strlen(now.person.name)) == 0)
					   {
						   change = true;
						   break;
					   }
					   else { i++; }
					   fread(&_user, sizeof(user), 1, users);
				   } while (!feof(users));
					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   fread(&_user, sizeof(user), 1, users);
					   // system("pause");
					   // system("pause");
					   changeUser(now,products,a);
					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   fwrite(&now, sizeof(user), 1, users);
					   fclose(users);
				   }
                    system("pause");

                       case 1:
				   break; }

                        break;
                       }
				 while (answer2!=1);
					   }
				   }
				   fclose(my);
				   break; }
          case 3:
            {
                information products[Size];
                cout<<"********************��� �������*********************"<<endl<<endl;

                cout << "\t��� ��������� ���������� � ������ ������� �����,\n\t      ��� ������������� ������ ����� �������" << endl << endl;
				  my = fopen("text.txt", "rb");
				  for (int i = 0; i < now.counter_basket; i++)
                  cout << "(" << i + 1 << ")" << now.basket[i].title<<endl;



                        users = fopen("users.txt", "rb+");
				   fread(&_user, sizeof(user), 1, users);
				   do
				   {
					   if (strncmp(_user.person.name,now.person.name, strlen(now.person.name)) == 0)
						   break;
					   else { i++; }
					   fread(&_user, sizeof(user), 1, users);
				   } while (!feof(users));
					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   fread(&_user, sizeof(user), 1, users);
					   // system("pause");
					   // system("pause");

					   now.price=0;
					   for (int i(0);i<now.counter_basket;i++)
					   now.price+=atoi(now.basket[i].price);

					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   fwrite(&now, sizeof(user), 1, users);
					   fclose(users);



                      cout<<"           ����� :   "<<now.price<<endl<<endl<<endl;
				  cout << "\n\t\t����� : ";
				  char s[Size];
				  cin.getline(s, Size);
				  if (*s != '\0')
				  {
					  a = getChar(s);
					  system("cls");
					  cout << "*********************************������*********************************" << endl;
					  output(now.basket[a - 1]);
					  fclose(my);
					  system("pause");
					  cout<<endl;
                      int answer3;
					  do
                  {
                       answer3=menu3();
                       switch(answer3)
                       {
                       case 0:
                           {
                               cout<<"����� "<<now.basket[a-1].title<<" ������� ������ �� �������"<<endl;
                               system("pause");
                    users = fopen("users.txt", "rb+");
				   fread(&_user, sizeof(user), 1, users);
				   int i(0);
				   do
				   {
					   if (strncmp(_user.person.name,now.person.name, strlen(now.person.name)) == 0)
						   break;
					   else i++;
					   fread(&_user, sizeof(user), 1, users);
				   } while (!feof(users));

					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   //cout<<i<<endl<<endl;
					   //system("pause");
					   fread(&_user, sizeof(user), 1, users);
					   //cout<<now.counter_basket<<endl;
					   //system("pause");
					   for(int i(a-1);i<now.counter_basket-1;i++)
                       now.basket[i]=now.basket[i+1];
                       now.counter_basket--;
					   //cout<<now.counter_basket<<endl;
					   //system("pause");
					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   fwrite(&now, sizeof(user), 1, users);
					   fclose(users);
                               break;
                           }
                       case 1:
                        break;
                       }
                  }while(answer3!=1);
                system("pause");
                break;
                }
            break;
            }
            case 4:
                {
                    cout<<"***************���������� ������***************"<<endl<<endl;
                     int answer4;
					  do
                  {
                       answer4=menu4();
                       switch(answer4)
                       {
                       case 0:
                           {
                               cout<<"�� �������� ����� �� ����� "<<now.price<<" ������"<<endl<<endl;
                               cout<<"������� �� �������, ��������� ���!"<<endl<<endl;

                                users = fopen("users.txt", "rb+");
				   fread(&_user, sizeof(user), 1, users);
				   int i(0);
				   do
				   {
					   if (strncmp(_user.person.name,now.person.name, strlen(now.person.name)) == 0)
						   break;
					   else i++;
					   fread(&_user, sizeof(user), 1, users);
				   } while (!feof(users));

					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   //cout<<i<<endl<<endl;
					   //system("pause");
					   fread(&_user, sizeof(user), 1, users);
					   //cout<<now.counter_basket<<endl;
					   //system("pause");
					   now.counter_basket=0;
					   now.price=0;
					   //cout<<now.counter_basket<<endl;
					   //system("pause");
					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   fwrite(&now, sizeof(user), 1, users);
					   fclose(users);
                               system("pause");
                           }
                        case 1: break;

                       }

                }while(answer4!=1);
                break;
                }
		  case 5: break;
		}
    }
		while (answer1!= 5);
				   }
        else if(admin==3) break;
				   break;}
    case 2: break;
     }
    }
    while (first_answer!=2);
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
int menu()
{
    int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 8) % 8;
		if (key == 0) cout << "-> ����������� ������ �������" << endl;
		else cout << "\t����������� ������" << endl;
		if (key == 1) cout << "-> �������� �����" << endl;
		else cout << "\t�������� �����" << endl;
		if (key == 2) cout << "-> ������� �����" << endl;
		else cout << "\t������� �����" << endl;
		if (key == 3) cout << "-> ������������� ������ � ������" << endl;
		else cout << "\t������������� ������ � ������" << endl;
		if (key == 4) cout << "-> ����� �����" << endl;
		else cout << "\t����� �����" << endl;
		if (key == 5) cout << "-> ������" << endl;
		else cout << "\t������" << endl;
		if (key == 6) cout << "-> ���������� ����������" << endl;
		else cout << "\t��������� ����������" << endl;
		if (key == 7) cout << "-> �����" << endl;
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

information changeProduct(information product)
{
     char s[Size];

	cout << "                       ��������: \t";
	cin.getline(s, Size);
	if (*s != '\0')  strcpy(product.title, s);

	cout << "           ������ ������������ : \t";
	cin.getline(s, Size);
	if (*s != '\0')  strcpy(product.country, s);

	cout << "                          ���� : \t";
	cin.getline(s, Size);
	if (*s != '\0')  strcpy(product.colour, s);

	cout << "                          ���� : \t";
	cin.getline(s, Size);
	if (*s != '\0')  strcpy(product.price, s);

	cout << "             ���� ������������ : \n";
	cout << "                      -  ����� : \t";
	cin.getline(s, Size);
	if (*s != '\0')  strcpy(product.was_made.day, s);
	cout << "                      -  ����� : \t";
	cin.getline(s, Size);
	if (*s != '\0')  strcpy(product.was_made.month, s);
	cout << "                      -  ���   : \t";
	cin.getline(s, Size);
	if (*s != '\0')  strcpy(product.was_made.year, s);

	cout << "                           ��� :\t";
	cin.getline(s, Size);
	if (*s != '\0')  strcpy(product.weight, s);

	cout << "                      �������� :\t";
	cin.getline(s, Size);
	if (*s != '\0')  strcpy(product.warranty, s);

	cout << "                  ����� ������ :\t";
	cin.getline(s, Size);
	if (*s != '\0')  strcpy(product.id, s);

	cout << "                 ������� (+/-) : \t";
	cin.getline(s, Size);
	if (*s != '\0')
	{
		if (*s == '+') product.existance = true;
		else product.existance = false;
	}
	return product;
}
void findProduct(FILE *my,FILE*users, information product, information odd, user _user,user&now, int i,information*products)
{
   cout << "*********************************����� ������*********************************" << endl;
	bool find = false;
	do
	{
		if (compare(product, odd))
		{
			cout << "  �����, ������� �������� ��� �������, ������. ��� : " << product.title<< endl;
			find = true;  i--; break;
		}
		fread(&product, sizeof(information), 1, my); i++;
	} while (!feof(my)); i++;
	if (!find)
	{
		cout << "                        ���� ������ ������" << endl;
		system("pause");
	}
	else do
	{
		system("pause");
		int a = choose();
		switch (a)
		{
		case 0:
		{
				  system("cls");
				  cout << "*********************************����� ������*********************************" << endl;
				  fseek(my, i*sizeof(information), SEEK_SET);
				  fread(&product, sizeof(information), 1, my);
				  output(product);
				  system("pause");
                    int answer2;
					  do
                  {
                       answer2=menu2();
                       switch(answer2)
                       {
                       case 0:
                        {
                            now.basket[now.counter_basket]=product;
                            now.counter_basket++;
                            cout<<"����� "<<now.basket[now.counter_basket-1].title<<" ������� ��������"<<endl;
                            int i(0);
				   users = fopen("users.txt", "rb+");
				   fread(&_user, sizeof(user), 1, users);
				   do
				   {
					   if (strncmp(_user.person.name,now.person.name, strlen(now.person.name)) == 0)
                        break;
					   else { i++; }
					   fread(&_user, sizeof(user), 1, users);
				   } while (!feof(users));
					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   fread(&_user, sizeof(user), 1, users);
					   // system("pause");
					   // system("pause");
					   now.basket[now.counter_basket]=product;
					   fseek(users, (i)*sizeof(user), SEEK_SET);
					   fwrite(&now, sizeof(user), 1, users);
					   fclose(users);
				   }
                    system("pause");

                       case 1:
				   break; }

                        break;
                       }
				 while (answer2!=1);
				  break;
		}
		case 1:
		{
				  system("cls");
				  fread(&product, sizeof(information), 1, my);
				  if (feof(my))
				  {
					  system("pause"); break;
				  }
				  i++;
				  findProduct(my,users, product, odd,_user,now, i,products);
				  break;
		}
		case 2:
		{
				  system("cls");
				  cout << "*********************************����� ������*********************************" << endl;
				  break;
		}

		}
	} while ((!feof) && (!find));
}
bool compare(information product, information odd)
{
	return((!strcmp(product.title, odd.title) || (*odd.title == '\0')) &&
		(!strcmp(product.country, odd.country) || (*odd.country == '\0')) &&
		(!strcmp(product.was_made.day, odd.was_made.day) || (*odd.was_made.day == '\0')) &&
		(!strcmp(product.was_made.month, odd.was_made.month) || (*odd.was_made.month == '\0')) &&
		(!strcmp(product.was_made.year, odd.was_made.year) || (*odd.was_made.year == '\0')) &&
		(!strcmp(product.price, odd.price) || (*odd.price == '\0')) &&
		(!strcmp(product.weight, odd.weight) || (*odd.weight == '\0')) &&
		(!strcmp(product.colour, odd.colour) || (*odd.colour == '\0')) &&
		(!strcmp(product.price, odd.price) || (*odd.price == '\0')) &&
		(!strcmp(product.warranty, odd.warranty) || (*odd.warranty == '\0'))&&
        (!strcmp(product.id, odd.id) || (*odd.id == '\0')));
}
int choose()
{
	int key = 0;
	int code;
	do
	{
		system("cls");
		cout << "*********************************����� ������*********************************" << endl;
		key = (key + 3) % 3;
		if (key == 0) cout << "-> ����������� ��� ����������" << endl;
		else cout << "\t����������� ��� ����������" << endl;
		if (key == 1) cout << "-> �������� ��������� ���������� �����" << endl;
		else cout << "\t�������� ��������� ���������� �����" << endl;
		if (key == 2) cout << "-> ����� � ������� ����" << endl;
		else cout << "\t����� � ������� ����" << endl;
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
    return user;
}

user findUser(FILE *users, user _user, authorization odd,int i,int&admin,user&now)
{
    system("cls");
    cout << "**************************����� ������������**************************" << endl;
	bool find = false;
	do
	{
		if (compare_us(_user, odd))
		{
			cout << "������������ ������. ��� : " << _user.person.name<<" "<<_user.person.surname<< endl;
			now=_user;
			find = true; if(*_user.is_administration=='+') admin=1; else admin=2; break;
		}
		fread(&_user, sizeof(user), 1, users); i++;
	} while (!feof(users));
	if (!find) {cout<<"������������ �� ������, �������� �����������"<<endl;admin=3;}
}

bool compare_us(user _user,authorization odd)
{
   return((!(strcmp(_user.inform.login, odd.login))) && (!(strcmp(_user.inform.password, odd.password))));
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

int menu1()
{
    int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 6) % 6;
		if (key == 0) cout << "-> ����������� ������ �������" << endl;
		else cout << "\t����������� ������" << endl;
		if (key == 1) cout << "-> ����� �����" << endl;
		else cout << "\t����� �����" << endl;
		if (key == 2) cout << "-> ������" << endl;
		else cout << "\t������" << endl;
		if (key == 3) cout << "-> ��� �������" << endl;
		else cout << "\t��� �������" << endl;
		if (key == 4) cout << "-> ���������� ������" << endl;
		else cout << "\t���������� ������" << endl;
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

void Hash(char*s)
{
    for(int i(0);i<strlen(s);i++)
        s[i]+=for_hash;
}

int menu2()
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

int menu3()
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

int menu4()
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
