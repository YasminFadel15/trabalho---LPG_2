#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

//STRUCT notas
typedef struct notas{
  int id_aluno;
  int id_nota;
  float valor_nota;
} tabela_notas;

//STRUCT ALUNO
typedef struct aluno{
	tabela_notas
    tabelas_notas[30];
    int quant_notas;
    int id;
    char nome[50];
    int excluido;
} tabela_aluno;


//--------------------------------------------------------------//
 
//VARIÁVEIS GLOBAIS

tabela_aluno tabelas_alunos[10];
tabela_notas tabelas_notas[30];
int quant_alunos = 0;
int escolha;
int indice = 1;


//--------------------------------------------------------------//


//FUNÇÕES MENU RELATÓRIOS


void rel_medias(){
	
	struct tm *data_hora_atual;
	time_t segundos;
	time(&segundos);
	data_hora_atual = localtime(&segundos);
	int i;
	
	printf("_____________________________________\n");
    printf("\n");
    printf("----------RELATÓRIO DE MÉDIAS--------\n");
    printf("_____________________________________\n");
    printf("-------------------------------------\n");
    printf("|   ID   |      NOME      |  MÉDIA  |\n");
	
	for(i=1 ; i <= quant_alunos ; i++){
		printf("|   %d\t |", tabelas_alunos[i].id);
		printf("     %s\t  |", tabelas_alunos[i].nome);
		printf("   %.2f  |\n", (tabelas_alunos[i].tabelas_notas[3].valor_nota + tabelas_alunos[i].tabelas_notas[1].valor_nota + tabelas_alunos[i].tabelas_notas[2].valor_nota) / 3);
	}

    printf("\n-------------------------------------\n");
    printf("_________________________________________ Gerado em %d/%d/%d %i:%i:%i\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900, data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);
}


void rel_notas(){
	
	struct tm *data_hora_atual;
	time_t segundos;
	time(&segundos);
	data_hora_atual = localtime(&segundos);
	int i, k;
	
	printf("____________________________________________________________\n");
    printf("\n");
    printf("---------------------RELATÓRIO DE NOTAS---------------------\n");
    printf("____________________________________________________________\n");
    printf("------------------------------------------------------------\n");
    printf("|   ID   |      NOME      |  NOTA 1  |  NOTA 2  |  NOTA 3  |\n");
	
	for(i = 1 ; i <= quant_alunos ; i++){
		printf("|   %d\t |", tabelas_alunos[i].id);
		printf("     %s\t  |", tabelas_alunos[i].nome);
		for(k = 1 ; k <= 3 ; k++){
			printf("   %.2f   |", tabelas_alunos[i].tabelas_notas[k].valor_nota);
		}
		printf("\n");
	}
   
   
    printf("\n------------------------------------------------------------\n");
    printf("_________________________________________ Gerado em %d/%d/%d %i:%i:%i\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900, data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);
}

//--------------------------------------------------------------//


//FUNÇÕES MENU NOTAS


void consultaNota(){
    
    int i, k, j, idDigitado;

    printf("\n-----CONSULTAR NOTAS-----\n");
    printf("Digite o id do aluno: ");
    scanf("%i", &idDigitado);
    getchar();
    
    for(i = 1; i<=quant_alunos; i++){
        if((tabelas_alunos[i].id == idDigitado) && (tabelas_alunos[i].excluido == 0) && (tabelas_alunos[i].quant_notas!= 0)){
            printf("Aluno: %s\n", tabelas_alunos[i].nome);

            for(j = 1 ; j <= 3 ; j++){
                printf("Nota [%i]: %.2f\n", j, tabelas_alunos[i].tabelas_notas[j].valor_nota);
            }
        } else if((tabelas_alunos[i].id == idDigitado) && (tabelas_alunos[i].excluido == 1)){
            printf("Aluno não existe na base!\n");
        } else if(tabelas_alunos[i].quant_notas == 0){
        	printf("Aluno sem notas cadastradas!\n");
		}
    }
    if ((quant_alunos == 0) || (idDigitado > quant_alunos)){
        printf("Aluno não cadastrado!\n");
    }
    
    printf("---------------------------\n");
}


void excluirNota(){
	int i, k, j, idDigitado;
	int notaExcluida;

    printf("\n-----EXCLUIR NOTAS-----\n");
    printf("Digite o id do aluno: ");
    scanf("%i", &idDigitado);
    getchar();
    
    for(i = 1; i<=quant_alunos; i++){
        if((tabelas_alunos[i].id == idDigitado) && (tabelas_alunos[i].excluido == 0) && (tabelas_alunos[i].quant_notas != 0)){
            printf("Aluno: %s\n", tabelas_alunos[i].nome);

            for(j = 1 ; j <= 3 ; j++){
                printf("Nota [%i]: %.2f\n", j, tabelas_alunos[i].tabelas_notas[j].valor_nota);
            }

            for(k = 1 ; k < 2 ; k++){
            	printf("Qual nota deseja excluir? ");
            	scanf("%d", &notaExcluida);
            	if(notaExcluida < 3){
            		if(notaExcluida <= 3){
            			tabelas_alunos[i].tabelas_notas[k].valor_nota = 0;
            			printf("Nota excluída!\n");
            		}
            	}
            	
                else{
            		printf("Nota inválida!\n");
				}
        	}
        } else if((tabelas_alunos[i].id == idDigitado) && (tabelas_alunos[i].excluido == 1)){
            printf("Aluno não existe na base!\n");
        } else if (tabelas_alunos[i].quant_notas == 0){
			printf("Aluno sem notas cadastradas!\n");
		}
    }

    if ((quant_alunos == 0) || (idDigitado > quant_alunos)){
        printf("Aluno não cadastrado!\n");
    }

    printf("---------------------------\n");
}


void alterarNota(){
	int i, k, j, idDigitado;
	int notaAlterada;
	float valorAlterado;

    printf("\n-----ALTERAR NOTAS-----\n");
    printf("Digite o id do aluno: ");
    scanf("%d", &idDigitado);
    getchar();
    
    for(i = 1 ; i<=quant_alunos ; i++){
        if((tabelas_alunos[i].id == idDigitado) && (tabelas_alunos[i].excluido == 0) && (tabelas_alunos[i].quant_notas != 0)){
            printf("Aluno: %s\n", tabelas_alunos[i].nome);
            for(j = 1; j <= 3; j++){
                printf("Nota [%i]: %.2f\n", j, tabelas_alunos[i].tabelas_notas[j].valor_nota);
            }
            for(k = 1; k<2; k++){
            	printf("Qual nota deseja alterar? ");
            	scanf("%d", &notaAlterada);
            	if(notaAlterada < 3){
            		printf("Nova nota [%i] (de 0 a 10): ", notaAlterada);
            		scanf("%f", &valorAlterado);
            		tabelas_alunos[i].tabelas_notas[k].valor_nota = valorAlterado;
            		printf("Nota alterada!\n");
            	}
            	else
            		printf("Nota inválida!\n");
        	}
        } else {
            if((tabelas_alunos[i].id == idDigitado) && (tabelas_alunos[i].excluido == 1)){
              printf("Aluno não existe na base!\n");
            } else {
                    if (tabelas_alunos[i].quant_notas == 0)
			            printf("Aluno sem notas cadastradas!\n");
		    }
        }
    }

    if ((quant_alunos == 0) || (idDigitado > quant_alunos))
        printf("Aluno não cadastrado!\n");
    
    
    printf("---------------------------\n");
}


void incluirNota(){
    int i, k, idDigitado, indice;
    float notaDigitada; 

    printf("\n-----INCLUIR NOTAS-----\n");
    printf("Digite o id do aluno: ");
    scanf("%d", &idDigitado);
    getchar();
    
    for(i = 1 ; i <= quant_alunos ; i++){
        if((tabelas_alunos[i].id == idDigitado) && (tabelas_alunos[i].excluido == 0) && (tabelas_alunos[i].quant_notas <= 4)){
            printf("Aluno: %s\n", tabelas_alunos[i].nome);

            for(tabelas_alunos[i].quant_notas = 1; tabelas_alunos[i].quant_notas <= 3; tabelas_alunos[i].quant_notas++){
                printf("Digite a %i nota (de 0 a 10): ", tabelas_alunos[i].quant_notas);
                scanf("\n%f", &notaDigitada);

                tabelas_alunos[i].tabelas_notas[tabelas_alunos[i].quant_notas].valor_nota = notaDigitada;
            }
            printf("Notas cadastradas com sucesso!\n");
        } else if((tabelas_alunos[i].id == idDigitado) && (tabelas_alunos[i].excluido == 1)){
            printf("Aluno não existe na base!\n");
        } else if((tabelas_alunos[i].id == idDigitado) && (tabelas_alunos[i].excluido == 0) && (tabelas_alunos[i].quant_notas > 3)){
        	printf("As notas do aluno já foram cadastradas\n");
		}
    }

    if ((quant_alunos == 0) || (idDigitado > quant_alunos))
        printf("Aluno não cadastrado!\n");
    
    printf("---------------------------\n");
}


//--------------------------------------------------------------//


//FUNÇÕES MENU ALUNO

void relatorioAluno(){
	struct tm *data_hora_atual;
	time_t segundos;
	time(&segundos);
	data_hora_atual = localtime(&segundos);
    int i;
    char excluido[2];

    printf("___________________________________________\n");
    printf("\n");
    printf("--------------RELATÓRIO DE ALUNOS-----------\n");
    printf("___________________________________________\n");
    printf("-------------------------------------------\n");
    printf("|   ID  |       NOME        |  EXCLUÍDO  |\n");
	for(i=1 ; i <= quant_alunos ; i++){
		printf("|   %d\t|", tabelas_alunos[i].id);
		printf("      %s\t    |", tabelas_alunos[i].nome);
		printf("      %i     |\n", tabelas_alunos[i].excluido);
	}
    printf("\n----------------------------------------\n");
    printf("_________________________________________ Gerado em %d/%d/%d %i:%i:%i\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900, data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);
}


void alterar(){
    int i, idDigitado;
    char opcao[2];
    char nomeAlterado[50];

    printf("\n-----ALTERAÇÃO DE ALUNO-----\n");
    printf("Digite o id do aluno: ");
    scanf("%i", &idDigitado);
    getchar();

    for (i = 1; i <= quant_alunos; i++){
        if ((idDigitado == tabelas_alunos[i].id) && (tabelas_alunos[i].excluido == 0)){
            printf("Aluno: %s\nNovo nome: ", tabelas_alunos[i].nome);
            fgets(nomeAlterado, 50, stdin);
            printf("Confirmar alteração? [S]im ou [N]ão\n");

            fgets(opcao, 2, stdin);
            getchar();
            opcao[0] = toupper(opcao[0]);
            if (strcmp(opcao, "S") == 0){
                strcpy(tabelas_alunos[i].nome, nomeAlterado);
                tabelas_alunos[i].nome[strcspn(tabelas_alunos[i].nome, "\n")] = 0;
                printf("\nNome alterado!\n");
            } else if (strcmp(opcao, "N") == 0){
                printf("Operação cancelada!\n");
            } else if ((tabelas_alunos[i].excluido == 1) && (idDigitado == tabelas_alunos[i].id)){
                printf("Aluno não existe na base!\n");
            }
        }
    }

    if ((quant_alunos == 0) || (idDigitado > quant_alunos))
        printf("Aluno não cadastrado!\n");
    
    printf("---------------------------\n");
}


void excluir(){
    int i, idDigitado;
    char opcao[2];

    printf("\n-----EXCLUSÃO DE ALUNO-----\n");
    printf("Digite o id do aluno: ");
    scanf("%d", &idDigitado);

    for (i = 1; i <= quant_alunos; i++){
        if ((idDigitado == tabelas_alunos[i].id) && (tabelas_alunos[i].excluido == 0)){
            printf("Confirmar exclusão? [S]im ou [N]ão\n");
            getchar();
            fgets(opcao, 2, stdin);
            opcao[0] = toupper(opcao[0]);

            if (strcmp(opcao, "S") == 0){
                tabelas_alunos[i].excluido = 1;
                printf("Aluno deletado!\n");
            } else
                printf("Operação cancelada!\n");  
        }
    }

    if ((quant_alunos == 0) || (idDigitado > quant_alunos) || (tabelas_alunos[i].id == 1))
        printf("Aluno não cadastrado!\n");
    
    printf("---------------------------\n");
}


void busca(){
    int i, idDigitado;

    printf("\n------BUSCA DE ALUNOS------\n");
    printf("Digite o id do aluno: ");
    scanf("%i", &idDigitado);
    getchar();

    for (i = 1; i <= quant_alunos; i++){
        if ((idDigitado == tabelas_alunos[i].id) && (tabelas_alunos[i].excluido == 0)){
            printf("Aluno: %s\n", tabelas_alunos[i].nome);
        } else if ((tabelas_alunos[i].excluido == 1) && (idDigitado == tabelas_alunos[i].id))
            printf("Aluno não existe na base!\n");  
    }

    if ((quant_alunos == 0) || (idDigitado > quant_alunos))
        printf("Aluno não cadastrado!\n");
    
    printf("---------------------------\n");
}


void cadastro(){
    quant_alunos++;
    tabelas_alunos[quant_alunos].id = quant_alunos;

    printf("\n------CADASTRO DE ALUNOS------\n");
    printf("Código do aluno: %i\n", quant_alunos);
    do{
        printf("Digite o nome do aluno: ");
        fgets(tabelas_alunos[quant_alunos].nome, 50, stdin);
        tabelas_alunos[quant_alunos].nome[strcspn(tabelas_alunos[quant_alunos].nome, "\n")] = 0;
        if (strlen(tabelas_alunos[quant_alunos].nome) <= 4){
            printf("O nome deve ter mais de três caracteres\n");
        }
    } while (strlen(tabelas_alunos[quant_alunos].nome) <= 4);

    tabelas_alunos[quant_alunos].excluido = 0; 
    printf("\nAluno cadastrado!\n");
    printf("---------------------------\n");
}

//--------------------------------------------------------------//

//MENUS SECUNDÁRIOS

int aluno(){
    do{
        printf("\n");
        printf("----------MENU ALUNO---------\n");
        printf("-------------------\n");
        printf("| [1] - Cadastrar |\n| [2] - Consultar |\n| [3] - Excluir   |\n| [4] - Alterar   |\n| [5] - Relatório |\n| [6] - Voltar    |\n");
        printf("-------------------\n");
        printf("Opção: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha){
        case 1:
            cadastro();
            break;
        case 2:
            busca();
            break;
        case 3:
            excluir();
            break;
        case 4:
            alterar();
            break;
        case 5:
            relatorioAluno();
            break;
        }
    } while (escolha != 6);
}



int notas(){
    do{
        printf("\n");
        printf("----------MENU NOTAS----------\n");
        printf("------------------------\n");
        printf("| [1] - Cadastrar Nota |\n| [2] - Alterar Nota   |\n| [3] - Excluir Nota   |\n| [4] - Consultar Nota |\n| [5] - Voltar         |\n");
        printf("------------------------\n");
        printf("Opção: ");
        scanf("%d", &escolha);
        switch (escolha){
        case 1:
            incluirNota();
            break;
        case 2:
            alterarNota();
            break;
        case 3:
            excluirNota();
            break;
        case 4:
            consultaNota();
            break;
        }
    } while (escolha != 5);
}



void relatorio(){
    do{
        printf("\n");
        printf("----------MENU RELATÓRIO----------\n");
        printf("-----------------------------\n");
        printf("| [1] - Relatório de Notas |\n| [2] - Relatório de Médias |\n| [3] - Voltar              |\n");
        printf("-----------------------------\n");
        printf("Opção: ");
        scanf("%d", &escolha);
        switch (escolha){
        case 1:
            rel_notas();
            break;
        case 2:
            rel_medias();
            break;
        }
    } while (escolha != 3);
}


//--------------------------------------------------------------//


int main() {
    setlocale(LC_ALL, ""); 

    do{
    	struct tm *data_hora_atual;
		time_t segundos;
		time(&segundos);
		data_hora_atual = localtime(&segundos);
    	printf("Acesso em %d/%d/%d %i:%i:%i\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900, data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);

        printf("--MENU PRINCIPAL--\n");
        printf("------------------\n");
        printf("| [1] - Aluno     |\n| [2] - Notas |\n| [3] - Relatório |\n| [4] - Sair      |\n");
        printf("------------------\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            aluno();
            break;
        case 2:
            notas();
            break;
        case 3:
            relatorio();
            break;
        }
    } while (escolha != 4);
    return 0;
}

