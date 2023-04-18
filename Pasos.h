//
// Created by crist on 09/03/2023.
//

#ifndef PASOS_H
#define PASOS_H
#include <stdio.h>
typedef struct {
	int Id_viaje;
	char Poblacion[21];
}Pasos;

// Precondición: p no esta vacío
// Postcondición: Muestra p
void mostrar_paso(Pasos p);
// Precondición: p inicializado, n > 0
// Postcondición: Muestra todos los pasos del vector p
void mostrar_pasos(Pasos *p, unsigned n);
// Precondición: nPasos > 0
// Postcondición: Inicializa el vector de la estructura Pasos de Pasos.txt y devuelve por parámetro el número de pasos
Pasos *leer_pasos(unsigned *nPasos);
// Precondición: paso no nulo, f debe apuntar a pasos.txt
// Postcondición: Guarda un paso en el fichero f
void guardar_paso(Pasos paso, FILE *f);
// Precondición: n > 0
// Postcondición: Guarda todos los pasos en pasos.txt
void guardar_pasos(Pasos *pasos, unsigned n);
// Precondición: n > 0
// Postcondición: Devuelve la posición de la primera vez que se encuentra la id proporcionada
int encontrar_id_paso(Pasos *p, unsigned n, int id);
// Precondición: n > 0
// Postcondición: Devuelve la posición en el que se encuentra el paso buscado por id y población
int encontrar_paso(Pasos *p, unsigned n,int id, char *poblacion);
// Precondición: n > 0
// Postcondición: Agrega tantos pasos como el usuario quiera
Pasos *agregar_pasos(Pasos *original,int *n);
// Precondición: n > 0, i >= 0
// Postcondición: elimina el paso i-1
Pasos *eliminar_paso(Pasos *original, int *n, int i);
// Precondición: n > 0
// Postcondición: Elimina todos los pasos con id = id
Pasos *eliminar_pasos(Pasos *original, int *n, int id);
// Precondición: n > 0
// Postcondición: Modifica los pasos que quiera el usuario
Pasos *modificar_pasos(Pasos *original, int n, int id);
// Precondición: Ninguna
// Postcondición: Modifica el paso "original"
void modificar_paso(Pasos *original);
// Precondición: nTotal > 0
// Postcondición: Devuelve si existe un paso, omitiendo el actual
int existe_paso_no_actual(Pasos *p, int nTotal, char *Poblacion, int actual, int id);
// Precondición: n > 0
// Postcondición: Devuelve 1 si existe y 0 si no algún paso con esa id
int existe_paso(Pasos *p, unsigned n, int id);
// Precondición: n > 0
// Postcondición: Muestra todos los pasos con la id id
void mostrar_pasos_id(Pasos *pasos, int n, int id);
// Precondición: numero_pasos > 0
// Postcondición: Ordena los pasos por id
Pasos *ordenar_pasos(Pasos *p, int numero_pasos);
// Precondición: numero_pasos > 0
// Postcondición: Genera una nueva id del siguiente paso
int generar_id_pasos(Pasos *p, int *numero_pasos);
#endif //PASOS_H
