#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char matric_veh[8];
	char id_usu[5];
	char num_plazas[2];
	char descrip_veh[51];
}Datos_vehiculos;


Datos_vehiculo *cargar_estrucura_vehiculo(int *);

void lista_vehiculos();


//¿Qué funciones meto aquí? Las de cambiar salto o las de añadir vehiculo, etc.
