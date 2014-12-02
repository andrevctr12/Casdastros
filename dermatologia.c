//
//              Trabalho de Arquivos
//
//   André Victor Teixeira Lopes / 201411640020
//   Elizane
//   Larissa Roman
//
//

#include <stdio.h>


#define A 10

int i,contPacientes = 0;

//marcas

int marca1 = 0,marca4 = 0;

//typedef structs:

typedef struct {

    char medicamento[200], agentes[150], ambiente[200], outros[200];
}reg04;

typedef struct {
    int CPF, telefone, idade, codPaciente;
    char nomePaciente[50], endereco[100], genero, predGenetica[200], exames[200],resultados[150];
    reg04 risco[A];
}reg4;



typedef struct {
    int codID, codDoenca;
    float valorConsulta, valorExame;
    char nomeMedico[30], nomePaciente[30],tempoObs[5], tempoInter[5], resp;
}reg5;

//Declaração de structs:

reg4 pacientes[A];
reg5 tratamentos[A];



//Protótipo de funções:

void sair(char);

void num1();
void num2();
void num3();
void num4();
void num5();
void num6();
void num7();
void num8();

int main() {

    int op;
    char ok;

    printf("1. Cadastrar doenças\n");
    printf("2. Cadastrar sintomas\n");
    printf("3. Cadastrar médicos\n");
    printf("4. Cadastrar pacientes\n");
    printf("5. Cadastrar tratamentos\n");
    printf("6. Cadastrar medicamentos\n");
    printf("7. Cadastrar exames\n");



    printf("X. Sair\n\n> ");


    do {

        scanf("%d",&op);

        switch (op) {
            case 1:
                marca1 = 1;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                num4();
                marca4 = 1;
                break;
            case 5:
                if (marca1 == 0) {

                    printf("Você não tem nenhuma doença cadastrada. Cadastre para continuar!\n\n");

                    //num1();
                    marca1 = 1;
                    num5();

                }
                else if (marca4 == 0) {
                    printf("Você não tem nenhum paciente cadastrado. Cadastre para continuar!\n\n");
                    num4();
                    marca4 = 1;
                    num5();
                }
                else
                    num5();
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                break;
        }
    } while (op != 'X');



    return 0;
}





void sair(char ok) {

    printf("Você deseja sair? (S/N)");
    scanf("%s",&ok);

}

/*

 Registro de pacientes: CPF, nome do paciente, telefone, endereço, idade, gênero, predisposição genética
 (presença de doenças no pai e/ou na mãe), riscos associados (já toma algum medicamento?, está exposto a agentes
 nocivos à saúde? trabalha em ambiente insalubre? dentre outros), exames realizados (quais?), quais os resultados
 de exames anteriores?;

 */

void num4() {

    char ok;

    for(i = contPacientes; i < A; i++) {

        pacientes[i].codPaciente = i + 1;
        printf("Código do Paciente: '%d'\n", pacientes[i].codPaciente);

        printf("Digite o CPF do paciente: \n");
        scanf("%d", &pacientes[i].CPF);
        printf("Digite o nome do paciente: \n");
        fflush(stdin);
        gets(pacientes[i].nomePaciente);
        printf("Digite a idade do paciente: \n");
        scanf("%d", &pacientes[i].idade);
        printf("Qual o genero do paciente? (M/F) \n");
        scanf("%c", &pacientes[i].genero);
        printf("Digite o telefone do paciente: \n");
        scanf("%d", &pacientes[i].telefone);
        printf("Digite o endereco do paciente: \n");
        fflush(stdin);
        gets(pacientes[i].endereco);
        printf("Predisposicao Genetica do paciente: \n");
        fflush(stdin);
        gets(pacientes[i].predGenetica);
        printf("Há algum risco associado ao paciente?\nJá toma algum medicamento?\nEstá exposto a agentes nocivos à saúde?\nTrabalha em ambiente insalubre?\nDentre outros\n");
        printf("(S/N)\n");
        scanf(" %c", &ok);

        if (ok == 's' || ok == 'S') {

            printf("Toma algum medicamento?\n");
            gets(pacientes[i].risco[i].medicamento);
            printf("Está exposto a agentes nocivos à saúde?\n");
            gets(pacientes[i].risco[i].agentes);
            printf("Trabalha em ambiente insalubre?\n");
            gets(pacientes[i].risco[i].ambiente);
            printf("Outros?\n");
            gets(pacientes[i].risco[i].outros);

        }

        printf("Quais exames ja foram realizados?\n");
        gets(pacientes[i].exames);
        printf("Quais os resultados de exames anteriores?\n\n");
        gets(pacientes[i].resultados);

        contPacientes += 1;

    }

}




