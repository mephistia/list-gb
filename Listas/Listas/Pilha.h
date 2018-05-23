#pragma once
#include "Nodo.h"
#include <iostream>
#include <string>

template <class T>

class Pilha {

public:

	// construtor
	Pilha<T>::Pilha() {
		primeiro = NULL;
		ultimo = NULL;
		tam = 0;
		cont = 0;
	}

	// destrutor
	Pilha<T>::~Pilha() {

	}

	// limpar pilha existente
	void Pilha<T>::clear() {
		primeiro = NULL;
		ultimo = NULL;
		tam = 0;
	}

	// adicionar
	void Pilha<T>::push(const T &dado) {
		Nodo<T> *add = new Nodo<T>;
		add->dado = dado;

		// se a pilha estiver vazia
		if (tam == 0) {
			add->proximo = NULL;
			add->anterior = NULL;
			primeiro = add;
			ultimo = add;
		}

		// se tiver só 1 elemento
		else if (tam == 1) {
			add->proximo = NULL;
			ultimo->proximo = add;
			add->anterior = ultimo;
			ultimo = add;
		}
		// inserir no final
		else {
			add->proximo = NULL;
			ultimo->proximo = add;
			add->anterior = ultimo;
			ultimo = add;
		}

		// aumentar o tamanho
		tam++;
	}

	// retornar topo
	T Pilha<T>::top() {
		if (tam > 0)
		return ultimo->dado;
	}

	// remover topo
	void Pilha<T>::pop() {
		if (tam == 0) {
			cout << endl << "A pilha está vazia!" << endl;
		}
		else if (tam == 1) {
			clear();
		}
		else {
			ultimo->anterior->proximo = NULL; 
			ultimo = ultimo->anterior;
		

			tam--;
		}
		
	}


	// remover 1 pra outra pilha
	void Pilha<T>::undo() {
		if (tam > 0) {
			if (_undo == NULL) {
				_undo = new Pilha;
			}

			T dado = ultimo->dado;
			_undo->push(dado);
			pop();
		}
		else {
			cout << endl << "A pilha está vazia!" << endl;
		}
	}

	// adicionar 1 da outra pilha
	void Pilha<T>::redo() {
		if (_undo->tam > 0) {
			T dado = _undo->top();
			push(dado);
			_undo->pop();
		}
		else {
			cout << endl << "Pilha vazia!" << endl;
		}
	}

	// redo todos da outra pilha
	void Pilha<T>::redo_all() {
		if (_undo->tam > 0) {
			while (_undo->tam > 0) {
				redo();
			}
			cout << endl << "Itens readicionados à pilha!" << endl;
		}
		else {
			cout << endl << "Pilha vazia!" << endl;
		}
		
	}

	// existe item?
	bool Pilha<T>::find(const T &dado) {
		if (tam > 0) {
			if (ultimo->dado == dado) {
				redo_all();
				return true;
			}
			else {
				undo();
				find(dado);
			}
		}
		else {
			return false;
		}
	}

	// imprimir pilha recursivamente da base
	void Pilha<T>::imprimirB(Nodo<T> *nodo) {
		if (nodo != NULL) {
			cout << nodo->dado << endl;
			imprimirB(nodo->proximo);
		}
	}

	// imprimir pilha recursivamente do topo
	void Pilha<T>::imprimirT(Nodo<T> *nodo) {
		if (nodo != NULL) {
			cout << nodo->dado << endl;
			imprimirT(nodo->anterior);
		}
	}

	// imprimir a partir da base
	void Pilha<T>::imprime_base() {
		imprimirB(primeiro);
	}

	// imprimir a partir do topo
	void Pilha<T>::imprime_topo() {
		imprimirT(ultimo);
	}

	// imprimir pilha de redo da base
	void Pilha<T>::imprime_redo_base() {
		imprimirB(_undo->primeiro);
	}

	// imprimir pilha de redo do topo
	void Pilha<T>::imprime_redo_topo() {
		imprimirT(_undo->ultimo);
	}

	// palindromo
	bool Pilha<T>::palindromo(std::string &palavra) {
		clear(); // limpa o que tiver na pilha

		int size = palavra.size();
		for (int i = 0; i < size; i++) {
			push(palavra[i]);
		}

		for (int i = 0; i < size; i++) {
			if (palavra[i] == top()) {
				cont++;
				undo();
			}
		}
		
		redo_all();


		if (cont == size)
			return true;
		else
			return false;
		
	}

	// palavra inversa
	void Pilha<T>::inverter(std::string &palavra) {
		clear(); // limpa a pilha atual

		int s = palavra.size();

		 // cria pilha de caracteres
		for (int i = 0; i < s; i++) {
			push(palavra[i]);
		}

		// imprime em ordem de topo para base
		imprime_topo();

	}

private:
	Nodo<T> *primeiro; //base
	Nodo<T> *ultimo; // topo
	Pilha<T> *_undo; // pilha para redo
	T *palavra;
	int tam, cont;

};