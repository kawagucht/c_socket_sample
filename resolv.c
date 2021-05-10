#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){
        struct hostent *host1 =NULL;
        struct in_addr *addr1;
        struct in_addr **addr_list1;

        if (argc !=2) {
                printf("specify hostname!\n");
                return 1;
        }

        host1 = gethostbyname(argv[1]);

        if(host1==NULL) {
                printf("cannot reolve the hostname.\n");
                return 1;
        };

        int i;

        for (i=0; host1->h_aliases[i]; i++) {
                printf("aliases\t :\t%s\n", host1->h_aliases[i]);
        }

        addr_list1 = (struct in_addr **)host1->h_addr_list;
        for (i=0; addr_list1[i]; i++) {
                printf("address\t :\t%s\n", inet_ntoa(*addr_list1[i]));
        }
        return 0;
}