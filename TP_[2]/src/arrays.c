/*
 * arrays.c
 *
 *  Created on: 12 abr. 2022
 *      Author: julieta_enee
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "tp.h"
#include "arrays.h"

#define INICIAL 0
#define FLOAT_INICIAL 0

////// ############################### { ARRAY INT } ############################### //////
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


/*
 * \breif Ordena un array de enteros segun el criterio indicado
 * \param unArray[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeArray Recibe por valor el tamaño del array con el que trabaja
 * \param criterio Recibe por valor el codigo del criterio indicado: 1 ordena en forma ascendente
 * 																	 2 ordena de forma descendente
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   		   0 si no se realizo ningur ordenamiento
 * 			   	   >0 si se realizo ordenamiento (retorna la cantidad de iteraciones que fueron necesarias para ordenarlo)
 *
 */
int array_sortNumeros(int unArray[], int sizeArray, int criterio)
{
	int retorno;
	int flagSwap;
	int i;
	int nuevoLimite;
	int contador;

	retorno = -1;

	if(unArray!= NULL && sizeArray>0)
	{
		nuevoLimite = sizeArray-1;
		contador = 0;
		do
		{
			flagSwap = 0;
			for (i=0; i<nuevoLimite; i++)
			{
				contador++;
				switch(criterio)
				{
					case 1: //ordena de menor a mayor
						if(unArray[i] > unArray[i+1]) //#######!!!cuando sepa llamar a un puntero de un puntero, puedo hacerlo en una funcion!!!#######
						{
							swap(&unArray[i], &unArray[i+1]);
						}

						break;
					case 2: //ordena de mayor a menor
						if(unArray[i] < unArray[i+1])
						{
							flagSwap=1;
							swap(&unArray[i], &unArray[i+1]);
						}
						break;
				}
			}
			nuevoLimite--;
		}while(flagSwap);
	}
	retorno = contador;

	return retorno;
}
/*int array_sortNumeros(int unArray[], int sizeArray, int criterio)
{
    int retorno;
    int i;
    int j;
    retorno = -1;
    if(unArray!= NULL && sizeArray>0)
    {
        retorno = 0;
        for(i=0; i<sizeArray-1; i++)
        {
            for (j=i+1; j<sizeArray; j++)
            {
                switch(criterio)
                {
                    case 1: //ordena de menor a mayor
                        ordenarFormaCreciente(numeroA, numeroB);
                        break;
                    case 2: //ordena de mayor a menor
                        ordenarFormaDecreciente(numeroA, numeroB);
                        break;
                }

            }
        }
    }
    return retorno;
}*/

////// ############################### { ARRAY FLOAT } ############################### //////

/*
 * \breif recorre el array recibido para asignar el valor indicado en cada posicion (se sirve de funcion asignarValor..)
 * \param unArray[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeArray Recibe por valor el tamaño del array con el que trabaja
 * \param inicializar Recibe por valor el dato que se asigna a cada posicion
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si no hubo error
 *
 */
