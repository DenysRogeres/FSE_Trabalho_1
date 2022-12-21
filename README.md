# FSE-2022/2
Trabalho 1 de Fundamentos de Sistemas Embarcados

Aluno   | Matrícula
--------- | ------
Denys Rógeres | 180041592

## Objetivo 
Este trabalho tem por objetivo a criação de um sistema distribuído de automação predial para monitoramento e acionamento de sensores e dispositivos de um prédio de 2 andares. O sistema deve ser desenvolvido para funcionar em um conjunto de placas Raspberry Pi com um servidor central responsável pelo controle e interface com o usuário e servidores distribuídos para leitura e acionamento dos dispositivos. Dentre os dispositivos envolvidos estão o monitoramento de temperatura e umidade, sensores de presença, sensores de fumaça, sensores de contagem de pessoas, sensores de abertura e fechamento de portas e janelas, acionamento de lâmpadas, aparelhos de ar-condicionado, alarme e aspersores de água em caso de incêndio.



## Execução

Na pasta de cada servidor (`servidor_central` e `servidor_distribuido`) execute o comando:
```
make
```

Em seguida, na pasta de cada servidor execute o comando:
```
make run
```