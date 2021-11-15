#include <iostream>
using namespace std;
typedef int Type;
struct Node {
    Type elem; //данные
    Node* next; //указатель на следующий узел
    Node* prev; //указатель на предыдущий
};

class LIST {
    Node* head;
    Node* tail;
public:
    int index;
    LIST();
    void addFirst(Type elem);
    void addLast(Type elem);
    void addAfter(Type elemwh, Type elemin);
    void mergeAfter(Type elemwh, const LIST& it);
    void delTail();
    void delHead();
    void delElem(Type elemwh);
    void sortingList();
    void count();
    void unique();
    int search_el(Type elem);
    Type search_in(int in);
    Node* search_uk(Type elem);
    void swap(int& a, int& b);
    void showList() const;
  
};

LIST::LIST() {
    head = tail = NULL;
    index=0;
}

void LIST::count() 
{
    if (head) {
        Node* buf = head;
        while (buf) {
            index++;
            buf = buf->next;
        }
    }
}

Node* LIST::search_uk(Type elem) {
    int i = 0;
    if (head) {
        Node* buf = head;
        while (buf) {
            if (buf->elem == elem)return buf;
            buf = buf->next;
            i++;
        }
    }
}

Type LIST::search_in(int in) { 
    int i = 0;
    if (head) {
        Node* buf = head;
        while (buf) {
            if (i==in) return buf->elem;
            buf = buf->next;
            i++;
        }
    }
    return NULL;
}

int LIST::search_el(Type elem) {
    int i = 0;
    if (head) {
        Node* buf = head;
        while (buf) {
            if (buf->elem == elem)return i;
            i++;
            buf = buf->next;
        }
    }
    i = NULL;
    return i;
}
//Добавление узла в начало
void LIST::addFirst(Type elem) {
    Node* buf = new Node;
    buf->elem = elem;
    if (!head) {
        buf->next = tail;
        tail = buf;
    }
    else {
        buf->next = head;
        head->prev = buf;
    }
    head = buf;
    head->prev = NULL;

}

//Добавление узла в конец
void LIST::addLast(Type elem) {
    Node* buf = new Node;
    buf->elem = elem;
    if (!head) {
        buf->next = tail;
        head = buf;
        buf->prev = NULL;
    }
    else {
        buf->next = tail->next;
        buf->prev = tail;
        tail->next = buf;
    }
    tail = buf;
}
void LIST::addAfter(Type elemwh,Type elemin) {
    Node* bufwh = new Node;
    bufwh=search_uk(elemwh);//находит то, где лежит элемент после которого вставить
    Node* bufin = new Node;

        bufin->elem = elemin;
        bufin->next = bufwh->next;
        bufwh->next = bufin;
        bufin->prev = bufwh;

}

void LIST::mergeAfter(Type elemwh, const LIST& it ) {
    Node* bufwh = new Node;
    bufwh = search_uk(elemwh);//находит то, где лежит элемент после которого вставить

    if (it.head) {
        Node* buf = it.head;
        while (buf) {
            addAfter(elemwh, buf->elem);
            buf = buf->next;
        }
    }
}

//Пройти по списку и вывести все элементы
void LIST::showList() const {
    if (head) {
        Node* buf = head;
        while (buf) {
            cout << buf->elem << " ";
            buf = buf->next;
        }
        cout << endl;
    }
    else cout << "List is empty " << endl;
}

//Удаление головы
void LIST::delHead() {
    if (head) {
        Node* buf = head;
        head = head->next;
        head->prev = NULL;
        delete buf;
    }
    else cout << "List is empty" << endl;
}

//Удаление хвоста
void LIST::delTail() {
    if (tail) {
        Node* buf = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete buf;
    }
    else cout << "List is empty" << endl;
}
void LIST::delElem(Type elemwh) {
    Node* bufwh = new Node;
    bufwh = search_uk(elemwh);
    if (bufwh==head) {
        Node* buf = head;
        head = head->next;
        head->prev = NULL;
        delete buf;
    }
    
    else if (bufwh == tail) {
        Node* buf = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete buf;
    }
    
    else if (bufwh) 
    {
        Node* bufprev = bufwh->prev;
        Node* bufnext = bufwh->next;
        bufprev->next = bufnext;
        bufnext->prev = bufprev;
       
    }
    delete bufwh;
}
//Обмен данных списка
void LIST::swap(int& a, int& b) {
    int buf = a;
    a = b;
    b = buf;
}

//Сортировка
void LIST::sortingList() {
    Node* buf = head;
    for (Node* i = buf; i; i = i->next) {
        for (Node* j = i->next; j; j = j->next) {
            if (i->elem < j->elem) {
                swap(i->elem, j->elem);
            }
        }
    }

}

void LIST::unique() {

    if (head) {
        Node* buf = head;
        Type tmp = buf->elem;
        int i = index;
        while (i > 0) {
            while (buf) {

                buf = buf->next;
            }
            i--;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "RUS");
    

    LIST mylist;
    int a_i;
    cout << "Enter elements" << endl;
    while (1) {
        cin >> a_i;
        if (a_i) {
            mylist.addFirst(a_i);
        }
        else break;
    }
    mylist.sortingList();
    mylist.count();
    cout << mylist.index << endl;
    cout << "Элемент 5 находится по индексу:";
    cout << mylist.search_el(5) << endl;
    cout << "Элемент по номеру 3 это:";
    cout << mylist.search_in(3) << endl;
    cout << "Найти элемент 5 и вернуть указатель:";
    cout << mylist.search_uk(5)->elem<<endl;

    mylist.showList();
   mylist.addAfter(4, 100);
   mylist.addAfter(5, 100);

    mylist.showList();
    //______________________________________--
    LIST mylist2;
    int i=0;
    while (i < 5) {
        mylist2.addFirst(i);
        i++;
    }
    mylist.mergeAfter(1, mylist2);
    cout << "list после суммы с другим list : "<< endl;
    mylist.showList();
    //_______________________
    mylist.delElem(0);
    cout << "list после удаление элемента 1 : " << endl;
    mylist.showList();

    cout << "Hello World!" << endl;
    return 0;
}