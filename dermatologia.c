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


#define MAXREG 40
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
    int codNum, nivel, qntSintomas;
    char nomeDoenca[TAM1], descricao[TAM4];
    int codSintoma[MAXREG];
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
    int codNum, CRM, codPaciente[MAXREG], qntPaciente;
    char nomeMedico[TAM2], CPF[15], telefone[20];
    reg03 endereco;
};

//paciente4()

typedef struct {
    char rua[TAM2], bairro[TAM1], cidade[TAM2], estado[TAM1], CEP[9];
    int numero;
}reg14;

struct reg4 {
    int idade, codNum, codExame[MAXREG], codDoenca[MAXREG];
    char nomePaciente[TAM2], genero;
    int resultados, qntDoencas;
    char CPF[15], telefone[20];
    int risco, predGenetica;
    reg14 endereco;
};

//tratamento5()
struct reg5 {
    int codNum, codDoenca, codPaciente, codMedico;
    int codExame[MAXREG], codMedicamento[MAXREG], qntExames;
    float valorConsulta, valorExame;
    char tempoObs[5], tempoInter[5];
    int exameAdicional;
};

//medicamento6()
struct reg6 {
    int codNum, faixaEtaria;
    char nomeMedicamento[TAM2], posologia[TAM3], contraIndicacao[TAM3];
    int codPaciente[MAXREG];
    float valor;
};


//exame7()
struct reg7 {
    int codNum, pgto;
    char nomeExame[TAM1];
    float valor;
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
void sintomasDoenca();
void pacientesMedico(int*);
void pacientesInternacao();
void pacientesInternacao();
void examesParticular();
void medicamentosExames();

void listaDoencas(int);
void listaSintomas(int);
void listaMedicos(int,int);
void listaPacientes(int);
void listaMedicamentos(int);
void listaExames(int);

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
        printf("9. Pacientes atendidos pelos Médicos cadastrados\n");
        printf("10. Tratamentos que utilizaram os mesmos medicamentos e solicitaram exames adicionais\n");
        printf("11. Lista de exames que foram pagos de forma particular em ordem decrescente de valor\n");
        printf("12. Lista de pacientes que foram indicados para internação no hospital\n");




        printf("0. Sair\n\n> ");

        scanf(" %d",&op);
        limparBuffer();
        switch (op) {
            case 1:
                if (marca2 == 0) {

                    printf("Você não tem nenhum sintoma cadastrado. Cadastre para continuar!\n");
                    marca2 = sintoma2();
                    marca1 = doenca1();
                }
                else
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
                else
                    marca3 = medico3();

                break;
            case 4:
                if (marca7 == 0) {

                    printf("Você não tem nenhum exame cadastrado. Cadastre para continuar!\n");
                    marca7 = exame7();
                    marca4 = paciente4();
                }
                if (marca1 == 0) {

                    printf("Você não tem nenhum exame cadastrado. Cadastre para continuar!\n");
                    marca1 = doenca1();
                    marca4 = paciente4();
                }
                else
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
                else if (marca7 == 0) {

                    printf("Você não tem nenhum exame cadastrado. Cadastre para continuar!\n");
                    marca7 = exame7();
                    marca5 = tratamento5();

                }

                else if (marca3 == 0) {
                    printf("Você não tem nenhum medico cadastrado. Cadastre para continuar!\n");
                    marca3 = medico3();
                    marca5 = tratamento5();
                }
                else if (marca6 == 0) {
                    printf("Você não tem nenhum medicamento cadastrado. Cadastre para continuar!\n");
                    marca6 = medicamento6();
                    marca5 = tratamento5();
                }

                else
                    marca5 = tratamento5();
                break;
            case 6:
                if (marca4 == 0) {

                    printf("Você não tem nenhum paciente cadastrado. Cadastre para continuar!\n");
                    marca4 = paciente4();
                    marca6 = medicamento6();
                }
                else
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
                    printf("Você não tem nenhuma Doenca cadastrado. Cadastre para continuar!\n");
                    marca1 = doenca1();
                    sintomasDoenca();

                    printf("Você não tem nenhum Paciente cadastrado. Cadastre para continuar!\n");
                    marca4 = paciente4();
                    sintomasDoenca();

                    printf("Você não tem nenhum sintoma cadastrado. Cadastre para continuar!\n");
                    marca2 = sintoma2();
                    sintomasDoenca();

                }
                else
                    sintomasDoenca();
                break;
            case 9:
                pacientesMedico(&marca3);
                break;
            case 10:
                medicamentosExames();
                break;
            case 11:
                examesParticular();
                break;
            case 12:
                sintomasDoenca();
                pacientesInternacao();
                break;


