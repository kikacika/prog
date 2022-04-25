//после всех чисел, кратных y, вставить новый элемент
#include <iostream>

using namespace std;

struct queue{
    int inf;
    queue *next;
};

void push (queue *&h,queue *&t, int x){ //вставка элемента в очередь
    queue *r = new queue; //создаем новый элемент
    r->inf = x;
    r->next = NULL; //всегда последний
    if (!h && !t){ //если очередь пуста
        h = t = r; //это и голова и хвост
    }else{
        t->next = r; //r - следующий для хвоста
        t = r; //теперь r - хвост
    }
}

int pop (queue *&h,queue *&t){ //удаление элемента из очереди и сохранение его значения
    queue *r = h; //создаем указатель на голову
    int i = h->inf; //сохраняем значение головы
    h = h->next; //сдвигаем указатель на следующий элемент
    if (!h){ //если удаляем последний элемент из очереди
        t = NULL;
    }
    delete r; //удаляем первый элемент
    return i;
}

void result(queue*& h, queue*& t, int y, int a){
 queue* h_res = NULL, *t_res = NULL;
 while (h){
  int x = pop(h, t);
  push(h_res, t_res, x);
  if (x % y == 0){
   push(h_res, t_res, a);
  }
 }
 h=h_res; //замена исходной очереди на новую
 t=t_res;
}

int main(){
    queue *h = NULL, *t = NULL;//инициализируем очередь
    int n, x, y, a;
    cout << "n= "; cin >> n;
    cout << "X= "; cin >> y;
    cout << "new element= "; cin >> a;
    cout << "input elements: " << endl;
    for (int i=0; i<n; i++){
        cin >> x;
        push(h, t, x); //добавляем число в очередь
    }
 result(h, t, y, a);
 cout << "result: " << endl;
    while (h || t){
        cout << pop(h, t) << " ";// выводим очередь
    }
 cout << endl;
    system("pause");
    return 0;
}
