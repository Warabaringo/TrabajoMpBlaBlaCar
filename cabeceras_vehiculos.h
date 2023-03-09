typedef struct{
	char matric_veh[8];
	char id_usu[5];
	char num_plazas[2];
	char descrip_veh[51];
}alum;

void menu(int *x);
alum *cargar(unsigned *nalumnos);
void lista_alumnos();
void cambio(char aux[130]);
void add();
void crear_fichero();
//void intercambio(alum *a, alum *b, int i)
