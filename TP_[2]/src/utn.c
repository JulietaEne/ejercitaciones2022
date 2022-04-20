/*
 * utn.c
 *
 *  Created on: 3 ago. 2021
 *      Author: julieta_enee
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//firmas para funciones internas
//static int esNumerica_previa(char* cadena);
static int esEntero(char* pCadena, int limite);//cambiarla a es numero int
static int esFlotante(char* pCadena, int limite);
static int getInt(int* pRespuesta);
static int getFloat(float* pRespuesta);
//static int myGets(char* cadena, int len);
static int getChar(char* pRespuesta);

//a partir de acá desarrollo mis funciones
/**
 * \brief 	Lee el stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres. EN ÉSTA FUNCIÓN, MARCA ERROR SI EL USUARIO
 *          INGRESA MÁS CARACTERES DE LO SOLICITADO.######TAMBIEN ME SIRVE PARA LEVANTAR UN ARRAY CHAR :D###########
 * \param *cadena Puntero al espacio de memoria donde se copiará la cadena obtenida
 * \param longitud Indica la longitud de la cadena trabajada
 * \return Retorna 0 si se obtiene la cadena exitosamente, y -1 si ha encontrado un error.
 *
 */
int myGets_prueba(char* pCadena, int len)
{
	int retorno= -1;
	char bufferString [4096]; //**********************
	if(pCadena != NULL && len >0)
	{
		__fpurge(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(pCadena, bufferString, len);
				//retorno = printf("entró a mygets, obvio --->");
				retorno =0;
			}
		}
	}
	//printf("retorno función myGets %d", retorno);
	return retorno;
}

/**
 * \brief 	Verifica si cada dato de la cadena ingresada es un dato numerico int (contempla negativos)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es numerica y 0(falso) si no lo es
 * 			//PORQUE LAS FUNCIONES QUE SON TIPO PREGUNTA, DEVUELVEN SI ES V(1) Ó F(0)
 */
static int esEntero(char* pCadena, int limite) //tengo que hacer uno para flotante
{
	int retorno= 1;
	int flagFlotante=0;
	int i;
	for (i=0; i<limite && pCadena[i] != '\0'; i++) //LIMITE POR DOBLE CRITERIO: voy a recorrer mientras no me haya pasado del límite y mientras no encuentre un \0
	{
		if(i==0 && (pCadena[i] == '+' || pCadena[i]== '-'))
		{
			continue; //ejecuta de nuevo el for
		}
		if(pCadena[i] < '0' || pCadena [i] > '9')
		{
			//printf("estoy en el %d : %c - %d\n", i , pCadena[i], pCadena[i]);
			retorno=0;
			break;
		}
	}
	if (flagFlotante > 1)
	{
		retorno = 0;//acá hay muchos puntitos
	}
	//printf("retorno función esEntero %d", retorno);
	return retorno;
}

/**
 * \brief 	Verifica si cada dato de la cadena ingresada es un dato flotante (contempla negativos)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es numerica y 0(falso) si no lo es
 *
 */
static int esFlotante(char* pCadena, int limite)
{
	int retorno= 1;
	int contadorFlotante=0;
	int i;

	for (i=0; i<limite && pCadena[i] != '\0'; i++) //LIMITE POR DOBLE CRITERIO: voy a recorrer mientras no me haya pasado del límite y mientras no encuentre un \0
	{
		if(i==0 && (pCadena[i] == '+' || pCadena[i]== '-'))
		{
			continue; //ejecuta de nuevo el for
		}
		if(pCadena[i] < '0' || pCadena [i] > '9')
		{
			if(pCadena[i]=='.' && contadorFlotante ==0)
			{
				contadorFlotante++;
			}
			else
			{
				//printf("estoy en el %d : %c - %d\n", i , pCadena[i], pCadena[i]);
				retorno=0;
				break;
			}
		}
	}
	//printf("retorno función esFlotante %d", retorno);
	return retorno;
}

/** #####probando con myGets_prueba + ARREGLOS
 * \brief 	Solicita un dato desde la terminal (se sirve de myGets) y
 * 			busca haber obtenido un numero entero (se sirve de esNumerica)
 * \param *pRespuesta Puntero al espacio de memoria donde se dejará el resultado de la función
 * \return Retorna 0 si se obtiene un número entero exitosamente y -1 si ha encontrado un error.
 *
 */
static int getInt(int* pRespuesta)
{
	int retorno= -1;
	char bufferString[4096];
	if (pRespuesta != NULL &&
		myGets_prueba(bufferString, sizeof(bufferString))==0 &&	 //recordar que es lo mismo myGets_prueba(bufferString, sizeof(bufferString))==0 y !myGets_prueba(bufferString, sizeof(bufferString))
		esEntero(bufferString,sizeof(bufferString)))
	{
			retorno=0;
			*pRespuesta = atoi(bufferString); //convierto el dato (array de string) en numero integrer con ¡ atoi !
	}
	return retorno;
}


