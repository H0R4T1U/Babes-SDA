#include "Iterator.h"

#include <iostream>

#include "DO.h"

using namespace std;

Iterator::Iterator(const DO& d) : dict(d){
	/* de adaugat */

	currentIndex = 0;
}

void Iterator::prim(){
	/* de adaugat */
	currentIndex=0;
}

void Iterator::urmator(){
	/* de adaugat */
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
	/* de adaugat */
	if(currentIndex < dict.dim()) {
		return true;
	}
	return false;
}

TElem Iterator::element() const{
	/* de adaugat */
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


