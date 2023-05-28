#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void opcao0(), opcao1(), opcao2(), imprimirExplicacao(), imprimirQuadro(), colocandoPalavras();

char quadro[10][10], palavras[7][15];
int sorteio;	

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int i = 0, j = 0, numeroLetras, erros = 0, tentativas = 0, resta = 0;
	int numeroCorretas = 0, contador = 0, todasPalavras = -1;
	char palavraDigitada[100], todasDigitadas[40][20];
	bool acertou, repetiu;
	char digitadasCertas[7][15]; 

	imprimirExplicacao();
	
	srand(time(NULL));
	for(i = 1; i <= 1; i++){
		sorteio = rand() % 3;
	}

	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			quadro[i][j] = ' ';
		} 
	}
	
	for(i = 0; i < 10; i++){ 
		for(j = 0; j < 10; j++){
			if(quadro[i][j] == ' '){
				quadro[i][j] = 'A' + (char)(rand()%26);
			} 
		}
	}
	
	while(numeroCorretas != 7){
		numeroLetras = 0;
		acertou = false;
		repetiu = false;
		
		colocandoPalavras();
		
		imprimirQuadro();
	
		printf("\nDigite a palavra encontrada: "); 
		gets(palavraDigitada);
		fflush(stdin);

		numeroLetras = strlen(palavraDigitada); 
	
		for(contador = 0; contador < numeroLetras; contador++){
			palavraDigitada[contador] = toupper(palavraDigitada[contador]);
		}
		
		for(contador = 0; contador < tentativas ; contador++){
			if(strcmp(palavraDigitada, digitadasCertas[contador]) == 0){
				repetiu = true;
			}
		}
		
		todasPalavras++;
		strcpy(todasDigitadas[todasPalavras], palavraDigitada);
		
		for(i = 0; i < 7; i++){
			if(strcmp(todasDigitadas[todasPalavras], palavras[i]) == 0){
				strcpy(digitadasCertas[numeroCorretas], palavraDigitada);
				acertou = true;
			}
		}
		system("cls");
		
		printf("\nTentativa %d", tentativas + 1);
		tentativas++;
		
		if(acertou == true ){ 
			numeroCorretas++;
			printf("\nPalavra correta!");
		}else{
			printf("\nPalavra incorreta! Tente novamente!");
			erros++;
		}

		if(repetiu == true){
			printf("\nATENÇÃO! Você digitou uma palavra repetida!");
			numeroCorretas--;
		}
		
		printf("\n---------------------------------------------------------");
		printf("\nTodas digitadas: ");
		for(i = 0; i < tentativas; i++){
			if(i % 5 == 0 && i != 0){
				printf("\n");
			}
				printf("%s ", todasDigitadas[i]);
		}
		
		printf("\n---------------------------------------------------------");
		if(numeroCorretas > 0){
			printf("\n\t\tPalavras corretas digitadas ");
			for(i = 0; i < numeroCorretas; i++){
				printf("\n%s ", digitadasCertas[i]);
			}
			printf("\n---------------------------------------------------------");
		}
		resta = 7 - numeroCorretas; 
		printf("\nQuantidade de palavras encontradas: %d", numeroCorretas);
		if(resta > 0){
			printf("\nFaltam: %d", resta);			
		}
	}
	
	printf("\n\n                         RESPOSTA                         \n");
	printf(".........................................................\n");
	for(i = 0; i < 10; i++){ 
		for(j = 0; j < 10; j++){
			quadro[i][j] = ' ';
		}
	}
	
	colocandoPalavras();
	
	imprimirQuadro();

	printf("\nPARABÉNS! Completou o caça palavras!!!");
	
	if(erros != 0){
		if(erros > 1){
			printf("\n\nVocê digitou %d palavras erradas durante o jogo!", erros);	
		}else{
			printf("\n\nVocê digitou %d palavra errada durante o jogo!", erros);	
		}
	}else{
		printf("\n\nVocê não digitou palavras erradas!!");
	}
	printf("\n---------------------------------------------------------");
}

