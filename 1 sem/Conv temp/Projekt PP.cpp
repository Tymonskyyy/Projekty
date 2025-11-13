#include <iostream> // biblioteka do wejścia/wyjścia
#include <stdlib.h> // biblioteka do funkcji system
using namespace std;  //Żeby nie pisac std:: 
int g_table_history[100][2]; // tablica do przechowywania historii konwersji
int g_Data_Center = 0; // zmienna do przechowywania liczby wpisów w historii
/*Uwaga dotycząca całego projektu w funckji do Zapisu stopni używamy odpowiedniego kodu:
1.0 = Celciusze
2.0 = farehaity
3.0 = Kelviny
*/

void Memory_History(double result, int unit_code) { //Archiwista zapisujący historię świata

	if (g_Data_Center < 100) { //Jeżeli nasza historia jest mniejsza niż 100 wpisów
		g_table_history[g_Data_Center][0] = result; // zapisywanie wyniku działania użytkowniak
		g_table_history[g_Data_Center][1] = unit_code; // zapisywanie kodu jednostki
		g_Data_Center++;	// Przechodzimy do następnego wpisu w historii
	}
	else { //Jeżeli nie
			//Zapełnienie tablicy (przeciwdziałanie)
		cout << "History is full!" << endl;
		cout << "Cannot save more entries." << endl;

	}
	}
