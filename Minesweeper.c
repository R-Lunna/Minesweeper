// Biblioteca (standard input-output header) que possui as fun��es principais de entrada e sa�da.
#include <stdio.h>

// Biblioteca (standard library) que possui fun��es envolvendo aloca��o de mem�ria, controle de processos, dentre outras.
#include <stdlib.h>

// Biblioteca (time) que possui fun��es para manipula��o de datas e hor�rios.
#include <time.h>

// Biblioteca (windows) que possui fun��es de coordenadas, dentre outras.
#include <windows.h>

// Biblioteca (locale) que possui fun��es para mudar a linguagem do programa.
#include <locale.h>

// Biblioteca (conio2) que possui fun��es de colora��o de ambiente.
#include <conio2.h>

// Vari�vel global que vai determinar o tamanho da matriz.
int TAM;

// Fun��o pra deslocar o cursor.
void coordinates() {
	COORD coord;
	coord.X = 55;
	coord.Y = 15;
	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), coord);
}

// Fun��o que possui o t�tulo.
void printTitle() {

	// Foram utilizados v�rios output para que n�o houvesse nenhum tipo de bug, pois o t�tulo � muito grande.
	printf("             -----------------------------------------------------------------------------------------\n");
	printf("             ���    ��� �� ���    �� ������� ������� ��     �� ������� ������� ������  ������� ������ \n");
	printf("             ����  ���� �� ����   �� ��      ��      ��     �� ��      ��      ��   �� ��      ��   �� \n");
	printf("             �� ���� �� �� �� ��  �� �����   ������� ��  �  �� �����   �����   ������  �����   ������  \n");
	printf("             ��  ��  �� �� ��  �� �� ��           �� �� ��� �� ��      ��      ��      ��      ��   �� \n");
	printf("             ��      �� �� ��   ���� ������� �������  ��� ���  ������� ������� ��      ������� ��   �� \n");
	printf("             -----------------------------------------------------------------------------------------\n\n\n");
}

// Fun��o para armazenar qualquer tecla digitada.
void waitForEnter() {
	char erro;
	fflush(stdin);
	scanf("%c", &erro);
}

// Fun��o contendo a tela de carregamento.
void loading() {

	// Vari�vel contadora usada para finalizar a estrutura de repeti��o.
	int i = 0;

	// Fun��o que define a cor das letras do programa.
	system ("color A");
    printf ("\n\n\n\n\n\n\n\n\n\n\n                                          Carregando MINESWEEPER");

    // Contagem de 2 voltas, para n�o ficar cansativo.
    while (i < 2){

    	// Comando respons�vel por segurar, neste caso, 1s antes de aparecer o pr�ximo comando.
        sleep(1);
        printf(".");
        sleep(1);
        printf (".");
        sleep(1);
        printf (".");
        sleep(1);

        // Comando de retrocesso, apaga o caractere � esquerda do cursor.
        printf ("\b\b\b   \b\b\b");
        i++;
    }

    // Fun��o respons�vel por apagar tudo que foi printado em tela.
    system("cls");
}

