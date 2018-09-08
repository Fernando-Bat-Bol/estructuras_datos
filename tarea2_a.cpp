/*implementacion de las 4 operaciones CRUD crear, obtener, modificar y borrar dentro de una lista doblemente enlazada*/

#include <iostream>
#include <string>
#include<stdlib>
using namespace std;

struct Libro{
    string titulo;
    int anioDePublicacion;
    struct Libro *next;
    struct Libro *previous;
    int posicion;
};
void crear(struct Libro **lista, string titulo, int anio)
{
    struct Libro *libroNue = new Libro;
    struct Libro *ultimo = *lista;
    int pos = 1;
    libroNue->titulo = titulo;
    libroNue->anioDePublicacion=anio;
    libroNue->next=NULL;
    if(*lista == NULL)
    {
        libroNue->previous = NULL;
        libroNue->posicion=pos;
        *lista = libroNue;
        return;
    }
    while(ultimo->next != NULL)
    {
        ultimo = ultimo->next;
        pos++;
    }
    pos++;
    ultimo->next = libroNue;
    libroNue->posicion = pos;
    libroNue->previous = ultimo;
}
void modificarAnio(struct Libro *referencia, int anio, int pos)
{
    struct Libro *libro = referencia;
    while(libro != NULL)
    {
        if(libro->posicion == pos)
        {
            libro->anioDePublicacion=anio;
            return;
        }
        libro=libro->next;
    }
    cout<<"libro no encontrado"<<endl;
    return;
}
void modificarNombre(struct Libro *referencia, string titulo, int pos)
{
    struct Libro *libro = referencia;
    do
    {
        if(libro->posicion = pos)
        {
            libro->titulo=titulo;
            return;
        }
        libro=libro->next;
    }while (libro != NULL);
    cout<<"Libro no encontrado"<<endl;
    return;
}
void borrar(struct Libro **referencia, int posicion)
{
    struct Libro *aux = *referencia;
    struct Libro *prev;

    while(aux != NULL && aux->posicion != posicion)
    {
        if (aux!=NULL && aux->posicion == 1)
        {
            *referencia = aux->next;
            aux->previous = NULL;
            free(aux);
            return;
        }
        else
        prev = aux;
        aux = aux->next;
    }
    if(aux == NULL)
    {
        cout<<"no existe esa posicion"<<endl;
        return;
    }

    prev->next = aux->next;
    prev->previous = aux->previous;
    free(aux);
}
Libro *obtener(struct Libro *referencia, int pos)
{
    struct Libro *libro = referencia;
    struct Libro *aux = NULL;
    while (libro != NULL)
    {
        if(libro->posicion == pos)
            return libro;
        libro=libro->next;
    }
    return aux;
}

int main()
{
    struct Libro *libros = NULL;
    crear(&libros, "El lenguaje de programacion C", 1978);
    crear(&libros, "Un libro bonito", 2018);
    crear(&libros, "Momo", 1987);
    crear(&libros, "La niebla", 1983);
    struct Libro *libroBuscado = obtener(libros, 4);
    cout<<libroBuscado->titulo<<" "<<libroBuscado->anioDePublicacion<<endl;
    borrar(&libros, 4);
    modificarNombre(libros, "El ejemplo", 4);
    modificarAnio(libros, 1740, 4);
    crear(&libros, "El otro ejemplo", 2018);
    modificarAnio(libros, 2017, 4);
    struct Libro *libroBuscado2 = obtener(libros, 4);
    cout<<libroBuscado2->titulo<<" "<<libroBuscado2->anioDePublicacion<<endl;
}
