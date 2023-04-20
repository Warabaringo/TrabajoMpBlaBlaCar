#ifndef VEHICULOS_H
#define VEHICULOS_H

typedef struct{
	char matric_veh[8];
	int id_usu;  
	int num_plazas;
	char descrip_veh[51];
}Datos_vehiculos;

//Cabecera: void menu_vehiculos(Datos_vehiculos *, int *
//Condicion:
//Postcondicon: Imprime por pantalla un menu, el cual permite elegir diferentes opciones. No devuelve nada.
void menu_vehiculos(Datos_vehiculos *, int *);

//Cabecera:void lista_vehiculos(Datos_vehiculos *, int)
//Condicion:
//Postcondicion: Muestra una lista de los vehiculos que están registrados.
void lista_vehiculos(Datos_vehiculos *, int);

//Cabecera:void agregar_vehiculo(Datos_vehiculos **, int *)
//Condicion:
//Postcondicion: Registra un vehiculo mas en la lista.
void agregar_vehiculo(Datos_vehiculos **, int *);

//Cabecera:void modificar_vehiculo(Datos_vehiculos *, int)
//Condicion:
//Postcondicion: Modifica los datos de un vehiculo ya registrado.
void modificar_vehiculo(Datos_vehiculos *, int);

//Cabecera:void borrar_vehiculo(Datos_vehiculos *, int *)
//Condicion:
//Postcondicion: Elimina un vehiculo de la lista.
void borrar_vehiculo(Datos_vehiculos *, int *);

//Cabecera:int buscar_matricula(Datos_vehiculos *, int , char *)
//Condicion:
//Postcondicion: Busca si la matricula introducida por el usuario pertenece a un vehiculo o no existe.
int buscar_matricula(Datos_vehiculos *, int *, char *);

#endif

