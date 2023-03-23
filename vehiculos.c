#include "Vehiculos.h"

int main(){
	
	Datos_vehiculos* prueba;
	int num_vehiculos;
	
	prueba=(Datos_vehiculos*)malloc(num_vehiculos*sizeof(Datos_vehiculos));
	
}


//Cabecera:Datos_vehiculo *cargar_estrucura_vehiculo(int *)
//Condicion:
//Postcondicion: Carga la estructura en el fichero "Vehiculos.txt".
Datos_vehiculo *cargar_estrucura_vehiculo(int *numero_vehiculos){
	
	char linea_vehiculos[66];
	FILE *f;
	Datos_vehiculos *vehiculos;
	int numero_vehiculos = 0;

	
	f=fopen("Vehiculos.txt","w");
	if(f==NULL) printf("No se ha encontrado el fichero.\n");
	else{
		//Falta funcion para meter parametros por teclado creo. ¿aqui o en otra funcion?
		while(fgets(linea,66,f) != NULL){
		
		vehiculos=(Datos_vehiculos *)realloc(vehiculos, numero_vehiculos*sizeof(Datos_vehiculos));
		token = strtok(linea,"-");
		strcpy(vehiculos[numero_vehiculos].matric_veh,token);
		
		token = strtok(NULL,"-");
		strcpy(vehiculos[numero_vehiculos].id_usu,token);
		
		token = strtok(NULL,"-");
		strcpy(vehiculos[numero_vehiculos].num_plazas,token);
		
		token = strtok(NULL,"\n");
		strcpy(vehiculos[numero_vehiculos].descrip_veh,token);
				
		*numero_vehiculos++;
		
		}
		
		//¿Falta algo aquí?
	}
	
	fclose(f);
	return vehiculos;
	free(vehiculos);
	
}


//Cabecera:void lista_vehiculos()
//Condicion:
//Postcondicion: Muestra una lista de los vehiculos que hay en el fichero "Vehiculos.txt".
void lista_vehiculos(){
	int i;
	
	printf("LISTA VEHICULOS\n\nMatricula-ID Usuario-Numero de plazas-Descripcion\n\n");
	
	for(i = 0; i < numero_alumnos; i++){
	
		printf("%s-%s-%s-%s\n",Datos_vehiculos[i].matric_veh, Datos_vehiculos[i].id_usu, Datos_vehiculos[i].num_plazas, Datos_vehiculos[i].descrip_veh);
	
	}
	
	puts(""); //¿Que hacia?
}



void introducir_vehiculos{
	
	
	
}