/**
 * #####probando con myGets_prueba
 * \brief 	Solicita un dato desde la terminal (se sirve de myGets) y
 * 			busca haber obtenido un numero flotante (se sirve de esNumerica)
 * \param *pRespuesta Puntero al espacio de memoria donde se dejará el resultado de la función
 * \return Retorna 0 si se obtiene un número entero exitosamente y -1 si ha encontrado un error.
 *
 */
static int getFloat(float* pRespuesta)
{
	int retorno= -1;
	char buffer[4096]; // por qué en la clase 7 se usa un buffer de 128?
	if(pRespuesta!=NULL)
	{
		if(myGets_prueba(buffer, sizeof(buffer))==0 && esFlotante(buffer,sizeof(buffer))==1)
			{
				//retorno=printf("\nentroó a getFloat");
				retorno=0;
				*pRespuesta = atof(buffer);
			}
	}

	//printf("--->retorno funcion getFloat: %d", retorno);
	return retorno;
}

/**
 * #####probando con myGets_prueba
 * \brief 	Solicita un dato desde la terminal (se sirve de myGets) y
 * 			busca haber obtenido un caracter(se sirve de esNumerica negado)
 * \param *pRespuesta Puntero al espacio de memoria donde se dejará la respuesta de la función
 * \return Retorna 0 si se obtiene un número entero exitosamente y -1 si ha encontrado un error.
 *
*/
static int getChar(char* pRespuesta)
{
	int retorno= -1;
	char buffer[4096];


	//verifico si lo ingresado en buffer es EXITOSAMENTE números:
	if(myGets_prueba(buffer, sizeof(buffer))==0) //si el dato solicitado con myGets es correcto
	{
		retorno=0;
		*pRespuesta = buffer[0]; //derivo el dato alojado en la primera posición buffer hacia la variable que me apunta a la respuesta (solo acepta 1 caracter)
	}

	return retorno;
}

/**
 * \brief 	Solicita un numero al usuario(se sirve de getInt), luego de verificarlo devuelve el resultado
 * \param *pRespuesta Puntero al espacio de memoria donde se dejará el resultado de la función
 * \param *mensaje Es el mensaje a ser mostrado
 * \param *mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero máximo a ser aceptado
 * \param reintentos Cantidad de reintentos posibles, luego del primer uso de la función
 * \return Retorna 0 si se obtuvo exitosamente el numero y -1 si no se obtuvo
 *
 */
