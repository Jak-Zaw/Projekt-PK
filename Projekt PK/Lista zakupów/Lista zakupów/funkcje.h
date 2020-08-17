#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef FUNKCJE_H
#define FUNKCJE_H



/**
Strukura "zakupy" opsiujaca dane tworzenia i odczytywania listy zakupow.
*/
typedef struct zakupy
{
	char produkt[100];
	int ilosc;
	struct zakupy* next;
} zakupy;


//1
/** Funckja dodaje nowy wezel do listy.
@param lista wsakznik na liste.
@param nowy_element nowy element listy.
*/
void dodaj_wezel(zakupy*& lista, zakupy* nowy_element);


/** Funkcja usuwa liste.
@param nowy_element wsakznik na liste.
*/
void clear(zakupy* nowy_element);


/** Funkcja zapisuje dane do pliku .txt dla trzech plikow .txt
@param adres lsity. 
*/
void zapis_do_pliku(zakupy** lista);


//2
/** Funkcja wyswietla dane z pliku .txt dla listy zakupow na dany dzien tygodnia.
*/
void wyswietl_liste_na_dany_dzien();


//3
/** Funkcja wyswietla dane z pliku .txt zawierajaca historie zakupow z danego dnia tygodnia.
*/
void wyswietl_historie_zakupow_z_danego_dnia();


//4
/** Funkcja wyswietla z pliku .txt wszystkie utworzone listy zakupow.
*/
void wyswietl_wszystkie_dane();


//5
/**Funkcja wyswietla odpowiedni komunikat dotyczacy opcji zwiazanej z wyswietlaniem listy zakupow w formacie .htm.
*/
void html();




#endif
