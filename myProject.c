#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "tools.h"
#define TAM 10


int main(){

    int *unsortedList = generateRandomList(TAM);

    printf("\nEscolha uma das opções de ordenação abaixo: \n");
    printf("\nDigite 1 para Bubble Sort");
    printf("\nDigite 2 para Insertion Sort");
    printf("\nDigite 3 para Selection Sort");
    printf("\nDigite 4 para Merge Sort");
    printf("\nDigite 5 para Quick Sort\n");
    printf("\nSua escolha é: ");


    int selecao = scanf("%d", &selecao);

    switch (selecao) {
    case 1:
        bubbleSort(unsortedList, TAM);
        break;
    case 2:
        insertionSort(unsortedList, TAM);
        break;
    case 3:
        selectionSort(unsortedList, TAM);
        break;
    case 4:
        mergeSort(unsortedList, 0, TAM);
        break;
    case 5:
        quickSort(unsortedList, 0, TAM);
        break;
    default:
        printf("Você deve escolher entre as opções 1 e 5!");
        break;
    }
    
}
