/*APLICACION DE CIRCULARIDAD
 Sistema de Monitor Publicitario Circular
Desarrolla un programa para gestionar un monitor publicitario que debe mostrar frases de
 anuncios de manera circular. Para lograr esto, implementarás una solución utilizando una lista
 circular simplemente enlazada.
 Requisitos:
 1.
 Frases de Anuncios:
 ○ Cada frase deanuncio será un texto simple que el monitor debe mostrar por
 vez.
 2. Mostrar Circularmente:
 ○ Las frases deben mostrarse en un formato circular, es decir, una vez que se ha
 mostrado la última frase, el monitor debe volver a mostrar la primera y así
 infinitamente.
 3. Implementación:
 ○ Utiliza una lista circular simplemente enlazada para gestionar el almacenamiento
 y la visualización de las frases. La lista circular debe permitir el recorrido
 continuo de los elementos.
 4. Operaciones Básicas:
 ○ Agregar Frases: Capacidad para añadir nuevas frases a la lista circular.
 ○ Eliminar Frases: Capacidad para eliminar frases específicas de la lista.
 ○ MostrarFrases: Implementa una función para mostrar las frases en el monitor
 de manera continua, recorriendo circularmente la lista e infinitamente.
*/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Lista/CircList.h"
using namespace std;

void mostrarFrases(CircList<string> &frases)
{
    if(frases.esVacia())
    {
        cout << "No hay frases" << endl;
        return;
    }

    int pos=0;
    while (true)
    {
        cout << frases.getDato(pos) << endl;
        pos=(pos+1) % frases.getTamanio();

        this_thread::sleep_for(chrono::seconds(3));
    }
}

int main()
{
    CircList<string> frases;
    string frase;
    int opcion;
    do
    {
        cout << "1. Agregar frase" << endl;
        cout << "2. Eliminar frase" << endl;
        cout << "3. Mostrar frases" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
            cout << "Frase: ";
            getline(cin, frase);
            frases.insertarUltimo(frase);
            break;
        case 2:
            cout << "Frase a eliminar: ";
            getline(cin, frase);
            frases.eliminarPorValor(frase);
            break;
        case 3:
            mostrarFrases(frases);
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 4);

}


