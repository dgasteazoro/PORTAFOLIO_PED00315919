// Segundo Examen Parcial - PED 
// Diego Alejandro Gasteazoro Coen - 00315919
// Ciclo 03-20

#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *ant;
    nodo *sig;
};

class ListaDoble{
    private:
        nodo *pInicio;
    
    public:
        ListaDoble();
        ~ListaDoble();
        void insertarEnLista(void);
        void mostrarLista(void);
        void insertarAntesDeElemento(int, int); // Funciﾃｳn a elaborar.
        void buscarRec(int);
        bool buscarRecAux(nodo *, int); // Funciﾃｳn a elaborar.
        void sumaypromedio(void); // Funciﾃｳn a elaborar.
};

ListaDoble::ListaDoble(void)
{
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void)
{
    nodo *p;

    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertarEnLista(void)
{
    int dato, datoRef;

    cout << "Digite un entero o Ctrl-Z para terminar: ";
    while(cin >> dato){
        cout << "Digite el elemento antes del cual insertara: ";
        cin >> datoRef;
        insertarAntesDeElemento(dato, datoRef);
        cout << "Digite un entero o Ctrl-Z para terminar: ";
    }
}

// ESCRIBA AQUﾃ・LA FUNCIﾃ哲 DE INSERTAR NODOS ANTES DE UN ELEMENTO DETERMINADO:
void ListaDoble::insertarAntesDeElemento(int dato, int datoRef)
{
     nodo *nuevo = new nodo;
     nuevo->dato = dato; // nuevo nodo en el cual insertamos el dato ingresado por el usuario
     
     if (!pInicio) { // Si no hay lista
         pInicio = nuevo; // nuevo es el 1er nodo
         nuevo->sig = NULL; // no hay nodo siguiente
         nuevo->ant = NULL; // no hay nodo anterior
     }
     else if (pInicio->dato == datoRef) { // Si es el 1er elemento de la lista
         nuevo->sig = pInicio; // nuevo->sig apunta a pInicio
         nuevo->ant = NULL; // nuevo es el 1er elemento, asi que no hay nodo anterior
         pInicio->ant = nuevo; // el nodo anterior a pInicio es nuevo
         pInicio = nuevo; // nuevo es definido como el comienzo de la lista
     }
     else { // Si esta adentro o al final de la lista 
         nodo *p = pInicio;
         
         while (p->sig && p->sig->dato != datoRef) // Si p->sig no apunta a nulo y el dato de p->sig no es el valor de referencia
            p = p->sig; // Siguiente nodo
            
        nuevo->ant = p; // El nodo antes de nuevo es p
        nuevo->sig = p->sig; // El nodo despues de nuevo es el nodo que originalmente iba despues de p
        if (p->sig) p->sig->ant = nuevo; // Si hay un nodo despues de p, el nodo antes de el es el nuevo nodo
        p->sig = nuevo; // El nodo despues de p es el nuevo nodo
     } 
}

void ListaDoble::mostrarLista(void)
{
    nodo *p;
    cout << "Los elementos de la lista son:" << endl;
    p = pInicio;
    while(p->sig){
        cout << p->dato << endl;
        p = p->sig;
    }
    while(p->ant){
        cout << p->dato << endl;
        p = p->ant;
    }
    cout << "Fin de mostrar lista" << endl;
}

void ListaDoble::buscarRec(int datoB)
{
    if(buscarRecAux(pInicio, datoB))
        cout << "Si lo encontre" << endl;
    else
        cout << "No lo encontre" << endl;
}

// ESCRIBA AQUﾃ・LA FUNCIﾃ哲 DE Bﾃ售QUEDA RECURSIVA:
bool ListaDoble::buscarRecAux(nodo* pInicio, int datoB) 
{
    if (pInicio == NULL) // Si no hay lista o el puntero recorrio toda la lista y no encontro nada
        return false;
    else if (pInicio->dato == datoB) // Si el dato es encontrado
        return true;
    else
        return buscarRecAux(pInicio->sig, datoB); // La recursion 
}


// ESCRIBA AQUﾃ・LA FUNCIﾃ哲 QUE CALCULA LA SUMA Y EL PROMEDIO:
void ListaDoble::sumaypromedio() {
    float suma = 0, contador = 0;
    nodo *p = pInicio;
    
    while(p) { // Recorre la lista hasta que p apunte a NULL
        suma += p->dato; // suma = suma + p->dato
        contador++;
        p = p->sig;
    }
    
    float promedio = suma/contador;
    
    cout << "La suma es " << suma << " y el promedio es " << promedio << "." << endl;
}


int main(void)
{
    ListaDoble objListaDoble;

    cout << endl;
    cout << "PROGRAMA DEL SEGUNDO EXAMEN PARCIAL" << endl << endl;

    cout << "Insercion de datos en la lista:" << endl;
    objListaDoble.insertarEnLista();

    objListaDoble.mostrarLista();

    cin.clear();
    int datoB;
    cout << "Que dato desea buscar? ";
    cin >> datoB;
    objListaDoble.buscarRec(datoB);

    objListaDoble.sumaypromedio();
    
    cout << endl;
    return 0;
}
