/*
 * Esercitazione per la verifica
 * Dato un vettore di n elementi random 0-100, chiedi num e verifica se è presente in array e quante volte, poi crea 3 array
 * Nel primo tutti gli 0 dell'array principale
 * Nel secondo tutti i numeri>=num
 * Nel terzo tutti i numeri<num
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int array[100]={0};
    int arrayMin[100]={0};
    int arrayMax[100]={0};
    int zero[100]={0};
    int sizeMain=0;
    int sizeMin=0;
    int sizeMax=0;
    int sizeZero=0;
    int num=0;

    cout<<"Inserisci la dimensione dell'array ";
    cin>>sizeMain;

    cout<<"Inserisci un qualsiasi numero compreso tra 0 e 100: ";
    cin>>num;

    for(int i=0; i<sizeMain; i++) {
        array[i]=rand() % 101;
        
        //imposto gli array in base ai controlli
        if (array[i]==0) {
            sizeZero++;
        } else if (array[i]>=num) {
            arrayMax[sizeMax]=array[i];
            sizeMax++;
        } else {
            arrayMin[sizeMin]=array[i];
            sizeMin++;
        }
    }

    //cicli output
    cout << "Ci sono "<<sizeZero<<" zeri nel tuo array: ";
    for(int i=0; i<sizeZero; i++) {
        cout<<zero[i]<<" ";
    }
    cout<<endl;

    cout<<"Ci sono "<<sizeMax<<" numeri maggiori o uguali al numero che hai inserito: ";
    for(int i=0; i<sizeMax; i++) {
        cout<<arrayMax[i]<<" ";
    }
    cout<<endl;

    cout << "Ci sono "<<sizeMin<<" numeri minori del numero che hai inserito: ";
    for(int i=0; i<sizeMin; i++) {
        cout<<arrayMin[i]<<" ";
    }
    cout<<endl;

    return 0;
}