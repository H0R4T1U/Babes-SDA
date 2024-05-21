#include "IteratorLI.h"
#include "LI.h"
#include <exception>

//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
IteratorLI::IteratorLI(const LI& li) : lista(li) {
    /* de adaugat */
    curent = lista.primul;
}
//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
void IteratorLI::prim() {
    /* de adaugat */
    curent = lista.primul;
}
//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
void IteratorLI::urmator() {
    /* de adaugat */
    if (!valid())
        throw std::exception();
    curent = lista.urm[curent];
}
//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
void IteratorLI::anterior() {
    if (!valid())
        throw std::exception();
    curent = lista.ant[curent];
}
//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
bool IteratorLI::valid() const {
    /* de adaugat */
    return curent != -1;
}
//CF:Theta(1)
//CD:Theta(1)
//CT:Theta(1)
TElem IteratorLI::element() const {
    /* de adaugat */
    if (!valid())
        throw std::exception();
    return lista.elems[curent];
}
