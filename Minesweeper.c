// Biblioteca (standard input-output header) que possui as funções principais de entrada e saída.
#include <stdio.h>

// Biblioteca (standard library) que possui funções envolvendo alocação de memória, controle de processos, dentre outras.
#include <stdlib.h>

// Biblioteca (time) que possui funções para manipulação de datas e horários.
#include <time.h>

// Biblioteca (windows) que possui funções de coordenadas, dentre outras.
#include <windows.h>

// Biblioteca (locale) que possui funções para mudar a linguagem do programa.
#include <locale.h>

// Biblioteca (conio2) que possui funções de coloração de ambiente.
#include <conio2.h>

// Variável global que vai determinar o tamanho da matriz.
int TAM;

// Função pra deslocar o cursor.
void coordinates() {
	COORD coord;
	coord.X = 55;
	coord.Y = 15;
	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), coord);
}

// Função que possui o título.
void printTitle() {

	// Foram utilizados vários output para que não houvesse nenhum tipo de bug, pois o título é muito grande.
	printf("             -----------------------------------------------------------------------------------------\n");
	printf("             ¦¦¦    ¦¦¦ ¦¦ ¦¦¦    ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦     ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦  ¦¦¦¦¦¦¦ ¦¦¦¦¦¦ \n");
	printf("             ¦¦¦¦  ¦¦¦¦ ¦¦ ¦¦¦¦   ¦¦ ¦¦      ¦¦      ¦¦     ¦¦ ¦¦      ¦¦      ¦¦   ¦¦ ¦¦      ¦¦   ¦¦ \n");
	printf("             ¦¦ ¦¦¦¦ ¦¦ ¦¦ ¦¦ ¦¦  ¦¦ ¦¦¦¦¦   ¦¦¦¦¦¦¦ ¦¦  ¦  ¦¦ ¦¦¦¦¦   ¦¦¦¦¦   ¦¦¦¦¦¦  ¦¦¦¦¦   ¦¦¦¦¦¦  \n");
	printf("             ¦¦  ¦¦  ¦¦ ¦¦ ¦¦  ¦¦ ¦¦ ¦¦           ¦¦ ¦¦ ¦¦¦ ¦¦ ¦¦      ¦¦      ¦¦      ¦¦      ¦¦   ¦¦ \n");
	printf("             ¦¦      ¦¦ ¦¦ ¦¦   ¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦  ¦¦¦ ¦¦¦  ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦      ¦¦¦¦¦¦¦ ¦¦   ¦¦ \n");
	printf("             -----------------------------------------------------------------------------------------\n\n\n");
}

// Função para armazenar qualquer tecla digitada.
void waitForEnter() {
	char erro;
	fflush(stdin);
	scanf("%c", &erro);
}

// Função contendo a tela de carregamento.
void loading() {

	// Variável contadora usada para finalizar a estrutura de repetição.
	int i = 0;

	// Função que define a cor das letras do programa.
	system ("color A");
    printf ("\n\n\n\n\n\n\n\n\n\n\n                                          Carregando MINESWEEPER");

    // Contagem de 2 voltas, para não ficar cansativo.
    while (i < 2){

    	// Comando responsável por segurar, neste caso, 1s antes de aparecer o próximo comando.
        sleep(1);
        printf(".");
        sleep(1);
        printf (".");
        sleep(1);
        printf (".");
        sleep(1);

        // Comando de retrocesso, apaga o caractere à esquerda do cursor.
        printf ("\b\b\b   \b\b\b");
        i++;
    }

    // Função responsável por apagar tudo que foi printado em tela.
    system("cls");
}

