#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabeceras_vehiculos.h"

alum *alumno = NULL;
unsigned numero_alumnos = 0;


void menu(int *x){
	
	int cont = 1;
	
	system("cls");
	
	printf("CUADERNO DIGITAL\n\n(1).A%cadir vehiculos\n(2).Lista vehiculos\n(3).Eliminar alumno\n(4).Salir del programa\n\n",164);
	scanf("%i",x);
	
	switch(*x){
		case 1: system("cls"); add(); system("pause"); break;
		case 2: system("cls"); lista_alumnos(); system("pause"); break;
		case 3: system("cls"); eliminar_string(); system("pause"); break;
		case 4: goto fin; break;
		default: system("cls"); fflush(stdin); 
	}
		
	fin:
	system("cls");
	printf("\n");
	
}

alum *cargar(unsigned *nalumnos){
int i = 0;
FILE *f ;
char linea[140];

*nalumnos = 0;

char *token;

f = fopen("Vehiculos.txt","r");
if(f == NULL) printf("No se ha podido abrir el fichero.\n\n");
else{

	while(fgets(linea,140,f) != NULL){
		
		alumno =(alum *)realloc(alumno, (*nalumnos+1)*sizeof(alum));
		token = strtok(linea,"-");
		strcpy(alumno[*nalumnos].Id_alum,token);
		
		token = strtok(NULL,"-");
		strcpy(alumno[*nalumnos].Nombre_alum,token);
		
		token = strtok(NULL,"-");
		strcpy(alumno[*nalumnos].Direc_alum,token);
		
		token = strtok(NULL,"-");
		strcpy(alumno[*nalumnos].Local_alum,token);
		
		token = strtok(NULL,"-");
		strcpy(alumno[*nalumnos].Curso,token);
		
		token = strtok(NULL,"\n");
		strcpy(alumno[*nalumnos].Grupo,token);
				
		(*nalumnos)++;
		
		}
	
	}
	
	
	
numero_alumnos = *nalumnos;

fclose(f);

return alumno;

}

void lista_alumnos(){
	int i;
	
	printf("LISTA VEHICULOS\n\nID-Nombre-Direccion-Localidad-Curso-Grupo\n\n");
	
	for(i = 0; i < numero_alumnos; i++){
	
		printf("%s-%s-%s-%s-%s-%s\n",alumno[i].Id_alum,alumno[i].Nombre_alum,alumno[i].Direc_alum,alumno[i].Local_alum,alumno[i].Curso,alumno[i].Grupo);
	
	}
	
	puts("");
}

void cambio(char aux[130]){
	int i, temp = 0;
	for(i = 0; i < 130 && temp == 0; i++){
		if(aux[i] == '\n') {
			aux[i] = '\0';
			temp = 1;
		}
	}
}

void add(){
	int i,j,salida;
	int funcion = 1;
	int bucle;
	FILE *f;
	char continuar = 's';
	
	if(numero_alumnos == 0) {
		numero_alumnos++;
	}
	
		
	do{
	
	bucle = 0;
	
	f = fopen("Alumnos.txt","a");
	if(f == NULL) printf("No se ha podido abrir el fichero.\n\n");
	
	else{
	
	
	
	
	for(i = 0; i < numero_alumnos && bucle != 1; i++){
		
				
				
				alumno =(alum *)realloc(alumno, (numero_alumnos+1)*sizeof(alum));
				f = fopen("Alumnos.txt","a");
					
				printf("Introduzca un ID de 6 digitos para el alumno: "); fflush(stdin); fgets(alumno[numero_alumnos].Id_alum,7,stdin);		
				
				printf("Introduzca el nombre del alumno: "); fflush(stdin); fgets(alumno[numero_alumnos].Nombre_alum,21,stdin);				
				printf("Introduzca la direccion del alumno: "); fflush(stdin); fgets(alumno[numero_alumnos].Direc_alum,31,stdin);
				printf("Introduzca la localidad del alumno: "); fflush(stdin); fgets(alumno[numero_alumnos].Local_alum,31,stdin);
				printf("Introduzca el curso del alumno: "); fflush(stdin); fgets(alumno[numero_alumnos].Curso,31,stdin);
				printf("Introduzca el grupo del alumno: "); fflush(stdin); fgets(alumno[numero_alumnos].Grupo,21,stdin);
				
				cambio(alumno[numero_alumnos].Id_alum);
				cambio(alumno[numero_alumnos].Nombre_alum);
				cambio(alumno[numero_alumnos].Direc_alum);
				cambio(alumno[numero_alumnos].Grupo);
				cambio(alumno[numero_alumnos].Curso);
				cambio(alumno[numero_alumnos].Local_alum);
			
				fprintf(f,"%s-%s-%s-%s-%s-%s\n",alumno[numero_alumnos].Id_alum,alumno[numero_alumnos].Nombre_alum,alumno[numero_alumnos].Direc_alum,alumno[numero_alumnos].Local_alum,alumno[numero_alumnos].Curso,alumno[numero_alumnos].Grupo);
				
				do{
					system("cls");
					printf("%cDesea a%cadir otro alumno?\n\n(s/n)",168,164);
					fflush(stdin);
					scanf("%c",&continuar);	
					system("cls");
							
				}while(continuar != 's' && continuar != 'n');
				
				bucle = 1;
			}
	
		
	
		}
		
		fclose(f);
		}while(continuar == 's');
	
	
	
}

