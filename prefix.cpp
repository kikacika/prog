#include <iostream>
#include <string>

using namespace std;

struct stack {
	string inf;
	stack* next;
};

void push(stack*& h, string x) {
	stack* r = new stack;
	r->inf = x;

	if (!h) {
		r->next = nullptr;
		h = r;
	}
	else {
		r->next = h;
		h = r;
	}
}

string pop(stack*& h) {
	stack* p = h;
	string i = p->inf;
	h = h->next;

	delete p;
	return i;
}

void print(stack* h) {
	while (h)
		cout << pop(h) << " ";
}

string itos(int x) {
	string res = "";
	while (x > 0) {
		res.insert(0, 1, (x % 10) + '0');
		x /= 10;
	}
	return res;
}

int main() {
	stack* h = nullptr;

	string x = ""; cin >> x;
	for (string::size_type i = 0; i < x.length(); ++i) {
		if (!(isdigit(x[i])))
			push(h, x.substr(i, 1));
		else
			if (!isdigit(h->inf[0]))
				push(h, x.substr(i, 1));
			else {
				int x2 = stoi(x.substr(i, 1));
				while (h && isdigit(h->inf[0])) {
					int x1 = stoi(pop(h));
					string op = pop(h);

					if (op == "+")
						x2 += x1;
					else
						if (op == "-")
							x2 = x1 - x2;
						else
							if (op == "*")
								x2 *= x1;
							else
								if (op == "/")
									x2 = x1 / x2;
				}
				push(h, itos(x2));
			}
	}

	cout << "Result: "; print(h); cout << "\n";

	return 0;
}