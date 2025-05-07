#include <stdio.h>
#include <stdlib.h>


void print_even(int user_num) {
    for (int i = 1; i <= user_num; i++){
        if (i % 2 == 0){
            printf("%d\n", i);
        }
    }
}

int main(){

    //Write a Program that output information about myself. This is just to get started writing c code.
    char name[] = "Gabriel";
    int age = 25;
    float height = 5.9;

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);


    //Ask the user to input a number and in the output tell the user if the number is positive, negative or zero. 
    int number;
    // First check if the user enters invalid input in a while loop.
    while (1) {
        printf("Write an integer and i tell you what kind of integer it is: ");
        if (scanf("%d", &number) == 1) break;
        printf("Invalid input!. Please enter a valid integer.\n");
        while (getchar() != '\n'); //clean the buffer.

    }

    if (number > 0){
        printf("Number is positive.\n");
    } else if (number < 0) {
        printf("The number is negative.\n");
    } else {
        printf("The number is zero.\n");
    }

    //Write a program that outputs all even numbers between 1 and a number that the user selects.

    int max;
    //first check if any invalid inputs are made from the user.
    while(1) {
        printf("Please enter a number: ");
        if (scanf("%d", &max) == 1) break;
        printf("Invalid input! Please enter a valid integer.\n");
        while (getchar() != '\n'); //clean the buffer

    }

    print_even(max);

    return 0;
}