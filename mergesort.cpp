#include <iostream>
#define T 10

using namespace std;

void merge(int arr[], int izq, int puntoMedio, int der){
    cout<<izq<<"\t"<<puntoMedio<<"\t"<<der<<endl;
    int n1 = puntoMedio-izq;
    int n2 = der-puntoMedio;
    int temp1[n1];
    int temp2[n2];
    int i;
    cout<<"Estos son los n's "<<n1<<"\t"<<n2;
    for(i=1;i<=n1;i++){
        temp1[i-1] = arr[izq+i-1];
        //cout<<temp1<<" ";
    }
    cout<<endl;
    for(i=1;i<=n2;i++){
        temp2[i-1] = arr[puntoMedio+i];
        //cout<<temp2[i]<<" ";
    }
    cout<<endl;
    int j=0;
    i=0;
    for(int k=izq;k<der;k++ ){
        if(temp1[i]<=temp2[j]){
            arr[k]=temp1[i];
            //cout<<k<<" "<<temp1[i]<<endl;
            i++;
        }
        else{
            arr[k]=temp2[j];
            //cout<<k<<" "<<temp2[j]<<endl;
            j++;
        }

    }


}
void mergesort(int arr[], int izq, int der){
    if(izq<der){
        int puntoMedio = (der+izq)/2;
        mergesort(arr, izq, puntoMedio);
        mergesort(arr, puntoMedio+1, der);
        merge(arr, izq, puntoMedio, der);
    }
}

int main()
{
    int arreglo[T] = {4, 7, 1, 9, 3, 5, 10, 5, 9, 1};
    int inicio=0;

    mergesort(arreglo, inicio, T);
    int i=0;
    for(i=0; i<T; i++){
        cout<<arreglo[i]<<endl;
    }
    return 0;
}
