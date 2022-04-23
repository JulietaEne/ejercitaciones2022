/*
 * passenger.c
 *
 *  Created on: 20 abr. 2022
 *      Author: juliet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "tp.h"
#include "arrays.h"
#include "validaciones.h"
#include "passenger.h"

#define IS_EMPTY 0
#define NOT_EMPTY 1
#define SIZE_STR 51
#define REINTENTOS 2
#define SIZE_CODE 10
#define MAX_PRICE 200000
#define MIN_PRICE 15000
#define MAX_TYPEPASSENGER 5
#define MIN_TYPEPASSENGER 1

/** \brief To indicate that all position in the array are empty,
* 		this function put the flag (isEmpty) in TRUE in all
* 		position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int passenger_initArray(ePassenger* listPassenger, int sizeListPassenger)
{
	int retorno;
	int i;
	retorno = -1;

	if(listPassenger != NULL && sizeListPassenger>0)
	{
		for (i=0; i<sizeListPassenger; i++)
		{
			passenger_initAPossition(listPassenger, i, IS_EMPTY);
		}
		retorno = 0;
	}
	return retorno;
}

/*
 * \breif To assign a init value to array's a particular possition
 * \param listPassenger ePassenger* receives the array which will be operated
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \param valor Recibe por valor el dato que se asigna
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si opero exitosamente
 *
*/
int passenger_initAPossition(ePassenger* listPassenger, int indice, int valorInicial)
{
	int retorno;
	retorno = -1;

	if(listPassenger!= NULL)
	{
		listPassenger[indice].isEmpty = valorInicial;
		retorno = 0;
	}

	return retorno;
}
/*
 * recorre el array recibido
 * retorna -1 si hubo una falla en los parametros recibidos
 * 			>=0 si encontró un espacio libre
 */
int passenger_firstEmptyPosition(ePassenger* listPassenger, int sizeListPassenger)
{
	int retorno;
	int i;
	retorno = -1;
	if(listPassenger != NULL && sizeListPassenger>0)
	{
		for(i=0; i<sizeListPassenger; i++)
		{
			if(listPassenger[i].isEmpty == 0)
			{
				retorno=i;
				break;
			}
			/*else
			{
				tp_MensajeErrorGenerico(retorno);
			}*/
		}
	}
	return retorno;
}



/** \brief add in a existing list of passengers the values received
* 		as parameters in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
* \free space] - (0) if Ok
* 				-2 no se encontró espacio para guardar el elemento
*/
int passenger_addPassengerToArray(ePassenger* listPassenger, int sizeListPassenger, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int retorno;
	int indiceIsEmpty;
	retorno = -1;
	if( listPassenger!= NULL && sizeListPassenger >0 && name != NULL)// && lastName != NULL && flycode != NULL)
	{
		indiceIsEmpty =passenger_firstEmptyPosition(listPassenger, sizeListPassenger);

		if(indiceIsEmpty >=0)
		{
			strncpy(listPassenger[indiceIsEmpty].name, name, SIZE_STR);
			strncpy(listPassenger[indiceIsEmpty].lastName, lastName, SIZE_STR);
			listPassenger[indiceIsEmpty].id = id;//este id proviene de una variable autoincremental
			listPassenger[indiceIsEmpty].price = price;
			listPassenger[indiceIsEmpty].typePassenger = typePassenger;
			strncpy(listPassenger[indiceIsEmpty].flycode, flycode, SIZE_CODE);
			listPassenger[indiceIsEmpty].isEmpty = NOT_EMPTY;
			retorno=0;
		}
		else
		{
			tp_MensajeError("No hay espacio para nuevas cargas");
			retorno= -2;
		}
	}
	return retorno;
}

/*
* \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna 0 si opero exitosamente
 *
 */
int passenger_getNew(ePassenger* listPassenger, int sizeListPassenger, int id)
{
	int retorno;
	char nombre[SIZE_STR];
	char apellido[SIZE_STR];
	float precio;
	char codigoVuelo[SIZE_CODE];
	int tipoPasajero;

	retorno = -1;
	if(listPassenger!= NULL && sizeListPassenger >0)
	{
		retorno = -2;
		if( !passenger_getName(nombre, SIZE_STR)
			&& !passenger_getLastName(apellido, SIZE_STR)
			&& passenger_getPrice(&precio)>0
			&& !passenger_getFlyCode(codigoVuelo, SIZE_CODE)
			&& passenger_getTypePassenger(&tipoPasajero)>0
			)
		{
			passenger_addPassengerToArray(listPassenger, sizeListPassenger, id, nombre, apellido, precio, tipoPasajero, codigoVuelo);
			retorno = 0;
		}
	}
	return retorno;
}


