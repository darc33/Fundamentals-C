/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Loops_functions.c
 * Author: Darc
 *
 * Created on January 19, 2018, 11:27 AM
 */

#include <stdio.h>
//#include <stdlib.h>

int foo(int bar); //DECLARACION DE FUNCION
int runner();

int main() {
    //FOR LOOPS
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    
    //WHILE LOOPS
    int n = 0;
    while (1) {
        n++;
        if (n == 10) {
            break;//interrumpe el loop
        }
    }
    
    printf("The value of foo is %d\n", foo(1)); //Llama la funcion
    printf("%d \n", runner());
    printf("%d \n", runner());
    
    

    return 0;
}

//FUNCION
int foo( int bar) {
    return bar + 1;
}

int runner()
{
    static int count = 0; //Variable estatica o global
    count++;
    return count;
}
