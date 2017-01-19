//Liczby doskona³e
//(c) Dominik GoŸdziuk
//www.algorytm.org
 
#include <conio.h>
#include <iostream>
 
int main() {
using namespace std;
 
//Inicjalizacja zmiennych
int liczby[3];
int znalezione = 0, x = 1, suma_dzielnikow = 0;
 
//Dopóki nie znaleziono 3 liczb doskona³ych
while (znalezione < 3) {
//SprawdŸ czy x jest liczb¹ doskona³¹
for (int i = 1; i <= (x/2); i++) {
if ((x % i) == 0)
suma_dzielnikow += i;   
}
 
//Je¿eli x jest liczb¹ doskona³¹ to dodaj j¹ do tablicy
if (suma_dzielnikow == x) {
liczby[znalezione] = x;
++znalezione;                   
}
++x;
suma_dzielnikow = 0;   
}
 
//Wypisz znalezione liczby doskona³ê
cout << "Trzy pierwsze liczby doskonale: " << endl
<< liczby[0] << ", " << liczby[1] << ", " << liczby[2]
<< endl;
 
getch();
return(0);  
}
