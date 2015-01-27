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


#define MAXREG 10
#define TAM1 50
#define TAM2 100
#define TAM3 300
#define TAM4 500

//CONTADORES

//int cont;
int i, j;
long int total;

//VARIAVEIS DE VEREIFICACAO
char ok;
int op;


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
    int codSintoma[MAXREG];
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
    char rua[TAM2], bairro[TAM1], cidade[TAM2], estado[TAM1], CEP[9];
    int numero;
}reg14;

struct reg4 {
    int idade, codNum, codExame[MAXREG];
    char nomePaciente[TAM2], genero;
    int resultados;
    char CPF[15], telefone[20];
    int risco, predGenetica;
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


//DECLARAÇÃO DE REGISTROS

struct reg1 doencas[MAXREG];
struct reg2 sintomas[MAXREG];
struct reg3 medicos[MAXREG];
struct reg4 pacientes[MAXREG];
struct reg5 tratamentos[MAXREG];
struct reg6 medicamentos[MAXREG];
struct reg7 exames[MAXREG];



//TAMANHO DE REGISTROS

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
int sintomasDoenca();
void listaSintomas();
void listaPacientes();
void listaExames();
void limparBuffer();


//PROTÓTIPO DE FUNÇÕES ESPECIAIS

int codigoPaciente(int, int, int);


//ARQUIVOS

FILE *Bin[8];


//PROTÓTIPO DE FUNÇÕES DE ABERTURA DE ARQUIVOS

int abrirDoenca1();
int abrirSintoma2();
int abrirMedico3();
int abrirPaciente4();
int abrirTratamento5();
int abrirMedicamento6();
int abrirExame7();

int main() {

    int marca1 = 0;
    int marca2 = 0;
    int marca3 = 0;
    int marca4 = 0;
    int marca5 = 0;
    int marca6 = 0;
    int marca7 = 0;
    int op, marca = 0;

    if (marca == 0) {

        marca1 = abrirDoenca1();
        marca2 = abrirSintoma2();
        marca3 = abrirMedico3();
        marca4 = abrirPaciente4();
        marca5 = abrirTratamento5();
        marca6 = abrirMedicamento6();
        marca7 = abrirExame7();

        marca = 1;

    }


    do {
        printf("\nEscolha a opcao desejada:\n");
        printf("1. Cadastrar doenças\n");
        printf("2. Cadastrar sintomas\n");
        printf("3. Cadastrar médicos\n");
        printf("4. Cadastrar pacientes\n");
        printf("5. Cadastrar tratamentos\n");
        printf("6. Cadastrar medicamentos\n");
        printf("7. Cadastrar exames\n");
        printf("8. Quantos e quais sintomas podem causar uma determinada doença\n");




        printf("9. Sair\n\n> ");

        scanf(" %d",&op);
        limparBuffer();
        switch (op) {
            case 1:
                if (marca2 == 0) {

                    printf("Você não tem nenhum sintoma cadastrado. Cadastre para continuar!\n");
                    marca2 = sintoma2();
                    marca1 = doenca1();
                }
                marca1 = doenca1();
                break;
            case 2:
                marca2 = sintoma2();
                break;
            case 3:
                if (marca4 == 0) {

                    printf("Você não tem nenhum paciente cadastrado. Cadastre para continuar!\n");
                    marca4 = paciente4();
                    marca3 = medico3();
                }

                marca3 = medico3();

                break;
            case 4:
                if (marca7 == 0) {

                    printf("Você não tem nenhum exame cadastrado. Cadastre para continuar!\n");
                    marca7 = exame7();
                    marca4 = paciente4();
                }
                marca4 = paciente4();
                break;
            case 5:
                if (marca1 == 0) {

                    printf("Você não tem nenhuma doença cadastrada. Cadastre para continuar!\n");

                    doenca1();
                    marca1 = 1;
                    marca5 = tratamento5();

                }
                else if (marca4 == 0) {

                    printf("Você não tem nenhum paciente cadastrado. Cadastre para continuar!\n");
                    marca4 = paciente4();
                    marca5 = tratamento5();
                }
                else
                    marca5 = tratamento5();
                break;
            case 6:
                marca6 = medicamento6();
                break;
            case 7:
                marca7 = exame7();
                break;
            case 8:
                if (marca1 == 0) {

                    printf("Você não tem nenhuma doença cadastrada. Cadastre para continuar!\n");

                    marca1 = doenca1();
                    sintomasDoenca();

                }
                else if (marca4 == 0) {

                    printf("Você não tem nenhum paciente cadastrado. Cadastre para continuar!\n");
                    marca4 = paciente4();
                    sintomasDoenca();
                }
                else if (marca2 == 0) {

                    printf("Você não tem nenhum sintoma cadastrado. Cadastre para continuar!\n");
                    marca2 = sintoma2();
                    sintomasDoenca();

                }

                sintomasDoenca();
                break;
            default:
                if (op != 9)
                    printf("Opcao invalida!\n");
                break;
        }
    } while (op != 9);



    return 0;
}


int codigoPaciente(int cod, int contPaciente, int cont) {

    for (i = 0; i < contPaciente; i++) {

        if (cod == medicos[cont].codPaciente[i]) {

            puts("Paciente ja cadastrado no registro do medico");

            return 1;
        }

    }

    return 0;

}

void listaSintomas() {
    int cont = abrirSintoma2();

    for (i = 0; i < cont; i++) {

        if (i == 0)

            puts("Lista de Sintomas:");


        printf("%d. %s, ",sintomas[i].codNum, sintomas[i].descricao);

        if (sintomas[i].nivel == 1)
            puts("Baixo");
        else if (sintomas[i].nivel == 2)
            puts("Medio");
        else
            puts("Alto");


    }


}
void listaPacientes() {

    int cont = abrirPaciente4();

    for (i = 0; i < cont; i++) {

        if (i == 0)

            puts("Lista de Pacientes:");


        printf("%d. %s, %d anos\n",pacientes[i].codNum, pacientes[i].nomePaciente, pacientes[i].idade);

    }


}
void listaExames() {


    int cont = abrirExame7(0);

    for (i = 0; i < cont; i++) {

        if (i == 0)

            puts("Lista de Exames:");


        printf("%d. %s, ",i + 1, exames[i].nomeExame);

        if (exames[i].pgto == 1)
            puts("Convenio");
        else if (exames[i].pgto == 2)
            puts("Particular");
        else
            puts("Gratuito");

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
    //CONSTANTE INTEIRA QUE RECEBE O VALOR DO NUMERO DA FUNCAO
    const int numeroFuncao = 1;

    int cont = 0;

    //ABRE O ARQUIVO

    Bin[numeroFuncao] = fopen("doenca1.bin","a+b"); //"NOME DO ARQUIVO.BIN",
                                                    //a = ADICIONAR, b = BINARIO, a+b = LER E ESCREVER NO FINAL DE UM ARQUIVO BINARIO

    //TESTA O ARQUIVO PARA SABER SE ABRIU

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        exit(1);
    }

    //VOLTA NO COMECO DO ARQUIVO
    rewind(Bin[numeroFuncao]);


    //LACO DE REPETICAO PARA LER O CONTEUDO DO ARQUIVO E PASSAR PARA AS VARIAVEIS NOS REGISTROS
    while (cont < MAXREG && fread(&doencas[cont], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont++;

    }

    //FECHA O ARQUIVO
    fclose(Bin[numeroFuncao]);

    //TESTE PARA SABER SE O REGISTRO ESTA CHEIO
    if (cont == MAXREG) {

        printf("Registro %d está cheio.\n", numeroFuncao);

        return cont;

    }
    //IMPRIME SE NAO TEM NENHUM REGISTRO CADASTRADO
    if (cont == 0)

        puts("Nenhum Cadastro no registro de Doencas.");


    //RETORNA O VALOR DE REGISTROS CADASTRADOS
    return cont;


}
int doenca1() {
    const int numeroFuncao = 1;
    int contSintoma = abrirSintoma2();
    int cont = abrirDoenca1(); //VARIAVEL QUE RECEBE O VALOR RETORNADO DE UMA FUNCAO PARA ABERTURA DO ARQUIVO
    int contBin = cont; //CONTBIN RECEBE O VALOR ATUAL REGISTRO CADASTRADOS
    int cont2;
    int codRegistro;

    while (cont < MAXREG) {

        //REGISTRO DE INFORMACOES GERAIS DA DOENCA

        doencas[cont].codNum = cont + 1;
        printf("Codigo de identificacao: %d \n",doencas[cont].codNum);
        printf("Informe o nome da doenca:\n");
        gets(doencas[cont].nomeDoenca);

        printf("Descreva a doenca \n");
        gets(doencas[cont].descricao);



        //EXAMES REALIZADOS PELO PACIENTE

        listaSintomas();
        printf("Quais sao os sintomas da doenca?\n");


        cont2 = 0;

        while (cont2 < contSintoma) {  //LAÇO DE REPETICAO PARA SABER OS EXAMES DO PACIENTE

            printf("Codigo: ");
            scanf("%d",&codRegistro);
            limparBuffer();


            if (contSintoma < codRegistro || codRegistro < 1) {

                do {

                    printf("Sintoma não cadastrado.\n1. Cadastrar.\n2. Digitar outro codigo de Sintoma.\n> ");
                    scanf("%d", &op);
                    switch (op) {
                        case 1:
                            contSintoma = sintoma2();
                            printf("Digite outro codigo de Exame: ");
                            scanf("%d", &codRegistro);
                            limparBuffer();

                            break;
                        case 2:
                            printf("Digite outro codigo de Exame: ");
                            scanf("%d", &codRegistro);
                            limparBuffer();
                            break;
                        default:
                            printf("Digite novamente\n");
                            break;
                    }

                } while (contSintoma < codRegistro || codRegistro < 1);

            }






            printf("Descricao do Sintoma: %s\n",sintomas[codRegistro - 1].descricao);

            sintomas[contSintoma].codSintoma[cont2] = codRegistro;

            cont2++;

            if (cont2 != contSintoma) {

                puts("Você deseja informar mais algum sintoma? (S/N)");
                ok = getchar();
                limparBuffer();

                if (ok == 'S' || ok == 's')

                    continue;

                break;


            }

        }

        cont++;

        if (cont != MAXREG) {

            if (sair() == 1)
                break;

        }


    }

    //LISTA DE DOENCAS CADATRADAS

    if (cont > 0) {

        puts("Lista de Doencas cadastradas:");

        for (i = 0; i < cont; i++) {

            printf("%d. %s\n",doencas[i].codNum, doencas[i].nomeDoenca);

        }

        //SALVAR NO ARQUIVO

        Bin[numeroFuncao] = fopen("doenca1.bin","a+b");

        if (Bin[numeroFuncao] == NULL) {

            fputs("Nao foi possivel abrir o arquivo\n",stderr);
            exit(0);

        }

        total = fwrite(&doencas[contBin], REG[numeroFuncao], cont - contBin, Bin[numeroFuncao]);

        if (total != cont - contBin) {
            printf("Erro na escritura\n");

        }

        fclose(Bin[numeroFuncao]);


    }

    return cont;
}

int abrirSintoma2() {
    const int numeroFuncao = 2;

    int cont = 0;

    Bin[numeroFuncao] = fopen("sintoma2.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        exit(1);
    }

    rewind(Bin[numeroFuncao]);

    while (cont < MAXREG && fread(&sintomas[cont], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont++;

    }


    fclose(Bin[numeroFuncao]);

    if (cont == MAXREG) {

        printf("Registro %d está cheio.\n", numeroFuncao);

        return cont;

    }

    if (cont == 0)

        puts("Nenhum Cadastro no registro de Sintomas.");


    return cont;



}
int sintoma2() {
    const int numeroFuncao = 2;

    int cont = abrirSintoma2();
    int contBin = cont;

    //REGISTRO DE INFORMACOES GERAIS DOS SINTOMAS
    while (cont < MAXREG) {

        sintomas[cont].codNum = cont + 1;
        printf("Codigo de identificacao: %d\n",sintomas[cont].codNum);
        puts("Descreva os Sintomas:");
        gets(sintomas[cont].descricao);

        printf("Informe o nivel de severidade do sintoma:\n");

        do { //LACO PARA DETERMINAR A SEVERIDADE DO SINTOMA

            printf("1. Baixo \n2. Medio \n3. Alto \n");
            scanf("%d",&sintomas[cont].nivel);
            limparBuffer();

            switch (sintomas[cont].nivel) {
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
                    break;
            }

        } while (sintomas[cont].nivel <= 0 || sintomas[cont].nivel > 3);



        cont++;

        if (cont != MAXREG) {

            if (sair() == 1)
                break;
        }

    }

    //LISTA DOS SINTOMAS CADASTRADOS

    if (cont > 0) {

        puts("Lista de Sintomas cadastrados:");

        for (i = 0; i < cont; i++) {

            printf("%d. %s, ",sintomas[i].codNum, sintomas[i].descricao);

            if (sintomas[i].nivel == 1)
                puts("Severidade Baixa");
            else if (sintomas[i].nivel == 2)
                puts("Severidade Media");
            else
                puts("Severidade Alta");

        }


        //SALVAR NO ARQUIVO

        Bin[numeroFuncao] = fopen("sintoma2.bin","a+b");

        if (Bin[numeroFuncao] == NULL) {

            fputs("Nao foi possivel abrir o arquivo\n",stderr);
            exit(0);
        }


        total = fwrite(&sintomas[contBin], REG[numeroFuncao], cont - contBin, Bin[numeroFuncao]);

        if (total != cont - contBin) {
            printf("Erro na escritura\n");

        }
    }

    fclose(Bin[numeroFuncao]);

    return cont;
}

int abrirMedico3() {
    const int numeroFuncao = 3;

    int cont = 0;

    Bin[numeroFuncao] = fopen("medico3.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        exit(1);

    }

    rewind(Bin[numeroFuncao]);

    while (cont < MAXREG && fread(&medicos[cont], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {


        cont++;

    }

    fclose(Bin[numeroFuncao]);

    if (cont == MAXREG) {

        printf("Registro %d está cheio.\n", numeroFuncao);

        return cont;

    }

    if (cont == 0)

        puts("Nenhum Cadastro no registro de Medicos.");

    return cont;



}
int medico3() {
    const int numeroFuncao = 3;
    int cont4;
    int codRegistro, op;
    int cont = abrirMedico3();
    int contPaciente = abrirPaciente4();
    int contBin = cont;

    while (cont < MAXREG) {

        printf("Digite o CRM:\n");
        scanf("%d", &medicos[cont].CRM);
        limparBuffer();

        printf("Digite o nome do Medico:\n");
        gets(medicos[cont].nomeMedico);

        printf("Informe o CPF: \n");
        scanf("%s", medicos[cont].CPF);
        limparBuffer();

        printf("Digite o Telefone do medico: \n");
        scanf("%s", medicos[cont].telefone);
        limparBuffer();


        printf("Digite o endereco da clinica/hospital\n");

        printf("Rua:\n");
        gets(medicos[cont].endereco.rua);

        printf("Numero:\n");
        scanf("%d", &medicos[cont].endereco.numero);
        limparBuffer();

        printf("Bairro:\n");
        gets(medicos[cont].endereco.bairro);

        printf("Cidade:\n");
        gets(medicos[cont].endereco.cidade);

        printf("Estado:\n");
        gets(medicos[cont].endereco.estado);

        printf("CEP:\n");
        scanf("%s", medicos[cont].endereco.CEP);
        limparBuffer();

        cont4 = 0;

        listaPacientes();

        printf("\nInforme o codigo de identificacao dos pacientes atendidos pelo medico\n");


        while (cont4 < contPaciente) {

            printf("Codigo: ");
            scanf("%d",&codRegistro);
            limparBuffer();

            if (codigoPaciente(codRegistro, cont4, contPaciente) == 1)

                continue;



            if (contPaciente < codRegistro || codRegistro < 1) {

                do {

                    printf("Paciente não cadastrado.\n1. Cadastrar.\n2. Digitar outro codigo de Paciente.\n> ");
                    scanf("%d", &op);
                    switch (op) {
                        case 1:
                            contPaciente = paciente4();
                            printf("Digite outro codigo de Paciente: ");
                            scanf("%d", &codRegistro);
                            limparBuffer();
                            if (codigoPaciente(codRegistro, cont4, contPaciente) == 1) {
                                goto continuar;
                            }
                            break;
                        case 2:
                            printf("Digite outro codigo de Paciente: ");
                            scanf("%d", &codRegistro);
                            limparBuffer();
                            if (codigoPaciente(codRegistro, cont4, contPaciente) == 1) {
                                goto continuar;
                            }
                            break;
                        default:
                            printf("Digite novamente\n");
                            break;
                    }

                } while (contPaciente < codRegistro || codRegistro < 1);

            }






            printf("Nome do paciente: %s\n",pacientes[codRegistro - 1].nomePaciente);

            medicos[cont].codPaciente[cont4] = codRegistro;

            cont4++;

            if (cont4 != contPaciente) {

                puts("Você deseja informar mais algum paciente? (S/N)");
                ok = getchar();
                limparBuffer();

                if (ok == 'S' || ok == 's')

                    continuar: continue;

                break;


            }



        }



        printf("\nNome e idade de todos os pacientes atendidos pelo medico:\n");

        for (i = 0; i < cont4; i++) {

            codRegistro = medicos[cont].codPaciente[i];

            printf("%d. %s, %d anos\n", codRegistro, pacientes[codRegistro - 1].nomePaciente, pacientes[codRegistro - 1].idade);

        }

        cont++;

        if (cont != MAXREG) {

            if (sair() == 1)
                break;
        }

    }


    if (cont > 0) {

        Bin[numeroFuncao] = fopen("medico3.bin","a+b");

        if (Bin[numeroFuncao] == NULL) {

            fputs("Nao foi possivel abrir o arquivo\n",stderr);
            return 1;

        }

        total = fwrite(&medicos[contBin], REG[numeroFuncao], cont - contBin, Bin[numeroFuncao]);

        if (total != cont - contBin) {
            printf("Erro na escritura\n");

        }
    }

    fclose(Bin[numeroFuncao]);



    return cont;
}

int abrirPaciente4() {
    const int numeroFuncao = 4;

    int cont = 0;

    Bin[numeroFuncao] = fopen("paciente4.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        exit(1);
    }

    rewind(Bin[numeroFuncao]);

    while (cont < MAXREG && fread(&pacientes[cont], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont++;

    }


    fclose(Bin[numeroFuncao]);

    if (cont == MAXREG) {

        printf("Registro %d está cheio.\n", numeroFuncao);

        return cont;

    }

    if (cont == 0)

        puts("Nenhum Cadastro no registro de Pacientes.");


    return cont;



}
int paciente4() {
    const int numeroFuncao = 4;
    int cont = abrirPaciente4();
    int contBin = cont;
    int contExame = abrirExame7();
    int cont7;
    int codRegistro;

    while (cont < MAXREG) {

        //REGISTRO DE INFORMACOES GERAIS DO PACIENTE

        pacientes[cont].codNum = cont + 1;
        printf("Código do Paciente: '%d'\n", pacientes[cont].codNum);

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

        do {

            printf("Paciente com antecedentes da doenca na Familia?\n");
            printf("1. Sim\n2. Nao\n");
            scanf("%d", &pacientes[cont].predGenetica);
            limparBuffer();

        } while (pacientes[cont].predGenetica != 1 || pacientes[cont].predGenetica != 2);

        do {

            printf("Há algum risco associado ao paciente?\n(Toma algum medicamento. Está exposto a agentes nocivos à saúde. Trabalha em ambiente insalubre.)\n");
            printf("1. Sim\n2. Nao\n");
            scanf("%d", &pacientes[cont].risco);
            limparBuffer();
        } while (pacientes[cont].predGenetica != 1 || pacientes[cont].predGenetica != 2);

        //EXAMES REALIZADOS PELO PACIENTE

        listaExames();
        printf("\nQuais exames ja foram realizados?\n");

        cont7 = 0;

        while (cont7 < contExame) {  //LAÇO DE REPETICAO PARA SABER OS EXAMES DO PACIENTE

            printf("Codigo: ");
            scanf("%d",&codRegistro);
            limparBuffer();


            if (contExame < codRegistro || codRegistro < 1) {

                do {

                    printf("Exame não cadastrado.\n1. Cadastrar.\n2. Digitar outro codigo de Exame.\n> ");
                    scanf("%d", &op);
                    switch (op) {
                        case 1:
                            contExame = exame7();
                            printf("Digite outro codigo de Exame: ");
                            scanf("%d", &codRegistro);
                            limparBuffer();

                            break;
                        case 2:
                            printf("Digite outro codigo de Exame: ");
                            scanf("%d", &codRegistro);
                            limparBuffer();
                            break;
                        default:
                            printf("Digite novamente\n");
                            break;
                    }

                } while (contExame < codRegistro || codRegistro < 1);

            }






            printf("Nome do Exame: %s\n",exames[codRegistro - 1].nomeExame);

            pacientes[contExame].codExame[cont7] = codRegistro;

            cont7++;

            if (cont7 != contExame) {

                puts("Você deseja informar mais algum exame? (S/N)");
                ok = getchar();
                limparBuffer();

                if (ok == 'S' || ok == 's')

                    continue;

                break;


            }



        }

        printf("\nResultados de exames anteriores.\n");

        do {

            printf("Informe o nivel de seriedade dos exames\n");
            printf("1. Normal \n2. Media \n3. Grave \n4. Gravissima\n");
            scanf("%d",&pacientes[cont].resultados);
            limparBuffer();


            switch (pacientes[cont].resultados) {
                case 1:
                    printf("Normal\n");
                    break;
                case 2:
                    printf("Media\n");
                    break;
                case 3:
                    printf("Grave\n");
                    break;
                case 4:
                    printf("Gravissima\n");
                    break;
                default:
                    printf("Opcao invalida\n");
            }

        } while (pacientes[cont].resultados <= 0 || pacientes[cont].resultados > 4);




        cont++;

        if (cont != MAXREG) {

            if (sair() == 1)
                break;
        }

    }

    //MOSTRA LISTA DE PACIENTES CADASTRADOS

    if (cont > 0) {

        puts("Lista de Pacientes cadastrados:");

        for (i = 0; i < cont; i++)

            printf("%d - %s, %d anos, %c\n",pacientes[i].codNum, pacientes[i].nomePaciente, pacientes[i].idade, pacientes[i].genero);


        //SALVA NO ARQUIVO

        Bin[numeroFuncao] = fopen("paciente4.bin","a+b");

        if (Bin[numeroFuncao] == NULL) {

            fputs("Nao foi possivel abrir o arquivo\n",stderr);
            exit(1);

        }



        total = fwrite(&pacientes[contBin], REG[numeroFuncao], cont - contBin, Bin[numeroFuncao]);

        if (total != cont - contBin) {

            printf("Erro na escritura\n");

        }
    }

    fclose(Bin[numeroFuncao]);

    return cont;
}

int abrirTratamento5() {
    const int numeroFuncao = 4;

    int cont = 0;

    Bin[numeroFuncao] = fopen("paciente4.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return -2;
    }

    rewind(Bin[numeroFuncao]);

    while (cont < MAXREG && fread(&pacientes[cont], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont++;

    }


    fclose(Bin[numeroFuncao]);


    return cont;



}
int tratamento5() {
    const int numeroFuncao = 5;
    int codRegistro, op;
    int contDoenca = abrirDoenca1();
    int contPaciente = abrirPaciente4();
    int contMedico = abrirMedico3();
    int cont = abrirTratamento5();
    int contBin = cont;

    if (cont == -2) {

        return cont;
    }

    if (cont == MAXREG) {

        fputs("O Registro está cheio.\n", stderr);

        return cont;

    }

    if (cont == 0)

        puts("Nenhum Cadastro de paciente.");

    else

        printf("Cadastrados [%d] registros de pacientes.\n",cont);



    for (i = 0; i < MAXREG; i++) {

        tratamentos[i].codNum = i + 1;
        printf("Codigo de identificacao:  '%d'\n", tratamentos[i].codNum);


        printf("Informe o codigo de identificacao da doenca: ");
        scanf("%d",&codRegistro);


        if (contDoenca < codRegistro) {
            do {
                printf("Doenca não cadastrada.\n1. Cadastrar?\n2. Digitar outra\n> ");
                scanf("%d", &op);
                switch (op) {
                    case 1:
                        doenca1();
                        //marca1 = 1;
                        printf("Digite outro codigo de doenca: ");
                        scanf("%d", &codRegistro);
                        break;
                    case 2:
                        printf("Digite outro codigo de doenca: ");
                        scanf("%d", &codRegistro);
                    default:
                        if (contDoenca < codRegistro) {
                            printf("Digite novamente\n");
                        }
                }
            } while (contDoenca < codRegistro);

        }

        printf("Nome da doenca: ");
        puts(doencas[codRegistro].nomeDoenca);

        tratamentos[i].codDoenca = codRegistro;

        printf("Informe o codigo de identificacao do paciente: ");
        scanf("%d",&codRegistro);

        //if(marca4 == 0) {

        //}

        codRegistro = codRegistro - 1;
        if (contPaciente <= codRegistro) {
            do {
                printf("Paciente não cadastrado.\n1. Cadastrar?\n2. Digitar outro\n> ");
                scanf("%d", &op);
                switch (op) {
                    case 1:
                        paciente4();
                        //marca4 = 1;
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
                        //marca3 = 1;
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

    int cont = 0;

    Bin[numeroFuncao] = fopen("medicamento6.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return -2;
    }

    rewind(Bin[numeroFuncao]);

    while (cont < MAXREG && fread(&medicamentos[cont], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont++;

    }


    fclose(Bin[numeroFuncao]);


    return cont;



}
int medicamento6() {
    const int numeroFuncao = 6;
    int cont = abrirMedicamento6();
    int contBin = cont;

    if (cont == -2) {

        return cont;
    }

    if (cont == MAXREG) {

        fputs("O Registro está cheio.\n", stderr);

        return cont;

    }

    if (cont == 0)

        puts("Nenhum Cadastro de Medicamento.");

    else

        printf("Cadastrados [%d] registros de Medicamentos.\n",cont);





    while (cont < MAXREG) {

        medicamentos[cont].codNum = cont + 1;
        printf ("Codigo do medicamento: '%d'\n", medicamentos[cont].codNum);
        printf("Nome do medicamento:\n");

        gets(medicamentos[cont].nomeMedicamento);

        printf("Para quais pacientes o medicamento e indicado?\n");
        gets(medicamentos[cont].indicacao);

        printf("Informe a posologia:\n");
        gets(medicamentos[cont].posologia);
        printf("Informe a faixa etaria indicada para o uso do medicamento:\n");
        scanf("%d", &medicamentos[cont].faixaEtaria);
        limparBuffer();

        printf("Para quais pacientes o medicamento e contra indicado?\n");
        gets(medicamentos[cont].contraIndicacao);

        cont++;

        if (cont != MAXREG) {

            if (sair() == 1)
                break;
        }

    }

    if (cont > 0) {

        //preciso pra alguma coisa talvez
        puts("Lista de Pacientes cadastrados:");

        for (i = 0; i < cont; i++)

            printf("%d - %s, %d\n",exames[i].codNum, exames[i].nomeExame, exames[i].pgto);


        Bin[numeroFuncao] = fopen("medicamento6.bin","a+b");

        if (Bin[numeroFuncao] == NULL) {

            fputs("Nao foi possivel abrir o arquivo\n",stderr);
            return 1;

        }

        total = fwrite(&medicamentos[contBin], REG[numeroFuncao], cont - contBin, Bin[numeroFuncao]);

        if (total != cont - contBin) {

            printf("Erro na escritura\n");

        }

    }


    fclose(Bin[numeroFuncao]);

    return cont;


}

int abrirExame7() {
    const int numeroFuncao = 7;

    int cont = 0;

    Bin[numeroFuncao] = fopen("exame7.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        return -2;
    }

    rewind(Bin[numeroFuncao]);

    while (cont < MAXREG && fread(&exames[cont], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont++;

    }


    fclose(Bin[numeroFuncao]);


    return cont;



}
int exame7() {
    const int numeroFuncao = 7;
    int cont = abrirExame7();
    int contBin = cont;

    if (cont == -2) {

        return cont;
    }

    if (cont == MAXREG) {

        fputs("O Registro está cheio.\n", stderr);

        return cont;

    }

    if (cont == 0)

        puts("Nenhum Cadastro de Exame.");

    else

        printf("Cadastrados [%d] registros de Exames.\n",cont);


    while (cont < MAXREG) {

        exames[cont].codNum = cont + 1;
        printf ("Codigo do exame: '%d'\n", exames[cont].codNum);
        limparBuffer();
        printf("Nome do exame \n");
        gets(exames[cont].nomeExame);

        do {
            printf("A forma de pagamento\n1. Convenio\n2. Particular\n3. Gratuito\n");
            scanf("%d",&exames[cont].pgto);
            limparBuffer();
            switch (exames[cont].pgto) {

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
                    if(exames[cont].pgto <= 0 || exames[cont].pgto > 3)
                        printf("Opcao invalida\n");
            }


        } while (exames[cont].pgto <= 0 || exames[cont].pgto > 3);


        cont++;

        if (cont != MAXREG) {

            if (sair() == 1)
                break;
        }

    }

    if (cont > 0) {

        //preciso pra alguma coisa talvez
        puts("Lista de Pacientes cadastrados:");

        for (i = 0; i < cont; i++)

            printf("%d. %s, %d\n",exames[i].codNum, exames[i].nomeExame, exames[i].pgto);


        Bin[numeroFuncao] = fopen("exame7.bin","a+b");

        if (Bin[numeroFuncao] == NULL) {

            fputs("Nao foi possivel abrir o arquivo\n",stderr);
            return 1;

        }

        total = fwrite(&exames[contBin], REG[numeroFuncao], cont - contBin, Bin[numeroFuncao]);

        if (total != cont - contBin) {

            printf("Erro na escritura\n");

        }

    }


    fclose(Bin[numeroFuncao]);

    return cont;
}

int sintomasDoenca() {


    return 0;
}


//(h) Verifique e mostre quantos e quais sintomas podem causar uma determinada doença, indicando o nível de severidade da doença. Observe que o nível de severidade da doença depende do nível de severidade dos sintomas, da predisposição genética, dos riscos associados, da idade, e dos resultados de exames anteriores;
//(i) Descubra e mostre todos os pacientes atendidos pelos médicos cadastrados (ex: médico1 = pacientes x, y, z; médico2 = pacientes a, b, c; e assim por diante);
//(j) Identifique e mostre os tratamentos que utilizaram os mesmos medicamentos e solicitaram exames adicionais. Apresente os nomes dos medicamentos e dos exames também;
//(k) Classifique e mostre, em ordem decrescente de valor, a lista de exames que foram pagos de forma particular (em dinheiro);
//(l) Apresente a lista de pacientes (nome e CPF) que foram indicados para internação no hospital, levar em consideração os
//pacientes com doença de alto nível de severidade;
