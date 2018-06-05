#include "Lista.h"
#include "Item.h"
#include "Amuleto.h"
#include "Arma.h"
#include "Consumivel.h"
#include "Pilha.h"
#include "Fila.h"
#include <time.h>



using namespace std;

int main() {
	setlocale(LC_ALL, "");

	srand(time(0));

	Fila<int> fila;

	

	cout << " Digite o n�mero de itera��es para a fila:   ";
	
	int n;
	cin >> n;

	cout << endl << " Come�ando a simula��o..." << endl;

	int chegando;
	int saindo;
	int *chegadas = new int[n];
	int *saidas = new int[n];

	for (int i = 0; i < n; i++) {
		chegando = rand() % 3 + 2;
		saindo = rand() % 2;

		chegadas[i] = chegando;
		saidas[i] = saindo;

		while (chegando > 0) {
			fila.push(1);
			chegando--;
		}

		while (saindo > 0) {
			fila.pop();
			saindo--;
		}

	}

	cout << " Simula��o finalizada!" << endl << " N�mero total de chegadas: ";
	int t = 0;
	for (int i = 0; i < n; i++) {
		t += chegadas[i];
	}
	cout << t << endl << " M�dia de chegadas: " << (t / n) << endl;
	cout << endl << endl << " N�mero total de sa�das: ";

	int t2 = 0;
	for (int i = 0; i < n; i++) {
		t2 += saidas[i];
	}

	int m = (t2 / n);

	cout << t2 << endl << " M�dia de sa�das: " << m  << endl << endl;

	system("pause");
	return 0;
}