/** @file */

/*
PROGRAMOWANIE KOMPUTEROW

Projet na zaliczenie: Lista zakupow i historia zakupow.

*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include <cstring>
#include <cstdio>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif




typedef struct zakupy
{
	char produkt[100];
	int ilosc;
	struct zakupy* next;
} zakupy;


void dodaj_wezel(zakupy*& lista, zakupy* nowy_element)
{

	while (lista) lista = lista->next;
	(lista = nowy_element)->next = 0;
}

void clear(zakupy* nowy_element)
{

	zakupy* current = nowy_element;
	zakupy* next = nullptr;

	while (nullptr != current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}


//1
void zapis_do_pliku(zakupy** lista)
{
	setlocale(LC_CTYPE, "Polish");
	zakupy* nowy_element = (zakupy*)malloc(sizeof(zakupy));
	FILE* plik = NULL;
	FILE* plik2 = NULL;
	FILE* plik3 = NULL;
	FILE* html = NULL;

	char nazwa[50];//nazwa dnia tygodnia, dla bie¿¹cej listy.
	
	printf("Podaj nazwe dnia tygodnia.\nDla poniedzia³ku 'pn'\nDla wtorku'wt'\nDla œrody 'sr'\nDla czwartku 'cz'\nDla pi¹tku 'pt'\nDla soboty 'sb'\n");

	scanf_s("%49s", nazwa, 50);
	const char* txt = ".txt";
	strcat_s(nazwa, txt);
	puts(nazwa);

	char nazwa1[20];//nazwa dnia tygodnia dla historii danego dnia.
	strncpy_s(nazwa1, nazwa, 2);
	const char* txt1 = "1.txt";
	strcat_s(nazwa1, txt1);
	puts(nazwa1);
	
	char nazwa2[20];// nazwa dnia tyogdnia dla pliku html
	strncpy_s(nazwa2, nazwa, 2);
	const char* htm = ".htm";
	strcat_s(nazwa2, htm);
	puts(nazwa2);


	printf("\n");
	if (remove(nazwa) == 0 && remove(nazwa2) == 0)
		printf("Mo¿na rozpocz¹æ tworzenie listy.\n");
	

	char produkt[100];
	int ilosc;
	printf("'0' koñczy wprowadzanie.\n");


	do {
		printf("Podaj iloœæ: ");
		scanf_s("%d", &nowy_element->ilosc);
		printf("Podaj produkt: ");
		scanf_s("%99s", &nowy_element->produkt, 100);
		dodaj_wezel(*lista, nowy_element);



		fopen_s(&plik, nazwa, "a");
		fopen_s(&plik2, "all_data.txt", "a");
		fopen_s(&plik3, nazwa1, "a");
		fopen_s(&html, nazwa2, "a");
		fprintf(plik, "%d %s\n", nowy_element->ilosc, nowy_element->produkt);
		fprintf(plik2, "%d %s\n", nowy_element->ilosc, nowy_element->produkt);
		fprintf(plik3, "%d %s\n", nowy_element->ilosc, nowy_element->produkt);
		fprintf(html, "%d %s</p>\n", nowy_element->ilosc, nowy_element->produkt);

		fclose(plik);
		fclose(plik2);
		fclose(plik3);
		fclose(html);

	} while (nowy_element->ilosc != 0);
	printf("Koniec wprowadzania\n");
	return;
}


//2
void wyswietl_liste_na_dany_dzien()
{
	char nazwa[50];
	printf("Podaj nazwe dnia tygodnia.\nDla poniedzia³ku 'pn'\nDla wtorku'wt'\nDla œrody 'sr'\nDla czwartku 'czw'\nDla pi¹tku 'pt'\nDla soboty 'sob'\n");
	scanf_s("%49s", nazwa, 50);
	const char* txt = ".txt";
	strcat_s(nazwa, txt);
	puts(nazwa);
	printf("\n");


	FILE* test = NULL;
	const char buf_size = 111;
	char buf[buf_size];
	int liczba = 0;
	errno_t err = fopen_s(&test, nazwa, "r");

	if (err)
	{
		printf("Nie moge otworzyc pliku .txt do odczytu!\n");
	}

	if (strncmp(nazwa, "pn", 2) == 0) {
		printf("Lista zakupów dla poniedzia³ku.\n");
	}
	else if (strncmp(nazwa, "wt", 2) == 0) {
		printf("Lista zakupów dla wtorku.\n");
	}
	else if (strncmp(nazwa, "sr", 2) == 0) {
		printf("Lista zakupów dla œrody.\n");
	}
	else if (strncmp(nazwa, "cz", 2) == 0) {
		printf("Lista zakupów dla czwartku.\n");
	}
	else if (strncmp(nazwa, "pt", 2) == 0) {
		printf("Lista zakupów dla pi¹tku.\n");
	}
	else if (strncmp(nazwa, "sb", 2) == 0) {
		printf("Lista zakupów dla soboty.\n");
	}

	while (fgets(buf, buf_size, test))
	{
		printf("%s\n", buf);
	}

	fclose(test); /* zamknij plik */
	system("pause"); //zatrzymanie ekranu wraz z komunikatem
	return;
}



