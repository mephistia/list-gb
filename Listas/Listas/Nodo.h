#pragma once
template <class T>
struct Nodo {

	T dado;
	struct Nodo<T> *proximo;
	struct Nodo<T> *anterior;

};
