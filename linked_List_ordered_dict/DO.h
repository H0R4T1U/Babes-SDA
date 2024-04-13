#pragma once

typedef int TCheie;
typedef int TValoare;

#define NULL_TVALOARE -1

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

class Iterator;
class Nod;

//se defineste tipul PNod ca fiind adresa unui Nod
typedef Nod* PNod;

class Nod
{
public:
    friend class DO;
    //constructor
    Nod(TElem e, PNod urm);
    TElem element();
    PNod urmator();

private:

    TElem e;
    PNod urm;
};

typedef bool(*Relatie)(TCheie, TCheie);

class DO {
	friend class Iterator;
    private:
	/* aici e reprezentarea */
        PNod Inceput;
        Relatie r;
        int len;
    public:

	// constructorul implicit al dictionarului
	DO(Relatie r);
    void sort();

	// adauga o pereche (cheie, valoare) in dictionar
	//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	TValoare adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	TValoare cauta(TCheie c) const;


	//sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	TValoare sterge(TCheie c);

	//returneaza numarul de perechi (cheie, valoare) din dictionar
	int dim() const;

	//verifica daca dictionarul e vid
	bool vid() const;

	// se returneaza iterator pe dictionar
	// iteratorul va returna perechile in ordine dupa relatia de ordine (pe cheie)
	Iterator iterator() const;


	// destructorul dictionarului
	~DO();

};
