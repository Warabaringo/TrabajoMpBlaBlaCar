#include "usuarios.h"

//Cabecera: void crear_fichero()
//Precondicion: sin precondicion
//Postcondicion: Se crea un fichero de texto "usuarios.txt". Si el fichero ya existe, la funcion\
no haría nada

void crear_fichero(){
    FILE *f;
    f = fopen("usuarios.txt","a");
    fclose(f);
}


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


//Cabecera: usuario *cargar(usuario *usu)
//Precondicion: se necesita un fichero de texto "usuarios.txt". Recibe un vector de estructura dinámico
//Postcondicion: devuelve el vector con los datos del fichero de texto almacenados en él

usuario *cargar(usuario *usu, int *numero_usuarios){

    FILE *f ;
    char *token, linea[67];

    (*numero_usuarios) = 0;

    f = fopen("usuarios.txt","r");
    if(f == NULL) printf("No se ha podido abrir el fichero.\n\n");
    else{

        usu = (usuario *) malloc(sizeof (usuario));

        while(fgets(linea,67,f) != NULL){

            usu =(usuario *)realloc(usu, (*numero_usuarios+1)*sizeof(usuario));
            token = strtok(linea,"-");
            strcpy(usu[*numero_usuarios].Id_usuario,token);

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


    printf("%s-%s-%s-%s-%s-%s\n", usu[0].Id_usuario, usu[0].Nomb_usuario,usu[0].Localidad,usu[0].Usuario,usu[0].Perfil_usuario,usu[0].Contrasena);
    printf("%s-%s-%s-%s-%s-%s\n", usu[1].Id_usuario, usu[1].Nomb_usuario,usu[1].Localidad,usu[1].Usuario,usu[1].Perfil_usuario,usu[1].Contrasena);
    printf("%s-%s-%s-%s-%s-%s\n", usu[2].Id_usuario, usu[2].Nomb_usuario,usu[2].Localidad,usu[2].Usuario,usu[2].Perfil_usuario,usu[2].Contrasena);
    printf("%s-%s-%s-%s-%s-%s\n\n", usu[3].Id_usuario, usu[3].Nomb_usuario,usu[3].Localidad,usu[3].Usuario,usu[3].Perfil_usuario,usu[3].Contrasena);

    printf("En funcion cargar: %i\n\n", *numero_usuarios);

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
        printf("%s-%s-%s-%s-%s-%s", user[i].Id_usuario, user[i].Nomb_usuario, user[i].Localidad, user[i].Perfil_usuario, user[i].Usuario, user[i].Contrasena);
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

            quitar_salto(user[*numero_usuarios].Id_usuario);
            quitar_salto(user[*numero_usuarios].Nomb_usuario);
            quitar_salto(user[*numero_usuarios].Localidad);
            quitar_salto(user[*numero_usuarios].Perfil_usuario);
            quitar_salto(user[*numero_usuarios].Usuario);
            quitar_salto(user[*numero_usuarios].Contrasena);

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


