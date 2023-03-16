//
// Created by crist on 09/03/2023.
//

#ifndef PASOS_H
#define PASOS_H
#include <stdio.h>
typedef struct {
	int Id_viaje;
	char Poblacion[21];
}Pasos;

void mostrar_paso(Pasos);
void mostrar_pasos(Pasos *, unsigned );
Pasos *leer_pasos(unsigned *);
void guardar_paso(Pasos, FILE *);
void guardar_pasos(Pasos *, unsigned);
int encontrar_paso(Pasos *, unsigned , int);
int existe_paso(Pasos *, unsigned , int);
void mostrar_pasos_id(Pasos *, int, int);
#endif //PASOS_H
