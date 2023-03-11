//
// Created by crist on 11/03/2023.
//

#include "Utilidades.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *crear_identificador (int i, int num_car) {
	int digitos = num_digitos(i);
	int ceros = num_car - digitos;
	char *id = malloc((num_car + 1) * sizeof (char));
	char *char_digitos = malloc(sizeof (digitos));
	int cont = 0;
	
	for(cont = 0; cont < ceros; cont++)
		id[cont] = '0';
	
	id[ceros] = '\0';
	
	sprintf(char_digitos,"%d",i);
	
	strcat(id,char_digitos);
	
	free(char_digitos);
	return id;
}
int num_digitos(int n) {
	int digitos = 0;
	
	while(n != 0) {
		n = n/10;
		digitos++;
	}
	
	return digitos;
}

void quitar_salto(char *s) {
	char *pos = strchr(s, '\n');
	if(pos != NULL)
		*pos = '\0';
}
