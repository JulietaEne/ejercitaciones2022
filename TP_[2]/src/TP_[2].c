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
#define ID_INICIAL 100


int main(void) {

	//ePassenger unPasajero;
	ePassenger arrayPasajeros[MAX_PASAJEROS];//= {{14,"julieta","nakasone",45.5,"tcpx1403",1,1},{15,"lau","rancho",45.5,"tcpx1403",1,1}};
	int id;
	char oneName[LEN_STR];//={"julieta"};
	char oneLastName[LEN_STR];//={"nakasone"};
	float onePrice; //= 15000;
	int oneTypePassager;//= 1;
	char oneFlyCode[10];//={"XFG13"};
	int confirmacion;

	id=ID_INICIAL;

	passenger_initArray(arrayPasajeros, MAX_PASAJEROS);//inicializado ok
	passenger_print(arrayPasajeros, MAX_PASAJEROS);//print ok
		//printf("entramos a agregar pasajero\n");
	do{
		if(	passenger_getName(oneName, LEN_STR)==1
				&& passenger_getLastName(oneLastName, LEN_STR)==1
				&& passenger_getPrice(&onePrice)>0
				&& passenger_getTypePassenger(&oneTypePassager)>0
				&& passenger_getFlyCode(oneFlyCode, 10)==1
				)
			{
				passenger_addPassenger(arrayPasajeros, MAX_PASAJEROS, id, oneName,oneLastName,onePrice,oneTypePassager, oneFlyCode);
				passenger_print(arrayPasajeros, MAX_PASAJEROS);
				id++;
			}
		else
		{
			tp_MensajeError("\nHa habido un error al cargar el cliente\n");
		}
		confirmacion= continuar("Desea ingresar otro cliente (Y/N)? ");
	}while(confirmacion);

		//printf("%s", oneName);

	return EXIT_SUCCESS;
}



