//
// Created by crist on 09/03/2023.
//

#include "Pasos.h"
#include "Viajes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrar_pasos(Pasos *p, int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		mostrar_paso(p[i]);
	}
}

void mostrar_paso(Pasos p) {
	printf("%06d-%s\n", p.Id_viaje, p.Poblacion);
}

int encontrar_paso(Pasos *p, unsigned n, int id) {
	int i = 0, encontrado = -1;
	
	while (i < n && encontrado == -1) {
		if(id == p[i].Id_viaje) {
			encontrado = i;
		}
		else
			i++;
	}
	
	return encontrado;
}
void mostrar_pasos_id(Pasos *pasos, int n, int id) {
	int i = 0, encontrado = encontrar_paso(pasos,n,id), fin = 0;
	
	while (fin == 0) {
		if(pasos[i].Id_viaje > encontrado)
			fin = 1;
		else {
			mostrar_paso(pasos[i]);
			i++;
		}
	}
	
}

Pasos *leer_pasos(unsigned *nPasos) {
	Pasos *pasos = NULL;
	Pasos p;
	
	FILE *f = fopen("Pasos.txt", "r");
	char linea[40], *token;
	unsigned n = 0;
	
	while (fgets(linea,40,f) != NULL) {
		token = strtok(linea,"-");
		p.Id_viaje = atoi(token);
		token = strtok(NULL, "\n");
		strcpy(p.Poblacion,token);
		
		n++;
		pasos = (Pasos*)realloc(pasos, n*sizeof(pasos));
		pasos[n-1] = p;
	}
	
	fclose(f);
	*nPasos = n;
	
	return pasos;
}

void guardar_paso(Pasos paso, FILE *f) {
	
	fprintf(f,"%06d-",paso.Id_viaje);
	fprintf(f,"%s\n",paso.Poblacion);
	
}

void guardar_pasos(Pasos *pasos, unsigned n) {
	FILE *f = fopen("Pasos.txt", "w");
	unsigned i;
	
	for(i = 0; i < n; i++)
		guardar_paso(pasos[i], f);
	fclose(f);
}

int existe_paso(Pasos *p, unsigned n, int id) {
	if(encontrar_paso(p,n,id) != -1)
		return 1;
	else
		return 0;
}
