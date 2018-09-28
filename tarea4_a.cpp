#include <iostream>
#include <string>
using namespace std;
struct Nodo{
    int dato;
    Nodo *izquierda, *derecha;
};
Nodo insertar(int valor){
    Nodo nuevo;
    nuevo.dato=valor;
    nuevo.derecha=NULL;
    nuevo.izquierda=NULL;
    return nuevo;
}
Nodo* enqueue(Nodo* lista, int valor){
    Nodo temp=insertar(valor);
    if(lista == NULL){
        return &temp;
    }
    else{
        Nodo* aux;
        lista->derecha=aux;
        aux->izquierda=lista;
        return aux;
    }
}
Nodo* dequeue(Nodo* lista){
    if(lista == NULL){
        cout<<"No existe nodo que eliminar";
        return 0;
    }
    else{
        Nodo* temp=NULL;
        if(lista->izquierda!=NULL)
            temp=lista->izquierda;
        delete(lista);
        return temp;
    }
}
int Front(Nodo* lista){
    return lista->dato;
}
int Back(Nodo* lista){
    while(lista->izquierda!=NULL){
        lista=lista->izquierda;
    }
    return lista->dato;
}
bool Empty(Nodo* lista){
    if(lista==NULL)
        return 1;
    else
        return 0;
}
int Size(Nodo* lista){
    int cont=1;
    while(lista->izquierda!=NULL){
        cont++;
        lista=lista->izquierda;
    }
    return cont;
}
int main(){
    Nodo* lista=NULL;
    for(int i=5; i<=45; i+=10){
        lista=enqueue(lista, i);
    }
    lista=dequeue(lista);
    cout<<"Back = "<<Back(lista)<<endl;
    cout<<"Front = "<<Front(lista)<<endl;
    if(Empty(lista)==1)
        cout<<"La lista esta vacia"<<endl;
    else
        cout<<"La lista no esta vacia"<<endl;
    cout<<"El tamanio de la lista es de: "<<Size(lista);
}
