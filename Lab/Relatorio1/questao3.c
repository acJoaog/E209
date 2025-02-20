#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    
    for(int i = 0; i < x; i++){
        int par = 0, imp = 0, pos = 0, neg = 0;
        
        
        for(int j = 0; j < 5; j++){
            int y;
            scanf("%d", &y);
            
            if (y%2 == 0)
                par++;
            if (y%2 != 0) 
                imp++;
            if (y >= 0)
                pos++;
            if (y <0)
                neg++;
            
        }
        
        printf("Quantidade de numeros pares: %d \n",par);
        printf("Quantidade de numeros impares: %d \n",imp);
        printf("Quantidade de numeros positivos: %d \n",pos);
        printf("Quantidade de numeros negativos: %d \n",neg);
        printf("\n");
    }
    
    return 0;
}