int array_floatInicializar(float unArray[], int sizeArray, float inicializar)
{
	int retorno;
	int i;
	retorno = -1;

	if(unArray != NULL && sizeArray>0)
	{
		retorno = 0;
		for (i=0; i<sizeArray; i++)
		{
			array_floatAsignarValorAUnaPosicion(unArray, i, inicializar);
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
int array_floatAsignarValorAUnaPosicion(float unArray[], int unaPosicion, float valor)
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
int array_floatImprimirArrayCompleto(float unArray[], int sizeArray)
{
	int retorno;
	int i;
	retorno = -1;

	if(unArray!= NULL && sizeArray >0)
	{
		for (i = 0; i<sizeArray; i++)
		{
			array_floatImprimirPosicionArray(unArray, i);
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
int array_floatImprimirArraySinInicializados(float unArray[], int sizeArray)
{
	int retorno;
	int i;
	retorno = -1;

	if(unArray!= NULL && sizeArray >0)
	{
		for (i = 0; i<sizeArray; i++)
		{
			if(esDistintoDeInicial(unArray[i], FLOAT_INICIAL))
			{
				array_floatImprimirPosicionArray(unArray, i);
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

int array_floatImprimirPosicionArray(float unArray[], int unaPosicion)
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
		printf("%.2f ", unArray[unaPosicion]);
	}

	return retorno;
}

int array_floatCargarSecuencial(float unArray[], int sizeArray, float minimoPosible, float maximoPosible, int reintentos)
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
			utn_GetNumeroFloat(&unArray[i], "ingrese valor: ", "[ERROR] ", minimoPosible, maximoPosible, reintentos);
		}
	}

	return retorno;
}

int array_floatCargarAleatorio(float unArray[], int sizeArray, int* indice, float valor)
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
int array_floatAcumuladorPositivos(float unArray[], int sizeArray, float* acumuladorPositivos)
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
int array_floatAcumuladorNegativos(float unArray[], int sizeArray, float* acumuladorNegativos)
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


int array_floatIdentificarMenorNumero(float unArray[], int sizeArray, float* menorNumero)
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

////// ############################### { ARRAY CHAR } ############################### //////
int array_convertirStringMayuscula(char unString[], int lenArray)
{
	int retorno;
	int i;
	retorno = -1;

	if(unString != NULL && lenArray >0)
	{
		retorno = 0;
		for(i=0; i<lenArray; i++)
		{
			convertirAMayuscula(&unString[i]);
		}
	}
	return retorno;
}

int array_convertirStringMinuscula(char unString[], int lenArray)
{
	int retorno;
	int i;
	retorno = -1;

	if(unString != NULL && lenArray >0)
	{
		retorno = 0;
		for(i=0; i<lenArray; i++)
		{
			convertirAMinuscula(&unString[i]);
		}
	}
	return retorno;
}

int array_visualizarApellidoNombre(char nombre[], char apellido[], char apellidoNombre[], int lenApellidoNombre)
{
	int retorno;

	retorno = -1;

	if(nombre != NULL && apellido != NULL && apellidoNombre != NULL && lenApellidoNombre >0)
	{
		retorno = 0;
		//apellidoNombre[0]='\0'inicializamos la variable para que no tenga datos basura
		//strcpy(apellidoNombre, apellidoNombre);
		strncpy(apellidoNombre,apellido,lenApellidoNombre);
		strncat(apellidoNombre, ", ", lenApellidoNombre);
		strncat(apellidoNombre, nombre, lenApellidoNombre);
	}
	return retorno;
}

int array_eliminarEspaciosExtra(char unString[], int sizeString)
{
	int retorno;
	int i;
	int j;
	retorno = -1;
	if(unString != NULL && sizeString >0)
	{
		retorno = 0;
		for(i = 0; i < sizeString; i++)
		{
			if(unString[i]== ' ')
			{
				while(unString[i+1]== ' ')
				{
					retorno=1;
					for(j = i; j < sizeString; j++)
					{
						unString[j]=unString[j+1];
					}
				}
			}
		}
	}
	return retorno;
}

int array_eliminarEspaciosAdelante(char unString[], int sizeString)
{
	int retorno;
	int i;
	int j;
	retorno = -1;
	if(unString != NULL && sizeString > 0)
	{
		retorno = 0;
		for(i = 0; i < sizeString; i++)
		{
			if(i==0)
			{
				while(unString[i]== ' ')
				{
					retorno = 1;
					for(j = 0; j < sizeString; j++)
					{
						unString[j]=unString[j+1];
					}
				}
			}
		}
	}

	return retorno;
}

/*
 * retorna -1 si hubo error en los parametros
 * 		    0 si no elimino ningun espacio
 * 		    >0 la cantidad de espacios que borró
 *
 *
 */

int array_eliminarTodosLosEspacios(char unString[], int sizeString)
{
	int retorno;
	int i;
	int j;
	int contador;
	retorno = -1;
	contador = 0;
	if(unString != NULL && sizeString > 0)
	{
		for(i = 0; i < sizeString; i++)
		{
			while(unString[i]== ' ')
			{
				for(j = i; j < sizeString; j++)
				{
					unString[j]=unString[j+1];
					contador++
				}
			}
		}
		retorno = contador;
	}

	return retorno;
}