// Função contendo o menu principal do jogo.
int mainMenu() {
	int op;

	// Laço para fazer com que o usuário consiga voltar ao menu caso selecione a segunda opção ou digite qualquer outro valor fora das opções do menu.
	while (1) {
		system ("cls");

		// Função que contém o título, dessa forma o título vai sempre aparecer na tela, tornando o ambiente mais agradável.
		printTitle();

		// Menu de opções para o usuário.
		printf("						Novo Jogo -> {1}\n\n");
		printf("						Créditos  -> {2}\n\n");
		printf("						Sair      -> {0}\n\n");

		// Centralizar o cursor.
		coordinates();
		scanf("%d",&op);

 		// Irá receber o número que o usuário digitou e entrar no switch.
		switch(op) {

			// Finaliza o jogo.
			case 0:

			// Inicia um novo jogo.
			case 1: {

				// Serve para parar o laço e retornar o valor 1 ou 0 para a função mainMenu.
				return op;
			}

			// Contém os créditos do jogo.
			case 2: {

				// Limpa a tela.
				system("cls");
				printTitle();
				textcolor(GREEN);
				cprintf("Jogo desenvolvido por estudantes de Ciência da Computação\n\n");
				cprintf("Professor:\n");
				textcolor(WHITE);
				cprintf("Marcio Soussa\n\n");
				textcolor(GREEN);
				cprintf("Desenvolvedor:\n");
				textcolor(WHITE);
				cprintf("Rafael Luna\n\n");
				textcolor(GREEN);
				cprintf("precione \"enter\" para voltar ao menu principal...");

				// Chama função.
				waitForEnter();
				break;
			}

			// Caso o usuário digite qualquer outra coisa que não esteja no menu de opções irá aparecer a seguinte mensagem.
			default: {
				system("cls");
				printf("Código inválido\n");
				printf("Precione \"enter\" para retornar...");

				waitForEnter();
				break;
			}
		}
	}
}

// Função para printar o tabuleiro.
// Parâmetros:
//    - area: Matriz do mapa do tabuleiro.
void printTabuleiro(int area[TAM][TAM]) {
	int i, j;

	// laço feito para organizar as coordenadas pro usuário.
	for (j = 0; j < TAM; j++) {
		if (j == 0) {
			textcolor(GREEN);
			cprintf("    %d   ", j + 1);
			
		} else  {
			textcolor(GREEN);
			cprintf("   %d    ", j + 1);
		}
	}

	printf("\n\n");
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {

			//Condição para organizar as coordenadas pro usuário.
			if (j == 0 && i >= j) {
				textcolor(GREEN);
				cprintf("%d", i + 1);
			}

			// Verifica se o valor de área é -3 e printa 0 (void).
			if (area[i][j] == -3) {
				textcolor(WHITE);
				cprintf("  [%d]	", 0);
			}
			
			// Verifica se o valor de área é >= -4 e printa as dicas do jogo de 1 à 8.
			else if (area[i][j] == -4) {
				textcolor(BLUE);
				cprintf("  [%d]	", 1);
				
			} else if (area[i][j] == -5) {
				textcolor(CYAN);
				cprintf("  [%d]	", 2);
			} else if (area[i][j] == -6) {
				textcolor(RED);
				cprintf("  [%d]	", 3);
			} else if (area[i][j] == -7) {
				textcolor(MAGENTA);
				cprintf("  [%d]	", 4);
			} else if (area[i][j] == -8) {
				textcolor(YELLOW);
				cprintf("  [%d]	", 5);
			} else if (area[i][j] == -9) {
				textcolor(BROWN);
				cprintf("  [%d]	", 6);
			} else if (area[i][j] == -10) {
				textcolor(RED + GREEN);
				cprintf("  [%d]	", 7);
			} else if (area[i][j] == -11) {
				textcolor(LIGHTMAGENTA);
				cprintf("  [%d]	", 8);
			}

			// Printa o restante do tabuleiro, as casas que ainda não foram abertas.	
			else  {
				textcolor(GREEN);
				cprintf("  [ ]	");	
			}
		}
		printf("\n\n");
	}
}

// Função recursiva.
// Paramêntros:
//    - area: Matriz do mapa do tabuleiro.
//    - x: Posição X para verificar.
//    - y: Posição Y para verificar.
/* Tem como função abrir todas as casas adjacentes, quando encontrar
    uma bomba ou uma dica a função encerra para aquela posição,
   chegando a mostrar pelo menos uma dica da casa adjacente à
   vazia. */
