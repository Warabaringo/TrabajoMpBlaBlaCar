//
// Created by crist on 11/03/2023.
//

#include "Utilidades.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void quitar_salto(char *s) {
	char *pos = strchr(s, '\n');
	if(pos != NULL)
		*pos = '\0';
}
