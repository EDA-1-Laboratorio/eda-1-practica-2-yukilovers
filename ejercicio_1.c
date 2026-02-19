/*Ejercicio 1. El "espejo" de memoria.

El ejercicio consiste en completar la función invertirCadena para que invierta el orden 
de los caracteres de una palabra utilizando exclusivamente apuntadores. No se permite 
el uso de índices del arreglo de entrada.
*/

#include <stdio.h>

void invertirCadena(char *inicio) {
    char *fin = inicio;
    char aux;
    // 1. Mover 'fin' al último carácter antes del '\0'
    while (*fin != '\0') {
        fin++;
    }
    fin--; 

    // 2. Intercambio de valores
    while (*inicio != *fin) {
        // Guardamos el carácter de la izquierda en la caja temporal
        aux = *inicio; 
        
        // Ponemos el carácter de la derecha en la posición de la izquierda
        *inicio = *fin; 
        
        // Ponemos lo que estaba en la izquierda (guardado en aux) en la derecha
        *fin = aux; 

        // Desplaza los apuntadores: el inicio sube, el fin baja
        inicio++; 
        fin--;
    }
}

int main() {
    char palabra[100];
    printf("Digita la palabra que deseas invertir: ");
    scanf("%s",palabra);
    int lon=strlen(palabra);

    printf("Original: %s\n", palabra);
    invertirCadena(palabra);
    printf("Invertida: %s\n", palabra);
    return 0;
}

/*Durante el ciclo de intercambio (swap), la condición de parada es while (inicio < fin). 
Explica detalladamente qué es lo que se está comparando físicamente en esa instrucción 
(¿valores o direcciones?)

Se están comparando direcciones de memoria, la condición verifica que el apuntador inicio 
todavía se encuentre en una posición previa al apuntador fin, como inicio aumenta y 
fin disminuye en cada paso, el ciclo se detiene cuando los apuntadores se encuentran 
en el centro de la palabra o se cruzan. Si no tuviéramos esta condición, los 
apuntadores seguirían de largo y volverían a invertir lo que ya estaba invertido
o accederían a memoria que no les pertenece."

 y qué sucedería si la condición fuera while (*inicio != *fin).

Lo que haria seria que en lugar de comparar las direcciones de memoria compararía
letra por letra 

lo que hay ocasiones en las que esta funcionaría pero si en la palabra hay letras
que se repiten, al estar comparndo las letras y no sus direcciones abria veces en las
que no se realiza un cambio ya que el bucle acabaria antes de tiempo.

 */
//Durante el ciclo de intercambio (swap), la condición de parada es while (inicio < fin). 
//Explica detalladamente qué es lo que se está comparando físicamente en esa instrucción (¿valores o direcciones?) 
// y qué sucedería si la condición fuera while (*inicio != *fin).
