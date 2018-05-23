#include "Lista.h"
#include "Item.h"
#include "Amuleto.h"
#include "Arma.h"
#include "Consumivel.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "");


	cout << endl << "Criando Itens..." << endl;
	Amuleto rubi;
	Arma cajadoFogo;
	Consumivel magiaPedra;
	Amuleto jade;
	Consumivel pocaoVida;

	rubi.setNome("Amuleto de Rubi");
	cajadoFogo.setNome("Cajado de Fogo");
	magiaPedra.setNome("Magia das Pedras");
	jade.setNome("Amuleto de Jade");
	pocaoVida.setNome("Poção da Vida");

	cout << endl << endl << "Itens criados!" << endl << "Criando a lista..." << endl;

	Lista<Item> bag;
	bag.add_final(rubi);
	bag.add_final(magiaPedra);
	bag.add_final(jade);
	bag.add_final(cajadoFogo);
	bag.add_final(pocaoVida);

	cout << endl << "Itens adicionados à nova lista!" << endl << endl << "Lista de Itens: " << endl << endl;
	bag.imprime_lista();

	cout << endl << "Organizando a lista..." << endl << endl << "Lista de Itens por ordem alfabética:" << endl << endl;
	bag.organizar();
	bag.imprime_lista();

	system("pause");
	return 0;
}