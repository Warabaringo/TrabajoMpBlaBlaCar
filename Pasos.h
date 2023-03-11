//
// Created by crist on 09/03/2023.
//

#ifndef TRABAJOMPBLABLACAR_PASOS_H
#define TRABAJOMPBLABLACAR_PASOS_H

typedef struct {
	char Id_viaje[7];
	char Poblacion[21];
}Pasos;

void mostrar_parada(Pasos);
void mostrar_pasos(Pasos *, int);

#endif //TRABAJOMPBLABLACAR_PASOS_H
