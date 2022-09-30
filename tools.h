#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#ifndef tools
#define tools


// bloco de gerar números aleatórios

int* generateRandomList(int TAM) {

    static int result[] = {}; 

    printf("Sua lista desordenada é: ");

    for(int i=0; i < TAM; i++) {
        result[i] = rand() % TAM;
        printf("%2d", result[i]);
    }

    return result; 

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

// bloco print do bublle

void bubble(void){

    printf("Parabéns! Você ordenou sua lista usando Bubble Sort!\nLista ordenada: ");

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

    bubble();

    printArray(lista, length);

}


// bloco print do insertion

void insertion(void){

    printf("Parabéns! Você ordenou sua lista usando Insertion Sort!\nLista ordenada: ");

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
    
    insertion();

    printArray(lista, length);

} 


// bloco do print do selection

void selection(void){

    printf("Parabéns! Você ordenou sua lista usando Selection Sort!\nLista ordenada: ");

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

    insertion();
    
    printArray(lista, length);

}

// bloco do print do merge
void printMerge(void){

    printf("Parabéns! Você ordenou sua lista usando Merge Sort!\nLista ordenada: ");

}

// bloco do Merge

// Merge two subarrays L and M into arr
void merge(int lista[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = lista[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = lista[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      lista[k] = L[i];
      i++;
    } else {
      lista[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    lista[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    lista[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int lista[], int l, int r) {

  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(lista, l, m);
    mergeSort(lista, m + 1, r);

    // Merge the sorted subarrays
    merge(lista, l, m, r);
  }

}


// bloco do print do quick sort

void quick(void){

  printf("Parabéns! Você ordenou sua lista usando Quick Sort!\nLista ordenada: ");

}


// bloco do Quick Sort

// função para trocar elementos
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

    quick();

    printArray(lista, length);

  }
}

#endif
