#include <iostream>

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    void agregarDato(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevoNodo;
        }
        else {
            Nodo* actual = cabeza;
            while (actual->siguiente) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    void verDatos() {
        Nodo* actual = cabeza;
        while (actual) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    void eliminarDato(int valor) {
        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;

        while (actual && actual->dato != valor) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual) {
            if (anterior) {
                anterior->siguiente = actual->siguiente;
            }
            else {
                cabeza = actual->siguiente;
            }
            delete actual;
        }
    }
};

int main() {
    ListaEnlazada lista;
    char opcion;

    do {
        std::cout << "Seleccione una opcion:\n"
            << "1. Agregar dato\n"
            << "2. Ver lista\n"
            << "3. Eliminar dato\n"
            << "0. Salir\n";

        std::cin >> opcion;

        switch (opcion) {
        case '1': {
            int valor;
            std::cout << "Ingrese el valor a agregar: ";
            std::cin >> valor;
            lista.agregarDato(valor);
            break;
        }
        case '2':
            std::cout << "Lista: ";
            lista.verDatos();
            break;
        case '3': {
            int valor;
            std::cout << "Ingrese el valor a eliminar: ";
            std::cin >> valor;
            lista.eliminarDato(valor);
            break;
        }
        case '0':
            std::cout << "Saliendo del programa.\n";
            break;
        default:
            std::cout << "Opcion no valida. Intente de nuevo.\n";
        }

    } while (opcion != '0');

    return 0;
}
