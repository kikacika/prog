#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;


ifstream in("input.txt");
ofstream out("output.txt");

struct date {//дата
	int dd, mm, yy;

};


struct people {//данные о человеке
	string Surname; //фамилия
	date DateOfBirth; //дата рождения
	string Post;// должность
	int num;
	string Exp; // опыт
	int Salary; //зарплата

};

date Str_to_Date(string str) {//из строки в дату
	date x;
	string temp = str.substr(0, 2);//день
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2);//месяц
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4);//год
	x.yy = atoi(temp.c_str());
	return x;

};

vector<people> inFile() {//ввод из файла
	vector<people> x;
	people temp;
	while (in.peek() != EOF) {
		in >> temp.Surname;//фамилия
		in >> temp.Post; // должность
		string tmp;//дата рождения
		in >> tmp;
		temp.DateOfBirth = Str_to_Date(tmp);
		in >> temp.num;
		in >> temp.Exp;
		in >> temp.Salary;//зарплата
		x.push_back(temp);
	}
	return x;

};

void print(people x) {//вывод в файл
	out << setw(10) << left << x.Surname << ' ';//по левому краю, 10 позиций для фамилии
	out << left << setw(7) << x.Post << ' ';
	if (x.DateOfBirth.dd < 10) out << left << '0' << x.DateOfBirth.dd << '.';//добавляем 0
	else out << left << x.DateOfBirth.dd << '.';
	if (x.DateOfBirth.mm < 10) out << '0' << x.DateOfBirth.mm << '.';
	else out << x.DateOfBirth.mm << '.';
	out << left << setw(6) << x.DateOfBirth.yy;
	out << left << setw(2) << x.num << ' ';
	out << left << setw(7) << x.Exp << ' ';//на год 6 позиций
	out << left << setw(10) << x.Salary << endl;//запрлата

};


void insertSort(vector<people>& a, int size) {
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0; j--) // пока j>0 и элемент j-1 > j, то меняем; x-массив int
			if (a[j - 1].Surname > a[j].Surname)
				swap(a[j - 1], a[j]);
			else if (a[j - 1].Surname == a[j].Surname && a[j - 1].num > a[j].num)
				swap(a[j - 1], a[j]);
			else if (a[j - 1].Surname == a[j].Surname && a[j - 1].num == a[j].num && a[j - 1].DateOfBirth.yy > a[j].DateOfBirth.yy)
				swap(a[j - 1], a[j]);
}

int main() {
	setlocale(LC_ALL, "rus");
	vector<people> x;
	x = inFile();
	insertSort(x, x.size());
	for (int i = 0; i < x.size(); i++)
		print(x[i]);
	return 0;
}

