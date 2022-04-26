#include <iostream>
#include <string>

using namespace std;

struct list {
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x) {
	list* r = new list;
	r->inf = x;
	r->next = nullptr;
	if (!h && !t) {
		r->prev = nullptr;
		h = r;
	}
	else {
		t->next = r;
		r->prev = t;
	}
	t = r;
}

void insert_after(list*& h, list*& t, list*& r, int x) {
	list* p = new list;
	p->inf = x;
	if (r == t) {
		p->next = nullptr;
		p->prev = r;
		r->next = p;
		t = p;
	}
	else {
		r->next->prev = p;
		p->next = r->next;
		p->prev = r;
		r->next = p;
	}
}

void print(list*& h, list*& t) {
	list* p = h;
	while (p) {
		cout << p->inf << " ";
		p = p->next;
	}
}

list* find(list*& h, list*& t, int x) {
	list* p = h;
	while (p) {
		if (p->inf == x)
			break;
		p = p->next;
	}
	return p;
}

void del_node(list*& h, list*& t, list*& r) {
	if (h == r && t == r)
		h = t = nullptr;
	else
		if (h == r) {
			h = h->next;
			h->prev = nullptr;
		}
		else 
			if (t == r) {
				t = t->prev;
				t->next = nullptr;
			}
			else {
				r->prev->next = r->next;
				r->next->prev = r->prev;
			}
	delete r;
}

void del_list(list*& h, list*& t) {
	while (h) {
		list* p = h;
		h = h->next;
		h->prev = nullptr;
		delete p;
	}
}

void reversed_print(list*& h, list*& t) {
	list* p = t;
	while (p) {
		cout << p->inf << " ";
		p = p->prev;
	}
}

list* find_last_even(list*& h, list*& t) {
	list* p = t;
	while (p->inf % 2) 
		p = p->prev;
	
	return p;
}

list* find_first_min(list*& h, list*& t) {
	list* p = h;
	list* min = p;
	while (p) {
		if (p->inf < min->inf)
			min = p;
		p = p->next;
	}

	return min;
}

list* find_last_max(list*& h, list*& t) {
	list* p = h;
	list* max = p;
	while (p) {
		if (p->inf >= max->inf)
			max = p;
		p = p->next;
	}

	return max;
}

void list_copy(list*& h1, list*& t1, list*& h, list*& t) {
	list* p = h;
	while (p) {
		push(h1, t1, p->inf);
		p = p->next;
	}
}

int main() {
	list* h = nullptr;
	list* t = nullptr;
	int n = 0; cout << "Input n = "; cin >> n;
	int x = 0; cout << "Input list: "; for (int i = 0; i < n; cin >> x, push(h, t, x), ++i);

	cout << "1. Reversed list: "; reversed_print(h, t); cout << "\n";

	list* r = find_last_even(h, t);
	cout << "2. Last even element = " << r->inf << "\n";

	list* h1 = nullptr;
	list* t1 = nullptr;
	list_copy(h1, t1, h, t);

	list* min = find_first_min(h1, t1);
	del_node(h1, t1, min);
	cout << "3. Delete first min element: "; print(h1, t1); cout << "\n";

	list* max = find_last_max(h, t);
	insert_after(h, t, max, 0);
	cout << "4. Insert 0 after last max element: "; print(h, t); cout << "\n";

	return 0;
}