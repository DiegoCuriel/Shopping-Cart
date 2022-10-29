/*
INTEGRANTES: Victoria RamÃ­rez Castro y Diego Curiel
MATRICULAS: A01640824 y A01640372
ACTIVIDAD: Proyecto Integrador 
FECHA: 02/12/2021
*/

#ifndef ALMACEN_H
#define ALMACEN_H
#include "ProductoAlmacen.h"
#include "Carrito.h"


class Almacen{
    private:
        ProductoAlmacen productos[20];
        int size;
    public:
        Almacen();
        void abrirAlmacen(); 
        bool verificar(string id, int cant); 
        ProductoAlmacen getProducto(string id); 
        void reducirExistencia(Carrito &carro);
};

#endif