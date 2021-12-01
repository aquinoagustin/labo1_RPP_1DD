#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED

int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,long long int max);
/*
 * @brief Esta funcion se encarga de pedir un numero entero y validarlo
 * @param Recibe como puntero un entero
 * @param Recibe el numero de intentos que permitira la validacion
 * @param Recibe un mensaje que se mostrara al usuario
 * @param Recibe un mensaje de error que se mostrara al usuario
 * @param Recibe el minimo que aceptara la funcion
 * @param Recibe el maximo que aceptara la funcion
 * */


int getInt(int* pAux);
/*
 * @brief Esta funcion se complementa con utn_getEntero
 * @param Recibe como puntero el entero ingresado previamente cargado de utn_getEntero
 * */

int isInt(char *pAux);
/*
 * @brief Esta funcion se complementa con utn_getEntero
 * @param Recibe como puntero un char
 * */

int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max);
/*
 * @brief Esta funcion se encarga de pedir un numero flotante y validarlo
 * @param Recibe como puntero un flotante
 * @param Recibe el numero de intentos que permitira la validacion
 * @param Recibe un mensaje que se mostrara al usuario
 * @param Recibe un mensaje de error que se mostrara al usuario
 * @param Recibe el minimo que aceptara la funcion
 * @param Recibe el maximo que aceptara la funcion
 * */

int getFloat(float*pAux);

/*
 * @brief Esta funcion se complementa con utn_getFlotante
 * @param Recibe como puntero el flotante ingresado previamente cargado de utn_getFlotante
 * */

int isFloat(char* pAux);

/*
 * @brief Esta funcion se complementa con utn_getFlotante
 * @param Recibe como puntero un char
 * */


int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError);

/*
 * @brief Esta funcion se encarga de pedir una cadena y validarla
 * @param Recibe como puntero una cadena
 * @param Recibe el limite de la cadena
 * @param Recibe el numero de intentos que permitira la validacion
 * @param Recibe un mensaje que se mostrara al usuario
 * @param Recibe un mensaje de error que se mostrara al usuario
 * */


int getCadena(char* pAux,int limite);

/*
 * @brief Esta funcion se complementa con utn_getCadena
 * @param Recibe como puntero la cadena ingresada previamente cargada en utn_getCadena
 * */


int isLetras(char*pAux);

/*
 * @brief Esta funcion se complementa con utn_getCadena
 * @param Recibe como puntero un char
 * */

int pedirCaracter(char* caracter, char* mensaje);

/*
 * @brief Esta funcion se encarga de pedir un caracter y verifica que cumpla las condiciones
 * @param cadena Recibe como puntero un caracter
 * @param mensaje Recibe el mensaje que se mostrara por pantalla
 * @return Retorna 0, para verificar que se cumplio, sino retorna -1
 * */

void pasarMinuscula(char* cadena);
/*
 * @brief Esta funcion se encarga de pasar todas las letras a minusculas
 * @param cadena Recibe una cadena
 * */

void pasarMayuscula(char* cadena);
/*
 * @brief Esta funcion se encarga de pasar todas las letras a mayusculas
 * @param cadena Recibe una cadena
 * */
void clear();
/*
 * @brief Esta funcion se encarga de limpiar la pantalla agregando printn("\n")
 * */


int confirmacion();
/*
 * @brief Esta funcion se encarga de hacer una confirmacion, devuelve 0 si se confirma sino devuelve -1
 * */


int systemPause();

#endif // VALIDACION_H_INCLUDED
