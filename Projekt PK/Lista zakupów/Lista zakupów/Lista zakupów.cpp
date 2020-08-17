/** @file */

/*
PROGRAMOWANIE KOMPUTEROW

Projet na zaliczenie: Lista zakupow i historia zakupow.

*/


#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <conio.h>

#include"funkcje.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


int main()
{

	
	setlocale(LC_ALL, "polish");
	zakupy* lista = NULL;
	int wybor;
	do {
		printf("[1] Zrób listę zakupów na dany dzień tygodnia.\n[2] Wyświetl listę zakupów na dany dzień tygodnia.\n[3] Wyświetl historię zakupów z danego dnia tygodnia.\n[4] Wyświetl całą hisotrię zakupów.\n[5] HTML\n[0] Koniec pracy.\n");

		scanf_s("%d", &wybor);

		switch (wybor)
		{
		case 1:
			zapis_do_pliku(&lista);
			clear(lista);
			break;
		case 2:
			wyswietl_liste_na_dany_dzien();
			break;
		case 3:
			wyswietl_historie_zakupow_z_danego_dnia();
			break;
		case 4:
			wyswietl_wszystkie_dane();
			break;
		case 5:
			html();
			break;
		case 0:
			printf("Udanych zakupow!\n");
			break;

		default: printf("Błąd wyboru!\n");
			break;
		}
	} while (wybor != 0);

	
	
	
}