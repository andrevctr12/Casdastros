//
//              Trabalho de Arquivos
//
//   André Victor Teixeira Lopes / 201411640020
//   Elizane Ferraz             / 201411640022
//   Larissa Roman Françoso    / 201411640013
//
//

#include <stdio.h>
#include <stdlib.h>


#define MAXREG 4
#define TAM1 50
#define TAM2 100
#define TAM3 300
#define TAM4 500


long int total;
int cont;
int contSair;
int contArq;
int i, j;
int contPacientes = 0;
int contMedicos = 0;
int contDoencas = 0;

//MARCAS

int marca1 = 0;
int marca3;
int marca4 = 0;

//REGISTROS

//doenca1()
struct reg1 {
    int codID, nivel;
    char nomeDoenca[TAM1], descricao[TAM4];
};

//sintoma2()
struct reg2 {
    int codID, nivel;
    char descricao[TAM4];
};

//medico3()
typedef struct {
    char rua[TAM2], bairro[TAM1], cidade[TAM1], estado[TAM1], CEP[9];
    int numero;
}reg03;

struct reg3 {
    int CRM, codPaciente[MAXREG];
    char nomeMedico[TAM2], nomePacientes[TAM2], CPF[15], telefone[20];
    reg03 endereco;
};

//paciente4()
typedef struct {

    char medicamento[TAM3], agentes[TAM3], ambiente[TAM3], outros[TAM3];

}reg04;

typedef struct {
    char rua[TAM2], bairro[TAM1], cidade[TAM2], estado[TAM1], CEP[9];
    int numero;
}reg14;

struct reg4 {
    int idade, codPaciente;
    char nomePaciente[TAM2], genero, predGenetica[TAM3], exames[TAM3],resultados[TAM3];
    char CPF[15], telefone[20];
    reg04 risco;
    reg14 endereco;
};

//tratamento5()
struct reg5 {
    int codID, codDoenca, codPaciente, codMedico;
    float valorConsulta, valorExame;
    char tempoObs[5], tempoInter[5], resp;
};

//medicamento6()
struct reg6 {
    int codID, faixa_etaria;
    char nome_medicamento[20], indicacao[20], posologia[30], contra_indicacao[20];
    float valor;
};


//exame7()
struct reg7 {
    int cod_exame, pgto;
    char nome_exame[20];
};


//DECLARAÇÃO DE REGISTROS

struct reg1 doencas[MAXREG];
struct reg2 sintomas[MAXREG];
struct reg3 medicos[MAXREG];
struct reg4 pacientes[MAXREG];
struct reg5 tratamentos[MAXREG];
struct reg6 medicamentos[MAXREG];
struct reg7 exames[MAXREG];


//TAMANHO DE REGISTROS

int REG1 = sizeof (struct reg1);
int REG2 = sizeof (struct reg2);
int REG3 = sizeof (struct reg3);
int REG4 = sizeof (struct reg4);
int REG5 = sizeof (struct reg5);
int REG6 = sizeof (struct reg6);
int REG7 = sizeof (struct reg7);


//PROTÓTIPO DE FUNÇÕES

void sair();
int doenca1();
int sintoma2();
int medico3();
int paciente4();
int tratamento5();
int medicamento6();
int exame7();
void listaPacientes();

//ARQUIVOS

FILE *doencaBin;
FILE *sintomaBin;
FILE *medicoBin;
FILE *pacienteBin;
FILE *tratamentoBin;
FILE *medicamentoBin;
FILE *exameBin;

