#include "Nexo.h"
int producto_altaProducto(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria,int* id)
{
	eProducto auxProducto;
	int ok=-1;
	int perritoId;
	int index;
	printf("Alta\n"
	"---------------------------------------\n");
	index=producto_espacioDisponible(producto,tam);
	if(index!=-1)
	{
		*id = *id+1;
		auxProducto.id = *id;
		utn_getCadena(auxProducto.nombre,21,100,"Ingrese el nombre del producto:","Error\n");
		utn_getCadena(auxProducto.descripcion,31,100,"Ingrese la descripcion del producto:","Error\n");
		utn_getFlotante(&auxProducto.precio,100,"Ingrese precio del producto:","Error\n",1,999999);
		categoria_mostrarTodos(categoria,tamCategoria);
		do
		{
			perritoId=-1;
			utn_getEntero(&auxProducto.idCategoria,100,"Eliga una categoria:","Error\n",2000,3000);
			if(categoria_encontrarPorId(categoria,tamCategoria,auxProducto.idCategoria)!=-1)
			{
				perritoId=0;
			}
		}while(perritoId==-1);
		pasarMinuscula(auxProducto.nombre);
		pasarMinuscula(auxProducto.descripcion);
		if(!confirmacion("Esta por dar de alta este producto"))
		{
			producto[index].id=auxProducto.id;
			producto[index].isEmpty=0;
			strcpy(producto[index].nombre,auxProducto.nombre);
			strcpy(producto[index].descripcion,auxProducto.descripcion);
			producto[index].precio=auxProducto.precio;
			producto[index].idCategoria=auxProducto.idCategoria;
			ok=0;
		}
	}
	return ok;
}



int producto_espacioDisponible(eProducto producto[],int tam)
{
	int ok=-1;
	for(int i=0;i<tam;i++)
	{
		if(producto[i].isEmpty==1)
		{
			ok=i;
			break;
		}
	}
	return ok;
}



void producto_inicializarProducto(eProducto producto[],int tamProducto)
{
	for(int i=0;i<tamProducto;i++)
	{
		producto[i].isEmpty=1;
	}
}



int producto_isEmpty(eProducto producto[],int tam)
{
	int ok=-1;
	for(int i=0;i<tam;i++)
	{
		if(producto[i].isEmpty==0)
		{
			ok=0;
			break;
		}
	}
	return ok;
}




void producto_mostrarUno(eProducto producto,eCategoria categoria)
{
	printf("%-10d	%-10s	%-10s	%-10.2f		%-10s\n",producto.id,producto.nombre,producto.descripcion,producto.precio,categoria.nombre);
}


void producto_mostrarTodas(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria)
{
	printf("-----------------------------------------------------------------------------------\n");
	printf("ID		NOMBRE		DESCRIPCION	PRECIO			CATEGORIA\n");
	printf("-----------------------------------------------------------------------------------\n");
	for(int i=0;i<tam;i++)
	{
		if(producto[i].isEmpty==0)
		{
			for(int j=0;j<tamCategoria;j++)
			{
				if(producto[i].idCategoria==categoria[j].id)
				{
					printf("-----------------------------------------------------------------------------------\n");
					producto_mostrarUno(producto[i],categoria[j]);
					printf("-----------------------------------------------------------------------------------\n");
				}
			}
		}
	}
}




void producto_mostrarUnoSolo(eProducto producto)
{
	printf("%-10d	%-10s	%-10s	%-10.2f\n",producto.id,producto.nombre,producto.descripcion,producto.precio);
}


void producto_mostrarTodasSolo(eProducto producto[],int tam)
{
	printf("-----------------------------------------------------------------------------------\n");
	printf("ID		NOMBRE		DESCRIPCION	PRECIO\n");
	printf("-----------------------------------------------------------------------------------\n");
	for(int i=0;i<tam;i++)
	{
		if(producto[i].isEmpty==0)
		{
			printf("-----------------------------------------------------------------------------------\n");
			producto_mostrarUnoSolo(producto[i]);
			printf("-----------------------------------------------------------------------------------\n");
		}
	}
}

int producto_encontrarPorId(eProducto producto[],int tam,int id)
{
	int ok=-1;
	for(int i=0;i<tam;i++)
	{
		if(producto[i].id==id&&producto[i].isEmpty==0)
		{
			ok=i;
			break;
		}
	}
	return ok;
}



