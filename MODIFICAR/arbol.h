#ifndef ARBOL_H /*Verifica si no esta definido*/
#define ARBOL_H /*Define*/

#include <vector>
#include <string>
#include <fstream>

class Nodo /*CLASE NODO*/{
public:
    int ValNodo; /*Valor del nodo*/
    std::vector<Nodo*> Hnodo;   /*Vector de punteros a nodos hijos*/
    
    Nodo(int num);
    void AgregaH(Nodo* nuevoH);
};

class Arbol {
private:
    Nodo* NodoRa;
    
    Nodo* Busca(Nodo* NodoAct, int ValB);
    void ArbolElim(Nodo* NodoAct);
    int altura(Nodo* actual);
    bool Binario(Nodo* Bin);
    void preorden(Nodo* pre);
    void Inorden(Nodo* actual);
    void postorden(Nodo* post);
    void mostrarbol(Nodo* Consarbol, std::string espacios, bool lineas);


public:
    Arbol();
    ~Arbol();
    
    void raiz(int val);
    void AgregaHijo(int padre, int hijo);
    void MuestraArbol();
    void Prerecorrido();
    void Postrecorrido();
    void Inrecorrido();
    void CalcuAltura();
    void Bin();
    void BuscaNodo(int val);
    void limpiar();
};

#endif