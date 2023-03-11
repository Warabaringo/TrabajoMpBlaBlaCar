//
// Created by crist on 11/03/2023.
//

#include "Utilidades.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *crear_identificador (int n, int num_car) {
	int digitos = num_digitos(n);
	int ceros = num_car - digitos;
	char *id = malloc((num_car + 1) * sizeof (char));
	char *char_digitos = malloc(sizeof (digitos));
	int i = 0;
	
	for(i = 0; i < ceros; i ++)
		id[i] = '0';
	
	id[ceros] = '\0';
	
	sprintf(char_digitos,"%d",n);
	
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
	
	