int producto_modificarProducto(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria,int id)
{
	eProducto auxProducto;
	int ok=-1;
	int opcion;
	int index=producto_encontrarPorId(producto,tam,id);
	int indexCategoria=categoria_encontrarPorId(categoria,tamCategoria,producto[index].idCategoria);
	clear();
	printf("-----------------------------------------------------------------------------------\n");
	printf("ID		NOMBRE		DESCRIPCION	PRECIO			CATEGORIA\n");
	printf("-----------------------------------------------------------------------------------\n");
	producto_mostrarUno(producto[index],categoria[indexCategoria]);
	printf("-----------------------------------------------------------------------------------\n");
	utn_getEntero(&opcion,100,"Que quiere modificar??\n"
			"1.Categoria\n"
			"2.Precio\n"
			"Eliga una opcion:","Error\n",1,2);
	switch(opcion)
	{


	case 1:
		categoria_mostrarTodos(categoria,tamCategoria);
		utn_getEntero(&auxProducto.idCategoria,100,"Eliga una nueva categoria:","Error\n",1,3000);
		if(!confirmacion("Esta seguro que desea modificar la categoria?"))
		{
			if(index!=-1)
			{
				producto[index].idCategoria=auxProducto.idCategoria;
				ok=0;
			}
		}
		break;

	case 2:
		utn_getFlotante(&auxProducto.precio,100,"Eliga un nuevo precio:","Error\n",1,9999999999);
		if(!confirmacion("Esta seguro que desea modificar el telefono?"))
		{
			if(index!=-1)
			{
				producto[index].precio=auxProducto.precio;
				ok=0;
			}
		}
		break;
	}
	return ok;
}



int producto_eliminarProducto(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria,int id)
{
	int ok=-1;
	int index=producto_encontrarPorId(producto,tam,id);
	int indexCategoria=categoria_encontrarPorId(categoria,tamCategoria,producto[index].idCategoria);
	clear();
	printf("-----------------------------------------------------------------------------------\n");
	printf("ID		NOMBRE		DESCRIPCION	PRECIO			CATEGORIA\n");
	printf("-----------------------------------------------------------------------------------\n");
	producto_mostrarUno(producto[index],categoria[indexCategoria]);
	printf("-----------------------------------------------------------------------------------\n");
	if(index!=-1)
	{
		if(!confirmacion("Esta a punto de eliminar esta estadia"))
		{
			producto[index].isEmpty=1;
			ok=0;
		}
	}
	return ok;
}




int producto_sortProducto(eProducto producto[],int tam)
{
	int ok=-1;
	eProducto auxProducto;
	for(int i=0;i<tam;i++)
	{
		for(int j=i+1;j<tam-1;j++)
		{
			if(producto[i].precio<producto[j].precio)
			{
				auxProducto=producto[i];
				producto[i]=producto[j];
				producto[j]=auxProducto;
			}
			else
			{
				if(producto[i].precio==producto[j].precio)
				{
					if(strcmp(producto[i].nombre,producto[j].nombre)==1)
					{
						auxProducto=producto[i];
						producto[i]=producto[j];
						producto[j]=auxProducto;
					}
				}
			}
		}
	}
	return ok;
}



void producto_promedioPrecios(eProducto producto[],int tam)
{
	int cant=0;
	float precioMaximo=0;
	float promedioPrecio;
	producto_mostrarTodasSolo(producto,tam);
	for(int i=0;i<tam;i++)
	{
		if(producto[i].isEmpty==0)
		{
			precioMaximo=precioMaximo+producto[i].precio;
			cant++;
		}

	}
	promedioPrecio=precioMaximo/cant;
	printf("-------------------------------------------------\n");
	printf("El promedio del precio de los productos es:%2.f\n",promedioPrecio);
	printf("-------------------------------------------------\n");
}


void producto_hardcodearProducto(eProducto producto[])
{
	int id[]={1000,1001,1002};
	//char nombre[][21]={"jazmin","agustin","alan","aalan"};
	char nombre[][21]= {"jose","agustin","alan"};
	char descripcion[][31]={"asfasf","faafa","gaaa"};
	float precio[]={200,400,200};
	int categoria[]={2000,2002,2000};
	for(int i=0;i<3;i++)
	{
		producto[i].id=id[i];
		strcpy(producto[i].nombre,nombre[i]);
		strcpy(producto[i].descripcion,descripcion[i]);
		producto[i].precio=precio[i];
		producto[i].idCategoria=categoria[i];
		producto[i].isEmpty=0;
	}
}
