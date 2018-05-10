#ifndef TABLICA_HPP_INCLUDED
#define TABLICA_HPP_INCLUDED
#include <stdexcept>
#include <algorithm>


template <typename T>
class tablica
{
private:
    T *t ; // wskaznik tablicy na stercie
    int n; // rozmiar tablicy
public:
    // int get_size();
    tablica (int rozm) throw(std::invalid_argument())  ; // konstruktor
    ~tablica(); //destruktor
    T* get_ptr() noexcept ;
    tablica(const tablica &tab) noexcept ; //konstruktor kopiujacy
    tablica (tablica &&tab) noexcept ; // konstruktor przenoszacy
    tablica& operator = (const tablica &tab) noexcept ; // przypisanie kopiujace
    tablica& operator = (tablica &&tab) noexcept ; // przypisanie przenoszace
public:
    const int rozmiar()  noexcept ;
    const T& operator[] (int i) const throw (std::range_error)  ; // operator odczytu danych
    T& operator[] (int i) throw (std::range_error); // operator zapisu danych
public:
    void sortuj(T *a , int size) noexcept ;
    void sortmax(T *a, int size) noexcept ;
};

//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************


template<class T>
tablica<T>::tablica(int rozm) throw(std::invalid_argument()):n(rozm)
{
    try
    {
    if(rozm < 0 ) throw std::invalid_argument("Podales niedodatni rozmiar tablicy!!!") ;
    else
        {
        t = new T [n] ;
      //  std::cout << "Tworze tablice: " << n << " elementow " << std::endl;
        }
    }

    catch(std::invalid_argument)
    {
        std::cerr << "Podales niedodatni rozmiar tablicy!!!" << std::endl ;
    }
}
//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************
//destruktor
template<class T>
tablica<T>::~tablica()
{
    //std::cout <<"Usuwam tablice " << n << " elementow" << std::endl  ;
   delete [] t ;
}
//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************
template<class T>
tablica<T>::tablica(const tablica &tab) noexcept:
	tablica(tab.n)
{
     std::cout << "Dziala konstruktor kopiujacy" << std::endl ;
    t = new T[tab.n] ;
	for (int i = 0; i < n; i++) {
		t[i] = tab.t[i];
	}
}
//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************
template<class T>
tablica<T>::tablica(tablica &&tab) noexcept:
	tablica(tab.n)
{
   std::cout << "Dziala konstruktor przenoszacy" << std::endl ;
    t = new T [tab.n] ;
	for (int i = 0; i < n; i++) {
		t[i] = tab.t[i];
	}
}
//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************
template<class T>
tablica<T>& tablica<T>::operator = (const tablica &tab) noexcept
{
    std::cout << "Dziala przypisanie kopiujace" << std::endl ;
       t = new T[tab.n] ;
	for (int i = 0; i < n; i++) {
		t[i] = tab.t[i];
	}
    return *this ;
}
//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************
template<class T>
tablica<T>& tablica<T>::operator = (tablica &&tab) noexcept
{
    std::cout << "Dziala przypisanie przenoszace" << std::endl ;
   t = new T[tab.n] ;
	for (int i = 0; i < n; i++) {
		t[i] = tab.t[i];
	}
    return *this ;
}


//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************
template<class T>
const int tablica<T>::rozmiar() noexcept
{
    return  n ;
}
//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************
template<class T>
 const T& tablica<T> ::operator [] (int i) const throw (std::range_error)
{
    try
    {
        if (  i > n || i < 0) throw std::range_error("Przekroczenie zakresu tablicy!!");
          else
            return t[i] ;
    }

  catch(std::range_error)
  {
     std::cerr << "Przekroczenie zakresu tablicy!!" ;
  }
}
//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************

template<class T>
T& tablica<T> ::operator [] (int i) throw (std::range_error)
{
    try
    {
        if ( i > n || i < 0 ) throw std::range_error("Przekroczyles zakres tablicy!!!");
          else
            return t[i] ;
    }

  catch(std::range_error)
  {
     std::cerr << "Przekroczyles zakres tablicy!!!" << std::endl  ;
  }
}
//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************
template<class T>
void tablica<T>::sortuj(T *a , int size) noexcept
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size - 1 ; j++)
        {
            if ( a[j] > a[j+1] )
            {
                std::swap(a[j], a[j+1]) ;
            }
        }
    }
}

//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************

template<class T>
void tablica<T>::sortmax(T *a , int size) noexcept
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size - 1 ; j++)
        {
            if ( a[j] < a[j+1] )
            {
                std::swap(a[j], a[j+1]) ;
            }
        }
    }
}
//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************
template<class T>
T* tablica<T>::get_ptr() noexcept
 {
     return t;
 }
//*************************************************************************
//#########################################################################
//#########################################################################
//*************************************************************************

template<typename T>
void drukuj(T tab, int n) {
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        if (i) std::cout << ", ";
        std::cout << tab[i];
    }
    std::cout << "]" << std::endl;
}

#endif // TABLICA_HPP_INCLUDED
