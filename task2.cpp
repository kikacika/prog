//изменить список, переместив в начало все элементы, меньшие Х, потом большие или равные Х
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

void del_node(list *&h, list *&t, list *&r){//удаление заданного элемента
    int i = r->inf;
    if (r == h && r == t){ //единичный список
        h = t = NULL;
    }else{ if (r == h){ //удаление головы
                h = h->next;
                h->prev = NULL;
            }else{ if (r == t){ //удаление хвоста
                    t = t->prev;
                    t->next = NULL;
                    }else{
                        r->next->prev = r->prev;
                        r->prev->next = r->next;
                    }
            }
    }
    delete r;
}

void result(list *&h, list *&t, int x){
    list *r = h, *rt = t;  // указатели на голову и хвост
    while (r != rt){       //проход по списку
        if (r->inf >= x){   //перемещение в конец, если >= X
            list *p = r;        //указатель на элемент
            push(h, t, r->inf); // копирование в конец списка
            r = r->next;        // перемещение на следующий
            del_node(h, t, p);  // удаление
        }
        else
            r = r->next;
    }

    if (rt->inf >= x){ // проверка последнего элемнета элемента
        push(h, t, rt->inf); // копирование в конец списка
        del_node(h, t, rt);  // удаление
    }
}

int main(){
    list *h = NULL, *t = NULL;
    int n, x;
    cout << "n= "; cin >> n;
    cout << "X= "; cin >> x;
    for (int i = 0; i < n; ++i){ //заполнение списка
        int y;
        cin >> y;
        push(h, t, y);
    }
    result(h, t, x);
    list *r = h; //указатель на голову
    while (r){
        cout << r->inf << " ";
        r = r->next;
    }
    cout << endl;
    system("pause");
    return 0;
}
