#include <iostream>
#include <limits>
#include <random>
#include <stdlib.h>

using namespace std;

double g_table_history[100]; // tablica do przechowywania historii konwersji
char g_table_units[100]; // tablica do przechowywania jednostek konwersji
int g_Data_Center = 0; // zmienna do przechowywania liczby wpisów w historii

bool Check_temp(double temp_value, char unit_type) { //Funkcja do sprawdzania czy temperatura nie jest ponizej zera absolutnego
	//Sprawdzanie czy temperatura nie jest ponizej zera absolutnego
	switch (unit_type) { //Switch do wyboru decyzji żeby sprawdzić odpowiednią temperaturę
		//Do danej decyzji sprawdzamy czy nie zrobił użytkownik błedu
	case 'F': {
		if (temp_value < -459.67) {
			cout << "Error: Temperature below absolute zero!" << endl;
			return false;
		}
		break;
	}
	case 'C': {
		if (temp_value < -273.15) {
			cout << "Error: Temperature below absolute zero!" << endl;
			return false;
		}
		break;
	}
	case 'K': {
		if (temp_value < 0) {
			cout << "Error: Temperature below absolute zero!" << endl;
			return false;
		}
		break;
	}
	default: {
		cout << "Unknown unit type!" << endl;
		return false;
	}
	}
	return true; //Zwracanie prawdy jeśli temperatura jest powyżej zera absolutnego
}
void Save_to_history(double temperature1, char degreeType1, double temperature2, char degreeType2) {
	if (g_Data_Center < 100) {
		g_table_history[g_Data_Center] = temperature1;
		g_table_history[g_Data_Center + 1] = temperature2;
		g_table_units[g_Data_Center] = degreeType1;
		g_table_units[g_Data_Center + 1] = degreeType2;
		g_Data_Center += 2;
	}
	else { 
		cout << "Conversion history is full!" << endl;
	}
}
double Fahr_Celsius(double fahr) {

	return (fahr - 32.0) * 5.0 / 9.0;
}
void Fahr_Celsius_option(){
	double fahr;
	cout << "Enter temperature in Fahrenheit: ";
	cin >> fahr;
	if (Check_temp(fahr, 'F') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróć mi błąd
	}
	double celsius = Fahr_Celsius(fahr);
	cout << fahr << "F is " << celsius << "C" << endl;
	//Zapis do historii
	Save_to_history(fahr, 'F', celsius, 'C');
}
double Fahr_Kelvin(double fahr) {
	return (fahr - 32.0) * 5.0 / 9.0 + 273.15;
}
void Fahr_Kelvin_option() {
	double fahr;
	cout << "Enter temperature in Fahrenheit: ";
	cin >> fahr;
	if (Check_temp(fahr, 'F') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróć mi błąd
	}
	double kelvin = Fahr_Kelvin(fahr);
	cout << fahr << "F is " << kelvin << "K" << endl;
	//Zapis do historii
	Save_to_history(fahr, 'F', kelvin, 'K');
}
double Celsium_Fahr(double celsius) {
	return (celsius * 9.0 / 5.0) + 32.0;
}
void Celsium_Fahr_option() {
	double celsius;
	cout << "Enter temperature in Celsius: ";
	cin >> celsius;
	if (Check_temp(celsius, 'C') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróć mi błąd
	}
	double fahr = Celsium_Fahr(celsius);
	cout << celsius << "C is " << fahr << "F" << endl;
	//Zapis do historii
	Save_to_history(celsius, 'C', fahr, 'F');
}
double Celsius_Kelv(double celsius) {
	return celsius + 273.15;
}
void Celsius_Kelv_option() {
	double celsius;
	cout << "Enter temperature in Celsius: ";
	cin >> celsius;
	if (Check_temp(celsius, 'C') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróć mi błąd
	}
	double kelvin = Celsius_Kelv(celsius);
	cout << celsius << "C is " << kelvin << "K" << endl;
	//Zapis do historii
	Save_to_history(celsius, 'C', kelvin, 'K');
}
double Kelv_cels(double kelvin) {
	return kelvin - 273.15;
}
void Kelv_cels_option() {
	double kelvin;
	cout << "Enter temperature in Kelvin: ";
	cin >> kelvin;
	if (Check_temp(kelvin, 'K') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróć mi błąd
	}
	double celsius = Kelv_cels(kelvin);
	cout << kelvin << "K is " << celsius << "C" << endl;
	//Zapis do historii
	Save_to_history(kelvin, 'K', celsius, 'C');
}
double Kelvin_Fahr(double kelvin) {
	return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}
