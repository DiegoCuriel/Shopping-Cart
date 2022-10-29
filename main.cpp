/*
INTEGRANTES: Victoria Ramírez Castro y Diego Curiel
MATRICULAS: A01640824 y A01640372
ACTIVIDAD: Proyecto Integrador 
FECHA: 02/12/2021
*/

#include <iostream>
#include <string>
#include "Carrito.h"
#include "Almacen.h"
#include <fstream>
#include <sstream>

using namespace std;

int main()
{   
    // Crear los objetos de la clase almacen y carrito
    Almacen almacen;
    Carrito carro;

    // Inicializo varibales
    int opc = 0,
        cantidad = 0,
        cantidadN = 0,
        eleccion = 0;
    string id = " ",
           idN = " ",
           comprobar = "N";

    // While para estar mostrando el menu
    while (opc != 6)
    {
        cout << endl
             << "-------------M E N U----------------" << endl
             << "1) Ver productos" << endl
             << "2) Comprar" << endl
             << "3) Ver carrito" << endl
             << "4) Editar" << endl
             << "5) Pagar" << endl
             << "6) Salir" << endl;

        cout << "Opcion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            almacen.abrirAlmacen(); // Mostrar los productos del almacen
            break;
        case 2:
            while (comprobar != "S")
            {
                // Pregunta al usuario el id del producto que quiere el usuario y la cantidad que desea comprar
                cout << endl
                     << "-------------AGREGAR AL CARRITO----------------" << endl;
                cout << "Id: ";
                cin >> id;
                cout << "Cantidad: ";
                cin >> cantidad;
                cout << cantidad << " productos a comprar, del producto " << id;
                cout << "\n¿Son correctos estos datos? (S/N): ";
                cin >> comprobar;

                if (comprobar == "S")
                {   // Verifica si ese id existe en almacen y si hya suficiente cantidad de producto
                    if (almacen.verificar(id, cantidad)){
                        cout<<"\nProducto agregado al carrito"<<endl;
                        // si si existe en almacen y si hay producto, se copian los datos de ese producto al carrito
                        carro.addItem(almacen.getProducto(id), cantidad);
                    }else{
                        cout<<"\nProducto o la cantidad invalido"<<endl;
                    }
                    comprobar = "N";
                    
                    break;
                }
            }

            break;
        case 3:
            // Te muestra todos los productos que tienes en carrito
            cout << endl
                     << "-------------CARRITO----------------" << endl;
            carro.mostrarCarrito();
            break;
        case 4:
            // Te pregunta si quieres modificar o eliminar el producto
            cout << endl
            << "-------------MODIFICAR CARRITO----------------" << endl;
            cout << "Eliga una opcion"<<endl;
            cout<<"1) Modificar producto"<<endl
                <<"2) Eliminar producto"<<endl
                <<"Opcion: ";
            cin >> eleccion;

            comprobar = "N";
            while (comprobar != "S")
            {
                if (eleccion == 1)
                {   
                    // Si el usuario elige modifcar el producto, le pregunta al usuario cual producto y la nueva cantidad que desea
                    cout << "\nId del producto a modificar: ";
                    cin >> idN;
                    cout << "Cantidad nueva: ";
                    cin >> cantidadN;
                    cout << "Quiere modificar el articulo " << idN << " a la cantidad de " << cantidadN <<" productos."<<"\n¿Es correcto?(S/N): ";
                    cin >> comprobar;
                    eleccion = 1;
                    if (comprobar == "S")
                    {
                        if (almacen.verificar(idN, cantidadN)){
                            cout<<"\nProducto modificado"<<endl;
                            carro.modificar(idN, cantidadN);
                        }else{
                            cout<<"\nProducto o la cantidad invalido"<<endl;
                        }
                        comprobar = "N";  
                        break;
                    }
                } else{ // Si quiere eliminarlo, solo te pide el id y elimina el producto
                    cout << "\nId del producto a eliminar: ";
                    cin >> idN;
                    cantidadN = 0;
                    cout << "¿Esta segur@ que quiere eliminar el producto "<<idN<<" de su carrito? (S/N) ";
                    cin >> comprobar;
                    eleccion = 2;
                    if (comprobar == "S"){
                        cout<<"\nProducto eliminado"<<endl;
                        carro.modificar(idN, cantidadN);
                        comprobar = "N";
                        break;
                    }       
                }
            }
            break;
        case 5:
        // Te muestra el total de tu compra, se descuentan la cantidad de productos que hay en el carrito, del almacen, y despues se borran los productos del carrito
            cout << endl
                 << "-------------CARRITO----------------" << endl;
            cout << "La cuenta total a pagar es de $" << carro.total() << endl;
            cout << "GRACIAS POR TU COMPRA" << endl;
            
            //Descontar del almacen
            almacen.reducirExistencia(carro);
            
            //vaciar carrito
            carro.vaciar();
            break;
            
        case 6:
        // Se termina el programa
            cout << "Saliendo......";
            break;
            
        default:
            break;
        }
    }
    return 0;
}