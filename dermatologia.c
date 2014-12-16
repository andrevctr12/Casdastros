//
//              Trabalho de Arquivos
//
//   André Victor Teixeira Lopes / 201411640020
//   Elizane Ferraz             / 201411640022
//   Larissa Roman Françoso    / 201411640013
//
//
//

#include <stdio.h>


#define A 3


int i, j;
int contPacientes = 0;
int contMedicos = 0;
int contDoencas = 0;

//marcas

int marca1 = 0, marca3, marca4 = 0;

//typedef structs:

//num1()
typedef struct {
    int codID, nivel;
    char nomeDoenca[50], descricao[500];
}reg1;

//num2()
typedef struct{
    int codID, nivel;
    char descricao[300];
}reg2;

//num3()
typedef struct {
    char rua[50], bairro[30], cidade[30], estado[30], CEP[9];
    int numero;
}reg03;

typedef struct {
    int CRM, codPacientes[A];
    char nomeMedico[50], nomePacientes[50], CPF[15], telefone[20];
    reg03 endereco;
}reg3;

//num4()
typedef struct {

    char medicamento[200], agentes[150], ambiente[200], outros[200];
}reg04;

typedef struct {
    char rua[50], bairro[30], cidade[30], estado[30], CEP[9];
    int numero;
}reg14;

typedef struct {
    int idade, codPaciente;
    char nomePaciente[50], genero, predGenetica[200], exames[200],resultados[150];
    char CPF[15], telefone[20];
    reg04 risco;
    reg14 endereco;
}reg4;

//num5()
typedef struct {
    int codID, codDoenca, codPaciente, codMedico;
    float valorConsulta, valorExame;
    char tempoObs[5], tempoInter[5], resp;
}reg5;

//Declaração de structs:


reg1 doencas[A];
reg2 sintomas[A];
reg3 medicos[A];
reg4 pacientes[A];
reg5 tratamentos[A];




//Protótipo de funções:

void sair();


void doenca();
void sintoma();
void medico();
void paciente();
void tratamento();
void medicamento();
void exame();
void num8();

