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
		int decision; // deklaracja zmiennej decyzji
		system("cls"); // czyści ekran konsoli
		cout << "Convert temperature" << endl;
		cout << "------------------------" << endl;
		cout << "What temperature do you want to convert?" << endl;
		cout << "1. Fahrenheit to Celsius" << endl;
		cout << "2. Fahrenheit to Kelvin" << endl;
		cout << "3. Celsius to Fahrenheit" << endl;
		cout << "4. Celsius to Kelvin" << endl;
		cout << "5. Kelvin to celsius" << endl;
		cout << "6. Kelvin to Fahrenheit" << endl;
		cout << "7. History" <<endl;
		cout << "8. Delete record from History" << endl;
		cout << "9. Modify record in History" << endl;
		cout << "10. Fill History with random values" << endl;
		cout << "-1. Exit" << endl;
		cout << "------------------------" << endl;
		cout << "Enter your decision: ";
		decision = (int)get_safedouble(); //zabezpieczenie do popbierania odpowiedniej wartości
		system("cls"); // czyści ekran konsoli
		//decyzje które kto chce convertować.
		if (decision == -1) {
			return 0;
		}
		switch (decision) {
		case 1: {
			Fahr_Celsius_option();
			break;
		}
		case 2: {
			Fahr_Kelvin_option();
			break;
		}
		case 3: {
			Celsium_Fahr_option();
			break; //Break musi być na końcu
		}
		case 4: {
			Celsius_Kelv_option();
			break;
		}
		case 5: {
			Kelv_cels_option();
			break;
		}
		case 6: {
			Kelvin_Fahr_option();
			break;
		}
		case 7: {
			show_History();
			break;
		}
		case 8: {
			deleteRecords();
			break;
		}
		case 9: {
			ModifyRecord();
			break;
		}
		case 10: {
			Fill_History_Random_Values();
			break;
		}
		default: {
			cout << "Invalid decision. Please try again." << endl;
		}
		}
		cout << "Press Enter to continue..." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignoruj poprzednie wejście
		cin.get(); //Czekaj na enter
	}
}