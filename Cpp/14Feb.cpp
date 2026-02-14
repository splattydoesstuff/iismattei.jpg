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
    int k=0;
    int q=0;
    int temp1=0;
    int temp2=0;
    int deleteQuantity=0;
    int addQuantity=0;

    char answer;

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
    
    for (int i=0; i<n; i++) {
        array[i]=rand()%101;
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Di quanto vuoi spostare l'array? ";
    cin>>move;
    
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
    
} else if (opt==3) {
    //CANCELLAZIONE
    for (int i=0; i<n; i++) {
        array[i]=rand()%101;
        cout<<array[i]<<" ";
    }
    cout<<endl;

    cout<<"Vuoi eliminare più elementi? [Y/N] ";
    cin>>answer;
    
    if (answer=='Y') {
        cout<<"Quanti elementi vuoi eliminare? ";
        cin>>deleteQuantity;

        for (int i=0; i<deleteQuantity; i++) {
            cout<<"Inserisci la posizione del "<<i+1<<" elemento da eliminare: ";
            cin>>k;
    
            for (int i=k-1; i<=n-1; i++) {
                array[i]=array[i+1];
            }

            n--;
        }
    } else if (answer=='N') {
            cout<<"Quale elemento vuoi eliminare? ";
            cin>>k;
    
            for (int i=k-1; i<=n-1; i++) {
                array[i]=array[i+1];
            }

            n--;
    } else {
        cout<<"Non ho capito"<<endl;
        return 1;
    }
    
    for (int i=0; i<n; i++) {
          cout<<array[i]<<" ";
    }
} else if (opt==4) {
    //SWAP
    for (int i=0; i<n; i++) {
        array[i]=rand()%101;
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Quale elemento vuoi swappare?"<<endl;
    cin>>k;
    temp1=array[k-1];
    cout<<"Con quale?"<<endl;
    cin>>q;
    temp2=array[q-1];

    array[k-1]=temp2;
    array[q-1]=temp1;
    
    for (int i=0; i<n; i++) {
          cout<<array[i]<<" ";
    }
} else if (opt==5) {
    //ADD
    for (int i=0; i<n; i++) {
        array[i]=rand()%101;
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Quanti elementi vuoi aggiungere? ";
    cin>>addQuantity;

    for (int i=n; i<n+addQuantity; i++) {
        array[i]=rand()%101;
    }
    n=n+addQuantity;
    
    for (int i=0; i<n; i++) {
          cout<<array[i]<<" ";
    }
} else {
    cout<<"Non ho capito"<<endl;
    return 1;
}
    
    return 0;
}