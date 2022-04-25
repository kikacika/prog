//сначала вывести гласные, потом согласные буквы
#include<iostream>

using namespace std;

struct stack{
    char inf;
    stack *next;
};
void push(stack *&h, char x){//добавление нового элемента в конец
    stack *r = new stack;  //создаем новый элемент
    r->inf = x; //поле inf = x
    r->next = h; //следу элем явл h
    h = r; //теперь r явл головой
}
char pop (stack *&h){ //удаление элемента и сохранение его значения
    char i = h->inf; //знач первого элем
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
bool glas (char x){
    if ( x == 'a'  x == 'u' x == 'e'|| x == 'i'|| x == 'o'|| x == 'y' ) return true;
    return false;
}
stack* result(stack*& h){
 stack *res = NULL;
 stack *h1 = NULL;
 while (h){
  char x = pop(h);
  if (!glas(x)){
            push(res, x);
  }else{
            push(h1, x);
  }
 }
 reverse(res);
 while (h1){
  push(res, pop(h1));
 }
 return res;
}

int main(){
    int n;
    cout << "n= "; cin >> n;
    stack *h = NULL; //инициализация
    char x;
    cout << "input elements: " << endl;
    for (int i=0; i<n; i++){
        cin >> x;
        push(h, x);
    }
    reverse(h); //переворачиваем стек
    stack *res = result(h); //результат
    cout << "result: " << endl;
    while(res){
        cout << pop(res) << " "; //выводим на экран
    }
    cout << endl;
    system("pause");
    return 0;
}
