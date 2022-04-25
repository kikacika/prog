//перед каждым минимальным элементом вставить новый элемент
#include<iostream>

using namespace std;

struct stack{
    int inf;
    stack *next;
};
void push(stack *&h, int x){ //добавление нового элемента в конец
    stack *r = new stack;  //создаем новый элемент
    r->inf = x; //поле inf = x
    r->next = h; //следу элем явл h
    h = r; //теперь r явл головой
}
int pop (stack *&h){ //удаление элемента и сохранение его значения
    int i = h->inf; //знач первого элем
    stack *r = h; //указатель на голову стека
    h = h->next; //переносим указатель на следующий элемент
    delete r; //уд первый элем
    return i;
}
void reverse(stack *&h) { //"обращение"стека
 stack *h1 = NULL;
 while (h){
        push(h1, pop(h));
 }
 h = h1;
}
stack *result(stack *&h, int m, int n) {
 stack *res = NULL;
 while (h){
  int x = pop(h);
  if (x == m){
            push(res, n);
            push(res, x); //вставка нового элемента, а после уже мин
  }else {
      push(res, x);
  }
 }
 reverse(res);
 return res;
}

int main(){
    int n, a;
    cout << "n= "; cin >> n;
    cout << "new element= "; cin >> a;
    stack *h = NULL; //инициализация
    int x,m=10000000;
    cout << "input elements: " << endl;
    for (int i=0; i<n; i++){ //заполняем стек
        cin >> x;
        if (x<m){   //поиск минимального
            m=x;
        }
        push(h, x);
    }
    reverse(h); //переворачиваем стек
    stack *res = result(h, m, a); //результат
    cout << "result: " << endl;
    while(res){
        cout << pop(res) << " "; //выводим на экран
    }
    cout << endl;
    system("pause");
    return 0;
}
