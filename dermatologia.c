//
//              Trabalho de Arquivos
//
//   André Victor Teixeira Lopes / 201411640020
//   Elizane
//   Larissa
//
//

#include <stdio.h>


int paciente();

int main() {

    int op;

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
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                paciente();
                break;
            case 5:
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
    } while (op != "X");



    return 0;
}




/*

 Registro de pacientes: CPF, nome do paciente, telefone, endereço, idade, gênero, predisposição genética
 (presença de doenças no pai e/ou na mãe), riscos associados (já toma algum medicamento?, está exposto a agentes
 nocivos à saúde? trabalha em ambiente insalubre? dentre outros), exames realizados (quais?), quais os resultados
 de exames anteriores?;

 */

void paciente() {

    int i, A = 10;
    char risco[3];

    struct reg {
        char medicamento[200], agentes[150], ambiente[200], outros[200];
    };

    struct {
        int CPF, telefone, idade;
        char nomePaciente[50], endereco[100], genero, predGenetica[200], exames[200],resultados[150];
        struct reg risco[10];
    }pacientes[A];

    for(i = 0; i < A; i++) {

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
        printf("Algum risco associado ao paciente?\nJá toma algum medicamento?\nEstá exposto a agentes nocivos à saúde?\nTrabalha em ambiente insalubre?\nDentre outros\n");
        printf("(S/N)  ");
        gets(risco);

        if ((risco == "S") | (risco == "s") | (risco == "Sim") | (risco == "sim")) {

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

    }

}




/*     Registro de tratamentos: código de identificação, nome do médico, nome do paciente, código de identificação da doença, exames adicionais (quais?), valor(es) da consulta e dos exames adicionais, haverá tempo de observação? (caso positivo, quanto tempo?), indicação de internação no hospital? (caso positivo, quanto tempo?);
 */

void tratamentos() {

    struct reg {
        int cod,

    }









}

