#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct queue {
	int inf;
	queue* next;
};

struct stack {
	int inf;
	stack* next;
};

void push_queue(queue*& h, queue*& t, int x) {
	queue* r = new queue;
	r->inf = x;
	r->next = nullptr;
	if (!h && !t) 
		h = t = r;
	else {
		t->next = r;
		t = r;
	}
}

int pop_queue(queue*& h, queue*& t) {
	queue* r = h;
	int i = h->inf; 
	h = h->next; 
	if (!h) 
		t = nullptr;
	delete r; 
	return i;
}

void push_stack(stack*& h, int x) {
	stack* r = new stack; 
	r->inf = x; 
	r->next = h; 
	h = r;
}

int pop_stack(stack*& h) {
	int i = h->inf; 
	stack * r = h; 
	h = h->next; 
	delete r; 
	return i;
}

void depth(vector<vector<int>> &array, int x, int n, int* arr) {
	stack* h = nullptr;

	arr[x] = 1;
	push_stack(h, x);
	cout << x << " ";

	while (h) {
		bool fl = false;
		int r = h->inf;
		int y = 0;
		for (vector<int>::iterator it = array[r].begin(); it != array[r].end(); ++it)
			if (!arr[*it]) {
				y = *it;
				fl = true;
				break;
			}
		if (fl) {
			arr[y] = 1;
			push_stack(h, y);
			cout << y << " ";
		}
		else
			pop_stack(h);
	}
	for (int i = 0; i < n; ++i)
		if (!arr[i])
			depth(array, i, n, arr);
}

void width(vector<vector<int>> &array, int x, int n, int* arr) {
	queue* h = nullptr;
	queue* t = nullptr;

	arr[x] = 1;
	push_queue(h, t, x);
	cout << x << " ";

	while (h) {
		int r = pop_queue(h, t);
		int y = 0;
		for (vector<int>::iterator it = array[r].begin(); it != array[r].end(); ++it)
			if (!arr[*it]) {
				y = *it;
				arr[y] = 1;
				push_queue(h, t, y);
				cout << y << " ";
			}
	}
	for (int i = 0; i < n; ++i)
		if (!arr[i])
			width(array, i, n, arr);
}

int main() {
	int n = 0; cout << "Input n = "; cin >> n;
	vector<vector<int>> array;
	array.resize(n);
	string str = ""; getline(cin, str);
	cout << "Input graph:\n";
	for (int i = 0; i < n; ++i) {
		cout << i << ": ";
		getline(cin, str);
		bool flag = true;
		for (string::size_type pos = 0; pos < str.length(); pos = str.find(' ', pos + 1)) {
			if (!flag)
				pos += 1;
			array[i].push_back(stoi(str.substr(pos, str.find(' ', pos + 1) - pos)));
		}
	}

	int* dep = new int[n];
	for (int i = 0; i < n; ++i)
		dep[i] = 0;

	cout << "\n";
	cout << "Depth tracing: "; depth(array, 0, n, dep);
	cout << "\n";
	
	int* wide = new int[n];
	for (int i = 0; i < n; ++i)
		wide[i] = 0;

	cout << "\n";
	cout << "Width tracing: "; width(array, 0, n, wide);
	cout << "\n";
	
	return 0;
}

/*
0 1 1 0 1 1 0
1 0 0 1 0 0 0
1 0 0 0 0 1 0
0 1 0 0 0 0 0
1 0 0 0 0 0 1
1 0 1 0 0 0 1
0 0 0 0 1 1 0

1 2 4 5
0 3
0 5
1
0 6
0 2 6
4 5
*/