int main() {

    int op;

    do {
        printf("\nEscolha a opcao desejada:\n");
        printf("1. Cadastrar doenças\n");
        printf("2. Cadastrar sintomas\n");
        printf("3. Cadastrar médicos\n");
        printf("4. Cadastrar pacientes\n");
        printf("5. Cadastrar tratamentos\n");
        printf("6. Cadastrar medicamentos\n");
        printf("7. Cadastrar exames\n");



        printf("9. Sair\n\n> ");

        scanf(" %d",&op);

        switch (op) {
            case 1:
                doenca1();
                marca1 = 1;
                break;
            case 2:
                sintoma2();
                break;
            case 3:
                if (marca4 == 0) {
                    printf("Você não tem nenhum paciente cadastrado. Cadastre para continuar!\n\n");
                    paciente4();
                    marca4 = 1;
                    medico3();
                }
                else {
                    medico3();
                    marca3 = 1;
                }
                break;
            case 4:
                paciente4();
                marca4 = 1;
                break;
            case 5:
                if (marca1 == 0) {

                    printf("Você não tem nenhuma doença cadastrada. Cadastre para continuar!\n\n");

                    doenca1();
                    marca1 = 1;
                    tratamento5();

                }
                else if (marca4 == 0) {
                    printf("Você não tem nenhum paciente cadastrado. Cadastre para continuar!\n\n");
                    paciente4();
                    marca4 = 1;
                    tratamento5();
                }
                else
                    tratamento5();
                break;
            case 6:
                medicamento6();
                break;
            case 7:
                exame7();
                break;
            case 8:
                listaPacientes();
                break;
            default:
                if (op != 9)
                    printf("Opcao invalida!\n\n");
                break;
        }
    } while (op != 9);



    return 0;
}



void listaPacientes() {

    cont = 0;

    pacienteBin = fopen("paciente4.dat", "rb");

    while (cont < MAXREG && fread(&pacientes[cont], REG4, 1, pacienteBin) == 1) {

        if (cont == 0)

            puts("Lista de Pacientes:");


        printf("%d - %s, %d anos\n",cont + 1, pacientes[cont].nomePaciente, pacientes[cont].idade);



        cont++;

    }

    fclose(pacienteBin);


}




void sair() {
    char ok;
    printf("Você deseja sair deste cadastramento? (S/N)\n");
    scanf(" %c",&ok);
    if (ok == 'S' || ok == 's')
        cont = MAXREG;

}



void limparBuffer() {

    char c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }

}



int doenca1() {


    for(i = contDoencas; i < MAXREG; i++) {
        doencas[i].codID = i + 1;
        printf("Codigo de identificacao: %d \n",doencas[i].codID);

        printf("Informe o nome da doenca:\n");
        gets(doencas[i].nomeDoenca);
        limparBuffer();
        printf("Descreva a doenca \n");
        gets(doencas[i].descricao);

        do {

            printf("Informe o nivel de seriedade da doenca\n");
            printf("1. Baixo \n2. Medio \n3. Alto \n");
            scanf("%d",&doencas[i].nivel);


            switch (doencas[i].nivel) {
                case 1:
                    printf("Baixo\n");
                    break;
                case 2:
                    printf("Medio\n");
                    break;
                case 3:
                    printf("Alto\n");
                    break;
                default:
                    printf("Opcao invalida\n");
            }

        } while (doencas[i].nivel <= 0 || doencas[i].nivel > 3);



        contDoencas += 1;

        sair();
        limparBuffer();
    }
    return 0;
}



int sintoma2() {

    cont = 0;

    sintomaBin = fopen("sintoma2.dat","a+b");

    if (sintomaBin == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        getchar();
        return 1;
    }

    rewind(sintomaBin);

    while (cont < MAXREG && fread(&sintomas[cont], REG2, 1, sintomaBin) == 1) {

        if (cont == 0)

            puts("Atuais Sintomas Cadastrados:");


        printf("CodID: %d\nNivel: %d\nDescricao:%s\n",sintomas[cont].codID, sintomas[cont].nivel, sintomas[cont].descricao);



        cont++;

    }

    //o que vai ficar realmente

    printf("Cadastrados [%d] registros de sintomas.\n", cont);

    contArq = cont;

    if (cont == MAXREG) {

        fputs("O Registro está cheio.\n", stderr);

        return 2;

    }

    limparBuffer();



    while (cont < MAXREG) {

        sintomas[cont].codID = cont + 1;
        printf("Codigo de identificacao: %d\n",sintomas[cont].codID);
        puts("Descreva os Sintomas:");
        gets(sintomas[cont].descricao);

        printf("Informe o nivel de severidade da doenca:\n");


        do {

            printf("1. Baixo \n2. Medio \n3. Alto \n");
            scanf("%d",&sintomas[cont].nivel);

            switch (sintomas[cont].nivel) {
                case 1:
                    printf("Baixo\n\n");
                    break;
                case 2:
                    printf("Medio\n\n");
                    break;
                case 3:
                    printf("Alto\n\n");
                    break;
                default:
                    printf("Opcao invalida\n\n");
            }

        } while (sintomas[cont].nivel <= 0 || sintomas[cont].nivel > 3);



        cont++;
        contSair = cont;

        if (cont != MAXREG)

            sair();

        limparBuffer();

    }

    cont = contSair;

    if (cont > 0) {

        //preciso pra alguma coisa talvez
        puts("Lista de Sintomas cadastrados:");

        for (i = 0; i < cont; i++)

            printf("CodID: %d\n%d\nDescricao:%s\n",sintomas[i].codID, sintomas[i].nivel, sintomas[i].descricao);

        total = fwrite(&sintomas[contArq], REG2, cont - contArq, sintomaBin);

        if (total != cont - contArq) {
            printf("Erro na escritura\n");

        }
    }

    fclose(sintomaBin);

    return 0;
}

