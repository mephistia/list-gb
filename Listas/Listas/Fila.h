#pragma once
#include "Nodo.h"
#include <iostream>

//template <class T>
//struct Nodo {
//
//	T dado;
//	int prior = 0;
//	struct Nodo<T> *proximo;
//	struct Nodo<T> *anterior;
//
//};

template <class T>

class Fila {

public:

	Fila<T>::Fila() {
		primeiro = NULL;
		ultimo = NULL;
		tam = 0;
	}

	Fila<T>::~Fila() {
	}

	// limpa tudp
	void Fila<T>::clear() {
		primeiro = NULL;
		ultimo = NULL;
		tam = 0;
		pos = primeiro;
	}


	// adiciona no final sem prioridade
	void Fila<T>::push(const T &dado1) {
		Nodo<T> *add = new Nodo<T>;
		add->dado = dado1;

		

		// se a fila estiver vazia
		if (tam == 0) {
			add->anterior = NULL;
			add->proximo = NULL;
			primeiro = add;
			ultimo = add;
			pos = primeiro; // para busca de prioridade
		}

		// inserir no fim da lista
		else {
			add->proximo = NULL; // o próximo do último é vazio
			ultimo->proximo = add; // o próximo do antigo último é o novo adicionado
			add->anterior = ultimo; // o anterior do novo é o antigo último
			ultimo = add; // agora o último é o novo
			pos = primeiro;
		}

		// aumenta tamanho da fila
		tam++;

	}


	void Fila<T>::pushP(const T &dado1, int i) {
		if (tam == 0) {
			antes(dado1, i);
			tam++;
			pos = primeiro;
		}
		else {
			if (i > pos->prior) {
				antes(dado1, i);
				tam++;
				pos = primeiro;
			}

			else if (pos->prior == i) {
				if (pos->proximo != NULL && pos->proximo->prior == i) {
					pos = pos->proximo;
					pushP(dado1, i);
				}
				else {
					depois(dado1, i);
					tam++;
					pos = primeiro;

				}
			}
			else {
				depois(dado1, i);
				tam++;
				pos = primeiro;
			}
		}
	}

	// botar antes da pos
	void Fila<T>::antes(const T &dado1, int i) {
		Nodo<T> *add = new Nodo<T>;
		add->dado = dado1;
		add->prior = i;
		
		if (tam == 0) {
			add->proximo = NULL;
			add->anterior = NULL;
			primeiro = add;
			ultimo = add;
			pos = primeiro;
		}

		else if (tam == 1) {
			add->anterior = NULL;
			primeiro->anterior = add;
			add->proximo = primeiro;
			primeiro = add;
			pos = primeiro;

		}
		else
		{
			if (pos->anterior == NULL) {
				add->proximo = pos;
				pos->anterior = add;
				primeiro = add;
			}
			else {
				add->proximo = pos;
				add->anterior = pos->anterior;
				pos->anterior->proximo = add;
				pos->anterior = add;
				pos = primeiro;
			}
		}
	}

	// botar depois da pos
	void Fila<T>::depois(const T &dado1, int i) {
		Nodo<T> *add = new Nodo<T>;
		add->dado = dado1;
		add->prior = i;

		if (tam == 0) {
			add->proximo = NULL;
			add->anterior = NULL;
			primeiro = add;
			ultimo = add;
			pos = primeiro;
		}

		else if (tam == 1) {
			add->proximo = NULL;
			ultimo->proximo = add;
			add->anterior = ultimo;
			ultimo = add;
			pos = primeiro;
		}


		else
		{
			add->proximo = pos->proximo;
			add->anterior = pos;
			pos->proximo->anterior = add;
			pos->proximo = add;
			pos = primeiro;
		}
	}

	// remover o primeiro
	void Fila<T>::pop() {

		if (tam == 0) {
			cout << endl << "A fila está vazia!" << endl;
		}
		else if (tam == 1) {
			clear();
			tam--;
		}
		else {
			primeiro = primeiro->proximo;
			primeiro->anterior = NULL;


			tam--;
		}
	}

	// retornar o primeiro
	T Fila<T>::front() {
		if (tam > 0)
			return primeiro->dado;
	}


	// imprimir recursivo
	void Fila<T>::_imprimir(Nodo<T> *nodo) { // mandar o primeiro como parâmetro
		if (nodo != NULL) {
			cout << nodo->dado << endl;
			_imprimir(nodo->proximo);
		}

	}

	// imprimir
	void Fila<T>::imprimir() {
		_imprimir(primeiro);
	}

private:
	Nodo<T> *primeiro;
	Nodo<T> *ultimo;
	Nodo<T> *pos;
	int tam;
};
