#include "Nexo.h"


void categoria_inicializarCategoria(eCategoria categoria[],int tamCategoria)
{
	for(int i=0;i<tamCategoria;i++)
	{
		categoria[i].isEmpty=1;
	}
}

void categoria_hardcodearCategorias(eCategoria categoria[])
{
	int id[]={2000,2001,2002};
	char nombre[][21]={"Comida","Juguetes","Golosinas"};
	for(int i=0;i<3;i++)
	{
		categoria[i].id=id[i];
		strcpy(categoria[i].nombre,nombre[i]);
		categoria[i].isEmpty=0;
	}
}



int categoria_encontrarPorId(eCategoria categoria[],int tamCategoria,int id)
{
	int ok=-1;
	for(int i=0;i<tamCategoria;i++)
	{
		if(categoria[i].id==id)
		{
			ok=i;
			break;
		}
	}
	return ok;
}



void categoria_mostrarUno(eCategoria categoria)
{
	printf("%-10d	%-10s\n",categoria.id,categoria.nombre);
}

int categoria_mostrarTodos(eCategoria categoria[],int tamCategoria)
{
	clear();
	int ok=-1;
	printf("-------------------------------\n");
	printf("ID		NOMBRE\n");
	printf("-------------------------------\n");
	for(int i=0;i<tamCategoria;i++)
	{
		if(categoria[i].isEmpty==0)
		{
			printf("-------------------------------\n");
			categoria_mostrarUno(categoria[i]);
			printf("-------------------------------\n");
		}
	}
	return ok;
}

void categoria_listadoCategoriaProducto(eCategoria categoria[],int tamCategoria,eProducto producto[],int tam)
{

	for(int i=0;i<tamCategoria;i++)
	{
		printf("-----------------------------------------------------------------------------------\n");
		printf("%s\n-----------------------------------------------------------------------------------\n\n",categoria[i].nombre);
		for(int j=0;j<tam;j++)
		{
			if(categoria[i].id==producto[j].idCategoria)
			{
				printf("-----------------------------------------------------------------------------------\n");
				producto_mostrarUno(producto[j],categoria[i]);
				printf("-----------------------------------------------------------------------------------\n");
			}
		}
	}
}