// Fun��o contendo o menu principal do jogo.
int mainMenu() {
	int op;

	// La�o para fazer com que o usu�rio consiga voltar ao menu caso selecione a segunda op��o ou digite qualquer outro valor fora das op��es do menu.
	while (1) {
		system ("cls");

		// Fun��o que cont�m o t�tulo, dessa forma o t�tulo vai sempre aparecer na tela, tornando o ambiente mais agrad�vel.
		printTitle();

		// Menu de op��es para o usu�rio.
		printf("						Novo Jogo -> {1}\n\n");
		printf("						Cr�ditos  -> {2}\n\n");
		printf("						Sair      -> {0}\n\n");

		// Centralizar o cursor.
		coordinates();
		scanf("%d",&op);

 		// Ir� receber o n�mero que o usu�rio digitou e entrar no switch.
		switch(op) {

			// Finaliza o jogo.
			case 0:

			// Inicia um novo jogo.
			case 1: {

				// Serve para parar o la�o e retornar o valor 1 ou 0 para a fun��o mainMenu.
				return op;
			}

			// Cont�m os cr�ditos do jogo.
			case 2: {

				// Limpa a tela.
				system("cls");
				printTitle();
				textcolor(GREEN);
				cprintf("Jogo desenvolvido por estudantes de Ci�ncia da Computa��o\n\n");
				cprintf("Professor:\n");
				textcolor(WHITE);
				cprintf("Marcio Soussa\n\n");
				textcolor(GREEN);
				cprintf("Desenvolvedor:\n");
				textcolor(WHITE);
				cprintf("Rafael Luna\n\n");
				textcolor(GREEN);
				cprintf("precione \"enter\" para voltar ao menu principal...");

				// Chama fun��o.
				waitForEnter();
				break;
			}

			// Caso o usu�rio digite qualquer outra coisa que n�o esteja no menu de op��es ir� aparecer a seguinte mensagem.
			default: {
				system("cls");
				printf("C�digo inv�lido\n");
				printf("Precione \"enter\" para retornar...");

				waitForEnter();
				break;
			}
		}
	}
}

// Fun��o para printar o tabuleiro.
// Par�metros:
//    - area: Matriz do mapa do tabuleiro.
void printTabuleiro(int area[TAM][TAM]) {
	int i, j;

	// la�o feito para organizar as coordenadas pro usu�rio.
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

			//Condi��o para organizar as coordenadas pro usu�rio.
			if (j == 0 && i >= j) {
				textcolor(GREEN);
				cprintf("%d", i + 1);
			}

			// Verifica se o valor de �rea � -3 e printa 0 (void).
			if (area[i][j] == -3) {
				textcolor(WHITE);
				cprintf("  [%d]	", 0);
			}
			
			// Verifica se o valor de �rea � >= -4 e printa as dicas do jogo de 1 � 8.
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

			// Printa o restante do tabuleiro, as casas que ainda n�o foram abertas.	
			else  {
				textcolor(GREEN);
				cprintf("  [ ]	");	
			}
		}
		printf("\n\n");
	}
}

// Fun��o recursiva.
// Param�ntros:
//    - area: Matriz do mapa do tabuleiro.
//    - x: Posi��o X para verificar.
//    - y: Posi��o Y para verificar.
/* Tem como fun��o abrir todas as casas adjacentes, quando encontrar
    uma bomba ou uma dica a fun��o encerra para aquela posi��o,
   chegando a mostrar pelo menos uma dica da casa adjacente �
   vazia. */