void opcao0 (void){ //Estabelecimentos

	strcpy(palavras[0], "PADARIA");
	strcpy(palavras[1], "MERCADO");
	strcpy(palavras[2], "LIVRARIA");
	strcpy(palavras[3], "LANCHONETE");
	strcpy(palavras[4], "DROGARIA");
	strcpy(palavras[5], "BAR");
	strcpy(palavras[6], "LANHOUSE");
	
	// 1. Padaria
	quadro[3][0] = 'P';
	quadro[3][1] = 'A';
	quadro[3][2] = 'D';
	quadro[3][3] = 'A';
	quadro[3][4] = 'R';
	quadro[3][5] = 'I';
	quadro[3][6] = 'A';
	
	// 2. Mercado
	quadro[1][4] = 'M';
	quadro[2][4] = 'E';
	quadro[4][4] = 'C';
	quadro[5][4] = 'A';
	quadro[6][4] = 'D';
	quadro[7][4] = 'O';
	
	// 3. Lanhouse
	quadro[1][9] = 'L';
	quadro[2][9] = 'A';
	quadro[3][9] = 'N';
	quadro[4][9] = 'H';
	quadro[5][9] = 'O';
	quadro[6][9] = 'U';
	quadro[7][9] = 'S';
	quadro[8][9] = 'E';
	
	// 4. Livraria
	quadro[0][1] = 'L';
	quadro[1][2] = 'I';
	quadro[2][3] = 'V';
	quadro[4][5] = 'A';
	quadro[5][6] = 'R';
	quadro[6][7] = 'I';
	quadro[7][8] = 'A';
	
	// 5. Lanchonete
	quadro[9][9] = 'L';
	quadro[9][8] = 'A';
	quadro[9][7] = 'N';
	quadro[9][6] = 'C';
	quadro[9][5] = 'H';
	quadro[9][4] = 'O';
	quadro[9][3] = 'N';
	quadro[9][2] = 'E';
	quadro[9][1] = 'T';
	quadro[9][0] = 'E';
	
	// 6. Drogaria
	quadro[8][1] = 'D';
	quadro[8][2] = 'R';
	quadro[8][3] = 'O';
	quadro[8][4] = 'G';
	quadro[8][5] = 'A';
	quadro[8][6] = 'R';
	quadro[8][7] = 'I';
	quadro[8][8] = 'A';
	
	// 7. Bar
	quadro[0][7] = 'B';
	quadro[0][8] = 'A';
	quadro[0][9] = 'R';
}

void opcao1(void){ //Frutas

	strcpy(palavras[0], "ABACAXI");
	strcpy(palavras[1], "AMEIXA");
	strcpy(palavras[2], "MELANCIA");
	strcpy(palavras[3], "CARAMBOLA");
	strcpy(palavras[4], "ACEROLA");
	strcpy(palavras[5], "GOIABA");
	strcpy(palavras[6], "FRAMBOESA");
	
	// 1. Abacaxi
	quadro[1][1] = 'A';
	quadro[1][2] = 'B';
	quadro[1][3] = 'A';
	quadro[1][4] = 'C';
	quadro[1][5] = 'A';
	quadro[1][6] = 'X';
	quadro[1][7] = 'I';
	
	// 2. Ameixa
	quadro[2][5] = 'M';
	quadro[3][5] = 'E';
	quadro[4][5] = 'I';
	quadro[5][5] = 'X';
	quadro[6][5] = 'A';
	
	// 3. Melancia
	quadro[9][7] = 'M';
	quadro[7][7] = 'L';
	quadro[6][7] = 'A';
	quadro[5][7] = 'N';
	quadro[4][7] = 'C';
	quadro[3][7] = 'I';
	quadro[2][7] = 'A';
	
	// 4. Carambola
	quadro[1][4] = 'C';
	quadro[2][4] = 'A';
	quadro[3][4] = 'R';
	quadro[4][4] = 'A';
	quadro[5][4] = 'M';
	quadro[6][4] = 'B';
	quadro[7][4] = 'O';
	quadro[8][4] = 'L';
	quadro[9][4] = 'A';
	
	// 5. Acerola
	quadro[8][9] = 'A';
	quadro[8][8] = 'C';
	quadro[8][7] = 'E';
	quadro[8][6] = 'R';
	quadro[8][5] = 'O';
	quadro[8][3] = 'A';
	
	// 6. Goiaba
	quadro[6][0] = 'G';
	quadro[6][1] = 'O';
	quadro[6][2] = 'I';
	quadro[6][3] = 'A';
	
	// 7. Framboesa
	quadro[0][1] = 'F';
	quadro[0][2] = 'R';
	quadro[0][3] = 'A';
	quadro[0][4] = 'M';
	quadro[0][5] = 'B';
	quadro[0][6] = 'O';
	quadro[0][7] = 'E';
	quadro[0][8] = 'S';
	quadro[0][9] = 'A';
}

