#pragma once
#include<iostream>
#include<sstream>
#include"NodoArbol.h"
class ArbolBinario
{
private:
	void Insertar(NodoArbol* raiz, string value) {
		string tmp = raiz->GetValor();
		stringstream converter1(value);
		stringstream converter2(tmp);
		int nuevo = 0;
		int actual = 0;
		converter1 >> nuevo;
		converter2 >> actual;
		if (nuevo>= actual) {
			if (raiz->GetDerecho() == nullptr) {
				NodoArbol* nuevo = new NodoArbol(value);
				raiz->SetDerecho(nuevo);
				return;
				
			}
			else {
				Insertar(raiz->GetDerecho(), value);
			}
		}
		else if (nuevo < actual) {
			if (raiz->GetIzquierdo() == nullptr) {
				NodoArbol* nuevo = new NodoArbol(value);
				raiz->SetIzquierdo(nuevo);
				return;

			}
			else {
				Insertar(raiz->GetIzquierdo(), value);
			}
		}
	}

public:
	NodoArbol* Raiz;
	int Count;
	ArbolBinario():Raiz(nullptr) {
		Count = 0;
	}

	void Agregar(string valor) {
		if (Count == 0) {
			NodoArbol* nuevo = new NodoArbol(valor);
			Raiz = nuevo;
			
		}
		else {

			Insertar(Raiz, valor);

		}
		Count++;

	}




};

