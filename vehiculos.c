#include "Vehiculos.h"
#include "Utilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_vehiculos(Datos_vehiculos *vector, int *numero_vehiculos){

    int selec = 0, id_user = -1;
    int posicion = 0;

    do{

        system("cls");
        printf("\tVEHICULOS\n\n");
        printf("1. Agregar vehiculo\n2. Modificar vehiculo\n3. Eliminar vehiculo\n4. Listar vehiculos\n5. Volver\n\n");
        printf("Seleccione una opcion: ");
        selec = 0;
        fflush(stdin);
        scanf("%i", &selec);
        system("cls");

        switch (selec) {
            case 1: agregar_vehiculo(&vector, numero_vehiculos); break;
            case 2: modificar_vehiculo(vector, posicion); break;
            case 3: borrar_vehiculo(vector, posicion); break;
            case 4: lista_vehiculos(vector, *numero_vehiculos); system("pause"); break;
            case 5: break;
            default: printf("\nSELECCIONE UNA OPCION VALIDA\n\n");
                system("pause");
                system("cls");
        }
    } while(selec != 5);
}



Datos_vehiculos *cargar_estrucura_vehiculo(int *numero_vehiculos){
	
	char linea[66];
	FILE *f;
	Datos_vehiculos *vehiculos=0; //=0 para inicializar?
	*numero_vehiculos = 0;
	char *token;

	
	f=fopen("Vehiculos.txt","w");
	if(f==NULL) printf("No se ha encontrado el fichero.\n");
	else{
		//Falta funcion para meter parametros por teclado creo. ¿aqui o en otra funcion?
		while(fgets(linea,66,f) != NULL){
		
		token = strtok(linea,"-");
		strcpy(vehiculos[*numero_vehiculos].matric_veh,token);
		
		token = strtok(NULL,"-");
		vehiculos[*numero_vehiculos].id_usu=atoi(token);
		
		token = strtok(NULL,"-");
		vehiculos[*numero_vehiculos].num_plazas=atoi(token);
		
		token = strtok(NULL,"\n");
		strcpy(vehiculos[*numero_vehiculos].descrip_veh,token);
				
		*numero_vehiculos++;
		
		}
		
		vehiculos=(Datos_vehiculos *)realloc(vehiculos, *numero_vehiculos*sizeof(Datos_vehiculos));
	}
	
	fclose(f);
	return vehiculos;
	// Hay que poner algo que te lleve al menú otra vez?
}



void lista_vehiculos(Datos_vehiculos *vector, int n ){ // num vehiculos q hay. Datos_vehiculos *vector = Datos_vehiculos vector[]
	int i;
	
	printf("LISTA VEHICULOS\n\nMatricula-ID Usuario-Numero de plazas-Descripcion\n\n");
	
	for(i = 0; i < n; i++){
	
		printf("%s-%s-%s-%s\n",vector[i].matric_veh, vector[i].id_usu, vector[i].num_plazas, vector[i].descrip_veh);
	
	}
	
	puts(""); //¿Que hacia?
}

void agregar_vehiculo(Datos_vehiculos **vector, int *tamano) { //¿Qué hacen los 2 punteros (**)?
    Datos_vehiculos vehiculo;

    printf("Introduce la matricula (maximo 7 caracteres): ");
    fgets(vehiculo.matric_veh, 8, stdin);
    quitar_salto(vehiculo.matric_veh);

    printf("Introduce el ID del usuario: ");
    scanf("%d", &vehiculo.id_usu);
    fflush(stdin);

    printf("Introduce el numero de plazas: ");
    scanf("%d", &vehiculo.num_plazas);
    fflush(stdin);

    printf("Introduce la descripcion del vehiculo (maximo 50 caracteres): ");
    fgets(vehiculo.descrip_veh, 51, stdin);
    quitar_salto(vehiculo.descrip_veh);

    (*tamano)++;
    Datos_vehiculos *tmp = (Datos_vehiculos *) realloc(*vector, (*tamano) * sizeof(Datos_vehiculos));
    if (tmp != NULL) {
        *vector = tmp;
        (*vector)[(*tamano)-1] = vehiculo;
    } else {
        printf("Error al reservar memoria.\n");
        exit(EXIT_FAILURE);
    }
}


void modificar_vehiculo(Datos_vehiculos *vector, int posicion) {
    char matricula[8];
    int pos;

    do {
        printf("Introduce la matricula del vehiculo a modificar (maximo 7 caracteres): ");
        fgets(matricula, 8, stdin);
        quitar_salto(matricula);
        pos = buscar_matricula(vector, posicion, matricula);
        if (pos == -1) {
            printf("La matricula no existe.\n");
        }
    } while (pos == -1);

    printf("Introduce el ID del usuario: ");
    scanf("%d", &vector[pos].id_usu);
    fflush(stdin);

    printf("Introduce el numero de plazas: ");
    scanf("%d", &vector[pos].num_plazas);
    fflush(stdin);

    printf("Introduce la descripcion del vehiculo (maximo 50 caracteres): ");
    fgets(vector[pos].descrip_veh, 51, stdin);
    quitar_salto(vector[pos].descrip_veh);
}




void borrar_vehiculo(Datos_vehiculos *vector, int *tamano) {
    char matricula[8];
    int pos, i;
    Datos_vehiculos *aux;

    do {
        printf("Introduce la matricula del vehiculo a borrar (maximo 7 caracteres): ");
        fgets(matricula, 8, stdin);
        quitar_salto(matricula);
        pos = buscar_matricula(vector, *tamano, matricula);
        if (pos == -1) {
            printf("La matricula no existe.\n");
        }
    } while (pos == -1);
    
    aux=(Datos_vehiculos *)malloc((*tamano)*sizeof(Datos_vehiculos));
    if(aux==NULL){
    	printf("No se ha podido reservar memoria.\n");
    	exit(1);
	}

    for (i = pos; i < *tamano - 1; i++) {
		if(i==pos){
			strcpy(aux[i].matric_veh, vector[i].matric_veh);
			aux[i].id_usu=vector[i].id_usu;
			aux[i].num_plazas=vector[i].num_plazas;
			strcpy(aux[i].descrip_veh, vector[i].descrip_veh);
			
		}
		strcpy(vector[i - 1].matric_veh, vector[i].matric_veh);
    	vector[i - 1].id_usu = vector[i].id_usu;
        vector[i - 1].num_plazas = vector[i].num_plazas;
        strcpy(vector[i - 1].descrip_veh, vector[i].descrip_veh);
        if(i==*tamano-1){
        	strcpy(vector[i].matric_veh, aux[i].matric_veh);
        	vector[i].id_usu=aux[i].id_usu;
        	vector[i].num_plazas=aux[i].num_plazas;
        	strcpy(vector[i].descrip_veh, aux[i].descrip_veh);
		}
    }

    (*tamano)--;
    vector=(Datos_vehiculos *)realloc(vector, (*tamano)*sizeof(Datos_vehiculos));
    if(vector==NULL){
    	printf("No se ha podido reservar memoria.\n");
    	exit(1);
	}
}



int buscar_matricula(Datos_vehiculos *vector, int tamano, char *matricula) {
	int i;
	
    for (i=0; i < tamano; i++) {
        if (strcmp(vector[i].matric_veh, matricula) == 0) {
            return i;
        }
    }
    return -1;
}
