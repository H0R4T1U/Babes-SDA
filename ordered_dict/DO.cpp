#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>
using namespace std;
// 0(1)
// constructorul clasei DO
// preconditii: -
// postconditii: elemente este dictionar vid

DO::DO(Relatie r) {
	DIM = 0;
	ALLOCATED = 1;
	elemente = new TElem[DIM];
	rel = r;

}

// 0(n)
// alocarea in plus de spatiu de memorie
// preconditii: vect este Colectie
// postconditii: s-a alocat spatiu in plus pentru vect
void DO::mareste() {
	TElem* v_nou = new TElem[2* ALLOCATED];
	for(int i =0 ; i< DIM; i++) {
		v_nou[i] = elemente[i];
	}
	ALLOCATED = 2*ALLOCATED;
	delete[] elemente;
	elemente = v_nou;
}
// 0(n^2)
// Sorteaza dictionarul in functie de relatie
// preconditii: elemente este un dictionar
// postconditii: elemente este un dictionar ordonat
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
//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
// caz favorabil (elementul este pe prima pozitie): O(1)
// caz defavorabil (elementul nu exista in colectie): O(n)
// caz mediu: O(n)
// COMPLEXITATE TOTALA O(N^2)
// preconditii: elemente este DO, c este TCheie, v este Tvaloare
// postconditii: elemente' este DO, elemente' = elemente + {(c,v)}
TValoare DO::adauga(TCheie c, TValoare v) {
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

// cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
// caz favorabil (cheia este pe prima pozitie): O(1)
// caz defavorabil (cheia nu se afla in colectie): O(n)
// caz mediu: O(n)
// preconditii: elemente este DO, c este Tcheie
// postconditii: cauta <- true, daca c apare in DO
//
TValoare DO::cauta(TCheie c) const {
	/* de adaugat */
	for(int i = 0; i< this->DIM;i++) {
		if(this->elemente[i].first == c) {
			return this->elemente[i].second;
		}
	}
	return NULL_TVALOARE;	
}

//O(n)
//sterge o cheie si returneaza valoarea asociata (daca exista) sau null
// precondiiti: elemente este DO, c este TCheie
// postconditii: elemente' este DO, elemente' = elemente' - {c}
//				 sterge <- true, daca s-a sters cheia
//						<- false, in caz contrar

TValoare DO::sterge(TCheie c) {
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

// 0(n)
// calcularea dimensiunii Dictinoarului Ordonat
// preconditii: Elemente este DO
// postconditii: dim <- numarul total de perechi (chei,valoare)
int DO::dim() const {
	/* de adaugat */
	return this->DIM;
}

// 0(1)
// determina daca elemente este DO vid
// preconditii: elemente este DO
// postconditii: vida <- true, in cazul in care DO este vid
//					  <- false, in caz contrar
bool DO::vid() const {
	/* de adaugat */
	return this->DIM == 0;
}

// 0(1)
// returnarea unui iterator pe DO elemente
// preconditii: elemente este DO
// postconditii: iterator <- un iterator pe DO elemente
Iterator DO::iterator() const {
	return  Iterator(*this);
}

// 0(n)
// destructorul clasei Colectie
// preconditii: elemente este DO
// postconditii: Dictionarul ordonat  elemente a fost distrus (spatiul de memorie a fost dealocat)

DO::~DO() {
	/* de adaugat */
	delete[] elemente;
}

//returneaza toate perechile chei valoare care apartin unui interval a,b
// CAZ FAVORABIL: O(1), NU EXISTA nici-o cheie in intervalul specificat
// CAZ DEFAVORABIL: O(n^2), Toate elementele din DO se afla in intervalul a,b
DO DO::perechi_interval(TCheie a, TCheie b) const {
    DO dict = DO{this->rel};
    int i = 0;
    while(elemente[i].first >= a && elemente[i].first <= b && i < this->DIM){
        dict.adauga(elemente[i].first,elemente[i].second);
        i++;
    }
    return dict;
}