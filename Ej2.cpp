/*
Implementar una función que recibe una lista de números enteros y un número entero “n” y
que modifique la lista borrando todos los elementos de la lista que tengan el número “n”.
Imprimir la lista antes de hacer el llamado a la función y luego del llamado a la función para
mostrar que la lista original cambió. ej: lista: 1->2->3->4->5->3->7->8->3->10 con n=3 debe
pasar con la función a 1->2->4->5->7->8.

*/

#include <iostream>
#include "Lista/Lista.h"
using namespace std;


void BorrarElemento(Lista<int>& lista, int n){
    int i=0;

    while (i<lista.getTamanio())
    {
        if(lista.getDato(i)==n){
            lista.remover(i);
        }else{
            i++;
        }
    }
}

int main() {

    Lista<int> Lista1;
    int n,d,t;

    cout<<"Ingrese el tamanio de la lista: "<<endl;
    cin>>t;

    for (int i = 0; i < t; i++)
    {
        cout<<"Ingrese el valor de la lista en la posicion "<<i+1<<":"<<endl;
        cin>>d;
        Lista1.insertarUltimo(d);
    }

    cout<<"Lista original: "<<endl;
    Lista1.print();

    cout<<"Ingrese el numero que desea eliminar: "<<endl;
    cin>>n;

    BorrarElemento(Lista1,n);

    cout<<"Lista modificada: "<<endl;
    Lista1.print();
    
    
    
}
