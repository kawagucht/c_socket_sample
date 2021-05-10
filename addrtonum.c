#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
        if(argc != 2){
                printf("specify ip address!\n");
                return 1;
        }
        struct in_addr addr;
        inet_aton(argv[1], &addr);
        printf("address is : 0x%08x\n", addr.s_addr);
}
