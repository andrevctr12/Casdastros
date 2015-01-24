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



//CONTADORES

//int cont;
int i, j;
long int total;
char ok;


//MARCAS

int marca1 = 0;
int marca3 = 0;
int marca4 = 0;


//REGISTROS

//doenca1()
struct reg1 {
    int codNum, nivel;
    char nomeDoenca[TAM1], descricao[TAM4];
};

//sintoma2()
struct reg2 {
    int codNum, nivel;
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
    int idade, codNum;
    char nomePaciente[TAM2], genero, predGenetica[TAM3], exames[TAM3],resultados[TAM3];
    char CPF[15], telefone[20];
    reg04 risco;
    reg14 endereco;
};

//tratamento5()
struct reg5 {
    int codNum, codDoenca, codPaciente, codMedico;
    float valorConsulta, valorExame;
    char tempoObs[5], tempoInter[5], resp;
};

//medicamento6()
struct reg6 {
    int codNum, faixaEtaria;
    char nomeMedicamento[TAM2], indicacao[TAM3], posologia[TAM3], contraIndicacao[TAM3];
    float valor;
};


//exame7()
struct reg7 {
    int codNum, pgto;
    char nomeExame[TAM1];
};


//codigo__________()
//int codDoenca[MAXREG];
//int codSintoma[MAXREG];
//int codMedico[MAXREG];
//int codPaciente[MAXREG];
//int codTratamento[MAXREG];
//int codMedicamento[MAXREG];
//int codExame[MAXREG];

struct regCod1 {
    int codDoenca[MAXREG];
    int codSintoma[MAXREG];
    int codMedico[MAXREG];
    int codPaciente[MAXREG];
    int codTratamento[MAXREG];
    int codMedicamento[MAXREG];
    int codExame[MAXREG];
};

struct regCod {
    struct regCod1 cod[MAXREG];
};


//DECLARAÇÃO DE REGISTROS

struct reg1 doencas[MAXREG];
struct reg2 sintomas[MAXREG];
struct reg3 medicos[MAXREG];
struct reg4 pacientes[MAXREG];
struct reg5 tratamentos[MAXREG];
struct reg6 medicamentos[MAXREG];
struct reg7 exames[MAXREG];

struct regCod codigos[8];


//TAMANHO DE REGISTROS


int REGCOD = sizeof(struct regCod);


int REG[8] = {0,
    sizeof (struct reg1),
    sizeof (struct reg2),
    sizeof (struct reg3),
    sizeof (struct reg4),
    sizeof (struct reg5),
    sizeof (struct reg6),
    sizeof (struct reg7)
};


//PROTÓTIPO DE FUNÇÕES GERAIS

int sair();
int doenca1();
int sintoma2();
int medico3();
int paciente4();
int tratamento5();
int medicamento6();
int exame7();
void listaPacientes();
void limparBuffer();


//PROTÓTIPO DE FUNÇÕES ESPECIAIS

int codigoLer();
int codigoSalvar();
int codigoPaciente(int, int, int, int);


//ARQUIVOS

FILE *Bin[8];


//PROTÓTIPO DE FUNÇÕES DE ABERTURA DE ARQUIVOS

int abrirDoenca1();
int abrirMedico3();
int abrirPaciente4();


