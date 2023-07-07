#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"

int main(void) {

    //declaração das variáveis

    //opcao é a opção selecionada do menu, lin é a linha situada na matriz, col é a coluna situada na matriz,
    //brilho é o valor desejado para aumentar/diminuir o brilho da imagem, limite é o valor a ser comparado na redução de ruídos
    //media é a média calculada para a redução de ruídos, aux_lin é um auxiliar para a linha, aux_col é um auxiliar para a coluna,
    //diferenca é a diferença calculada para a redução de ruídos e tam_opcao é o tamanho da string opcao

    char opcao[4];
    int lin=0, col=0, brilho=0, limite=0, media=0, aux_lin=0, aux_col=0, diferenca=0, tam_opcao=0;

    //mensagem de apresentação
    printf("\n\t======================================================================================================"
           "\n\t\t\t\t\t\t\tIMad Edits"
           "\n\t======================================================================================================\n");
    printf("\n\tOla! Seja bem-vindx ao nosso programa de edicoes de imagem!");
    printf("\n\tNo menu a seguir, voce pode escolher, de acordo com a numeracao, a alteracao que deseja fazer.\n");
    printf("\n\tO que voce deseja fazer com a imagem?\n\n");

    do {

        //menu e suas opções
        printf("\t| 1. Rotacao de 90 graus\n"
               "\t| 2. Rotacao de -90 graus\n"
               "\t| 3. Inversao horizontal\n"
               "\t| 4. Inversao vertical\n"
               "\t| 5. Negativo\n"
               "\t| 6. Aumento de brilho\n"
               "\t| 7. Diminuicao de brilho\n"
               "\t| 8. Deteccao e reducao de ruidos 2D e 3D\n"
               "\t| 0. Encerrar\n");


        //recebe o valor de opcao
        printf("\n\tOpcao: ");
        scanf("%[^\n]%*c", &opcao);

        //validação para opcao
        do {
            //determinar o tamanho da string
            for (tam_opcao=0;opcao[tam_opcao]!='\0';tam_opcao++);

            //testa se a string possui mais de um caractere
            if (tam_opcao>1) {
                //se sim, ele informa a invalidez da opcao e pede novamente
                printf("\n\tOpa, valor invalido para opcao! Digite novamente... \n");
                scanf("%[^\n]%*c", &opcao);
            }

        } while (tam_opcao!=1);

        printf("\n========================================================================================================================\n");

        //acesso às opções do menu
        switch (opcao[0]) {

            //sair do menu
            case '0':
                printf("\n\tMuito obrigadx por utilizar nosso programa! Ate mais :)\n");
                break;

            //rotacionar a imagem 90 graus (sentido horário)
            case '1':
            {
                printf("\n");
                abrir_imagem();
                int nova_imagem[nlin][ncol];

                //realocação dos elementos de imagem em nova_imagem
                for(lin = 0 ; lin < nlin ; lin++) {
                    for(col = 0 ; col < ncol ; col++) {
                        nova_imagem[lin][col] = imagem[lin][col];
                    }
                }

                //reorganização dos elementos, seguindo o sentido horário
                for (lin = 0 ; lin < nlin ; lin++) {
                    for (col = 0 ; col < ncol ; col++) {
                        int nova_lin = col;
                        int nova_col =  nlin - lin - 1;
                        imagem[nova_lin][nova_col] = nova_imagem[lin][col];
                    }
                }

                fechar_imagem();
                printf("\tImagem alterada com sucesso!\n\n");

                //limpeza do conteúdo da tela
                printf("\tPressione ENTER para continuar ");
                scanf("%*c");
                system("clear||cls");

                break;
            }

            //rotacionar a imagem -90 graus (sentido anti-horário)
            case '2':
            {
                printf("\n");
                abrir_imagem();
                int nova_imagem[nlin][ncol];

                //realocação dos elementos de imagem em nova_imagem
                for(lin = 0 ; lin < nlin ; lin++) {
                    for(col = 0 ; col < ncol ; col++) {
                        nova_imagem[lin][col] = imagem[lin][col];
                    }
                }

                //reorganização dos elementos, seguindo o sentido anti-horário
                for (lin = 0 ; lin < nlin ; lin++) {
                    for (col = 0 ; col < ncol ; col++) {
                        int nova_lin = ncol - col - 1;
                        int nova_col =  lin;
                        imagem[nova_lin][nova_col] = nova_imagem[lin][col];
                    }
                }

                fechar_imagem();
                printf("\tImagem alterada com sucesso!\n\n");

                //limpeza do conteúdo da tela
                printf("\tPressione ENTER para continuar ");
                scanf("%*c");
                system("clear||cls");

                break;
            }

            //inverter a imagem horizontalmente
            case '3':
            {
                printf("\n");
                abrir_imagem();

                //realização da troca de valores de um elemento
                //pelo outro com o auxílio da variável aux
                for (lin = 0 ; lin < nlin - 1 ; lin++) {
                    for(col = 0 ; col < ncol/2 ; col++) {
                        int aux = imagem[lin][col];
                        imagem[lin][col] = imagem[lin][ncol-col-1];
                        imagem[lin][ncol-col-1] = aux;
                    }
                }

                fechar_imagem();
                printf("\tImagem alterada com sucesso!\n\n");

                //limpeza do conteúdo da tela
                printf("\tPressione ENTER para continuar ");
                scanf("%*c");
                system("clear||cls");

                break;
            }

            //inverter a imagem verticalmente
            case '4':
            {
                printf("\n");
                abrir_imagem();

                //realização da troca de valores de um elemento
                //pelo outro com o auxílio da variável aux
                for(lin = 0 ; lin < nlin/2 ; lin++) {
                    for(col = 0 ; col < ncol ; col++) {
                        int aux = imagem[lin][col];
                        imagem[lin][col] = imagem[nlin-lin-1][col];
                        imagem[nlin-lin-1][col] = aux;
                    }
                }

                fechar_imagem();
                printf("\tImagem alterada com sucesso!\n\n");

                //limpeza do conteúdo da tela
                printf("\tPressione ENTER para continuar ");
                scanf("%*c");
                system("clear||cls");

                break;
            }

            //tornar a imagem negativa
            case '5':
            {
                printf("\n");
                abrir_imagem();

                //realiza a subtração do valor que se encontra naquela posição da imagem,
                //encontrando o seu complemento na escala
                for(lin = 0 ; lin < nlin ; lin++) {
                    for(col = 0 ; col < ncol ; col++) {
                        imagem[lin][col] = 255 - imagem[lin][col];
                    }
                }

                fechar_imagem();
                printf("\tImagem alterada com sucesso!\n\n");

                //limpeza do conteúdo da tela
                printf("\tPressione ENTER para continuar ");
                scanf("%*c");
                system("clear||cls");

                break;
            }

            //aumentar o brilho da imagem
            case '6':
            {
                printf("\n");
                abrir_imagem();

                //recebe o valor de brilho
                printf("\n\tQual eh o valor de aumento do brilho? ");

                //validação do valor de brilho (se é um caracter)
                int validacao=1;
                do {
                    validacao=scanf("%d", &brilho);
                    scanf("%*c");
                    if (validacao==0) {
                        printf("\n\tOpa, valor invalido para brilho! Digite novamente... \n");
                    }
                } while (validacao==0);

                //validação do valor de brilho (se respeita o intervalo de valores válidos)
                while (brilho < 0 || brilho > 255) {
                    printf("\n\tValor invalido! Digite um valor entre 0 e 255: ");
                    scanf("%d%*c", &brilho);
                }

                //trecho para aumento de brilho
                for(lin = 0 ; lin < nlin ; lin++) {
                    for(col = 0 ; col < ncol ; col++) {

                        //adiciona o valor de brilho ao valor do elemento atual
                        imagem[lin][col] = imagem[lin][col] + brilho;

                        //testa se o valor vai passar do limite máximo de 255 e, se sim, mantém como 255
                        if(imagem[lin][col] > 255) {
                            imagem[lin][col] = 255;
                        }
                        //testa se o valor vai passar do limite mínimo de 0 e, se sim, mantém como 0
                        else if(imagem[lin][col] < 0) {
                            imagem[lin][col] = 0;
                        }
                    }
                }

                fechar_imagem();
                printf("\tImagem alterada com sucesso!\n\n");

                //limpeza do conteúdo da tela
                printf("\tPressione ENTER para continuar ");
                scanf("%*c");
                system("clear||cls");

                break;
            }

            //diminuir o brilho da imagem
            case '7':
            {
                printf("\n");
                abrir_imagem();

                //recebe o valor de brilho
                printf("\n\tQual eh o valor de diminuicao do brilho? ");

                //validação do valor de brilho (se é um caracter)
                int validacao=1;

                do {
                    validacao=scanf("%d", &brilho);
                    scanf("%*c");
                    if (validacao==0) {
                        printf("\n\tOpa, valor invalido para brilho! Digite novamente... \n");
                    }
                } while (validacao==0);

                //validação do valor de brilho (se respeita o intervalo de valores válidos)
                while (brilho < -255 || brilho > 0) {
                    printf("\n\tValor invalido! Digite um valor entre -255 e 0: ");
                    scanf("%d%*c", &brilho);
                }

                //trecho para diminuição de brilho
                for(lin = 0 ; lin < nlin ; lin++) {
                    for(col = 0 ; col < ncol ; col++) {

                        //adiciona o valor de brilho ao valor do elemento atual
                        imagem[lin][col] = imagem[lin][col] + brilho;

                        //testa se o valor vai passar do limite máximo de 255 e mantém como 255
                        if(imagem[lin][col] > 255) {
                            imagem[lin][col] = 255;
                        }
                        //testa se o valor vai passar do limite mínimo de 0 e mantém como 0
                        else if(imagem[lin][col] < 0) {
                            imagem[lin][col] = 0;
                        }
                    }
                }

                fechar_imagem();
                printf("\tImagem alterada com sucesso!\n\n");

                //limpeza do conteúdo da tela
                printf("\tPressione ENTER para continuar ");
                scanf("%*c");
                system("clear||cls");

                break;
            }

            //detectar e reduzir ruídos 2D e 3D
            case '8':
            {
                printf("\n");
                abrir_imagem();

                //recebimento do valor limite de ruído
                printf("\tDigite o limite para ruido na imagem: ");

                //validação do valor de limite (se é um caracter)
                int validacao=1;

                do {
                    validacao=scanf("%d", &limite);
                    scanf("%*c");
                    if (validacao==0) {
                        printf("\n\tOpa, valor invalido para o limite! Digite novamente... \n");
                    }
                } while (validacao==0);

                //validação do valor limite de ruído (0 a 255)
                while (limite < 0 || limite > 255) {
                    printf("\tValor invalido para o limite. Digite novamente: ");
                    scanf("%d%*c", &limite);
                }

                for (lin = 0 ; lin < nlin ; lin++) {
                    for (col = 0 ; col < ncol ; col++) {
                        if(lin > 0 && lin < 255 && col > 0 && col < 255){
                            media = ((imagem[lin-1][col-1]) +
                                     (imagem[lin-1][col]) +
                                     (imagem[lin-1][col+1]) +
                                     (imagem[lin][col-1]) +
                                     (imagem[lin][col+1]) +
                                     (imagem[lin+1][col-1]) +
                                     (imagem[lin+1][col]) +
                                     (imagem[lin+1][col+1])) / 8;

                        }
                        //testagem para as extremidades do vértice
                        else if(lin == 0 && col == 0 ||
                                lin == 0 && col == 255 ||
                                lin == 255 && col == 0 ||
                                lin == 255 && col == 255) {

                            if(lin == 0) {
                                aux_lin = lin + 1;
                            }
                                else if(lin == 255){
                                    aux_lin = lin - 1;
                                }

                            if(col == 0){
                                aux_col = col + 1;
                            }
                                else if(col == 255){
                                    aux_col = col - 1;
                                }

                            media = ((imagem[aux_lin][col]) +
                                     (imagem[lin][aux_col]) +
                                     (imagem[aux_lin][aux_col])) / 3;
                        }
                        //testagem para as outras extremidades
                        else {
                            if(lin == 0){
                                media = ((imagem[lin + 1][col])+
                                         (imagem[lin + 1][col + 1])+
                                         (imagem[lin + 1][col - 1])+
                                         (imagem[lin][col + 1])+
                                         (imagem[lin][col - 1])) / 5;
                            }
                            else {
                                media = ((imagem[lin - 1][col]) +
                                         (imagem[lin - 1][col + 1])+
                                         (imagem[lin - 1][col - 1])+
                                         (imagem[lin][col + 1])+
                                         (imagem[lin][col - 1])) / 5;
                            }

                            if(col == 0){
                                media = ((imagem[lin][col + 1])+
                                         (imagem[lin + 1][col + 1])+
                                         (imagem[lin - 1][col + 1])+
                                         (imagem[lin + 1][col])+
                                         (imagem[lin - 1][col])) / 5;
                            }
                            else if(col == 255){
                                media = ((imagem[lin][col - 1])+
                                         (imagem[lin + 1][col - 1])+
                                         (imagem[lin - 1][col - 1])+
                                         (imagem[lin + 1][col])+
                                         (imagem[lin - 1][col])) / 5;
                            }
                        }

                        //Verificar se existe ruido, pela comparação com o limite,
                        // e, se sim, a correção é feita
                        diferenca = media - imagem[lin][col];
                        diferenca = (diferenca < 0) ? diferenca * -1: diferenca;
                        if(diferenca > limite){
                            imagem[lin][col] = media;
                        }
                    }
                }

                fechar_imagem();
                printf("\n\tImagem alterada com sucesso!\n\n");

                //limpeza do conteúdo da tela
                printf("\tPressione ENTER para continuar ");
                scanf("%*c");
                system("clear||cls");

                break;
            }

            default:
                printf("\n\tOpa, valor invalido para opcao! Escolha novamente... \n");
                break;
        }

        if (opcao[0]!='0') {
            printf("\n\tDeseja realizar mais alguma alteracao?\n\n");
        }

    } while(opcao[0]!='0');

    return 0;
}
