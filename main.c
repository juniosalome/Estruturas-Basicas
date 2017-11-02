#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab.h"

int main(int argc, char const *argv[])
{
	if(argc < 3){
		printf("uso: %s arq_labirinto arq_solucao [alg]\n", argv[0]);
		return 0;
	}

	// por padrão, algoritmo recursivo
	int alg = (argc == 3)? 0 : atoi(argv[3]);

	Labirinto* lab = LeLabirinto(argv[1]);

	EncontraCaminho(lab, argv[2], alg);

	return 0;
}