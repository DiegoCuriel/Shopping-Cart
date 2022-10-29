/*
INTEGRANTES: Victoria RamÃ­rez Castro y Diego Curiel
MATRICULAS: A01640824 y A01640372
ACTIVIDAD: Proyecto Integrador 
FECHA: 02/12/2021
*/

#ifndef CARRITO_H 
#define CARRITO_H
#include <string>
#include <iostream>
#include "ProductoCarrito.h"

using namespace std;

class Carrito{
    private:
        string cliente;
        ProductoCarrito productos[10];
        int size;
        
    public:
        Carrito();
        void addItem(ProductoAlmacen producto, int cantidad);
        void mostrarCarrito();
        void modificar(string id, int cantidad);
        double total();
        void vaciar();
        string obtenerId(int index);
        int obtenerCant(int index);
        int getSize();
        
};

#endif