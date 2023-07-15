/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Darc
 *
 * Created on January 19, 2018, 4:26 PM
 */

#include <stdio.h>
#include <stdlib.h>

void someFunction(int arg)
{
    printf("This is someFunction being called and arg is: %d\n", arg);
    printf("Whoops leaving the function now!\n");
}

void f1(int var) {
    printf("this is f1 and var is: %d\n", var);
}

void f2(int var) {
    printf("this is f2 and var is: %d\n", var);
}

void f3(int var) {
    printf("this is f3 and var is: %d\n", var);
}

int main() {
    //UNIONS (allows for multiples names to the same variable)

    union hiddenMessage {
        int ints[6];
        char chars[21];
    };
    
    union hiddenMessage intCharacters = {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};

    printf("[");
    // only go to 18 because 1 byte is for the terminating 0 and we don't print the last in the loop
    for (int i = 0; i < 19; ++i)
        printf("%c, ", intCharacters.chars[i]); //cada numero tiene 4 bytes, los primeros 5 numeros son 20 bytes 
    printf("%c]\n", intCharacters.chars[19]);//el ultimo byte representa: !]
    printf("%s\n", intCharacters.chars);
    
    //POINTER ARITHMETICS (++: increment(siguiente), --: decrement(anterior), -: subtract pointers(anterior x un valor), +:add pointers(siguiente x un valor))
    
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[2]; //point to the 3th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 3th element

    intpointer++; //now increase the pointer's address so it points to the 4th elemnt in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 4th element
    

    intpointer--; //now decrease the point's address so it points to the 3th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 3th element
        

    intpointer += 2; //now shift by two the point's address so it points to the 5th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element
    
    intpointer -= 2; //now shift by two the point's address so it points to the 3rd element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 3rd element
    
    //FUNCTION POINTERS
    
    void (*pf)(int); //declaracion del puntero a la funcion
    pf = &someFunction;//asigna la funcion
    (pf)(5);//llama la funcion
    
    void (*pfv[])(int) = {f1, f2, f3};//vector de punteros

    int c = 0;
    while (c < 3) {
        pfv[c](c);
        ++c;
    }

    return 0;
}