void Kelvin_Fahr_option() {
	double kelvin;
	cout << "Enter temperature in Kelvin: ";
	cin >> kelvin;
	if (Check_temp(kelvin, 'K') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróć mi błąd
	}
	double fahr = Kelvin_Fahr(kelvin);
	cout << kelvin << "K is " << fahr << "F" << endl;
	//Zapis do historii
	Save_to_history(kelvin, 'K', fahr, 'F');
}
void show_menu_history(){
	cout << "Conversion History:" << endl;
	cout << "------------------------" << endl;
	cout << "Celsius (C)" << endl;
	cout << "Fahrenheit (F)" << endl;
	cout << "Kelvin (K)" << endl;
	cout << "All (A)" << endl;
}
void show_History() {
	if (g_Data_Center == 0) {
		cout << "No entries in history." << endl;
		return;
	}
	else {
		int index = 1, counter = 0;

		show_menu_history();
		int deccision;
		cout << "Enter your decision: ";
		cin >> deccision;
		system("cls"); // czyści ekran konsoli
		switch (deccision) {
			case 1: {
				for (int i = 0; i < g_Data_Center; i += 2) { //Iteracja przez historię
					if (g_table_units[i] == 'C') { //Sprawdzenie czy jednostka to Celsium
						cout << index++ << ". " << g_table_history[i] << "C -> " << g_table_history[i + 1] << g_table_units[i + 1] << endl; //Wyświetlanie wpisu historii
						counter++;
					}
				}
				break;
			}
			case 2: {
				for (int i = 0; i < g_Data_Center; i += 2) {
					if (g_table_units[i] == 'F') {
						cout << index++ << ". " << g_table_history[i] << "F -> " << g_table_history[i + 1] << g_table_units[i + 1] << endl;
						counter++;
					}
				}
				break;
			}
			case 3: {
				for (int i = 0; i < g_Data_Center; i += 2) {
					if (g_table_units[i] == 'K') {
						cout << index++ << ". " << g_table_history[i] << "K -> " << g_table_history[i + 1] << g_table_units[i + 1] << endl;
						counter++;
					}
				}
				break;
			}
			case 4: {
				for (int i = 0; i < g_Data_Center; i += 2) {
					cout << index++ << ". " << g_table_history[i] << g_table_units[i] << " -> " << g_table_history[i + 1] << g_table_units[i + 1] << endl;
					counter++;
				}
				break;
			}
		}
	}
}
void show_All_History() {
	if (g_Data_Center == 0) {
		cout << "No entries in history." << endl;
		return;
	}
	else {
		for (int i = 0; i < g_Data_Center; i += 2) {
			cout << (i / 2) + 1 << ". " << g_table_history[i] << g_table_units[i] << " -> " << g_table_history[i + 1] << g_table_units[i + 1] << endl;
		}
	}
}
void deleteRecords() {
	if (g_Data_Center == 0) {
		cout << "No entries in history to delete." << endl;
		return;
	}
	else {
		show_All_History();

		int recordNumber;
		cout << "Enter the record number to delete (or 0 to cancel): ";
		while (true) {
			cin >> recordNumber;
			if (recordNumber < 0 || recordNumber >= g_Data_Center / 2) { //Sprawdzanie czy numer rekordu jest prawidłowy
				cout << "Invalid record number. Please try again: "; //Komunikat o błędzie
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignoruj poprzednie wejście1
			}
			else {
				break;
			}
		}
		//usuwanie rekordu
		for (int i = (recordNumber * 2) - 2; i < g_Data_Center - 2; i++) { // Przesuwanie wpisów historii
			g_table_history[i] = g_table_history[i + 2]; // Przesuwanie wpisów historii
			g_table_units[i] = g_table_units[i + 2]; // Przesuwanie jednostek
		}
		g_Data_Center -= 2; // Zmniejszenie liczby wpisów w historii
		cout << "Record " << recordNumber << " deleted successfully." << endl;
	}
}
void ModifyRecord() {
	if (g_Data_Center == 0) {//Sprawdzanie czy historia jest pusta
		cout << "No conversion records to modify." << endl; //Komunikat o braku wpisów
	}
	else {
		show_All_History(); // Wyświetlanie całej historii

		int recordNumber = 0; 
		cout << "Enter the record number to modify (or 0 to cancel): ";
		while (true) {
			cin >> recordNumber;
			if (recordNumber < 0 || recordNumber >= g_Data_Center / 2) { //Sprawdzanie czy numer rekordu jest prawidłowy
				cout << "Invalid record number. Please try again: "; //Komunikat o błędzie
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignoruj poprzednie wejście1
			}
			else {
				break;
			}
			float newtemperature; // Nowa temperatura
			char newunit; // Nowa jednostka
			char newdegreeType1; // Nowy typ stopni
			cout << "What is the new temperature degree type (C/F/K): ";
			cin >> newdegreeType1;
			newdegreeType1 = toupper(newdegreeType1); // Zmiana na wielką literę
			switch (newdegreeType1) { //Switch do wyboru decyzji żeby sprawdzić odpowiednią temperaturę
			case 'F': {
				cout << "Enter new temperature in Fahrenheit: ";
				cin >> newtemperature; // Pobranie nowej temperatury
				g_table_history[(recordNumber - 1) * 2] = newtemperature; // Zmiana temperatury w historii
				g_table_units[(recordNumber - 1) * 2] = 'F'; // Zmiana jednostki w historii
				cout << "Conver to (C/K): "; // Pobranie nowego typu stopni
				cin >> newdegreeType1; // Pobranie nowego typu stopni
				newdegreeType1 = toupper(newdegreeType1); // Zmiana na wielką literę
				if (newdegreeType1 == 'C') {
					double celsius = Fahr_Celsius(newtemperature);
					g_table_history[(recordNumber - 1) * 2 + 1] = celsius; // Zmiana temperatury w historii
					g_table_units[(recordNumber - 1) * 2 + 1] = 'C'; // Zmiana jednostki w historii
				}
				else if (newdegreeType1 == 'K') {
					double kelvin = Fahr_Kelvin(newtemperature);
					g_table_history[(recordNumber - 1) * 2 + 1] = kelvin; // Zmiana temperatury w historii
					g_table_units[(recordNumber - 1) * 2 + 1] = 'K'; // Zmiana jednostki w historii
				}
				else {
					cout << "Invalid degree type!" << endl; // Komunikat o błędzie
				}
			}
			case 'C': {
				cout << "Enter new temperature in Celsius: ";
				cin >> newtemperature;
				g_table_history[(recordNumber - 1) * 2] = newtemperature; // Zmiana temperatury w historii
				g_table_units[(recordNumber - 1) * 2] = 'C'; // Zmiana jednostki w historii
				cout << "Conver to (F/K): "; // Pobranie nowego typu stopni
				cin >> newdegreeType1;
				newdegreeType1 = toupper(newdegreeType1); // Zmiana na wielką literę
				if (newdegreeType1 == 'F') { 
					double fahr = Celsium_Fahr(newtemperature);
					g_table_history[(recordNumber - 1) * 2 + 1] = fahr; // Zmiana temperatury w historii
					g_table_units[(recordNumber - 1) * 2 + 1] = 'F'; // Zmiana jednostki w historii
				}
				else if (newdegreeType1 == 'K') {
					double kelvin = Celsius_Kelv(newtemperature);
					g_table_history[(recordNumber - 1) * 2 + 1] = kelvin; // Zmiana temperatury w historii
					g_table_units[(recordNumber - 1) * 2 + 1] = 'K'; // Zmiana jednostki w historii
				}
				else {
					cout << "Invalid degree type!" << endl;
				}
			}
			case 'K': {
				cout << "Enter new temperature in Kelvin: ";
				cin >> newtemperature;
				g_table_history[(recordNumber - 1) * 2] = newtemperature; // Zmiana temperatury w historii
				g_table_units[(recordNumber - 1) * 2] = 'K'; // Zmiana jednostki w historii
				cout << "Conver to (C/F): ";
				cin >> newdegreeType1;
				newdegreeType1 = toupper(newdegreeType1); // Zmiana na wielką literę
				if (newdegreeType1 == 'C') {
					double celsius = Kelv_cels(newtemperature); // Zmiana temperatury w historii
					g_table_history[(recordNumber - 1) * 2 + 1] = celsius; // Zmiana temperatury w historii
					g_table_units[(recordNumber - 1) * 2 + 1] = 'C'; // Zmiana jednostki w historii
				}
				else if (newdegreeType1 == 'F') {
					double fahr = Kelvin_Fahr(newtemperature);
					g_table_history[(recordNumber - 1) * 2 + 1] = fahr; // Zmiana temperatury w historii
					g_table_units[(recordNumber - 1) * 2 + 1] = 'F'; // Zmiana jednostki w historii
				}
			}
			default: {
				cout << "Invalid degree type!" << endl;
			}

				   break;
			}
		}
	}
}
void Full_History_RandomValues() {

}