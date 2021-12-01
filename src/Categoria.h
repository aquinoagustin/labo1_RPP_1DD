/*
 * Categoria.h
 *
 *  Created on: 1 dic 2021
 *      Author: Akino
 */

#ifndef CATEGORIA_H_
#define CATEGORIA_H_

typedef struct{
	int id;
	char nombre[21];
	int isEmpty;
}eCategoria;

void categoria_inicializarCategoria(eCategoria categoria[],int tamCategoria);
void categoria_hardcodearCategorias(eCategoria categoria[]);
void categoria_mostrarUno(eCategoria categoria);
int categoria_mostrarTodos(eCategoria categoria[],int tamCategoria);
int categoria_encontrarPorId(eCategoria categoria[],int tamCategoria,int id);
#endif /* CATEGORIA_H_ */
