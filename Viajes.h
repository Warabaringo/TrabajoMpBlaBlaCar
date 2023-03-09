#ifndef Viajes_h
#define Viajes_h
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char dia[1];
	char mes[1];
	char anio[1];		
}Fecha;

typedef struct{
	char H_inic[1];
	char H_fin[1];	
}Hora;

typedef struct{
	char id_viaje[6];
	char id_mat[7];
	Fecha fecha;
	Hora hora;
	int Plazas_libres;//Solo puede ser un dígito
	float Importe_Total;
	char Estado[20];// Abierto,Cerrado,iniciado,finalizado o anulado.

}Struct_Viaje;

void Rellenar_Fichero(Struct_Viaje *,int);

#endif




