/*
INTEGRANTES: Victoria RamÃ­rez Castro y Diego Curiel
MATRICULAS: A01640824 y A01640372
ACTIVIDAD: Proyecto Integrador 
FECHA: 02/12/2021
*/

#include <iostream>
#include <string>
#include "ProductoAlmacen.h"
#include "Carrito.h"

using namespace std;

//Constructor que inicializa el objeto vacio
ProductoAlmacen::ProductoAlmacen(){
    this->id = "";
    this->nombre = "";
    this->precio = 0.0;
    this->existencia = 0;
}

//Constructor que le asigna los atributos a cada objeto
ProductoAlmacen::ProductoAlmacen(string caracteristicas[]){
    this->id = caracteristicas[0];
    this->nombre = caracteristicas[1];
    this->precio = stod(caracteristicas[2]);
    this->existencia = stoi(caracteristicas[3]);
}

//Regresa el Nombre
string ProductoAlmacen::getNombre(){
    return this-> nombre;
}

//Regresa el ID
string ProductoAlmacen::getId(){
    return this-> id;
}

//Regresa el Precio
double ProductoAlmacen::getPrecio(){
    return this-> precio;
}

//Regresa la cantidad de productos en existencia
int ProductoAlmacen::getExistencia(){
    return this-> existencia;
}

//Imprime a pantalla los atributos del objeto, ID - Nombre - Precio - Existencia
void ProductoAlmacen::imprimir(){
    cout<<this->id<<","<<this->nombre<< ","<<this->precio<<","<<this->existencia<<endl;
}


// Setter para "actualizar" la cantidad articulos de cada producto del carrito
void ProductoAlmacen::setExistencia(int existencia){
    this->existencia = existencia;
}