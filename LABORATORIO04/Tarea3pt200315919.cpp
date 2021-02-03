// Diego Gasteazoro 00315919
// Tarea 3 parte 2 Laboratorio PED

#include <iostream>

using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

class DLList {
private:
    node* pHead;

public:
    DLList();
    ~DLList();
    void listData();
    void insertListStart(int);
    bool deletePrevNode(int);
    void displayList();


};

DLList::DLList()
{
    pHead = NULL;
}

DLList::~DLList()
{
    node* p;

    while (pHead) {
        p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

void DLList::listData() { // La pila
    int n = 0; // Numero

    cout << "Digite un entero. Si desea no ingresar mas datos, oprima 'CTRL-Z'" << endl;
    while (cin >> n) { // Mientras se agreguen numeros
        insertListStart(n); // Lo ingresa el comienzo de la lista
        cout << "Digite un entero. Si desea no ingresar mas datos, oprima 'CTRL-Z'" << endl;
    }
}

void DLList::insertListStart(int data) { // Ingresa el nodo al comienzo de la lista
    node* n = new node;
    n->data = data;
    if (!pHead) { // Si no hay nodos
        pHead = n;
        n->next = NULL;
        n->prev = NULL;
    }
    else {
        n->next = pHead;
        n->prev = NULL;
        pHead->prev = n;
        pHead = n; // Primer nodo de la lista
    }
}

bool DLList::deletePrevNode(int ref) { // Borra el nodo anterior al valor
    if (!pHead) {
        return false; // no hay lista, regresa falso
    }
    else {
        node* p = pHead;
        node* d; // nodos ha ocupar
            
        while (p->next && p->next->data != ref) // mientra haya un siguiente nodo y ese nodo no tenga el valor de ref
                p = p->next;
        if (!p->next) { // Si ya no hay lista que recorrer
            return false;
        }
        else {
            if (p == pHead) pHead = p->next; // Si p es el 1er nodo, se mueve el inicio de la lista al 2do nodo
            if (p->prev) p->prev->next = p->next; // Si hay un valor antes del nodo p (esto se usa si p es el 1er nodo), el nodo anterior apunta al nodo despues de p
            p->next->prev = p->prev; // El nodo siguiente apunta al nodo antes de p
            d = p; // d es igual a p 
            p = p->next; // p es igual al siguiente nodo
            delete d; // se borra d, que era el p original
            return true; // Se ha borrado algo.
        }
    }
}

void DLList::displayList() {
    node* p = pHead;

    cout << "Los numeros en la lista son:" << endl;
    while (p) {
        cout << p->data << endl;
        p = p->next;
    }
    cout << "Fin de la lista." << endl << endl;
}

int main()
{
    DLList numbers;

    numbers.listData();
    cin.clear();

    numbers.displayList();

    int ref;

    cout << "Digite el valor del dato cuyo nodo anterior desea borrar: "; cin >> ref;
    if (numbers.deletePrevNode(ref)) {
        cout << "Dato previo a " << ref << " excitosamente borrado." << endl << endl;
        cout << "Nueva lista:" << endl;
    }
    else {
        cout << "No hay ningun dato con ese valor";
        cout << "No hay cambios en la lista" << endl;
    }
    numbers.displayList();

    return 0;
}