int main() {

    int op, marca = 0;

    if (marca == 0) {

        codigoLer();
        marca = 1;

    }

    codigoSalvar();

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
                if (marca4 == abrirPaciente4()) {

                    printf("Você não tem nenhum paciente cadastrado. Cadastre para continuar!\n\n");
                    paciente4();
                    medico3();
                }
                else {
                    medico3();
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


    codigoSalvar();

    return 0;
}


int codigoLer() {
    const int numeroFuncao = 0;

    int contCodigo = 0;

    Bin[numeroFuncao] = fopen("codigo.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return 1;

    }

    rewind(Bin[numeroFuncao]);

    while (contCodigo < MAXREG && fread(&codigos[contCodigo], REGCOD, 1, Bin[numeroFuncao]) == 1) {

        contCodigo++;

    }

    fclose(Bin[numeroFuncao]);

    return 0;
}
int codigoSalvar() {
    const int numeroFuncao = 0;


    Bin[numeroFuncao] = fopen("codigo.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return 1;

    }

    total = fwrite(&codigos[0], REGCOD, 8, Bin[numeroFuncao]);


    if (total != 8)

        printf("Erro na escritura\n");


    fclose(Bin[numeroFuncao]);



    return 0;
}
int codigoPaciente(int numeroFuncao, int cod, int contPaciente, int cont) {

    for (i = 0; i < contPaciente; i++) {

        if (cod == codigos[numeroFuncao].cod[cont].codPaciente[i]) {

            puts("Paciente ja cadastrado no registro do medico");

            return 1;
        }

    }

    return 0;

}

void listaPacientes() {

    int cont4 = abrirPaciente4();

    for (i = 0; i < cont4; i++) {

        if (i == 0)

            puts("Lista de Pacientes:");


        printf("%d. %s, %d anos\n",i + 1, pacientes[i].nomePaciente, pacientes[i].idade);

    }


}
void limparBuffer() {

    char c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }

}
int sair() {
    char ok;
    printf("Você deseja sair deste cadastramento? (S/N)\n");
    ok = getchar();
    limparBuffer();

    if (ok == 'S' || ok == 's')
        return 1;
    return 0;
}

