
using std::cout;
using std::cin;
using std::endl;
double g_table_history[100][2]; // tablica do przechowywania historii konwersji
int g_Data_Center = 0; // zmienna do przechowywania liczby wpisów w historii
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
static void Show_History(int filter_code) { // Telewizor do wyświetlania 
	cout << "Conversion History:" << endl; // nagłówek historii
	if (g_Data_Center == 0) { // sprawdzanie czy historia jest pusta
		cout << "No entries in history." << endl;
		return;
	}
	bool found_enteries = false; //zmienna do sprawdzania czy znaleziono wpisy


	for (int i = 0; i < g_Data_Center; i++) { // Pętlka jęzeli coś jest w hitsorii to wypisz na ekranie

		double result = g_table_history[i][0]; // pobieranie wyniku z historii
		int	unit_code = g_table_history[i][1]; // pobieranie kodu jednostki z historii

		if (unit_code == filter_code || filter_code == 4) {
			found_enteries = true; //znalezienie prawidłowego wpisu
			cout << "Entry " << i + 1 << ": " << result; // wyświetlanie numeru wpisu



			switch (unit_code) { //DO wyboru literki do tempperatyu
			case 1:
				cout << result  << "C" << endl; //endl to nowa linia zaś cała linijka pokazuje wynik
				//cout << i + 1 << ". " << g_table_history[i][0] << endl; // wyświetlanie wpisów historii
				break;
			case 2:
				cout << result  << "F" << endl;
				//cout << i + 1 << ". " << g_table_history[i][0] << endl; // wyświetlanie wpisów historii
				break;
			case 3:
				cout << result << "K" << endl;
				//cout << i + 1 << ". " << g_table_history[i][0] << endl; // wyświetlanie wpisów historii
				break;
			case 4:
				cout << "C" << endl;
				//cout << i + 1 << ". " << g_table_history[i][0] << endl; // wyświetlanie wpisów historii
				break;
			default:
				cout << "Unknown unit code" << endl;
				break;

			}

		}
	}
		if (!found_enteries) {
			cout << "No entries found for the specified filter." << endl;
		}
	
}

static bool Check_temp(double temp_value, int unit_type) { //Funkcja do sprawdzania czy temperatura nie jest ponizej zera absolutnego
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
		if (temp_value < -459.67) {
			cout << "Error: Temperature below absolute zero!" << endl;
			return false;
		}


		break;

	case 3:
		if (temp_value < -273.15) {
			cout << "Error: Temperature below absolute zero!" << endl;
			return false;
		}

		break;
	case 4:
		if (temp_value < -273.15) {
			cout << "Error: Temperature below absolute zero!" << endl;
		}

		break;
	case 5:
		if (temp_value < 0) {
			cout << "Error: Temperature below absolute zero!" << endl;
			return false;
		}
		break; //Zawsze musi być break w switch
	case 6:
		if (temp_value < 0) {
			cout << "Error: Temperature below absolute zero!" << endl;
			return false;
		}
		break;	//Zawsze musi być break w switch
	}
	return true; //Zwracanie prawdy jeśli temperatura jest powyżej zera absolutnego
}
static double Fahr_Celsius() {
	double fahr, celsius;
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
} //Działa//Działa
static double Fahr_Kelvin() {
	double fahr, kelvin;
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
		double kelvin = (fahr + 459.67) * 5.0 / 9.0;
		cout << fahr << "F" << "\t" << kelvin << "K" << endl;
		return kelvin;
	}
	return 0;
	/*
	if kelvin < 0{
		cout << "Error: Temperature below absolute zero!" << endl;

	}*/
}//Działa
static double Celsium_Fahr() {
	double fahr, celsius; // deklaracja zmiennych
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
		cout << celsius << "C" << "\t" << fahr << "F" << endl; // Wyświetlanie wartości
		return fahr; //Zwracanie wartości funkcji

	}
	return 0;
	/*
	if fahr < -459.67 {
		cout << "Error: Temperature below absolute zero!" << endl;*/
		//}
}//Działa
static double Celsius_Kelv() {
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
static double Kelv_cels() {
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
static double Kelvin_Fahr() {
	double kelvin, fahr;
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
		double fahr = kelvin * 9.0 / 5.0 - 459.67;
		cout << kelvin << "K" << "\t" << fahr << "F" << endl;
		return fahr;
	}

	return 0;
}