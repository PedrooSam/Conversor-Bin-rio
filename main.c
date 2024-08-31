/*
1ª Questão:
Início 23/08 as 14h
Finalização 29/08 as 19h

2ª Questão:
Início 30/08 9h
Finalização 30/08 12h

3ª Questão:
Início 30/08 13h
Finalização 30/08 23h
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next;
}node;

typedef struct node2{
    float valor;
    struct node *next;
}node2;

void conveterBase(int base);
void converterCodigoBCD();
void ComplementoA2();
void converterFloat();
void converterDouble();

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
                ComplementoA2();
                
            }else if (opcao == 6){
                converterFloat();

            }else if (opcao == 7){
                converterDouble();
                
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


void ComplementoA2(void){
    system("cls");

    int complemento [16];
    int num, voltar;
    printf("Digite o número que deseja converter: ");
    scanf("%d", &num);

    if (num < 0){
        complemento[0] = 1;
    }else{
        complemento[0] = 0;
    }

    for (int i=15; i>0; i--){
        complemento[i] = num%2;
        num = num/2;

    }

    printf("\nPimeiro, convertemos o numero para binário,\no primeiro bit representa o sinal.\n\n");

    for (int i = 0; i < 16; i++){
        printf("%d", complemento[i]);
    }

    printf("\n\nDepois, invertemos os algarismos da direita para a esquerda a partir do primeiro 1\n\n");

    int aux;

    for (int i = 16; i > 0; i--){

        if (complemento[i] == 1){
            aux = i-1;
            break;
        }
        
    }
    
    for (int i = aux; i >= 0; i--){

        if (complemento[i] == 0){
            complemento[i] = 1;

        }else if (complemento[i] == 1){
            complemento[i] = 0;

        }
    }

    printf("Resultado: ");

    for (int i = 0; i < 16; i++){
        printf("%d", complemento[i]);
    }
    
    

    printf("\n\n[1]Voltar ");
    scanf("%d", &voltar);

    if (voltar == 1) return;

}


void converterFloat(void){

    system("cls");

    int sinal = 0;
    int expoente = 0;
    unsigned int mantissa = 0;
    int voltar;
    float num;
    printf("Digite o número que deseja converter: ");
    scanf("%f", &num);

    printf("\nO primeiro bit no número deve ser o de sinal\n");
    
    if (num < 0) {
        sinal = 1;
        num = -num;
        printf("Sinal: %d | Número positívo\n", sinal);
    
    }else{
        printf("Sinal: %d | Número negativo\n", sinal);
    }    
    
    int e = 0;
    while (num >= 2.0) {
        num /= 2.0;
        e++;
    }
    while (num < 1.0) {
        num *= 2.0;
        e--;
    }

    printf("\nDepois coloca-se o número em notação científica e pegamos o expoente");
    printf("\nNúmero: %f", num);
    printf("\nexpoente: %f\n", num);
    
    expoente = e + 127;
    num -= 1.0;

    printf("\nSe segue multiplicando o número por dois, a parte inteira será um bit da mantissa,");
    printf("despois subtrai um do número e repete o processo.\n");

    for (int i = 0; i < 23; i++) {
        num *= 2;
        if (num >= 1.0) {
            mantissa |= (1 << (22 - i));
            printf("\nNúmero: %f | Bit: %d", num, (int)num%10);
            num -= 1.0;
            continue;
        }

        printf("\nNúmero: %f | Bit: %d", num, (int)num%10);
        
    }
    
    printf("\n\nSinal: %d\n", sinal);
    
    printf("Expoente: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }
    printf("\n");
    
    printf("Mantissa: ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (mantissa >> i) & 1);
    }

    printf("\n\nResultado: ");

    printf("%d", sinal);
    
    for (int i = 7; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }

    for (int i = 22; i >= 0; i--) {
        printf("%d", (mantissa >> i) & 1);
    }

    
    printf("\n\n[1]Voltar ");
    scanf("%d", &voltar);

    if (voltar == 1) return;
        

}



void converterDouble(void){

    system("cls");

    int sinal = 0;
    int expoente = 0;
    unsigned long long int mantissa = 0;
    int voltar;
    double num;
    printf("Digite o número que deseja converter: ");
    scanf("%lf", &num);

    printf("\nO primeiro bit do número deve ser o de sinal\n");
    
    if (num < 0) {
        sinal = 1;
        num = -num;
        printf("Sinal: %d | Número negativo\n", sinal);
    
    }else{
        printf("Sinal: %d | Número positivo\n", sinal);
    }
    
    int e = 0;
    while (num >= 2.0) {
        num /= 2.0;
        e++;
    }
    while (num < 1.0) {
        num *= 2.0;
        e--;
    }

    printf("\nDepois coloca-se o número em notação científica e pegamos o expoente");
    printf("\nNúmero: %lf", num);
    printf("\nExpoente: %d\n", e);
    
    expoente = e + 1023;
    num -= 1.0;

    printf("\nSe segue multiplicando o número por dois, a parte inteira será um bit da mantissa,");
    printf("despois subtrai um do número e repete o processo.\n");

    for (int i = 0; i < 52; i++) {
        num *= 2;
        if (num >= 1.0) {
            mantissa |= (1ULL << (51 - i));
            printf("\nNúmero: %lf | Bit: %d", num, (int)num%10);
            num -= 1.0;
            continue;
        }

        printf("\nNúmero: %lf | Bit: %d", num, (int)num%10);
        
    }
    
    printf("\n\nSinal: %d\n", sinal);
    
    printf("Expoente: ");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }
    printf("\n");
    
    printf("Mantissa: ");
    for (int i = 51; i >= 0; i--) {
        printf("%d", (mantissa >> i) & 1);
    }

    printf("\n\nResultado: ");

    printf("%d", sinal);
    
    for (int i = 10; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }

    for (int i = 51; i >= 0; i--) {
        printf("%d", (mantissa >> i) & 1);
    }

    
    printf("\n\n[1]Voltar ");
    scanf("%d", &voltar);

    if (voltar == 1) return;

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