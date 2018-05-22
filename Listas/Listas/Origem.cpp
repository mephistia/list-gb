#include "Lista.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "");

	Lista<float> lista;
	lista.add_inicio(3.0f);
	lista.add_inicio(8.2f);
	lista.add_final(0.5f);
	lista.add_final(4.0f);
	lista.add_final(5.5f);
	lista.add_final(10.0f);
	lista.add_final(0.1f);
	lista.add_final(10.0f);
	lista.add_final(4.4f);

	cout << "Lista em ordem de adição: " << endl;

	lista.imprime_lista();

	cout << endl << "Lista em ordem ascendente (do menor para o maior):" << endl;
	lista.organizar();
	lista.imprime_lista();


	system("pause");
	return 0;
}