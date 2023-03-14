//
// Created by crist on 09/03/2023.
//

#include "Pasos.h"
#include "Viajes.h"
#include <stdio.h>
#include <stdlib.h>

void mostrar_pasos(Pasos *p, int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		mostrar_parada(p[i]);
	}
}

void mostrar_parada(Pasos p) {
	printf("$i-%s\n", p.Id_viaje, p.Poblacion);
}



