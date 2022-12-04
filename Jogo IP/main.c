#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


// erros encontrados: o programa permite colocar dois numeros na coluna ex:a20,c30./o programa n?o aceita letras maiusculas
void exibeTabuleiro(char tab[][9], char letra[]){

		int l,c;


		printf("\n\t  1   2   3   4   5   6   7   8   9 \n");
		for(l=0;l<9;l++){
			for(c=0;c<9;c++){
				if(c==0){
					printf("\t| ");
				}
				printf("%c",tab[l][c]);

				if(c<=8){
					printf(" | ");
				}
				if(c==8){
					printf("%c",letra[l]);
				}
			}
				if(l<8)
					printf("\n\t-------------------------------------");
			printf("\n");
	}

}


int naCasa(char tab[][9], int linha, int coluna){

	if(tab[linha][coluna]=='x'){
		return 0;
	}
	else if(tab[linha][coluna]=='o'){
		return 1;
	}
	else if(tab[linha][coluna]=='+'){
		return 2;
	}
	else if(tab[linha][coluna]=='*'){
		return 3;
	}
	else{
		return 4;
	}
}

int validaPeca1(char tab[][9],int linha, int coluna){

	if(tab[linha][coluna]!='x'){
		return 1;
			}
	else{
		return 0;
	}

  }


int validaPeca2(char tab[][9], int linha, int coluna){

	if(tab[linha][coluna]!='o'){
		return 1;
	}

 	else{
 		return 0;
	 }

}

int validaMovimento(char tab[][9], int l1, int c1, int l2, int c2){

	int i, maior, menor, d, b, lmenor, lmaior;
	int dv= abs(l2-l1);
	int dh= abs(c2-c1);

	//d=(abs(l2-l1)+abs(c2-c1));

	if (c1 > c2){
		maior=c1;
		menor=c2;
	}

	else if (c2 > c1){
			maior=c2;
			menor=c1;
		}

	if (l1 > l2){
		lmaior=l1;
		lmenor=l2;
	}

	else if(l2 > l1){
			lmaior=l2;
			lmenor=l1;
		}

	if( (dv == dh)|| (dv == 0)|| (dh == 0)){

			if (dv==0){

			for (i = (menor+1); i < maior; i++){
				if (tab[l1][i] != ' '){
					return 2;
				}
			}
		}

		if (dh==0){
			for (i = (lmenor+1); i < lmaior; i++){
				if (tab[i][c1] != ' '){
					return 2;
				}
			}
		}

		if (dv==dh){

       if (lmaior > l1 && maior > c1){
          for(i=1; i<=dv;i++){
            d = l1 + i;
            b = c1 + i;
           if (tab[d][b] != ' '){
            return 2;
            }}}
       if (lmenor < l1 && menor < c1){
          for(i=1; i<=dv;i++){
            d = l1 - i;
            b = c1 - i;
           if (tab[d][b] != ' '){
            return 2;
            }}}
        if (lmaior > l1 && menor < c1){
          for(i=1; i<=dv;i++){
            d = l1 + i;
            b = c1 - i;
           if (tab[d][b] != ' '){
            return 2;
            }}}
        if (lmenor < l1 && maior > c1){
          for(i=1; i<=dv;i++){
             d = l1 - i;
             b = c1 + i;
           if (tab[d][b] != ' '){
            return 2;
            }}}


			}

		return 1;
	}

	else{
		return 0;
	}


 }




