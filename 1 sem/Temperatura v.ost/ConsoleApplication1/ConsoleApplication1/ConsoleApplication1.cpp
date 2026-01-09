#include <iostream> // biblioteka do wejścia/wyjścia
#include <stdlib.h> // biblioteka do funkcji system
#include "funkcje.h" // dołączenie pliku nagłówkowego z deklaracjami funkcji
using namespace std;  //Żeby nie pisac std:: 
/*Uwaga dotycząca całego projektu w funckji do Zapisu stopni używamy odpowiedniego kodu:
1.0 = Celciusze
2.0 = farehaity
3.0 = Kelviny
*/

int main() {
	int prime = 1; //Żaby była rekurencja  (pętla nieskonczona)
	double result;
	while (prime == 1) { //Pętla nieskończona
		int fahr, celsius, kelvin; //deklaracja zmiennych
		int start, limit, step;	//	deklaracja zmiennych

		int decision; // deklaracja zmiennej decyzji
		cout << "Convert temperature" << endl;
		cout << "------------------------" << endl;
		cout << "What temperature do you want to convert?" << endl;
		cout << "1. Fahrenheit to Celsius" << endl;
		cout << "2. Fahrenheit to Kelvin" << endl;
		cout << "3.Celsius to Fahrenheit" << endl;
		cout << "4.Celsius to Kelvin" << endl;
		cout << "5.Kelvin to celsius" << endl;
		cout << "6.Kelvin to Fahrenheit" << endl;
		cout << "7.Clean Screen" << endl;
		cout << "8.History" << endl;
		cout << "10.Clear History" << endl;
		cout << "-1 Exit" << endl;
		cout << "------------------------" << endl;
		cout << "Enter your decision (1-6): ";
		cin >> decision; // pobranie decyzji od u¿ytkownika
		//decyzje które kto chce convertować.
		switch (decision) {
		case 1:
			result = Fahr_Celsius();

			//Wywoływanie funkcji do sprawdzania temperatury
			if (result != -1000) {
				Memory_History(result, 1); //Zapisz wynik jeżeli nie ma błeu
			}
			break;

		case 2:
			result = Fahr_Kelvin();

			if (result != -1000) {
				Memory_History(result, 3); //Zapisz wynik jeżeli nie ma błeu
			}
			break;
		case 3:
			result = Celsium_Fahr();

			if (result != -1000) {
				Memory_History(result, 2); //Zapisz wynik jeżeli nie ma błeu
			}
			break; //Break musi być na końcu

		case 4:
			result = Celsius_Kelv();

			if (result != -1000) {
				Memory_History(result, 3); //Zapisz wynik jeżeli nie ma błeu
			}
			break;

		case 5:
			result = Kelv_cels();

			if (result != -1000) {
				Memory_History(result, 1); //Zapisz wynik jeżeli nie ma błeu
			}

			break;

		case 6:
			result = Kelvin_Fahr();

			if (result != -1000) {
				Memory_History(result, 2); //Zapisz wynik jeżeli nie ma błeu
			}
			break;

		case 7:
			system("cls");
			break;
		case 8: {
			int filter_choice = 4; //Wartość domyślna
			cout << "Showing conversion history:" << endl;
			cout << "Filter by unit type?" << endl;
			cout << "1. Celsius" << endl;
			cout << "2. Fahrenheit" << endl;
			cout << "3. Kelvin" << endl;
			cout << "4. Everything" << endl;
			cout << "Enter your choice (1-4): ";
			cin >> filter_choice;

			Show_History(filter_choice);
			break;
		}
		case 10: {
			cout << "Goodbye!" << endl;
			prime = 0;
			break;


		}
		case 9: {
			cout << "Clearing history..." << endl;
			Clear_History();
			break;
		}


			   return 0;
		}
	}
}