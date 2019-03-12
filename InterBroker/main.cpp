extern "C" {
#include "tcp/server.h"
#include "tcp/listener.h"
}

#include <cstdio>


int main()
{
    printf("Starting!!\n");

	listen_entry();
	
    return 0;
}