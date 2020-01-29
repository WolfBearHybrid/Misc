#include <stdio.h>
#include <stdlib.h>

void PrintMatrix(int v, int e, int a[v][v][e]){
	for(int i=0; i<=e; i++){
		printf ("\nVariavel %d\n", i);
		for(int j=0; j<=v; j++){
			for(int k=0; k<=v; k++){
				printf("[%i]", a[k][j][i]);
			}
		printf("\n");
		}
	printf("\n\n");
	}
	
}
int main(){
	printf("Defina quantidade total de estados e de Variaveis do Automato: \n");
	int Vertex, Edges;
	scanf("%d%d", &Vertex, &Edges);
	Vertex--; Edges--;
	int Aut[Vertex][Vertex][Edges];
	for(int i=0; i<=Edges; i++){
		printf ("Variavel %d", i);
		for(int j=0; j<=Vertex; j++){	
			for(int k=0; k<=Vertex; k++){
				printf("\nIndice [%i][%i]: ", j, k);
				scanf("%d", &Aut[k][j][i]);
			}
		}
	}
	PrintMatrix(Vertex, Edges, Aut);

return 0;
}
