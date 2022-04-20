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
	ePassenger arrayPasajeros[MAX_PASAJEROS];

	passenger_initArray(arrayPasajeros, MAX_PASAJEROS);
	passenger_print(arrayPasajeros, MAX_PASAJEROS);


	return EXIT_SUCCESS;
}



