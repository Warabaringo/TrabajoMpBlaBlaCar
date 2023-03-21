#include "Usuario.h"
#include "Utilidades.h"

usuario *perfil(usuario *user, int sesion_usuario, int *numero_usuarios){
    int selec;
    system("cls");

    printf("\tPERFIL\n\n");

    printf("ID: %05d\n", user[sesion_usuario].Id_usuario);
    printf("Nombre: %s\n", user[sesion_usuario].Nomb_usuario);
    printf("Localidad: %s\n", user[sesion_usuario].Localidad);
    printf("Usuario: %s\n", user[sesion_usuario].Usuario);
    printf("Contrasena: %s\n", user[sesion_usuario].Contrasena);

    printf("\n1. Volver\n");
    printf("2. Modificar perfil\n");
    printf("\nIntroduce una opcion: ");
    scanf("%i", &selec);

    do{
        fflush(stdin);

        switch(selec){
            case 1: break;
            case 2: user = modificar_usuario(user, sesion_usuario, numero_usuarios); break;
            default:
                system("cls");
                printf("\tPERFIL\n\n");
                printf("ID: %05d\n", user[sesion_usuario].Id_usuario);
                printf("Nombre: %s\n", user[sesion_usuario].Nomb_usuario);
                printf("Localidad: %s\n", user[sesion_usuario].Localidad);
                printf("Usuario: %s\n", user[sesion_usuario].Usuario);
                printf("Contrasena: %s\n", user[sesion_usuario].Contrasena);

                printf("\n1. Volver\n");
                printf("2. Modificar perfil\n");
                printf("\nIntroduce una opcion valida: ");
                scanf("%i", &selec);

        }

    }while(selec < 1 || selec > 2 );

   // printf("%s", user[sesion_usuario].Nomb_usuario);
    return user;

}

usuario *modificar_usuario(usuario *user, int sesion_usuario, int *numero_usuarios){

    int selec;
    char eliminar;

    system("cls");


    do{
        if(sesion_usuario < 0 || sesion_usuario >= *numero_usuarios){
            printf("Introduce ID de usuario: "); fflush(stdin); scanf("%i", &sesion_usuario); sesion_usuario -= 1;

            if(sesion_usuario < 0 || sesion_usuario >= *numero_usuarios){
                printf("\n\nINTRODUCE UN ID VALIDO\n\n");
                system("pause");
                system("cls");
            }


        }
    }while(sesion_usuario < 0 || sesion_usuario >= *numero_usuarios);


    do{
        printf("MODIFICAR PERFIL\n\n");
        printf("1. Nombre\n");
        printf("2. Localidad\n");
        printf("3. Usuario\n");
        printf("4. Contrasena\n");
        printf("5. Volver\n\n");
        printf("6. Eliminar cuenta\n\n");
        printf("Seleccione una opcion: "); fflush(stdin); scanf("%i", &selec);
        system("cls");

        switch (selec){

            case 1: printf("Introduce nuevo nombre (20 caracteres): "); fflush(stdin); fgets(user[sesion_usuario].Nomb_usuario, 21, stdin); quitar_salto(user[sesion_usuario].Nomb_usuario); break;
            case 2: printf("Introduce nueva localidad (20 caracteres): "); fflush(stdin); fgets(user[sesion_usuario].Localidad, 21, stdin); quitar_salto(user[sesion_usuario].Localidad); break;
            case 3: printf("Introduce nuevo usuario (5 caracteres): "); fflush(stdin); fgets(user[sesion_usuario].Usuario, 6, stdin); quitar_salto(user[sesion_usuario].Usuario); break;
            case 4: printf("Introduce nueva contrasena (8 caracteres): "); fflush(stdin); fgets(user[sesion_usuario].Contrasena, 9, stdin); quitar_salto(user[sesion_usuario].Contrasena); break;
            case 5: break;
            case 6:
                printf("¿Estas seguro que deseas eliminar esta cuenta permanentemente?\n\n(s/n)"); scanf("%c", &eliminar); if(eliminar == 's' || eliminar == 'S') printf("Sin implementar\n\n"); break;//dar_baja()
            default:
                printf("INTRODUCE UNA OPCION VALIDA");
                system("pause");
                system("cls");

        }
        system("cls");
    }while(selec < 1 || selec > 5);

    sobreescribir_fichero(user, numero_usuarios);

    return user;
}