////////////////////////***************GETTERS***************////////////////////////
/*
 * \breif interactua con el usuario para solicitar el nombre del cliente
 * \param listPassenger recibe el array dentro del cual se encuentra el elemento
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \param name[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeName tamaño del array de name
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna 0 si opero exitosamente
 *
 */
int passenger_getName(char name[], int sizeName)
{
	int retorno;
	char auxName [sizeName];
	retorno =-1;
	if(name!= NULL && sizeName>0)
	{
		retorno = -2;
		if(		!utn_ingresarAlfabetica(auxName, sizeName, "Ingrese nombre de cliente: ", "ERROR, ingrese un dato valido", REINTENTOS)
				&& validaciones_esNombre(auxName, sizeName)==1)
		{
			strncpy(name, auxName, sizeName);
			retorno = 0;
		}
	}
	return retorno;
}

/*
 * \breif interactua con el usuario para solicitar el nombre del cliente
 * \param listPassenger recibe el array dentro del cual se encuentra el elemento
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \param name[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeName tamaño del array de name
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna 0 si opero exitosamente
 *
 */
int passenger_getLastName(char lastName[], int sizeName)
{
	int retorno;
	char auxlastName [sizeName];
	retorno =-1;
	if(lastName!= NULL && sizeName>0)
	{
		retorno = -2;
		if(	!utn_ingresarAlfabetica(auxlastName, sizeName, "Ingrese apellido de cliente: ", "ERROR, ingrese un dato valido", REINTENTOS)
			&& validaciones_esNombre(auxlastName, sizeName)==1)
		{
			strncpy(lastName, auxlastName, sizeName);
			retorno = 0;
		}
	}
	return retorno;
}

/*
 * \breif interactua con el usuario para solicitar el nombre del cliente
 * \param listPassenger recibe el array dentro del cual se encuentra el elemento
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \param name[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeName tamaño del array de name
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna >0 si opero exitosamente
 *
 */
float passenger_getPrice(float* onePrice)
{
	//float retorno;
	float auxPrice;
	auxPrice=-1;

	if(onePrice!= NULL)
	{
		auxPrice=-2;
		if(!utn_GetNumeroFloat(&auxPrice, "precio: ", "ingrese un dato valido", MIN_PRICE, MAX_PRICE, REINTENTOS))
		{
			*onePrice=auxPrice;
		}
	}

	return auxPrice;
}

/*
 * \breif interactua con el usuario para solicitar el nombre del cliente
 * \param listPassenger recibe el array dentro del cual se encuentra el elemento
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \param name[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeName tamaño del array de name
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna 0 si opero exitosamente
 *
 */
int passenger_getFlyCode(char* oneFlyCode, int sizeCode)
{
	int retorno;
	char auxOneFlyCode[sizeCode];
	retorno=-1;
	if(oneFlyCode!= NULL && sizeCode > 0)
	{
		retorno = -2;
		if(!utn_getAlfaNumerica(auxOneFlyCode, sizeCode, "ingrese codigo de vuelo: ", "ingrese un codigo valido", REINTENTOS))//QUE HAY QUE TENER EN CUENTA PARA VALIDAR EL CODIGO ????
		{
			array_convertirStringMayuscula(auxOneFlyCode, sizeCode);
			array_eliminarTodosLosEspacios(auxOneFlyCode, sizeCode);

			strncpy(oneFlyCode, auxOneFlyCode, sizeCode);
			retorno=0;
		}
	}
	return retorno;
}

/*
 * \breif interactua con el usuario para solicitar el nombre del cliente
 * \param listPassenger recibe el array dentro del cual se encuentra el elemento
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \param name[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeName tamaño del array de name
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna >0 si opero exitosamente
 *
 */
