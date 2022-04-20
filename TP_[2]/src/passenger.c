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

#define VALUE_INIT 0
#define SIZE_STR 51
#define REINTENTOS 2


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
			retorno = 0;
			for (i=0; i<sizeListPassenger; i++)
			{
				passenger_initAPossition(listPassenger, i, VALUE_INIT);
			}
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
int passenger_initAPossition(ePassenger* listPassenger, int sizeListPassenger, int valorInicial)
{
	int retorno;
	retorno = -1;

	if(listPassenger!= NULL)
	{
		listPassenger[sizeListPassenger].isEmpty = valorInicial;
		retorno = 0;
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

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	return -1;
}*/

/*
 * \breif interactua con el usuario para solicitar el nombre del cliente
 * \param name[] Recibe por referencia el array sobre el cual trabajara
 * \param lenName Recibe por valor el dato que se asigna
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si opero exitosamente
 *

int passenger_getName(char name[], int lenName, int unaPosicion)
{
	int retorno;
	char auxName [lenName];
	retorno =-1;
	if(name!= NULL && lenName>0 && unaPosicion >=0)
	{
		retorno = 0;
		if(		!utn_ingresarAlfabetica(auxName, lenName, "Ingrese nombre de cliente: ", "ERROR, ingrese un dato valido", REINTENTOS)
				&& validaciones_esNombre(auxName, lenName)==1)
		{
			strncpy(namee, auxName, lenName);
			retorno = 1;
		}
	}
	return retorno;
} */

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*

int findPassengerById(Passenger* list, int len,int id)
{
	return NULL;
}*/

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
			if(i==0)
			{
				printf("id\tnombre\t\tapellido\tprecio\t\tcodigo vuelo\ttipo pasajero\n");
			}
			if(esDistintoDeInicial(listPassenger[i].isEmpty, VALUE_INIT))
			{
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

		printf("%s %14s %10.2f %10s %10d\n",
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