//void sintoma2() {
//
//    int cod,op;
//
//    for (i = 0; i < MAXREG; i++) {
//        //sintomas[i].codID = i + 1;
//
//        printf("Sintoma de qual doenca?");
//
//        printf("Informe o codigo de identificacao da doenca: ");
//        scanf("%d",&cod);
//
//        cod = cod - 1;
//        if (contDoencas <= cod) {
//            do {
//                printf("Doenca não cadastrada.\n1. Cadastrar?\n2. Digitar outra\n> ");
//                scanf("%d", &op);
//                switch (op) {
//                    case 1:
//                        doenca1();
//                        marca1 = 1;
//                        printf("Digite outro codigo de doenca: ");
//                        scanf("%d", &cod);
//                        cod = cod - 1;
//                        break;
//                    case 2:
//                        printf("Digite outro codigo de doenca: ");
//                        scanf("%d", &cod);
//                        cod = cod - 1;
//                    default:
//                        if (contDoencas <= cod) {
//                            printf("Digite novamente\n");
//                        }
//
//                        break;
//                }
//            } while (contDoencas <= cod);
//
//        }
//
//
//        printf("Codigo de identificacao: %d\n",sintomas[i].codID);
//        fflush(stdin);
//        printf("Descreva os sintomas\n");
//        gets(sintomas[i].descricao);
//
//
//
//        do {
//
//            printf("Informe o nivel de severidade do sintoma\n");
//            printf("1. Baixo \n2. Medio \n3. Alto \n");
//            scanf("%d",&sintomas[i].nivel);
//
//            switch (sintomas[i].nivel) {
//                case 1:
//                    printf("Baixo\n");
//                    break;
//                case 2:
//                    printf("Medio\n");
//                    break;
//                case 3:
//                    printf("Alto\n");
//                    break;
//                default:
//                    printf("Opcao invalida\n");
//            }
//
//        } while (sintomas[i].nivel <= 0 || sintomas[i].nivel > 3);
//
//        sair();
//        limparBuffer();
//    }
//
//}



