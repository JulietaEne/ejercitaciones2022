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
	int ultimoId;
	int menuPrincipal;
	int flagClientesCargados;

	/*char oneName[SIZE_STR];//={"julieta"};
	char oneLastName[SIZE_STR];//={"nakasone"};
	float onePrice; //= 15000;
	int oneTypePassager;//= 1;
	char oneFlyCode[10];//={"XFG13"};
	int confirmacion;
	int unId;
	int indexDelId;
	int respuesta;
	int reintentos;*/

	ultimoId=ID_INICIAL;
	flagClientesCargados = -1;//no hay clientes cargados ni se inicializó el array
	do
	{
		menuPrincipal = tp_ImprimirMenuSeisOpciones("\nPROGRAMA NAKASONE JULIETA:", "1) ALTAS", "2) MODIFICAR", "3) BAJA", "4) INFORMES", "5) SALIR", "6) \n");
		switch(menuPrincipal)
		{
			case 1:
				printf("ALTA DE CLIENTES\n");
				if(!passenger_getNew(arrayPasajeros, MAX_PASAJEROS, ultimoId))
				{
					if(flagClientesCargados == -1)
					{
						passenger_initArray(arrayPasajeros, MAX_PASAJEROS);
						flagClientesCargados=0;//no hay clientes cargados pero se inicializó el array
					}
					ultimoId++;
					flagClientesCargados++;//indicará la cant de clientes cargados
					passenger_print(arrayPasajeros, MAX_PASAJEROS);

					//que pasa si no tengo más lugares?
				}
				else
				{
					tp_MensajeError("[**ERROR**] Ha habido un conflicto en la carga de clientes");
				}
				break;
			case 2:
				printf("MODIFICAR CLIENTES\n");
				if(flagClientesCargados>0)
				{
					//tengo que pedir el ID del cliente que quiero modificar
					//tengo que consultar qué dato deseo modificar
					//ahora puedo modificar según lo seleccionado por el usuario
				}
				else
				{
					printf("[**ERROR**] Debe ingresar al menos un cliente para poder operar");
				}
				break;
			case 3:
				printf("BORRAR CLIENTES\n");
				if(flagClientesCargados>0)
				{
					//tengo que pedir el ID del cliente que quiero eliminar
					//tengo que pedir confirmacion
					//coloco en .isEmpty = NOT_EMPTY  para un borrado logico
				}
				else
				{
					printf("[**ERROR**] Debe ingresar al menos un cliente para poder operar");
				}
				break;
			case 4:
				/*
				 * 1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
				*	2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
				*	promedio.
				*	3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
				 */
				break;
			case 5:
				printf("saliendo....");
				break;
		}

	}while(menuPrincipal<5);



/*

	reintentos = 2;

	passenger_initArray(arrayPasajeros, MAX_PASAJEROS);//inicializado ok
	passenger_print(arrayPasajeros, MAX_PASAJEROS);//print ok
		//printf("entramos a agregar pasajero\n");

	//carga de elementos OK
	do{
		if(	!passenger_getName(oneName, SIZE_STR)
				&& !passenger_getLastName(oneLastName, SIZE_STR)
				&& passenger_getPrice(&onePrice)>0
				&& passenger_getTypePassenger(&oneTypePassager)>0
				&& !passenger_getFlyCode(oneFlyCode, 10)
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

	do{
		utn_GetNumeroInt(&unId, "\ningrese el ID del cliente que desea modificar", "Ingrese un dato valido", ID_INICIAL, ID_MAXIMO, REINTENTOS);

		printf("Id : %d", id);
			if( unId >= ID_INICIAL && unId <= id)
			{
				indexDelId= findPassengerById(arrayPasajeros, MAX_PASAJEROS, unId);

				passenger_printOnePosition(arrayPasajeros, indexDelId);
				respuesta= tp_ImprimirMenuSeisOpciones("\nMODIFICAR", "1) Nombre", "2) Apellido", "3) Precio", "4) FlyCode", "5) TypePassenger", "6) Volver atras");
				switch (respuesta)
				{
					case 1:
						passenger_getName(arrayPasajeros[indexDelId].name, SIZE_STR);
						break;
					case 2:
						passenger_getLastName(arrayPasajeros[indexDelId].lastName, SIZE_STR);
						break;
					case 3:
						passenger_getPrice(&arrayPasajeros[indexDelId].price);
						break;
					case 4:
						passenger_getFlyCode(arrayPasajeros[indexDelId].flycode, 10);
						break;
					case 5:
						passenger_getTypePassenger(&arrayPasajeros[indexDelId].typePassenger);
						break;
					default:
						break;
				}
			}
			else
			{
				tp_MensajeError("el dato ingresado no es un ID valido");
			}
			reintentos--;
	}while(reintentos>0);*/


	//if(!continuar("desea modificar el cliente seleccionado (Y/N)? "))
	//{

	//}
		//printf("%s", oneName);

	return EXIT_SUCCESS;
}



