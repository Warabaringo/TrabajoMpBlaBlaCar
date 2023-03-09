typedef struct{
    char matric_veh[8];
    char id_usu[5];
    char num_plazas[2];
    char descrip_veh[51];
}alum;

void menu_veh(int *x);
vehi *cargar_veh(unsigned *nvehiculos);
void lista_vehiculos();
void cambio_veh(char aux[130]);
void add_veh();
void crear_fichero_veh();