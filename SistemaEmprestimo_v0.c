/*
    Nome do arquivo : SistemaEmprestimo_v0.c

    Desenvolvedores : Erika Barbosa Gomes
                      Everson Henrich da Silva
                      Luiz Fantin Neto
                      Paulo Otávio Godio
                      Vitor Lohan Brito Teixeira

    Versão Atual: (1.0.0)
           Mudanças:
               - Adicionado sistema de requisição de dados dos clientes

*/

/*Importação de bibliotecas*/
//Entrada e saída de dados (utilizadas: scanf(), printf(), fflush())
#include<stdio.h>
//Operacoes matematicas (utilizadas: pow())
#include<math.h>
//Para usar getch().
#include<conio.h>

/*Funcao principal*/
int main()
{
    /*Variáveis que armazenam os dados do cliente*/
    char nomeCliente[51] = {' '};
    char  CPF[15] = {0};
    int dataEmprestimo_dia = 0;
    int dataEmprestimo_mes = 0;
    int dataEmprestimo_ano = 0;
    int tipoEmprestimo = 0;
    float valorEmprestimo = 0.0;
    int numParcelas = 0;
    float jurosParcelas = 0.0;
    int parcelasPagas = 0;
    float valorParcela = 0.0;


    /*Cabecalho da interface do sistema*/
    printf("\tSISTEMA DE CADASTRO DE CLIENTES\n\n");
    printf("INSTRUCOES\n");
    printf("- Entre com as informacoes solicitadas\n");
    printf("- A tecla ENTER registra as informacoes inseridas\n");
    printf("- As informacoes devem ser inseridas seguindo o formato entre parenteses()\n\n");
    printf("\nINSERINDO NOVO CLIENTE\n");

    /*Solicitando as informacoes do cliente*/
    printf("Insira o nome do cliente (max. 50 caracteres)\n: ");
    //Lê e armazena uma string de no maximo 50 caracteres até encontrar \n(ENTER)
    scanf(" %50[^\n]s", nomeCliente);
    //limpa o buffer do teclado
    fflush(stdin);

    printf("Insira o CPF do cliente (XXX.XXX.XXX-XX)\n: ");
    scanf(" %14[^\n]s", CPF);
    fflush(stdin);

    printf("Insira a data em que o emprestimo foi realizado\n");
    printf("dia(XX)\n: ");
    scanf("%d",&dataEmprestimo_dia);
    printf("mes(XX)\n: ");
    scanf("%d",&dataEmprestimo_mes);
    printf("ano(XXXX)\n: ");
    scanf("%d",&dataEmprestimo_ano);

    printf("Insira o tipo de emprestimo (X)\n");
    printf("1 - Aquisicao de imovel\n");
    printf("2 - Reforma de imovel\n");
    printf("3 - Aquisicao de veiculo\n");
    printf("4 - Viagem\n");
    printf("5 - Estudo\n: ");
    scanf("%d", &tipoEmprestimo);

    printf("Insira o valor do emprestimo RS(XXXXX.XX)\n: ");
    scanf("%f", &valorEmprestimo);

    printf("Insira o numero de parcelas do emprestimo (XX)\n: ");
    scanf("%d", &numParcelas);

    printf("Insira a taxa de juros mensal do emprestimo(XX.XX)%%\n: ");
    scanf("%f", &jurosParcelas);

    printf("Insira o numero de parcelas do emprestimo que ja foram pagas (XX)\n: ");
    scanf("%d", &parcelasPagas);

    /*Calculo da parcela mensal a ser paga*/
    jurosParcelas /= 100;
    //valorParcela =  (valorEmprestimo/numParcelas)*(1+jurosParcelas);
    valorParcela = (jurosParcelas*valorEmprestimo)/(1- pow(1+jurosParcelas, -numParcelas));

    printf("\tDADOS ARMAZENADOS\n");
    /*mostra as informações armazenadas ao usuario*/
    /*
    printf("\nDADOS REGISTRADOS\n\n");

    printf("Nome do Cliente\n");
    printf("\t%s\n", nomeCliente);

    printf("CPF\n");
    printf("\t%s\n", CPF);

    printf("Data de realizacao do emprestimo\n");
    printf("\t%d/%d/%d\n", dataEmprestimo_dia, dataEmprestimo_mes, dataEmprestimo_ano);

    printf("Tipo do emprestimo :\t %d\n", tipoEmprestimo);
    printf("\t1 - Aquisicao de imovel\n");
    printf("\t2 - Reforma de imovel\n");
    printf("\t3 - Aquisicao de veiculo\n");
    printf("\t4 - Viagem\n");
    printf("\t5 - Estudo\n");

    printf("Valor do Emprestimo\n");
    printf("\tRS %.2f\n", valorEmprestimo);

    printf("Numero de Parcelas\n");
    printf("\t%d\n", numParcelas);

    printf("Taxa de juros mensal\n");
    printf("\t%.2f%%\n", jurosParcelas*100);

    printf("Numero de Parcelas pagas\n");
    printf("\t%d\n", parcelasPagas);

    printf("Valor da parcela\n");
    printf("\tRS %.2f\n", valorParcela);
    */

    getch();

    return 0;
}
