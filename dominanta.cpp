//Program do wyznacznia najczêœciej wystêpuj¹cej wartoœci w tablicy (dominaty)
//Micha³ Witaszek
//dla algorytm.org

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{

  int T[100];            // Tablica bêdzie przechowywa³a zadany zbiór liczb
  int lista[100];        // Lista liczb wystêpuj¹cych w zbiorze
  int wystepowanie[100]; // Zapamiêta ile razy liczby pojawiaj¹ siê w zbiorze
  int n;                     
  int i,j;               // Bêd¹ s³u¿y³y jako indeksy tablic
  bool znaleziono;       // Podczas przeszukiwania tablic bêdzie okreœla³a czy liczba ju¿ zajduje siê na liœcie

  int dlugosc_listy=0;         

  const string separator = "--------------------------- \n";

start:
// Pobranie od u¿ytkownika iloœci elementów tablicy

  cout << "Ilosc elementow tablicy: ";
  cin >> n;

if (n<=0 || n>100) 
    {
    cout << "Podaj wartosc z akresu 1-100 \n";
    goto start;
    }
    
 cout << separator;
 
// Odczytywanie n elementów tablicy
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

// Przeszukuje listê liczb a¿ znajdzie w niej aktualnie odczytan¹ wartoœæ z tablicy T[]
// lub osi¹gnie koniec listy

      for (j=0; j<dlugosc_listy; j++)
      {
        if (lista[j]==T[i]) //Jeœli liczba znajduje siê na liœcie...
          {
          wystepowanie[j]++; // Zwiêksz iloœæ wyst¹pieñ liczby o 1
          znaleziono= true; // Zapamiêtaj ¿e odnaleziono liczbê.
          }
        if (znaleziono) break;
      }  
      

      if (!znaleziono) //Jeœli liczba nie znajduje siê jeszcze na liœcie...
        {
          dlugosc_listy++;          
          lista[dlugosc_listy-1]=T[i]; //Wstaw liczbê na ostani¹ pozycje w liœcie
          wystepowanie[dlugosc_listy-1]=1; //Ustaw iloœæ wyst¹pieñ liczby na 1
        }	   
	  } 

  cout << separator;

  
    //Dla przej¿ystoœci program wypisze iloœæi wyst¹pieñ wszystkich liczb.
    for (i=0; i<dlugosc_listy; i++)  {cout << lista[i] << " x " << wystepowanie[i] << endl;}

  cout << separator;

    //Szukanie najczêœciej wystêpuj¹cej liczby
    i=0; 
    j=0;
   
    for (i=1; i<dlugosc_listy; i++)  //Przeszukanie tablicy wystêpowania liczb
    {
     //Jeœli liczba wyst¹pieñ jest wiêksza od poprzednio znalezionej...
        if (wystepowanie[i] >= wystepowanie[j]) j=i; // zapamiêtaj indeks liczby.
    } 

   //Wypisz wynik
    cout << "Dominanta jest liczba " << lista[j] << endl;
    cout << "Pojawia sie " << wystepowanie[j] << " razy." << endl;  
  
//Czekaj na ANYKEY
  system("PAUSE");	
//i zamknij program
  return 0;
}