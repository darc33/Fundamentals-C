/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Darc
 *
 * Created on January 19, 2018, 12:25 PM
 */

#include <stdio.h>
#include <stdlib.h>


int main() {
    //POINTERS (Integer variable which holds a memory address that points to a value )
    int a = 1;

    /* define a pointer variable, and point it to a using the & operator */
    int * pointer_to_a = &a;

    printf("The value a is %d\n", a);
    printf("The value of a is also %d\n", *pointer_to_a);
    
    a += 1;

    /* we just changed the variable again! */
    *pointer_to_a += 1;

    /* will print out 3 */
    printf("The value of a is now %d\n", a);
    
    //STRUCTURES (large variables which contain several named variables inside)
    struct point {
        int x;
        int y;
    };
    
    struct point p; //crea una variable de una estructura
    p.x = 10;
    p.y = 5;
    
    //TYPEDEF (define types with different name)

    typedef struct {
        char * brand;
        int model;
    } vehicle;
    
    vehicle mycar;
    mycar.brand = "Ford";
    mycar.model = 2007;
    
    //DYNAMIC ALLOCATION
    
    typedef struct {
        char * name;
        int age;
    } person;
    
    person * myperson = malloc(sizeof(person)); //dynamic allocate (crea puntero del tamaño requerido para la estructura persona)
    
    myperson->name = "John"; //accesa a los miembros de persona
    myperson->age = 27;
    
    free(myperson); // libera la memoria que estaba usando myperson, pero no borra el puntero, simplemente la info que contenia
    
    //ARRAYS, POINTERS AND DINAMIC ALLOCATION
    
    int nrows = 2;
    int ncols = 5;
    int i, j;

    // Allocate memory for nrows pointers
    char **pvowels = (char **) malloc(nrows * sizeof (char *));//Crea un vector vacio con el numero de filas requeridas 

    // For each row, allocate memory for ncols elements
    pvowels[0] = (char *) malloc(ncols * sizeof (char));//Crea ahora una matriz vacia con el numero de columnas requeridas para cada fila
    pvowels[1] = (char *) malloc(ncols * sizeof (char));

    pvowels[0][0] = 'A';
    pvowels[0][1] = 'E';
    pvowels[0][2] = 'I';
    pvowels[0][3] = 'O';
    pvowels[0][4] = 'U';

    pvowels[1][0] = 'a';
    pvowels[1][1] = 'e';
    pvowels[1][2] = 'i';
    pvowels[1][3] = 'o';
    pvowels[1][4] = 'u';

    for (i = 0; i < nrows; i++) {
        for (j = 0; j < ncols; j++) {
            printf("%c ", pvowels[i][j]);
        }

        printf("\n");
    }

    // Free individual rows
    free(pvowels[0]);
    free(pvowels[1]);

    // Free the top-level pointer
    free(pvowels);
    
    
    return 0;
}

