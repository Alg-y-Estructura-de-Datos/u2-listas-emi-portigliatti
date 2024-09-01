/*
APLICACIÓN DE DOBLE ENLAZADA.
 Gestión de Historial de Navegación en un Navegador
 Desarrolla un programa que simule el historial de páginas web visitadas en un navegador
 utilizando una lista doblemente enlazada. El programa debe permitir al usuario retroceder y
 avanzar entre las páginas visitadas, mostrando sus direcciones en pantalla.
 Requisitos:
 1.
 Estructura de Datos:
 ○ Usaelconcepto de una lista doblemente enlazada para mantener el historial de
 páginas web visitadas.
 ○ Cadanododelalista debe almacenar la URL de la página web visitada.
 2. Funciones del Programa:
 ○ AñadirPágina: Permite agregar una nueva URL al final del historial de
 navegación.
 ○ Mostrar Histórico: Muestra todas las URLs del historial desde la más antigua a la
 más reciente.
 ○ Retroceder: Permite al usuario retroceder a la página web visitada
 anteriormente, mostrando la URL en pantalla.
 ○ Avanzar: Permite al usuario avanzar a la siguiente página web en el historial,
 mostrando la URL en pantalla.
 3. Interfaz del Usuario:
 ○ Lainterfaz debe ser de línea de comandos y debe permitir al usuario ingresar
 URLs y navegar a través del historial usando comandos simples.
○ Implementa un menú para aquel usuario pueda elegir entre las opciones
 disponibles: añadir una página, mostrar el historial, retroceder, avanzar, y salir
 del programa.
*/

#include <iostream>
#include <string>
#include "Lista/ListaDoble.h"
using namespace std;


void MostrarPaginaActual(ListaDoble<string> &historial,int &pos){
    
    if(pos>=0 && pos<historial.getTamanio()){
        cout << "Pagina actual: " << historial.getDato(pos) << endl;
    }else{
        cout << "No hay ninguna pagina actual" << endl;
    }
}

void Retroceder(ListaDoble<string> &historial, int &pos){
    if(pos>0){
    pos--;
    MostrarPaginaActual(historial,pos);
    }else{
        cout<<"No hay paginas anteriores en el historial"<<endl;
    }
}

void Avanzar(ListaDoble<string> &historial, int &pos){
    if(pos>=0 && pos<historial.getTamanio()-1){
    pos++;
    MostrarPaginaActual(historial,pos);
    }else{
        cout << "No hay paginas siguientes en el historial." << endl;
    }
}

void MostrarHistorial(ListaDoble<string> &historial){
    historial.imprimir();
}

void AnadirPag(ListaDoble<string> &historial, int &pos){
    string url;
    cout<<"Ingrese URL a anadir: "<<endl;
    getline(cin,url);
    historial.insertarUltimo(url);
    if(historial.getTamanio()==1){
        pos=0;
    }else{
        pos=historial.getTamanio()-1;
    }
}

int main(){
    int opcion;
    int pos=-1;
    ListaDoble<string> historial;

    do{
        cout<<"MENU: "<<endl;
        cout << "1. Anadir pagina" << endl;
        cout << "2. Mostrar Historial" << endl;
        cout << "3. Retroceder" << endl;
        cout << "4. Avanzar" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion){
            case 1:
                AnadirPag(historial,pos);
                break;
            case 2:
                MostrarHistorial(historial);
                break;
            case 3:
                Retroceder(historial,pos);
                break;
            case 4:
                Avanzar(historial,pos);
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }


        }while(opcion != 5);

}


