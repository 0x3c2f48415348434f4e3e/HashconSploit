//lets see if we can implement a way to get device current IP from scratch
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <ws2def.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>


//lets define the addrinfo (specially for an IP address or something like that)
struct addrinfo hints;
struct addrinfo *result = NULL;

int initiliases(void){
    WSADATA wsaData;
    return  WSAStartup(MAKEWORD(2,2),&wsaData);
}

void IPAddressInformation(const char *IPAddress,const ADDRINFOA *pHints){
//since we are working with HTTP, then we are going to use 'http
    const char*port = "http";

    //returns 0 on success, else non-zero

    int error = 0;

    error = getaddrinfo(IPAddress,port,&pHints,&result);
}

int main(){
    if(initiliases() != 0){
        fprintf(stderr,"Could not initiate\n");
        //no allocated memory so no need to deallocate anything
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    else{
        fprintf(stdout,"Successfully initiated\n");

    }


    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
}
