//neoreo-dev@iismattei.jpg - Check if an array is palindrome

#include <iostream>

using namespace std;

int main() {
    int n=0;
    int temp=0;
    int notEqual=0;
    int debug=0;

    cout<<"Quanti elementi vuoi inserire nell'array? ";
    cin>>n;
    
    int array[n];

    //input cycle
    for (int i=0; i<n; i++) {
        cout<<"Inserisci il "<<i+1<<" elemento: ";
        cin>>array[i];
    }

    cout<<"Inserimento terminato!"<<endl;
    
    //verifica specchio
    for (int i=0; i<n/2; i++) {
        if (debug==1) {
            cout<<"DEBUG - Risultato n/2: "<<n/2<<endl;
            debug=0;
        }
        
        temp=array[n/2+i+1];

        if (temp==array[n/2-(i+1)] && notEqual==0) {
            //cout<<"DEBUG - Valore: "<<temp<<endl;
            //cout<<"DEBUG - Valore uguale! ("<<temp<<")"<<endl;
        } else {
            notEqual=1;
            //cout<<"DEBUG - Valore: "<<temp<<endl;
            temp=array[n/2-(i+1)];
            cout<<"Valore NON uguale trovato ("<<temp<<")"<<endl;
            break;
        }
        temp=0;
    }

    //output result
    if (notEqual==1) {
        cout<<"L'array che hai inserito NON È palindromo."<<endl;
    } else {
        cout<<"L'array che hai inserito È palindromo!"<<endl;
    }
    //if necessary, output the middle position's value
    if (n%2==1) {
        cout<<"L'array è dispari - Il valore centrale è: "<<array[n/2]<<endl;  
    }
    
    return 0;

}

