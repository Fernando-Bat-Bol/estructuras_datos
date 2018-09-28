#include <iostream>
#include <string>
#define DIMENSION 10
using namespace std;
int lista[DIMENSION];
int frente=0, cola=0;
int tamanio=sizeof(lista)/sizeof(*lista);
void enqueue(int valor){
    if(!lista[frente]){
        lista[frente]=valor;
        frente++;
        if(frente>(tamanio-1))
            frente=0;
    }
}
int dequeue(){
    int temp=lista[cola];
    lista[cola]=0;
    cola++;
    if(cola>(tamanio-1) && lista[0]!=0)
        cola=0;
    return temp;
}
int Back(){
    return lista[cola];
}
int Front(){
    if(frente)
        return lista[frente-1];
    return lista[tamanio-1];
}
bool Empty(){
    if(!lista[frente] && !lista[cola])
        return 1;
    return 0;
}
int Size(){
    int cont=0;
    for(int i=0; i<tamanio; i++){
        if(lista[i]!=0)
            cont++;
    }
    return cont;
}
int main(){
    for(int i=10;i<=100;i+=10)
        enqueue(i);
    cout<<"Se ha retirado "<<dequeue()<<endl;
    enqueue(15);
    cout<<"Back-> "<<Back()<<endl;
    cout<<"Front-> "<<Front()<<endl;
    Empty()?cout<<"Esta vacio"<<endl:cout<<"No esta vacio"<<endl;
    cout<<"Tamanio-> "<<Size()<<endl;
    for(int i=0;i<10;i++)
        cout<<lista[i]<<endl;
}
