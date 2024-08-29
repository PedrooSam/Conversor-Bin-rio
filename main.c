#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next;
}node;

void conveterBase(int base);
void converterCodigoBCD();
void funcao_5();
void funcao_6();
void funcao_7();

void adicionarAlgarismo(node **head, int num);
void printLista(node *head);
void liberarLista(node **head);


int main (void){

    while (1){
    
        system("cls");
        printf("-----Calculadora de Conversão-----\n");
        printf("\n[1]Base 10 para base 2\n[2]Base 10 para base 8\n[3]base 10 para base 16\n[4]base 10 para código BCD\n");
        printf("[5]Base 10 para base 2 16bits com sinal/complemento a 2\n");
        printf("[6]Real em decimal para float\n");
        printf("[7]Real em decimal para double\n");
        printf("[8]Sair\n");
        printf("\nDigite a opção desejada: ");

        int opcao;
        scanf("%d", &opcao);
        printf("\n");

            if (opcao == 1){
                conveterBase(2);

            }else if (opcao == 2){
                conveterBase(8);

            }else if (opcao == 3){
                conveterBase(16);

            }else if (opcao == 4){
                converterCodigoBCD();

            }else if (opcao == 5){
                funcao_5();
                
            }else if (opcao == 6){
                funcao_6();

            }else if (opcao == 7){
                funcao_7();
                
            }else{
                break;
            }

    }
    return 0;
}


//=============================================


void conveterBase(int base){
    system("cls");

    printf("=====Converter Decimal para Base %d=====\n", base);

    int num, voltar;
    printf("\nDigite o número que deseja converter: ");
    scanf("%d", &num);
    printf("\n");
    printf("Para converter um numero de decimal para base %d,  é necessário", base);
    printf("\ndividi-lo por %d e pegar o seu resto, ate que sobre 0.", base);
    printf("\nA resposta é encontrada de tras pra frente.\n");

    node *head = NULL;

    while (num != 0){
        adicionarAlgarismo(&head, num%base);
        printf("\n%d / %d = %d | resto: %d", num, base, num/base, num%base);
        num = num/base;

    }
    
    if (base == 16)printf("\n\nOs dígitos acima de 9 são convertidos para letras em ordem alfabética.");    

    printLista(head);
    liberarLista(&head);

    printf("\n\n[1]Voltar ");
    scanf("%d", &voltar);

    if (voltar == 1) return;

}


void converterCodigoBCD(void){
    system("cls");

    int num, voltar, cont = 0;

    printf("Digite o número que deseja converter: ");
    scanf("%d", &num);

    int numero = num;

    if (num == 0){
        cont = 1;
    }

    while (numero > 0){
        cont++;
        numero/=10;
    }

    numero = num;
    int lista[cont];

    for (int i = cont - 1; i >= 0; i--) {
        lista[i] = numero % 10;
        numero /= 10;
    }
    
    printf("\nNo código BCD, cada algarismo é convertido individualmente\n\n");

    for (int i = 0; i<cont; i++){

        int algarismo = lista[i];
        
        if (algarismo == 0){
            printf("0000 -> 0\n");
        }else if (algarismo == 1){
            printf("0001 -> 1\n");
        }else if (algarismo == 2){
            printf("0010 -> 2\n");
        }else if (algarismo == 3){
            printf("0011 -> 3\n");
        }else if (algarismo == 4){
            printf("0100 -> 4\n");
        }else if (algarismo == 5){
            printf("0101 -> 5\n");
        }else if (algarismo == 6){
            printf("0110 -> 6\n");
        }else if (algarismo == 7){
            printf("0111 -> 7\n");
        }else if (algarismo == 8){
            printf("1000 -> 8\n");
        }else if (algarismo == 9){
            printf("1001 -> 9\n");
        }
    }

    printf("\nResultado:");
    
    for (int i = 0; i<cont; i++){

        int algarismo = lista[i];
        
        if (algarismo == 0){
            printf("0000 ");
        }else if (algarismo == 1){
            printf("0001 ");
        }else if (algarismo == 2){
            printf("0010 ");
        }else if (algarismo == 3){
            printf("0011 ");
        }else if (algarismo == 4){
            printf("0100 ");
        }else if (algarismo == 5){
            printf("0101 ");
        }else if (algarismo == 6){
            printf("0110 ");
        }else if (algarismo == 7){
            printf("0111 ");
        }else if (algarismo == 8){
            printf("1000 ");
        }else if (algarismo == 9){
            printf("1001 ");
        }
    }

    printf("\n\n[1]Voltar ");
    scanf("%d", &voltar);

    if (voltar == 1) return;

}


void funcao_5(void){
    system("cls");

    int num;
    printf("Digite o número que deseja converter: ");
    scanf("%d\n", &num);

    

}


void funcao_6(void){
    system("cls");

    int num;
    printf("Digite o número que deseja converter: ");
    scanf("%d\n", &num);

    

}


void funcao_7(void){
    system("cls");

    int num;
    printf("Digite o número que deseja converter: ");
    scanf("%d\n", &num);

    

}


//=============================================


void adicionarAlgarismo(node **head, int num){

    node *novo = (node*)malloc(sizeof(node));
    printf("%d\n", num);

    if(novo){
        novo->valor = num;
        novo->next = *head;

        *head = novo;
    }
}


void printLista(node *head){

    int numeros[6] = {10, 11, 12, 13, 14, 15};
    char letras[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

    printf("\n\n");
    printf("Resultado: ");

    while (head != NULL){

        int letra = 0;

        for (int i = 0; i < 6; i++){

            if (head->valor == numeros[i]){

                printf("%c", letras[i]);
                letra = 1;
                break;

            }
            
        }
        
        if (!letra) printf("%d", head->valor);        
        
        head = head->next;

    }

    return;
}


void liberarLista(node **head){
    while (*head != NULL){

        node *aux = *head;

        *head = (*head)->next;
        free(aux);

    }

    return;

}