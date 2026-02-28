#include <iostream>
using namespace std;

int main() {
    int opt=0;
    int n=0;
    int countHigh=0;
    int countLow=0;
    int giorni=0;
    int temp[100]={0};
    int allHigh[100]={0};
    int allLow[100]={0};
    int media=0;
    int somma=0;
    int high=0;
    int cold=100;
    int coldCounter=0;
    
    cout<<"Quanti giorni vuoi inserire? ";
    cin>>giorni;
    
    while (giorni>31 || giorni<=0) {
        cout<<"Non puoi inserire questa dimensione! Inserisci un'altra dimensione: ";
        cin>>giorni;
    }

    for (int i=0; i<giorni; i++) {
        cout<<"Inserisci la temperatura per il giorno "<<i+1<<": ";
        cin>>temp[i];

        while (temp[i]>=50 || temp[i]<=-30) {
            cout<<"Un po' fuori dagli schemi, non credi? Inserisci un'altra temperatura: ";
            cin>>temp[i];
        }
        somma=somma+temp[i];

        if (temp[i]>high) {
            high=temp[i];
        }

        if (temp[i]<cold) {
            cold=temp[i];
        }

        if (temp[i]<0) {
            coldCounter++;
        }
    }

    cout<<endl<<endl;
    cout<<"--TEMPERATURE--"<<endl;

    for (int i=0; i<giorni; i++) {
        cout<<"Temperatura del giorno "<<i+1<<": "<<temp[i]<<endl;
    }

    media=somma/giorni;

    cout<<endl<<endl<<"--DETTAGLI--"<<endl<<"La temperatura media di questo periodo ("<<giorni<<" giorni) è di "<<media<<"°C"<<endl<<"La temperatura più alta è stata di "<<high<<"°C, quella più bassa di "<<cold<<"°C, mentre i giorni di gelo (<0°C) sono stati "<<coldCounter<<endl;

    cout<<endl<<endl<<"--NUOVO ARRAY--"<<endl<<"Scegli un opzione:"<<endl<<"1) Crea array col ciclo while"<<endl<<"2) Crea array col ciclo for"<<endl<<"Scegli un opzione: ";

    cin>>opt;
    
    if (opt==1) {
        while (n<giorni) {
            if (temp[n]>30) {
                allHigh[countHigh]=temp[n];
                countHigh++;
            }

            if (temp[n]<0) {
                allLow[countLow]=temp[n];
                countLow++;
            }
            n++;
        }
    } else if (opt==2) {
        for (int i=0; i<giorni; i++) {
            if (temp[i]>30) {
                allHigh[countHigh]=temp[i];
                countHigh++;
            }

            if (temp[i]<0) {
                allLow[countLow]=temp[i];
                countLow++;
            }
        }
    } else {
        cout<<"Non ho capito"<<endl;
        return 1;
    }

    cout<<endl<<endl<<"--TEMPERATURE ALTE--"<<endl;
    
    for (int i=0; i<countHigh; i++) {
        cout<<allHigh[i]<<" ";
    }

    cout<<endl<<endl<<"--TEMPERATURE BASSE--"<<endl;
    
    for (int i=0; i<countLow; i++) {
        cout<<allLow[i]<<" ";
    }
    
    return 0;
}
