#pragma once
#include "Nodo.h"
#include <iostream>

template <class T>
class Lista {

public:
	

	// construtor
	Lista<T>::Lista(){
		primeiro = NULL;
		ultimo = NULL;
		pos = NULL;
		tam = 0;
		cont = 0;
	
	}

	// destrutor
	Lista<T>::~Lista(){
	}
	// limpar a lista
	void Lista<T>::clear() {
		primeiro = NULL;
		primeiro->proximo = NULL;
		primeiro->anterior = NULL;
		ultimo = NULL;
		ultimo->proximo = NULL;
		ultimo->anterior = NULL;
		tam = 0;
	}

	// adiciona no inicio
	void Lista<T>::add_inicio(const T &dado1) {
		Nodo<T> *addIni = new Nodo<T>;
		addIni->dado = dado1; // atribui o dado

		// se a lista estiver vazia
		if (tam == 0) {
			addIni->proximo = NULL;
			addIni->anterior = NULL;
			primeiro = addIni;
			ultimo = addIni;
			pos = primeiro;
		}

		// inserir na frente da lista
		else {
			addIni->anterior = NULL; // anterior do primeiro � vazio
			primeiro->anterior = addIni; // o anterior do antigo "primeiro" � o novo adicionado
			addIni->proximo = primeiro; // o pr�ximo do adicionado � o antigo primeiro
			primeiro = addIni; // o primeiro agora � o adicionado na frente
		}
		
		// aumenta o contador do tamanho da lista
		tam++;
	}

	// adiciona no final
	void Lista<T>::add_final(const T &dado1) {
		Nodo<T> *addFim = new Nodo<T>;
		addFim->dado = dado1;

		// se a lista estiver vazia
		if (tam == 0) {
			addFim->anterior = NULL;
			addFim->proximo = NULL;
			primeiro = addFim;
			ultimo = addFim;
			pos = primeiro;
		}

		// inserir no fim da lista
		else {
			addFim->proximo = NULL; // o pr�ximo do �ltimo � vazio
			ultimo->proximo = addFim; // o pr�ximo do antigo �ltimo � o novo adicionado
			addFim->anterior = ultimo; // o anterior do novo � o antigo �ltimo
			ultimo = addFim; // agora o �ltimo � o novo
		}

		// aumenta tamanho da lista
		tam++;
	}


	// imprimir
	void Lista<T>::imprime_lista() {
		imprimir(primeiro);

		// imprimir iterativo:

		/*	temp = primeiro;
				int num = 0;

				cout << "Lista: " << endl

				while (temp != NULL) {
					cout << num << ": " << temp->dado << endl;
		}*/
	}

	// imprimir recursivo
	void Lista<T>::imprimir(Nodo<T> *nodo) { // mandar o primeiro como par�metro
		if (nodo != NULL) {
			cout << nodo->dado << endl;
			imprimir(nodo->proximo);
		}
		
	}


	// remover o item da posi��o atual (pos)
	void Lista<T>::remover_item() {

		// s� um item na lista
		if (pos->anterior == NULL && pos->proximo == NULL) {
			pos = NULL;
			primeiro = NULL;
			ultimo = NULL;
			tam--;
		}

		// incio da lista
		else if (pos->anterior == NULL) {
			pos->proximo->anterior = NULL;
			pos = pos->proximo;
			primeiro = pos;
			tam--;
		}

		// fim da lista
		else if (pos->proximo == NULL) {
			pos->anterior->proximo = NULL;
			pos = pos->anterior;
			ultimo = pos;
			tam--;
		}

		// meio da lista
		else {
			pos->anterior->proximo = pos->proximo;
			pos->proximo->anterior = pos->anterior;
			pos = pos->proximo;
			tam--;

		}
		
	}


	// selecionar o proximo da lista
	void Lista<T>::andar_frente() {
		if (pos->proximo != NULL)
		pos = pos->proximo; // a posi��o atual recebe a pr�xima posi��o se n�o for o �ltimo da lista
		else {
			// se for o �ltimo, aponta de volta para o primeiro
			pos = primeiro;
		}

	}

