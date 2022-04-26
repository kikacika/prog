#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
#include <algorithm>
#include <numeric>

using namespace std;

void print(vector<int> vec) {
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); cout << *it << " ", ++it); cout << "\n";
}

vector<int> create_vector(int n) {
	vector<int> vec;
	for (int i = 0; i < n; vec.push_back(rand() % 10000), ++i);

	//for (int i = 0; i < n; cin >> vec[i], ++i);

	print(vec);

	return vec;
}

void class_sort(vector<int>& vec, int k_10, int n) {
	//Рекурсивно выполняем данную функцию, пока не отсортируем все подвекторы вектора data
	vector<vector<int>> data;
	data.resize(10);

	for (int j = 0; j < n; ++j)
		data[(vec[j] / k_10) % 10].push_back(vec[j]);

	for (int i = 0; i < 10; ++i)
		if (data[i].size() > 1)
			class_sort(data[i], k_10 / 10, data[i].size());

	vec.clear();

	for (int j = 0; j < 10; ++j) {
		for (vector<int>::iterator it = data[j].begin(); it != data[j].end(); vec.push_back(*it), ++it);
		data[j].clear();
	}
}

void RadixSortMSD(vector<int> &vec, int n) {
	//Максимальное число
	int mx = 0;
	for (int i = 0; i < n; mx = max(mx, vec[i]), ++i);

	//Максимальный разряд 
	int k = 0;
	for (int i = 0; mx > 0; ++k, ++i)
		mx /= 10;

	//10^k
	int k_10 = 1;
	for (int i = 0; i < k - 1; k_10 *= 10, ++i);
	
	class_sort(vec, k_10, n);
}

int main() {
	srand(time(0));
	int n = 0; cout << "Input n = "; cin >> n;

	vector<int> vec = create_vector(n);

	RadixSortMSD(vec, n); 
	
	print(vec);
}

/*
* 
* data[i].size() > 1

6134 65 5053 8707 7376 3466 1865 4163 1430 6558



0:
1: 
2:
3:
4: 
5: 
6:
7:
8: 
9:

0: 65
1: 1430 1865
2: 
3: 3466
4: 4163
5: 5034
6: 6134 6558
7: 7376
8: 8707
9:



*/