int medico3() {

    int cod, op;
    int contAtendidos = 0;
    char ok;

    for (i = contMedicos; i < MAXREG; i++) {

        printf("Digite o CRM:\n");
        scanf("%d", &medicos[i].CRM);
        printf("Digite o nome do Medico:\n");
        gets(medicos[i].nomeMedico);
        printf("Informe o CPF: \n");
        scanf("%s", medicos[i].CPF);
        printf("Digite o Telefone do medico: \n");
        scanf("%s", medicos[i].telefone);

        printf("Digite o endereco da clinica/hospital\n");
        printf("Rua:\n");
        gets(medicos[i].endereco.rua);
        limparBuffer();
        printf("Numero:\n");
        scanf("%d", &medicos[i].endereco.numero);
        limparBuffer();
        printf("Bairro:\n");
        gets(medicos[i].endereco.bairro);
        limparBuffer();
        printf("Cidade:\n");
        gets(medicos[i].endereco.cidade);
        limparBuffer();
        printf("Estado:\n");
        gets(medicos[i].endereco.estado);
        limparBuffer();
        printf("CEP:\n");
        scanf("%s", medicos[i].endereco.CEP);


        printf("Informe o codigo de identificacao dos pacientes atendidos pelo medico\n");

        for (j = 0; j < MAXREG; j++) {

            printf("Codigo: ");
            scanf("%d",&cod);

            cod = cod - 1;
            if (contPacientes <= cod) {
                do {
                    printf("Paciente não cadastrado.\n1. Cadastrar?\n2. Digitar outro\n> ");
                    scanf("%d", &op);
                    switch (op) {
                        case 1:
                            paciente4();
                            marca4 = 1;
                            printf("Digite outro codigo de paciente: ");
                            scanf("%d", &cod);
                            cod = cod - 1;
                            break;
                        case 2:
                            printf("Digite outro codigo de paciente: ");
                            scanf("%d", &cod);
                            cod = cod - 1;
                        default:
                            printf("Digite novamente\n");
                            break;
                    }
                } while (contPacientes <= cod);

            }

            printf("Nome do paciente: ");
            puts(pacientes[cod].nomePaciente);

            medicos[i].codPaciente[j] = cod;

            contAtendidos += 1; //contAtendidos = contAtendidos + 1;

            printf("Você deseja informar mais algum paciente? (S/N)");
            scanf(" %c",&ok);
            if (ok != 'S' || ok != 's')
                j = MAXREG;

        }

        printf("Nome e CPF de todos os pacientes atendidos pelo medico:\n");

        for (j = 0; j < contAtendidos; j++) {

            printf("Codigo: '%d'\n",medicos[i].codPaciente[j]);
            printf("Nome do paciente: ");
            puts(pacientes[medicos[i].codPaciente[j]].nomePaciente);
            printf("CPF do paciente: ");
            printf("%s\n", pacientes[medicos[i].codPaciente[j]].CPF);

        }

        contMedicos += 1;
        sair();
        limparBuffer();
    }
    return 0;
}



int paciente4() {

    char ok;

    cont = 0;

    pacienteBin = fopen("paciente4.dat","a+b");

    if (pacienteBin == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        getchar();
        return 1;
    }

    rewind(pacienteBin);

    while (cont < MAXREG && fread(&pacientes[cont], REG4, 1, pacienteBin) == 1) {

        if (cont == 0)

            puts("Atuais Pacientes Cadastrados:");

        printf("Codigo: '%d'\nNome: %s\n%d anos\n%c\n",pacientes[cont].codPaciente, pacientes[cont].nomePaciente, pacientes[cont].idade, pacientes[cont].genero);

        cont++;

    }

    //o que vai ficar realmente

    printf("Cadastrados [%d] registros de pacientes.\n",cont);

    contArq = cont;

    if (cont == MAXREG) {

        fputs("O Registro está cheio.\n", stderr);

        return 2;

    }

    limparBuffer();

    while (cont < MAXREG) {

        pacientes[cont].codPaciente = cont + 1;
        printf("Código do Paciente: '%d'\n", pacientes[cont].codPaciente);

        printf("Digite o CPF do paciente: \n");
        scanf("%s", pacientes[cont].CPF);
        limparBuffer();
        printf("Digite o nome do paciente: \n");
        gets(pacientes[cont].nomePaciente);
        printf("Digite a idade do paciente: \n");
        scanf("%d", &pacientes[cont].idade);
        limparBuffer();
        printf("Qual o genero do paciente? (M/F) \n");
        scanf("%c", &pacientes[cont].genero);
        limparBuffer();
        printf("Digite o telefone do paciente: \n");
        scanf("%s", pacientes[cont].telefone);
        limparBuffer();

        printf("Digite o endereco do paciente: \n");
        printf("Rua:\n");
        gets(pacientes[cont].endereco.rua);
        printf("Numero:\n");
        scanf("%d", &pacientes[cont].endereco.numero);
        limparBuffer();
        printf("Bairro:\n");
        gets(pacientes[cont].endereco.bairro);
        printf("Cidade:\n");
        gets(pacientes[cont].endereco.cidade);
        printf("Estado:\n");
        gets(pacientes[cont].endereco.estado);

        printf("CEP:\n");
        scanf("%s", pacientes[cont].endereco.CEP);
        limparBuffer();

        printf("Predisposicao Genetica do paciente:\n");
        gets(pacientes[cont].predGenetica);
        printf("Há algum risco associado ao paciente?\nJá toma algum medicamento?\nEstá exposto a agentes nocivos à saúde?\nTrabalha em ambiente insalubre?\nDentre outros\n");
        printf("(S/N)\n");
        scanf(" %c", &ok);
        limparBuffer();

        if (ok == 's' || ok == 'S') {

            printf("Toma algum medicamento?\n");
            gets(pacientes[cont].risco.medicamento);
            printf("Está exposto a agentes nocivos à saúde?\n");
            gets(pacientes[cont].risco.agentes);
            printf("Trabalha em ambiente insalubre?\n");
            gets(pacientes[cont].risco.ambiente);
            printf("Outros?\n");
            gets(pacientes[cont].risco.outros);

        }

        printf("Quais exames ja foram realizados?\n");
        gets(pacientes[cont].exames);
        printf("Quais os resultados de exames anteriores?\n");
        gets(pacientes[cont].resultados);


        //tirar depois (talvez)
        contPacientes += 1;


        cont++;
        contSair = cont;

        if (cont != MAXREG)

            sair();

        limparBuffer();

    }

    cont = contSair;

    if (cont > 0) {

        //preciso pra alguma coisa talvez
        puts("Lista de Pacientes cadastrados:");

        for (i = 0; i < cont; i++)

            printf("Codigo: '%d'\nNome: %s\n%d anos\n%c\n",pacientes[i].codPaciente, pacientes[i].nomePaciente, pacientes[i].idade, pacientes[i].genero);


        total = fwrite(&pacientes[contArq], REG4, cont - contArq, pacienteBin);

        if (total != cont - contArq) {

            printf("Erro na escritura\n");

        }
    }

    fclose(pacienteBin);

    return 0;
}



