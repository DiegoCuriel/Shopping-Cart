/*
INTEGRANTES: Victoria RamÃ­rez Castro y Diego Curiel
MATRICULAS: A01640824 y A01640372
ACTIVIDAD: Proyecto Integrador 
FECHA: 02/12/2021
*/

#include <iostream>
#include <string>
#include "Carrito.h"
#include "ProductoAlmacen.h"

// se crea el constructor de la clase y se inicializan valores
Carrito::Carrito(){
    this-> cliente = "Victoria y Curiel";
    this-> size = 0;
}

// metodo que recibe un producto y la cantidad deseada a agregar al carrito
void Carrito::addItem(ProductoAlmacen producto, int cantidad){
    //cout<<this->size ++;
    ProductoCarrito compra(producto, cantidad);
    productos[this->size] = compra;
    this->size ++; // cuenta cuantos productos tienes en tu carrito
}

// imprime los valores que tengas en el carrito y calcula cuanto vas a pagar por producto
void Carrito::mostrarCarrito(){
    cout<<"\nCarritos de compra de "<<this->cliente<<endl;
    cout<<"\nID NOMBRE COST$ CANT SUBTOTAL"<<endl;
    double subtotal = 0;
    for (int i = 0; i < this->size; i++){ 
        this->productos[i].imprimir(); 
    }
    //cout<<"\nTotal de su compra: $"<<total()<<endl;
}

// calcula el precio total a pagar de todos los productos del carrito
double Carrito::total(){
    double total = 0;
    for (int i = 0; i < this->size; i++){ 
        total = total + this->productos[i].subtotal();
    }
    return total;
}

// metodo que recibe un id y una cantidad, y modifica la cantidad de producto de un item (id) especifico
void Carrito::modificar(string id, int cantidad){
    for (int i = 0; i < this->size; i++){
        if (cantidad > 0){
            if (this->productos[i].getId() == id){
                this->productos[i].setCantidad(cantidad);
                break;
            }
        }
        else{
            if (this->productos[i].getId() == id){
                this->productos[i] = this->productos[size-1];
                this->size --;
                break;
                //borrar producto
            } 
        } 
    }
}

// metodo que te imprime el valor total de tu compra, vacia el carrito y descuenta los productos del almacen
void Carrito::vaciar(){
    int tam = this->size;
    for (int i = 0; i < tam; i++)
    {
        this->productos[i] = this->productos[size-1];
        this->size --;
    }
}

// getter para obtener cuantos productos hay en el carrito
int Carrito::getSize(){
    return this->size;
}

// getter para obtener cada id y cada cantidad, de todos los productos que hay en carrito
string Carrito::obtenerId(int index){
    
    return this->productos[index].getId();
}

int Carrito::obtenerCant(int index){

    return this->productos[index].getCantidad();
}