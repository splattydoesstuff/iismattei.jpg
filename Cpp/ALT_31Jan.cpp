/* ALT 2
 * Data la dimensione dell'array, riempirlo con valori a caso e stampare tutti i valori.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int n=0;
    
    while (n<=0 || n>100) {
        cout << "Quanti numeri vuoi generare? ";
        cin>>n;
        if (n<=0 || n>100) {
            cout<<"Non puoi inserire questo valore!"<<endl;
        }
    }
    
    int rNum=rand()%10;
    int array[n];

    cout<<"Ecco i "<<n<<" numeri che ho generato:"<<endl;

    for (int i=0; i<n; i++) {
        array[i]=rNum;
        cout<<array[i]<<endl;
        rNum=rand()%10;
    }
    
    return 0;
}