void crear_fichero(){	//Crea un fichero de texto "Alumnos". En caso de que ya exista, la función no haría nada
	FILE *f;
	f = fopen("Alumnos.txt","a");
	fclose(f);
}

void eliminar_string(){
	
	FILE *f;
	int id_pedido,id,i,j;
	int aux = 0;
	char temp[140];
	
	printf("Introduzca el ID del alumno que desea eliminar: ");
	scanf("%i",&id_pedido);
	
	for(i = 0; i < numero_alumnos && aux == 0; i++){
		id = atoi(alumno[i].Id_alum);
		if(id == id_pedido){
			
			while(i < numero_alumnos){
				alumno[i] = alumno[i+1];
				i++;
			}
			
			
			aux = 1;
		}
				
	}
	numero_alumnos--;
	
	alumno =(alum *)realloc(alumno, (numero_alumnos)*sizeof(alum));
	
	f = fopen("Alumnos.txt","w");
	
	for(i = 0; i < numero_alumnos; i++){
		fprintf(f,"%s-%s-%s-%s-%s-%s\n",alumno[i].Id_alum,alumno[i].Nombre_alum,alumno[i].Direc_alum,alumno[i].Local_alum,alumno[i].Curso,alumno[i].Grupo);
	}
	
	fclose(f);
		
}



int primer_add(){
	int i,j;
	int salida = 0;
	FILE *f;
	char continuar;
	
	f = fopen("Alumnos.txt","a");
	if(f == NULL) printf("No se ha podido abrir el fichero.\n\n");
	else{
				
		alumno =(alum *)realloc(alumno, (numero_alumnos+1)*sizeof(alum));
				
					
		printf("Introduzca un ID de 6 digitos para el alumno: "); fflush(stdin); fgets(alumno[0].Id_alum,7,stdin);									printf("Introduzca el nombre del alumno: "); fflush(stdin); fgets(alumno[0].Nombre_alum,21,stdin);				
		printf("Introduzca la direccion del alumno: "); fflush(stdin); fgets(alumno[0].Direc_alum,31,stdin);
		printf("Introduzca la localidad del alumno: "); fflush(stdin); fgets(alumno[0].Local_alum,31,stdin);
		printf("Introduzca el curso del alumno: "); fflush(stdin); fgets(alumno[0].Curso,31,stdin);
		printf("Introduzca el grupo del alumno: "); fflush(stdin); fgets(alumno[0].Grupo,21,stdin);
				
		cambio(alumno[0].Id_alum);
		cambio(alumno[0].Nombre_alum);
		cambio(alumno[0].Direc_alum);
		cambio(alumno[0].Grupo);
		cambio(alumno[0].Curso);
		cambio(alumno[0].Local_alum);
		
		fprintf(f,"%s-%s-%s-%s-%s-%s\n",alumno[0].Id_alum,alumno[0].Nombre_alum,alumno[0].Direc_alum,alumno[0].Local_alum,alumno[0].Curso,alumno[0].Grupo);
				
		do{
			system("cls");
			printf("%cDesea a%cadir otro alumno?\n\n(s/n)",168,164);
			fflush(stdin);
			scanf("%c",&continuar);	
			system("cls");
					
		}while(continuar != 's' && continuar != 'n');
				
	}
		fclose(f);
	
	if(continuar == 's') {
		salida = 1;	
	}
	
	numero_alumnos = 1;
	return salida;
}
