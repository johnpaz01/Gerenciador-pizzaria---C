#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
/* Um sistema de gerenciamaneto de pizzaria...*/
typedef struct {
    int codigo_pizza;
    char nome_pizza[MAX];
    float valor;
} Pizza;

typedef struct {
    int numero_pedido;
    int telefone_entregador;
    int codigo_pedido;
    int codigo_entregador;
    char situacao[MAX];
    int codigo_pizza;
    int numero_cliente;
    int verifica;
} Pedido;

typedef struct {
    int telefone;
    char nome[MAX];
    int cep;
    char endereco[MAX];
    char complemento[MAX];
    int numero;
} Cliente;

enum{cadastrocliente=1, cadastropizza, cadastropedido, despacho, confirmarentrega, verpedido, sair=0 };

/* aqui auma fun��o menu onde eu leio as op��es disponiveis para o usu�rio*/
void menu(int *op) {
    printf("\n*** Pizzaria Ketchup ***\n");
        printf("1. cadastrar clientes\n2. cadastrar pizzas\n");
            printf("3. novos pedidos\n4. pedido para despacho\n");
                printf("5. confirmar entegua\n6. ver pedidos entregues\n0. Sair\n--->");
                    scanf("%d", op);
}

/* nesse bloco de cadastro eu juro que tentei bastante, mas eu tive que pesquisar
como fazia por que tava dando waring em tudo que é lugar
e o erro era que eu estava passando a 
estrutura errado, mas eu consegui corrijir e os cadastros estão funcionando certinho

#outro ponto é que eu usei valores aleatorios para serem ditos na entrega, como
codigo do motoboy e afins*/

void cadastro_cliente(Cliente *ptr, int i) {
printf("*** Cadastro de clientes ***\n\n");
    printf("Telefone para contato do cliente %d: ", i + 1);
        scanf("%d", &ptr->telefone);
            printf("Nome do cliente %d: ", i + 1);
                getchar();
                    fgets(ptr->nome, MAX, stdin);
                        printf("CEP do cliente %d: ", i + 1);
                            scanf("%d", &ptr->cep);
    printf("informe o nome da rua do cliente %d: ", i + 1);
        getchar();
            fgets(ptr->endereco, MAX, stdin);
                    printf("informe o numero da casa do cliente %d: ", i + 1);
                        scanf("%d", &ptr->numero); 
                            printf("Complemento: ");
                                getchar();
                                    fgets(ptr->complemento, MAX, stdin);
                                        printf("Cliente cadastrado: [V]\n");
}

void nova_pizza(Pizza *ptr, int i) {
    printf("\n*** Cadastro Pizza ***\n");
        printf("\ninforme o codigo da pizza %d: ", i + 1);
          getchar();
            scanf("%d", &ptr->codigo_pizza);
                printf("Nome da pizza %d: ", i + 1);
                    getchar();
                        fgets(ptr->nome_pizza, MAX, stdin);
    printf("Valor da pizza %d: ", i + 1);
        scanf("%f", &ptr->valor);
            printf("\nPizza cadastrada com sucesso!\n");
}

void pedidos(Pedido *ptr, int i) {
    printf("*** Novo pedido ***\n");
     printf("Telefone do cliente %d: ", i + 1);
         scanf("%d", &ptr->numero_cliente);
            ptr->codigo_pedido = rand() % 99 + 100;
                 ptr->codigo_entregador = rand() % 99 + 100;
                    strcpy(ptr->situacao, "Preparando");
                        printf("\nDigite o codigo da pizza: ");
                         scanf("%d", &ptr->codigo_pizza);
                             printf("\nNumero do pedido: [%d]", i + 1);
                                printf("\nCodigo do pedido: %d", ptr->codigo_pedido);
                                    printf("\nCodigo entregador: Ainda nao ha um entregador disponivel");
                                         printf("\nSituacao do pedido: %s", ptr->situacao);
}


