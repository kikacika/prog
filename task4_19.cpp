//выполнить циклический сдвиг, так чтобы в начале находился первый максимальный элемент.

#include <iostream>

using namespace std;

struct stack{
 int inf;
 stack* next;
};
void push(stack *&h, int x){//добавление нового элемента в конец
    stack *r = new stack;  //создаем новый элемент
    r->inf = x; //поле inf = x
    r->next = h; //следу элем явл h
    h = r; //теперь r явл головой
}

int pop (stack *&h){ //удаление элемента и сохранение его значения
    int i = h->inf; //знач первого элем
    stack *r = h; //указатель на голову стека
    h = h->next; //переносим указатель на следующий элемент
    return i;
}
stack* reverse(stack* h) {
 stack* head1 = NULL;
 while (h){
  push(head1, pop(h)); //переписываем элементы из одного стека в другой
 }
 return head1;
}
int max_el(stack* h) {
 stack* temp = NULL;
 int max = pop(h);   //в max кладем первый элемент стека h
 push(temp, max);    //первый элемент стека h перекладываем в стек temp
 while (h) {
  int x = pop(h);
  if (x > max)
   max = x;
  push(temp, x);    //кладем извлеченный элемент в temp
 }
 temp = reverse(temp);
 h = temp;   //h будет указывать на temp
 return max;
}

int ind_max(stack* h) {
 stack* temp = NULL;
 temp = reverse(h);
 int m = max_el(temp);
 int j = 0;
 while (temp){
  int x = pop(temp);
  if (x == m)
   return j;
  j++;
 }
}

stack* sdvig(stack* h){
 stack* head1 = NULL;
 int x = pop(h);
 while (h){
  int y = pop(h);
  push(head1, y);
 }
 push(head1, x);
 head1 = reverse(head1);
 return head1;
}

stack* result(stack* h){
 int max = ind_max(h);  //ищем индекс максимального элемента
 h = reverse(h);
 for (int i = 0; i<max; i++){
  h = sdvig(h);
 }
 return (h);
}

int main(){
 stack* h = NULL;
 int n, x;
 cout << "n="; cin >> n;
 cout << "input elements: " << endl;
 for (int i=0; i<n; i++){
        cin >> x;
        push(h, x);
    }
 h = result(h);
 while (h) {
  cout << pop(h) << " ";
 }
 cout << endl;
    system("pause");
    return 0;
}