// Ela s� funciona caso o conte�do da matriz seja 0 (void). 
void recursiv(int area[TAM][TAM], int x, int y) {

	/* Marca a casa que o usu�rio escolheu com -3
	   e toda vez que a fun��o recursiva for 
	   chamada  e o conte�do na matriz for 0 ela
	   � marcada com o -3 */
	area[x][y] = -3;

	/* Verifica se com o acr�scimo ou decr�scimo o espa�o continua
	   v�lido, dessa forma ele s� vai procurar se o espa�o estiver
	   dentro da matriz. */
	if (y + 1 < TAM) {

		/* Se a verifica��o for v�lido ele
		   acessa a determinada casa e
		   verifica o conte�do dela. */
        switch (area[x][y + 1]) {

        	// Caso seja 0.
        	case 0 : {

        		// Chama recursividade
        		// Par�metros:
        		//    - area: Matriz do mapa do tabuleiro.
        		//    - x: Posi��o.
        		//    - Y: Posi��o com o acr�scimo.
        		recursiv(area, x, y + 1);
				break;
			}

			// Caso seja maior ou igual a 1, ele apenas marca aquela posi��o com o valor correspondente a cada dica.
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

	// Os coment�rios de cima servem para o restante do c�digo.
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

// Fun��o para abrir uma posi��o no tabuleiro.
// Par�metros:
//    - area: Matriz do mapa do tabuleiro.
//    - x: Posi��o X para abrir.
//    - y: Posi��o Y para abrir.
int openPosition(int area[TAM][TAM], int x, int y) {
	/* Todos os valores valores dentro da matriz s�o substitu�dos por n�meros negativos.
		dessa forma consigo manter aquela posi��o aberta no tabuleiro e ainda verificar
		se o usu�rio j� abriu essa posi��o */

	// Verifica o conte�do de �rea na posi��o x e y;
	switch (area[x][y]) {

		// Se for -1 significa que � uma bomba.
		case -1 : {
			return -1;
		}

		// Se for 0 significa que � vazio.
		case 0 : {
			
			// Chama recursividade.
			recursiv(area, x, y);
			return 0;
		}

		// Se for maior ou igual a 1 significa que � uma dica.
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

		// Siginifica que o usu�rio j� abriu essa posi��o.
		default : {
			return -2;
		}
	}
}

// Fun��o para gerar as bombas.
void bomb(int area[TAM][TAM]) {
	int i, j;

	// Semente para melhorar a aleatoriedade.
	srand(time(NULL));

	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {

			// Operadores tern�rios, se for -1 (?) randomifique novamente, ent�o 0 (:).
			area[i][j] = ((rand() % 2) -1 == -1) ? (rand() % 2) -1 : 0;
		}
	}
}

// Fun��o que gera o status para saber quando o usu�rio ganhou.
int win(int area[TAM][TAM]) {
	int i, j, vazio = 0;

	// Percorre a matriz procurando os espa�os sem bombas.
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			
			// Incrementa +1 a vazio cada vez que encontra.
			if (area[i][j] >= 0) vazio++;
		}
	}

	// Retorna a quantidade de espa�os vazios.
	return vazio;
}