int iniciar_sesion(usuario *user, int *numero_usuarios){

    FILE *f;
    int i, valor_usuario, salida = 0, error = 0;
    char login[6], psw[9];

    f = fopen("Usuarios.txt", "r");
    system("cls");
    if(f == NULL) printf("No se ha podido abrir el archivo");
    else{

        printf("Introduce usuario: "); fflush(stdin); fgets(login, 6, stdin);
        printf("Introduce contrasena: "), fflush(stdin); fgets(psw, 9, stdin); puts("");


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
}

void registrarse(){


}

//Cabecera: void menu (int selec)
//Precondición:
//Postcondición: imprime por pantalla un menú, el cual permite elegir diferentes opciones. No devuelve nada.

void menu_inicio(){

    int selec, salir;
    usuario *user;
    int *numero_usuarios;
    int sesion_usuario;
    char *selec_admin = "administrador";

    user = cargar(&numero_usuarios);

    do{

        user = ordenar_usuarios(user, numero_usuarios);
        sobreescribir_fichero(user, &numero_usuarios);
        system("cls");
        printf("   ___  _           ___  _           ___              \n"
               "  / __\\| |  __ _   / __\\| |  __ _   / __\\  __ _  _ __ \n"
               " /__\\//| | / _` | /__\\//| | / _` | / /    / _` || '__|\n"
               "/ \\/  \\| || (_| |/ \\/  \\| || (_| |/ /___ | (_| || |   \n"
               "\\_____/|_| \\__,_|\\_____/|_| \\__,_|\\____/  \\__,_||_|   \n"
               "                                                      ");
        puts("");

        printf("Opcion 1: Iniciar sesion\n");
        printf("Opcion 2: Registrarse\n");
        printf("Opcion 3: Salir del programa\n");
        printf("\nSeleccione una opcion: ");
        fflush(stdin);
        scanf("%i", &selec);


        switch(selec){

            case 1: sesion_usuario = iniciar_sesion(user, &numero_usuarios); break;
            case 2: system("cls"); user = dar_alta(user, &numero_usuarios); break;
            case 3: salir = 1; break;
            default: printf("\nSELECCIONE UNA OPCION VALIDA\n\n");
                system("pause");

        }

        if(salir == 1) exit(1);

        if(selec == 1){
            if(strcmp(user[sesion_usuario].Perfil_usuario, selec_admin) != 0) cuenta_usuario(user, sesion_usuario, &numero_usuarios);
            else cuenta_admin(user, sesion_usuario, &numero_usuarios);
        }



    }while ((selec < 1 || selec > 3) || salir != 1);

}

void cuenta_admin(usuario *user, int sesion_usuario, int *numero_usuarios){

    int selec, exit = 0;
    system("cls");

    do{
        printf("\tUsuario: %s\n\n", user[sesion_usuario].Nomb_usuario);
        printf("1. Usuarios\n2. Vehiculos\n3. Viajes\n4. Salir\n\n");
        printf("Seleccione una opcion: ");
        selec = 0;
        fflush(stdin);
        scanf("%i", &selec);

        switch (selec) {

            case 1: menu_admin_usuarios(user, numero_usuarios);break;
            case 2: break;
            case 3: break;
            case 4: exit = 1; break;
            default: printf("\nSELECCIONE UNA OPCION VALIDA\n\n");
                fflush(stdin);
                system("pause");
                system("cls");
        }
    }while((selec < 1 || selec > 4) || exit == 0);

}

void menu_admin_usuarios(usuario *user, int *numero_usuarios){

    int selec, exit = 0, id_user = -1;

    do{

        system("cls");
        printf("\tGestion de Usuarios\n\n");
        printf("1. Dar de alta\n2. Dar de baja\n3. Modificar usuario\n4. Listar usuarios\n5. Volver\n\n");
        printf("Seleccione una opcion: ");
        selec = 0;
        fflush(stdin);
        scanf("%i", &selec);
        system("cls");

        switch (selec) {

            case 1: dar_alta(user, numero_usuarios); break;
            case 2: dar_baja(user, numero_usuarios); break;
            case 3: modificar_usuario(user, id_user, numero_usuarios);break;
            case 4: mostrar_lista(user, numero_usuarios); system("pause"); break;
            case 5: exit = 1; break;
            default: printf("\nSELECCIONE UNA OPCION VALIDA\n\n");
                system("pause");
                system("cls");
        }
    }while(selec < 1 || selec > 5 || exit == 0);

}

void cuenta_usuario(usuario *user, int sesion_usuario, int *numero_usuarios){

    int selec;
    system("cls");
    do{

        printf("\tUsuario: %s\n\n",user[sesion_usuario].Nomb_usuario);
        printf("1. Perfil\n2. Vehiculos\n3. Viajes\n4. Salir\n\n");
        printf("Seleccione una opcion: ");
        fflush(stdin);
        scanf("%i", &selec);

        switch (selec){

            case 1: perfil(user, sesion_usuario, numero_usuarios); fflush(stdin); break;
            case 2: printf("Sin implementar.\n"); break;
            case 3: printf("Sin implementar.\n"); break;
            case 4: break;
            default: printf("\nSELECCIONE UNA OPCION VALIDA\n\n"); fflush(stdin);
                system("pause");
                system("cls");
        }
        system("cls");
    }while(selec != 4);



}





//
// FUNCIONES RELACIONADAS A FICHEROS
//


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
    (*numero_usuarios) = 0;

    f = fopen("usuarios.txt","r");
    if(f == NULL){
        printf("No se ha podido abrir el fichero.\n\n");
        exit(1);
    }
    else {

        //usu = (usuario *)malloc((*numero_usuarios+1)* sizeof(usuario));
        usu = (usuario *) calloc((*numero_usuarios) + 1, sizeof(usuario));

        while (fgets(linea, 67, f) != NULL) {
            usu = (usuario *) realloc(usu, (*numero_usuarios + 1) * sizeof(usuario));
            token = strtok(linea, "-");
            usu[*numero_usuarios].Id_usuario = atoi(token);

            token = strtok(NULL, "-");
            strcpy(usu[*numero_usuarios].Nomb_usuario, token);

            token = strtok(NULL, "-");
            strcpy(usu[*numero_usuarios].Localidad, token);

            token = strtok(NULL, "-");
            strcpy(usu[*numero_usuarios].Perfil_usuario, token);

            token = strtok(NULL, "-");
            strcpy(usu[*numero_usuarios].Usuario, token);

            token = strtok(NULL, "\n");
            strcpy(usu[*numero_usuarios].Contrasena, token);

            (*numero_usuarios)++;
        }

    }
    fclose(f);
    return usu;
    free(usu);

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

void sobreescribir_fichero(usuario *user, int *numero_usuarios){

    FILE *f;
    int i;

    f = fopen("Usuarios.txt", "w");

    for(i = 0; i < (*numero_usuarios); i++){
        fprintf(f, "%05d-%s-%s-%s-%s-%s\n", user[i].Id_usuario, user[i].Nomb_usuario, user[i].Localidad, user[i].Perfil_usuario, user[i].Usuario, user[i].Contrasena);
    }

    fclose(f);
}

usuario *dar_alta(usuario *user, int *numero_usuarios){

    FILE *f;
    char *usu = "usuario";
    char nombre_usuario[6];
    int id, salir = 0;

    f = fopen("Usuarios.txt", "a");

    usuario nuevo_usuario;

    nuevo_usuario.Id_usuario = generar_id_usuarios(user, numero_usuarios);

    printf("Introduzca su nombre (20 caracteres): "); fflush(stdin); fgets(nuevo_usuario.Nomb_usuario, 21, stdin);
    printf("Introduzca su localidad (20 caracteres): "); fflush(stdin); fgets(nuevo_usuario.Localidad, 21, stdin);
    strcpy(nuevo_usuario.Perfil_usuario, usu);

    do {
        printf("Introduce su nombre de usuario: "); fflush(stdin); fgets(nombre_usuario, 6, stdin);

        if ((*numero_usuarios) == 0) {
            strcpy(nuevo_usuario.Usuario, nombre_usuario);
        }
        else {
            salir = 0;
            for (int i = 0; i < (*numero_usuarios) && salir == 0; i++) {
                if (strcmp(nombre_usuario, user[i].Usuario) == 0) {
                    salir = 1;
                    printf("USUARIO EXISTENTE, INTRODUZCA UN USUARIO DIFERENTE\n\n");
                    system("pause");
                    system("cls");
                }
            }

            if (salir == 0) {
                strcpy(nuevo_usuario.Usuario, nombre_usuario);
            }
        }
    } while (salir == 1);

    printf("Introduzca una contrasena (8 caracteres): "); fflush(stdin); fgets(nuevo_usuario.Contrasena, 9, stdin);

    quitar_salto(nuevo_usuario.Nomb_usuario);
    quitar_salto(nuevo_usuario.Localidad);
    quitar_salto(nuevo_usuario.Perfil_usuario);
    quitar_salto(nuevo_usuario.Usuario);

    usuario *temporal = (usuario *)malloc((*numero_usuarios + 1) * sizeof(usuario));
    for (int i = 0; i < (*numero_usuarios); i++) {
        temporal[i] = user[i];
    }

    temporal[*numero_usuarios] = nuevo_usuario;

    free(user);
    user = temporal;

    (*numero_usuarios)++;
    sobreescribir_fichero(user, numero_usuarios);

    fclose(f);

    return user;
}

usuario *dar_baja(usuario *user, int *numero_usuarios){

    int id_usuario, encontrado = 0;
    usuario *temporal = (usuario *)malloc((*numero_usuarios - 1) * sizeof(usuario));

    printf("Introduzca el ID del usuario a dar de baja: ");
    scanf("%d", &id_usuario);

    for (int i = 0; i < (*numero_usuarios) && encontrado == 0; i++) {
        if (user[i].Id_usuario == id_usuario) {
            encontrado = 1;

            int j;
            for (j = 0; j < i; j++) {
                temporal[j] = user[j];
            }
            for (j = i + 1; j < (*numero_usuarios); j++) {
                temporal[j - 1] = user[j];
            }
            free(user);
            user = temporal;
            (*numero_usuarios)--;
            sobreescribir_fichero(user, numero_usuarios);

            printf("Usuario con ID %d eliminado correctamente.\n", id_usuario);
        }
    }

    if (encontrado == 0) {
        printf("Usuario con ID %d no encontrado.\n", id_usuario);
    }

    return user;
}

usuario *ordenar_usuarios(usuario *user, int numero_usuarios){
    for (int i = 0; i < numero_usuarios - 1; i++) {
        for (int j = i + 1; j < numero_usuarios; j++) {
            if (user[i].Id_usuario > user[j].Id_usuario) {

                usuario temp = user[i];
                user[i] = user[j];
                user[j] = temp;

            }
        }
    }
    return user;
}

int generar_id_usuarios(usuario *user, int *numero_usuarios){

    int i, comp = 1, salida, encontrado = 0;

    do{
        salida = 0;
        for(i = 0; i < *numero_usuarios && salida == 0; i++){
            if(comp == user[i].Id_usuario) {
                salida = 1;
                comp++;
            }
        }
        if(salida == 0) encontrado = 1;

    }while(i < *numero_usuarios && encontrado == 0);

    return comp;
}