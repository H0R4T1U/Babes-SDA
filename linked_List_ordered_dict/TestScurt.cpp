#include <assert.h>

#include "DO.h"
#include "Iterator.h"

#include <exception>
using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}
void testActualizeaza(){
    DO dictOrd = DO(relatie1);
    DO dictOrd2 = DO(relatie1);
    dictOrd.adauga(1,2);
    dictOrd.adauga(2,3);
    dictOrd.adauga(3,1);
    dictOrd.adauga(5,0);

    dictOrd2.adauga(1,5);
    dictOrd2.adauga(3,3);
    dictOrd2.adauga(4,0);
    dictOrd2.adauga(5,2);
    assert(dictOrd.cauta(1)  == 2);
    assert(dictOrd.cauta(3)  == 1);
    assert(dictOrd.cauta(5)  == 0);
    assert(dictOrd.cauta(4)  == NULL_TVALOARE);
    assert(dictOrd.actualizeazaDict(dictOrd2) == 3);
    assert(dictOrd.cauta(4)  == NULL_TVALOARE);
    assert(dictOrd.cauta(1)  == 5);
    assert(dictOrd.cauta(3)  == 3);
    assert(dictOrd.cauta(5)  == 2);
}
void testAll(){
	DO dictOrd = DO(relatie1);
	assert(dictOrd.dim() == 0);
	assert(dictOrd.vid());
    dictOrd.adauga(1,2);
    assert(dictOrd.dim() == 1);
    assert(!dictOrd.vid());
    assert(dictOrd.cauta(1)!=NULL_TVALOARE);
    TValoare v =dictOrd.adauga(1,3);
    assert(v == 2);
    assert(dictOrd.cauta(1) == 3);
    Iterator it = dictOrd.iterator();
    it.prim();
    while (it.valid()){
    	TElem e = it.element();
    	assert(e.second != NULL_TVALOARE);
    	it.urmator();
    }
    assert(dictOrd.sterge(1) == 3);
    assert(dictOrd.vid());
    testActualizeaza();
}

