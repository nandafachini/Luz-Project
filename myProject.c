#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int myMenu(char yourList[5][15]){
    int i;
    int entrada;

    printf("\nBem-vindo ao menu de opções de ordenação!\nEscolha dentre as opções abaixo\n");

    for(i=0; i<5; i++){
        printf("Digite %d para a opção %s\n", i+1, yourList[i]);
    }

    printf("Eu quero a opção: ");
    scanf("%d", &entrada);
    printf("Opção escolhida: %s\n", yourList[entrada-1]);
    return entrada-1; 

}

void bubbleSort(int lista[], int length){
    printf("Começando o Bubble Sort...\n");
    for(int cont = 1; cont < length; cont++){
        for(int i = 0; i < cont; i++){
        if(lista[i] > lista[i+1]){
            int aux = lista[i];
            lista[i] = lista[i+1];
            lista[i+1] = aux;
            }
        }
    }
    
    printf("Parabéns! Você ordenou sua lista usando Bubble Sort!\nLista ordenada: ");
    for(int i = 0; i < length; i++){
        printf("%2d", lista[i]);
    }
    printf("\nBubble Sort finalizado!");

}

void insertionSort(int lista[], int length){
    printf("Começando o Insertion Sort..\n");
    int i;
    for(int cont = 1; cont < length; cont++){
        int aux = lista[cont];
        for(i = cont - 1; i >= 0 && aux < lista[i]; i--){
            lista[i+1] = lista[i];
        }
        lista[i +1] = aux;
    }
    printf("Parabéns! Você ordenou sua lista usando Insertion Sort!\nLista ordenada: ");
    for(i = 0; i < length; i++){
        printf("%2d", lista[i]);
    }
    printf("\nInsertion Sort finalizado!");
} 

void selectionSort(int lista[], int length){
    printf("Começando o Selection Sort..\n");
    // int aux;
    // int menor;
    for(int aux = 0; aux < length; aux++){
        int menor = aux;
        for(int temp = aux + 1; temp < length; temp++){
            if(lista[temp] < lista[menor]){
                menor = temp;
            }
        }
        if(menor != aux){
            int troca = lista[aux];
            lista[aux] = lista[menor];
            lista[menor] = troca;
        }
    } 
    printf("Parabéns! Você ordenou sua lista usando Selection Sort!\nLista ordenada: ");
    for(int i = 0; i < length; i++){
        printf("%2d", lista[i]);
    }
    printf("\nSelection Sort finalizado!");

}

void merge(int lista[], int length){
    printf("Começando o Merge Sort..\n");
    int l = lista[0];
    // printf("%d", l);
    int r = lista[length-1];
    // printf("%d", r);
    int m = lista[length/2];
    // printf("%d", m);

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = lista[l + i];
    }    
    for (j = 0; j < n2; j++){
        R[j] = lista[m + 1 + j];
    }

    i = 0; 
    j = 0; 
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            lista[k] = L[i];
            i++;
        }
        else {
            lista[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        lista[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        lista[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int lista[], int length){
    printf("Começando o Merge Sort..\n");
    int l = lista[0];
    printf("%d", l);
    int r = lista[length-1];
    printf("%d", r);
    int m = lista[length/2];
    printf("%d", m);

    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(lista, length);
        mergeSort(lista, length);
 
        merge(lista, length);
    }

    printf("Parabéns! Você ordenou sua lista usando Merge Sort!\nLista ordenada: ");
    for(int i = 0; i < length; i++){
        printf("%2d", lista[i]);
    }
    printf("\nSelection Sort finalizado!");

}

void quickSort(int lista[], int length){
    printf("Começando o Quick Sort");
}

int* generateRandomList(int TAM){
    static int result[] = {}; //alocada estaticamente
    // int result[] = (int)malloc(TAM * sizeof(int));
    printf("Sua lista desordenada é: ");
    for(int i=0; i < TAM; i++){
        result[i] = rand() % TAM;
        printf("%2d", result[i]);
    }
    // free(result);
    // printf("%d", result);
    return result; //estava alocado na minha stack, ideal seria alocar dinamicamente
}

int main(){
    // lista de 5 posições e de no máx 15
    char optionsList[5][15] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Merge Sort", "Quick Sort"};
    // int result[] = {};
    int * numbersToSort = generateRandomList(10);

    typedef void (*f)(int[], int);    //declaro typdef - lista de funções que recebe lista de inteiros e retorna void

    f func[5] = {&bubbleSort, &insertionSort, &selectionSort, &mergeSort, &quickSort }; // inicializo minha lista de 5 posições que contém 5 funções de ordenação

    int selected = myMenu(optionsList); //aponto para a minha lista
    // printf("%d", selected); // a variável selected guarda o index da minha lista

    func[selected](numbersToSort,10);
}