int abrirDoenca1() {




    return 0;
}
int doenca1() {

    int cont1;


    while (cont1 < MAXREG) {

        doencas[cont1].codNum = cont1 + 1;
        printf("Codigo de identificacao: %d \n",doencas[cont1].codNum);

        printf("Informe o nome da doenca:\n");
        gets(doencas[cont1].nomeDoenca);
        limparBuffer();
        printf("Descreva a doenca \n");
        gets(doencas[cont1].descricao);

        do {

            printf("Informe o nivel de seriedade da doenca\n");
            printf("1. Baixo \n2. Medio \n3. Alto \n");
            scanf("%d",&doencas[cont1].nivel);
            limparBuffer();


            switch (doencas[cont1].nivel) {
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

        } while (doencas[cont1].nivel <= 0 || doencas[cont1].nivel > 3);



        cont1++;

        if (cont1 != MAXREG) {

            if (sair() == 1)
                break;

        }

    }
    return 0;
}

int abrirSintoma2() {
    const int numeroFuncao = 4;

    int cont4 = 0;

    Bin[numeroFuncao] = fopen("paciente4.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return -2;
    }

    rewind(Bin[numeroFuncao]);

    while (cont4 < MAXREG && fread(&pacientes[cont4], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont4++;

    }


    fclose(Bin[numeroFuncao]);


    return cont4;



}
int sintoma2() {
    const int numeroFuncao = 2;

    int cont2 = 0;
    int contBin;

    Bin[numeroFuncao] = fopen("sintoma2.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return 1;
    }

    rewind(Bin[numeroFuncao]);

    while (cont2 < MAXREG && fread(&sintomas[cont2], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        if (cont2 == 0)

            puts("Atuais Sintomas Cadastrados:");


        printf("codNum: %d\nNivel: %d\nDescricao:%s\n",sintomas[cont2].codNum, sintomas[cont2].nivel, sintomas[cont2].descricao);



        cont2++;

    }

    //o que vai ficar realmente

    printf("Cadastrados [%d] registros de sintomas.\n", cont2);

    contBin = cont2;

    if (cont2 == MAXREG) {

        fputs("O Registro está cheio.\n", stderr);

        return 2;

    }

    limparBuffer();



    while (cont2 < MAXREG) {

        sintomas[cont2].codNum = cont2 + 1;
        printf("Codigo de identificacao: %d\n",sintomas[cont2].codNum);
        puts("Descreva os Sintomas:");
        gets(sintomas[cont2].descricao);

        printf("Informe o nivel de severidade do sintoma:\n");

        do {

            printf("1. Baixo \n2. Medio \n3. Alto \n");
            scanf("%d",&sintomas[cont2].nivel);

            switch (sintomas[cont2].nivel) {
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
                    break;
            }

        } while (sintomas[cont2].nivel <= 0 || sintomas[cont2].nivel > 3);



        cont2++;

        if (cont2 != MAXREG) {

            if (sair() == 1)
                break;
        }

        limparBuffer();

    }

    if (cont2 > 0) {

        //preciso pra alguma coisa talvez
        puts("Lista de Sintomas cadastrados:");

        for (i = 0; i < cont2; i++)

            printf("codNum: %d\n%d\nDescricao:%s\n",sintomas[i].codNum, sintomas[i].nivel, sintomas[i].descricao);

        total = fwrite(&sintomas[contBin], REG[numeroFuncao], cont2 - contBin, Bin[numeroFuncao]);

        if (total != cont2 - contBin) {
            printf("Erro na escritura\n");

        }
    }

    fclose(Bin[numeroFuncao]);

    return 0;
}

int abrirMedico3() {
    const int numeroFuncao = 3;

    int cont3 = 0;

    Bin[numeroFuncao] = fopen("medico3.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return 1;

    }

    rewind(Bin[numeroFuncao]);

    while (cont3 < MAXREG && fread(&medicos[cont3], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {


        cont3++;

    }


    return cont3;



}
int medico3() {
    const int numeroFuncao = 3;

    int codRegistro, op;
    int contPaciente;
    int cont3 = abrirMedico3();
    int cont4 = abrirPaciente4();
    int contBin = cont3;


    if (cont3 == MAXREG) {

        fputs("O Registro está cheio.\n", stderr);

        return 2;

    }

    if (cont3 == 0)

        puts("Nenhum Cadastro de medico.");

    else

        printf("Cadastrados [%d] registros de medicos.\n", cont3);


    while (cont3 < MAXREG) {

        printf("Digite o CRM:\n");
        scanf("%d", &medicos[cont3].CRM);
        limparBuffer();

        printf("Digite o nome do Medico:\n");
        gets(medicos[cont3].nomeMedico);

        printf("Informe o CPF: \n");
        scanf("%s", medicos[cont3].CPF);
        limparBuffer();

        printf("Digite o Telefone do medico: \n");
        scanf("%s", medicos[cont3].telefone);
        limparBuffer();


        printf("Digite o endereco da clinica/hospital\n");

        printf("Rua:\n");
        gets(medicos[cont3].endereco.rua);

        printf("Numero:\n");
        scanf("%d", &medicos[cont3].endereco.numero);
        limparBuffer();

        printf("Bairro:\n");
        gets(medicos[cont3].endereco.bairro);

        printf("Cidade:\n");
        gets(medicos[cont3].endereco.cidade);

        printf("Estado:\n");
        gets(medicos[cont3].endereco.estado);

        printf("CEP:\n");
        scanf("%s", medicos[cont3].endereco.CEP);
        limparBuffer();

        contPaciente = 0;

        listaPacientes();

        printf("\nInforme o codigo de identificacao dos pacientes atendidos pelo medico\n");


        while (contPaciente < cont4) {

            printf("Codigo: ");
            scanf("%d",&codRegistro);
            limparBuffer();

            if (codigoPaciente(numeroFuncao, codRegistro, contPaciente, cont3) == 1)

                continue;



            if (cont4 < codRegistro || codRegistro < 1) {

                do {

                    printf("Paciente não cadastrado.\n1. Cadastrar.\n2. Digitar outro codigo de Paciente.\n> ");
                    scanf("%d", &op);
                    switch (op) {
                        case 1:
                            cont4 = paciente4();
                            printf("Digite outro codigo de Paciente: ");
                            scanf("%d", &codRegistro);
                            limparBuffer();
                            if (codigoPaciente(numeroFuncao, codRegistro, contPaciente, cont3) == 1) {
                                goto continuar;
                            }
                            break;
                        case 2:
                            printf("Digite outro codigo de Paciente: ");
                            scanf("%d", &codRegistro);
                            limparBuffer();
                            if (codigoPaciente(numeroFuncao, codRegistro, contPaciente, cont3) == 1) {
                                goto continuar;
                            }
                            break;
                        default:
                            printf("Digite novamente\n");
                            break;
                    }

                } while (cont4 < codRegistro || codRegistro < 1);

            }






            printf("Nome do paciente: %s\n",pacientes[codRegistro - 1].nomePaciente);

            codigos[numeroFuncao].cod[cont3].codPaciente[contPaciente] = codRegistro;

            contPaciente++;

            if (contPaciente != cont4) {

                puts("Você deseja informar mais algum paciente? (S/N)");
                ok = getchar();
                limparBuffer();

                if (ok == 'S' || ok == 's')

                    continuar: continue;

                break;


            }



        }



        printf("\nNome e idade de todos os pacientes atendidos pelo medico:\n");

        for (i = 0; i < contPaciente; i++) {

            codRegistro = codigos[numeroFuncao].cod[cont3].codPaciente[i];

            printf("%d. %s, %d anos\n", codRegistro, pacientes[codRegistro - 1].nomePaciente, pacientes[codRegistro].idade);

        }

        cont3++;

        if (cont3 != MAXREG) {

            if (sair() == 1)
                break;
        }

    }


    if (cont3 > 0) {

        Bin[numeroFuncao] = fopen("medico3.bin","a+b");

        if (Bin[numeroFuncao] == NULL) {

            fputs("Nao foi possivel abrir o arquivo\n",stderr);
            return 1;

        }

        total = fwrite(&medicos[contBin], REG[numeroFuncao], cont3 - contBin, Bin[numeroFuncao]);

        if (total != cont3 - contBin) {
            printf("Erro na escritura\n");

        }
    }

    fclose(Bin[numeroFuncao]);



    return cont3;
}

int abrirPaciente4() {
    const int numeroFuncao = 4;

    int cont4 = 0;

    Bin[numeroFuncao] = fopen("paciente4.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return -2;
    }

    rewind(Bin[numeroFuncao]);

    while (cont4 < MAXREG && fread(&pacientes[cont4], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont4++;

    }


    fclose(Bin[numeroFuncao]);


    return cont4;



}
int paciente4() {
    const int numeroFuncao = 4;
    int cont4 = abrirPaciente4();
    int contBin = cont4;

    if (cont4 == MAXREG) {

        fputs("O Registro está cheio.\n", stderr);

        return cont4;

    }

    if (cont4 == 0)

        puts("Nenhum Cadastro de paciente.");

    else

        printf("Cadastrados [%d] registros de pacientes.\n",cont4);


    if (cont4 == -2) {

        return cont4;
    }

    while (cont4 < MAXREG) {

        pacientes[cont4].codNum = cont4 + 1;
        printf("Código do Paciente: '%d'\n", pacientes[cont4].codNum);

        printf("Digite o CPF do paciente: \n");
        scanf("%s", pacientes[cont4].CPF);
        limparBuffer();
        printf("Digite o nome do paciente: \n");
        gets(pacientes[cont4].nomePaciente);
        printf("Digite a idade do paciente: \n");
        scanf("%d", &pacientes[cont4].idade);
        limparBuffer();
        printf("Qual o genero do paciente? (M/F) \n");
        scanf("%c", &pacientes[cont4].genero);
        limparBuffer();
        printf("Digite o telefone do paciente: \n");
        scanf("%s", pacientes[cont4].telefone);
        limparBuffer();

        printf("Digite o endereco do paciente: \n");
        printf("Rua:\n");
        gets(pacientes[cont4].endereco.rua);
        printf("Numero:\n");
        scanf("%d", &pacientes[cont4].endereco.numero);
        limparBuffer();
        printf("Bairro:\n");
        gets(pacientes[cont4].endereco.bairro);
        printf("Cidade:\n");
        gets(pacientes[cont4].endereco.cidade);
        printf("Estado:\n");
        gets(pacientes[cont4].endereco.estado);

        printf("CEP:\n");
        scanf("%s", pacientes[cont4].endereco.CEP);
        limparBuffer();

        printf("Predisposicao Genetica do paciente:\n");
        gets(pacientes[cont4].predGenetica);
        printf("Há algum risco associado ao paciente?\nJá toma algum medicamento?\nEstá exposto a agentes nocivos à saúde?\nTrabalha em ambiente insalubre?\nDentre outros\n");
        printf("(S/N)\n");
        scanf(" %c", &ok);
        limparBuffer();

        if (ok == 's' || ok == 'S') {

            printf("Toma algum medicamento?\n");
            gets(pacientes[cont4].risco.medicamento);
            printf("Está exposto a agentes nocivos à saúde?\n");
            gets(pacientes[cont4].risco.agentes);
            printf("Trabalha em ambiente insalubre?\n");
            gets(pacientes[cont4].risco.ambiente);
            printf("Outros?\n");
            gets(pacientes[cont4].risco.outros);

        }

        printf("Quais exames ja foram realizados?\n");
        gets(pacientes[cont4].exames);
        printf("Quais os resultados de exames anteriores?\n");
        gets(pacientes[cont4].resultados);


        cont4++;

        if (cont4 != MAXREG) {

            if (sair() == 1)
                break;
        }

    }

    if (cont4 > 0) {

        //preciso pra alguma coisa talvez
        puts("Lista de Pacientes cadastrados:");

        for (i = 0; i < cont4; i++)

            printf("%d - %s, %d anos, %c\n",pacientes[i].codNum, pacientes[i].nomePaciente, pacientes[i].idade, pacientes[i].genero);

        Bin[numeroFuncao] = fopen("paciente4.bin","a+b");

        if (Bin[numeroFuncao] == NULL) {

            fputs("Nao foi possivel abrir o arquivo\n",stderr);
            return 1;

        }

        total = fwrite(&pacientes[contBin], REG[numeroFuncao], cont4 - contBin, Bin[numeroFuncao]);

        if (total != cont4 - contBin) {

            printf("Erro na escritura\n");

        }
    }

    fclose(Bin[numeroFuncao]);

    return cont4;
}

int abrirTratamento5() {
    const int numeroFuncao = 4;

    int cont4 = 0;

    Bin[numeroFuncao] = fopen("paciente4.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return -2;
    }

    rewind(Bin[numeroFuncao]);

    while (cont4 < MAXREG && fread(&pacientes[cont4], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont4++;

    }


    fclose(Bin[numeroFuncao]);


    return cont4;



}
int tratamento5() {
    const int numeroFuncao = 5;
    int codRegistro, op;
    int contDoenca;
    int contPaciente;
    int contMedico;

    for (i = 0; i < MAXREG; i++) {

        tratamentos[i].codNum = i + 1;
        printf("Codigo de identificacao:  '%d'\n", tratamentos[i].codNum);


        printf("Informe o codigo de identificacao da doenca: ");
        scanf("%d",&codRegistro);

        codRegistro = codRegistro - 1;
        if (contDoenca <= codRegistro) {
            do {
                printf("Doenca não cadastrada.\n1. Cadastrar?\n2. Digitar outra\n> ");
                scanf("%d", &op);
                switch (op) {
                    case 1:
                        doenca1();
                        marca1 = 1;
                        printf("Digite outro codigo de doenca: ");
                        scanf("%d", &codRegistro);
                        codRegistro = codRegistro - 1;
                        break;
                    case 2:
                        printf("Digite outro codigo de doenca: ");
                        scanf("%d", &codRegistro);
                        codRegistro = codRegistro - 1;
                    default:
                        if (contDoenca <= codRegistro) {
                            printf("Digite novamente\n");
                        }
                }
            } while (contDoenca <= codRegistro);

        }

        printf("Nome da doenca: ");
        puts(doencas[codRegistro].nomeDoenca);

        tratamentos[i].codDoenca = codRegistro;

        printf("Informe o codigo de identificacao do paciente: ");
        scanf("%d",&codRegistro);

        if(marca4 == 0) {

        }

        codRegistro = codRegistro - 1;
        if (contPaciente <= codRegistro) {
            do {
                printf("Paciente não cadastrado.\n1. Cadastrar?\n2. Digitar outro\n> ");
                scanf("%d", &op);
                switch (op) {
                    case 1:
                        paciente4();
                        marca4 = 1;
                        printf("Digite outro codigo de paciente: ");
                        scanf("%d", &codRegistro);
                        codRegistro = codRegistro - 1;
                        break;
                    case 2:
                        printf("Digite outro codigo de paciente: ");
                        scanf("%d", &codRegistro);
                        codRegistro = codRegistro - 1;
                    default:
                        if (contPaciente <= codRegistro) {
                            printf("Digite novamente\n");
                        }
                }
            } while (contPaciente <= codRegistro);

        }

        printf("Nome do paciente: ");
        puts(pacientes[codRegistro].nomePaciente);

        tratamentos[i].codPaciente = codRegistro;

        printf("Informe o codigo de identificacao do medico: ");
        scanf("%d",&codRegistro);

        codRegistro = codRegistro - 1;
        if (contMedico <= codRegistro) {
            do {
                printf("Medico não cadastrado.\n1. Cadastrar?\n2. Digitar outro\n> ");
                scanf("%d", &op);
                switch (op) {
                    case 1:
                        medico3();
                        marca3 = 1;
                        printf("Digite outro codigo de medico: ");
                        scanf("%d", &codRegistro);
                        codRegistro = codRegistro - 1;
                        break;
                    case 2:
                        printf("Digite outro codigo de medico: ");
                        scanf("%d", &codRegistro);
                        codRegistro = codRegistro - 1;
                    default:
                        if (contMedico <= codRegistro) {
                            printf("Digite novamente\n");
                        }
                }
            } while (contMedico <= codRegistro);

        }

        printf("Nome do medico: ");
        puts(medicos[codRegistro].nomeMedico);

        tratamentos[i].codMedico = codRegistro;

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
    return 0;
}

int abrirMedicamento6() {
    const int numeroFuncao = 6;

    int cont6 = 0;

    Bin[numeroFuncao] = fopen("medicamento6.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return -2;
    }

    rewind(Bin[numeroFuncao]);

    while (cont6 < MAXREG && fread(&medicamentos[cont6], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont6++;

    }


    fclose(Bin[numeroFuncao]);


    return cont6;



}
int medicamento6() {
    const int numeroFuncao = 6;
    int cont6 = abrirMedicamento6();
    int contBin = cont6;

    if (cont6 == MAXREG) {

        fputs("O Registro está cheio.\n", stderr);

        return cont6;

    }

    if (cont6 == 0)

        puts("Nenhum Cadastro de Medicamento.");

    else

        printf("Cadastrados [%d] registros de Medicamentos.\n",cont6);


    if (cont6 == -2) {

        return cont6;
    }


    while (cont6 < MAXREG) {

        medicamentos[cont6].codNum = cont6 + 1;
        printf ("Codigo do medicamento: '%d'\n", medicamentos[cont6].codNum);
        printf("Nome do medicamento:\n");

        gets(medicamentos[cont6].nomeMedicamento);

        printf("Para quais pacientes o medicamento e indicado?\n");
        gets(medicamentos[cont6].indicacao);

        printf("Informe a posologia:\n");
        gets(medicamentos[cont6].posologia);
        printf("Informe a faixa etaria indicada para o uso do medicamento:\n");
        scanf("%d", &medicamentos[cont6].faixaEtaria);
        limparBuffer();

        printf("Para quais pacientes o medicamento e contra indicado?\n");
        gets(medicamentos[cont6].contraIndicacao);

        cont6++;

        if (cont6 != MAXREG) {

            if (sair() == 1)
                break;
        }

    }

    if (cont6 > 0) {

        //preciso pra alguma coisa talvez
        puts("Lista de Pacientes cadastrados:");

        for (i = 0; i < cont6; i++)

            printf("%d - %s, %d\n",exames[i].codNum, exames[i].nomeExame, exames[i].pgto);


        Bin[numeroFuncao] = fopen("medicamento6.bin","a+b");

        if (Bin[numeroFuncao] == NULL) {

            fputs("Nao foi possivel abrir o arquivo\n",stderr);
            return 1;

        }

        total = fwrite(&medicamentos[contBin], REG[numeroFuncao], cont6 - contBin, Bin[numeroFuncao]);

        if (total != cont6 - contBin) {

            printf("Erro na escritura\n");

        }

    }


    fclose(Bin[numeroFuncao]);

    return cont6;


}

int abrirExame7() {
    const int numeroFuncao = 7;

    int cont7 = 0;

    Bin[numeroFuncao] = fopen("exame7.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return -2;
    }

    rewind(Bin[numeroFuncao]);

    while (cont7 < MAXREG && fread(&exames[cont7], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont7++;

    }


    fclose(Bin[numeroFuncao]);


    return cont7;



}
int exame7() {
    const int numeroFuncao = 7;
    int cont7 = abrirExame7();
    int contBin = cont7;

    if (cont7 == MAXREG) {

        fputs("O Registro está cheio.\n", stderr);

        return cont7;

    }

    if (cont7 == 0)

        puts("Nenhum Cadastro de Exame.");

    else

        printf("Cadastrados [%d] registros de Exames.\n",cont7);


    if (cont7 == -2) {

        return cont7;
    }

    while (cont7 < MAXREG) {

        exames[cont7].codNum = cont7 + 1;
        printf ("Codigo do exame: '%d'\n", exames[cont7].codNum);
        printf("Nome do exame \n");
        gets(exames[cont7].nomeExame);

        do {
            printf("A forma de pagamento\n1. Convenio\n2. Particular\n3. Gratuito\n");
            scanf("%d",&exames[cont7].pgto);
            limparBuffer();
            switch (exames[cont7].pgto) {

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
                    if(exames[cont7].pgto <= 0 || exames[cont7].pgto > 3)
                        printf("Opcao invalida\n");
            }


        } while (exames[cont7].pgto <= 0 || exames[cont7].pgto > 3);


        cont7++;

        if (cont7 != MAXREG) {

            if (sair() == 1)
                break;
        }

    }

    if (cont7 > 0) {

        //preciso pra alguma coisa talvez
        puts("Lista de Pacientes cadastrados:");

        for (i = 0; i < cont7; i++)

            printf("%d - %s, %d\n",exames[i].codNum, exames[i].nomeExame, exames[i].pgto);


        Bin[numeroFuncao] = fopen("exame7.bin","a+b");

        if (Bin[numeroFuncao] == NULL) {

            fputs("Nao foi possivel abrir o arquivo\n",stderr);
            return 1;

        }

        total = fwrite(&exames[contBin], REG[numeroFuncao], cont7 - contBin, Bin[numeroFuncao]);

        if (total != cont7 - contBin) {

            printf("Erro na escritura\n");

        }

    }


    fclose(Bin[numeroFuncao]);

    return cont7;
}