int main() {

    int op;

    do {
        printf("Escolha a opcao desejada:\n");
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
                doenca();
                marca1 = 1;
                break;
            case 2:
                sintoma();
                break;
            case 3:
                medico();
                marca3 = 1;
                break;
            case 4:
                paciente();
                marca4 = 1;
                break;
            case 5:
                if (marca1 == 0) {

                    printf("Você não tem nenhuma doença cadastrada. Cadastre para continuar!\n\n");

                    doenca();
                    marca1 = 1;
                    tratamento();

                }
                else if (marca4 == 0) {
                    printf("Você não tem nenhum paciente cadastrado. Cadastre para continuar!\n\n");
                    paciente();
                    marca4 = 1;
                    tratamento();
                }
                else
                    tratamento();
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
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

    for (i = 0; i < A; i++) {
        printf("%d. ", i + 1);
        puts(pacientes[i].nomePaciente);
    }


}

void sair() {
    char ok;
    printf("Você deseja sair deste cadastramento? (S/N)\n");
    scanf(" %c",&ok);
    if (ok == 'S' || ok == 's')
        i = A;

}

/*

 Registro de pacientes: CPF, nome do paciente, telefone, endereço, idade, gênero, predisposição genética
 (presença de doenças no pai e/ou na mãe), riscos associados (já toma algum medicamento?, está exposto a agentes
 nocivos à saúde? trabalha em ambiente insalubre? dentre outros), exames realizados (quais?), quais os resultados
 de exames anteriores?;

 */

void doenca() {

    FILE *arqDoencas;
    arqDoencas = fopen("arqDoencas.bin","a+b");

    if (arqDoencas == NULL) {

        printf("Erro na abertura do Arquivo!\n");
        exit(1);
    }

    else {

        for(i = contDoencas; i < A; i++) {
            doencas[i].codID = i + 1;
            fprintf(arqDoencas, doencas[i].codID);
            printf("Codigo de identificacao: %d \n",doencas[i].codID);

            printf("Informe o nome da doenca:\n> ");
            fflush(stdin);
            gets(doencas[i].nomeDoenca);
            fprintf(arqDoencas, doencas[i].nomeDoenca);
            printf("Descreva a doenca:\n> ");
            fflush(stdin);
            gets(doencas[i].descricao);
            fprintf(arqDoencas, doencas[i].descricao);

            do{

                printf("Informe o nivel de seriedade da doenca\n");
                printf("1. Baixo \n2. Medio \n3. Alto \n");
                scanf("%d",&doencas[i].nivel);
                fprintf(arqDoencas, doencas[i].nivel);

                switch (doencas[i].nivel) {
                    case 1:
                        printf("\n1. Baixo\n");
                        break;
                    case 2:
                        printf("\n2. Medio\n");
                        break;
                    case 3:
                        printf("\n3. Alto\n");
                        break;
                    default:
                        printf("Opcao invalida\n");
                }

            } while (doencas[i].nivel <= 0 || doencas[i].nivel > 3);



            contDoencas += 1;
            fprintf(arqDoencas, contDoencas);
            sair();
        }
    }



    fclose(arqDoencas);

}



void sintoma() {

    for (i = 0; i < A; i++) {
        sintomas[i].codID = i + 1;
        printf("Codigo de identificacao: %d\n",sintomas[i].codID);
        fflush(stdin);
        printf("Descreva os sintomas\n> ");
        gets(sintomas[i].descricao);



        do {

            printf("Informe o nivel de severidade da doenca\n");
            printf("1. Baixo \n2. Medio \n3. Alto \n");
            scanf("%d",&sintomas[i].nivel);

            switch (sintomas[i].nivel) {
                case 1:
                    printf("\n1. Baixo\n");
                    break;
                case 2:
                    printf("\n2. Medio\n");
                    break;
                case 3:
                    printf("\n3. Alto\n");
                    break;
                default:
                    printf("Opcao invalida\n");
            }

        } while (sintomas[i].nivel <= 0 || sintomas[i].nivel > 3);

        sair();


    }

}


void medico() {

    int cod, op;
    char ok;

    for (i = contMedicos; i < A; i++) {

        printf("Digite o CRM:\n> ");
        fflush(stdin);
        scanf("%d", &medicos[i].CRM);
        printf("\nDigite o nome do Medico:\n> ");
        fflush(stdin);
        gets(medicos[i].nomeMedico);
        printf("\nInforme o CPF:\n> ");
        scanf("%s", medicos[i].CPF);
        printf("\nDigite o Telefone do medico:\n> ");
        fflush(stdin);
        scanf("%s", medicos[i].telefone);

        printf("\n\nDigite o endereco da clinica/hospital\n");
        printf("\nRua: ");
        fflush(stdin);
        gets(medicos[i].endereco.rua);
        printf("\nNumero: ");
        scanf("%d", &medicos[i].endereco.numero);
        printf("\nBairro: ");
        fflush(stdin);
        gets(medicos[i].endereco.bairro);
        printf("\nCidade: ");
        fflush(stdin);
        gets(medicos[i].endereco.cidade);
        printf("\nEstado: ");
        fflush(stdin);
        gets(medicos[i].endereco.estado);
        printf("\nCEP: ");
        scanf("%s", medicos[i].endereco.CEP);


        printf("Informe o codigo de identificacao dos pacientes atendidos pelo medico\n");

        for (j = 0; j < A; j++) {

            printf("Codigo: ");
            scanf("%d",&cod);

            cod = cod - 1;
            if (contPacientes <= cod) {
                do {
                    printf("Paciente não cadastrado.\n1. Cadastrar?\n2. Digitar outro\n> ");
                    scanf("%d", &op);
                    switch (op) {
                        case 1:
                            paciente();
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

            medicos[i].codPacientes[j] = cod;

            printf("Você deseja informar mais algum paciente? (S/N)");
            scanf(" %c",&ok);
            if (ok != 'S' || ok != 's')
                j = A;

        }

        printf("Nome e CPF de todos os pacientes atendidos pelo medico:");

        for (j = 0; j < A; j++) {

            printf("Codigo: %d\n",medicos[i].codPacientes[j]);
            printf("Nome do paciente: ");
            puts(pacientes[medicos[i].codPacientes[j]].nomePaciente);
            printf("CPF do paciente: ");
            printf("%s\n", pacientes[medicos[i].codPacientes[j]].CPF);

        }

        contMedicos += 1;
        sair();
    }

}



void paciente() {

    char ok;

    for(i = contPacientes; i < A; i++) {

        pacientes[i].codPaciente = i + 1;
        printf("Código do Paciente: '%d'\n", pacientes[i].codPaciente);

        printf("Digite o CPF do paciente: \n");
        scanf("%s", pacientes[i].CPF);
        printf("Digite o nome do paciente: \n");
        fflush(stdin);
        gets(pacientes[i].nomePaciente);
        printf("Digite a idade do paciente: \n");
        scanf("%d", &pacientes[i].idade);
        printf("Qual o genero do paciente? (M/F) \n");
        fflush(stdin);
        scanf("%c", &pacientes[i].genero);
        printf("Digite o telefone do paciente: \n");
        fflush(stdin);
        scanf("%s", pacientes[i].telefone);

        printf("Digite o endereco do Paciente\n");
        printf("Rua:\n");
        fflush(stdin);
        gets(pacientes[i].endereco.rua);
        printf("Numero:\n");
        scanf("%d", &pacientes[i].endereco.numero);
        printf("Bairro:\n");
        fflush(stdin);
        gets(pacientes[i].endereco.bairro);
        printf("Cidade:\n");
        fflush(stdin);
        gets(pacientes[i].endereco.cidade);
        printf("Estado:\n");
        fflush(stdin);
        gets(pacientes[i].endereco.estado);
        printf("CEP:\n");
        fflush(stdin);
        scanf("%s", pacientes[i].endereco.CEP);

        printf("Predisposicao Genetica do paciente:\n");
        fflush(stdin);
        gets(pacientes[i].predGenetica);
        printf("Há algum risco associado ao paciente?\nJá toma algum medicamento?\nEstá exposto a agentes nocivos à saúde?\nTrabalha em ambiente insalubre?\nDentre outros\n");
        printf("(S/N)\n");
        fflush(stdin);
        scanf(" %c", &ok);

        if (ok == 's' || ok == 'S') {

            printf("Toma algum medicamento?\n");
            fflush(stdin);
            gets(pacientes[i].risco.medicamento);
            printf("Está exposto a agentes nocivos à saúde?\n");
            fflush(stdin);
            gets(pacientes[i].risco.agentes);
            printf("Trabalha em ambiente insalubre?\n");
            fflush(stdin);
            gets(pacientes[i].risco.ambiente);
            printf("Outros?\n");
            fflush(stdin);
            gets(pacientes[i].risco.outros);

        }

        printf("Quais exames ja foram realizados?\n");
        fflush(stdin);
        gets(pacientes[i].exames);
        printf("Quais os resultados de exames anteriores?\n");
        fflush(stdin);
        gets(pacientes[i].resultados);

        contPacientes += 1;
        sair();


    }

}




/*     Registro de tratamentos: código de identificação, nome do médico, nome do paciente, código de identificação da doença, exames adicionais (quais?), valor(es) da consulta e dos exames adicionais, haverá tempo de observação? (caso positivo, quanto tempo?), indicação de internação no hospital? (caso positivo, quanto tempo?);
 */


void tratamento() {

    char ok;
    int cod, op;

    for (i = 0; i < A; i++) {

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
                        doenca();
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
                        printf("Digite novamente\n");
                        break;
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
                        paciente();
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
                        medico();
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
                        printf("Digite novamente\n");
                        break;
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
    }
}
