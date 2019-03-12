extern "C" {
#include "tcp/server.h"
#include "tcp/listener.h"
}

#include <cstdio>


int main()
{
	char* message;

    printf("Starting!!\n");

	message = listen_entry();

	printf(message);
	
    return 0;
}