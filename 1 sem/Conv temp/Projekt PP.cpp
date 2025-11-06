	#include <iostream>
	#include <stdlib.h>
using namespace std; //Check_temp function to verify temperature above absolute zero is the end version
	static bool Check_temp(int decision) {
		int Fahr_Celsius(int fahr);
		int Fahr_Kelvin(int fahr);
		int Celsium_Fahr(int celsius);
		int Celsius_Kelv(int celsius);
		int Kelv_cels(int kelvin);
		int Kelvin_Fahr(int kelvin);
		//Sprawdzanie czy temperatura nie jest ponizej zera absolutnego
		switch (decision) {
		case 1:
			int fahr;
			cout << "Provide temperature in Fahrenheit: ";
			cin >> fahr;
			if (fahr < -459.67) {
				cout << "Error: Temperature below absolute zero!" << endl;
				return false;
			}

		case 2:
			int fahr2;
			cout << "Provide temperature in Fahrenheit: ";
			cin >> fahr2;
			if (fahr2 < -459.67) {
				cout << "Error: Temperature below absolute zero!" << endl;
			}
			
			return false;
		case 3:
			int celsius;
			cout << "Provide temperature in Celsius: ";
			cin >> celsius;
			if (celsius < -273.15) {
				cout << "Error: Temperature below absolute zero!" << endl;
			}
			return false;
		case 4:
			int celsius2;
			cout << "Provide temperature in Celsius: ";
			cin >> celsius2;
			if (celsius2 < -273.15) {
				cout << "Error: Temperature below absolute zero!" << endl;
			}
			return false;
		case 5:
			int kelvin;
			cout << "Provide temperature in Kelvin: ";
			cin >> kelvin;
			if (kelvin < 0) {
				cout << "Error: Temperature below absolute zero!" << endl;
			}
			return false;
		case 6:
			int kelvin2;
			cout << "Provide temperature in Kelvin: ";
			cin >> kelvin2;
			if (kelvin2 < 0) {
				cout << "Error: Temperature below absolute zero!" << endl;
			}
			return false;

		}
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
		Check_temp(1);
		while (fahr <= limit) {

			double celsius = (fahr - 32) * 5.0 / 9.0;
			cout << fahr << "\t" << celsius << endl;
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
		while (fahr <= limit) {
			double kelvin = (fahr +459.67)*5.0/9.0;
			cout << fahr << "\t" << kelvin << endl;
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
		while (celsius <= limit) { // pêtla while
			double fahr = celsius * 9.0 / 5.0 + 32.0; // Konwersja Celsium na Fahrenheita
			cout << celsius << "\t" << fahr << endl; // Wyświetlanie wartości
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
		while (celsius <= limit) {
			double kelvin = celsius + 273.15;
			cout << celsius << "\t" << kelvin << endl;
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
		while (kelvin <= limit) {
			double celsius = kelvin - 273.15;
			cout << kelvin << "\t" << celsius << endl;
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
		while (kelvin <= limit) {
			double fahr = kelvin *9.0/5.0 - 459.67;
			cout << kelvin << "\t" << fahr << endl;
			return fahr;
		}

		return 0;
	}
	int main() {
		int prime = 1;
		while (prime == 1) {
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
			cout << "8.Exit" << endl;
			cout << "------------------------" << endl;
			cout << "Enter your decision (1-6): ";
			cin >> decision; // pobranie decyzji od u¿ytkownika
			//decyzje które kto chce convertować.
			switch (decision) {
			case 1:
				Check_temp(decision);
				Fahr_Celsius();
				break;
			case 2:
				Check_temp(decision);
				Fahr_Kelvin();
				break;
			case 3:
				Check_temp(decision);
				Celsium_Fahr();
				break;
			case 4:
				Check_temp(decision);
				Celsius_Kelv();
				break;
			case 5:
				Check_temp(decision);
				Kelv_cels();
				break;
			case 6:
				Check_temp(decision);
				Kelvin_Fahr();
				break;
			case 7:
				system("cls");
				break;


			case 8:
				cout << "Goodbye!" << endl;
				prime = 0;
				break;

			}
		}
		return 0;
	}
