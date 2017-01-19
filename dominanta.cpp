//Program do wyznacznia najcz�ciej wyst�puj�cej warto�ci w tablicy (dominaty)
//Micha� Witaszek
//dla algorytm.org

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{

  int T[100];            // Tablica b�dzie przechowywa�a zadany zbi�r liczb
  int lista[100];        // Lista liczb wyst�puj�cych w zbiorze
  int wystepowanie[100]; // Zapami�ta ile razy liczby pojawiaj� si� w zbiorze
  int n;                     
  int i,j;               // B�d� s�u�y�y jako indeksy tablic
  bool znaleziono;       // Podczas przeszukiwania tablic b�dzie okre�la�a czy liczba ju� zajduje si� na li�cie

  int dlugosc_listy=0;         

  const string separator = "--------------------------- \n";

start:
// Pobranie od u�ytkownika ilo�ci element�w tablicy

  cout << "Ilosc elementow tablicy: ";
  cin >> n;

if (n<=0 || n>100) 
    {
    cout << "Podaj wartosc z akresu 1-100 \n";
    goto start;
    }
    
 cout << separator;
 
// Odczytywanie n element�w tablicy
 for (i=0; i<n; i++)
    {
      cout << "Wartosc nr " << i+1 << ": ";
      cin >> T[i];
    }

// Przeszukiwanie zadanej tablicy T[]
   for (i=0; i<n; i++) 
    {
      j=0;
      znaleziono= false;

// Przeszukuje list� liczb a� znajdzie w niej aktualnie odczytan� warto�� z tablicy T[]
// lub osi�gnie koniec listy

      for (j=0; j<dlugosc_listy; j++)
      {
        if (lista[j]==T[i]) //Je�li liczba znajduje si� na li�cie...
          {
          wystepowanie[j]++; // Zwi�ksz ilo�� wyst�pie� liczby o 1
          znaleziono= true; // Zapami�taj �e odnaleziono liczb�.
          }
        if (znaleziono) break;
      }  
      

      if (!znaleziono) //Je�li liczba nie znajduje si� jeszcze na li�cie...
        {
          dlugosc_listy++;          
          lista[dlugosc_listy-1]=T[i]; //Wstaw liczb� na ostani� pozycje w li�cie
          wystepowanie[dlugosc_listy-1]=1; //Ustaw ilo�� wyst�pie� liczby na 1
        }	   
	  } 

  cout << separator;

  
    //Dla przej�ysto�ci program wypisze ilo��i wyst�pie� wszystkich liczb.
    for (i=0; i<dlugosc_listy; i++)  {cout << lista[i] << " x " << wystepowanie[i] << endl;}

  cout << separator;

    //Szukanie najcz�ciej wyst�puj�cej liczby
    i=0; 
    j=0;
   
    for (i=1; i<dlugosc_listy; i++)  //Przeszukanie tablicy wyst�powania liczb
    {
     //Je�li liczba wyst�pie� jest wi�ksza od poprzednio znalezionej...
        if (wystepowanie[i] >= wystepowanie[j]) j=i; // zapami�taj indeks liczby.
    } 

   //Wypisz wynik
    cout << "Dominanta jest liczba " << lista[j] << endl;
    cout << "Pojawia sie " << wystepowanie[j] << " razy." << endl;  
  
//Czekaj na ANYKEY
  system("PAUSE");	
//i zamknij program
  return 0;
}