int tratamento5() {

    char ok;
    int cod, op;

    for (i = 0; i < MAXREG; i++) {

        tratamentos[i].codID = i + 1;
        printf("Codigo de identificacao:  '%d'\n", tratamentos[i].codID);


        printf("Informe o codigo de identificacao da doenca: ");
        scanf("%d",&cod);

        cod = cod - 1;
        if (contDoencas <= cod) {
            do {
                printf("Doenca não cadastrada.\n1. Cadastrar?\n2. Digitar outra\n> ");
                scanf("%d", &op);
                switch (op) {
                    case 1:
                        doenca1();
                        marca1 = 1;
                        printf("Digite outro codigo de doenca: ");
                        scanf("%d", &cod);
                        cod = cod - 1;
                        break;
                    case 2:
                        printf("Digite outro codigo de doenca: ");
                        scanf("%d", &cod);
                        cod = cod - 1;
                    default:
                        if (contDoencas <= cod) {
                            printf("Digite novamente\n");
                        }
                }
            } while (contDoencas <= cod);

        }

        printf("Nome da doenca: ");
        puts(doencas[cod].nomeDoenca);

        tratamentos[i].codDoenca = cod;

        printf("Informe o codigo de identificacao do paciente: ");
        scanf("%d",&cod);

        if(marca4 == 0) {

        }

        cod = cod - 1;
        if (contPacientes <= cod) {
            do {
                printf("Paciente não cadastrado.\n1. Cadastrar?\n2. Digitar outro\n> ");
                scanf("%d", &op);
                switch (op) {
                    case 1:
                        paciente4();
                        marca4 = 1;
                        printf("Digite outro codigo de paciente: ");
                        scanf("%d", &cod);
                        cod = cod - 1;
                        break;
                    case 2:
                        printf("Digite outro codigo de paciente: ");
                        scanf("%d", &cod);
                        cod = cod - 1;
                    default:
                        if (contPacientes <= cod) {
                            printf("Digite novamente\n");
                        }
                }
            } while (contPacientes <= cod);

        }

        printf("Nome do paciente: ");
        puts(pacientes[cod].nomePaciente);

        tratamentos[i].codPaciente = cod;

        printf("Informe o codigo de identificacao do medico: ");
        scanf("%d",&cod);

        cod = cod - 1;
        if (contMedicos <= cod) {
            do {
                printf("Medico não cadastrado.\n1. Cadastrar?\n2. Digitar outro\n> ");
                scanf("%d", &op);
                switch (op) {
                    case 1:
                        medico3();
                        marca3 = 1;
                        printf("Digite outro codigo de medico: ");
                        scanf("%d", &cod);
                        cod = cod - 1;
                        break;
                    case 2:
                        printf("Digite outro codigo de medico: ");
                        scanf("%d", &cod);
                        cod = cod - 1;
                    default:
                        if (contMedicos <= cod) {
                            printf("Digite novamente\n");
                        }
                }
            } while (contMedicos <= cod);

        }

        printf("Nome do medico: ");
        puts(medicos[cod].nomeMedico);

        tratamentos[i].codMedico = cod;

        printf("Informe o valor da consulta:\n");
        scanf("%f", & tratamentos[i].valorConsulta);

        printf("Exames adicionais? (S/N)\n");
        scanf(" %c", &ok);
        if (ok == 'S' || ok == 's') {

            printf("Informe o valor dos exames:");
            scanf("%f", & tratamentos[i].valorExame);
        }
        printf("Havera tempo de observacao (S/N)? \n");
        scanf(" %c", & tratamentos[i].resp);

        if (tratamentos[i].resp=='s') {

            printf ("Informe o tempo de observacao");
            scanf("%s", tratamentos[i].tempoObs);
            puts(tratamentos[i].tempoObs);
            printf ("Informe o tempo de observacao");
            scanf("%s", tratamentos[i].tempoObs);
        }

        printf("Existe tempo de internacao (s/n):");
        fflush(stdin);
        scanf("%c \n ", & tratamentos[i].resp);
        if (tratamentos[i].resp=='s') {

            printf("Quanto tempo de internacao?");
            scanf("%s", tratamentos[i].tempoInter);
            puts(tratamentos[i].tempoInter);
            printf("Quanto tempo de internacao?");
            scanf("%s", tratamentos[i].tempoInter);
        }

        sair();
        limparBuffer();
    }
    return 0;
}



