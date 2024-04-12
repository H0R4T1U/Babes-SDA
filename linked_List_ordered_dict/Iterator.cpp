#include <iostream>
#include "Iterator.h"
#include "DO.h"

using namespace std;
//O(1)
Iterator::Iterator(const DO& d) : dict(d){
	/* de adaugat */
    this->p = this->dict.Inceput;
}
//O(1)
void Iterator::prim(){
	/* de adaugat */
    this->p = this->dict.Inceput;
}
//O(1)
void Iterator::urmator(){
	/* de adaugat */
    if(!this->valid())
        throw exception();
    this->p = this->p->urmator();
}
//O(1)
bool Iterator::valid() const{
	/* de adaugat */
    if(this->p == nullptr)
        return false;
    return true;
}
//O(1)
TElem Iterator::element() const{
	/* de adaugat */
    if(!this->valid())
        throw exception();
    return this->p->element();
}