void opcao2(void){ //Países

	strcpy(palavras[0], "BRASIL");
	strcpy(palavras[1], "HOLANDA");
	strcpy(palavras[2], "ANGOLA");
	strcpy(palavras[3], "ALEMANHA");
	strcpy(palavras[4], "TAILANDIA");
	strcpy(palavras[5], "AUSTRALIA");
	strcpy(palavras[6], "CHILE");
	
	// 1. Brasil
	quadro[2][0] = 'B';
	quadro[2][1] = 'R';
	quadro[2][2] = 'A';
	quadro[2][3] = 'S';
	quadro[2][4] = 'I';
	quadro[2][5] = 'L';
	
	// 2. Holanda
	quadro[2][9] = 'H';
	quadro[3][9] = 'O';
	quadro[4][9] = 'L';
	quadro[5][9] = 'A';
	quadro[6][9] = 'N';
	quadro[7][9] = 'D';
	quadro[8][9] = 'A';
	
	// 3. Angola
	quadro[3][2] = 'N';
	quadro[4][2] = 'G';
	quadro[5][2] = 'O';
	quadro[6][2] = 'L';
	quadro[7][2] = 'A';
	
	// 4. Alemanha
	quadro[9][9] = 'A';
	quadro[9][8] = 'L';
	quadro[9][7] = 'E';
	quadro[9][6] = 'M';
	quadro[9][5] = 'A';
	quadro[9][4] = 'N';
	quadro[9][3] = 'H';
	quadro[9][2] = 'A';
	
	//5. Tailândia
	quadro[0][0] = 'T';
	quadro[0][1] = 'A';
	quadro[0][2] = 'I';
	quadro[0][3] = 'L';
	quadro[0][4] = 'A';
	quadro[0][5] = 'N';
	quadro[0][6] = 'D';
	quadro[0][7] = 'I';
	quadro[0][8] = 'A';
	
	// 6. Austrália
	quadro[1][2] = 'U';
	quadro[3][4] = 'T';
	quadro[4][5] = 'R';
	quadro[4][7] = 'A';
	quadro[5][6] = 'A';
	quadro[6][7] = 'L';
	quadro[7][8] = 'I';

	// 7. Chile
	quadro[5][0] = 'C';
	quadro[6][0] = 'H';
	quadro[7][0] = 'I';
	quadro[8][0] = 'L';
	quadro[9][0] = 'E';
	
}

void imprimirExplicacao(void){ 

	printf("*********************************************************\n");
	printf("                      CAÇA PALAVRAS                      \n");
	printf("*********************************************************\n");
	printf(" Quando encontrar a palavra, digite sem acentuações.\n");
	printf(" Digite apenas 1 palavra de cada vez.\n");
	printf(" Há 7 palavras no caça palavras.\n");
	printf("---------------------------------------------------------");
}

void imprimirQuadro(void){ 

	int i, j;
	
	printf("\n\t+---+---+---+---+---+---+---+---+---+---+"); 
	for(i = 0; i < 10; i++){
		printf("    \n  \t|");
		for(j = 0; j < 10; j++){
			printf(" %c |", quadro[i][j]);
		} 
		printf("\n\t+---+---+---+---+---+---+---+---+---+---+");
	}
}

void colocandoPalavras(void){
	
	switch(sorteio){
		case 0: 
			printf("\n\t\t     Estabelecimentos");
			opcao0();
		break;	
		
		case 1: 
			printf("\n\t\t\t  Frutas");
			opcao1();
		break;
		
		case 2:
			printf("\n\t\t\t Países");
			opcao2();
		break;
		
		default: 
			printf("ERRO!\n");
		break;
	}
}
