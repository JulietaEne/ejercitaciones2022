/*
 * arrays.c
 *
 *  Created on: 12 abr. 2022
 *      Author: julieta_enee
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "tp.h"
#include "arrays.h"

#define INICIAL 0

/*
 * \breif recorre el array recibido para asignar el valor indicado en cada posicion (se sirve de funcion asignarValor..)
 * \param unArray[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeArray Recibe por valor el tamaño del array con el que trabaja
 * \param inicializar Recibe por valor el dato que se asigna a cada posicion
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si no hubo error
 *
 */
int array_inicializar(int unArray[], int sizeArray, int inicializar)
{
	int retorno;
	int i;
	retorno = -1;

	if(unArray != NULL && sizeArray>0)
	{
		retorno = 0;
		for (i=0; i<sizeArray; i++)
		{
			array_asignarValorAUnaPosicion(unArray, i, inicializar);
		}
	}

	return retorno;
}

/*
 * \breif asigna un valor a la posicion indicada del array
 * \param unArray[] Recibe por referencia el array sobre el cual trabajara
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \param valor Recibe por valor el dato que se asigna
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si opero exitosamente
 *
 */
int array_asignarValorAUnaPosicion(int unArray[], int unaPosicion, int valor)
{
	int retorno;
	retorno = -1;

	if(unArray!= NULL)
	{
		unArray[unaPosicion] = valor;
		retorno = 0;
	}

	return retorno;
}

/*
 * \breif recorre el array para imprimirlo (se sirve de imprimirPosicionArray), incluso las posiciones con el valor inicial
 * \param unArray[] Recibe por referencia el array
 * \param sizeArray Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si opero exitosamente
 *
 */
int array_imprimirArrayCompleto(int unArray[], int sizeArray)
{
	int retorno;
	int i;
	retorno = -1;

	if(unArray!= NULL && sizeArray >0)
	{
		for (i = 0; i<sizeArray; i++)
		{
			array_imprimirPosicionArray(unArray, i);
			if(i== sizeArray-1)
			{
				printf("\n");
			}
		}
		retorno = 0;
	}

	return retorno;
}

/*
 * \breif recorre el array para imprimirlo (se sirve de imprimirPosicionArray), omite las posiciones con el valor inicial
 * \param unArray[] Recibe por referencia el array
 * \param sizeArray Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si opero exitosamente
 *
 */
int array_imprimirArraySinInicializados(int unArray[], int sizeArray)
{
	int retorno;
	int i;
	retorno = -1;

	if(unArray!= NULL && sizeArray >0)
	{
		for (i = 0; i<sizeArray; i++)
		{
			if(esDistintoDeInicial(unArray[i], INICIAL))
			{
				array_imprimirPosicionArray(unArray, i);
				if(i== sizeArray-1)
				{
					printf("\n");
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

int array_imprimirPosicionArray(int unArray[], int unaPosicion)
{
	int retorno;
	retorno = -1;

	if(unArray!= NULL)
	{
		retorno = 0;
		if(unaPosicion==0)
		{
			printf("\n");
		}
		printf("%d ", unArray[unaPosicion]);
	}

	return retorno;
}

int array_cargarSecuencial(int unArray[], int sizeArray, int minimoPosible, int maximoPosible, int reintentos)
{
	int retorno;
	int i;
	retorno = -1;

	if(unArray != NULL && sizeArray>0)
	{
		retorno = 0;
		for (i=0; i<sizeArray; i++)
		{
			printf("%d ", i+1);
			utn_GetNumeroInt(&unArray[i], "ingrese valor: ", "[ERROR] ", minimoPosible, maximoPosible, reintentos);
		}
	}

	return retorno;
}

int array_cargarAleatorio(int unArray[], int sizeArray, int* indice, int valor)
{
	int retorno;
	retorno = -1;

	if(unArray != NULL)
	{
		unArray[*indice] = valor;
		retorno = 0;
		*indice = *indice+1;
	}

	return retorno;
}

/*
 * \breif recorre el array recibido para acumular los valores positivos
 * \param unArray[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeArray Recibe por valor el tamaño del array con el que trabaja
 * \param *acumuladorPositivos Recibe por referencia un espacio de memoria para almacenar la sumatoria de los valores positivos
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   		    0 si no existen numeros positivos
 * 			   		>0 si existen positivos (la cantidad de positivos que se encontraron)
 *
 */
int array_acumuladorPositivos(int unArray[], int sizeArray, int* acumuladorPositivos)
{
	int i;
	int positivos;

	positivos = -1;

	if(unArray!= NULL && sizeArray>0)
	{
		positivos = 0;
		for(i=0; i<sizeArray; i++)
		{
			if(unArray[i]!= 0 && esPositivo(unArray[i])==1)
			{
				*acumuladorPositivos = *acumuladorPositivos+unArray[i];
				positivos++;
			}
		}
	}

	return positivos;
}

/*
 * \breif recorre el array recibido para acumular los valores negativos
 * \param unArray[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeArray Recibe por valor el tamaño del array con el que trabaja
 * \param *acumuladorNegativos Recibe por referencia un espacio de memoria para almacenar la sumatoria de los valores negativos
 * \return retorna 1 si hubo un error en los parametros recibidos
 * 		   		   0 si no existen numeros positivos
 * 			   	   >0 si existen negativos (la cantidad de negativos que se encontraron)
 *
 */
int array_acumuladorNegativos(int unArray[], int sizeArray, int* acumuladorNegativos)
{
	int i;
	int cantNegativos;

	cantNegativos = -1;

	if(unArray!= NULL && sizeArray>0)
	{
		cantNegativos = 0;
		for(i=0; i<sizeArray; i++)
		{
			if(unArray[i]!= 0 && !esPositivo(unArray[i]))
			{
				*acumuladorNegativos = *acumuladorNegativos+unArray[i];
				cantNegativos++;
			}
		}
	}

	return cantNegativos;
}


int array_identificarMenorNumero(int unArray[], int sizeArray, int* menorNumero)
{
	int retorno;
	int i;
	retorno = -1;
	if(unArray != NULL && sizeArray > 0 && menorNumero != NULL )
	{
		retorno =0;
		for (i = 0; i<sizeArray; i++)
		{
			if(i==0)
			{
				*menorNumero = unArray[i];
				continue;
			}
			if(*menorNumero > unArray[i])
			{
				*menorNumero = unArray[i];
			}
		}
	}
	return retorno;
}