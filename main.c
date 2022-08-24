#include <stdio.h>
#include <stdlib.h>

void recorrerArray(int array[],int v, int i);
void recorrerArrayInverso(int array[], int v, int i);
int arregloCapicua(int array[],int i, int v);
int main()
{
    printf("Hello world!\n");
    printf("\n el factorial de 5 es : %i", facotrial(5));
    printf("\nel resultado de 2 a la 2 es: %i", potencia(2,2));

    int arreglo [] = {16,32,64,128};
    int capicua [] = {1,2,2,1};
    int validos = 4;
    int i = 0;
    int rta = 0;

    printf("\n punto 3: ");
    recorrerArray(arreglo, validos, i );
    printf("\n punto 3 bis: ");
    recorrerArrayInverso( arreglo, validos, i);
    printf("\n punto 4:");
    rta = arregloCapicua( capicua,0, 4);
    printf("%i", rta);

    return 0;
}

int facotrial (int x){
    int rta;

    if(x == 0){
        rta = 1;
    }
    else{
        rta = x * facotrial(x-1);
    }

    return rta;
}


/// 2-Calcular la potencia de un número en forma recursiva

int potencia (int x, int y){

    int rta;

    if(y == 0){
        rta = 1;
    }
    else{
        rta = x * potencia(x , y -1);
    }
    return rta;
}

/// 3-Recorrer un arreglo y mostrar sus elementos en forma recursiva

void recorrerArray(int array[],int v, int i){


    if(i < v){
        printf("\n %i", array[i]);
        recorrerArray(array, v, i +1);
    }

}

/// 4-recorre el arreglo y lo muestra al reves
void recorrerArrayInverso(int array[], int v, int i){

    if(i < v){

        recorrerArrayInverso(array, v, i + 1);
        printf("\n %i", array[i]);
    }

}

/// 5- Determinar en forma recursiva si un arreglo es capicúa.

int arregloCapicua(int array[],int i, int v){

    int flag;
    if(i < v && array[i] == array[v-1]){

        arregloCapicua(array, i + 1, v - 1);
        flag = 1;
    }
    else{
        flag = 0;
    }

    return flag;
}

/// 6 - Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.