	// selecionar o item anterior da lista
	void Lista<T>::andar_tras() {
		if (pos->anterior != NULL)
		pos = pos->anterior;
		else {
			pos = ultimo;
		}
	}
	
	// busca iterativa
	//void Lista<T>::buscar(const T &dado1) {
	//	T dado = NULL;
	//	
	//	if (tam != 0) {

	//		for (int i = 0; i != tam; i++) {
	//			if (pos->dado == dado1) {
	//				dado = pos->dado; // copia o valor para a vari�vel que confirma a busca
	//				cout << "A busca encontrou um resultado! Item selecionado." << endl; // n�o pega itens duplicados
	//				break; // sai do loop, "pos" agora seleciona o item buscado
	//			}
	//			else
	//				andar_frente();
	//		}

	//		if (dado == NULL) { // se o valor n�o foi copiado
	//			cout << "A busca n�o encontrou um item correspondente."
	//		}
	//	}

	//}

	// busca recursiva
	int Lista<T>::buscar_r(const T &dado1, Nodo<T> *nodo) {
		if (cont == tam) {
			return 0;
		}

		if (nodo != NULL && cont != tam) {
			cont++; // aumenta o contador de ciclos de busca

			pos = nodo; // seleciona o nodo do par�metro
			if (nodo->dado == dado1) {
				cont = 0; // zera contador para pr�ximas buscas
				return 1;
			}
			else {
				return buscar_r(dado1, nodo->proximo); // vai selecionar o pr�ximo nodo
			}
		}
	}

	// buscar e deletar
	void Lista<T>::remover(const T dado) {
		if (buscar_r(dado, primeiro) == 1) {
			cout << "Item encontrado e selecionado!" << endl;
			cout << "Deletando..." << endl;
			remover_item();
			cout << "Item removido!" << endl;
			pos = primeiro;
			cout << "Item selecionado � o primeiro da lista: " << primeiro->dado << endl;
		}
		else {
			cout << "N�o existe item correspondente na lista." << endl;
			pos = primeiro;
			cout << "Item selecionado � o primeiro da lista: " << primeiro->dado << endl;


		}
	}


	// trocar dado
	void Lista<T>::trocar(Nodo<T> *x, Nodo<T> *y) {
		T temp = x->dado;
		x->dado = y->dado;
		y->dado = temp;
	}

	// nodo do final
	struct Nodo<T> *nodoFinal(Nodo<T> *nodo) {
		while (nodo && nodo->proximo) {
			nodo = nodo->proximo;
		}
		return nodo;
	}

	// nodos primeiro e �ltimo como refer�ncia
	Nodo<T> *dividir(Nodo<T> *a, Nodo<T> *b) {
		T x = b->dado;

		Nodo<T> *i = a->anterior;

		for (Nodo<T> *j = a; j != b; j = j->proximo) {
			if (j->dado <= x) {
				if (i == NULL) {
					i = a;
				}
				else {
					i = i->proximo;
				}

				trocar(i, j);
			}
		}

		if (i == NULL) {
			i = a;
		}
		else {
			i = i->proximo;
		}

		trocar(i, b); 
		return i;
	}

	// organizar recursivamente
	void sort_asc(Nodo<T> *a, Nodo<T> *b) {
		if (b != NULL && a != b && a != b->proximo) {
			Nodo<T> *p = dividir(a, b);
			sort_asc(a, p->anterior);
			sort_asc(p->proximo, b);
		}
	}

	// chamar a organiza��o
	void organizar() {
		Nodo<T> *n = nodoFinal(primeiro);
		sort_asc(primeiro, n);
	}

	

private:
	Nodo<T> *primeiro; // ponteiro que sempre aponta para o primeiro item da lista
	Nodo<T> *ultimo; // ponteiro que sempre aponta para o ultimo item da lista
	Nodo<T> *pos; // ponteiro da posi��o atual que estou percorrendo na lista (sempre posiciono no inicio da lista)
	Nodo<T> *temp; // ponteiro tempor�rio
	int tam, cont; // tamanho da lista e contador de busca
	

};
