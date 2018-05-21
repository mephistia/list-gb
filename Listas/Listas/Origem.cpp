#include "Lista.h"


using namespace std;

int main() {

	Lista<float> lista;
	lista.add_inicio(3.0f);
	lista.add_inicio(8.2f);
	lista.add_final(0.5f);
	lista.add_final(4.0f);

	lista.imprime_lista();

	system("pause");
	return 0;
}