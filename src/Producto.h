

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct{
	int id;
	char nombre[21];
	char descripcion[31];
	float precio;
	int isEmpty;
	int idCategoria;
}eProducto;

void producto_inicializarProducto(eProducto producto[],int tamProducto);
int producto_isEmpty(eProducto producto[],int tam);
int producto_sortProducto(eProducto producto[],int tam);
int producto_encontrarPorId(eProducto producto[],int tam,int id);
void producto_promedioPrecios(eProducto producto[],int tam);
int producto_espacioDisponible(eProducto producto[],int tam);
#endif /* PRODUCTO_H_ */
