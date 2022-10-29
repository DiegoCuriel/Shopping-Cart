/*
INTEGRANTES: Victoria RamÃ­rez Castro y Diego Curiel
MATRICULAS: A01640824 y A01640372
ACTIVIDAD: Proyecto Integrador 
FECHA: 02/12/2021
*/

#ifndef PRODUCTOALMACEN_H
#define PRODUCTOALMACEN_H 
#include <string>

using namespace std;

class ProductoAlmacen{
    private:
        string id;
        string nombre;
        double precio;
        int existencia;
    public: 
        ProductoAlmacen();
        ProductoAlmacen(string caracteristicas[]);
        string getNombre();
        string getId();
        double getPrecio();
        int getExistencia();
        void imprimir();
        void setExistencia(int existencia);
};

#endif