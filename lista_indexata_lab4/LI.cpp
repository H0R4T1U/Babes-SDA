#include <exception>
#include <iostream>
#include "LI.h"
#include "IteratorLI.h"
//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
int LI::aloca()
{
	int i = prim_liber;
	prim_liber = urm[prim_liber];
	return i;
}
//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
void LI :: dealoca(int poz)
{
	urm[poz] = prim_liber;
	ant[prim_liber] = poz;
	prim_liber = poz;
}


//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
int LI::creeazaNod(TElem e)
{
	if (prim_liber == -1)
		resize();
	int i = aloca();
	elems[i] = e;
	urm[i] = 0;
	ant[i] = 0;
	return i;
}
//CF:Theta(n)
//CD:Theta(n)
//CT:Theta(n) n=cp
void LI::resize()
{
	TElem* elems_nou = new TElem[2 * cp];
	TElem* urm_nou = new int[2 * cp];
	TElem* ant_nou = new int[2 * cp];

	for (int i = 0; i < cp; i++) {
		elems_nou[i] = elems[i];
		urm_nou[i] = urm[i];
		ant_nou[i] = ant[i];
	}
	for (int i = cp; i < 2 * cp; i++)
	{
		urm_nou[i] = i + 1;
		ant_nou[i] = i - 1;
	}
	urm_nou[2 * cp - 1] = -1; //echivalent NIL
	ant_nou[0] = -1; //echivalent NIL

	delete[] elems;
	delete[] urm;
	delete[] ant;

	elems = elems_nou;
	urm = urm_nou;
	ant = ant_nou;
	prim_liber = cp;
	cp = 2 * cp;
}
//CF:Theta(n)
//CD:Theta(n)
//CT:Theta(n)
LI::LI() {
	primul = -1;
	ultimul = -1;
	cp = 5;
	n = 0;
	prim_liber = 0;
	elems = new TElem[cp];
	urm = new int[cp];
	ant = new int[cp];
	for (int i = 0; i < cp; i++)
	{
		urm[i] = i + 1;
		ant[i] = i - 1;
	}
	urm[cp - 1] = -1;
	ant[0] = -1;
}
//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
int LI::dim() const {
	return n;
}
//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
bool LI::vida() const {
	return (primul ==-1);
}
//CF:Theta(1)
//CD:Theta(n)
//CT:O(n)
TElem LI::element(int i) const {
	if (i < 0 || i >= n)
		throw std::exception();
	int poz = primul;
	for (int j = 0; j < i; j++)
		poz = urm[poz];
	return elems[poz];
}
//CF:Theta(1)
//CD:Theta(n)
//CT:O(n)
TElem LI::modifica(int i, TElem e) {
	if (i < 0 || i >= n)
		throw std::exception();
	int poz = primul;
	for (int j = 0; j < i; j++)
		poz = urm[poz];
	TElem vechi = elems[poz];
	elems[poz] = e;
	return vechi;
}
//CF:Theta(1)
//CD:Theta(n)
//CT:O(n)
void LI::adaugaSfarsit(TElem e) {
	if (prim_liber == -1)
		resize();
	int poz = aloca();
	elems[poz] = e;
	if (n == 0)
	{
		primul = poz;
		ultimul = poz;
		ant[primul] = -1;
	}
	else
	{
		urm[ultimul] = poz;
		ant[poz] = ultimul;
		ultimul = poz;
	}
	urm[ultimul] = -1;
	n++;
}

//CF:Theta(1)
//CD:Theta(n)
//CT:O(n)
void LI::adauga(int i, TElem e) {
	if (i < 0 || i >= n)
		throw std::exception();
	if (prim_liber ==-1)
		resize();
	int poz = aloca();
	elems[poz] = e;
	if (i == 0) {
		ant[poz] = -1;
		urm[poz] = primul;
		ant[primul] = poz;
		primul = poz;
		ultimul = poz;
	}
	else {
		int p = primul;
		for (int j = 0; j < i - 1; j++)
			p = urm[p];
		urm[poz] = urm[p];
		ant[poz] = p;
		urm[p] = poz;
		ant[urm[poz]] = poz;
	}
	n++;
}
//CF:Theta(1)
//CD:Theta(n)
//CT:O(n)
TElem LI::sterge(int i) {
	if (i < 0 || i >= n)
		throw std::exception();
	int poz;
	if (i == 0) {
		poz = primul;
		primul = urm[poz];
		if (primul != -1)
		{
			ant[primul] = -1;
		}
		else
			ultimul = -1;
	}
	else if (i == n - 1) {
		poz = ultimul;
		ultimul = ant[poz];
		if(ultimul!=-1)
			urm[ultimul] = -1;
	}
	else {
		int p = primul;
		for (int j = 0; j < i; j++)
			p = urm[p];
		poz = p;
		urm[ant[poz]] = urm[poz];
		ant[urm[poz]] = ant[poz];
	}
	TElem val = elems[poz];
	dealoca(poz);
	n--;
	return val;
}
//CF:Theta(1)
//CD:Theta(n)
//CT:O(n)
int LI::cauta(TElem e) const {
	int poz = primul;
	int i = 0;
	while (poz != -1 && elems[poz] != e) {
		poz = urm[poz];
		i++;
	}
	if (poz == -1)
		return -1;
	else
		return i;
}
//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
IteratorLI LI::iterator() const {
	return  IteratorLI(*this);
}
//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
LI::~LI() {
	delete[] elems;
	delete[] urm;
	delete[] ant;
}
//CF:Theta(n)
//CD:Theta(n)
//CT:Theta(n)
int LI::ultimulIndex(TElem elem)const
{
	int poz = primul;
	int i = -1;
	while (poz != -1)
	{
		if (elems[poz] == elem)
			i = poz;
		poz = urm[poz];
	}
	return i;
}