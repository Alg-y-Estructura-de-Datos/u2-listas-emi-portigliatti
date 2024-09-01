/*Implementar una función llamada “printLista” que reciba una lista y una posición “p” e
imprima los elementos de esa lista a partir de la posición “p”. No debe modificarse la lista
original. Ej: listaOriginal: 1->2->3->4->5->6->7->8->9->10 con p=5 Por pantalla se verá:
6->7->8->9->10
*/



#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void PrintLista(Lista<int> lista, int p){
    int tamanio=lista.getTamanio();

    if(p>=tamanio || p<0){
        cout<<"La posicion ingresada esta fuera de los rangos de la lista."<<endl;
        return;
    }

    for (int i = p; i < tamanio; i++)
    {
        cout<<lista.getDato(i)<<"->";
    }
    cout<<"NULL"<<endl;
}

int main(){
    Lista<int> Lista1;
    int n,d,p;

    cout<<"Ingrese el tamanio de la lista: "<<endl;
    cin>>n;
    
    for (int i = 0; i < n; i++)
    {
        cout<<"Ingrese el valor de la lista en la posicion "<<i+1<<": "<<endl;
        cin>>d;
        Lista1.insertarUltimo(d);
    }

    cout<<"Ingrese la posicion desde la cual desea imprimir la lista: "<<endl;
    cin>>p;

    PrintLista(Lista1,p);
    
}