#include <iostream>
using namespace std;
int main() {
	double celsius, fahrenheit;
	cout << "Podaj temperature w stopniach Celsjusza: ";
	cin >> celsius;
	fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
	cout << "Temperatura w stopniach Fahrenheita: " << fahrenheit << endl;
	return 0;
}