#include <stdio.h>

int main()
{
    int x;
    
    scanf("%d", &x);
    
    if (x<=50 && x>=0){
        for(int i = x; i > 0; i--){
            int result = x%i;
            printf("Resto da divisao de %d por %d: %d\n", x, i, result);
        }
    }else
         printf("Numero inválido\n");

    return 0;
}