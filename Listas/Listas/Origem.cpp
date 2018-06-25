#include "Lista.h"
#include "Item.h"
#include "Amuleto.h"
#include "Arma.h"
#include "Consumivel.h"
#include "Pilha.h"
#include "Fila.h"
#include <time.h>
#include <fstream>




using namespace std;


int main() {

	Lista<Item> lista;

	// criar variáveis pra cada dado
	int bda, bde, bvi;
	char nome[30], desc[30], tipo[30];

	Item *item;
	int qt = 3;
	item = new Item[qt];

	ifstream file("itens.dat");
	if (file) {
		cout << "Arquivo existe! Carregando..." << endl;

		// carregar arquivo
		while (file && !file.eof())
		{
			for (int i = 0; i < qt; i++) {
				file.read(reinterpret_cast<char*> (&bda), sizeof(int));				file.read(reinterpret_cast<char*> (&bde), sizeof(int));				file.read(reinterpret_cast<char*> (&bvi), sizeof(int));				file.read(reinterpret_cast<char*> (&nome), sizeof(char[30]));				file.read(reinterpret_cast<char*> (&desc), sizeof(char[30]));				file.read(reinterpret_cast<char*> (&tipo), sizeof(char[30]));

				// criar e colocar na lista
				item[i].criar(bvi, bda, bde, i, nome, desc, tipo);
				lista.add_final(item[i]);
			}
	

		
		}
		file.close();

	

	}

	else {
		file.close();

		// criar arquivo

		cout << "Criando arquivo..." << endl;

		char a[30];
		cout << "Escreva um nome de item para o item 0: ";

		for (int i = 0; i < 30; i++) {
			cin >> a[i];
			if (a[i] == '#') { // marcador de input
				break;
			}
		}
		cout << endl;

		char b[30] = "Blablabla#";
		char c[30] = "ItemGenerico#";
		char a1[30] = "Item1#";
		char b1[30] = "Blebleble#";
		char c1[30] = "ItemGenerico#";
		char a3[30] = "Item3#";
		char b3[30] = "Bliblibli#";
		char c3[30] = "ItemEspecial#";

		item[0].criar(10, 10, 10, 0, a,b, c);
		item[1].criar(11, 11, 11, 1, a1, b1, c1);
		item[2].criar(12, 12, 12, 2, a3, b3, c3);

		lista.add_final(item[0]);
		lista.add_final(item[1]);
		lista.add_final(item[2]);



	}

	cout << "Imprimindo dados..." << endl << endl;
	for (int i = 0; i < qt; i++) {
		// 
		for (int i = 0; i < 30; i++) {
			// imprimir nome
			cout << lista.get().getNome(i);
			if (lista.get().getNome(i) == '\0')
				break;
		}
		cout << ": ";
		for (int i = 0; i < 30; i++) {
			// imprimir descrição
			cout << lista.get().getDesc(i);
			if (lista.get().getDesc(i) == '\0')
				break;
		}
		cout << ". Tipo do item: ";
		for (int i = 0; i < 30; i++) {
			// imprimir tipo (teste para sem final \0)
			cout << lista.get().getTipo(i);
			
		}

		cout << "Bonus Dano: " << lista.get().getBonusDano() << " Bonus Defesa: " << lista.get().getBonusDefesa() << 
			"  Bonus Vida: " << lista.get().getBonusVida() << endl;

		lista.andar_frente();


	}


	// selecionar primeiro da lista
	lista.resetPos();

	cout << "Salvando arquivo..." << endl;

	ofstream arquivo;
	arquivo.open("itens.dat", ios::binary);

	if (!arquivo)
		cout << "Arquivo nao pode ser salvo!!" << endl;
	else
	{

		for (int i = 0; i < qt; i++) {

			// setar variaveis
			bda = lista.get().getBonusDano();
			bde = lista.get().getBonusDefesa(); 
			bvi = lista.get().getBonusVida();

			for (int i = 0; i < 30; i++) {

				nome[i] = lista.get().getNome(i);
				desc[i] = lista.get().getDesc(i);
				tipo[i] = lista.get().getTipo(i);
			}
			

			// salvar variaveis

			arquivo.write( reinterpret_cast<const char*> (&bda), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&bde), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&bvi), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&nome), sizeof(char[30]));
			arquivo.write(reinterpret_cast<const char*> (&desc), sizeof(char[30]));
			arquivo.write(reinterpret_cast<const char*> (&tipo), sizeof(char[30]));

			lista.andar_frente();

		}
		arquivo.close();

		cout << "Arquivo salvo com sucesso!" << endl;
	}

	system("pause");
	return 0;
}