// Ela só funciona caso o conteúdo da matriz seja 0 (void). 
void recursiv(int area[TAM][TAM], int x, int y) {

	/* Marca a casa que o usuário escolheu com -3
	   e toda vez que a função recursiva for 
	   chamada  e o conteúdo na matriz for 0 ela
	   é marcada com o -3 */
	area[x][y] = -3;

	/* Verifica se com o acréscimo ou decréscimo o espaço continua
	   válido, dessa forma ele só vai procurar se o espaço estiver
	   dentro da matriz. */
	if (y + 1 < TAM) {

		/* Se a verificação for válido ele
		   acessa a determinada casa e
		   verifica o conteúdo dela. */
        switch (area[x][y + 1]) {

        	// Caso seja 0.
        	case 0 : {

        		// Chama recursividade
        		// Parâmetros:
        		//    - area: Matriz do mapa do tabuleiro.
        		//    - x: Posição.
        		//    - Y: Posição com o acréscimo.
        		recursiv(area, x, y + 1);
				break;
			}

			// Caso seja maior ou igual a 1, ele apenas marca aquela posição com o valor correspondente a cada dica.
			case 1 : {
				area[x][y + 1] = -4;
				break;
			}
			case 2 : {
				area[x][y + 1] = -5;
				break;
			}
			case 3 : {
				area[x][y + 1] = -6;
				break;
			}
			case 4 : {
				area[x][y + 1] = -7;
				break;
			}
			case 5 : {
				area[x][y + 1] = -8;
				break;
			}
			case 6 : {
				area[x][y + 1] = -9;
				break;
			}
			case 7 : {
				area[x][y + 1] = -10;
				break;
			}
			case 8 : {
				area[x][y + 1] = -11;
				break;
			}
			
			// Caso seja bomba ele apenas pula.
			default : {
				break;
			}
		}
        	
	}

	// Os comentários de cima servem para o restante do código.
	if (y - 1 >= 0) {
       	switch (area[x][y - 1]) {
        	case 0 : {
        		recursiv(area, x, y - 1);
				break;
			}
			case 1 : {
				area[x][y - 1] = -4;
				break;
			}
			case 2 : {
				area[x][y - 1] = -5;
				break;
			}
			case 3 : {
				area[x][y - 1] = -6;
				break;
			}
			case 4 : {
				area[x][y - 1] = -7;
				break;
			}
			case 5 : {
				area[x][y - 1] = -8;
				break;
			}
			case 6 : {
				area[x][y - 1] = -9;
				break;
			}
			case 7 : {
				area[x][y - 1] = -10;
				break;
			}
			case 8 : {
				area[x][y - 1] = -11;
				break;
			}
			default : {
				break;
			}
		}
	}
	if (x + 1 < TAM) {
       	switch (area[x + 1][y]) {
        	case 0 : {
        		recursiv(area, x + 1, y);
				break;
			}
			case 1 : {
				area[x + 1][y] = -4;
				break;
			}
			case 2 : {
				area[x + 1][y] = -5;
				break;
			}
			case 3 : {
				area[x + 1][y] = -6;
				break;
			}
			case 4 : {
				area[x + 1][y] = -7;
				break;
			}
			case 5 : {
				area[x + 1][y] = -8;
				break;
			}
			case 6 : {
				area[x + 1][y] = -9;
				break;
			}
			case 7 : {
				area[x + 1][y] = -10;
				break;
			}
			case 8 : {
				area[x + 1][y] = -11;
				break;
			}
			default : {
				break;
			}
		}
	}
	if (x - 1 >= 0) {
      	switch (area[x - 1][y]) {
        	case 0 : {
        		recursiv(area, x - 1, y);
				break;
			}
			case 1 : {
				area[x - 1][y] = -4;
				break;
			}
			case 2 : {
				area[x - 1][y] = -5;
				break;
			}
			case 3 : {
				area[x - 1][y] = -6;
				break;
			}
			case 4 : {
				area[x - 1][y] = -7;
				break;
			}
			case 5 : {
				area[x - 1][y] = -8;
				break;
			}
			case 6 : {
				area[x - 1][y] = -9;
				break;
			}
			case 7 : {
				area[x - 1][y] = -10;
				break;
			}
			case 8 : {
				area[x - 1][y] = -11;
				break;
			}
			default : {
				break;
			}
		}
	}
	if (x - 1 >= 0 && y + 1 < TAM) {
        switch (area[x - 1][y + 1]) {
        	case 0 : {
        		recursiv(area, x - 1, y + 1);
				break;
			}
			case 1 : {
				area[x - 1][y + 1] = -4;
				break;
			}
			case 2 : {
				area[x - 1][y + 1] = -5;
				break;
			}
			case 3 : {
				area[x - 1][y + 1] = -6;
				break;
			}
			case 4 : {
				area[x - 1][y + 1] = -7;
				break;
			}
			case 5 : {
				area[x - 1][y + 1] = -8;
				break;
			}
			case 6 : {
				area[x - 1][y + 1] = -9;
				break;
			}
			case 7 : {
				area[x - 1][y + 1] = -10;
				break;
			}
			case 8 : {
				area[x - 1][y + 1] = -11;
				break;
			}
			default : {
				break;
			}
		}
	}
	if (x + 1 < TAM && y + 1 < TAM) {
        switch (area[x + 1][y + 1]) {
        	case 0 : {
        		recursiv(area, x + 1, y + 1);
				break;
			}
			case 1 : {
				area[x + 1][y + 1] = -4;
				break;
			}
			case 2 : {
				area[x + 1][y + 1] = -5;
				break;
			}
			case 3 : {
				area[x + 1][y + 1] = -6;
				break;
			}
			case 4 : {
				area[x + 1][y + 1] = -7;
				break;
			}
			case 5 : {
				area[x + 1][y + 1] = -8;
				break;
			}
			case 6 : {
				area[x + 1][y + 1] = -9;
				break;
			}
			case 7 : {
				area[x + 1][y + 1] = -10;
				break;
			}
			case 8 : {
				area[x + 1][y + 1] = -11;
				break;
			}
			default : {
				break;
			}
		}
	}
	if (x - 1 >= 0 && y - 1 >= 0) {
      	switch (area[x - 1][y - 1]) {
       		case 0 : {
       			recursiv(area, x - 1, y - 1);
				break;
			}
			case 1 : {
				area[x - 1][y - 1] = -4;
				break;
			}
			case 2 : {
				area[x - 1][y - 1] = -5;
				break;
			}
			case 3 : {
				area[x - 1][y - 1] = -6;
				break;
			}
			case 4 : {
				area[x - 1][y - 1] = -7;
				break;
			}
			case 5 : {
				area[x - 1][y - 1] = -8;
				break;
			}
			case 6 : {
				area[x - 1][y - 1] = -9;
				break;
			}
			case 7 : {
				area[x - 1][y - 1] = -10;
				break;
			}
			case 8 : {
				area[x - 1][y - 1] = -11;
				break;
			}
			default : {
				break;
			}
		}
	}
	if (x + 1 < TAM && y - 1 >= 0) {
       	switch (area[x + 1][y - 1]) {
        	case 0 : {
   				recursiv(area, x + 1, y - 1);
				break;
			}
			case 1 : {
				area[x + 1][y - 1] = -4;
				break;
			}
			case 2 : {
				area[x + 1][y - 1] = -5;
				break;
			}
			case 3 : {
				area[x + 1][y - 1] = -6;
				break;
			}
			case 4 : {
				area[x + 1][y - 1] = -7;
				break;
			}
			case 5 : {
				area[x + 1][y - 1] = -8;
				break;
			}
			case 6 : {
				area[x + 1][y - 1] = -9;
				break;
			}
			case 7 : {
				area[x + 1][y - 1] = -10;
				break;
			}
			case 8 : {
				area[x + 1][y - 1] = -11;
				break;
			}
			default : {
				break;
			}
		}
	}
}

