/*
Escribir un programa que pida al usuario una palabra o frase y la almacene en una Lista
separando letra por letra, luego pedirá al usuario una vocal que desee contar y, por último, se
debe imprimir por pantalla la lista y el número de veces que aparece la vocal en la palabra o
frase. Validar que la Lista no esté vacía y que la letra a contar que introduzca el usuario sea
una vocal.
*/

#include <iostream>
#include "Lista/Lista.h"
#include <cctype> 
using namespace std;


bool EsVocal(char c){
    c=tolower(c);
    return c='a'||'e'||'i'||'o'||'u';
}

int ContarVocal(Lista<char>& lista, char vocal){
    int cont=0;

    for (int i = 0; i < lista.getTamanio(); i++)
    {
        if(tolower(lista.getDato(i)==tolower(vocal))){
            cont++;
        }
    }
    return cont;
}

int main() {

Lista<char> lista;
string frase;
char vocal;

cout<<"Ingrese una frase: "<<endl;
getline(cin,frase);

for (int i = 0; i < frase.length(); i++)
{
    char c=frase[i];
    lista.insertarUltimo(c);
}

if(lista.esVacia()){
    cout<<"No hay nada para contar. LISTA VACIA"<<endl;
    return 0;
}

cout<<"Ingrese una vocal para contabilizar cuantas veces aparece en la frase: "<<endl;
cin>>vocal;

if(!EsVocal(vocal)){
    cout<<"El caracter ingresado no es una vocal."<<endl;
    return 0;
}

cout<<"Lista: "<<endl;
lista.print();

int cant=ContarVocal(lista,vocal);
cout<<"La cantidad de veces que aparece la vocal "<<vocal<<" es: "<<cant<<endl;

}


