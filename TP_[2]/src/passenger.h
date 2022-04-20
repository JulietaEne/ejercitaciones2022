/*
 * passenger.h
 *
 *  Created on: 20 abr. 2022
 *      Author: juliet
 */

#ifndef PASSENGER_H_

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
}typedef ePassenger;

int passenger_initArray(ePassenger* listPassenger, int sizeListPassenger);
int passenger_initAPossition(ePassenger* listPassenger, int sizeListPassenger, int valorInicial);
/*int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int sortPassengers(Passenger* list, int len, int order);*/
int passenger_print(ePassenger* listPassenger, int sizeListPassenger);
int passenger_printOnePosition(ePassenger* listPassenger, int onePosition);
/*int sortPassengers(Passenger* list, int len, int order);*/


#define PASSENGER_H_



#endif /* PASSENGER_H_ */
