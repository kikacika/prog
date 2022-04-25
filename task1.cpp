//после всех максимальных элементов вставить минимальный элемент
#include <iostream>

using namespace std;

struct list{
    int inf;    //значение элемента
    list *prev; //следюущий элемент
    list *next; //предыдущий элемент
};

void push(list *&h, list *&t, int x){ //добавление нового элемента в конец
    list *r = new list; //создание нового элемента
    r->inf = x;
    r->next = NULL;
    r->prev = t;
    if (!h && !t){ //первый элемент
        h = r;
    }else{
        t->next = r;
    }
    t = r; //перемещение хвоста на новый элемент
}


void insert_after(list *&h, list *&t, list *&r, int x){//добавление нового элемента после заданного
    list *p = new list; //создание нового элемента
    p->inf = x;
    if (r == t){ //добавление в конец
        p->next = NULL;
        p->prev = r;
        r->next = p;
        t = p;
    }else{
        r->next->prev = p;
        p->next = r->next;
        p->prev = r;
        r->next = p;
    }
}

void result(list *&h, list *&t, int min, int max){
    list *r = h; //указатель на голову
    while (r){
        if (r->inf == max){    //если max
            insert_after(h, t, r, min); // вставить после него min
        }
        r = r->next;
    }
}

int main(){
    int n, min=1000000, max = -min;
    list *h = NULL, *t = NULL;
    cout << "n= "; cin >> n;
    for (int i = 0; i < n; ++i){ //заполнение списка
        int x;
        cin >> x;
        push(h, t, x);
        if (x > max) //поиск максимального
            max = x;
        if (x < min) //поиск минимального
            min = x;
    }
    result(h, t, min, max);
    list *r = h; //указатель на голову
    while (r){
        cout << r->inf << " ";
        r = r->next;
    }
    cout << endl;
    system("pause");
    return 0;
}
