#include "Usuario.h"

void perfil(){



}

int iniciar_sesion(usuario *user, int *numero_usuarios){

    FILE *f;
    int i, j, valor_usuario, salida = 0, error = 0;
    char login[5], psw[8];

    f = fopen("Usuarios.txt", "r");
    if(f == NULL) printf("No se ha podido abrir el archivo");
    else{

        printf("Introduce usuario: "); fgets(login, 6, stdin); puts("");
        printf("Introduce contrasena: "), fgets(psw, 9, stdin); puts("");

        for(i = 0; i < *numero_usuarios && salida == 0 && error == 0; i++){

            if(strcmp(login, user[i].Usuario) == 0){

                    if(strcmp(psw, user[i].Contrasena) == 0){
                        valor_usuario = i;
                        salida = 1;
                    }else error = 1;

            }

        }
        if(salida == 0 || error == 1) printf("Usuario o contrasena incorrectos.\n\n");
    }


    return valor_usuario;
};

void registrarse(){


}

//Cabecera: void menu (int selec)
//Precondición:
//Postcondición: imprime por pantalla un menú, el cual permite elegir diferentes opciones. No devuelve nada.

void menu(){

    int selec;
    usuario *user;
    int *numero_usuarios = 0;

    user = cargar(&numero_usuarios);

    do{

        printf("Opcion 1:Perfil  \n");
        printf("Opcion 2: Vehiculos \n");
        printf("Opcion 3: Viajes\n");
        printf("\nSeleccione una opcion: ");
        scanf("%i", &selec);

        switch(selec){

            case 1: mostrar_lista(user, &numero_usuarios); break;
            case 2: printf("Anadir.\n"); anadir(user, numero_usuarios); break;
            case 3: printf("Has seleccionado la opcion 3.\n"); break;
            default: printf("\nSELECCIONE UNA OPCION VALIDA\n\n"); fflush(stdin);
                system("pause");
                system("cls");

        }
    }while (selec < 1 || selec > 3);

    printf("%s", user[0].Id_usuario);

}