int utn_GetNumeroInt(int* pRespuesta, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1; //devuelve el error en la primer instancia
	int bufferInt;

	if(pRespuesta != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			__fpurge(stdin);
			if(getInt(&bufferInt)==0 &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
			{
				*pRespuesta= bufferInt;
				retorno = 0;
				break; //porque ya no precisaría continuar el bucle do-while ya que llegué al caso de éxito
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief 	Solicita un numero al usuario(se sirve de getFloat), luego de verificarlo devuelve el resultado
 * \param *pRespuesta Puntero al espacio de memoria donde se dejará el resultado de la función
 * \param *mensaje Es el mensaje a ser mostrado
 * \param *mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero máximo a ser aceptado
 * \param reintentos Cantidad de reintentos posibles, luego del primer uso de la función
 * \return Retorna 0 si se obtuvo exitosamente el numero y -1 si no se obtuvo
 *
 */
int utn_GetNumeroFloat(float* pRespuesta, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=-1;
	float bufferFloat;


	if(pRespuesta != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			__fpurge(stdin);
			//scanf("%f", &bufferFloat);

			if(getFloat(&bufferFloat)==0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pRespuesta= bufferFloat;
				//retorno=printf("\nentroó a getNumeroFloat");
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	//printf("--->retorno de función %d", retorno);
	return retorno;
}

/**
 * \brief 	Solicita un caracter al usuario, luego de verificarlo devuelve el resultado
 * \param *pRespuesta Puntero al espacio de memoria donde se dejará la respuesta obtenida con la función
 * \param *mensaje Es el mensaje a ser mostrado
 * \param *mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero máximo a ser aceptado
 * \param reintentos Cantidad de reintentos posibles, luego del primer uso de la función
 * \return Retorna 0 si se obtuvo exitosamente el numero y -1 si no se obtuvo
 *
 */
int utn_GetChar(char* pRespuesta, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno=-1; //devuelve el error en la primer instancia
	char bufferChar;

	//primero validamos que no haya punteros NULL (pRespuesta = el valor que se aloja en la dirección de memoria a la que apunta *pRespuesta)
	if(pRespuesta != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			__fpurge(stdin);
			//scanf("%c", &bufferChar);
			if(getChar(&bufferChar)==0 && bufferChar >= minimo && bufferChar <= maximo)
			{
				*pRespuesta= bufferChar;
				//si tenemos hasta acá correcto, se considera que la función pudo trabajar exitosamente
				retorno = 0;
				break; //porque ya no precisaría continuar el bucle do-while ya que llegué al caso de éxito, entonces rompe el bucle de iteracion y continúa con la linea de código siguiente al do
			}
				printf("%s", mensajeError);
				reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/// \brief dialoga con el usuario para pedir un string de hasta 100 palabras
/// \param pRespuesta[] array donde se devuelve el dato ingresado
/// \param len tamaño del array
/// \param *mensaje es el mensaje que se muestra al usuario
/// \param reintentos la cantidad de reintentos que se pueden hacer
/// \return retorna 0 si se obtuvo exitosamente y -1 si hubo un error.

/// \solicita un dato por teclado y verifica que sea alfabetico (soporta espacios)
/// \ PUNTERO necesita un puntero a la memoria en otro scope para devolver el resultado obtenido en myGets_prueba
/// \recibe como parámetro el largo del array para que myGets_prueba no se exceda al escribir en ella
/// \ RECIBE el mensaje desde otro scopa
/// \ RECIBE el mensaje de error de otro scope
/// \ recibe como parámetro la cantidad de reiteraciones que se harán en caso de encontrar un error
/// \retorna 0 si operó con éxito, retorna -1 si no.
int utn_ingresarAlfabetica(char pArray[], int len, char* mensaje, char* mensajeError, int reintentos)
{
	int i;
   // int esAlfabetica;
	int retorno;


	if(pArray != NULL && mensaje!= NULL && mensajeError != NULL)
	{

		do{
			retorno=0;
			printf("\n%s", mensaje);
			//printf("reintentos actuales: %d\n", reintentos);
			myGets_prueba(pArray, len);
			if(strlen(pArray)<2)
			{
			   retorno=-1;
				reintentos--;
				//printf("\n caracter: %c",pArray[i]);
				printf("\n%s", mensajeError);
			}
			for (i=0; i<strlen(pArray); i++)
			{

			   if(!((pArray[i]>='a' && pArray[i]<= 'z') || (pArray[i]==' ') ||(pArray[i]>='A' && pArray[i]<= 'Z'))) /*|| (nombre[i] = 32) quise contemplar los espacios pero cuando pongo números, me los lee como espacios¿¿¿???*/
			   {
					   retorno=-1;
						reintentos--;
						//printf("\n caracter: %c",pArray[i]);
						printf("\n%s", mensajeError);
						break;
			   }
			}
			if (retorno==0)
			   {
				   reintentos =-1;
				   //printf("\n letra: %c",pArray[i]);
			   }

		}while(reintentos>=0);

	}
	//printf("[DEBUG UTN] el retorno es: %d", retorno);
	return retorno;
}


/// \brief solicita un dato por teclado y verifica que sea alfanumerica (contempla espacios)
/// \param pArray array que recibe para analizar
/// \param len recibe el tamaño del array
/// \param mensaje mensaje que recibe para intercambiar con usuario
/// \param mensajeError mensaje que recibe para indicar error en los datos ingresados
/// \param reintentos indica cantidad de reintentos posibles
/// \return retorna 0 si operó con éxito, retorna -1 si no.
int utn_getAlfaNumerica(char pArray[], int len, char* mensaje, char* mensajeError, int reintentos)
{
	int i;
   // int esAlfabetica;
	int retorno;


	if(pArray != NULL && mensaje!= NULL && mensajeError != NULL)
	{

		do{
			retorno=0;
			printf("%s", mensaje);
			//printf("reintentos actuales: %d\n", reintentos);
			myGets_prueba(pArray, len);
			for (i=0; i<strlen(pArray); i++)
			{
			   /*if(nombre[i]=='\0')
				{
					break;
				}*/
			   if(!((pArray[i]>='a' && pArray[i]<= 'z') || (pArray[i]>='A' && pArray[i]<= 'Z'))&& !(pArray[i]<= 9 || pArray[i]>= 0)) /*|| (nombre[i] = 32) quise contemplar los espacios pero cuando pongo números, me los lee como espacios¿¿¿???*/
			   {
					retorno=-1;
					reintentos--;
					//printf("\n caracter: %c",pArray[i]);
					printf("\n%s", mensajeError);
					break;
			   }
			}
			if (retorno==0)
			   {
				   reintentos =-1;
				   //printf("\n letra: %c",pArray[i]);
			   }

		}while(reintentos>=0);

	}
	//printf("el retorno es: %d", retorno);
	return retorno;
}


