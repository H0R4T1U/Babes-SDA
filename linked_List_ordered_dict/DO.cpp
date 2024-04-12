#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>
using namespace std;
//referire a clasei Nod
class Nod;

/// Teta(1)
Nod::Nod(TElem e, PNod urm, PNod pre) {
    this->e = e;
    this->urm = urm;
    this->pre = pre;
}
/// Teta(1)
TElem Nod::element() {
    return e;
}
/// Teta(1)
PNod  Nod::urmator(){
    return urm;
}
/// Teta(1)
PNod Nod::precedent() {
    return this->pre;
}
/// Teta(1)
DO::DO(Relatie r) {
    /* de adaugat */
    this->Inceput = nullptr;
    this->r = r;
    this->len = 0;
}
/// Teta(n^2)
void DO::sort() {
    for (int k = 0; k< this->len;k++) {
        PNod  p = this->Inceput;
        for(int i = 0; i<this->len-1;i++) {
            if(!r(p->element().first,p->urm->element().first )) {
                TElem el = p->element();
                p->e = p->urm->element();
                p->urm->e = el;
                //p->pre->urm = p->urm;
                //p->urm->pre = p->pre;
                //p->pre = p->urm;
                //p->urm = p->pre->urm;
                //p->pre->urm = p;
                //p->urm->pre = p;
            }
            p = p->urmator();
        }
    }
}
//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
// TETA(N^2)
TValoare DO::adauga(TCheie c, TValoare v) {
	/* de adaugat */
    TElem e;
    e.first = c;
    e.second = v;
    PNod Newp = new Nod(e,nullptr,nullptr);
    if(this->Inceput == nullptr){
        this->Inceput = Newp;
        this->len = 1;
        return NULL_TVALOARE;
    }
    PNod  p = this->Inceput;
    while(p->urmator() != nullptr){
        if(c == p->element().first){
            TValoare aux = p->e.second;
            p->e.second = v;
            return aux;
        }
        p = p->urmator();
    }
    if(c == p->element().first){
        TValoare  aux = p->e.second;
        p->e.second = v;
        return aux;
    }
    if(p->urm != nullptr){
        p->urm->pre = Newp;
        Newp->urm = p->urm;
    }
    p->urm = Newp;
    Newp->pre = p;
    this->len++;
    sort();
	return NULL_TVALOARE;
}

//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
// caz favorabil (cheia este pe prima pozitie): O(1)
// caz defavorabil (cheia nu se afla in colectie): O(n)
// caz mediu: O(n)
TValoare DO::cauta(TCheie c) const {
	/* de adaugat */
    PNod p = this->Inceput;
    while(p != nullptr){
        if(c==p->element().first){
            return p->e.second;
        }
        p=p->urmator();
    }
	return NULL_TVALOARE;	
}

//sterge o cheie si returneaza valoarea asociata (daca exista) sau null
// caz favorabil (cheia este pe prima pozitie): O(1)
// caz defavorabil (cheia nu se afla in colectie): O(n)
// caz mediu: O(n)
TValoare DO::sterge(TCheie c) {
	/* de adaugat */
    if(this->Inceput == nullptr){
        return NULL_TVALOARE;
    }
    PNod p = this->Inceput;
    if(c==p->element().first){
        PNod p_aux = this->Inceput;
        TValoare aux = p->e.second;
        this->Inceput = p->urm;
        if(this->Inceput != nullptr)
            this->Inceput->pre = nullptr;
        delete p_aux;
        this->len--;
        return aux;
    }
    while(p->urmator() != nullptr){
        if(c==p->element().first){
            PNod p_aux = p;
            TValoare aux = p->e.second;
            p = p->pre;
            if(p->urm->urm != nullptr)
                p->urm->urm->pre =p;
            p->urm = p->urm->urm;
            delete p_aux;
            this->len--;
            return aux;
        }
        p = p->urmator();
    }
    if(c == p->element().first){
        PNod p_aux = p;
        TValoare  aux = p->e.second;
        p->pre->urm = nullptr;
        p = nullptr;
        this->len--;
        delete p_aux;
        return aux;
    }
	return NULL_TVALOARE;
}

//returneaza numarul de perechi (cheie, valoare) din dictionar
//O(1)
int DO::dim() const {
	/* de adaugat */
	return this->len;
}

//verifica daca dictionarul e vid
//O(1)
bool DO::vid() const {
	/* de adaugat */
	return this->Inceput == nullptr;
}
//O(1)
Iterator DO::iterator() const {
	return  Iterator(*this);
}
//O(n)
DO::~DO() {
	/* de adaugat */
    while(this->Inceput != nullptr){
        PNod p = this->Inceput;
        this->Inceput = this->Inceput->urm;
        delete p;
    }
}
