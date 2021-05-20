#include <iostream>

using namespace std;

void printLista(int *lista,int n){
    int ii;
    for (ii = 0; ii < n; ii++) {
        cout << lista[ii] << endl;
    }
}

void swapLista(int *lista,int ii, int jj){
    int aux;
    aux = lista[ii];
    lista[ii] = lista[jj];
    lista[jj] = aux;
}

int HoarePartition(int *A, int l, int r){
    int p = A[l],ii = l,jj = r;
    do{
        do{
            ii++;
        }while(A[ii]<p);
        do{
            jj--;
        }while(A[jj]>p);
        swapLista(A,ii,jj);
    }while(!(ii>=jj));
    swapLista(A,ii,jj);
    swapLista(A,l,jj);
    return jj;
}

// algoritmo
void quickSort(int *A, int l, int r){
    int s;
    if(l<r-1){
       s = HoarePartition(A,l,r);
       quickSort(A,l,s);
       quickSort(A,s+1,r);
    }
}


int main()
{
    int lista[100] = {2,10,1,5,7,4,2};
    int tamanho_lista = 7,ii;
    quickSort(lista,0,tamanho_lista);
    printLista(lista,tamanho_lista);
    return 0;
}
