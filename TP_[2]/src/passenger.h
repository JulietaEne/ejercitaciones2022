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
int passenger_addPassenger(ePassenger* listPassenger, int sizeListPassenger, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
int passenger_getName(char name[], int sizeName);
int passenger_getLastName(char lastName[], int sizeName);
float passenger_getPrice(float* onePrice);
int passenger_getFlyCode(char* oneFlyCode, int sizeCode);
int passenger_getTypePassenger(int* oneTypePassenger);
/*int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int sortPassengers(Passenger* list, int len, int order);*/
int passenger_print(ePassenger* listPassenger, int sizeListPassenger);
int passenger_printOnePosition(ePassenger* listPassenger, int onePosition);
/*int sortPassengers(Passenger* list, int len, int order);*/
//int passenger_addPassenger(ePassenger* listPassenger, int sizeListPassenger, int id, char name[]);//,char lastName[],float price,int typePassenger, char flycode[])

#define PASSENGER_H_



#endif /* PASSENGER_H_ */
