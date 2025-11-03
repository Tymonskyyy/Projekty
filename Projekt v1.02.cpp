#include <iostream>
using namespace std;
static int Fahr_Celsius() {
	int fahr, celsius;
	int start, limit, step;

	cout << "Fahrenheit\tCelsius" << endl;
	cout << "------------------------" << endl;
	cout << "Provide grades";
	cin >> fahr;

	start = 0;    // pocz¹tkowa temperatura w skali Fahrenheita
	limit = 200; // przypis 200 do zmiennej limit
	step = 20;   // krok co 20 stopni
	while (fahr <= limit) {

		double celsius = (fahr - 32) * 5.0 / 9.0;
		cout << fahr << "\t" << celsius << endl;
		return celsius;
	}
	return 0;

}
static int Fahr_Kelvin() {
	int fahr, kelvin;
	int start, limit, step;

	cout << "Fahrenheit\tKelvin" << endl;
	cout << "------------------------" << endl;
	cout << "Provide grades";
	cin >> fahr;
	start = 0;    // pocz¹tkowa temperatura w skali Fahrenheita
	limit = 200; // przypis 200 do zmiennej limit
	step = 20;   // krok co 20 stopni
	while (fahr <= limit) {
		double kelvin = (fahr - 32) * 5.0 / 9.0 + 273.15;
		cout << fahr << "\t" << kelvin << endl;
		return kelvin;
	}
	return 0;

}
static int Celsium_Fahr() {
	int fahr, celsius; // deklaracja zmiennych
	int start, limit, step; // deklaracja zmiennych
	cout << "Celsium\tFahrenheit" << endl;
	cout << "------------------------" << endl;
	cout << "Provide grades";
	cin >> celsius;
	start = 0;    // pocz¹tkowa temperatura w skali Fahrenheita
	limit = 200; // przypis 200 do zmiennej limit
	step = 20;   // krok co 20 stopni
	while (celsius <= limit) { // pêtla while
		double fahr = celsius * 9.0 / 5.0 + 32.0; // Konwersja Celsium na Fahrenheita
		cout << celsius << "\t" << fahr << endl; // Wyświetlanie wartości
		return fahr; //Zwracanie wartości funkcji

	}
	return 0;
}
static int celsius_Clev() {
	int celsius;
	int kelvin;
	int start;
	int limit;
	int step;
	cout << "Celsius\tKelvin" << endl;
	cout << "------------------------" << endl;
	cout << "Provide grades";
	cin >> celsius;
	while (celsius <= limit) {
		double celsius = kelvin - 273.15;
		cout << celsius << "\t" << kelvin << endl;
		return kelvin;
	}
	return 0;
}
int main() {
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
	cout << "Enter your decision (1-6): ";
	cin >> decision; // pobranie decyzji od u¿ytkownika
	//decyzje które kto chce convertować.
	if (decision < 1 || decision>6) {
		cout << "Invalid decision. Please enter a number between 1 and 6." << endl;

		if (decision == 1) {
			Fahr_Celsius();
		}
		if (decision == 2) {
			Fahr_Kelvin();
		}
		if (decision == 3) {
			Celsium_Fahr(); // Do tego miejsca działa następny krok kolejna funkcja do zrobienia
		}
		if (decision == 4) {
			celsius_Clev();
		}
		if (decision == 5) {
			;//Kelv_cels();
		}
		if (decision == 6) {
			;//Kelvin_Fahr();
		}
	}

	return 0;


}