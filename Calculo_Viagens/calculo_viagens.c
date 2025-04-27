#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// Funcao que calcula o total de combustivel usado na viagem
float Calc_Combustivel(float kml, float dist) {
	float lt;
	// Calcula o total de combustivel dividindo a distancia pela autonomia do carro
	lt = dist/kml;
	return lt;
}

// Funcao que calcula a distancia percorrida na viagem
float Calc_Distancia(float kmh, float t) {
	float dist;
	// Calcula a distancia multiplicando a velocidade do carro pelo tempo
 	dist = kmh*t;
 	return dist;
}

// Funcao que calcula a velocidade media da viagem
float Calc_Km_Hr(float dist, float t) {
	float kmh;
	// Calcula a velocidade dividindo a distancia pelo tempo
	kmh = dist/t;
	return kmh;
}

// Funcao que calcula o tempo gasto na viagem
float Calc_Tempo(float dist, float kmh) {
	float t;
	// Calcula o tempo dividindo a distancia pela velocidade
	t = dist/kmh;
	return t;
}

// Algoritmo principal
int main() {
 	// Variaveis usadas no programa
 	float km_h, t, dist, km_l, l_total;
 	int op;
 	
 	// Looping que vai executar o codigo ate que a opcao 0 seja selecionada
 	do {
 		// Limpa a tela e exibe as opcoes disponiveis
 		system("cls");
 		printf("\n---------+ Calculo de Viagens +---------\n");
	 	printf("\n1- Descobrir Distancia percorrida");
	 	printf("\n2- Descobrir Velocidade media");
	 	printf("\n3- Descobrir Tempo gasto");
	 	printf("\n4- Guia de uso");
	 	printf("\n0- Sair do programa");
	 	
		printf("\n\nDigite a opcao: ");
	 	scanf("%d", &op);
	 	
		// Se opcao digitada for igual a 0, encerra o programa
	 	if(op == 0) {
	 		break;
		}
		// Se opcao for diferente das registradas, pede um valor valido
		else if(op > 4) {
	 		printf("\nDigite um valor valido!\n\n");
	 		system("pause");
			return main();
		}
		// Se opcao digitada for igual a 4, limpa a tela para o guia de uso
		else if(op == 4) {
			system("cls");
		}
		// Caso seja uma opcao valida, pergunta qual a autonomia do veiculo
		else {
			printf("\nQuantos km o veiculo anda por litro de combustivel? ");
			scanf("%f", &km_l);
		}
		
		// Dependendo de qual opcao for escolhida, executa um codigo diferente 	
	 	switch(op) {
	 		
	 		// Caso que calcula a distancia percorrida
	 		case 1:
				printf("Qual a velocidade media durante a viagem? ");
			 		scanf("%f", &km_h);
			 	printf("Qual o tempo em horas gasto na viagem? ");
			 		scanf("%f", &t);
			 	
			 	dist = Calc_Distancia(km_h, t);
			 				 	
				printf("\n+-+-+-+-+-+-+-+-+\n");
				printf("\nDistancia percorrida: %.2fkm\n", dist);
				break;
		
			// Caso que calcula a velocidade media da viagem
			case 2:
				printf("Qual a distancia percorrida? ");
			 		scanf("%f", &dist);
			 	printf("Qual o tempo em horas gasto na viagem? ");
			 		scanf("%f", &t);
			 		
			 	km_h = Calc_Km_Hr(dist, t);
		 		
		 		printf("\n+-+-+-+-+-+-+-+-+\n");
		 		printf("\nVelocidade media: %.2f km/h\n", km_h);
				break;
			
			// Caso que calcula o tempo gasto na viagem
			case 3:
				printf("Qual a distancia percorrida? ");
			 		scanf("%f", &dist);
			 	printf("Qual a velocidade media durante a viagem? ");
			 		scanf("%f", &km_h);
			 	
			 	t = Calc_Tempo(dist, km_h);
		 		
		 		printf("\n+-+-+-+-+-+-+-+-+\n");
		 		printf("\nTempo gasto: %.2f hrs\n", t);
		 		break;
		 		
		 	// Caso que exibe o passo a passo de como usar o programa
		 	case 4:
		 		// Titulo
		 		printf("\n---------+ Guia de Uso +---------\n");
		 		// 1o passo
		 		printf("\n\n1o Passo: Escolher uma das 3 opcoes listadas. Para cada opcao, serao solicitadas diferentes informacoes:\n\n");
		 		printf("- Distancia percorrida: Utiliza a velocidade media e o tempo gasto para encontrar o valor.\n");
		 		printf("- Velocidade media: Utiliza a distancia percorrida e o tempo gasto para encontrar o valor.\n");
		 		printf("- Tempo gasto: Utiliza a distancia percorrida e a velocidade media para encontrar o valor.\n\n");
		 		// 2o passo
		 		printf("\n2o Passo: Informar quantos quilometros o veiculo roda por  litro de combustivel.\n");
		 		printf("**O programa tambem calcula o total de combustivel gasto na viagem**\n");
		 		// 3o passo e encerramento
				printf("\n3o Passo: Preencher as informacoes solicitadas.\n");
				printf("**Caso queira digitar minutos, basta escrever '0.' e os minutos. Ex: 20min sao 0.20**\n");
		 		printf("\nApos informar todos os dados, o sistema realizara automaticamente os calculos e retornara o resultado.\n\n\n\n");
		 		
		 		// Volta para a tela inicial
				system("pause");
		 		return main();
		 		break;
		}
		
		// Exibe o o total de combustivel utilizado na viagem e pausa a tela
		l_total = Calc_Combustivel(km_l, dist);
		printf("Total combustivel usado: %.2fL\n\n", l_total);
		system("pause");
		
	}while(op != 0);
	return 0;
}
