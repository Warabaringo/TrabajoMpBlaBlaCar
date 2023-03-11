#include "usuarios.h"

void perfil(){



}

int iniciar_sesion(usuario *user, int *numero_usuarios){

    FILE *f;
    int i, j, valor_usuario, salida = 0;
    char login[5], psw[8];

    f = fopen("Usuarios.txt", "r");
    if(f == NULL) printf("No se ha podido abrir el archivo");
    else{

        printf("Introduce usuario: "); fgets(login, 6, stdin); puts("");
        printf("Introduce contrasena: "), fgets(psw, 9, stdin); puts("");

        for(i = 0; i < *numero_usuarios && salida == 0; i++){

            if(strcmp(login, user[i].Usuario) == 0){
                for(j = 0; j < *numero_usuarios && salida == 0; j++){
                    if(strcmp(psw, user[j].Contrasena) == 0){
                        valor_usuario = i;
                        salida = 1;
                    }
                }
            }

        }
        if(salida == 0) printf("Usuario o contrasena incorrectos.\n\n");
    }
    return valor_usuario;
};

void registrarse(){


}