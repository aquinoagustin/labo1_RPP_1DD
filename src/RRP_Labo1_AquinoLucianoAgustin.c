/*
 ============================================================================
 Name        : parcialPractica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Nexo.h"
int main(void) {
	setbuf(stdout,NULL);
	eProducto producto[TAM];
	eCategoria categoria[TAMCategoria];
	categoria_inicializarCategoria(categoria,TAMCategoria);
	producto_inicializarProducto(producto,TAM);
	categoria_hardcodearCategorias(categoria);
	//producto_hardcodearProducto(producto);
	int id=999;
	menu(producto,TAM,categoria,TAMCategoria,&id);
	return EXIT_SUCCESS;
}




void menu(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria,int* id)
{
	int opcion;
	int idProducto;
	int index;
	do
	{
		utn_getEntero(&opcion,100,"1.Cargar Producto\n"
				"2.Modificar Producto\n"
				"3.Borrar Producto\n"
				"4.Listar Productos\n"
				"5.Listar Categorias\n"
				"6.Promedio de precio de todos los productos\n"
				"7.Listado de categorias con sus productos\n"
				"8.Salir\n"
				"Eliga una opcion:","Error\n",1,8);
		switch(opcion)
		{
			case 1:
				clear();
				if(!producto_altaProducto(producto,tam,categoria,tamCategoria,id))
				{
					printf("Estadia dada de alta\n");
				}
				else
				{
					printf("No se pudo dar el alta\n");
				}
				systemPause();
				break;
			case 2:
				clear();
				if(!producto_isEmpty(producto,tam))
				{
					producto_mostrarTodas(producto,tam,categoria,tamCategoria);
					utn_getEntero(&idProducto,100,"Ingrese el id del producto:","Error\n",1,300000);
					index=producto_encontrarPorId(producto,tam,idProducto);
					if(index!=-1)
					{
						if(!producto_modificarProducto(producto,tam,categoria,tamCategoria,idProducto))
						{
							printf("Producto modificado\n");
						}
						else
						{
							printf("Se cancelaron los cambios\n");
						}
					}
					else
					{
						printf("Error producto no encontrado\n");
					}
				}
				else
				{
					printf("Primero cargue un producto\n");
				}
				systemPause();
				break;
			case 3:
				clear();
				if(!producto_isEmpty(producto,tam))
				{
					producto_mostrarTodas(producto,tam,categoria,tamCategoria);
					utn_getEntero(&idProducto,100,"Ingrese el id del producto:","Error\n",1,300000);
					if(producto_encontrarPorId(producto,tam,idProducto)!=-1)
					{
						if(!producto_eliminarProducto(producto,tam,categoria,tamCategoria,idProducto))
						{
							printf("Producto Eliminado\n");
						}
						else
						{
							printf("Se cancelaron los cambios\n");
						}
					}
					else
					{
						printf("Producto no encontrado\n");
					}
				}
				else
				{
					printf("Primero cargue un Producto\n");
				}
				systemPause();
				break;
			case 4:
				clear();
				if(!producto_isEmpty(producto,tam))
				{
					producto_sortProducto(producto,tam);
					producto_mostrarTodas(producto,tam,categoria,tamCategoria);
				}
				else
				{
					printf("Primero cargue un producto\n");
				}
				systemPause();
				break;
			case 5:
				clear();
				categoria_mostrarTodos(categoria,tamCategoria);
				systemPause();
				break;
			case 6:
				clear();
				if(!producto_isEmpty(producto,tam))
				{
					producto_promedioPrecios(producto,tam);
				}
				else
				{
					printf("Primero cargue nun producto\n");
				}
				systemPause();
				break;
			case 7:
				clear();
				if(!producto_isEmpty(producto,tam))
				{
					categoria_listadoCategoriaProducto(categoria,tamCategoria,producto,tam);
				}
				else
				{
					printf("Primero cargue un producto\n");
				}
				systemPause();
				break;
			case 8:
				clear();
				printf("Usted ha salido\n");
				systemPause();
				break;
		}
	}while(opcion!=9);
}
