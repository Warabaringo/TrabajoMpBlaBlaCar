#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char matric_veh[8];
	int id_usu;  
	int num_plazas;
	char descrip_veh[51];
}Datos_vehiculos;

//Cabecera: void menu (int selec)
//Condicion: recibe un entero
//Postcondicon: Imprime por pantalla un menu, el cual permite elegir diferentes opciones. No devuelve nada.
void menu_vehiculos(Datos_vehiculo *, int *);

//Cabecera:Datos_vehiculos *cargar_estrucura_vehiculo(int *)
//Condicion:
//Postcondicion: Carga los datos en la estructura Datos_vehiculos. Devuelve la estructura con los datos cargados.
Datos_vehiculos *cargar_estrucura_vehiculo(int *);

//Cabecera:void lista_vehiculos(Datos_vehiculos *, int)
//Condicion:
//Postcondicion: Muestra una lista de los vehiculos que están registrados.
void lista_vehiculos(Datos_vehiculos *, int);

//Cabecera:void agregar_vehiculo(Datos_vehiculos *, int *)
//Condicion:
//Postcondicion: Registra un vehiculo mas en la lista.
void agregar_vehiculo(Datos_vehiculos *, int *);  //Al poner el vector en la cabecera se pone el corchete?

//Cabecera:void borrar_vehiculo(Datos_vehiculos[], int , char[])
//Condicion:
//Postcondicion: Elimina un vehiculo de la lista.
void borrar_vehiculo(Datos_vehiculos[], int , char[]);  //cambiar



