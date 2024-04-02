#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>
using namespace std;

DO::DO(Relatie r) {
	/* de adaugat */
	DIM = 0;
	ALLOCATED = 1;
	elemente = new TElem[DIM];
	rel = r;

}

//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
void DO::mareste() {
	TElem* v_nou = new TElem[2* ALLOCATED];
	for(int i =0 ; i< DIM; i++) {
		v_nou[i] = elemente[i];
	}
	ALLOCATED = 2*ALLOCATED;
	delete[] elemente;
	elemente = v_nou;
}
void DO::sort() {
	for (int k = 0; k< this->DIM;k++) {
		for(int i = 0; i<this->DIM-1;i++) {
			if(!rel(this->elemente[i].first,this->elemente[i+1].first)) {
				TElem tmp = this->elemente[i];
				this->elemente[i] = this->elemente[i+1];
				this->elemente[i+1] = tmp;
			}
		}
	}
}

TValoare DO::adauga(TCheie c, TValoare v) {
	/* de adaugat */
	for(int i =0 ; i < this->DIM;i++) {
		if(this->elemente[i].first == c) {
			TValoare val_veche = this->elemente[i].second;
			this->elemente[i].second = v;
			return val_veche;
		}
	}

	if(DIM == ALLOCATED) {
		mareste();
	}


	elemente[this->DIM].first = c;
	elemente[this->DIM].second = v;
	this->DIM +=1;
	sort();
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
			DIM -= 1;
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
	delete[] elemente;
}
