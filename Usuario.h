#ifndef Usuario_H
#define Usuario_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    int  Id_usuario;
    char Nomb_usuario[21];
    char Localidad[21];
    char Perfil_usuario[14];
    char Usuario[6];
    char Contrasena[9];

}usuario;

void menu();
void crear_fichero();
usuario *cargar(int *numero_usuarios);
void mostrar_lista(usuario *user, int *numero_usuarios);
void anadir(usuario *user, int *numero_usuarios);
int iniciar_sesion(usuario *user, int *numero_usuarios);

#endif