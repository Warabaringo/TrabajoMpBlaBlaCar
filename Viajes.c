#include "Viajes.h"

void Rellenar_Fichero(Struct_Viaje *v,int n){
	
	FILE *f;
	int i;
	f = fopen("Viajes.txt","w");
	
	printf("Rellene La estructura.\n");
	
	for(i=0;i<n;i++){
		
		fflush(stdin);
		printf("Introduzca el id del viaje: ");
		fgets(v[i].id_viaje,n,stdin);
		fflush(stdin);
		
		printf("Introduzca el id de la matricula: ");
		fgets(v[i].id_mat,n,stdin);
		fflush(stdin);
		
		do{
			printf("Introduzca el dia del viaje: ");
			scanf("%c\n",&v[i].fecha.dia);
			printf("Introduzca el mes del viaje: ");
			scanf("%c\n",&v[i].fecha.mes);
			printf("Introduzca el anio del viaje: ");
			scanf("%c\n",&v[i].fecha.anio);
			//sscanf(stdin,"%i/%i/%i",)
		}while((v[i].fecha.dia >= '1' && v[i].fecha.dia <= '30') && (v[i].fecha.mes >= '1' && v[i].fecha.mes <= '12') && (v[i].fecha.anio > '2022') );
		
		do{
			printf("Introduzca la hora inicial del viaje: ");
			scanf("%c\n",v[i].hora.H_inic);
			printf("Introduzca la hora final del viaje: ");
			scanf("%c\n",v[i].hora.H_fin);
		}while((v[i].hora.H_inic >= '00' && v[i].hora.H_inic <= '24') && (v[i].hora.H_fin >= '0' && v[i].hora.H_fin <= '24'));
		
		printf("Introduzca las plazas libres: ");
		scanf("%i",&v[i].Plazas_libres);
		
		printf("Introduzca el importe total: ");
		scanf("%i",&v[i].Importe_Total);
		
		printf("Introduzca el estado del viaje: ");
		fgets(v[i].Estado,n,stdin);
		fflush(stdin);
		
		fprintf(f,"%s-%s-%s-%s-%s-%.2f-%s",v[i].id_viaje,v[i].id_mat,v[i].fecha,v[i].hora,v[i].Plazas_libres,v[i].Importe_Total,v[i].Estado);
	}//Falta arreglar concatenar hora y fecha.
	
	printf("Estructura volcada en Fichero.\n\n");
	
	fclose(f);				
}

//PREGUNTA 1: Viajes.c deber?a de tener Menu.h importado? ya que Viajes.c utiliza variables del Menu.c (Menu.c es como el main de viajes.c)
//PREGUNTA 2: En vez de declarar el vector din?mico se puede poner en Viajes.h para as? simplemente importar el m?dulo y poder usar
//			  el vector sin declararlo?