// Função para abrir uma posição no tabuleiro.
// Parâmetros:
//    - area: Matriz do mapa do tabuleiro.
//    - x: Posição X para abrir.
//    - y: Posição Y para abrir.
int openPosition(int area[TAM][TAM], int x, int y) {
	/* Todos os valores valores dentro da matriz são substituídos por números negativos.
		dessa forma consigo manter aquela posição aberta no tabuleiro e ainda verificar
		se o usuário já abriu essa posição */

	// Verifica o conteúdo de área na posição x e y;
	switch (area[x][y]) {

		// Se for -1 significa que é uma bomba.
		case -1 : {
			return -1;
		}

		// Se for 0 significa que é vazio.
		case 0 : {
			
			// Chama recursividade.
			recursiv(area, x, y);
			return 0;
		}

		// Se for maior ou igual a 1 significa que é uma dica.
		// Marca a dica com um valor negativo.
		case 1 : {
			area[x][y] = -4;
			return 1;
		}
		case 2 : {
			area[x][y] = -5;
			return 1;
		}
		case 3 : {
			area[x][y] = -6;
			return 1;
		}
		case 4 : {
			area[x][y] = -7;
			return 1;
		}
		case 5 : {
			area[x][y] = -8;
			return 1;
		}
		case 6 : {
			area[x][y] = -9;
			return 1;
		}
		case 7 : {
			area[x][y] = -10;
			return 1;
		}
		case 8 : {
			area[x][y] = -11;
			return 1;
		}

		// Siginifica que o usuário já abriu essa posição.
		default : {
			return -2;
		}
	}
}

