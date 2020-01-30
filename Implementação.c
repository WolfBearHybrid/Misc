#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

void PrintMatrix(int v, int e, int a[v][v][e]){
	
	for(int i=0; i<e; i++){
		printf ("\nVariavel %d\n", i);
		for(int j=0; j<v; j++){
			for(int k=0; k<v; k++){
				printf("[%d]", a[j][k][i]);
			}
		printf("\n");
		}
	printf("\n\n");
	}
	
}
	

int main(){
	printf("Defina quantidade total de Estados do Automato: ");
	int Vertex, Edges, Starts_Quantity, Ends_Quantity,  p, l, c;
	scanf("%d", &Vertex);
	
	printf("Defina quantidade total de Variaveis do Automato: ");
	scanf("%d", &Edges);
	
	printf("Defina a Quantidade de Estados Iniciais: ");
	scanf("%d", &Starts_Quantity);
	int Starts[Starts_Quantity];
	
	printf("Defina quais estados sao Iniciais (Insira o Numero correspondente, comecando apartir do 0): ");
	for(int i = 0; i < Starts_Quantity; i++){
		scanf("%d", &Starts[i]);
	}
	
	printf("Defina a Quantidade de Estados Finais: ");
	scanf("%d", &Ends_Quantity);
	int Ends[Ends_Quantity];
	
	printf("Defina quais estados sao Finais (Insira o Numero correspondente, contando apartir do 0): ");
	for(int i = 0; i < Ends_Quantity; i++){
		scanf("%d", &Ends[i]);
	}
	printf("ok, agora insira a matriz do Automato, [O formato e uma matriz Estados X Estados cada uma das variaveis tera uma matriz propria, comecando a partir de P0]: ");
	int Aut[Vertex][Vertex][Edges];
	for(p=0; p<Edges; p++){
		printf ("\nVariavel %d", p);
		for(l=0; l<Vertex; l++){	
			for(c=0; c<Vertex; c++){
				printf("\nEstado [P%d]->[P%d]: ", l, c, p);
				scanf("%d", &Aut[l][c][p]);
			}
		}
	}
	
	
	PrintMatrix(Vertex, Edges, Aut);
	
	int confirm=2;
	
	do {
		int strTam, linha;
		int falha = false, recon = false;
		
		printf("\n\nInsira o numero de instrucoes a ser reconhecido seguido da cadeia a ser reconhecida: \n");
		scanf("%d", &strTam);
		int String[strTam];
		scanf("%s", String);
		
		for(int s = 0; s < Starts_Quantity && recon == false; s++){
			linha = Starts[s];	
			//printf("%d", falha);
			for(int j = 0; j < strTam && falha == false; j++){
				int coluna = 0;
				printf("%d", Vertex);
				while(coluna < Vertex){
					if(Aut[linha][coluna][String[j]] == 1){
						printf("%d", coluna);
						linha = coluna;
						coluna = Vertex;	
					}else if(Aut[linha][coluna][String[j]] == 0){
						coluna++;
						if (coluna == Vertex){
							falha = true;
						}
					}	
				}		
			}
			if(falha == false){
				for(int i = 0; i < Ends_Quantity; i++){
					if(linha = Ends[i]){
						printf("%d", Ends[i]);
						recon=true;
					}
				}
			}
			
			
		}
		if(recon == true){
			printf("\nCadeia reconhecida pelo Automato");
		}else
			printf("\nCadeia nao reconhecida");
		
		
		printf("\nContinuar? 0 para sair");
		scanf("%d", &confirm);
	}while(confirm != 0);
return 0;
}
