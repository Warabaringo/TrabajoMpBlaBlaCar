#include "Vehiculos.h"

//Cabecera:void introducir_vehiculo()
//Condicion:
//Postcondicion: Se introduce la informacion de un nuevo vehiculo en el fichero "Vehiculos.txt".
void introducir_vehiculo(){
	char linea_vehiculos[66];
	FILE *f;
	Datos_vehiculos *vehiculos;
	unsigned numero_vehiculos = 0;

	
	f=fopen("Vehiculos.txt","w");
	if(f==NULL) printf("No se ha encontrado el fichero.\n");
	else{
		
		while(fgets(linea,66,f) != NULL){
		
		vehiculos=(Datos_vehiculos *)realloc(vehiculos, numero_vehiculos*sizeof(Datos_vehiculos));
		token = strtok(linea,"-");
		strcpy(vehiculos[numero_vehiculos].matric_veh,token);
		
		token = strtok(NULL,"-");
		strcpy(vehiculos[numero_vehiculos].id_usu,token);
		
		token = strtok(NULL,"-");
		strcpy(vehiculos[numero_vehiculos].num_plazas,token);
		
		token = strtok(NULL,"-");
		strcpy(vehiculos[numero_vehiculos].descrip_veh,token);
				
		numero_vehiculos++;
		
		}
		
		
	}
	
	fclose(f);
	
	
}