// Função para gerar as bombas.
void bomb(int area[TAM][TAM]) {
	int i, j;

	// Semente para melhorar a aleatoriedade.
	srand(time(NULL));

	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {

			// Operadores ternários, se for -1 (?) randomifique novamente, então 0 (:).
			area[i][j] = ((rand() % 2) -1 == -1) ? (rand() % 2) -1 : 0;
		}
	}
}

// Função que gera o status para saber quando o usuário ganhou.
int win(int area[TAM][TAM]) {
	int i, j, vazio = 0;

	// Percorre a matriz procurando os espaços sem bombas.
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			
			// Incrementa +1 a vazio cada vez que encontra.
			if (area[i][j] >= 0) vazio++;
		}
	}

	// Retorna a quantidade de espaços vazios.
	return vazio;
}

// Função que gera as dicas.
void generatetips(int area[TAM][TAM]) {
	int i, j;

	// Percorre a matriz.
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {

			// Procura pelos espaços vazios.	
			if (area[i][j] == 0) {

				// Verifica se com o acréscimo ou decréscimo o espaço continua válido.
				/* serve para ele percorrer todas as casas 
				   adjascentes procurando por bombas, caso encontre
				   já incrementa +1 onde estava vazio. */
				   
				// Posição a ser verificada, tendo o meio como referência, por exemplo:
				/* - - -
				   - - x
				   - - - */
				if (j + 1 < TAM) {
        			if (area[i][j + 1] == -1) {
        				area[i][j] += 1;
					}
				}

				// Posição a ser verificada por exemplo:
				/* - - -
				   x - -
				   - - - */   
				if (j - 1 >= 0) {
       				if (area[i][j - 1] == -1) {
       					area[i][j] += 1;
			  		}
			   }

				// Posição a ser verificada por exemplo:
				/* - - -
				   - - -
				   - x - */
			   if (i + 1 < TAM) {
       				if (area[i + 1][j] == -1) {
       					area[i][j] += 1;
					}
				}

				// Posição a ser verificada por exemplo:
				/* - x -
				   - - -
				   - - - */
				if (i - 1 >= 0) {
      				if (area[i - 1][j] == -1) {
        				area[i][j] += 1;
					}
				}

				// Posição a ser verificada por exemplo:
				/* - - x
				   - - -
				   - - - */
				if (i - 1 >= 0 && j + 1 < TAM) {
           			if (area[i - 1][j + 1] == -1) {
        				area[i][j] += 1;
					}
				}

				// Posição a ser verificada por exemplo:
				/* - - -
				   - - -
				   - - x */
				if (i + 1 < TAM && j + 1 < TAM) {
            	  	if (area[i + 1][j + 1] == -1) {
        				area[i][j] += 1;
					}
				}

				// Posição a ser verificada por exemplo:
				/* x - -
				   - - -
				   - - - */
				if (i - 1 >= 0 && j - 1 >= 0) {
              	 	if (area[i - 1][j - 1] == -1) {
        				area[i][j] += 1;
					}
				}

				// Posição a ser verificada por exemplo:
				/* - - -
				   - - -
				   x - - */
				if (i + 1 < TAM && j - 1 >= 0) {
              		if (area[i + 1][j - 1] == -1) {
        				area[i][j] += 1;
					}
				}
        	}
       }
	}
}

