/*
INTEGRANTES: Victoria RamÃ­rez Castro y Diego Curiel
MATRICULAS: A01640824 y A01640372
ACTIVIDAD: Proyecto Integrador 
FECHA: 02/12/2021
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Almacen.h"
#include "Carrito.h"

using namespace std;

Almacen::Almacen(){
    ifstream lector("Productos.txt"); //lee el archivo "Productos"
    string linea, // inicializa variables para cada linea del archivo cada campo
           campo;
    // inicializa las variables para contar la cantidad de productos y propiedades de cada producto
    int index = 0, 
        cant;
    while (!lector.eof()){   
        // lee cada linea del archivo hasta llegar al final del archivo y la guarda en la variable linea
        getline(lector, linea);
        stringstream ss(linea);
        // se inicializa el arreglo con las propiedades para cada producto
        string propiedades[4] = {}; 
        cant = 0;
        // separa la linea cada que encuentra una coma y guarda esa informacion en la varibale campo, que despues se guarda en el arreglo de las propiedade
        while(getline(ss, campo, ',')){  
            propiedades[cant] = campo; 
            cant ++;
        }
        // se crea un producto de la clase almacen al cual se le mete el arreglo con las 4 propiedades, por cada linea del archivo
        ProductoAlmacen producto(propiedades); 
        this->productos[index] = producto;  
        index ++; // aumenta dependiendo de la cantidad de productos (lineas) que tenga el archivo (o sea, cuantos productos tiene el almacen)
    }
    lector.close();  
    this->size = index; 
}

//Metodo para imprimir la lista de productos en existencia
void Almacen::abrirAlmacen(){
    cout<<"\n-------Productos en Existencia-----------"<<endl;
    cout<<"\nID NOMBRE COST$ CANT"<<endl;
    for (int i = 0; i < this->size; i++){ 
        this->productos[i].imprimir(); 
    }
}

//Metodo para verificar si existe un ID, de ser asi, verifica si la cantidad esta disponible
bool Almacen::verificar(string id, int cant){
    bool verificado = false;
    for (int i = 0; i < this->size; i++){
        if (this->productos[i].getId() == id && this->productos[i].getExistencia() >= cant){
            //productos[i].reducirExistencia(cant); --> hasta pagar puedo quitarselo
            verificado = true;
        }
    }
    return verificado;
}

//Metodo para regresar los datos del ID solicitado.
//Recorrido por todos los Id para regresar el buscado
ProductoAlmacen Almacen::getProducto(string id){
    ProductoAlmacen producto;
    for (int i = 0; i < this->size; i++){
        if (this->productos[i].getId() == id){
            return this->productos[i]; //si el ID concuerda, regresa el producto
        }
    }
    return producto;
}

// Metodo para reducir la existencia de cantidad de productos del almacen
void Almacen::reducirExistencia(Carrito &carro)
{
    for (int i = 0; i < carro.getSize(); i++) //recorre todo el carrito
    {   //obtiene cada id de los productos del carrito y su cantidad
        string productoIdAct = carro.obtenerId(i); 
        int cantCarrito = carro.obtenerCant(i);
        for (int j = 0; j < this->size; j++){ //recorre toda la lista del almance
        // si los id coincidcen, se resta del almacen dependiendo de la cantidad que se obtuvo del carrito
            if (this->productos[j].getId() == productoIdAct){
                int existenciaP = this->productos[j].getExistencia();
                int existenciaN = existenciaP - cantCarrito;
                productos[j].setExistencia(existenciaN);
                break;
            }
        }
    }
}