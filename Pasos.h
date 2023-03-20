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

void mostrar_paso(Pasos p);
void mostrar_pasos(Pasos *p, unsigned n);
Pasos *leer_pasos(unsigned *nPasos);
void guardar_paso(Pasos paso, FILE *f);
void guardar_pasos(Pasos *pasos, unsigned n);
int encontrar_id_paso(Pasos *p, unsigned n, int id);
int encontrar_paso(Pasos *p, unsigned n,int id, char *poblacion);
Pasos agregar_paso(int i);
Pasos *agregar_pasos(Pasos *original,int *n);
int existe_paso_no_actual(Pasos *p, int nTotal, char *Poblacion, int actual, int id);
int existe_paso(Pasos *p, unsigned n, int id);
void mostrar_pasos_id(Pasos *pasos, int n, int id);
#endif //PASOS_H
