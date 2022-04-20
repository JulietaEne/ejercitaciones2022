/*
 * utn.h
 *
 *  Created on: 3 ago. 2021
 *      Author: julieta_enee
 */

#ifndef UTN_H_
#define UTN_H_

int utn_GetNumeroInt(int* pRespuesta, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_GetNumeroFloat(float* pRespuesta, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_GetChar(char* pRespuesta, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int utn_ingresarAlfabetica(char pArray[], int len, char* mensaje, char* mensajeError, int reintentos);
int utn_getAlfaNumerica(char pArray[], int len, char* mensaje, char* mensajeError, int reintentos);

//int myGets_prueba(char* pCadena, int len);
#endif /* UTN_H_ */
