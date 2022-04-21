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
#define SIZE_STR 51
#define REINTENTOS 2
#define MAX_PASAJEROS 2000
#define ID_INICIAL 100
#define ID_MAXIMO 2200


int main(void) {

	//ePassenger unPasajero;
	ePassenger arrayPasajeros[MAX_PASAJEROS];//= {{14,"julieta","nakasone",45.5,"tcpx1403",1,1},{15,"lau","rancho",45.5,"tcpx1403",1,1}};
	int id;
	char oneName[SIZE_STR];//={"julieta"};
	char oneLastName[SIZE_STR];//={"nakasone"};
	float onePrice; //= 15000;
	int oneTypePassager;//= 1;
	char oneFlyCode[10];//={"XFG13"};
	int confirmacion;
	int unId;
	int indexDelId;
	int respuesta;

	id=ID_INICIAL;

	passenger_initArray(arrayPasajeros, MAX_PASAJEROS);//inicializado ok
	passenger_print(arrayPasajeros, MAX_PASAJEROS);//print ok
		//printf("entramos a agregar pasajero\n");

	//carga de elementos
	do{
		if(	passenger_getName(oneName, SIZE_STR)==1
				&& passenger_getLastName(oneLastName, SIZE_STR)==1
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

	//modificacion
	utn_GetNumeroInt(&unId, "ingrese el ID del cliente que desea modificar", "Ingrese un dato valido", ID_INICIAL, ID_MAXIMO, REINTENTOS);
	indexDelId= findPassengerById(arrayPasajeros, MAX_PASAJEROS, unId);
	passenger_printOnePosition(arrayPasajeros, indexDelId);
	if(!continuar("desea modificar el cliente seleccionado (Y/N)? "))
	{
		respuesta= tp_ImprimirMenuSeisOpciones("modificar", "1) nombre", "2) Apellido", "3) precio", "4) flyCode", "5) typePassenger", "6) volver atras");
		switch (respuesta) {
			case 1:
				passenger_getName(arrayPasajeros[indexDelId].name, SIZE_STR);
				break;
			case 2:
				passenger_getLastName(arrayPasajeros[indexDelId].lastName, SIZE_STR);
				break;
			case 3:

				//passenger_getPrice(arrayPasajeros[indexDelId].price);
				break;
			case 4:
				passenger_getFlyCode(arrayPasajeros[indexDelId].flycode, 10);
				break;
			case 5:
				//passenger_getTypePassenger(&arrayPasajeros[indexDelId].typePassenger);
				break;
			default:
				break;
		}
	}
		//printf("%s", oneName);

	return EXIT_SUCCESS;
}



