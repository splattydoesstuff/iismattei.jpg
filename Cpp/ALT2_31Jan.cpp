/* ALT 3
 * Data la (finta) dimensione dell'array, riempirlo con valori a caso e stampare tutti i valori.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int n=0;
    int n2=0;
    int n3=0;
    int array[100];
    
    while (n<=0 || n>100) {
        cout << "Quanti numeri vuoi generare? ";
        cin>>n;
        if (n<=0 || n>100) {
            cout<<"Non puoi inserire questo valore!"<<endl;
        }
    }
    
    int rNum=rand()%10;

    cout<<"Ecco i "<<n<<" numeri che ho generato:"<<endl;

    for (int i=0; i<n; i++) {
        array[i]=rNum;
        cout<<array[i]<<endl;
        rNum=rand()%10;
    }

    cout<<"Vuoi inserire altri numeri all'array? Se sì, scrivi un numero maggiore di 0 per indicare quanti numeri vuoi aggiungere."<<endl;
    cin>>n2;

    if (n2==0) {
        return 0;
    }
    
    while (n+n2>100) {
        cout<<"Il sistema non può gestire questo valore al momento. Inserisci un altro numero."<<endl;
        cin>>n2;
    }

    n3=n+n2;

    cout<<"Ecco il nuovo array di "<<n3<<" numeri:"<<endl;

    for (int i=n; i<n2; i++) {
        array[i]=rNum;
        rNum=rand()%10;
    }

    for (int i=0; i<n3; i++) {
        cout<<array[i]<<endl;
    }
    
    return 0;
}