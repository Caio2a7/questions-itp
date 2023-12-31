#include <stdio.h>

int divisores(int numero) {
    int divisores = 0;
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) {
            divisores = divisores + i;
        }
    }
    return divisores;
}

void intervalo(int numero_1, int numero_2, int contador) {
    int sem_amigos = 0;
    int caso_especial = 0;
    int numero;
    for (int i = numero_1; i <= numero_2; i++) {
        for (int j = i + 1; j <= numero_2; j++) {
            if (contador == 1 && divisores(i) == j && divisores(j) == i) {
                numero = j;
                caso_especial++;
                sem_amigos++;
            }
            else if (divisores(i) == j && divisores(j) == i) {
                printf("O %d possui um amigo!\n", i);
                sem_amigos++;
            }
        }   
    }
    if (caso_especial > 0) {
        printf("O %d possui um amigo!\n", numero);
    }
    if (sem_amigos == 0 && contador == 0) {
        printf("Os intervalos nao apresentam amigos!");
    }
}

int main() {
    int num1, num2, num3, num4;
    printf("");
    scanf("%d %d", &num1, &num2);
    printf("");
    scanf("%d %d", &num3, &num4);

    intervalo(num1, num2, 0);
    intervalo(num3, num4, 1);

    return 0;
}