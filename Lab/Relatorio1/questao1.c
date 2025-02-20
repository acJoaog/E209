#include <stdio.h>

int main()
{
    int x;
    
    scanf("%d", &x);
    
    if(x>11){
        printf("Preco da unidade: R$0.65\n");
        printf("Preco total: R$%.2f\n", x * 0.65);
    }
        
    else{
        printf("Preco da unidade: R$0.80\n");
        printf("Preco total: R$%.2f\n", x * 0.80);
    }
        
    return 0;
}