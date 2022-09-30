#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "tools.h"
#define TAM 10


int main(){

    int *unsortedList = generateRandomList(TAM);
    int selecao;
    do{ 
        printf("\nEscolha uma das opções de ordenação abaixo: \n");
        printf("\nDigite 1 para Bubble Sort");
        printf("\nDigite 2 para Insertion Sort");
        printf("\nDigite 3 para Selection Sort");
        printf("\nDigite 4 para Merge Sort");
        printf("\nDigite 5 para Quick Sort\n");
        printf("\nDigite 0 para sair\n");
        printf("\nSua escolha é: ");

        scanf("%d", &selecao);

        switch ( selecao ) {
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
            mergeSort(unsortedList, 0, TAM-1);
            printf("Começando o Merge Sort..\n");
            printMerge();
            printArray(unsortedList, TAM);
            break;
        case 5:
            quickSort(unsortedList, 0, TAM-1);
            printf("Começando o Quick Sort..\n");
            printQuick();
            printArray(unsortedList, TAM);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Você deve escolher entre as opções 1 e 5!");
            break;
        }
    } while (selecao != 0);    

    free(unsortedList);
}
