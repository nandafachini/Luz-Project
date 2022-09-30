#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#ifndef tools
#define tools

// bloco de gerar números aleatórios

int* generateRandomList(int TAM) {

    static int result[] = {}; //alocada estaticamente

    printf("Sua lista desordenada é: ");

    for(int i=0; i < TAM; i++) {
        result[i] = rand() % TAM;
        printf("%2d", result[i]);
    }

    return result; //estava alocado na minha stack, ideal seria alocar dinamicamente
}

// função para descobrir o tamanho da minha lista

int lengthArray(int lista[]) {

    size_t length = sizeof(*lista)/sizeof(lista[0]); 
    return length;

}

// função para printar os elementos da minha lista

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


//bloco do Bubble Sort

void bubbleSort(int lista[], int length) {

    printf("Começando o Bubble Sort...\n");

    for(int cont = 1; cont < length; cont++) {

        for(int i = 0; i < length - cont; i++) {

        if(lista[i] > lista[i+1]){
            int aux = lista[i];
            lista[i] = lista[i+1];
            lista[i+1] = aux;
            }
        }
    }
    
    printf("Parabéns! Você ordenou sua lista usando Bubble Sort!\nLista ordenada: ");
    
    printArray(lista, length);

    printf("\nBubble Sort finalizado!");

}


// bloco do Insertion Sort

void insertionSort(int lista[], int length) {

    int i;

    printf("Começando o Insertion Sort..\n");


    for(int cont = 1; cont < length; cont++) {
        int aux = lista[cont];

        for(i = cont - 1; i >= 0 && aux < lista[i]; i--) {
            lista[i+1] = lista[i];
        }

        lista[i +1] = aux;
    }
    printf("Parabéns! Você ordenou sua lista usando Insertion Sort!\nLista ordenada: ");
    
    printArray(lista, length);

    printf("\nInsertion Sort finalizado!");
} 


// bloco do Seletion Sort

void selectionSort(int lista[], int length) {

    printf("Começando o Selection Sort..\n");

    for(int aux = 0; aux < length; aux++) {
        int menor = aux;

        for(int temp = aux + 1; temp < length; temp++) {

            if(lista[temp] < lista[menor]) {
                menor = temp;
            }
        }
        if(menor != aux) {
            int troca = lista[aux];
            lista[aux] = lista[menor];
            lista[menor] = troca;
        }
    } 
    printf("Parabéns! Você ordenou sua lista usando Selection Sort!\nLista ordenada: ");

    printArray(lista, length);

    printf("\nSelection Sort finalizado!");

}


// bloco do Merge

void merge(int lista[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) {
        L[i] = lista[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = lista[m + 1 + j];
    }
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            lista[k] = L[i];
            i++;
        } else {
            lista[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        lista[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        lista[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */


// bloco do Merge Sort

void mergeSort(int lista[], int l, int r) {

    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(lista, l, m);
        mergeSort(lista, m + 1, r);
 
        merge(lista, l, m, r);
        
        int length;

        length = lengthArray(lista);

        printf("Parabéns! Você ordenou sua lista usando Merge Sort!\nLista ordenada: ");

        printArray(lista, length);

        printf("\nSelection Sort finalizado!");

    }
}


// bloco do Quick Sort

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int lista[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = lista[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (lista[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&lista[i], &lista[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&lista[i + 1], &lista[high]);
  
  // return the partition point
  return (i + 1);
}


void quickSort(int lista[], int low, int high) {

    if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(lista, low, high);
    
    // recursive call on the left of pivot
    quickSort(lista, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(lista, pi + 1, high);

    int length;

    length = lengthArray(lista);

    printf("Parabéns! Você ordenou sua lista usando Merge Sort!\nLista ordenada: ");

    printArray(lista, length);

    printf("\nSelection Sort finalizado!");

  }
}

#endif
