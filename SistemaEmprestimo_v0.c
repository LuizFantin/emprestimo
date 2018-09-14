/*
    Nome do arquivo : SistemaEmprestimo_v0.c

    Desenvolvedores : Erika Barbosa Gomes
                      Everson Henrich da Silva
                      Luiz Fantin Neto
                      Paulo Otávio Godio
                      Vitor Lohan Brito Teixeira
    Data: 14/09/2018
    Versão: (1.1.0)
           Mudanças:
               - Foram adicionados testes condicionais para analisar a possibilidade do empréstimo.
               Podendo ser: Aprovado, Aprovado após análise, Reprovado após análise, Reprovado.
    Versões Anteriores : (1.0.1) e (1.0.0)
*/

/*Importação de bibliotecas*/
//Entrada e saída de dados (utilizadas: scanf(), printf(), fflush()).
#include<stdio.h>
//Operacoes matematicas (utilizadas: pow()).
#include<math.h>
//Para utilizar o getch().
#include<conio.h>
//Para manipulação de strings.
#include<string.h>

/*Funcao principal*/
int main()
{
    /*Variáveis que armazenam os dados do cliente*/
    char nomeCliente[51] = {' '};
    char  cpf[15] = {0};
    char resultadoEmprestimo[23] = {' '};
    int dataEmprestimoDia = 0;
    int dataEmprestimoMes = 0;
    int dataEmprestimoAno = 0;
    int tipoEmprestimo = 0;
    float valorEmprestimo = 0.0;
    int numParcelas = 0;
    float jurosParcelas = 0.0;
    int parcelasPagas = 0;
    float valorParcela = 0.0;
    float rendaMensal = 0.0;
    int imovelQuitado = 0;
    int emprestimoAnterior = 0;
    int parcelaAnterior = 0;
    int parcelaPagaAnterior = 0;



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
    scanf(" %14[^\n]s", cpf);
    fflush(stdin);

    printf("Insira a data em que o emprestimo foi realizado\n");
    printf("dia(XX)\n: ");
    scanf("%d",&dataEmprestimoDia);
    printf("mes(XX)\n: ");
    scanf("%d",&dataEmprestimoMes);
    printf("ano(XXXX)\n: ");
    scanf("%d",&dataEmprestimoAno);

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

    printf("Insira o valor de sua renda mensal RS(XXXXX.XX)\n: ");
    scanf("%f", &rendaMensal);

    /*Calculo da parcela mensal a ser paga*/
    jurosParcelas /= 100;
    //valorParcela =  (valorEmprestimo/numParcelas)*(1+jurosParcelas);
    valorParcela = (jurosParcelas*valorEmprestimo)/(1- pow(1+jurosParcelas, -numParcelas));

    //Se o valor da parcela for menor ou igual a 10% da renda mensal, o empréstimo está aprovado.
    if(valorParcela<=rendaMensal*0.1)
        strcpy(resultadoEmprestimo,"Aprovado");

    //Se não, se o valor da parcela for maior que 30% da renda mensal, o empréstimo está reprovado.
    else if(valorParcela>rendaMensal*0.3)
        strcpy(resultadoEmprestimo,"Reprovado");

    //Se estiver entre 10% e 30% da renda mensal, é necessario pedir ao usuário novos dados.
    else
    {
        printf("O senhor(a) possue imovel proprio quitado? (1 - Sim ou 0 - Nao\n: ");
        scanf("%d",&imovelQuitado);
        if(imovelQuitado==0)
        {
            strcpy(resultadoEmprestimo,"Reprovado apos analise");
        }
        else
        {
            printf("O senhor(a) possue emprestimo anterior? (1 - Sim ou 0 - Nao\n: ");
            scanf("%d",&emprestimoAnterior);

            //Se o cliente não tiver empréstimo anterior, ele está aprovado após análise.
            if(emprestimoAnterior==0)
            {
                strcpy(resultadoEmprestimo,"Aprovado apos analise");
            }

            //Se ele possuir empréstimo anterior, é necessário saber se ele já pagou todas as parcelas pendentes.
            else
            {
                printf("Insira o numero de parcelas do emprestimo anterior (XX)\n: ");
                scanf("%d", &parcelaAnterior);

                printf("Insira o numero de parcelas pagas do emprestimo anterior (XX)\n: ");
                scanf("%d", &parcelaPagaAnterior);

                //Se ele não tiver quitado o empréstimo anterior, o empréstimo é reprovado após análise.
                if((parcelaAnterior-parcelaPagaAnterior!=0))
                    strcpy(resultadoEmprestimo,"Reprovado apos analise");

                //Já se ele tiver quitado o empréstimo anterior, é aprovado após análise.
                else
                    strcpy(resultadoEmprestimo,"Aprovado apos analise");
            }
        }
    }


    /*mostra as informações armazenadas ao usuario*/
    printf("\nDADOS REGISTRADOS\n\n");

    printf("Nome do Cliente\n");
    printf("\t%s\n", nomeCliente);

    printf("CPF\n");
    printf("\t%s\n", cpf);

    printf("Data de realizacao do emprestimo\n");
    printf("\t%d/%d/%d\n", dataEmprestimoDia, dataEmprestimoMes, dataEmprestimoAno);

    printf("Tipo do emprestimo : %d\n", tipoEmprestimo);
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

    printf("Status do Emprestimo\n");;
    printf("\t%s\n",resultadoEmprestimo);

    getch();

    return 0;
}
