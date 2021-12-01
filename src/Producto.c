#include "Nexo.h"
int producto_altaProducto(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria,int* id)
{
	eProducto auxProducto;
	int ok=-1;
	int perritoId;
	int index;
	//int idEstadia;
	printf("Alta\n"
	"---------------------------------------\n");
	index=producto_espacioDisponible(producto,tam);
	if(index!=-1)
	{
		*id = *id+1;
		auxProducto.id = *id;
		utn_getCadena(auxProducto.nombre,100,21,"Ingrese el nombre del producto:","Error\n");
		utn_getCadena(auxProducto.descripcion,100,31,"Ingrese la descripcion del producto:","Error\n");
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
		producto[index].id=auxProducto.id;
		producto[index].isEmpty=0;
		strcpy(producto[index].nombre,auxProducto.nombre);
		strcpy(producto[index].descripcion,auxProducto.descripcion);
		producto[index].precio=auxProducto.precio;
		producto[index].idCategoria=auxProducto.idCategoria;

		ok=0;
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
	printf("%-10d	%-10s	%-10s	%-10s\n",producto.id,producto.nombre,producto.descripcion,categoria.nombre);
}


void producto_mostrarTodas(eProducto producto[],int tam,eCategoria categoria[],int tamCategoria)
{
	printf("ID		NOMBRE		DESCRIPCION		CATEGORIA\n");
	for(int i=0;i<tam;i++)
	{
		if(producto[i].isEmpty==0)
		{
			for(int j=0;j<tamCategoria;j++)
			{
				if(producto[i].idCategoria==categoria[j].id)
				{
					producto_mostrarUno(producto[i],categoria[j]);
				}
			}
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
	printf("ID		NOMBRE		TELEFONO	PERRO		FECHA\n");
	producto_mostrarUno(producto[index],categoria[indexCategoria]);
	utn_getEntero(&opcion,100,"Que quiere modificar??\n"
			"1.Telefono\n"
			"2.Perro\n"
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
	printf("ID		NOMBRE		TELEFONO	PERRO		FECHA\n");
	producto_mostrarUno(producto[index],categoria[indexCategoria]);
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
	for(int i=0;i<tam;i++)
	{
		if(producto[i].isEmpty==0)
		{
			precioMaximo=precioMaximo+producto[i].precio;
			cant++;
		}

	}
	promedioPrecio=precioMaximo/cant;
	printf("El promedio del precio es:%2.f",promedioPrecio);
}


void producto_hardcodearProducto(eProducto producto[])
{
	int id[]={100000,100001,100002,100003};
	//char nombre[][21]={"jazmin","agustin","alan","aalan"};
	char nombre[][]= {"jose","agustin","alan"};
	float precio[]={2000,4000,2350};
	for(int i=0;i<4;i++)
	{
		estadia[i].id=id[i];
		//strcpy(estadia[i].nombreDuenio,nombre[i]);
		estadia[i].duenio=duenio[i];
		estadia[i].telefonoContacto=telefono[i];
		estadia[i].idPerro=perro[i];
		estadia[i].fecha.dia=dia[i];
		estadia[i].fecha.mes=mes[i];
		estadia[i].fecha.anio=anio[i];
		estadia[i].isEmpty=0;
	}
}
