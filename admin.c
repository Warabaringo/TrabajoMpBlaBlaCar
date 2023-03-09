#include "Menu.h"
#include "Viajes.h"

int main(){
	int x,n;
	Struct_Viaje *vector_viaje; 
	
	printf("Reserve memoria: ");
	scanf("\n%i",&n);
	
	vector_viaje = (Struct_Viaje *)malloc(n*sizeof(Struct_Viaje));
	if(vector_viaje == NULL)
		printf("No se ha podido reservar memoria.\n");
		
	do{
		printf("Escribe:\n");
		printf("1 para acceder a usuario.\n2 para acceder a viajes.\n3 para acceder a vehiculos.\n");
		printf("Tu respuesta es: ");
		scanf("%i",&x);
	}while(x != 1 && x != 2 && x != 3);
	
	menu(&x,n,vector_viaje);
	
	return 0;	
}