/* aqui estao os codigos de despacho etc, não tem muito oque falar, eles pedem o telefone do cliente ante no
momento de fazer o pedido, então so modifico as variaveis nescessaria normalmente*/
void despacho_pizza(Pedido *ptr, int num_pedidos) {
    int codigo;
    int i = 0;
    
    printf("Digite o codigo do pedido que deseja alterar: ");
        scanf("%d", &codigo);
    while (i < num_pedidos && codigo != ptr[i].codigo_pedido) {
        i++;
}
    if (i < num_pedidos) {
printf("\nDigite o telefone do entregador: ");
  scanf("%d", &ptr[i].telefone_entregador);
        strcpy(ptr[i].situacao, "A caminho...");
                printf("\nCodigo do pedido: %d", ptr[i].codigo_pedido);
                    printf("\nCodigo entregador: %d", ptr[i].codigo_entregador);
                        printf("\nCodigo da pizza: %d", ptr[i].codigo_pizza);
                            printf("\nSituacao do pedido: %s", ptr[i].situacao);

} else {
    printf("Pedido nao encontrado:[X]\n");
    }
}

/* aqui eu usei para saber se o pedido foi entregue um comparador presente na struct logo modificado na função
anterior*/
void pedido_entregue(Pedido *ptr, int num_pedidos){
    int codigo;
    int i = 0;   
    printf("Digite o numero do codigo do pedido que deseja alterar: ");
    scanf("%d", &codigo);    
    while (i < num_pedidos && codigo != ptr[i].codigo_pedido) {
        i++;
    }
if (i < num_pedidos) {
    strcpy(ptr[i].situacao, "Pedido entregue");
        printf("\nCodigo do pedido: %d", ptr[i].codigo_pedido);
           printf("\nCodigo entregador: %d", ptr[i].codigo_entregador);
               printf("\nCodigo da pizza: %d", ptr[i].codigo_pizza);
                   printf("\nSituacao do pedido: %s", ptr[i].situacao);
                   ptr[i].verifica=1;
} else {
    printf("Pedido nao encontrado.\n");
    }
}

void mostra_pedidos(int num_pedido, Pedido *ptr,Cliente *ptr2){
int i, j=0;
for (i=0;i<num_pedido;i++){
    if(ptr[i].verifica==1){
        printf("Codigo do pedido: %d", ptr[i].codigo_pedido);
           printf("\nCodigo entregador: %d", ptr[i].codigo_entregador);
               printf("\nCodigo da pizza: %d", ptr[i].codigo_pizza);
                   printf("\nSituacao do pedido: %s", ptr[i].situacao);
                      j++;
        if(ptr[i].numero_cliente==ptr2[i].telefone){
            printf("\nNumero do cliente: %d", ptr2[i].telefone);
                printf("\nNome do cliente: %s", ptr2[i].nome);
                    printf("\nCEP do cliente: %d", ptr2[i].cep);
                        printf("\nEndereco do cliente: %s", ptr2[i].endereco);
                            printf("\nComplemento do cliente: %s", ptr2[i].complemento);
                                printf("\nNumero do cliente: %d", ptr2[i].numero);
                                printf("\n------\n");
        }
    }  
}
getchar();
printf("\nTotal de pedidos entregues: %d", j);
}

int main() {
int clientes_cadastrados = 0;
int pizza_cadastrada = 0;
int pedidos_andamento = 0;
int op = 1;
Pizza pizza[MAX];
Pedido pedido[MAX];
Cliente cliente[MAX];
/* não tinha muito oque fazer na main so ess swtchi case que utiliza a enum cadastrada la atras
e esse programa nao caucula nada de valor ja que nao foi pedido!*/
while (op != 0) {
    menu(&op);
 switch(op){
case cadastrocliente:
    cadastro_cliente(&cliente[clientes_cadastrados], clientes_cadastrados);
        clientes_cadastrados++;
            break;

case cadastropizza:
    nova_pizza(&pizza[pizza_cadastrada], pizza_cadastrada);
        pizza_cadastrada++;
            break;
case cadastropedido:
    pedidos(&pedido[pedidos_andamento], pedidos_andamento);
        pedidos_andamento++;
            break;

case despacho:
    despacho_pizza(pedido, pedidos_andamento);
        break;
case confirmarentrega: 
    pedido_entregue(pedido, pedidos_andamento);
        break;
case verpedido:
    mostra_pedidos(pedidos_andamento, pedido,cliente);
    break;
case sair:
    printf("Saindo...\n");
        break;
default:
     printf("Opcao invalida!\n");
             break;
        }
    }
    return 0;
}
