#include <iostream>
#include <chrono>
#include <random>
#include <functional>
#include "btree.hpp"
using namespace std;

int main()
{
BTree<int> MyArbol;

default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> distribution (0, 100000);
auto randomInt = bind(distribution, generator);

int myEntero, Cvalores(0);
cout << "Generacion de numeros aleatorios del 0 al 100000..." << endl;

cout<< "Digita la cantidad de valores a generar" <<endl;
cin>>Cvalores;


cout<< "Generando e ingresando valores al arbol..."<<endl;
for(int i=0; i<=Cvalores; i++){
    myEntero = randomInt();
    MyArbol.insertData(myEntero);
    cout<<i<<": Dato ingresado: "<<myEntero<<endl;
    }
cout <<endl<<endl<< Cvalores << " valores ingresados al arbol." <<endl;
system("pause"); system("cls");

cout<< "Muestreo de los valores en PreOrder: " <<endl;
MyArbol.parsePreOrder();
system("pause"); system("cls");

cout<< "Muestreo de los valores en InOrder: " <<endl;
MyArbol.parseInOrder();
system("pause"); system("cls");

cout<< "Muestreo de los valores en PostOrder: " <<endl;
MyArbol.parsePostOrder();
system("pause"); system("cls");

cout <<"El elemento menor del arbol es: "<< MyArbol.retrieve(MyArbol.getLowest())<<endl<<endl;
cout <<"El elemento menor del arbol es: "<< MyArbol.retrieve(MyArbol.getHighest())<<endl;

cout <<"La altura correspondiente al subarbol izquierdo respecto de la raiz es: "<<MyArbol.getHeight(MyArbol.getRoot()->getLeft())<<endl;
cout <<"La altura correspondiente al subarbol derecho respecto de la raiz es: "<<MyArbol.getHeight(MyArbol.getRoot()->getRight())<<endl;

MyArbol.deleteAll();

cout<< "Eliminando todo el contenido del arbol..." <<endl;
system("pause"); system("cls");
if(MyArbol.isEmpty()){
    cout<<"El arbol se encuentra vacia..."<<endl;
    system("pause"); system("cls");
    }

return 0;
}