int main(){

	int l,c,linha,coluna,g=0,cont,al1,al2,jogador=1,linha2,coluna2, x;
	char tab[9][9], letra[9], movimento[2];

	letra [0]= 'a';
	for(x=1;x<10;x++)
	letra [x]=letra[x-1]+1;

	srand(time(NULL));

	for(l=0;l<9;l++){
		for(c=0;c<9;c++)
			tab[l][c]=' ';
	}
		while(cont!=5){
			al1=rand()%9;
			al2=rand()%9;
			if(tab[al1][al2]==' '){
				tab[al1][al2]='x';
				cont++;
		}
			else {
				while(tab[al1][al2]==' '){
					al1=rand()%9;
					al2=rand()%9;
					tab[al1][al2]='x';
					cont++;
					}
			}
	}


	al1=0;al2=0;cont=0;

		while(cont!=5){
			al1=rand()%9;
			al2=rand()%9;
			if(tab[al1][al2]==' '){
				tab[al1][al2]='o';
				cont++;
		}
			else {
				while(tab[al1][al2]==' '){
					al1=rand()%9;
					al2=rand()%9;
					tab[al1][al2]='o';
					cont++;
					}
			}
	}

	do{

		exibeTabuleiro(tab,letra);
		printf("\n\n");

		if(jogador==1){

		printf("Peca do jogador: x\n");
		printf("jogador %d digite a peca que deseja jogar (linha e coluna) (a-i)(1-9)\n",jogador);
		scanf("%s",&movimento);
		while (strlen(movimento)!=2){
            printf("Formato errado, digite novamente (Ex: a3)\n");
            printf("jogador %d digite a peca que deseja jogar (linha e coluna) (a-i)(1-9)\n",jogador);
            scanf("%s",&movimento);
		}
		linha = movimento[0]-'a'; coluna = movimento[1] - '1';


		while (linha < 0 || linha >8 || coluna < 0 || coluna > 8 || strlen(movimento)!=2){

			printf("Linha ou coluna invalida, escolha novamente\n");
			scanf("%s",&movimento);
			linha = movimento[0]-'a'; coluna = movimento[1] - '1';
			}



		while(validaPeca1(tab,linha,coluna) != 0){
			printf("posicao invalida, escolha novamente\n");
			scanf("%s", &movimento);
			linha = movimento[0]-'a'; coluna = movimento[1] - '1';
			validaPeca1(tab,linha,coluna) != 0;
		}

	}

		printf("digite o destino da peca\n");
		scanf("%s",&movimento);
		while(strlen(movimento)!=2){
         printf("Formato errado, digite novamente (Ex: a3)\n");
         printf("digite o destino da peca\n");
         scanf("%s",&movimento);
		}

		linha2 = movimento[0]-'a'; coluna2 = movimento[1] - '1';

		while (linha2 < 0 || linha2 >8 || coluna2 < 0 || coluna2 > 8 || strlen(movimento)!=2){
			printf("Linha ou coluna invalida, escolha novamente\n ");
			scanf("%s",&movimento);
			linha2 = movimento[0]-'a'; coluna2 = movimento[1] - '1';
		}



		while(tab[linha2][coluna2]!=' '){
			printf("posicao invalida, esolha novamente\n");
			scanf("%s", &movimento);
			linha2 = movimento[0]-'a'; coluna2 = movimento[1] - '1';
		}

		while(validaMovimento(tab,linha,coluna,linha2,coluna2) !=1){

			printf("Movimento invalido, escolha outra casa:\n");
			scanf("%s",&movimento);
			linha2 = movimento[0]-'a'; coluna2 = movimento[1] - '1';
			validaMovimento(tab,linha,coluna,linha2,coluna2);

		}



		tab[linha2][coluna2]=tab[linha][coluna];
		tab[linha][coluna]='+';
		jogador=2;
		system ("cls");


		exibeTabuleiro(tab,letra);

		printf("\n\n");

		if(jogador==2){

		printf("Peca do jogador: o\n");
		printf("jogador %d digite a peca que deseja jogar:\n ",jogador);
		scanf("%s",&movimento);
		while (strlen(movimento)!=2){
            printf("Formato errado, digite novamente (Ex: a3)\n");
            printf("jogador %d digite a peca que deseja jogar (linha e coluna) (a-i)(1-9)\n",jogador);
            scanf("%s",&movimento);
		}

		linha = movimento[0]-'a'; coluna = movimento[1] - '1';
	}

		while (linha < 0 || linha >8 || coluna < 0 || coluna > 8 || strlen(movimento)!=2){

			printf("Linha ou coluna invalida, escolha novamente\n");
			scanf("%s",&movimento);
			linha = movimento[0]-'a'; coluna = movimento[1] - '1';
		}



	while(validaPeca2(tab,linha, coluna) != 0 ){
			printf("posicao invalida, escolha novamente\n");
			scanf("%s", &movimento);
			linha = movimento[0]-'a'; coluna = movimento[1] - '1';
			validaPeca2(tab,linha,coluna);

		}

		printf("digite o destino da peca:\n");
		scanf("%s",&movimento);
		while(strlen(movimento)!=2){
         printf("Formato errado, digite novamente (Ex: a3)\n");
         printf("digite o destino da peca\n");
         scanf("%s",&movimento);
		}
		linha2 = movimento[0]-'a'; coluna2 = movimento[1] - '1';



		while (linha2 < 0 || linha2 >8 || coluna2 < 0 || coluna2 > 8){
			printf("Linha ou coluna invalida, escolha novamente\n ");
			scanf("%s",&movimento);
			linha2 = movimento[0]-'a'; coluna2 = movimento[1] - '1';
		}



	while(tab[linha2][coluna2]!=' '){

            printf("posicao invalida, esolha novamente\n");
			scanf("%s", &movimento);
			linha2 = movimento[0]-'a'; coluna2 = movimento[1] - '1';
		}

	while (validaMovimento(tab,linha,coluna,linha2,coluna2)!=1){

		printf("Movimento invalido,escolha outra casa:\n");
		scanf("%s",&movimento);
		linha2 = movimento[0]-'a'; coluna2 = movimento[1] - '1';

		}

		tab[linha2][coluna2]=tab[linha][coluna];
		tab[linha][coluna]='*';
		jogador=1;
		system("cls");




	}while(g!=1);
}
