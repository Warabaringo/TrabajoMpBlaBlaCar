//
// Created by crist on 11/03/2023.
//

#ifndef UTILIDADES_H
#define UTILIDADES_H

//Precondición: i es el número de identificador y num_car es el número de carácteres de la cadena
//Postcondición: Devuelve el identificador en forma de cadena
char *crear_identificador (int i, int num_car);

//Precondición: Ninguna
//Postcondición: Devuelve el número de digitos de n
int num_digitos(int n);

//Precondición: Ninguna
//Postcondición: Quita el salto de la cadena s
void quitar_salto(char *s);

#endif //UTILIDADES_H
