/* Verifica 21/02/2026
 * Tutto implementato tranne il punto 7 come da richiesta
 *
 * Sviluppa un software che permette a un negoziante di registrare gli incassi del giorno.
 * 
 * L'utente puo registrare al massimo gli incassi di un anno.
 * 
 * Le funzionalità richieste sono le seguenti:
 * 
 * 1 - Registrare gli incassi di "n" giorni (puoi anche utilizzare la funzione random tra 0 e 1000);
 * 
 * 2- Stampare a video degli incassi inseriti con il numero del giorno accanto a partire dal giorno 1 (es. "Giorno 1: 50 euro");
 * 
 * 3 - Calcola e stampa il totale e la media degli incassi di tutto il periodo;
 * 
 * 4 - Trova e stampa qual è stato l'incasso più alto e quello più basso registrato tra quelli inseriti;
 * 
 * 5 - Conta e stampa in quanti giorni l'incasso è stato inferiore a 50 euro (giornate "magre");
 * 
 * 6 - Crea due nuovi array, uno che contiene gli incassi inferiore all'incasso medio e l'altro che contiene gli incassi maggiore o uguale alla media;
 *
 * 7 - Ripeti il punto 6 utilizzando un ciclo iterativo diverso.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    //Array
    int incassi[400]={0};
    int small[400]={0};
    int big[400]={0};
    
    //Variabili
    int choice=0;
    int counter=-1;
    int counter2=-1;
    int n=0;
    int max=0;
    int min=100000;
    int magro=0;
    double media=0;
    double somma=0;
    bool invalid=false;

    //Random
    srand(time(0));
    
    //Input giorni
    cout<<"Quanti giorni di incassi vuoi inserire? ";
    cin>>n;
    if (n<=0 || n>366) {
        invalid=true;
    }

    //Controllo input giorni
    while (invalid==true) {
        cout<<"Numero invalido. Puoi inserire un massimo di 366 giorni."<<endl;
        cout<<"Quanti giorni di incassi vuoi inserire? ";
        cin>>n;

        if (n>0 && n<=366) {
        invalid=false;
        }
    }

    cout<<endl<<endl;

    //Menu scelta incassi random o input
    cout<<"--- MENU ---"<<endl;
    
        //Input opzione
        cout<<"Scegli un'opzione:"<<endl<<"0) Utilizza guadagni casuali"<<endl<<"1) Inserisci i tuoi guadagni"<<endl<<endl<<"Inserisci il numero corrispondente all'opzione per continuare: ";
        cin>>choice;

        //Controllo input opzione
        while (choice!=0 && choice!=1) {
            cout<<"Opzione non valida. Scegli tra 0 ed 1."<<endl;

            cout<<"Scegli un'opzione:"<<endl<<"0) Utilizza guadagni casuali"<<endl<<"1) Inserisci i tuoi guadagni"<<endl<<"Inserisci il numero corrispondente all'opzione per continuare: ";
            cin>>choice;
        }
    
    if (choice==0) {
        //Input casuale
        for (int i=0; i<n; i++){
            //Riempio incassi con numeri casuali da 0 a 1000
            incassi[i]=rand()%1001;

            //Salvo somma
            somma=somma+incassi[i];

            //Se maggiore di max, imposto il valore corrente a max
            if (incassi[i]>max) {
                max=incassi[i];
            }
        
            //Se minore di min, imposto il valore corrente a min
            if (incassi[i]<min) {
                min=incassi[i];
            }
        
            //Se minore di 50, aumento counter giornate magre
            if (incassi[i]<50) {
                magro++;
            }
        }
    } else if (choice==1) {
        //Input dall'utente
        for (int i=0; i<n; i++) {
            cout<<"Inserisci gli incassi del "<<i+1<<" giorno: ";
            cin>>incassi[i];

            //Controllo input incassi
            while (incassi[i]<0) {
                cout<<"Non puoi inserire guadagni minori di 0!"<<endl;
                cout<<"Inserisci gli incassi del "<<i+1<<" giorno: ";
                cin>>incassi[i];
            }
        
            //Salvo somma
            somma=somma+incassi[i];

            //Se maggiore di max, imposto il valore corrente a max
            if (incassi[i]>max) {
                max=incassi[i];
            }
        
            //Se minore di min, imposto il valore corrente a min
            if (incassi[i]<min) {
                min=incassi[i];
            }
        
            //Se minore di 50, aumento counter giornate magre
            if (incassi[i]<50) {
                magro++;
            }
        }
    }
    cout<<endl<<endl;
    
    //Ciclo output guadagni
    cout<<"--- Tutti i tuoi guadagni ---"<<endl;
    for (int i=0; i<n; i++) {
        cout<<"Giorno "<<i+1<<": "<<incassi[i]<<"€"<<endl;
    }
    cout<<endl<<endl;

    //Calcolo e output media guadagni
    media=somma/n;
    cout<<"La somma totale dei tuoi guadagni in questo periodo è di "<<somma<<"€, mentre la media giornaliera è di "<<media<<"€."<<endl;

    //Output max, min e magro
    cout<<"Il guadagno massimo che hai avuto è stato di "<<max<<"€, quello minimo è stato di "<<min<<"€, ed hai avuto "<<magro<<" giornate magre (guadagno inferiore a 50€)."<<endl;

    //for+if
    cout<<endl<<endl<<"--- OUTPUT ARRAY METODO 1 ---"<<endl;
    cout<<"Maggiori della media: ";
        //Riempio array minore della media
        for (int i=0; i<n; i++) {
            if (incassi[i]<media) {
                counter++;
                small[counter]=incassi[i];
                cout<<small[counter]<<"€ ";
            }
        }

        counter=-1;
        cout<<endl<<"Minori della media: ";
        //Riempio array maggiore della media
        for (int i=0; i<n; i++) {
            if (incassi[i]>=media) {
                counter++;
                 big[counter]=incassi[i];
                cout<<big[counter]<<"€ ";
            }
        }

    //do-while
    cout<<endl<<endl<<"--- OUTPUT ARRAY METODO 2 ---"<<endl;
    cout<<"Maggiori della media: ";
        //Riempio array minore della media
        counter2++;
            do {
                counter++;
                small[counter]=incassi[counter2];
                cout<<small[counter]<<"€ ";
                counter2++;
            } while (incassi[counter2]<media);

        counter=-1;
        cout<<endl<<"Minori della media: ";
        //Riempio array maggiore della media
            do {
                counter++;
                big[counter]=incassi[counter2];
                cout<<big[counter]<<"€ ";
                counter2++;
            } while (incassi[counter2]>media);
    
    return 0;
}