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

}

// FUNCIONES RELACIONADAS A FICHEROS

//Cabecera: void crear_fichero()
//Precondicion: sin precondicion
//Postcondicion: Se crea un fichero de texto "usuarios.txt". Si el fichero ya existe, la funcion\
no haría nada

void crear_fichero(){
    FILE *f;
    f = fopen("usuarios.txt","a");
    fclose(f);
}

//Cabecera: usuario *cargar(int *numero_usuarios)
//Precondicion: se necesita un fichero de texto "usuarios.txt". Recibe el numero de usuario, inicialmente a cero
//Postcondicion: devuelve el vector con los datos del fichero de texto almacenados en él

usuario *cargar(int *numero_usuarios){

    FILE *f ;
    char *token, linea[67];
    usuario *usu;

    f = fopen("usuarios.txt","r");
    if(f == NULL) printf("No se ha podido abrir el fichero.\n\n");
    else{

        usu = (usuario *)malloc((*numero_usuarios+1)* sizeof(usuario));
        //usu = (usuario *) calloc(*numero_usuarios+1,sizeof(usuario));

        while(fgets(linea,67,f) != NULL){
            usu =(usuario *)realloc(usu, (*numero_usuarios+1)*sizeof(usuario));
            token = strtok(linea,"-");
            usu[*numero_usuarios].Id_usuario = atoi(token);

            token = strtok(NULL,"-");
            strcpy(usu[*numero_usuarios].Nomb_usuario,token);

            token = strtok(NULL,"-");
            strcpy(usu[*numero_usuarios].Localidad,token);

            token = strtok(NULL,"-");
            strcpy(usu[*numero_usuarios].Perfil_usuario,token);

            token = strtok(NULL,"-");
            strcpy(usu[*numero_usuarios].Usuario,token);

            token = strtok(NULL,"\n");
            strcpy(usu[*numero_usuarios].Contrasena,token);

            (*numero_usuarios)++;
        }
    }

    printf("En funcion cargar: %i\n\n", *numero_usuarios);

    printf("En funcion cargar: %05d-%s-%s-%s-%s-%s\n", usu[0].Id_usuario, usu[0].Nomb_usuario, usu[0].Localidad, usu[0].Perfil_usuario, usu[0].Usuario, usu[0].Contrasena);


    fclose(f);

    free(usu);
    return usu;
}


//Cabecera: void mostrar_lista(usuario *user, int *numero_usuarios)
//Precondicion: Recibe un vector de estructura dinámico y un puntero a entero. El vector y el entero deben estar cargados
//Postcondicion: Muestra una lista de todos los usuarios con sus datos

void mostrar_lista(usuario *user, int *numero_usuarios){
    int i;

    printf("LISTA\n\nID-Nombre-Localidad-Perfil-usuario-Contrasena\n\n");

    for(i = 0; i < (*numero_usuarios); i++){
        printf("%05d-%s-%s-%s-%s-%s\n", user[i].Id_usuario, user[i].Nomb_usuario, user[i].Localidad, user[i].Perfil_usuario, user[i].Usuario, user[i].Contrasena);
    }
    puts("");
}

void anadir(usuario *user, int *numero_usuarios){

    FILE *f;
    int i, j, aux, bucle = 0;
    char continuar = 's';

    f = fopen("Usuarios.txt", "a");

    if(f == NULL) printf("No se ha podido abrir el fichero.\n\n");
    else{

        user = (usuario *) malloc(*numero_usuarios+1);
        printf("Introduzca un ID de 4 digitos: "); fflush(stdin), fgets(user[*numero_usuarios].Id_usuario, 5, stdin);
        printf("Control 1\n");
        for(i = 0; i <  *numero_usuarios && bucle == 0; i++){

            do{

                aux = 0;
                for(j = 0; j < *numero_usuarios && aux == 0; j++){

                    if(strcmp(user[j].Id_usuario, user[*numero_usuarios].Id_usuario) == 0) aux = 1;

                }

                if(aux == 1){
                    printf("Introduce un ID valido: ");
                    fflush(stdin);
                    fgets(user[*numero_usuarios].Id_usuario, 6, stdin);
                }

            }while(aux == 1);

            printf("Introduzca su nombre (20 caracteres): "); fflush(stdin); fgets(user[*numero_usuarios].Nomb_usuario, 21, stdin);
            printf("Introduce la localidad (20 caracteres): "); fflush(stdin); fgets(user[*numero_usuarios].Localidad, 21, stdin);
            printf("Introduce permisos de usuario (usario o administrador): "); fflush(stdin); fgets(user[*numero_usuarios].Perfil_usuario, 14, stdin);
            printf("Introduce el nombre de usuario (5 caracteres): "); fflush(stdin); fgets(user[*numero_usuarios].Usuario, 6, stdin);
            printf("Introduzca la contrasena (8 caracteres): "); fflush(stdin); fgets(user[*numero_usuarios].Contrasena, 9, stdin);

            /*
            quitar_salto(user[*numero_usuarios].Id_usuario);
            quitar_salto(user[*numero_usuarios].Nomb_usuario);
            quitar_salto(user[*numero_usuarios].Localidad);
            quitar_salto(user[*numero_usuarios].Perfil_usuario);
            quitar_salto(user[*numero_usuarios].Usuario);
            quitar_salto(user[*numero_usuarios].Contrasena);
             */

            printf("%s-%s-%s-%s-%s-%s", user[*numero_usuarios].Id_usuario, user[*numero_usuarios].Nomb_usuario, user[*numero_usuarios].Localidad, user[*numero_usuarios].Usuario, user[*numero_usuarios].Perfil_usuario, user[*numero_usuarios].Contrasena);

            do{
                system("cls");
                printf("%cDesea a%cadir otro alumno?\n\n(s/n)",168,164);
                fflush(stdin);
                scanf("%c",&continuar);
                system("cls");

            }while(continuar != 's' && continuar != 'n');

            if(continuar == 'n') bucle = 1;
        }

    }

    fclose(f);

}


/*

//cabecera: void quitar_salto(char aux[140])
//precondición: recibe un string
//postcondición: intercambia el caracter '\n' de un string por el caracter '\0'
void quitar_salto(char *aux){
    int i, temp = 0;
    for(i = 0; i < 67 && temp == 0; i++){
        if(aux[i] == '\n') {
            aux[i] = '\0';
            temp = 1;
        }
    }
}
*/