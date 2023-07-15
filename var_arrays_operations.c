/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Darc
 *
 * Created on January 18, 2018, 12:00 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //HOLA MUNDO
    printf("Hola mundo!\n");

// DEFINICION DE TIPO BOOLEANO   
#define BOOL char
#define True 1
#define False 0
    
    //DEFINICION DE ENTEROS
    int num; // variable sin inicializar
    int n = 1; // variable inicializada
    int a = 0,b = 1,c = 2,d = 3, e = 4; // definir varias variables
    
    //OPERACIONES
    a = b - c + d * e; 
    printf("%d\n", a); 
    
    //ARRAYS
    int numbers[10]; //arreglo de 10 enteros
    numbers[0] = 10; //agregar valores al arreglo
    numbers[1] = 20; //solo pueden tener un tipo de variable
    numbers[2] = 30;
    
    //MULTIDIMENSIONAL ARRAYS
    int mult_arr[3][4] = { 
        {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
        {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
        {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
    };
    int arra_m[2][3];
    int val = arra_m[2][3]; //asignar un arreglo a una variable
    
    //STRINGS
    char * name = "John Smith"; // Only read string
    char name2[] = "John Smith2"; // String which can be manipulated
    int len = strlen(name);//longitud de un string
    
    printf("%s len is %d.\n", name, len); //Imprimir un string
    
    if (strncmp(name, "John", 4) == 0) { //compara dos strings para una longitud dada
        printf("Hello, John!\n");
    } else {
        printf("You are not John. Go away.\n");
    }
    char dest[20] = "Hello";
    char src[20] = "World";
    strncat(dest, src, 3); //concatena dos strings, str destino, str fuente, longitud de str fuente
    printf("%s\n", dest);
    

    return 0;
}

