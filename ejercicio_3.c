#include <stdio.h>

void enteroABinario(int n, char *cadena) {
    for (int i = 31; i >= 0; i--) {
        *(cadena + (31 - i)) = (n >> i & 1) ? '1' : '0';
    }
    *(cadena + 32) = '\0';
}

int main() {
    int num, unos = 0;
    char bin[33], *p = bin;
    
    printf("Ingresa un entero positivo: ");
    scanf("%d", &num);
    enteroABinario(num, bin);
    printf("Binario: %s\n", bin);

    while(*p != '\0'){
        if(*p == '1'){
            unos++;
        }
        p++;
    }

    printf("Total de bits '1': %d\n", unos);
    return 0;
}

// PREGUNTA: En la función enteroABinario, estamos pasando un int (4 bytes) y un apuntador char *. 
// Si un int ya vive en la memoria como una secuencia de bits, 
// ¿por qué es necesario 'convertirlo' a una cadena de caracteres para contarlos con el apuntador?

/*
En realidad no es necesario convertir el número en una cadena para determinar la cantidad de '1'.

El número ya tiene un espacio en la memoria formado por su composición binaria ('1' y '0')
y este puede ser interpretado por operadores bitwise como "AND (&)" que directamente puede evaluar a un bit ('0' o '1'), y saber si es igual a 1;
y el operador "desplazamiento (>>)" que nos permite desplazar el bit evaluado para así llevar a cabo el análisis de todos los bits, 
así como fue empleado en la función enteroABinario. 

Transformarlo en una cadena únicamente sirve para permitirnos visualizar la cadena y facilitar la lectura e interpretación humana.
*/
