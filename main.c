#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void recorrerArray(int array[],int v, int i);
void recorrerArrayInverso(int array[], int v, int i);
int arregloCapicua(int array[],int i, int v);
void mostrarArreglo (int arreglo[], int v, int i);
int sumaRecursiva(int arreglo[], int v, int i);
int buscarMenorRecursivoDesordenado(int arreglo [], int v, int i );
void agregarAlfinalDelArchivo (char archivo[]);
int buscarMenorArchivo(FILE *archi);

int main()
{
    /**printf("Hello world!\n");
    printf("\n el factorial de 5 es : %i", facotrial(5));
    printf("\nel resultado de 2 a la 2 es: %i", potencia(2,2));**/

    int arreglo [] = {16,32,64,128};
    int capicua [] = {1,2,2,1};
    int arrSuma [] = {2,2,4,6};
    int arrDesordenado [] = {2,3,4,5,6,7};
    int validos = 6;
    int i = 0;
    int rta = 0;
    int menor  = 0;
    srand(time(NULL));

    /**printf("\n punto 3: ");
    recorrerArray(arreglo, validos, i );
    printf("\n punto 3 bis: ");
    recorrerArrayInverso( arreglo, validos, i);
    printf("\n punto 4:");
    rta = arregloCapicua( capicua,0, 4);
    printf("%i", rta);

    mostrarArreglo(arreglo,validos,i);

    rta = sumaRecursiva(arrSuma, validos, i);
    printf("%i",rta);

    printf("%i", buscarMenorRecursivoDesordenado(arrDesordenado, validos, i));**/

    FILE *archi = fopen(" archivoRecursividad.dat", "rb");
    agregarAlfinalDelArchivo("archivoRecursividad.dat");

    menor = buscarMenorArchivo(archi);
    printf("%i", menor);


    return 0;
}

/// mostrar un arreglo tanto al derecho como al reves.

void mostrarArreglo (int arreglo[], int v, int i){

    if(i < v){

        printf("|%i|", arreglo[i]);
        mostrarArreglo(arreglo,v, i + 1);
        printf("|%i|", arreglo[i]);

    }

}


/// 1. Calcular el factorial de un número en forma recursiva.
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


/// 2. Calcular la potencia de un número en forma recursiva.
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

/// forma corta de hacer el ejercicio

int potencia2 (int x, int y){
    int rta = 1;

    if (y == 0){
        rta = x * potencia2(x, y -1);
    }
    return rta;
}

/// 3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.

void recorrerArray(int array[],int v, int i){


    if(i < v){
        printf("\n %i", array[i]);
        recorrerArray(array, v, i +1);
    }

}

/// 4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo).

void recorrerArrayInverso(int array[], int v, int i){

    if(i < v){

        recorrerArrayInverso(array, v, i + 1);
        printf("\n %i", array[i]);
    }

}

/// 5. Determinar en forma recursiva si un arreglo es capicúa.

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

/// 6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.

int sumaRecursiva(int arreglo[], int v, int i){

    int rta = 0;

    if(i < v){

        rta =  arreglo[i] + sumaRecursiva(arreglo, v, i +1);
        sumaRecursiva(arreglo, v, i +1);


    }
    return rta;
}

/// 7. Buscar el menor elemento de un arreglo en forma recursiva. (Tener en cuenta para un arreglo desordenado y el caso para un arreglo ordenado)

int buscarMenorRecursivoDesordenado(int arreglo [], int v, int i ){

    int menor;

    if( i < v){

        menor = buscarMenorRecursivoDesordenado(arreglo, v, i + 1);

        if(arreglo[i] < menor){
            menor = arreglo[i];
        }
        return menor;
    }

}

/// 8. Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)


int buscarMenorArchivo(FILE *archi){

    int menor;
    int dato;

    if(fread(&menor, sizeof(int), 1, archi) == 0){

        fseek(archi, sizeof(int) * (-1),SEEK_END);
        fread(&menor,sizeof(int), 1, archi);

    }
    else{
        dato = buscarMenorArchivo(archi);
        if(dato < menor){
            menor = dato;
        }
    }

    return menor;
}

void agregarAlfinalDelArchivo (char archivo[])
{
    FILE *archi = fopen(archivo, "wb");

    if(archi){

        for(int i = 0; i < 10; i ++){
            int elemento = rand()%10;
            fwrite(&elemento, sizeof(int), 1, archi);
        }
    }
      fclose(archi);

}