int passenger_getTypePassenger(int* oneTypePassenger)
{
	int auxType;
	auxType = -1;
	if(oneTypePassenger!= NULL)
	{
		auxType=-2;
		if(!utn_GetNumeroInt(&auxType, "tipo de pasajero: ", "ingrese dato valido", MIN_TYPEPASSENGER, MAX_TYPEPASSENGER, REINTENTOS))
		{
			*oneTypePassenger=auxType;
		}
	}
	return auxType;
}
////////////////////////***************GETTERS***************////////////////////////
////////////////////////***************MODIFY***************////////////////////////
/*
 * \breif interactua con el usuario para solicitar el nombre del cliente
 * \param listPassenger recibe el array dentro del cual se encuentra el elemento
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \param name[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeName tamaño del array de name
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna 0 si opero exitosamente
 *
 */
int passenger_modifyName(ePassenger* listPassenger, int indexCarga, int sizeName)
{
	int retorno;
	char auxName [sizeName];
	retorno =-1;
	if(listPassenger!= NULL && sizeName>0 && indexCarga>=0)
	{
		retorno = -2;
		if(		!utn_ingresarAlfabetica(auxName, sizeName, "Ingrese nombre de cliente: ", "ERROR, ingrese un dato valido", REINTENTOS)
				&& validaciones_esNombre(auxName, sizeName)==1)
		{
			strncpy(listPassenger[indexCarga].name, auxName, sizeName);
			retorno = 0;
		}
	}
	return retorno;
}

int passenger_modifyNameOpcionDos(char campoNombre[], int sizeName)
{
	int retorno;
	char auxName[sizeName];
	retorno = -1;
	if(campoNombre!= NULL && sizeName>0)
	{
		retorno = -2;
		if(utn_ingresarAlfabetica(auxName, sizeName, "Ingrese nombre de cliente: ", "ERROR, ingrese un dato valido", REINTENTOS)
				&& validaciones_esNombre(auxName, sizeName))
		{
			strncpy(campoNombre, auxName, sizeName);
			retorno = 0;
		}
	}
	return retorno;
}





////////////////////////***************MODIFY***************////////////////////////
/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position
* 				 (-1) if [Invalid length or NULL pointer received or passenger not found]
*				-2 si no encontro ningun passenger con el id indicado
*/
int passenger_findPassengerById(ePassenger* listPassenger, int sizeListPassenger, int idRecibido)
{
	int indexEncontrado;
	int i;
	indexEncontrado = -1;
	if(listPassenger!= NULL && sizeListPassenger>0)
	{
		indexEncontrado=-2;
		for(i=0; i<sizeListPassenger; i++)
		{
			if(tp_sonIdenticos(listPassenger[i].isEmpty, NOT_EMPTY) && tp_sonIdenticos(listPassenger[i].id, idRecibido))
			{
				indexEncontrado=i;
				printf("DEBUG******* index: %d\n", i);
			}
		}

	}
	return indexEncontrado;
}



/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*

int removePassenger(Passenger* list, int len, int id)
{
	return -1;
}*/

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*

int sortPassengers(Passenger* list, int len, int order)
{
	return 0;
}*/

/** \brief print the content of passengers array
*
* \param listPassenger ePassenger* receives the array which will be analized
* \param sizeListPassenger int receives the value that indicates the array's size
* \return int -1 if error with de parameters
* 			  0 if its operates ok
*
*/
int passenger_print(ePassenger* listPassenger, int sizeListPassenger)
{
	int retorno;
	int i;
	retorno = -1;

	if(listPassenger != NULL && sizeListPassenger>0)
	{
		retorno = 0;
		for(i=0; i<sizeListPassenger; i++)
		{
			if(!tp_sonIdenticos(listPassenger[i].isEmpty,IS_EMPTY))
			{
				if(i==0)
				{
					printf("\nID\tNOMBRE\t\tAPELLIDO\tPRECIO\t\tCODIGO VUELO\tTIPO PASAJERO\n");
				}
				//printf("DEBUG** print pasajeros\n");
				passenger_printOnePosition(listPassenger, i);
			}
		}
	}
	return retorno;
}

int passenger_printOnePosition(ePassenger* listPassenger, int onePosition)
{
	int retorno;
	retorno = -1;

	if(listPassenger!= NULL && onePosition >=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf("%d %13s %16s %15.2f %12s %11d\n",
						listPassenger[onePosition].id,
						listPassenger[onePosition].name,
						listPassenger[onePosition].lastName,
						listPassenger[onePosition].price,
						listPassenger[onePosition].flycode,
						listPassenger[onePosition].typePassenger);
	}

	return retorno;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*

int sortPassengers(Passenger* list, int len, int order)
{
return 0;
}*/
