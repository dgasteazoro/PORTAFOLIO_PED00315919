// Diego Gasteazoro 00315919
// Tarea 3 Laboratorio PED

#include <iostream>

using namespace std;

struct node { // Nodos de la lista
    int data;
    node* next;
};

class List {
private: // Nodo de la lista
    node* pHead;

public: // Funciones de la lista
    List(); // Constructor
    ~List(); // Destructor
    void listData(); // Los datos de la lista son ingresados
    void insertListStart(int); // Se inserta al principio de la lista
    void deleteNodes(); // Borro nodos con el dato ingresado
    void displayLists(); //

};

List::List() { // Inicializa el puntero inicial en NULL
    pHead = NULL;
}

List::~List() { // Destruye las listas
    node* p;

    while (pHead) {
        p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

void List::listData() { // La pila
    int n = 0; // Numero

    cout << "Digite un entero. Si desea no ingresar mas datos, oprima 'CTRL-Z'" << endl;
    while (cin >> n) { // Mientras se agreguen numeros
        insertListStart(n); // Lo ingresa el comienzo de la lista
        cout << "Digite un entero. Si desea no ingresar mas datos, oprima 'CTRL-Z'" << endl;
    }
}

void List::insertListStart(int data) { // Ingresa el nodo al comienzo de la lista
    node* n = new node;
    n->data = data;
    n->next = pHead;
    pHead = n; // Primer nodo de la lista
}

void List::deleteNodes() { // Borra los nodos que contengan el valor de ref
    int ref = 0;
    node* p = pHead;
    node* d;

    cout << "Digite el numero que desea eliminar de la lista: "; cin >> ref;

    while (p) {
        if (pHead->data == ref) {
            pHead = pHead->next;
            d = p;
            delete d;
            p = pHead;
        }
        else {
            while (p->next && p->next->data != ref) {
                p = p->next;
            }
            if (!p->next)
                break;
            else {
                d = p;
                d = d->next;
                p->next = p->next->next;
                delete d;
            }
        }
    }
    
    cout << "Todos los datos con valor " << ref << " han sido borrados." << endl;
}


void List::displayLists() {
    int choice = 0;
    node* p;
    
    do {
        cout << "Por favor seleccione como quiere despliegar la lista:" << endl;
        cout << "1. Toda la lista" << endl;
        cout << "2. Solo pares" << endl;
        cout << "3. Solo impares" << endl;
        cout << "0. Salir" << endl;
        cin >> choice;
        
        switch (choice) {
        case 1:
            cout << "Los numeros en la lista son:" << endl;
            p = pHead;
            while (p) {
                cout << p->data << endl;
                p = p->next;
            }
            cout << "Fin de la lista" << endl << endl;
            break;
        case 2:
            cout << "Los numeros pares en la lista son:" << endl;
            p = pHead;
            while (p) {
                if ((p->data)%2 == 0) 
                    cout << p->data << endl;
                p = p->next;
            }
            cout << "Fin de la lista de pares" << endl << endl;
            break;
        case 3:
            cout << "Los numeros impares en la lista son:" << endl;
            p = pHead;
            while (p) {
                if ((p->data) % 2 != 0) 
                    cout << p->data << endl;
                p = p->next;
            }
            cout << "Fin de la lista de impares" << endl << endl;
            break;
        default:
            break;
    }

    } while (choice != 0);
}

int main()
{
    List numbers;
    int choice = 0;

    numbers.listData();
    cin.clear();

    cout << "Desea borrar algun valor de la lista?" << endl;
    cout << "1. Si" << endl;
    cout << "0. No" << endl;
    cin >> choice;
    if (choice == 1) {
        numbers.deleteNodes();
        cin.clear();
    }
    numbers.displayLists();

    return 0;
}