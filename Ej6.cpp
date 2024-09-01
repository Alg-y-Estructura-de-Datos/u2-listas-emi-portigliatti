/*
Crea un programa que gestione una lista circular
de contactos. Cada contacto contiene un nombre (cadena de caracteres)
y un número de teléfono (cadena de caracteres).

Tareas
1. Agregar Contactos:
○ Usa los métodos de CircList para agregar varios contactos a la lista. Deberás
insertar al menos cinco contactos con nombres y números de teléfono distintos.

2. Mostrar Contactos:
○ Implementa una función que recorra la lista circular y muestre todos los
contactos en orden. Usa el método imprimir() de CircList.

3. Buscar un Contacto por Nombre:
○ Implementa una función que busque un contacto por su nombre. Usa el método
getDato(int pos) para acceder a los datos de los nodos y busca el
contacto en la lista.

4. Eliminar un Contacto por Nombre:
○ Implementa una función que elimine un contacto por su nombre. Deberás usar
los métodos getDato(int pos) y eliminarPorValor(T valor) (supón
que eliminarPorValor está implementado, aunque no esté explícito en el
código proporcionado).

5. Contar Contactos:
○ Usa el método getTamanio() para contar el número de contactos en la lista y
muestra el resultado.
*/

#include <iostream>
#include "Lista/CircList.h"
#include <string>

using namespace std;

class Contacto {
public:
    string nombre;
    string telefono;

    Contacto() : nombre(""), telefono("") {}
    Contacto(const string &n, const string &t) : nombre(n), telefono(t) {}

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream &os, const Contacto &c) {
        os << "Nombre: " << c.nombre << ", Telefono: " << c.telefono;
        return os;
    }

    bool operator==(const Contacto& other) const {
        return nombre == other.nombre;
    }
};

void mostrarContactos( CircList<Contacto> &lista) {
    if (lista.esVacia()) {
        cout << "La lista de contactos está vacía." << endl;
        return;
    }
    lista.imprimir();
}


bool buscarContacto(CircList<Contacto> &lista, string &nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; i++) {
        Contacto c = lista.getDato(i);
        if (c.nombre == nombre) {
            cout << "Contacto encontrado: " << c << endl;
            return true;
        }
    }
    cout << "Contacto no encontrado." << endl;
    return false;
}

void eliminarContacto(CircList<Contacto> &lista, string &nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; i++) {
        Contacto c = lista.getDato(i);
        if (c.nombre == nombre) {
            // Suponiendo que implementarás eliminarPorValor en CircList
            lista.eliminarPorValor(c);
            cout << "Contacto eliminado: " << c << endl;
            return;
        }
    }
    cout << "Contacto no encontrado para eliminar." << endl;
}

int main() {
    CircList<Contacto> lista;

    lista.insertarUltimo(Contacto("Emilia", "248248"));
    lista.insertarUltimo(Contacto("Thomas", "210901"));
    lista.insertarUltimo(Contacto("Candelaria", "123456"));
    lista.insertarUltimo(Contacto("Sofia", "362514"));

    cout << "Lista de contactos:" << endl;
    mostrarContactos(lista);
    cout<<"-------------------------------------------------------"<<endl;

    // Buscar contacto existente
    string nombreABuscar = "Sofia";
    cout << "Buscando contacto con nombre " << nombreABuscar << ":" << endl;
    buscarContacto(lista, nombreABuscar);
    cout<<"-------------------------------------------------------"<<endl;

    // Buscar contacto no existente
    nombreABuscar = "Juan";
    cout << "Buscando contacto con nombre " << nombreABuscar << ":" << endl;
    buscarContacto(lista, nombreABuscar);
    cout<<"-------------------------------------------------------"<<endl;


    // Eliminar contacto existente
    string nombreAEliminar = "Candelaria";
    cout << "Eliminando contacto con nombre " << nombreAEliminar << ":" << endl;
    eliminarContacto(lista, nombreAEliminar);
    cout<<"-------------------------------------------------------"<<endl;

    // Eliminar contacto no existente
    nombreAEliminar = "Eduardo";
    cout << "Eliminando contacto con nombre " << nombreAEliminar << ":" << endl;
    eliminarContacto(lista, nombreAEliminar);
    cout<<"-------------------------------------------------------"<<endl;

    // Mostrar contactos después de eliminar
    cout << "Lista de contactos despues de la eliminacion:" << endl;
    mostrarContactos(lista);
    cout<<"-------------------------------------------------------"<<endl;

    // Contar contactos
    cout << "Numero de contactos en la lista: " << lista.getTamanio() << endl;
    cout<<"-------------------------------------------------------"<<endl;

}