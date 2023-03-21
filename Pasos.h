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

// Precondición: p no esta vacío
// Postcondición: Muestra p
void mostrar_paso(Pasos p);
// Precondición: p inicializado, n > 0
// Postcondición: Muestra todos los pasos del vector p
void mostrar_pasos(Pasos *p, unsigned n);
// Precondición: nPasos > 0
// Postcondición: Inicializa el vector de la estructura Pasos de Pasos.txt y devuelve por parámetro el número de pasos
Pasos *leer_pasos(unsigned *nPasos);
// Precondición:
void guardar_paso(Pasos paso, FILE *f);
void guardar_pasos(Pasos *pasos, unsigned n);
int encontrar_id_paso(Pasos *p, unsigned n, int id);
int encontrar_paso(Pasos *p, unsigned n,int id, char *poblacion);
Pasos *agregar_pasos(Pasos *original,int *n);
Pasos *eliminar_paso(Pasos *original, int *n, int i);
Pasos *eliminar_pasos(Pasos *original, int *n, int id);
int existe_paso_no_actual(Pasos *p, int nTotal, char *Poblacion, int actual, int id);
int existe_paso(Pasos *p, unsigned n, int id);
void mostrar_pasos_id(Pasos *pasos, int n, int id);
int* encontrar_posiciones_Pasos(Pasos* vector, int tam, int id_buscado, int* num_posiciones);
#endif //PASOS_H
