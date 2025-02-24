#include <stdio.h>
#include <unistd.h>

#define VERDE 12
#define AMARELO 3
#define VERMELHO 15

unsigned int estado_atual = VERMELHO;

int main (void){
	for(;;){
		switch(estado_atual)
		{
			case VERMELHO:
				printf("Vermelho\n");
				sleep(VERMELHO);
				estado_atual = VERDE;
				break;
			case VERDE:
				printf("Verde\n");
				sleep(VERDE);
				estado_atual = AMARELO;
				break;
			case AMARELO:
				printf("Amarelo\n");
				sleep(AMARELO);
				estado_atual = VERMELHO;
				break;
			default:
				printf("Algo de errado nao esta certo\n");
				break;
		}
	}
}
