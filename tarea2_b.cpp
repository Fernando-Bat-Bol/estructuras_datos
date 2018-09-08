/*Problema de Flavio Josefo implementado en C++ usando listas enlazadas circulares*/

#include <iostream>
#include <string>
#include <stdlib>
using namespace std;

struct Persona
{
    string nombre;
    int posicion;
    struct Persona *siguiente;
};
struct Persona *persona_inicial(struct Persona *ultimo, string nombre)
{
    struct Persona *aux = new Persona;
    aux->nombre = nombre;
    aux->posicion=1;
    ultimo = aux;
    ultimo->siguiente = ultimo;
    return ultimo;
}
struct Persona *agregaPersonas(struct Persona *ultimo, string nombre, int posicion)
{
    struct Persona *aux = new Persona;
    aux->posicion=posicion;
    aux->nombre = nombre;
    aux->siguiente = ultimo->siguiente;
    ultimo->siguiente = aux;
    ultimo = aux;
    return aux;
}
bool borrar(struct Persona **nodos, int saltos)
{
    struct Persona *aux = *nodos;
    struct Persona *anterior;
    while(saltos)
    {
        anterior = aux;
        aux = aux->siguiente;
        saltos--;
    }
    if(anterior->posicion == aux->posicion)
    {
        cout<<anterior->nombre<<" felicidades te has salvado"<<endl;
        return false;
    }
    anterior->siguiente = aux->siguiente;
    free(aux);
    return true;
}

int main()
{
    int numDeP, saltos;
    string nombre;
    struct Persona *ultimo = NULL;
    cout<<"Ingrese el numero de personas: ";
    cin>>numDeP;
    for(int i=1; i<=numDeP; i++)
    {
        cout<<"Cual es el nombre de la persona numero "<<i<<": ";
        cin>>nombre;
        if(i==1)
            ultimo = persona_inicial(ultimo, nombre);
        else
            ultimo = agregaPersonas(ultimo, nombre, i);
    }
    cout<<"ingrese el tamanio de saltos: ";
    cin>>saltos;
    bool checa = true;
    while (checa)
    {
        checa = borrar(&ultimo, saltos);
    }
}
