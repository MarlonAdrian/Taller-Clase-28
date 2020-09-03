#include <iostream>
#include <fstream>

using namespace std;

int mitad (int arr[], int pinicial, int pfinal);

void ordenar(int arr[], int pinicial, int pfinal);


int main()
{
ofstream archivo;
archivo.open("Quicksort.txt");
    int A[10]={88, -6, 69, -33, 98, 7, 23, -5, 0, 100};
    archivo << "Arreglo original: "; 
    for (int i=0; i < 10; i++){
    cout << "|" << A[i] << "|";
    archivo << "|" << A[i] << "|";
    }
    cout << endl;
    archivo << endl;
    ordenar(A,0,9);

    cout<<endl;
    archivo << "Arreglo modificado: "; 
    for(int i=0; i<10;i++)
    {
        cout<<"|"<<A[i]<<"|";
        archivo << "|" << A[i] << "|";
    }

archivo.close();
    return 0;
}



int mitad (int arr[], int pinicial,  int pfinal)
{
    return arr[(pinicial+pfinal)/2];
}


void ordenar(int arr[], int pinicial, int pfinal)
{
    int i=pinicial;
    int j=pfinal;
    int temp;
    int piv=mitad(arr,pinicial,pfinal);

    do
    {
        while(arr[i]<piv)
        {
            i++;
        }
        while(arr[j]>piv)
        {
            j--;
        }
        if(i<=j)
        {
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }

    }
    while(i<=j);

    if(pinicial<j)
        ordenar(arr,pinicial,j);
    if(i<pfinal)
        ordenar(arr,i,pfinal);
}