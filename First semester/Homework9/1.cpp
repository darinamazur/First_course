#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct scan_info {
	char model[25];
	int price;
	double x_size;
	double y_size;
	int optr;
	int grey;
};

scan_info *reading(int &number2);
int writing(scan_info *mas, int number);


int main()
{
	int number = 0;
	scan_info *f = reading(number);
	writing(f, number);
}

int writing(scan_info *mas, int number) {
	FILE *fo;
	fo = fopen("data.dat", "w+b");
	if (fo == NULL)
		return 1;
	int kol = 0;
	for (int i = 0; i < number; i++) {
		fwrite(&mas[i], sizeof(mas[i]), 1, fo);
	}

	int i = 0;
	cin >> i;
	if (i >= number) {
		cout << "Not exist";
		return 1;
	}

	scan_info m;
	fseek(fo, sizeof(m)*i, SEEK_SET);

	fread(&m, sizeof(m), 1, fo);
	cout << m.model << " " << m.price << " " << m.x_size << " " << m.y_size << " " << m.optr << " " << m.grey;
	fclose(fo);
	return 0;
}

scan_info *reading(int &number2) {
	int number;
	cin >> number;
	scan_info *mas = new scan_info[number];
	for (int i = 0; i < number; i++) {
		string mystr;
		cin.ignore();
		getline(cin, mystr);

		stringstream(mystr) >> mas[i].model;

		getline(cin, mystr);
		stringstream(mystr) >> mas[i].price;

		getline(cin, mystr);
		stringstream(mystr) >> mas[i].x_size;

		getline(cin, mystr);
		stringstream(mystr) >> mas[i].y_size;

		getline(cin, mystr);
		stringstream(mystr) >> mas[i].optr;

		getline(cin, mystr);
		stringstream(mystr) >> mas[i].grey;
	}
	number2 = number;
	return mas;
}
