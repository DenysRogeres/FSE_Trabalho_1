#include <stdio.h>

int main() {
    int cmd;

    while (1){
        printf("- Digite qual sala você deseja monitorar:\n\n[1] - Sala 01\n[2] - Sala 02\n\n");
        scanf("%d", &cmd);
    }

    return 0;
}