// Fun��o que gera as dicas.
void generatetips(int area[TAM][TAM]) {
	int i, j;

	// Percorre a matriz.
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {

			// Procura pelos espa�os vazios.	
			if (area[i][j] == 0) {

				// Verifica se com o acr�scimo ou decr�scimo o espa�o continua v�lido.
				/* serve para ele percorrer todas as casas 
				   adjascentes procurando por bombas, caso encontre
				   j� incrementa +1 onde estava vazio. */
				   
				// Posi��o a ser verificada, tendo o meio como refer�ncia, por exemplo:
				/* - - -
				   - - x
				   - - - */
				if (j + 1 < TAM) {
        			if (area[i][j + 1] == -1) {
        				area[i][j] += 1;
					}
				}

				// Posi��o a ser verificada por exemplo:
				/* - - -
				   x - -
				   - - - */   
				if (j - 1 >= 0) {
       				if (area[i][j - 1] == -1) {
       					area[i][j] += 1;
			  		}
			   }

				// Posi��o a ser verificada por exemplo:
				/* - - -
				   - - -
				   - x - */
			   if (i + 1 < TAM) {
       				if (area[i + 1][j] == -1) {
       					area[i][j] += 1;
					}
				}

				// Posi��o a ser verificada por exemplo:
				/* - x -
				   - - -
				   - - - */
				if (i - 1 >= 0) {
      				if (area[i - 1][j] == -1) {
        				area[i][j] += 1;
					}
				}

				// Posi��o a ser verificada por exemplo:
				/* - - x
				   - - -
				   - - - */
				if (i - 1 >= 0 && j + 1 < TAM) {
           			if (area[i - 1][j + 1] == -1) {
        				area[i][j] += 1;
					}
				}

				// Posi��o a ser verificada por exemplo:
				/* - - -
				   - - -
				   - - x */
				if (i + 1 < TAM && j + 1 < TAM) {
            	  	if (area[i + 1][j + 1] == -1) {
        				area[i][j] += 1;
					}
				}

				// Posi��o a ser verificada por exemplo:
				/* x - -
				   - - -
				   - - - */
				if (i - 1 >= 0 && j - 1 >= 0) {
              	 	if (area[i - 1][j - 1] == -1) {
        				area[i][j] += 1;
					}
				}

				// Posi��o a ser verificada por exemplo:
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

// Fun��o que cont�m a rela��o do player com o jogo.
int game() {

	// Definir a cor do texto printado no console para verde.
	system("color A");
	int area[TAM][TAM];
	int status;

	// Chama fun��o bomb.
	bomb(area);

	// Chama fun��o gera dicas.
	generatetips(area);

	// Come�a a intera��o com o player.
	while (1) {

		// Limpa a tela.
		system("cls");

		// Chama fun��o t�tulo.
		textcolor(GREEN);
		printTitle();

		// Chama fun��o win.
		status = win(area);

		if (status == 0) {
			system("cls");
			printTitle();
			printf("\n\n					  PARAB�NS, VOC� VENCEU!!!");

			waitForEnter();

  			// Chama a fun��o game, voltando para o menu.
			return main();;                                   
		}

		// Printar o tabuleiro.
		printTabuleiro(area);

		// Pedir a posi��o para o jogador.
		textcolor(WHITE);
		cprintf("\nDigite as coordenadas [X Y]: ");
		int x, y;
		scanf("%d %d", &x, &y);
		// Verificar se a posi��o informada � v�lida.
		if (x > 0 && x <= TAM && y > 0 && y <= TAM) {

			// Chama openPosition e retorna algum valor.
			int result = openPosition(area, x - 1, y - 1);

			// Se o valore retornado for -2 significa que ele j� abriu essa posi��o.
			if (result == -2) {
				textcolor(WHITE);
				cprintf("Voc� j� abriu essa posi��o!!\n");

			// Se for 0, posi��o vazia.
			} else if (result == 0) {
				textcolor(WHITE);
				cprintf("Voc� ainda n�o se explodiu, HAHAHA!!\n");

			// Se for -1, significa que � uma bomba.
			} else if (result == -1) {
				system("cls");
				printTitle();
				textcolor(RED);
				cprintf("\n\n					  FIM DE JOGO, VOC� PERDEU!!!");    

				waitForEnter();

				// Chama a fun��o game, voltando para o menu.
				return main();;
				
			// Se for qualquer outra coisa � uma dica.
			} else {
				textcolor(WHITE);
				cprintf("Segura essa dica!!!!");
			}

		// Posi��o inv�lida.
		} else {
			textcolor(RED);
			cprintf("Coordenadas inv�lidas, por favor, precione \"enter\" para tentar novamente.\n");
		}

		// Chama fun��o que espera qualquer tecla a ser digitada.
		waitForEnter();

		// Limpa tela.
		system("cls");
	}
}

// Fun��o main contendo as op��es 0 e 1 do menu principal.
int main() {
	
	// Fun��o que muda a linguagem do programa.
	setlocale(LC_ALL, "portuguese");

	// Vari�vel local est�tica, quando a fun��o � chamada pela segunda vez, a vari�vel n�o � recriada.
	static int x = 0;

	system("cls");

	// Fun��o contendo a tela de carregamento.
	if (x == 0) loading();

	// Atribui 1 a vari�vel local, dessa forma a anima��o de carregamento n�o ir� aparecer caso a fun��o seja chamada novamente.
	x = 1;

	int nivel;
	system("color A");

    // Se mainMenu retornou 1 ent�o entra no if.
	if (mainMenu() == 1) {

		// Limpa tela.
		system("cls");

		// La�o para fazer com que o usu�rio consiga voltar ao menu caso digite uma op��o inv�lida.
		while (1) {

			// Chama t�tulo.
			printTitle();

			// Dificuldades.
			printf("						F�cil   -> {1}\n\n");
			printf("						M�dio   -> {2}\n\n");
			printf("						Dif�cil -> {3}\n\n");

			// Centralizar o cursor.
			coordinates();
			scanf("%d", &nivel);

			switch (nivel) {

				// Easy.
				case 1 : {

					// Vari�vel global que define o tamanho do tabuleiro.
					TAM = 5;
					
					// Chama fun��o Game.
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
					printf("C�digo inv�lido\n");
					printf("Precione \"enter\" para retornar...");

					// Chama fun��o.
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
