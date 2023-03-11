#ifndef USUARIOS_H
#define USUARIOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char Id_usuario[5];
    char Nomb_usuario[21];
    char Localidad[21];
    char Perfil_usuario[14];
    char Usuario[6];
    char Contrasena[9];

}usuario;

void menu(int selec);
void crear_fichero();
usuario *cargar(usuario *user, int *numero_usuarios);
void mostrar_lista(usuario *user, int *numero_userarios);
void anadir(usuario *user, int *numero_usuarios);

#endif