/*     Registro de tratamentos: código de identificação, nome do médico, nome do paciente, código de identificação da doença, exames adicionais (quais?), valor(es) da consulta e dos exames adicionais, haverá tempo de observação? (caso positivo, quanto tempo?), indicação de internação no hospital? (caso positivo, quanto tempo?);
 */

/*
void tratamentos() {

    char escolha;

    struct reg {
        char nomeMedico[100], exames[300], observ[200];
        // char nomePaciente[100] // pegar o nome dos outros registros?
        int codMedico, tempoObserv,internacao,tempoInternacao;
        float valorConsulta, valorExames = 0;
        // int codIdentDoenca // pegar do outro registro?
    }tratamento[A];

    for(i = 0; i < A; i++) {

        tratamento[i].codMedico = i + 1;
        printf("Código do Médico: %d", tratamento[i].codMedico);

        printf("Digite o nome do Médico: \n");
        fflush(stdin);
        gets(tratamento[i].nomeMedico);

        //nome do paciente
        //Codigo de identificacao da doenca

        printf("Exames adicionais? (S/N)\n");
        scanf("%c", &escolha);
        if ((escolha == "S") | (escolha == "s") | (escolha == "Sim") | (escolha == "sim")) {
            fflush(stdin);
            gets(tratamento[i].exames);
            printf("Qual o valor dos exames adicionais?");
            scanf("%f",&tratamento[i].valorExames);

        }


        printf("Digite a idade do paciente: \n");
        scanf("%d", &paciente[i].idade);

    }

 }

*/

void num5() {


    char ok;
    int i, cod, escolha;

    for (i = 0; i < A; i++) {

        tratamentos[i].codID = i + 1;
        printf("Codigo de identificacao:  '%d'\n", tratamentos[i].codID);

        //printf("Informe o codigo de identificacao da doenca:\n");
        //scanf("%d", &tratamentos[i].codDoenca);
        //printf("Codigo de identificacao da doenca: %d\n", tratamentos[i].cod_doenca);

        printf("Informe o codigo de identificacao do paciente:\n");
        scanf("%d",&cod);

        cod = cod - 1;
        if (contPacientes < cod) {
            do {
            printf("Paciente não cadastrado.\n1. Cadastrar?\n2. Digitar outro\n> ");
            scanf("%d", &escolha);
                switch (escolha) {
                    case 1:
                        num4();
                        marca4 = 1;
                        break;
                    case 2:
                        printf("Digite outro codigo de paciente:");
                        scanf("%d", &cod);
                    default:
                        printf("Digite novamente\n");
                        break;
                }
            } while (contPacientes < cod);
        }
            printf("Nome do paciente: ");
            printf("%s",pacientes[cod].nomePaciente);

        fflush(stdin);
        printf("Nome do medico:\n");
        gets(tratamentos[i].nomeMedico);
        printf("Informe o valor da consulta:\n");
        scanf("%f", & tratamentos[i].valorConsulta);

        printf("Exames adicionais? (S/N)\n");
        scanf(" %c", &ok);
        if (ok == 'S' || ok == 's') {

            printf("Informe o valor dos exames:");
            scanf("%f", & tratamentos[i].valorExame);
        }
            printf("Havera tempo de observacao (S/N)? \n");
            scanf("%c \n", & tratamentos[i].resp);

        while(tratamentos[i].resp=='s') {

            printf ("Informe o tempo de observacao");
            scanf("%s", tratamentos[i].tempoObs);
            puts(tratamentos[i].tempoObs);
            printf ("Informe o tempo de observacao");
            scanf("%s", tratamentos[i].tempoObs);
        }

        printf("Existe tempo de internacao (s/n):");
        fflush(stdin);
        scanf("%c \n ", & tratamentos[i].resp);
        while (tratamentos[i].resp=='s') {

            printf("Quanto tempo de internacao?");
            scanf("%s", tratamentos[i].tempoInter);
            puts(tratamentos[i].tempoInter);
            printf("Quanto tempo de internacao?");
            scanf("%s", tratamentos[i].tempoInter);
        }
    }
}
