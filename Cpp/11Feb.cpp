/*
 * Crea un array di n numeri random compresi tra 1 e 100
 * Lo shift sempplice: Sposta tutti i numeri di una posizione verso destra.
 * L'ultimo numero cade nel vuoto (Va perso) e il primo posto va riempito con lo 0
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int n=0;
    int array[100];
    int temp[100];
    int opt=0;
    int move=0;

    cout<<"Inserisci la dimensione logica (Un numero tra 0 e 100): ";
    cin>>n;

    cout<<"Inserisci l'opzione: ";
    cin>>opt;
    
if (opt==1) {
    //start
    for (int i=0; i<n; i++) {
        array[i]=rand()%101;
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Di quanto vuoi spostare l'array? ";
    cin>>move;
    //SHIFT SEMPLICE
    for (int i=n-1; i>=move; i--) {
        array[i]=array[i-move];
    }

    for (int i=0; i<move; i++) {
        array[i]=0;
    }

    for (int i=0; i<n; i++) {
        cout<<array[i]<<" ";
    }
    //end
} else if (opt==2) {
    //ROTAZIONE
    //start
    for (int i=0; i<n; i++) {
        array[i]=rand()%101;
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Di quanto vuoi spostare l'array? ";
    cin>>move;
    //ROTAZIONE
    for (int i=0; i<move; i++) {
        temp[i]=array[n-move+i];
    }
    
    for (int i=n-1; i>=move; i--) {
        array[i]=array[i-move];
    }

    for (int i=0; i<move; i++) {
        array[i]=temp[i];
    }

    for (int i=0; i<n; i++) {
        cout<<array[i]<<" ";
    }
    //end
} else if (opt==3) {
    //CANCELLAZIONE
} else {
    cout<<"Non ho capito"<<endl;
    return 1;
}
    
    return 0;
}