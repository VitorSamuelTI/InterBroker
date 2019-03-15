#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>


int query() {
    
	PGconn *conn = PQconnectdb("user=vitor password=vitor123 dbname=broker");

    if (PQstatus(conn) == CONNECTION_BAD) {
        
        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
        do_exit(conn);
    }

    PGresult *res = PQexec(conn, "SELECT VERSION()");    
    
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {

        printf("No data retrieved\n");        
        PQclear(res);
        do_exit(conn);
    }    

    printf("%s\n", PQgetvalue(res, 0, 0));

    PQclear(res);
    PQfinish(conn);

    return 0;
}