//
// Created by crist on 09/03/2023.
//

#include "Pasos.h"
#include "Utilidades.h"
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

int encontrar_id_paso(Pasos *p, unsigned n, int id) {
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
	int i = encontrar_id_paso(pasos,n,id), fin = 0;
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
	
	FILE *f = fopen("Pasos.txt", "ra");
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
	if(encontrar_id_paso(p,n,id) != -1)
		return 1;
	else
		return 0;
}

Pasos *agregar_pasos(Pasos *original,int *n) {
	int i, nPasos, cont = 0, id = generar_id_pasos(original,n);
	char Poblacion[20];
	Pasos *p = ordenar_pasos(p,*n);
	do {
		puts("Introduzca los pasos del nuevo viaje");
		scanf("%i", &nPasos);
	} while (nPasos <= 0);
	
	p = (Pasos *) realloc(p, (*n + nPasos) * sizeof(Pasos));
	
	for (i = *n; i < (*n + nPasos); i++) {
		do {
			fflush(stdin);
			printf("Introduzca la poblacion del paso %i del nuevo viaje\n", cont+1);
			fgets(Poblacion,20,stdin);
			quitar_salto(Poblacion);
		} while (existe_paso_no_actual(p, *n+nPasos,Poblacion, *n + cont, id)== 1);
		strcpy(p[i].Poblacion,Poblacion);
		p[i].Id_viaje = id;
		cont++;
	}
	*n = *n + nPasos;
	return p;
}

int encontrar_paso(Pasos *p, unsigned n, int id, char *poblacion) {
	int i = 0, encontrado = -1;
	
	while(i < n && encontrado == -1) {
		if(id == p[i].Id_viaje && strcmp(poblacion,p[i].Poblacion) == 0)
			encontrado = i;
		i++;
	}
	
	return encontrado;
}

int existe_paso_no_actual(Pasos *p, int nTotal, char *Poblacion, int actual, int id) {
	int i = 0, existe = 0;
	
	while (i < nTotal && existe == 0) {
		if(i == actual)
			i++;
		else {
			if (strcmp(Poblacion, p[i].Poblacion) == 0 && id == p[i].Id_viaje)
				existe = 1;
			i++;
		}
	}
	return existe;
}

Pasos *eliminar_paso(Pasos *original, int *n, int i) {
	Pasos *p = original;
	
	while(i < (*n)-1) {
		p[i] = p[i+1];
		i++;
	}
	
	return p;
}

Pasos* eliminar_pasos(Pasos* original, int* n, int id) {
	Pasos *p = (Pasos*) malloc((*n) * sizeof(Pasos));
	int j = 0;
	for (int i = 0; i < *n; ++i) {
		if(original[i].Id_viaje != id) {
			p[j].Id_viaje = original[i].Id_viaje;
			strcpy(p[j].Poblacion, original[i].Poblacion);
			j++;
		}
	}
	
	*n = j;
	return (Pasos*) realloc(p, j*sizeof(Pasos));
}

Pasos *ordenar_pasos(Pasos *p, int numero_pasos){
	Pasos temp;
	for (int i = 0; i < numero_pasos - 1; i++) {
		for (int j = i + 1; j < numero_pasos; j++) {
			if (p[i].Id_viaje > p[j].Id_viaje) {
				
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				
			}
		}
	}
	return p;
}

int generar_id_pasos(Pasos *p, int *numero_pasos){
	
	int i, comp = 1, salida, encontrado = 0;
	
	do{
		salida = 0;
		for(i = 0; i < *numero_pasos && salida == 0; i++){
			if(comp == p[i].Id_viaje) {
				salida = 1;
				comp++;
			}
		}
		if(salida == 0) encontrado = 1;
		
	}while(i < *numero_pasos && encontrado == 0);
	
	return comp;
}