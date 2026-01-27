#ifndef HEADERFILE_H // Zabezpieczenie przed wielokrotnym dołączeniem
#define HEADERFILE_H 
/*Pliki headerFile.h przechowuje tylko zawijmy to wywoływacze funkcji które mają ciało w innym pliku. To jest tak samo jakbyś miał wołać na impreze do kumpla gdzieś inndziej*/

// Deklaracje zmiennych globalnych (extern oznacza: szukaj ich w pliku .cpp)
extern double g_table_history[100]; // tablica do przechowywania historii konwersji
extern char g_table_units[100]; // tablica do przechowywania jednostek konwersji
extern int g_Data_Center; // zmienna do przechowywania liczby wpisów w historii

// Prototypy funkcji 
bool Check_temp(double temp_value, char unit_type); // Funkcja do sprawdzania czy temperatura nie jest ponizej zera absolutnego
double get_safedouble(); //Deklaracja funkcji do pobierania bezpiecznej liczby zmiennoprzecinkowej
void Save_to_history(double temperature1, char degreeType1, double temperature2, char degreeType2); // Funkcja do zapisywania konwersji do historii
 
// Funkcje konwersji
double Fahr_Celsius(double fahr); //Funkcja do konwersji z F na C
double Fahr_Kelvin(double fahr); //Funkcja do konwersji z F na K
double Celsium_Fahr(double celsius); //Funkcja do konwersji z C na F
double Celsius_Kelv(double celsius); //Funkcja do konwersji z C na K
double Kelv_cels(double kelvin); //Funkcja do konwersji z K na C
double Kelvin_Fahr(double kelvin); //Funkcja do konwersji z K na F

// Funkcje obsługi menu
void Fahr_Celsius_option();	//Funkcja obsługi opcji F na C
void Fahr_Kelvin_option(); //Funkcja obsługi opcji F na K
void Celsium_Fahr_option(); //Funkcja obsługi opcji C na F
void Celsius_Kelv_option(); //Funkcja obsługi opcji C na K
void Kelv_cels_option(); //Funkcja obsługi opcji K na C
void Kelvin_Fahr_option(); //Funkcja obsługi opcji K na F
void podzielne_przez_5(); // Funkcja do sprawdzania podzielnego przez 


// Funkcje historii
void show_menu_history(); //Funkcja do wyświetlania menu historii
void show_History(); //Funkcja do wyświetlania historii
void show_All_History(); //Funkcja do wyświetlania całej historii
void deleteRecords(); //Funkcja do usuwania rekordu z historii
void ModifyRecord(); //Funkcja do modyfikowania rekordu w historii
void Fill_History_Random_Values(); //Funkcja do wypełniania historii losowymi wartościami

//Zabezpiecznie do pobierania bezpiecznej liczby zmiennoprzecinkowej


#endif