typedef struct{
    char matric_veh[8];
    char id_usu[5];
    char num_plazas[2];
    char descrip_veh[51];
}alum;

void menu(int *x);
vehi *cargar(unsigned *nvehiculos);
void lista_vehiculos();
void cambio(char aux[130]);
void add();
void crear_fichero();