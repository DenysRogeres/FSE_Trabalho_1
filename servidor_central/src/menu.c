#include "menu.h"

char** salas;
int quantSalas, quantPessoaSalas, salaAtual;
int* quantPessoa;
JSONData* estados_sensores;

void estilizacaoTerminal() {
    //init_pair(1, COLOR_BLUE, COLOR_BLACK);
}


void mostraInformacoes() {
    int x = quantSalas + 3;
    int y = 30;
    int row = 1;

    mvprintw(0, 0, "Quantidade de pessoas totais nas salas: %d", quantPessoaSalas);

    for (int i = 0; i < quantSalas ; i++)
        mvprintw(i + row, 0, "Há %d pessoas na %s: ", quantPessoa[i], salas[i]);

    mvprintw(x, 0, "---------------- Informações %s ----------------", salas[salaAtual]);
    mvprintw(x + 2, 0, "Pessoas na sala: %d", quantPessoa[salaAtual]);

    if (estados_sensores[salaAtual].temp == 0) {
        mvprintw(x + 3, 0, "Carregando temperatura");
        mvprintw(x + 4, 6, "e umidade ...");
    }

    else {
        mvprintw(x + 3, 0, "Umidade: %.1lf%%", estados_sensores[salaAtual].umidade);
        mvprintw(x + 4, 0, "Temperatura: %.1lf°C", estados_sensores[salaAtual].temp);
    }

    mvprintw(x + 2, y, "Sensor de presença");
    mvprintw(x + 3, y, "Sensor de fumaça");

    if (strcmp(salas[salaAtual], "Sala 01") == 0) {
        mvprintw(x + 6, y, "Porta de Entrada");
    }
}

void mostrarComando() {
    int x = quantSalas + 12;
    int y = 0;
    int z = 30;

    mvprintw(x, y, "-------------------- COMANDOS --------------------");

    mvprintw(x + 2, y, "[1] Lâmpada Sala 1");
    mvprintw(x + 3, y, "[2] Lâmpada  Sala 2");
    mvprintw(x + 4, y, "[3] Lâmpada Corredor");
    mvprintw(x + 2, z, "[4] Ar Condicionado");

    x += 6;

    mvprintw(x, 0, "-------------- COMANDOS ESPECIAIS --------------");
    mvprintw(x + 2, y, "[l] ligar todos os sensores da sala");
    mvprintw(x + 3, y, "[d] desligar todos os sensores da sala");
    mvprintw(x + 4, y, "[o] ligar todos os sensores do prédio");
    mvprintw(x + 5, y, "[i] desligar todos os sensores do prédio");

    mvprintw(x + 6, y, "[q] sair");

    if (quantSalas > 1)
        mvprintw(x + 10, 8, "Pressione espaço para trocar de sala");
}

void menu(JSONData* estados, char** _sala, int* qntdPessoas, int qntdSalas, int totalPessoas, int sala) {
    
    estados_sensores = estados;
    salas = _sala;
    quantPessoa = qntdPessoas;
    quantSalas = qntdSalas;
    quantPessoaSalas = totalPessoas;
    salaAtual = sala;

    estilizacaoTerminal();
    mostraInformacoes();
    mostrarComando();
}