#include <iostream> // biblioteka do wejścia/wyjścia
#include <stdlib.h> // biblioteka do funkcji system
#include "headerFile.h" // dołączenie pliku nagłówkowego z deklaracjami funkcji
using namespace std;  //Żeby nie pisac std:: 
/*Uwaga dotycząca całego projektu w funckji do Zapisu stopni używamy odpowiedniego kodu:
1.0 = Celciusze
2.0 = farehaity
3.0 = Kelviny
*/
int main() {
	int prime = 1; //Żaby była pętla nieskonczona
	while (prime == 1) { //Pętla nieskończona
		int fahr, celsius, kelvin; //deklaracja zmiennych
		int start, limit, step;	//	deklaracja zmiennych
		int deccision; // deklaracja zmiennej decyzji
		cout << "Convert temperature" << endl;
		cout << "------------------------" << endl;
		cout << "What temperature do you want to convert?" << endl;
		cout << "1. Fahrenheit to Celsius" << endl;
		cout << "2. Fahrenheit to Kelvin" << endl;
		cout << "3.Celsius to Fahrenheit" << endl;
		cout << "4.Celsius to Kelvin" << endl;
		cout << "5.Kelvin to celsius" << endl;
		cout << "6.Kelvin to Fahrenheit" << endl;
		cout << "Enter your decision (1-6): ";
		cin >> deccision; // pobranie decyzji od u¿ytkownika
			switch (deccision) {
				case 1:
					Fahr_Celsius();
					break;
				case 2:
					Fahr_Kelvin();
					break;
				case 3:
					Celsium_Fahr();
					break; //Break musi być na końcu
				case 4:
					Celsius_Kelv();
					break;
				case 5:
					Kelv_cels();
					break;
				case 6:
					Kelvin_Fahr();
					break;
				}
		return 0;

	}
}