int medicamento6() {

    for (i = 0; i < MAXREG; i++) {

        medicamentos[i].codID = i + 1;
        printf ("\n Codigo do exame: %d \n", medicamentos[i].codID);
        printf("Nome do medicamento \n");

        gets(medicamentos[i].nome_medicamento);

        printf("Para quais pacientes o medicamento e indicado?\n");
        gets(medicamentos[i].indicacao);

        printf("Informe a posologia \n");
        gets(medicamentos[i].posologia);
        printf("Informe a faixa etaria indicada para o uso do medicamento:\n");
        scanf("%d", &medicamentos[i].faixa_etaria);

        printf("Para quais pacientes o medicamento eh contra indicado?\n");
        gets(medicamentos[i].contra_indicacao);

    }

    sair();
    return 0;
}



int exame7() {

    for (i = 0; i < MAXREG; i++) {

        exames[i].cod_exame = i + 1;
        fflush(stdin);
        printf ("\n Codigo do exame: %d \n", exames[i].cod_exame);
        printf("Nome do exame \n");
        gets(exames[i].nome_exame);
        fflush(stdin);

        do {
            printf("A forma de pagamento\n1. Convenio\n2. Particular\n3. Gratuito\n");
            scanf("%d",&exames[i].pgto);
            limparBuffer();
            switch (exames[i].pgto) {

                case 1:
                    printf("Convenio\n");
                    break;
                case 2:
                    printf("Particular\n");
                    break;
                case 3:
                    printf("Gratuito\n");
                    break;
                default:
                    if(exames[i].pgto <= 0 || exames[i].pgto > 3)
                        printf("Opcao invalida\n");
            }

        } while (exames[i].pgto <= 0 || exames[i].pgto > 3);

        sair();
        limparBuffer();
    }
    return 0;
}