            default:
                if (op != 0)
                    printf("Opcao invalida!\n");
                break;
        }
    } while (op != 0);



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

void listaDoencas(int contDoenca) {

    for (i = 0; i < contDoenca; i++) {

        if (i == 0)

            puts("Lista de Doencas:");


        printf("%d. %s\n",doencas[i].codNum, doencas[i].nomeDoenca);


    }


}
void listaSintomas(int contSintoma) {

    for (i = 0; i < contSintoma; i++) {

        if (i == 0)

            puts("Lista de Sintomas:");


        printf("%d. %s, ",sintomas[i].codNum, sintomas[i].descricao);

        if (sintomas[i].nivel == 1)
            puts("Severidade Baixa");
        else if (sintomas[i].nivel == 2)
            puts("Severidade Media");
        else
            puts("Severidade Alta");


    }


}
void listaMedicos(int contMedico, int numeroPaciente) {

    for (i = 0; i < contMedico; i++) {
        if (i == 0)

            puts("Lista de Medicos que atendem o paciente:");

        for (j = 0; j < MAXREG; j++) {
            if (numeroPaciente == medicos[i].codPaciente[j]) {

                printf("%d. %s\n",medicos[i].codNum, medicos[i].nomeMedico);
            }
        }
    }
}
void listaPacientes(int contPaciente) {

    for (i = 0; i < contPaciente; i++) {

        if (i == 0)

            puts("Lista de Pacientes:");


        printf("%d. %s, %d anos\n",pacientes[i].codNum, pacientes[i].nomePaciente, pacientes[i].idade);

    }


}
void listaMedicamentos(int contMedicamento) {
    for (i = 0; i < contMedicamento; i++) {

        if (i == 0)

            puts("Lista de Medicamentos:");


        printf("%d. %s\n",medicamentos[i].codNum, medicamentos[i].nomeMedicamento);

    }


}
void listaExames(int contExame) {

    for (i = 0; i < contExame; i++) {

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

        puts("Registro de Doencas está cheio");

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



        //SINTOMAS DA DOENCA

        listaSintomas(contSintoma);
        printf("Quais sao os sintomas da doenca?\n");


        doencas[cont].qntSintomas = 0;

        cont2 = 0;

        while (cont2 < contSintoma) {  //LAÇO DE REPETICAO PARA SABER OS SINTOMAS DA DOENCA

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
                            printf("Digite outro codigo de Sintoma: ");
                            scanf("%d", &codRegistro);
                            limparBuffer();

                            break;
                        case 2:
                            printf("Digite outro codigo de Sintoma: ");
                            scanf("%d", &codRegistro);
                            limparBuffer();
                            break;
                        default:
                            printf("Digite novamente\n");
                            break;
                    }

                } while (contSintoma < codRegistro || codRegistro < 1);

            }






            printf("Sintoma: %s\n",sintomas[codRegistro - 1].descricao);

            doencas[contSintoma].codSintoma[cont2] = codRegistro;

            doencas[cont].qntSintomas++;

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

        puts("Registro de Sintomas está cheio");

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

        puts("Registro de Medicos está cheio");

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

        medicos[cont].codNum = cont + 1;
        printf("Codigo de identificacao: %d\n",medicos[cont].codNum);

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

        medicos[cont].qntPaciente = 0;

        listaPacientes(contPaciente);

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

            medicos[cont].qntPaciente++;

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

        puts("Registro de Pacientes está cheio.");

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
    int contDoenca = abrirDoenca1();
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

            printf("Paciente com Predisposicao Geneticas para doencas?\n");
            printf("1. Sim\n2. Nao\n");
            scanf("%d", &pacientes[cont].predGenetica);
            limparBuffer();

        } while (pacientes[cont].predGenetica < 1 || pacientes[cont].predGenetica > 2);

        do {

            printf("Há algum risco associado ao paciente?\n(Toma algum medicamento. Está exposto a agentes nocivos à saúde. Trabalha em ambiente insalubre.)\n");
            printf("1. Sim\n2. Nao\n");
            scanf("%d", &pacientes[cont].risco);
            limparBuffer();
        } while (pacientes[cont].risco < 1 || pacientes[cont].risco > 2);

        //EXAMES REALIZADOS PELO PACIENTE

        listaExames(contExame);
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

            pacientes[cont].codExame[cont7] = codRegistro;

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

        listaDoencas(contDoenca);

        printf("\nQuais doencas o paciente ja teve?\n");
        pacientes[cont].qntDoencas = 0;
        cont7 = 0;

        while (cont7 < contDoenca) {  //LAÇO DE REPETICAO PARA SABER OS EXAMES DO PACIENTE

            printf("Codigo: ");
            scanf("%d",&codRegistro);
            limparBuffer();


            if (contDoenca < codRegistro || codRegistro < 1) {

                do {

                    printf("Doenca não cadastrado.\n1. Cadastrar.\n2. Digitar outro codigo de Doenca.\n> ");
                    scanf("%d", &op);
                    switch (op) {
                        case 1:
                            contDoenca = doenca1();
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






            printf("Nome do Doenca: %s\n",doencas[codRegistro - 1].nomeDoenca);

            pacientes[cont].codDoenca[cont7] = codRegistro;


            pacientes[cont].qntDoencas++;
            cont7++;

            if (cont7 != contDoenca) {

                puts("Você deseja informar mais alguma doenca? (S/N)");
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
                    printf("Medio\n");
                    break;
                case 3:
                    printf("Grave\n");
                    break;
                case 4:
                    printf("Gravissimo\n");
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

            printf("%d. %s, %d anos, %c\n",pacientes[i].codNum, pacientes[i].nomePaciente, pacientes[i].idade, pacientes[i].genero);


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
    const int numeroFuncao = 5;

    int cont = 0;

    Bin[numeroFuncao] = fopen("tratamento5.bin","a+b");

    if (Bin[numeroFuncao] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        exit(0);
    }

    rewind(Bin[numeroFuncao]);

    while (cont < MAXREG && fread(&tratamentos[cont], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont++;

    }


    fclose(Bin[numeroFuncao]);

    if (cont == MAXREG) {

        puts("Registro de Tratamentos está cheio.");

        return cont;

    }

    if (cont == 0)

        puts("Nenhum Cadastro no registro de Tratamentos.");


    return cont;



}
int tratamento5() {
    const int numeroFuncao = 5;
    int codRegistro, op;
    int contDoenca = abrirDoenca1();
    int contPaciente = abrirPaciente4();
    int contMedico = abrirMedico3();
    int contMedicamento = abrirMedicamento6();
    int contExame = abrirExame7();
    int cont7;
    int cont = abrirTratamento5();
    int contBin = cont;

    while (cont < MAXREG)  {

        tratamentos[cont].codNum = cont + 1;
        printf("Codigo de identificacao:  '%d'\n", tratamentos[cont].codNum);

        listaDoencas(contDoenca);

        printf("Informe o codigo de identificacao da doenca:\n");
        scanf("%d",&codRegistro);
        limparBuffer();


        if (contDoenca < codRegistro || codRegistro < 1) {
            do {
                printf("Doenca não cadastrada.\n1. Cadastrar?\n2. Digitar outra\n> ");
                scanf("%d", &op);
                limparBuffer();
                switch (op) {
                    case 1:
                        contDoenca = doenca1();
                        printf("Digite outro codigo de doenca: ");
                        scanf("%d", &codRegistro);
                        limparBuffer();
                        break;
                    case 2:
                        printf("Digite outro codigo de doenca: ");
                        scanf("%d", &codRegistro);
                        limparBuffer();
                    default:
                        if (contDoenca < codRegistro) {
                            printf("Digite novamente\n");
                        }
                }
            } while (contDoenca < codRegistro);

        }

        printf("Nome da doenca: ");
        puts(doencas[codRegistro - 1].nomeDoenca);

        tratamentos[cont].codDoenca = codRegistro;

        listaPacientes(contPaciente);

        printf("Informe o codigo de identificacao do paciente com a doenca:\n");
        scanf("%d",&codRegistro);
        limparBuffer();


        if (contPaciente < codRegistro || codRegistro < 1) {
            do {
                printf("Paciente não cadastrado.\n1. Cadastrar?\n2. Digitar outro\n> ");
                scanf("%d", &op);
                limparBuffer();
                switch (op) {
                    case 1:
                        contPaciente = paciente4();
                        printf("Digite outro codigo de paciente: ");
                        scanf("%d", &codRegistro);
                        limparBuffer();
                        break;
                    case 2:
                        printf("Digite outro codigo de paciente: ");
                        scanf("%d", &codRegistro);
                        limparBuffer();
                    default:
                        if (contPaciente < codRegistro) {
                            printf("Digite novamente\n");
                        }
                }
            } while (contPaciente < codRegistro);

        }

        printf("Nome do paciente: ");
        puts(pacientes[codRegistro - 1].nomePaciente);

        tratamentos[cont].codPaciente = codRegistro;

        listaMedicos(contMedico,tratamentos[cont].codPaciente);

        printf("Informe o codigo de identificacao do medico que atende o paciente:\n");
        scanf("%d",&codRegistro);
        limparBuffer();

        if (contMedico < codRegistro || codRegistro < 1) {
            do {
                printf("Medico não cadastrado.\n1. Cadastrar?\n2. Digitar outro\n> ");
                scanf("%d", &op);
                limparBuffer();
                switch (op) {
                    case 1:
                        contMedico = medico3();

                        printf("Digite outro codigo de medico: ");
                        scanf("%d", &codRegistro);
                        limparBuffer();
                        break;
                    case 2:
                        printf("Digite outro codigo de medico: ");
                        scanf("%d", &codRegistro);
                        limparBuffer();
                    default:
                        if (contMedico < codRegistro) {
                            printf("Digite novamente\n");
                        }
                }
            } while (contMedico < codRegistro);

        }

        printf("Nome do medico: ");
        puts(medicos[codRegistro - 1].nomeMedico);

        tratamentos[cont].codMedico = codRegistro;

        printf("Informe o valor da consulta:\n");
        scanf("%f", & tratamentos[cont].valorConsulta);
        limparBuffer();

        tratamentos[cont].exameAdicional = 0;

        printf("Exames adicionais? (S/N)\n");
        scanf(" %c", &ok);
        limparBuffer();

        if (ok == 'S' || ok == 's') {

            tratamentos[cont].exameAdicional = 1;

            listaExames(contExame);

            cont7 = 0;

            while (cont7 < contExame) {  //LAÇO DE REPETICAO PARA SABER OS EXAMES A SEREM REALIZADOS

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

                tratamentos[cont].codExame[cont7] = codRegistro;

                tratamentos[cont].qntExames++;

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
        }

        printf("Medicamentos adicionais? (S/N)\n");
        scanf("%c", &ok);
        limparBuffer();

        if (ok == 'S' || ok == 's') {

            listaMedicamentos(contMedicamento);

            cont7 = 0;

            while (cont7 < contMedicamento) {  //LAÇO DE REPETICAO PARA SABER OS EXAMES A SEREM REALIZADOS

                printf("Codigo: ");
                scanf("%d",&codRegistro);
                limparBuffer();


                if (contMedicamento < codRegistro || codRegistro < 1) {

                    do {

                        printf("Medicamento não cadastrado.\n1. Cadastrar.\n2. Digitar outro codigo de Medicamento.\n> ");
                        scanf("%d", &op);
                        switch (op) {
                            case 1:
                                contMedicamento = medicamento6();
                                printf("Digite outro codigo de Medicamento: ");
                                scanf("%d", &codRegistro);
                                limparBuffer();

                                break;
                            case 2:
                                printf("Digite outro codigo de Medicamento: ");
                                scanf("%d", &codRegistro);
                                limparBuffer();
                                break;
                            default:
                                printf("Digite novamente\n");
                                break;
                        }

                    } while (contMedicamento < codRegistro || codRegistro < 1);

                }






                printf("Nome do Medicamento: %s\n",medicamentos[codRegistro - 1].nomeMedicamento);

                tratamentos[cont].codMedicamento[cont7] = codRegistro;

                cont7++;

                if (cont7 != contMedicamento) {

                    puts("Você deseja informar mais algum medicamento? (S/N)");
                    ok = getchar();
                    limparBuffer();

                    if (ok == 'S' || ok == 's')

                        continue;

                    break;

                }


            }
        }





        printf("Havera tempo de observacao (S/N)? \n");
        scanf("%c", &ok);
        limparBuffer();

        if (ok == 's' || ok == 'S') {

            printf ("Informe o tempo de observacao\n");
            gets(tratamentos[cont].tempoObs);
        }

        printf("Havera tempo de internacao (S/N):\n");
        scanf("%c", &ok);
        limparBuffer();

        if (ok == 's' || ok == 'S') {

            printf("Quanto tempo de internacao?\n");
            gets(tratamentos[cont].tempoInter);

        }

        if (cont != MAXREG) {

            if (sair() == 1)
                break;
        }

    }

    //MOSTRA LISTA DE TRATAMENTOS CADASTRADOS

    if (cont > 0) {

        puts("Lista de Tratamentos cadastrados:");
        puts("      Medico,      Paciente,       Doenca");

        for (i = 0; i < cont; i++) {

            contMedico = tratamentos[i].codMedico;
            contPaciente = tratamentos[i].codPaciente;
            contDoenca = tratamentos[i].codDoenca;

            printf("%d. %s, %s, %s\n", tratamentos[i].codNum, medicos[contMedico - 1].nomeMedico, pacientes[contPaciente - 1].nomePaciente, doencas[contDoenca - 1].nomeDoenca);
        }

        //SALVA NO ARQUIVO

        Bin[numeroFuncao] = fopen("tratamento5.bin","a+b");

        if (Bin[numeroFuncao] == NULL) {

            fputs("Nao foi possivel abrir o arquivo\n",stderr);
            exit(1);

        }



        total = fwrite(&tratamentos[contBin], REG[numeroFuncao], cont - contBin, Bin[numeroFuncao]);

        if (total != cont - contBin) {

            printf("Erro na escritura\n");

        }
    }

    fclose(Bin[numeroFuncao]);

    return cont;
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

    if (cont == MAXREG) {

        puts("Registro de Medicamentos está cheio.");

        return cont;

    }

    if (cont == 0)

        puts("Nenhum Cadastro no registro de Medicamentos.");


    return cont;



}
int medicamento6() {
    const int numeroFuncao = 6;
    int cont = abrirMedicamento6();
    int contPaciente = abrirPaciente4();
    int cont4;
    int contBin = cont;
    int codRegistro;

    while (cont < MAXREG) {

        medicamentos[cont].codNum = cont + 1;
        printf ("Codigo do medicamento: '%d'\n", medicamentos[cont].codNum);
        printf("Nome do medicamento:\n");

        gets(medicamentos[cont].nomeMedicamento);

        cont4 = 0;

        listaPacientes(contPaciente);
        printf("Para quais pacientes o medicamento e indicado?\n");


        while (cont4 < contPaciente) {

            printf("Codigo: ");
            scanf("%d",&codRegistro);
            limparBuffer();

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
                            break;
                        case 2:
                            printf("Digite outro codigo de Paciente: ");
                            scanf("%d", &codRegistro);
                            limparBuffer();
                            break;
                        default:
                            printf("Digite novamente\n");
                            break;
                    }

                } while (contPaciente < codRegistro || codRegistro < 1);

            }

            printf("Nome do paciente: %s\n",pacientes[codRegistro - 1].nomePaciente);

            medicamentos[cont].codPaciente[cont4] = codRegistro;

            cont4++;

            if (cont4 != contPaciente) {

                puts("Você deseja informar mais algum paciente? (S/N)");
                ok = getchar();
                limparBuffer();

                if (ok == 'S' || ok == 's')

                    continue;

                break;


            }

            printf("\nNome de todos os pacientes indicados a tomar o medicamento:\n");

            for (i = 0; i < cont4; i++) {

                codRegistro = medicamentos[cont].codPaciente[i];

                printf("%d. %s\n", codRegistro, pacientes[codRegistro - 1].nomePaciente);

            }




        }

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
        exit(1);
    }

    rewind(Bin[numeroFuncao]);

    while (cont < MAXREG && fread(&exames[cont], REG[numeroFuncao], 1, Bin[numeroFuncao]) == 1) {

        cont++;

    }


    fclose(Bin[numeroFuncao]);

    if (cont == MAXREG) {

        puts("Registro de Exames está cheio.");

        return cont;

    }

    if (cont == 0)

        puts("Nenhum Cadastro no registro de Exames.");

    return cont;



}
int exame7() {
    const int numeroFuncao = 7;
    int cont = abrirExame7();
    int contBin = cont;

    while (cont < MAXREG) {

        exames[cont].codNum = cont + 1;
        printf ("Codigo do exame: '%d'\n", exames[cont].codNum);
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

        if (exames[cont].pgto == 3)

            exames[cont].valor = 0;

        else {
            puts("Digite o valor do Exame:");
            scanf("%f",&exames[cont].valor);
            limparBuffer();
        }


        cont++;

        if (cont != MAXREG) {

            if (sair() == 1)
                break;
        }

    }

    if (cont > 0) {

        puts("Lista de Exames cadastrados:");

        for (i = 0; i < cont; i++)

            printf("%d. %s, R$%.2f\n",exames[i].codNum, exames[i].nomeExame, exames[i].valor);


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

void sintomasDoenca() {

    int contDoenca = abrirDoenca1();
    int contPaciente = abrirPaciente4();
    int codSintoma;
    int k;
    float cont = 0;
    float cont2 = 0;
    int cont3 = 0;

    for (i = 0; i < contDoenca; i++) {

        cont3 = 0;

        for (j = 0; j < doencas[i].qntSintomas; j++) {
            codSintoma = doencas[i].codSintoma[j];
            cont += sintomas[codSintoma - 1].nivel;
        }

        cont = cont/doencas[i].qntSintomas;

        cont3 ++;

        for (j = 0; j < contPaciente; j++) {
            for (k = 0; k < pacientes[j].qntDoencas; k++) {
                if (doencas[i].codNum == pacientes[j].codDoenca[k]) {

                    cont2 = 0;

                    if (pacientes[j].predGenetica == 1)
                        cont2 += 3;
                    else
                        cont2 += 1;

                    if (pacientes[j].risco == 1)
                        cont2 += 3;
                    else
                        cont2 += 1;

                    if (pacientes[j].idade < 30)
                        cont2 += 1;

                    else if (pacientes[j].idade > 60)
                        cont2 += 3;

                    else
                        cont2 +=2;

                    cont2 += pacientes[j].resultados;

                    }

                cont += cont2/4;
                cont3++;

            }

        }

        cont = cont/cont3;

        printf("%d. %s\n",doencas[i].codNum, doencas[i].nomeDoenca);

        if (cont < 2) {
            puts("Severidade Baixa");
            doencas[i].nivel = 1;
        }
        else if (cont >= 3) {
            puts("Severidade Alta");
            doencas[i].nivel = 2;
        }
        else {
            puts("Severidade Media");
            doencas[i].nivel = 3;
        }

        for (j = 0; j < doencas[i].qntSintomas; j++) {
            codSintoma = doencas[i].codSintoma[j];
            puts(sintomas[j].descricao);
        }

    }

    Bin[1] = fopen("doenca1.bin","a+b");

    if (Bin[1] == NULL) {

        fputs("Nao foi possivel abrir o arquivo\n",stderr);
        exit(0);

    }

    total = fwrite(&doencas[0], REG[1], contDoenca, Bin[1]);

    if (total != contDoenca) {
        printf("Erro na escritura\n");

    }

    fclose(Bin[1]);




}

void pacientesMedico(int *marca3) {

    int cont = 0;
    int cod;

    *marca3 = abrirMedico3();

    if (marca3 == 0)

        printf("Nenhum medico cadastrado");

    else {

        while (cont < *marca3) {

            printf("Pacientes do Medico %s:\n", medicos[cont].nomeMedico);

            for (i = 0; i < medicos[cont].qntPaciente; i++) {

                cod = medicos[cont].codPaciente[i];
                printf("%d %s\n", i + 1, pacientes[cod - 1].nomePaciente);
            }

            cont++;
        }
    }

}

void medicamentosExames() {
    int contMedicamento = abrirMedicamento6();
    int codExame, codMedicamento;
    int k;
    int contTratamento = abrirTratamento5();
    int cont;

    for (i = 0; i < contTratamento; i++) {
        for (j = 0; j < contTratamento; j++) {
            for (cont = 0; cont <= contMedicamento; cont++) {
                if (tratamentos[i].codMedicamento[cont] == tratamentos[j].codMedicamento[cont] && tratamentos[i].exameAdicional == 1 && tratamentos[j].exameAdicional == 1) {

                    puts("Tratamentos que utilizaram os mesmos medicamentos e solicitaram exames adicionais:");\
                    printf("\nTratamento,    Medicamento:");

                    codMedicamento = tratamentos[i].codMedicamento[cont];
                    printf("%d - %s\n",tratamentos[i].codNum, medicamentos[codMedicamento - 1].nomeMedicamento);
                    puts("Exames:");

                    for (k = 0; k < tratamentos[i].qntExames; k++) {

                        codExame = tratamentos[i].codExame[tratamentos[i].qntExames];

                        printf("%s", exames[codExame - 1].nomeExame);

                    }

                    printf("\nTratamento,    Medicamento:");
                    codMedicamento = tratamentos[j].codMedicamento[cont];
                    printf("%d - %s\n",tratamentos[j].codNum, medicamentos[codMedicamento - 1].nomeMedicamento);
                    puts("Exames:");

                    for (k = 0; k < tratamentos[i].qntExames; k++) {

                        codExame = tratamentos[j].codExame[tratamentos[i].qntExames];

                        printf("%s", exames[codExame - 1].nomeExame);
                    }
                }
            }
        }
    }
}

void examesParticular() {
    int contExame = abrirExame7();
    float maior;
    float valor[MAXREG];

            for (i = 0; i < contExame; i++) {
                valor[i] = exames[i].valor;
            }

            for (j = 0 ; j < (contExame - 1) ; j++)
            {
                for (i = 0 ; i < (contExame - 1) ; i++)
                {
                    if (valor[i + 1] < valor[i])
                    {
                        maior = valor[i];
                        valor[i] = valor[i + 1];
                        valor[i + 1] = maior;

            }

                }
            }


    printf ("Ordem Decrescente de Exames Particulares:\n");
    for (i = contExame ; i > 0 ; i--) {
        for (j = 0; j < contExame; j++) {
            if (exames[j].pgto == 2) {

                if (exames[j].valor == valor[i - 1]) {

                    printf("%d. %s, ", exames[j].codNum, exames[j].nomeExame);

                }
            }


        }


            printf ("%.2f\n", valor[i - 1]);


    }




}

void pacientesInternacao() {


    int contPaciente = abrirPaciente4();
    int contDoenca = abrirDoenca1();

    puts("Pacientes indicados para a internacao:");

    for (i = 0; i < contPaciente; i++) {
            for (j = 0; j < contDoenca; j++) {

            if (pacientes[i].codDoenca == doencas[j].codNum) {
                if (doencas[j].nivel == 3) {

                    printf("%d. %s, %s\n", pacientes[i].codNum, pacientes[i].nomePaciente, pacientes[i].CPF);
                }

            }

        }
    }







}