void Show_History() { // Telewizor do wyświetlania 
	cout << "Conversion History:" << endl; // nagłówek historii
	if (g_Data_Center == 0) { // sprawdzanie czy historia jest pusta
		cout << "No entries in history." << endl;
	}
	else {
		for (int i = 0; i < g_Data_Center; i++) { // Pętlka jęzeli coś jest w hitsorii to wypisz na ekranie

			double result = g_table_history[i][0]; // pobieranie wyniku z historii

			int	unit_code = g_table_history[i][1]; // pobieranie kodu jednostki z historii

			cout << "Entry " << i + 1 << ": "; // wyświetlanie numeru wpisu

			switch (unit_code) { //DO wyboru literki do tempperatyu
			case 1:
				cout << result << "C" << endl; //endl to nowa linia zaś cała linijka pokazuje wynik
				cout << i + 1 << ". " << g_table_history[i][0] << endl; // wyświetlanie wpisów historii
				break;
			case 2:
				cout << result << "F" << endl;
				cout << i + 1 << ". " << g_table_history[i][0] << endl; // wyświetlanie wpisów historii
				break;
			case 3:
				cout << result << "K" << endl;
				cout << i + 1 << ". " << g_table_history[i][0] << endl; // wyświetlanie wpisów historii
				break;
			case 4:
				cout << result << "C" << endl;
				cout << i + 1 << ". " << g_table_history[i][0] << endl; // wyświetlanie wpisów historii
				break;
			default:
				cout << "Unknown unit code" << endl;
				break;

			}
		}
	}
}
static bool Check_temp(double temp_value, int unit_type){ //Funkcja do sprawdzania czy temperatura nie jest ponizej zera absolutnego
	int Fahr_Celsius(int fahr); //Deklaracja funkcji
	int Fahr_Kelvin(int fahr); //Deklaracja funkcji
	int Celsium_Fahr(int celsius);
	int Celsius_Kelv(int celsius);
	int Kelv_cels(int kelvin);
	int Kelvin_Fahr(int kelvin);
	//Sprawdzanie czy temperatura nie jest ponizej zera absolutnego
		switch (unit_type) { //Switch do wyboru decyzji żeby sprawdzić odpowiednią temperaturę
		//Do danej decyzji sprawdzamy czy nie zrobił użytkownik błedu
		case 1:
			if (temp_value < -459.67) {
				cout << "Error: Temperature below absolute zero!" << endl;
				return false;
			}
			break;

		case 2:
			if (temp_value< -459.67) {
				cout << "Error: Temperature below absolute zero!" << endl;
			}
			
			return false;
			break;

		case 3:
			if(temp_value < -273.15) {
				cout << "Error: Temperature below absolute zero!" << endl;
			}
			return false;
			break;
		case 4:
			if (temp_value< -273.15) {
				cout << "Error: Temperature below absolute zero!" << endl;
			}
			return false;
			break;
		case 5:
			if (temp_value < 0) {
				cout << "Error: Temperature below absolute zero!" << endl;
			}
			return false; // zwracanie fałszu aby pokazać błąd
			break; //Zawsze musi być break w switch
		case 6:
			if (temp_value< 0) {
				cout << "Error: Temperature below absolute zero!" << endl;
			}
			return false; //Zwracanie fałszu jeśli temperatura jest poniżej zera absolutnego
			break;	//Zawsze musi być break w switch
		}
		return true; //Zwracanie prawdy jeśli temperatura jest powyżej zera absolutnego
	}
	static int Fahr_Celsius() {
		int fahr, celsius;
		int start, limit, step;

		cout << "Fahrenheit\tCelsius" << endl;
		cout << "------------------------" << endl;
		cout << "Provide grades";
		cin >> fahr;

		start = 0;    // poczatkowa temperatura w skali Fahrenheita
		limit = 200; // przypis 200 do zmiennej limit
		step = 20;   // krok co 20 stopni
		if (Check_temp(fahr, 1) == false) {
			return -1000; //Umyślny uniwerasalny bład ktory ma mi pokazać BŁĄD
		}
		while (fahr <= limit) {

			double celsius = (fahr - 32) * 5.0 / 9.0;
			cout << fahr << "F" << "\t" << celsius << "C" << endl;
			return celsius;
		}
		return 0;
		/*if celsius < -273.15{
			cout << "Error: Temperature below absolute zero!" << endl;
		}
		*/
	} //Działa//Działa
	static int Fahr_Kelvin() {
		int fahr, kelvin;
		int start, limit, step;

		cout << "Fahrenheit\tKelvin" << endl;
		cout << "------------------------" << endl;
		cout << "Provide grades";
		cin >> fahr;
		start = 0;    // poczatkowa temperatura w skali Fahrenheita
		limit = 200; // przypis 200 do zmiennej limit
		step = 20;   // krok co 20 stopni
		if (Check_temp(fahr, 2) == false) {
			return -1000; //Zwróć mi błąd
		}
		while (fahr <= limit) {
			double kelvin = (fahr +459.67)*5.0/9.0;
			cout << fahr << "F" << "\t" << kelvin << "K" << endl;
			return kelvin;
		}
		return 0;
		/*
		if kelvin < 0{
			cout << "Error: Temperature below absolute zero!" << endl;
		
		}*/
	}//Działa
	static int Celsium_Fahr() {
		int fahr, celsius; // deklaracja zmiennych
		int start, limit, step; // deklaracja zmiennych
		cout << "Celsium\tFahrenheit" << endl;
		cout << "------------------------" << endl;
		cout << "Provide grades";
		cin >> celsius;
		start = 0;    // poczatkowa temperatura w skali Fahrenheita
		limit = 200; // przypis 200 do zmiennej limit
		step = 20;   // krok co 20 stopni
		if (Check_temp(celsius, 3) == false) {
			return -1000; //Zwróć mi błąd

		}
		while (celsius <= limit) { // pêtla while
			double fahr = celsius * 9.0 / 5.0 + 32.0; // Konwersja Celsium na Fahrenheita
			cout << celsius << "C" << "\t" << fahr  << "F" << endl; // Wyświetlanie wartości
			return fahr; //Zwracanie wartości funkcji

		}
		return 0;
		/*
		if fahr < -459.67 {
			cout << "Error: Temperature below absolute zero!" << endl;*/
		//}
	}//Działa
	static int Celsius_Kelv() {
		int celsius;
		int kelvin;
		int start;
		int limit;
		int step;
		start = 0;    // poczatkowa temperatura w skali Fahrenheita
		limit = 200; // przypis 200 do zmiennej limit
		step = 20;   // krok co 20 stopni
		cout << "Celsius\tKelvin" << endl;
		cout << "------------------------" << endl;
		cout << "Provide grades";
		cin >> celsius;
		if (Check_temp(celsius, 4) == false) {
			return -1000; //Zwróć mi błąd
		}

		while (celsius <= limit) {
			double kelvin = celsius + 273.15;
			cout << celsius << "C" << "\t" << kelvin << "K" << endl;
			return kelvin;
		}
		return 0;
		/*
		if kelvin < 0 {
			cout << "Error: Temperature below absolute zero!" << endl;
			*/
		//}
	}
	static int Kelv_cels() {
		int kelvin, celsius;
		int start, limit, step;
		int ending;
		cout << "Kelvin\tCelsius" << endl;
		cout << "------------------------" << endl;
		cout << "Provide grades";
		cin >> kelvin;
		start = 0;    // poczatkowa temperatura w skali Fahrenheita
		limit = 200; // przypis 200 do zmiennej limit
		step = 20;   // krok co 20 stopni
		if (Check_temp(kelvin, 5) == false) { //Sprawdzenie czy temperatura nie jest poniżej zera absolutnego

			return -1000; //Zwróć mi błąd
		}
		while (kelvin <= limit) {
			double celsius = kelvin - 273.15;
			cout << kelvin << "K" << "\t" << celsius << "C" << endl;
			return celsius;
		}

		return 0;
	}
	static int Kelvin_Fahr() {
		int kelvin, fahr;
		int start, limit, step;
		cout << "Kelvin\tFahrenheit" << endl;
		cout << "------------------------" << endl;
		cout << "Provide grades";
		cin >> kelvin;
		start = 0;    // poczatkowa temperatura w skali Fahrenheita
		limit = 200; // przypis 200 do zmiennej limit
		step = 20;   // krok co 20 stopni
		if (Check_temp(kelvin, 6) == false) {
			return -1000; //Zwróć mi błąd
		}
		while (kelvin <= limit) {
			double fahr = kelvin *9.0/5.0 - 459.67;
			cout << kelvin << "K" << "\t" << fahr << "F" << endl;
			return fahr;
		}

		return 0;
	}
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
			cout << "9.Exit" << endl;
			cout << "------------------------" << endl;
			cout << "Enter your decision (1-6): ";
			cin >> decision; // pobranie decyzji od u¿ytkownika
			//decyzje które kto chce convertować.
			switch (decision) {
			case 1:
				result = Fahr_Celsius();
				
				//Wywoływanie funkcji do sprawdzania temperatury
				if (result != -1000) {
					Memory_History(result,1); //Zapisz wynik jeżeli nie ma błeu
				}
				break;
				
			case 2:
				result = Fahr_Kelvin();
				
				if (result != -1000) {
					Memory_History(result,3); //Zapisz wynik jeżeli nie ma błeu
				}
				break;
			case 3: 
				result = Celsium_Fahr();

				if (result != -1000) {
					Memory_History(result,2); //Zapisz wynik jeżeli nie ma błeu
				}
				break; //Break musi być na końcu

			case 4:
				result = Celsius_Kelv();
				
				if (result != -1000) {
					Memory_History(result,3); //Zapisz wynik jeżeli nie ma błeu
				}
				break;

			case 5:
				result = Kelv_cels();
				
				if (result != -1000) {
					Memory_History(result,1); //Zapisz wynik jeżeli nie ma błeu
				}
				
				break;

			case 6:
				result = Kelvin_Fahr();
				
				if (result != -1000) {
					Memory_History(result,2); //Zapisz wynik jeżeli nie ma błeu
				}
				break;

			case 7:
				system("cls");
				break;
			case 8:	
				Show_History();
				break;
			case 9:
				cout << "Goodbye!" << endl;
				prime = 0;
				break;

			}
		}
		return 0;
	}
