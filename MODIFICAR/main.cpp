#include <iostream>
#include "arbol.h"
using namespace std;

int main() {
    Arbol arbol;
    int opcion, valor, padre;
    
    do {
      system("cls");
cout << "\n";
cout << "┌───────────── MENÚ ÁRBOL ─────────────┐" << endl;
cout << "│  1. Crear raíz                       │" << endl;
cout << "│  2. Agregar hijo                     │" << endl;
cout << "│  3. Mostrar árbol                    │" << endl;
cout << "│  4. Recorridos                       │" << endl;
cout << "│  5. Calcular altura                  │" << endl;
cout << "│  6. Es binario?                      │" << endl;
cout << "│  7. Buscar nodo                      │" << endl;
cout << "│  8. Limpiar árbol                    │" << endl;
cout << "│  9. Salir                            │" << endl;
cout << "└──────────────────────────────────────┘" << endl;
cout << "Opción: ";
cin >> opcion;
        
switch(opcion) {
    case 1:
        system("cls");
        cout << "╭─ CREAR RAÍZ ────────────────────────╮" << endl;
        cout << "│ Ingresale un valor a la raíz: ";
        cin >> valor;
        cout << "╰──────────────────────────────────────╯" << endl;
        arbol.raiz(valor);
        break;
        
    case 2:
        system("cls");
        cout << "╭─ AGREGAR HIJO ──────────────────────╮" << endl;
        cout << "│ Nodo Padre: ";
        cin >> padre;
        cout << "│ Hijo:  ";
        cin >> valor;
        cout << "╰──────────────────────────────────────╯" << endl;
        arbol.AgregaHijo(padre, valor);
        break;
        
    case 3:
        system("cls");
        cout << "╭─ ESTRUCTURA DEL ÁRBOL ──────────────╮" << endl;
        arbol.MuestraArbol();
        cout << "╰──────────────────────────────────────╯" << endl;
        break;
        
    case 4:
    int sub;
        system("cls");
        cout << "╭─ RECORRIDOS ────────────────────────╮" << endl;
        cout << "│ 1 • Preorden                        │" << endl;
        cout << "│ 2 • Inorden                         │" << endl;
        cout << "│ 3 • Postorden                       │" << endl;
        cout << "│ Selección: ";
        cin >> sub;
        cout << "╰──────────────────────────────────────╯" << endl;
        if (sub == 1) arbol.Prerecorrido();     
        else if (sub == 2) arbol.Inrecorrido(); 
        else if (sub == 3) arbol.Postrecorrido(); 
        else cout << "Opción inválida\n";
        break;
        
    case 5:
        system("cls");
        cout << "╭─ CÁLCULO DE ALTURA ───────────────────╮" << endl;
        arbol.CalcuAltura();
        cout << "╰────────────────────────────────────────╯" << endl;
        break;
        
    case 6:
        system("cls");
        cout << "╭─ VERIFICACIÓN BINARIA ──────────────╮" << endl;
        arbol.Bin();
        cout << "╰──────────────────────────────────────╯" << endl;
        break;
        
    case 7:
        system("cls");
        cout << "╭─ BÚSQUEDA DE NODO ───────────────────╮" << endl;
        cout << "│ Valor: ";
        cin >> valor;
        cout << "╰──────────────────────────────────────╯" << endl;
        arbol.BuscaNodo(valor);
        break;
        
    case 8:
        system("cls");
        cout << "╭─ LIMPIAR ARBOL ──────────────────────╮" << endl;
        arbol.limpiar();
        cout << "╰──────────────────────────────────────╯" << endl;
        break;
        
    case 9:
        system("cls");
        cout << "╭─ FIN DEL PROGRAMA ──────────────────╮" << endl;
        cout << "│ ¡Gracias por usar el sistema!        │" << endl;
        cout << "╰──────────────────────────────────────╯" << endl;
        break;
        
    default:
        system("cls");
        cout << "╭─ ¡¡ERROR!!  ─────────────────────────╮" << endl;
        cout << "│ Opción no reconocida                 │" << endl;
        cout << "╰──────────────────────────────────────╯" << endl;
}

if (opcion != 9) {
    cout << "╭──────────────────────────────────────╮" << endl;
    cout << "│ Enter para continuar...              │" << endl;
    cout << "╰──────────────────────────────────────╯" << endl;
    cin.ignore();
    cin.get();
}
} while(opcion != 9);

    return 0;
}