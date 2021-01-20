// Diego Gasteazoro 00315919
// Tarea 1 Laboratorio PED

#include <iostream> // Para cin y cout 
#include <cmath> // Para abs

using namespace std;

int GCD(int a, int b); // Funcion recursiva que calcula el maximo comun divisor (Greatest Common Divisor)

int main()
{
   int a, b = 0;
   cout << "Por favor ingrese los 2 numeros cuyo maximo comun divisor desea calcular." << endl 
        << "Los dos numeros deben ser enteros positivos, el primero debe ser mayor o igual al segundo y el primer numero no puede ser 0." << endl; // Cout con la info requerida
   cin >> a >> b; // Ingreso de datos
   a = abs(a); 
   b = abs(b); // Asegura que ambos valores sean positivos
   
   if (a>=b && a!=0) // Se asegura que los prerequisitos sean cumplidos
        cout << "El maximo comun divisor de " << a << " y " << b << " es " << GCD(a, b) << "." << endl;
   else
   {
        cout << "Por favor ingrese una pareja de numeros valida." << endl;
        return 1; 
   }
   
    return 0;
}

int GCD(int a, int b) // Funcion de maximo comun divisor que regrese dicho valor
{
    if (b==0)
        return a; // Si 'b' es igual a 0, regresa 'a' como el maximo comun divisor
    else 
        return GCD(b, a%b); // Funcion recursiva basada en el algoritmo de Euclides. Manda a llamar a la funcion y asigna el valor de 'b' a 'a' y 'a%b' (modulo) a 'b'
}


