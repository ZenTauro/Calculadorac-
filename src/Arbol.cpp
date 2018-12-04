#include <string.h>
#include <iomanip>

#include "../include/Arbol.hpp"

using namespace std;

Arbol::Arbol(){//constructor del arbol donde vemos que esta la raiz y el actual inicializado a null
    raiz = NULL;
    /*actual = NULL;*/
}

void Arbol::insertar(nodoa ope, nodoa num1, nodoa num2_ope) {//insertamos los 3 nodos al arbol
    raiz = ope;
    raiz->izq = num1;
    raiz->der = num2_ope;
}

nodoa Arbol::getRaiz(){//obtenemos la raiz con este metodo
	return raiz;
}

void Arbol::pintar(nodoa p, int indent){//pintamos el arbol 
    
    if (p != NULL) {
		if (p->der) {
			pintar(p->der, indent + 6);
		}
		if (indent) {
			cout << setw(indent) << ' ';
		}
		if (p->der) cout << " /\n" << setw(indent) << ' ';
		cout << "/" << p->getValorArb() << "\n ";
		if (p->izq) {
			cout << setw(indent) << ' ' << " \\\n";
			pintar(p->izq, indent + 6);
		}
	}
}

void Arbol::borrar(nodoa){//borramos el arbol
    /*if (!nodoa == NULL){
        if(nodoa->izq)
            borrar(nodoa->izq);
        if(nodoa->der)
            borrar(nodoa->der);
        delete nodoa;*/
}

void Arbol::preOrden(nodoa b){
	if (b != NULL) {
		cout << b->getValorArb() << "\n";
        cout << endl;
		preOrden(b->izq);
		preOrden(b->der);
	}
}

void Arbol::postOrden(nodoa b){
	if (b != NULL) {
		postOrden(b->izq);
		postOrden(b->der);
		cout << b->getValorArb() << "\n";
        cout << endl;
	}
}

void Arbol::inOrden(nodoa b){
	if (b != NULL) {
		inOrden(b->izq);
		cout << b->getValorArb() << "\n";
        cout << endl;
		inOrden(b->der);
	}
}

Arbol::~Arbol(){}