//3
void wyswietl_historie_zakupow_z_danego_dnia()
{
	char nazwa[50];
	printf("Podaj nazwe dnia tygodnia.\nDla poniedzia³ku 'pn'\nDla wtorku'wt'\nDla œrody 'sr'\nDla czwartku 'czw'\nDla pi¹tku 'pt'\nDla soboty 'sob'\n");
	scanf_s("%49s", nazwa, 50);
	const char* txt = "1.txt";
	strcat_s(nazwa, txt);
	puts(nazwa);
	printf("\n");


	FILE* test = NULL;
	const char buf_size = 100;
	char buf[buf_size];
	int liczba = 0;
	errno_t err = fopen_s(&test, nazwa, "r");

	if (err)
	{
		printf("Nie moge otworzyc pliku .txt do odczytu!\n");
	}

	if (strncmp(nazwa, "pn",2)==0) {
		printf("Lista zakupów dla poniedzia³ków.\n");
	}
	else if (strncmp(nazwa, "wt", 2)==0) {
		printf("Lista zakupów dla wtorków.\n");
	}
	else if (strncmp(nazwa, "sr", 2)==0) {
	printf("Lista zakupów dla œród.\n");
	}
	else if (strncmp(nazwa, "cz", 2)==0) {
		printf("Lista zakupów dla czwartków.\n");
	}
	else if (strncmp(nazwa, "pt", 2)==0) {
		printf("Lista zakupów dla pi¹tków.\n");
	}
	else if (strncmp(nazwa, "sb", 2)==0) {
		printf("Lista zakupów dla sobót.\n");
	}

	while (fgets(buf, buf_size, test))
	{
		printf("%s\n", buf);
	}

	fclose(test); /* zamknij plik */
	system("pause"); //zatrzymanie ekranu wraz z komunikatem
	return;
}

	//4
	void wyswietl_wszystkie_dane()
	{
		FILE* test = NULL;
		const char buf_size = 100;
		char buf[buf_size];
		int liczba = 0;
		errno_t err = fopen_s(&test, "all_data.txt", "r");

		if (err)
		{
			printf("Nie moge otworzyc pliku .txt do odczytu!\n");
		}


		while (fgets(buf, buf_size, test))
		{
			printf("%s", buf);
		}

		fclose(test); /* zamknij plik */
		system("pause"); //zatrzymanie ekranu wraz z komunikatem
		return;
	}

	//5
	void html()
	{
		printf("Przekierowanie do storny www znajduje sie w folderze 'Lista zakupów'\n\n\n");
		system("pause"); //zatrzymanie ekranu wraz z komunikatem
		return;
	}


