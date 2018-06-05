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

	

	cout << " Digite o número de iterações para a fila:   ";
	
	int n;
	cin >> n;

	cout << endl << " Começando a simulação..." << endl;

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

	cout << " Simulação finalizada!" << endl << " Número total de chegadas: ";
	int t = 0;
	for (int i = 0; i < n; i++) {
		t += chegadas[i];
	}
	cout << t << endl << " Média de chegadas: " << (t / n) << endl;
	cout << endl << endl << " Número total de saídas: ";

	int t2 = 0;
	for (int i = 0; i < n; i++) {
		t2 += saidas[i];
	}

	int m = (t2 / n);

	cout << t2 << endl << " Média de saídas: " << m  << endl << endl;

	system("pause");
	return 0;
}