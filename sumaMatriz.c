#include <stdlib.h>
#include <stdio.h>

//prototipos de funciones
float** crear_matriz(int m,int n);
void liberar_matriz(float **p, int m);
void leer_matriz(float **p,int m, int n);
float** sumar_matriz(float **a, float **b,int m, int n);
void imprimir_matriz(float **matriz,int m,int n);
int main(){
    float **matrizA = NULL, **matrizB = NULL;
    float **matrizC = NULL;

    //dimensiones de las matrices
    int mA, nA, mB, nB;

    printf("Ingrese el numero de renglones y columnas de la primera matriz: \n");
    scanf("%d %d", &mA,&nA);
    printf("Ingrese el numero de renglones y columnas de la segunda matriz: \n");
    scanf("%d %d", &mB,&nB);

    //para poder sumar matrices deben tener las mismas dimensiones
    if(mA == mB && nA == nB){
        matrizA = crear_matriz(mA,nA);
        leer_matriz(matrizA, mA,nA);

        matrizB = crear_matriz(mB,nB);
        leer_matriz(matrizB,mB,nB);

        matrizC = sumar_matriz(matrizA,matrizB,mA,nA);
        imprimir_matriz(matrizC, mA,nA);

        liberar_matriz(matrizA,mA);
        liberar_matriz(matrizB,mB);
        liberar_matriz(matrizC,mA);
    }else{
        printf("\nLas matrices no se pueden sumar porque no tienen las mismas dimensiones.");
    }
}

/*  Función que reserva memoria para un doble apuntador
    @param m numero de renglones
    @param n numero de renglones
    @return matriz apuntador recien creado
*/
float** crear_matriz(int m,int n){
    float **matriz = (float**) malloc(m*sizeof(float*));
    for(int i = 0; i < m; i++){
        matriz[i] = (float *) malloc(n*sizeof(float*));
    }
    return matriz;
}

/*
    Función que libera la memoria tomada en matriz
    * @param matriz es la matriz creada en el problema
    * @param m es el numero de renglones
    * @return la matriz liberada de memoria
*/
void liberar_matriz(float **matriz, int m){
    //la memoria se libera de manera inversa de como se reserva
    for(int i = 0; i < m;i++){
        free(matriz[i]); 
    }
    free(matriz); //liberar apuntador principal
    matriz = NULL; //"para no conservar basura"
}

/*
    Función para pedirle al usuario los valores de matriz
    *@param **p 
    *@param m es el numero de renglones
    *@param n es el numero de columnas
*/
void leer_matriz(float **p, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n ;j++){
            printf("Ingresa el valor del elemento(%d,%d): \n",i+1,j+1);
            scanf("%f",&p[i][j]);
        }
    }
}
/*
    Función imprimir la matriz
    *@param **matriz es la matriz en cuestion 
    *@param m es el numero de renglones
    *@param n es el numero de columnas
*/
void imprimir_matriz(float **matriz,int m,int n){
    for(int i = 0; i < m; i++){
        printf("/ ");
        for(int j = 0; j < n ;j++){
            printf("%f ",matriz[i][j]);
        }
        printf("/\n");
    }
}

/*
    Función sumar matrizA y matrizB
    *@param **a es la matrizA
    *@param **b es la matrizB 
    *@param m es el numero de renglones
    *@param n es el numero de columnas
    *@return la matrizC
*/
float** sumar_matriz(float **a, float **b,int m, int n){
    float **matriz = crear_matriz(m,n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n ;j++){
            matriz[i][j] = a[i][j] + b[i][j];
        }
    }
    return matriz;
}