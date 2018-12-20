#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

bool czydopliku = false;
ofstream wynik;

int main()
{
        wynik.open("wynik.txt");
        int n = 0;
        int k = 0;
        bool czyDoklanieKblokowe = false;
        cout << "Program generuje podzialy zbioru n-elementowego. {1,...,n}" << endl;
        cout << "Gdzie wypisac wyniki? 1 - na ekran 2 - do pliku" << endl;
        cin >> n;
        if(n==2) czydopliku = true;
        n = 0;

        cout << "Warianty: " << endl;
        cout << "1. Generacja co najwyzej k-blokowych podzialow (1<=k<=n)" << endl;
        cout << "2. Generacja dokladnie k-blokowych podzialow (1<=k<=n)" << endl;
        //cout << "3. Generacja dokladnie k-blokowych podzialow zrownowazonych (Zakladam, ze podzialy zrownowazone to takie, ktore posiadaja taka sama ilosc elementow)" << endl;

        while(1){
            cout << "Wybierz wariant: ";
            cin >> n;
            if(n<1 || n>3){
                cout << "Podano bledne dane. Sprobuj jeszcze raz." << endl;
                continue;
            }
            if(n==2) czyDoklanieKblokowe = true; else czyDoklanieKblokowe = false;

            cout << "Podaj n: ";
            cin >> n;
            if(n<1){
                cout << "Podano bledne dane. Sprobuj jeszcze raz." << endl;
                continue;
            }

            cout << "Podaj k: ";
            cin >> k;
            if(k<1 || k>n){
                cout << "Podano bledne dane. Sprobuj jeszcze raz." << endl;
                continue;
            }
            break;
        }

        cout << "Rozpoczynam wypisywanie kolejnych mozliwych podzialow wybranego zbioru." << endl;
        int a[1024];
        for (int i = 0; i < n; i++) a[i] = 1;
        int ilosc = 0;
        int m = 0;
        bool czyWypisac = true;

        do{
            if(czyDoklanieKblokowe){
                for(int j = 0; j <= n-1 ; j++ ){
                    if( a[j] > m ){
                        m = a[j];
                    }
                }
                if(m!=k) czyWypisac = false; else czyWypisac = true;
            }else czyWypisac = true;

            if(czyWypisac){
                ilosc++;
                if(czydopliku) wynik << ilosc << ". "; else cout << ilosc << ". ";
                for (int i = 0; i < n; i++){
                        if(czydopliku) wynik << a[i]; else cout << a[i];
                }
                if(czydopliku) wynik << endl; else cout << endl;
            }

            a[n-1]++;
            for(int i = 1; n-i-1>=0 ; ){
                m = 0;
                for(int j = 0; j < n-i ; j++ ){
                    if( a[j] > m ){
                        m = a[j];
                    }
                }
                if( a[n-i] == m+2 || a[n-i] == k+1 ){ //a[n-i] == a[n-i-1]+2
                    a[n-i-1]++;
                    a[n-i] = 1;
                    i++;
                } else break;
            }
        }while(a[0] == 1); //&& ilosc < 24

        if(czydopliku) wynik << "Ilosc wygenerowanych podzialow: " << ilosc << endl; else cout << "Ilosc wygenerowanych podzialow: " << ilosc << endl;
        if(czydopliku) cout << "Gotowe. Wyniki znajdziesz w pliku wynik.txt" << endl;
        cin >> n;

        return 0;
}
