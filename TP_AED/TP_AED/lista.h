#pragma once
#include<iostream>
using namespace std;
template <typename T>
class lista {
public:
	struct nodo {
		nodo(T);
		T v;//valor del nodo
		nodo* anterior;
		nodo* siguiente;
	};
	lista();
	~lista();
	void insercionInicio(T v);
	void insercionFinal(T v);
	void insercionpos(T v, int pos);
	void eliminarenpos(int pos);
private:
	int tam;
	nodo* inicio;
	nodo* fin;
};

template<typename T>
lista<T>::nodo::nodo(T v)
{
	this->v = v;
	siguiente = anterior = nullptr;
}

template<typename T>
lista<T>::lista()
{
	tam = 0;
	incio = fin = nullptr;
}
template<typename T>
void lista<T>::insercionInicio(T v)
{
	if (tam == 0) inicio = fin = new nodo(v);
	else
	{
		nodo* nuevo = new nodo(v);

		nuevo->siguiente = inicio;
		inicio->anterior = nuevo;
		inicio = nuevo;

	}
	++tam;
}
template<typename T>
void lista<T>::insercionFinal(T v) {
	if (tam == 0) insercionInicio(v);
	else {
		nodo* nuevo = new nodo(v);
		fin->siguiente = nuevo;
		nuevo->anterior = fin;
		fin = nuevo;
	}
	++tam;
}
template<typename T>
void lista<T>::insercionpos(T v, int pos) {
	if (pos < 0) insercionInicio(v);
	else if (pos > tam - 1) {
		insercionFinal(v);
	}
	else {
		nodo* nuevo, * aux;
		aux = inicio;
		for (int i = 0; i < pos - 1; i++) {
			aux = aux->siguiente;
		}
		nuevo = new nodo(v);
		nuevo->siguiente = aux->siguiente;
		aux->siguiente->anterior = nuevo;
		aux->siguiente = nuevo;
		nuevo->anterior = aux;


	}
	++tam;
}

template<typename T>
void lista<T>::eliminarenpos(int pos) {
	if (tam == 1) {
		delete inicio;
	}
	else if (pos > 0) {
		nodo* nuevo, * aux1, * aux2;
		aux1 = inicio;
		for (int i = 0; i < pos - 1; i++) {
			aux1 = aux1->siguiente;
		}
		aux2 = aux1->siguiente;
		aux1->siguiente = aux2->siguiente;
		if (aux2->siguiente == nullptr) {
			fin = aux1;
		}
		else {
			aux2->siguiente = aux1;
		}
		delete aux2;
	}

	--tam;
}

template<typename T>
lista<T>::~lista() {}





