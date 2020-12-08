#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
	// Poczatek gry - wybor liczby drzwi i wypisanie ich na ekranie
	int ile{};
	cout << "Ile drzwi: "; cin >> ile;

	int* drzwi = new int[ile]{}; // stworzenie tablicy licz o wielkosci "ile"

	srand(time(NULL));

	double punkty{}, licznik=1;
	string koniec{};
	while (koniec!="tak")
	{
		int gdzie_samochod = rand() % ile; // losowanie drzwi za ktorymi bedzie samochod

		cout << endl;
		for (int i = 0; i < ile; i++)
		{
			if (i % 5 == 0) cout << endl;
			cout << "Drzwi" << i + 1 << "\t";
		}

		// Wybor drzwi i otwarcie wszystkich drzwi z kozami oprocz drzwi wybranych przez gracza i drzwi wybranych przez Monty'ego
		int wybor{};
		cout << endl << endl << "Wybierz drzwi: "; cin >> wybor;
		wybor -= 1;
		int los{};


		if (wybor == gdzie_samochod) // warunek jesli gracz trafi od razu na samochod
		{
			while (true) // losowanie drzwi ktore Monty zostawi zamkniete
			{
				los = rand() % ile;

				if (los != wybor)
					break;
			}

			for (int i = 0; i < ile; i++) // wypisanie obecnego stanu gry (zamkniete wciaz beda drzwi wybrane przez gracza i Monty'ego)
			{
				if (i % 5 == 0) cout << endl;

				if (i == los)
					cout << setw(12) << "Drzwi" << i + 1 << "\t";
				else if (i == wybor)
					cout << setw(12) << "Wybrane_drzwi" << "\t";
				else
					cout << setw(12) << "Koza" << "\t";
			}
		}
		else // !!! jesli gracz nie trafi od razu na samochod to NIE MA LOSOWANIA, Monty otworzy drzwi z kozami i pozostawi drzwi z samochodem !!!
		{
			for (int i = 0; i < ile; i++) // wypisanie obecnego stanu gry (zamkniete wciaz beda drzwi wybrane przez gracza i drzwi z samochodem)
			{
				if (i % 5 == 0) cout << endl;

				if (i == gdzie_samochod)
					cout << setw(12) << "Drzwi" << i + 1 << "\t";
				else if (i == wybor)
					cout << setw(12) << "Wybrane_drzwi" << "\t";
				else
					cout << setw(12) << "Koza" << "\t";
			}
		}

		// Stay or Switch - czy zostajemy przy swoim oryginalnym wyborze, czy zmieniamy wybor na drzwi "wybrane" przez Monty'ego
		string odp{};
		cout << endl << endl << "Czy chcesz zmienic drzwi? [tak]/[nie]: "; cin >> odp;

		if (odp == "tak") // Wypisanie koncowego stanu gry i wypisanie komunikatu o wygranej lub przegranej
		{
			for (int i = 0; i < ile; i++)
			{
				if (i % 5 == 0) cout << endl;

				if (i == gdzie_samochod)
					cout << setw(12) << "Samochod" << "\t";
				else
					cout << setw(12) << "Koza" << "\t";
			}

			if (wybor == gdzie_samochod)
				cout << endl << "P R Z E G R A L E S ! ! !";
			else
			{
				cout << endl << "W Y G R A L E S ! ! !";
				punkty++;
			}
		}
		else if (odp == "nie")
		{
			for (int i = 0; i < ile; i++)
			{
				if (i % 5 == 0) cout << endl;

				if (i == gdzie_samochod)
					cout << setw(12) << "Samochod" << "\t";
				else
					cout << setw(12) << "Koza" << "\t";
			}

			if (wybor == gdzie_samochod)
			{
				cout << endl << "W Y G R A L E S ! ! !";
				punkty++;
			}
			else
				cout << endl << "P R Z E G R A L E S ! ! !";
		}

		cout << endl << "Stosunek wygranych gier do rozegranych gier: " << punkty << "/" << licznik << "\tInaczej: " << punkty / licznik;
		cout << endl << "Czy chcesz zakonczyc gre? [tak/nie]: "; cin >> koniec;
		system("cls");

		licznik++;
	}

	return 0;
}