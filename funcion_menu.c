
#include "cabeceras.h"

//Cabecera: void menu (int selec)
//Precondición: recibe un entero
//Postcondición: imprime por pantalla un menú, el cual permite elegir diferentes opciones. No devuelve nada.

void menu(int selec){

    usuario *user;
    int *numero_usuarios;

    do{

        printf("Opcion 1:Perfil  \n");
        printf("Opcion 2: Vehiculos \n");
        printf("Opcion 3: Viajes\n");
        printf("\nSeleccione una opcion: ");
        scanf("%i", &selec);

        switch(selec){

            case 1: printf("Mostrar lista.\n"); cargar(user, numero_usuarios); mostrar_lista(user, numero_usuarios); break;
            case 2: printf("Anadir.\n"); cargar(user, numero_usuarios); anadir(user, numero_usuarios); break;
            case 3: printf("Has seleccionado la opcion 3.\n"); break;
            default: printf("\nSELECCIONE UNA OPCION VALIDA\n\n"); fflush(stdin);
                system("pause");
                system("cls");

        }
    }while (selec < 1 || selec > 3);

    printf("%s-%s-%s-%s-%s-%s\n\n", user[0].Id_usuario, user[0].Nomb_usuario,user[0].Localidad,user[0].Usuario,user[0].Perfil_usuario,user[0].Contrasena);
    printf("Fuera de funcion: %i\n\n", *numero_usuarios);

}
