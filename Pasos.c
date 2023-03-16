//
// Created by crist on 09/03/2023.
//

#include "Pasos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrar_pasos(Pasos *p, unsigned n) {
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
	int i = encontrar_paso(pasos,n,id), fin = 0;
	if(existe_paso(pasos,n,id)) {
		while (i < n && fin == 0) {
			if(id == pasos[i].Id_viaje) {
				mostrar_paso(pasos[i]);
				i++;
			}
			else
				fin = 1;
		}
	} else
		puts("No existe");
}

Pasos *leer_pasos(unsigned *nPasos) {
	Pasos *pasos = NULL;
	Pasos p;
	
	FILE *f = fopen("Pasos.txt", "r");
	char linea[40], *token;
	int n = 0;
	if(f == NULL) {
		puts("No se puedo abrir el fichero");
		exit(1);
	}
	
	else {
		while (fgets(linea, 40, f) != NULL) {
			token = strtok(linea, "-");
			p.Id_viaje = atoi(token);
			token = strtok(NULL, "\n");
			strcpy(p.Poblacion, token);
			
			n++;
			pasos = (Pasos *) realloc(pasos, n * sizeof(Pasos));
			pasos[n - 1] = p;
			
		}
		
		
		fclose(f);
		*nPasos = n;
		
		return pasos;
	}
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
