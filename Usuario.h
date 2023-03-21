#ifndef USUARIO_H
#define USUARIO_H
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

//FUNCIONES FICHERO
void menu_inicio();
void crear_fichero();
usuario *cargar(int *numero_usuarios);
void mostrar_lista(usuario *user, int *numero_usuarios);
void sobreescribir_fichero(usuario *user, int *numero_usuarios);
usuario *dar_alta(usuario *user, int *numero_usuarios);
usuario *dar_baja(usuario *user, int *numero_usuarios);
usuario *ordenar_usuarios(usuario *user, int numero_usuarios);
int generar_id_usuarios(usuario *user, int *numero_usuarios);


//FUNCIONES USUARIO
int iniciar_sesion(usuario *user, int *numero_usuarios);
void cuenta_usuario(usuario *user, int sesion_usuario, int *numero_usuarios);
void cuenta_admin(usuario *user, int sesion_usuario, int *numero_usuarios);
usuario *modificar_usuario(usuario *user, int sesion_usuario, int *numero_usuarios);
usuario *perfil(usuario *user, int sesion_usuario, int *numero_usuarios);
void menu_admin_usuarios(usuario *user, int *numero_usuarios);

#endif