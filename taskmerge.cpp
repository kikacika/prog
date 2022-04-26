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


void mergeSort(vector<people>& a, size_t start, size_t end) {
	if (end - start < 2)
		return;
	if (end - start == 2) {
		if (a[start].Salary > a[start + 1].Salary || (a[start].Salary == a[start + 1].Salary && a[start].DateOfBirth.yy > a[start + 1].DateOfBirth.yy))
			swap(a[start], a[start + 1]);
		return;
	}
	mergeSort(a, start, start + (end - start) / 2);
	mergeSort(a, start + (end - start) / 2, end);
	vector<people> b;
	size_t b1 = start;
	size_t e1 = start + (end - start) / 2;
	size_t b2 = e1;
	while (b.size() < end - start) {
		if ((b1 >= e1 || (b2 < end && a[b2].Salary <= a[b1].Salary)) || (b1 >= e1 || (b2 < end && a[b2].Salary == a[b1].Salary) && a[b2].DateOfBirth.yy <= a[b1].DateOfBirth.yy)) {
			b.push_back(a[b2]);
			b2++;
		}
		else {
			b.push_back(a[b1]);
			b1++;
		}
	}
	for (size_t i = start; i < end; ++i) {
		a[i] = b[i - start];
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	vector<people> x;
	x = inFile();
	mergeSort(x, 0, x.size());
	for (int i = 0; i < x.size(); i++)
		print(x[i]);
	return 0;
}

