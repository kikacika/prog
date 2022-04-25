//сортировка выбором
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

list *min(list *&h, list *&t){ //поиск минимального элемента
    list *min = h, *r = h->next; // выходной элемент и указатель
    while (r){
        if (r->inf < min->inf)
            min = r;
        r = r->next;
    }
    return min;
}

void result(list *&h, list *&t){
    list *l = h;  //указатель на голову, левая граница прохода цикла
    while (l){
        // Альтернативный вариант
        /*for (list* i = l->next; i; i = i->next) {
            if (l->inf > i->inf)
                swap(l->inf, i->inf);
        }*/
        swap(l->inf, min(l, t)->inf);
        l = l->next;
    }
}

int main(){
    list *h = NULL, *t = NULL;
    int n;
    cout << "n= "; cin >> n;
    for (int i = 0; i < n; ++i){ //заполнение списка
        int x;
        cin >> x;
        push(h, t, x);
    }
    result(h, t);
    list *r = h; //указатель на голову
    while (r){
        cout << r->inf << " ";
        r = r->next;
    }
    cout << endl;
    system("pause");
    return 0;
}
