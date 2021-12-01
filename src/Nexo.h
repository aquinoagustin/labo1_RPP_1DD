

#ifndef NEXO_H_
#define NEXO_H_
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "validaciones.h"
#include "Producto.h"
#include "Categoria.h"
#define TAM 20
#define TAMCategoria 3
void menu(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria,int* id);
int producto_altaProducto(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria,int* id);
void producto_mostrarTodas(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria);
int producto_modificarProducto(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria,int id);
int producto_eliminarProducto(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria,int id);
#endif /* NEXO_H_ */
