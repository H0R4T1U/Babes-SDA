#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>
using namespace std;

DO::DO(Relatie r) {
	/* de adaugat */
	DIM = 0;
	ALLOCATED = 0;
	elemente = new TElem[dim];
	rel = r;

}

//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
TValoare DO::adauga(TCheie c, TValoare v) {
	/* de adaugat */
	for(int i =0 ; i < this->DIM;i++) {
		if(this->elemente[i].first == c) {
			this->elemente[i].second = v;
		}
	}
	TElem* v_nou = new TElem[ALLOCATED+1];
	for(int i = 0; i < this->DIM;i++) {
		v_nou[i] = this->elemente[i];
	}
	v_nou[this->DIM].first = c;
	v_nou[this->DIM].second = v;
	delete[] elemente;
	this->elemente = v_nou;
	this->ALLOCATED +=1;
	this->DIM +=1;
	return NULL_TVALOARE;
}

//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare DO::cauta(TCheie c) const {
	/* de adaugat */
	for(int i = 0; i< this->DIM;i++) {
		if(this->elemente[i].first == c) {
			return this->elemente[i].second;
		}
	}
	return NULL_TVALOARE;	
}

//sterge o cheie si returneaza valoarea asociata (daca exista) sau null
TValoare DO::sterge(TCheie c) {
	/* de adaugat */
	TValoare ret = NULL_TVALOARE;
	for(int i =0 ;i < this->DIM;i++) {
		if(this->elemente[i].first == c) {
			ret = this->elemente[i].second;
			for(int j = i; j < this->DIM-1;j++) {
				this->elemente[j] = this->elemente[j+1];
			}
			break;
		}
	}

	return ret;
}

//returneaza numarul de perechi (cheie, valoare) din dictionar
int DO::dim() const {
	/* de adaugat */
	return this->DIM;
}

//verifica daca dictionarul e vid
bool DO::vid() const {
	/* de adaugat */
	return this->DIM == 0;
}

Iterator DO::iterator() const {
	return  Iterator(*this);
}

DO::~DO() {
	/* de adaugat */
}
