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

void quickSort(vector<people>& a, int left, int right) {
	int i = left;
	int j = right;
	int ref = a[(left+right) / 2].Salary;
	do {
		while (a[i].Salary < ref) {
			i++;
		}
		while (a[j].Salary > ref) {
			j--;
		}
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > left)
		quickSort(a, left, j);
	if (i < right)
		quickSort(a, i, right);
}

int main() {
	setlocale(LC_ALL, "rus");
	vector<people> x;
	x = inFile();
	quickSort(x,0,x.size() - 1);
	for (int i = 0; i < x.size(); i++)
		print(x[i]);
	return 0; 
}

