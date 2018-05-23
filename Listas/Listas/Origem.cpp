#include "Lista.h"
#include "Item.h"
#include "Amuleto.h"
#include "Arma.h"
#include "Consumivel.h"
#include "Pilha.h"



using namespace std;

int main() {
	setlocale(LC_ALL, "");

	Pilha<char> palavra;
	cout << "Digite uma palavra..." << endl;
	
	std::string p;
	cin >> p;
	
	for (int i = 0; i < p.size(); i++) {
		cout << "Letra: " << p[i] << endl;
		palavra.push(p[i]);
	}

	cout << endl << "Apagando pilha atual...." << endl << "Imprimindo palavra inversa com m�todo inverter..." << endl;
	palavra.inverter(p);

	cout << endl << "Apagando pilha atual..." << endl << "Verificando se a palavra � pal�ndromo..." << endl;
	if (palavra.palindromo(p)) {
		cout << endl << "A palavra � um pal�ndromo!" << endl;
	}
	else
		cout << endl << "A palavra N�O � um pal�ndromo." << endl;

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
	pocaoVida.setNome("Po��o da Vida");

	cout << endl << endl << "Itens criados!" << endl << "Criando a lista..." << endl;

	Lista<Item> bag;
	bag.add_final(rubi);
	bag.add_final(magiaPedra);
	bag.add_final(jade);
	bag.add_final(cajadoFogo);
	bag.add_final(pocaoVida);

	cout << endl << "Itens adicionados � nova lista!" << endl << endl << "Lista de Itens: " << endl << endl;
	bag.imprime_lista();

	cout << endl << "Organizando a lista..." << endl << endl << "Lista de Itens por ordem alfab�tica:" << endl << endl;
	bag.organizar();
	bag.imprime_lista();

	system("pause");
	return 0;
}