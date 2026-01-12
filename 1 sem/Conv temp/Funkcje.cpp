#include <iostream>
#include <limits>
#include <random>
#include <stdlib.h>
#include <time.h>   // Potrzebne do time(nullptr)
#include <limits> // <-- To jest kluczowe dla numeric_limits
#include "headerFile.h" // Musimy do³¹czyæ nasz nag³ówek!
using namespace std;
// Definicje zmiennych globalnych rezerwacja pamiêci dla nich
double g_table_history[100]; // tablica do przechowywania historii konwersji
char g_table_units[100]; // tablica do przechowywania jednostek konwersji
int g_Data_Center = 0; // zmienna do przechowywania liczby wpisów w historii

bool Check_temp(double temp_value, char unit_type) { //Funkcja do sprawdzania czy temperatura nie jest ponizej zera absolutnego
	//Sprawdzanie czy temperatura nie jest ponizej zera absolutnego
	switch (unit_type) { //Switch do wyboru decyzji ¿eby sprawdziæ odpowiedni¹ temperaturê
		//Do danej decyzji sprawdzamy czy nie zrobi³ u¿ytkownik b³edu
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
	return true; //Zwracanie prawdy jeœli temperatura jest powy¿ej zera absolutnego
}
double get_safedouble() {
	double value; // Deklaracja zmiennej do przechowywania wartoœci
	while (true) {
		cin >> value; // Pobranie wartoœci od u¿ytkownika
		if (cin.fail()) { //Sprawdzanie czy nie wpisano z³ej warotœci typu liczba = cyfra
			cin.clear(); //czyszczenie cina
			cin.ignore(numeric_limits<streamsize> ::max(), '\n');
			cout << "Invalid input. Please enter a valid number: "; //Komunikat o b³êdzie
		}
		else {
			cin.ignore(numeric_limits<streamsize> ::max(), '\n'); //Ignorowanie reszty linii, inaczej czyœci dalsz¹ czeœæ lini typu 12rahuj to masz tylko 12
			return value; //zwraca value
		}
	}
} //Deklaracja funkcji do pobierania bezpiecznej liczby zmiennoprzecinkowej

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
void Fahr_Celsius_option() {
	double fahr;
	cout << "Enter temperature in Fahrenheit: ";
	fahr = get_safedouble(); //zabezpieczenie do popbierania odpowiedniej wartoœci
	if (Check_temp(fahr, 'F') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróæ mi b³¹d
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
	fahr = get_safedouble(); //zabezpieczenie do popbierania odpowiedniej wartoœci
	if (Check_temp(fahr, 'F') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróæ mi b³¹d
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
	celsius = get_safedouble(); //zabezpieczenie do popbierania odpowiedniej wartoœci
	if (Check_temp(celsius, 'C') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróæ mi b³¹d
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
	celsius = get_safedouble(); //zabezpieczenie do popbierania odpowiedniej wartoœci
	if (Check_temp(celsius, 'C') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróæ mi b³¹d
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
	kelvin = get_safedouble(); //zabezpieczenie do popbierania odpowiedniej wartoœci
	if (Check_temp(kelvin, 'K') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróæ mi b³¹d
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
	kelvin = get_safedouble(); //zabezpieczenie do popbierania odpowiedniej wartoœci
	if (Check_temp(kelvin, 'K') == false) {
		cout << "Conversion aborted due to invalid temperature (Not in range)." << endl;
		return; //Zwróæ mi b³¹d
	}
	double fahr = Kelvin_Fahr(kelvin);
	cout << kelvin << "K is " << fahr << "F" << endl;
	//Zapis do historii
	Save_to_history(kelvin, 'K', fahr, 'F');
}
void show_menu_history() {
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
		int index = 1, counter = 0; //Inicjalizacja zmiennych do numeracji i liczenia wpisów11

		show_menu_history();
		int deccision;
		cout << "Enter your decision: ";
		cin >> deccision;
		system("cls"); // czyœci ekran konsoli
		switch (deccision) {
		case 1: {
			for (int i = 0; i < g_Data_Center; i += 2) { //Iteracja przez historiê
				if (g_table_units[i] == 'C') { //Sprawdzenie czy jednostka to Celsium
					cout << index++ << ". " << g_table_history[i] << "C -> " << g_table_history[i + 1] << g_table_units[i + 1] << endl; //Wyœwietlanie wpisu historii
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
			recordNumber = get_safedouble(); //Pobieranie bezpiecznej liczby
			if (recordNumber < 0 || recordNumber >= g_Data_Center / 2) { //Sprawdzanie czy numer rekordu jest prawid³owy
				cout << "Invalid record number. Please try again: "; //Komunikat o b³êdzie
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignoruj poprzednie wejœcie1
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
		show_All_History(); // Wyœwietlanie ca³ej historii
		cout << "Enter the record number to modify (or 0 to cancel): ";
		int recordNumber;
		cin >> recordNumber;
		double new_temperature;
		char new_degree_type, convert_to_type;
		cout << "What is the new temperature degree type? (F/C/K): ";
		cin >> new_degree_type;
		new_degree_type = toupper(new_degree_type);
		switch (new_degree_type) {
		case 'F': {
			cout << "Enter the new temperature in Fahrenheit: ";
			new_temperature = get_safedouble(); //zabezpieczenie do popbierania odpowiedniej wartoœci
			if (Check_temp(new_temperature, 'F') == false) {
				cout << "Modification aborted due to invalid temperature (Not in range)." << endl;
				return; //Zwróæ mi b³¹d
			}
			cout << "Convert to which degree type? (C/K): ";
			cin >> convert_to_type;
			convert_to_type = toupper(convert_to_type);
			if (convert_to_type == 'C') {
				double converted_temp = Fahr_Celsius(new_temperature);
				g_table_history[(recordNumber - 1) * 2] = new_temperature;
				g_table_units[(recordNumber - 1) * 2] = 'F';
				g_table_history[(recordNumber - 1) * 2 + 1] = converted_temp;
				g_table_units[(recordNumber - 1) * 2 + 1] = 'C';
				cout << "Record modified successfully." << endl;
			}
			else if (convert_to_type == 'K') {
				double converted_temp = Fahr_Kelvin(new_temperature);
				g_table_history[(recordNumber - 1) * 2] = new_temperature;
				g_table_units[(recordNumber - 1) * 2] = 'F';
				g_table_history[(recordNumber - 1) * 2 + 1] = converted_temp;
				g_table_units[(recordNumber - 1) * 2 + 1] = 'K';
				cout << "Record modified successfully." << endl;
			}
			else {
				cout << "Invalid degree type!" << endl;
			}
			break;
		}
		case 'C': {
			cout << "Enter the new temperature in Celsius: ";
			new_temperature = get_safedouble(); //zabezpieczenie do popbierania odpowiedniej wartoœci
			if (Check_temp(new_temperature, 'C') == false) {
				cout << "Modification aborted due to invalid temperature (Not in range)." << endl;
				return; //Zwróæ mi b³¹d
			}
			cout << "Convert to which degree type? (F/K): ";
			cin >> convert_to_type;
			convert_to_type = toupper(convert_to_type);
			if (convert_to_type == 'F') {
				double converted_temp = Celsium_Fahr(new_temperature);
				g_table_history[(recordNumber - 1) * 2] = new_temperature;
				g_table_units[(recordNumber - 1) * 2] = 'C';
				g_table_history[(recordNumber - 1) * 2 + 1] = converted_temp;
				g_table_units[(recordNumber - 1) * 2 + 1] = 'F';
				cout << "Record modified successfully." << endl;
			}
			else if (convert_to_type == 'K') {
				double converted_temp = Celsius_Kelv(new_temperature);
				g_table_history[(recordNumber - 1) * 2] = new_temperature;
				g_table_units[(recordNumber - 1) * 2] = 'C';
				g_table_history[(recordNumber - 1) * 2 + 1] = converted_temp;
				g_table_units[(recordNumber - 1) * 2 + 1] = 'K';
				cout << "Record modified successfully." << endl;
			}
			else {
				cout << "Invalid degree type!" << endl;
			}
			break;

		}
		case 'K': {
			cout << "Enter the new temperature in Kelvin: ";
			new_temperature = get_safedouble(); //zabezpieczenie do popbierania odpowiedniej wartoœci
			if (Check_temp(new_temperature, 'K') == false) {
				cout << "Modification aborted due to invalid temperature (Not in range)." << endl;
				return; //Zwróæ mi b³¹d
			}
			cout << "Convert to which degree type? (C/F): ";
			cin >> convert_to_type;
			convert_to_type = toupper(convert_to_type);
			if (convert_to_type == 'C') {
				double converted_temp = Kelv_cels(new_temperature);
				g_table_history[(recordNumber - 1) * 2] = new_temperature;
				g_table_units[(recordNumber - 1) * 2] = 'K';
				g_table_history[(recordNumber - 1) * 2 + 1] = converted_temp;
				g_table_units[(recordNumber - 1) * 2 + 1] = 'C';
				cout << "Record modified successfully." << endl;
			}
			else if (convert_to_type == 'F') {
				double converted_temp = Kelvin_Fahr(new_temperature);
				g_table_history[(recordNumber - 1) * 2] = new_temperature;
				g_table_units[(recordNumber - 1) * 2] = 'K';
				g_table_history[(recordNumber - 1) * 2 + 1] = converted_temp;
				g_table_units[(recordNumber - 1) * 2 + 1] = 'F';
				cout << "Record modified successfully." << endl;
			}
			else {
				cout << "Invalid degree type!" << endl;
			}
			break;

		}
		default: {
			cout << "Invalid degree type!" << endl;
			break;
		}
		}
	}
}
void Fill_History_Random_Values() {
	if (g_Data_Center >= 100) {
		cout << "Conversion history is full!" << endl;
		return;
	}
	int recordsToAdd;
	cout << "Enter the number of random records to add (max " << (100 - g_Data_Center) / 2 << "): ";
	cin >> recordsToAdd;

	if (recordsToAdd <1 || recordsToAdd >(100 - g_Data_Center) / 2) { // Sprawdzanie czy liczba rekordów jest prawid³owa
		cout << "Invalid number of records." << endl;
		return;
	}

	if (g_Data_Center + recordsToAdd > 100) { // Sprawdzanie czy dodanie rekordów przekroczy limit
		int possibleToAdd = (100 - g_Data_Center) / 2; // Obliczanie ile rekordów mo¿na dodaæ
		cout << "Not enough space in history. Can only add " << possibleToAdd << " records." << endl;
		cout << "Generating " << possibleToAdd << "instead (y/n)?";
		char choice;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			recordsToAdd = possibleToAdd;
		}
		else {
			return;
		}
	}
	srand(time(nullptr)); // Inicjalizacja generatora liczb losowych
	for (int i = 0; i < recordsToAdd; i++) {
		int randomtemperature;
		double converted_temp;
		double temperature;
		char degreeType;
		char convertToType;

		int randomchoice = rand() % 3; // Losowy wybór jednostki pocz¹tkowej
		if (randomchoice == 0) { //Celsium
			degreeType = 'C';
		}
		else if (randomchoice == 1) { //Fahrenheita
			degreeType = 'F';
		}
		else { //Kelvina
			degreeType = 'K';
		}
		switch (degreeType) {
		case 'F': {
			randomtemperature = rand() % 1000 - 459; // Losowa temperatura w zakresie od -459 do 540
			temperature = static_cast <float> (randomtemperature); // Konwersja na double
			converted_temp = (rand() % 2 == 0) ? Fahr_Celsius(temperature) : Fahr_Kelvin(temperature); // Losowy wybór jednostki docelowej
			convertToType = (degreeType == 'C') ? Fahr_Celsius(temperature) : Fahr_Kelvin(temperature); // Losowy wybór jednostki docelowej
			break;
		}
		case 'C': {
			randomtemperature = rand() % 500 - 273; // Losowa temperatura w zakresie od -273 do 226
			temperature = static_cast <float> (randomtemperature); // Konwersja na double
			converted_temp = (rand() % 2 == 0) ? Celsium_Fahr(temperature) : Celsius_Kelv(temperature); // Losowy wybór jednostki docelowej
			convertToType = (degreeType == 'F') ? Celsium_Fahr(temperature) : Celsius_Kelv(temperature); // Losowy wybór jednostki docelowej
			break;
		}
		case 'K': {
			randomtemperature = rand() % 500; // Losowa temperatura w zakresie od 0 do 499
			temperature = static_cast <float> (randomtemperature); // Konwersja na double
			converted_temp = (rand() % 2 == 0) ? Kelv_cels(temperature) : Kelvin_Fahr(temperature); // Losowy wybór jednostki docelowej
			convertToType = (degreeType == 'C') ? Kelv_cels(temperature) : Kelvin_Fahr(temperature); // Losowy wybór jednostki docelowej
			break;
		}
		}
		Save_to_history(temperature, degreeType, convertToType, converted_temp);
	}
	cout << "Random records added successfully." << endl;
}