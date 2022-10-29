/*
INTEGRANTES: Victoria RamÃ­rez Castro y Diego Curiel
MATRICULAS: A01640824 y A01640372
ACTIVIDAD: Proyecto Integrador 
FECHA: 02/12/2021
*/

#include <iostream>
#include <string>
#include "ProductoCarrito.h"

// inicializar el contructor
ProductoCarrito::ProductoCarrito(){
    this-> id = " ";
    this-> nombre = " ";
    this-> precio = 0.0;
    this-> cantidad = 0;
}

// asignarle los datos del producto que "copiamos" del almacen pero con la cantidad indicada por el producto
ProductoCarrito::ProductoCarrito(ProductoAlmacen producto, int cantidad){
    this-> id = producto.getId();
    this-> nombre = producto.getNombre();
    this-> precio = producto.getPrecio();
    this-> cantidad = cantidad;
}
// getter para obtener las caracteristicas del producto del carrito

string ProductoCarrito::getId(){
    return this-> id;
}

int ProductoCarrito::getCantidad(){
    return this-> cantidad;
}

// cambia el valor de cantidad al indicado por el usuario
void ProductoCarrito::setCantidad(int cantidad){
    this-> cantidad = cantidad;
}

// imprime las caracteristicas del producto y el precio a pagar dependiento de la cantidad de productos a comprar de cada item
void ProductoCarrito::imprimir(){
    cout<<this->id<< ","<<this->nombre<<","<<this->precio<< ","<<this->cantidad<<","<<subtotal()<<endl;
}

// calcular el precio por cada item dependiendo de los productos a comprar
double ProductoCarrito::subtotal(){
    double suma = 0;
    suma = suma + (this->precio*this->cantidad);
    return suma;
}