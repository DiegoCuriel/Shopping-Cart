/*
INTEGRANTES: Victoria RamÃ­rez Castro y Diego Curiel
MATRICULAS: A01640824 y A01640372
ACTIVIDAD: Proyecto Integrador 
FECHA: 02/12/2021
*/

#ifndef PRODUCTOCARRITO_H
#define PRODUCTOCARRITO_H
#include "ProductoAlmacen.h"
#include <string>
#include <iostream>

using namespace std;

class ProductoCarrito{
    private:
        string id;
        string nombre;
        double precio;
        int cantidad;

    public:
        ProductoCarrito();
        ProductoCarrito(ProductoAlmacen producto, int cantidad);
        void imprimir();
        string getId();
        int getCantidad();
        void setCantidad(int cantidad);
        double subtotal();
};

#endif