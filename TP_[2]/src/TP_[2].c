/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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
#define LEN_STR 51
#define REINTENTOS 2
#define MAX_PASAJEROS 2000


int main(void) {

	//ePassenger unPasajero;
	ePassenger arrayPasajeros[MAX_PASAJEROS];//= {{14,"julieta","nakasone",45.5,"tcpx1403",1,1},{15,"lau","rancho",45.5,"tcpx1403",1,1}};
	int id;
	char oneName[LEN_STR];
	char oneLastName[LEN_STR]={"nakasone"};
	float onePrice = 5.6;
	int oneTypePassager= 1;
	char oneFlyCode[10]={"XFG13"};



	id=1;

	passenger_initArray(arrayPasajeros, MAX_PASAJEROS);//inicializado ok
	if(!passenger_print(arrayPasajeros, MAX_PASAJEROS)) //print ok
	//carga de elementos
	//if(passenger_getName(listPassenger, sizeListPassenger, name, lenName, unaPosicion))
	{
		printf("entramos a agregar pasajero\n");
		if(passenger_getName(oneName, LEN_STR)==1&& passenger_getLastName(oneLastName, LEN_STR)==1)
		{
			passenger_addPassenger(arrayPasajeros, MAX_PASAJEROS, id, oneName,oneLastName,onePrice,oneTypePassager, oneFlyCode);
			passenger_print(arrayPasajeros, MAX_PASAJEROS);
		}
		//printf("%s", oneName);
	}
	return EXIT_SUCCESS;
}



