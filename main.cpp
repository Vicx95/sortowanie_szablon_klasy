#include <iostream>
#include "tablica.hpp"
using namespace std ;

int main()
{



    tablica <int>d(5) ;
    d[0] = 190;
    d[1] = 87 ;
    d[2] = 66 ;
    d[3] = 79 ;
    d[4] = 43 ;
    int f = 5 ;
    cout << "Przed sortowaniem(min to max): " <<endl ;
    drukuj(d,f);
    d.sortuj(d .get_ptr(), f) ;
    cout<< "Po sortowaniu(min to max): " << endl  ;
    drukuj(d,f) ;

    cout << "############################################ "<< endl ;
    cout << "############################################ "<< endl ;
    tablica <int>c(5) ;
    c[0] = 30 ;
    c[1] = 21 ;
    c[2] = 90 ;
    c[3] = 76 ;
    c[4] = 45 ;
     cout << "Przed sortowaniem(max to min): " <<endl ;
    drukuj(c,f);
    c.sortmax(c.get_ptr(), f) ;
    cout<< "Po sortowaniu(max to min): " << endl  ;
    drukuj(c,f) ;


    tablica<int>a(1) ;
    a[0] = 10 ;
    cout << "############################################ "<< endl ;
    cout << "############################################ "<< endl ;
    cout << "Indeks a[0]: " << a[0] <<endl;
    tablica <int> b(a) ; //uzycie konstruktora kopiujacego
    cout << "Indeks b[0] po uzyciu konstruktora kopiujacego: " << b[0] << endl;

     cout << "******************************************* "<< endl ;
     tablica<int>r =move(a) ; // uzycie kopnstruktora przenoszacego
     cout << "Indeks r[0] po uzyciu konstruktora przenoszacego: " << b[0] << endl;
    cout << "############################################ "<< endl ;
    cout << "############################################ "<< endl ;


    tablica<int>t(1) ;
        t[0] = 5 ;
    cout << "Indeks t[0] przed uzyciem przypisania kopiujacego: " << t[0] <<endl;
        t = a ; //uzycie przypisania kopiujacego
      cout << "Indeks t[0] po uzyciu przypisania kopiujacego: " << t[0] << endl;
    cout << "******************************************* "<< endl ;
    tablica <int>y(2) ;
    y[0] =15 ;
    y[1] = 14 ;
       cout << "Indeks y[0], y[1] przed uzyciem przypisania przenoszacego: " << y[0] << " " << y[1] << endl;
    y = move(a) ;
     cout << "Indeks y[0] po uzyciu przypisania przenoszacego: " << y[0] << " " << endl;

    cout << "############################################ "<< endl ;
    cout << "############################################ "<< endl ;

    cout << "Proba stworzenia tablicy z ujemnym rozmiarem: " << endl ;
    tablica<int>u(-20) ;

    cout << "Proba przekroczenia zakresu tablicy: " << endl ;
    tablica <int>o(10);
    o[15] = 30 ;
    cout << o[15]  << endl ;
    cout << "Druga proba przekroczenia zakresu tablicy: " << endl ;
    o[-30] = 15 ;
    cout << o[-30] << endl ;
    return 0 ;

}
