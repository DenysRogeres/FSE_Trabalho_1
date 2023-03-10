#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "servidor_tcp.h"
#include "cJSON.h"

cJSON* json;
int servidorSocket;
int socketCliente;
struct sockaddr_in servidorAddr;
struct sockaddr_in clienteAddr;
unsigned int clienteLength;

void TrataClienteTCP(int socketCliente) {
    char buffer[30000];
    int tamanhoRecebido;

    if ((tamanhoRecebido = recv(socketCliente, buffer, 30000, 0)) < 0)
        printf("Erro no recv()\n");

    buffer[tamanhoRecebido] = '\0';

    while (tamanhoRecebido > 0) {
        if (send(socketCliente, buffer, tamanhoRecebido, 0) != tamanhoRecebido)
            printf("Erro no envio - send()\n");

        if ((tamanhoRecebido = recv(socketCliente, buffer, 30000, 0)) < 0)
            printf("Erro no recv()\n");
    }

    json = cJSON_Parse(buffer);
}

void inicializaEscuta(unsigned short servidorPorta) {
    if ((servidorSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        printf("falha no socker do Servidor\n");

    // Montar a estrutura sockaddr_in
    memset(&servidorAddr, 0, sizeof(servidorAddr)); // Zerando a estrutura de dados
    servidorAddr.sin_family = AF_INET;
    servidorAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servidorAddr.sin_port = htons(servidorPorta);

    // Bind
    if (bind(servidorSocket, (struct sockaddr*)&servidorAddr, sizeof(servidorAddr)) < 0)
        printf("Falha no Bind\n");

    // Listen
    if (listen(servidorSocket, 10) < 0)
        printf("Falha no Listen\n");

}

cJSON* obterMensagem() {

    clienteLength = sizeof(clienteAddr);
    if ((socketCliente = accept(servidorSocket,
        (struct sockaddr*)&clienteAddr,
        &clienteLength)) < 0)
        printf("Falha no Accept\n");

    TrataClienteTCP(socketCliente);
    close(socketCliente);

    return json;
}

void encerraServidor() {
    close(socketCliente);
    close(servidorSocket);
}