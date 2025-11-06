#include "arbol.h"
#include <iostream>
#include <algorithm>
using namespace std;


Nodo::Nodo(int num) : ValNodo(num) {}

void Nodo::AgregaH(Nodo* nuevoH) {
    Hnodo.push_back(nuevoH);
}


Arbol::Arbol() : NodoRa(nullptr) {}     /*CONSTRUYE EL ARBOL*/
Arbol::~Arbol() { limpiar(); }          /*LIMPIA EL ARBOL*/ 



// ACA EMPIEZAN LOS METODOS PRIVADOS//
Nodo* Arbol::Busca(Nodo* NodoAct, int ValB) {
    if (!NodoAct) return nullptr;
    if (NodoAct->ValNodo == ValB) return NodoAct;
    for (Nodo* hijo : NodoAct->Hnodo) {
        Nodo* encontrado = Busca(hijo, ValB);
        if (encontrado) return encontrado;
    }
    return nullptr;
}
//////////////////////////////////////////////////

void Arbol::ArbolElim(Nodo* NodoAct) {
    if (!NodoAct) return;
    for (Nodo* hijo : NodoAct->Hnodo)
        ArbolElim(hijo);
    delete NodoAct;
}

//////////////////////////////////////////////////

int Arbol::altura(Nodo* actual) {
    if (!actual) return 0;
    int maxAltura = 0;
    for (Nodo* hijo : actual->Hnodo)
        maxAltura = max(maxAltura, altura(hijo));
    return 1 + maxAltura;
}

//////////////////////////////////////////////////

bool Arbol::Binario(Nodo* Bin) {
    if (!Bin) return true;
    if (Bin->Hnodo.size() > 2) return false;
    for (Nodo* hijo : Bin->Hnodo)
        if (!Binario(hijo)) return false;
    return true;
}

//////////////////////////////////////////////////

void Arbol::preorden(Nodo* pre) {
    if (!pre) return;
    cout << pre->ValNodo << " ";
    for (Nodo* hijo : pre->Hnodo)
        preorden(hijo);
}

//////////////////////////////////////////////////

void Arbol::postorden(Nodo* post) {
    if (!post) return;
    for (Nodo* hijo : post->Hnodo)
        postorden(hijo);
    cout << post->ValNodo << " ";
}

//////////////////////////////////////////////////

void Arbol::mostrarbol(Nodo* Consarbol, string espacios, bool lineas) {
    if (!Consarbol) return;
    cout << espacios << (lineas ? "└── " : "├── ") << Consarbol->ValNodo;
    if (Consarbol->Hnodo.size() > 0)
        cout << " (" << Consarbol->Hnodo.size() << " hijos)";
    cout << endl;
    
    string nuevoPrefijo = espacios + (lineas ? "    " : "│   ");
    for (size_t i = 0; i < Consarbol->Hnodo.size(); i++) {
        bool esUltimo = (i == Consarbol->Hnodo.size() - 1);
        mostrarbol(Consarbol->Hnodo[i], nuevoPrefijo, esUltimo);
    }
}

//////////////////////////////////////////////////
/*ACA EMPIEZAN LOS METODOS PUBLICOS*/

void Arbol::raiz(int val) {
    if (!NodoRa) {
        NodoRa = new Nodo(val);
        cout << "Raiz " << val << " creada\n";
    } else {
        cout << "Ya existe raiz\n";
    }
}

//////////////////////////////////////////////////

void Arbol::AgregaHijo(int padre, int hijo) {
    if (!NodoRa) {
        cout << "Crea raiz primero\n";
        return;
    }
    if (Busca(NodoRa, hijo)) {
        cout << "El valor " << hijo << " ya existe\n";
        return;
    }
    Nodo* nodoPadre = Busca(NodoRa, padre);
    if (!nodoPadre) {
        cout << "Padre " << padre << " no encontrado\n";
        return;
    }
    nodoPadre->AgregaH(new Nodo(hijo));
    cout << "Hijo " << hijo << " agregado a " << padre << "\n";
}

//////////////////////////////////////////////////

void Arbol::MuestraArbol() {
    if (!NodoRa) {
        cout << "Arbol vacio\n";
        return;
    }
    cout << "\nESTRUCTURA DEL ARBOL:\n";
    mostrarbol(NodoRa, "", true);
}

//////////////////////////////////////////////////

void Arbol::Prerecorrido() {
    if (!NodoRa) {
        cout << "Arbol vacio\n";
        return;
    }
    cout << "Preorden: ";
    preorden(NodoRa);
    cout << endl;
}

//////////////////////////////////////////////////

void Arbol::Postrecorrido() {
    if (!NodoRa) {
        cout << "Arbol vacio\n";
        return;
    }
    cout << "Postorden: ";
    postorden(NodoRa);
    cout << endl;
}

//////////////////////////////////////////////////

void Arbol::Inrecorrido() {
    if (!NodoRa) {
        cout << "Arbol vacio\n";
        return;
    }
    cout << "Inorden: ";
    Inorden(NodoRa);
    cout << endl;
}

void Arbol::Inorden(Nodo* actual) {
    if (!actual) return;
    
    if (!actual->Hnodo.empty()) {
        Inorden(actual->Hnodo[0]);
    }
    
    cout << actual->ValNodo << " ";
    
    for (size_t i = 1; i < actual->Hnodo.size(); i++) {
        Inorden(actual->Hnodo[i]);
    }
}
//////////////////////////////////////////////////

void Arbol::CalcuAltura() {
    cout << "Altura: " << altura(NodoRa) << endl;
}

void Arbol::Bin() {
    if (Binario(NodoRa)) {
        cout << "SI es binario\n";
        cout << "Ya que cada nodo tiene como maximo 2 hijos\n";
    } else {
        cout << "NO es binario\n";
        cout << "Ya que algun nodo tiene mas de 2 hijos\n";
    }
}

//////////////////////////////////////////////////

void Arbol::BuscaNodo(int val) {
    if (Busca(NodoRa, val))
        cout << "Valor " << val << " SI existe\n";
    else
        cout << "Valor " << val << " NO existe\n";
}

//////////////////////////////////////////////////

void Arbol::limpiar() {
    ArbolElim(NodoRa);
    NodoRa = nullptr;
    cout << "Arbol limpiado\n";
}