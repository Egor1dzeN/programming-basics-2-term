//Сортировка выбором
//Алгоритм сам по себе просой:
//1.	Находим номер минимального значения в текущем списке.
//2.	Производим обмен найденного значения со значением первой неотсортированной позиции (обмен не нужен, если минимальный   элемент уже находится на данной позиции).
//3.	Сортируем хвост списка, исключив из рассмотрения уже отсортированные элементы.

#include <iostream>
#include <stdlib.h>
#include<map>
#include <vector>

using namespace std;
#define MAX  10

struct lnode{
        int  data;
        struct  lnode  *next;
} *head,  *visit;

//добавляем новый узел в связный список
void llist_add(struct lnode  **q,  int num);

//выборочная сортировка списка
void  llist_selection_sort(void);
void llist_sort();


//выводим связный список
void llist_print(void);

int main(void){
    setlocale(LC_ALL, "Russian");
//связный список
    struct lnode  *newnode = NULL;
    int  i = 0;  //общий счетчик

//добавляем в список случайные данные
    for(int i =0 ;  i<MAX; i++)
    {
        llist_add(&newnode, (rand() % 100));
    }
    head = newnode;
    cout<< "before sort: \n";
    llist_print();
    cout<< "after: \n";
    //llist_selection_sort();
    //llist_print();
    llist_sort();
    return 0;
}

//добавляем узел в список связного списка
void  llist_add(struct  lnode  **q,  int num)
{
    struct  lnode  *temp;
    temp = *q;
    //если список пуст, создаем  первый элемент
    if( *q == NULL  )
    {
        *q = static_cast<lnode *>(malloc(sizeof(struct lnode)));
        temp = *q;
    } else
    {
        //переходим к последнему узлу
        while(temp-> next  !=  NULL)
        temp = temp->next;
        //добавляем узел в конец списка
        temp->next = static_cast<lnode *>(malloc(sizeof(struct lnode)));
        temp = temp->next;
    }
    //назначаем данные последнему узлу
    temp -> data = num;
    temp -> next = NULL;
}
//выводим связный список



void llist_print(void) {
    visit = head;
    //проходимся по списку и выводим его
    while (visit != NULL) {
        cout << visit->data << " ";
        visit = visit->next;
    }
    cout << endl;
}
//Сортировка выбором с выводом
void llist_sort(){
    visit = head;
    struct lnode*a = NULL;
    a = head;
    vector<int> mp(100,0);
    while(true) {
        a = head;
        int mins = INT16_MAX;
        while (a->next != NULL) {
            //cout<<a->data<<mp[a->data]<<endl;
            if(mp[a->data] != 1)
             mins = min(mins,a->data);
            a = a->next;
            //cout<<a->data<<" "<<mp[a->data]<<"   ";
        }
        //cout<<endl;
        if(mp[a->data] != 1)
            mins = min(mins,a->data);
        mp[mins] = 1;
        //visit->data = mins;
        cout<<mins<<" ";
        if(visit->next == NULL)
            break;
        else
        visit = visit->next;
    }
}
//функция сортировки выбором
void  llist_selection_sort(void) {              //Почему-то не работало, попробовал уже все варинты, создал свой сортировщик
    struct lnode *a = NULL;
    struct lnode *b = NULL;
    struct lnode *c = NULL;
    struct lnode *d = NULL;
    struct lnode *tmp = NULL;
    a = c = head;
    while (a->next != NULL) {
        d = b = a->next;
        while (b != NULL) {
            if (a->data > b->data) {
                //соседний связанный узел списка
                if (a->next == b) {
                    if (a == head) {
                        a->next = b->next;
                        b->next = a;
                        tmp = a;
                        a = b;
                        b = tmp;
                        head = a;
                        c = a;
                        d = b;
                        b = b->next;
                    } else {
                        a->next = b->next;
                        b->next = a;
                        c->next = a; //??
                        tmp = a;
                        a = b;
                        b = tmp;
                        d = b;
                        b = b->next;
                    }
                } else {
                    if (a == head) {
                        tmp = b->next;
                        b->next = a->next;
                        a->next = tmp;
                        d->next = a;
                        tmp = a;
                        a = b;
                        b = tmp;
                        d = b;
                        b = b->next;
                        head = a;
                    } else {
                        tmp = b->next;
                        b->next = a->next;
                        a->next = tmp;
                        c->next = b;
                        d->next = a;
                        tmp = a;
                        a = b;
                        b = tmp;
                        d = b;
                        b = b->next;
                    }
                } /*else{
                    D = b;
                    B = b->next;
                }*/
            }
            c = a;
            a = a->next;
        }
    }


}