// Função que contém a relação do player com o jogo.
int game() {

	// Definir a cor do texto printado no console para verde.
	system("color A");
	int area[TAM][TAM];
	int status;

	// Chama função bomb.
	bomb(area);

	// Chama função gera dicas.
	generatetips(area);

	// Começa a interação com o player.
	while (1) {

		// Limpa a tela.
		system("cls");

		// Chama função título.
		textcolor(GREEN);
		printTitle();

		// Chama função win.
		status = win(area);

		if (status == 0) {
			system("cls");
			printTitle();
			printf("\n\n					  PARABÉNS, VOCÊ VENCEU!!!");

			waitForEnter();

  			// Chama a função game, voltando para o menu.
			return main();;                                   
		}

		// Printar o tabuleiro.
		printTabuleiro(area);

		// Pedir a posição para o jogador.
		textcolor(WHITE);
		cprintf("\nDigite as coordenadas [X Y]: ");
		int x, y;
		scanf("%d %d", &x, &y);
		// Verificar se a posição informada é válida.
		if (x > 0 && x <= TAM && y > 0 && y <= TAM) {

			// Chama openPosition e retorna algum valor.
			int result = openPosition(area, x - 1, y - 1);

			// Se o valore retornado for -2 significa que ele já abriu essa posição.
			if (result == -2) {
				textcolor(WHITE);
				cprintf("Você já abriu essa posição!!\n");

			// Se for 0, posição vazia.
			} else if (result == 0) {
				textcolor(WHITE);
				cprintf("Você ainda não se explodiu, HAHAHA!!\n");

			// Se for -1, significa que é uma bomba.
			} else if (result == -1) {
				system("cls");
				printTitle();
				textcolor(RED);
				cprintf("\n\n					  FIM DE JOGO, VOCÊ PERDEU!!!");    

				waitForEnter();

				// Chama a função game, voltando para o menu.
				return main();;
				
			// Se for qualquer outra coisa é uma dica.
			} else {
				textcolor(WHITE);
				cprintf("Segura essa dica!!!!");
			}

		// Posição inválida.
		} else {
			textcolor(RED);
			cprintf("Coordenadas inválidas, por favor, precione \"enter\" para tentar novamente.\n");
		}

		// Chama função que espera qualquer tecla a ser digitada.
		waitForEnter();

		// Limpa tela.
		system("cls");
	}
}

// Função main contendo as opções 0 e 1 do menu principal.
int main() {
	
	// Função que muda a linguagem do programa.
	setlocale(LC_ALL, "portuguese");

	// Variável local estética, quando a função é chamada pela segunda vez, a variável não é recriada.
	static int x = 0;

	system("cls");

	// Função contendo a tela de carregamento.
	if (x == 0) loading();

	// Atribui 1 a variável local, dessa forma a animação de carregamento não irá aparecer caso a função seja chamada novamente.
	x = 1;

	int nivel;
	system("color A");

    // Se mainMenu retornou 1 então entra no if.
	if (mainMenu() == 1) {

		// Limpa tela.
		system("cls");

		// Laço para fazer com que o usuário consiga voltar ao menu caso digite uma opção inválida.
		while (1) {

			// Chama título.
			printTitle();

			// Dificuldades.
			printf("						Fácil   -> {1}\n\n");
			printf("						Médio   -> {2}\n\n");
			printf("						Difícil -> {3}\n\n");

			// Centralizar o cursor.
			coordinates();
			scanf("%d", &nivel);

			switch (nivel) {

				// Easy.
				case 1 : {

					// Variável global que define o tamanho do tabuleiro.
					TAM = 5;
					
					// Chama função Game.
					game(TAM);
					return 0;
				}

				// Medium.
				case 2 : {
				 	TAM = 7;
				 	game(TAM);
					return 0;
				 }

				// Hard.
				case 3 : {
					TAM = 9;
					game(TAM);
					return 0;
				}

				// Robustez.
				default : {
					system("cls");
					printf("Código inválido\n");
					printf("Precione \"enter\" para retornar...");

					// Chama função.
					waitForEnter();
					system("cls");
					break;
				}
			}
		}

	// Caso seja 0 deve finalizar o algoritmo.
	} else {
		printf("Finalizando...\n");
		system("pause");
	}

	return 0;
}
