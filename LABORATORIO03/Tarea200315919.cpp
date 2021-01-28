// Diego Gasteazoro 00315919
// Tarea 2 Laboratorio PED

#include <iostream>
#include <string>

using namespace std;

struct student { // Struct con el tipo de variable student
    string name;
    int ID, year;
    float socialHours;
};

struct node { // Nodos de la lista
    student data;
    node* next;
};

class List {
private: // Nodos de pila y cola
    node* pStack, * pQueue;

public: // Funciones de la lista
    List(); // Constructor
    ~List(); // Destructor
    void stackData(); // Los datos de la pila son ingresados
    void queueData(); // Los datos de la cola son ingresados
    void insertStackStart(student data); // Se inserta al principio de la pila
    void insertQueueStart(student data); // Se inserta al principio de la cola
    void searchID(int ID); // Busca un carnet en la lista y despliega su info
    void displayLists(); // Despliega la lista seleccionada
};

List::List() { // Inicializa los punteros en NULL
    pStack = NULL;
    pQueue = NULL;
}

List::~List() { // Destruye las listas
    node* s;
    node* q;

    while (s) {
        s = pStack;
        pStack = pStack->next;
        delete s;
    }

    while (q) {
        q = pQueue;
        pQueue = pQueue->next;
        delete q;
    }
}

void List::stackData() { // La pila
    student st; // Datos de estudiantes a ingresar
    int input = 0; // Controla el do-while 

    cout << "Ingrese los datos de los estudiantes inscritos a la materia." << endl;

    do { // Corre por lo menos una vez
        cout << "Nombre completo: "; getline(cin, st.name);
        cout << "Carnet: "; cin >> st.ID;
        cout << "Anio universitario (1-5): "; cin >> st.year;
        while (st.year < 1 || st.year > 5) { // Verifica que el anio sea valido
            cout << endl << "Por favor ingrese un anio entre 1 a 5"; cin >> st.year;
        }
        cout << "Horas sociales: "; cin >> st.socialHours;

        insertStackStart(st); // Lo ingresa el comienzo de la pila

        cout << "Si desea no ingresar mas datos, oprima '0' "; cin >> input;
        
        cin.clear(); cin.ignore(1000, '\n');
    } while (input != 0); // Si input es 0, ya no se ingresan mas datos
}

void List::queueData() { // La cola
    student st; // Datos de estudiantes a ingresar
    int input = 0; // Controla el do-while 

    cout << "Ingrese los datos de los estudiantes que atendieron a la materia." << endl;

    do { // Corre por lo menos una vez
        cout << "Nombre completo: "; getline(cin, st.name);
        cout << "Carnet: "; cin >> st.ID;
        cout << "Anio universitario (1-5): "; cin >> st.year;
        while (st.year < 1 || st.year > 5) { // Verifica que el anio sea valido
            cout << endl << "Por favor ingrese un anio entre 1 a 5"; cin >> st.year;
        }
        cout << "Horas sociales: "; cin >> st.socialHours;

        insertQueueStart(st); // Lo ingresa el comienzo de la pila

        cout << "Si desea no ingresar mas datos, oprima '0' "; cin >> input;
        
        cin.clear(); cin.ignore(1000, '\n');
    } while (input != 0); // Si input es 0, ya no se ingresan mas datos
}

void List::insertStackStart(student data) { // Ingresa el nodo al comienzo de la pila
    node* n = new node;
    n->data = data;
    n->next = pStack;
    pStack = n; // Primer nodo de la lista
}

void List::insertQueueStart(student data) { // Ingresa el nodo al comienzo de la cola
    node* n = new node;
    n->data = data;
    n->next = NULL; // Ultimo nodo de la lista

    if (!pQueue) // Si no hay una lista, lo ingresa como el primer nodo 
        pQueue = n;
    else {
        node* aux = pQueue; // Inicializa un nodo auxilliar al comienzo de la cola

        while (aux->next) // Mientras aux->next no apunte a NULL
            aux = aux->next; // El aux llega hasta el final de la lista

        aux->next = n; // Inserta el nuevo nodo al final de la lista 
    }
}

 void List::searchID(int ID) {
        node* aux = pStack;

        while (aux && aux->data.ID != ID)
            aux = aux->next;

        if (aux->data.ID == ID) {
            cout << "Nombre: " << aux->data.name << endl;
            cout << "Anio Universitario: " << aux->data.year << endl;
            cout << "Horas sociales: " << aux->data.socialHours << endl << endl;
        }
        else
            cout << "No hay ningun estudiante con el carnet " << ID << ".";
    }

    void List::displayLists() { // Despliega la lista de inscripcion o atendencia dependiendo del usuario
        int choice = 0;
        node* s = pStack;
        node* q = pQueue;

        cout << "Que lista desea ver?" << endl;
        cout << "1. Estudiantes inscritos" << endl;
        cout << "2. Estudiantes en atendencia" << endl;
        cout << "0. Salir" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            while (s) {
                cout << "Nombre: " << s->data.name << endl;
                cout << "Carnet: " << s->data.ID << endl;
                cout << "Anio Universitario: " << s->data.year << endl;
                cout << "Horas sociales: " << s->data.socialHours << endl << endl;

                s = s->next;
            };
            break;
        case 2:
            while (q) {
                cout << "Nombre: " << q->data.name << endl;
                cout << "Carnet: " << q->data.ID << endl;
                cout << "Anio Universitario: " << q->data.year << endl;
                cout << "Horas sociales: " << q->data.socialHours << endl << endl;

                q = q->next;
            };
            break;
        default:
            break;
        }
    }

    int main()
    {
        List students;

        int choice = 0, ID = 0;

        do {
            cout << "Por favor seleccione lo que desea hacer" << endl;
            cout << "1. Ingresar alumnos inscritos" << endl;
            cout << "2. Ingresar alumnos por orden de asistencia" << endl;
            cout << "3. Buscar alumno inscrito por numero de carnet" << endl;
            cout << "4. Despliegar lista de alumnos" << endl;
            cout << "0. Salir" << endl;
            cin >> choice;

            cin.clear(), cin.ignore(1000, '\n');

            switch (choice) {
            case 1:
                students.stackData();
                break;
            case 2:
                students.queueData();
                break;
            case 3:
                cout << "Ingrese el carnet que desea buscar: "; cin >> ID;
                students.searchID(ID);
                break;
            case 4:
                students.displayLists();
                break;
            default:
                break;
            }
        } while (choice != 0);

        return 0;
    }