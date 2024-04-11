#include "Iterator.h"

#include <iostream>

#include "DO.h"

using namespace std;

// 0(1)
// constructorul clasei Iterator
// preconditii: d este Dictionar Ordonat
// postconditii: iteratorul refera primul element
Iterator::Iterator(const DO& d) : dict(d){


	currentIndex = 0;
}
// 0(1)
// reseteaza pozitia iteratorului la inceputul DO
// preconditii: dict este DO
// postconditii: iteratorul a fost mutat la inceput
void Iterator::prim(){
	/* de adaugat */
	currentIndex=0;
}

void Iterator::urmator(){
    // 0(1)
    // mutam iteratorul inainte in DO
    // preconditii: it este iterator
    // postconditii: it' refera urmatorul element din Dictionar dupa
    //			     elementul referit de it sau este invalid daca nu
    //				 mai exista elemente de iterat
    // arunca exceptie daca it este invalid
	try {
		bool status = valid();
		if(status) {
			currentIndex +=1;
		}else {
			throw status;
		}
	}catch(...) {
		cout<<"Iteratorul este invalid!";
	}

}

bool Iterator::valid() const{
    // 0(1)
    // verificarea validitatii iteratorului
    // preconditii: it este iterator
    // postconditii: valid <- true, daca it refera un element din DICT care este valid
    //					      false, in caz contrar

	if(currentIndex < dict.dim()) {
		return true;
	}
	return false;
}

TElem Iterator::element() const{
    // 0(1)
    // returneaza elementul pe care il refera iteratorul
    // preconditii: it este iterator, it este valid
    // postconditii: element <- elementul curent din Dictionar, referit de it
    // arunca exceptie daca it este invalid

	try {
		bool status = valid();
		if(status) {
			TElem element;
			element.first = dict.elemente[currentIndex].first;
			element.second = dict.elemente[currentIndex].second;
			return element;
		}else {
			throw status;
		}
	}catch(...) {
		cout<<"Iteratorul este invalid!";
		return pair <TCheie, TValoare>  (-1, -1);

	}

}


