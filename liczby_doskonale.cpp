//Liczby doskona�e
//(c) Dominik Go�dziuk
//www.algorytm.org
 
#include <conio.h>
#include <iostream>
 
int main() {
using namespace std;
 
//Inicjalizacja zmiennych
int liczby[3];
int znalezione = 0, x = 1, suma_dzielnikow = 0;
 
//Dop�ki nie znaleziono 3 liczb doskona�ych
while (znalezione < 3) {
//Sprawd� czy x jest liczb� doskona��
for (int i = 1; i <= (x/2); i++) {
if ((x % i) == 0)
suma_dzielnikow += i;   
}
 
//Je�eli x jest liczb� doskona�� to dodaj j� do tablicy
if (suma_dzielnikow == x) {
liczby[znalezione] = x;
++znalezione;                   
}
++x;
suma_dzielnikow = 0;   
}
 
//Wypisz znalezione liczby doskona��
cout << "Trzy pierwsze liczby doskonale: " << endl
<< liczby[0] << ", " << liczby[1] << ", " << liczby[2]
<< endl;
 
getch();
return(0);  
}
