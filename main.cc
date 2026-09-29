
/*Biblioteca de Libros
Se necesita administrar una lista de libros utilizando una lista doblemente enlazada, la cual se manejara con un puntero global
A partir de las funciones proporcionadas, implemente las operaciones solicitadas, aplicando correctamente cada mecanismo a paso de parametros*/

/*Cada libro debe almacenarse en una struct con:
Codigo del libro
Titulo
Autor*/

/*La lista debe permitir realizar 2 operaciones no oblig, mas la oblig.*/
/*-Insetar al inicio
-Borrar al incio
-Insertar al final
-Insertar intermedio
-Eliminar final
-Eliminar intermedio
-Imprimir (obligatorio)*/

#include <iostream>
#include <string>
// 1. Estructura con los datos solicitados del libro
struct Libro
{
    std::string codigo;
    std::string titulo;
    std::string autor;
};

// 2. Estructura del Nodo para la lista doblemente enlazada
struct Nodo
{
    Libro libro;
    Nodo *siguiente;
    Nodo *anterior;
};

// 3. Punteros globales para manejar la lista
Nodo *lista_inicio = nullptr;

// Prototipos de funciones (Estilo Google: snake_case)
void insertar_al_inicio(const Libro &nuevo_libro);
void insertar_al_final(const Libro &nuevo_libro);
void imprimir_biblioteca();
Libro pedir_datos_usuario();
void cargar_datos_quemados();

int main()
{
    int opcion = 0;

    do
    {
        std::cout << "\n===================================\n";
        std::cout << "   BIBLIOTECA DE LIBROS (LAB 2)    \n";
        std::cout << "===================================\n";
        std::cout << "1. Insertar libro al inicio\n";
        std::cout << "2. Insertar libro al final\n";
        std::cout << "3. Imprimir biblioteca (Obligatoria)\n";
        std::cout << "4. Cargar datos quemados (Hardcoded)\n";
        std::cout << "0. Salir del programa\n";
        std::cout << "-----------------------------------\n";
        std::cout << "Ingrese su opcion: ";
        // Validacion simple por si el usuario ingresa letras en vez de numeros
        if (!(std::cin >> opcion))
        {
            std::cout << "\nError: Por favor, ingrese un numero valido.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        std::cin.ignore(); // Limpiar salto de linea

        switch (opcion)
        {
        case 1:
        {
            Libro nuevo = pedir_datos_usuario();
            insertar_al_inicio(nuevo);
            break;
        }
        case 2:
        {
            Libro nuevo = pedir_datos_usuario();
            insertar_al_final(nuevo);
            break;
        }
        case 3:
            imprimir_biblioteca();
            break;
        case 4:
            cargar_datos_quemados();
            break;
        case 0:
            std::cout << "\nSaliendo del sistema de la biblioteca...\n";
            break;
        default:
            std::cout << "\nOpcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}

// Solicita de forma segura los strings al usuario
Libro pedir_datos_usuario() {
    Libro nuevo;
    std::cout << "\n--- Registrar Datos del Libro ---\n";
    std::cout << "Codigo del libro: ";
    std::getline(std::cin, nuevo.codigo);
    std::cout << "Titulo: ";
    std::getline(std::cin, nuevo.titulo);
    std::cout << "Autor: ";
    std::getline(std::cin, nuevo.autor);
    return nuevo;
}

// Operacion: Insertar al inicio de la lista doble
void insertar_al_inicio(const Libro& nuevo_libro) {
    Nodo* nuevo_nodo = new Nodo{nuevo_libro, nullptr, nullptr};

    // Validacion simple: Si la lista esta vacia
    if (lista_inicio == nullptr) {
        lista_inicio = nuevo_nodo;
    } else {
        nuevo_nodo->siguiente = lista_inicio;
        lista_inicio->anterior = nuevo_nodo;
        lista_inicio = nuevo_nodo; // El puntero global ahora apunta al nuevo primero
    }
    std::cout << "\n[!] Libro insertado al inicio con exito.\n";
}

// Operacion: Insertar al final de la lista doble
void insertar_al_final(const Libro& nuevo_libro) {
    Nodo* nuevo_nodo = new Nodo{nuevo_libro, nullptr, nullptr};

    // Validacion simple: Si es el primer elemento
    if (lista_inicio == nullptr) {
        lista_inicio = nuevo_nodo;
    } else {
        // Al no tener un puntero 'fin' global, recorremos hasta llegar al ultimo
        Nodo* actual = lista_inicio;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = actual;
    }
    std::cout << "\n[!] Libro insertado al final con exito.\n";
}