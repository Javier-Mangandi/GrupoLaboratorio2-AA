
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
Nodo *inicio = nullptr;
Nodo *fin = nullptr;

int main()
{
    // Aquí puedes agregar la lógica base:
    // Datos quemados (hardcoded) para probar o el menú principal.

    std::cout << "--- Sistema de Biblioteca Inicializado ---\n";

    return 0;
}