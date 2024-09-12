#ifndef  DB_CONNECTION_H
#define  DB_CONNECTION_H

#include <mysql/mysql.h>
#include <string>

bool connect_to_database(MYSQL *&conn);

void close_database_connection(MYSQL *conn);

#endif // ! DB_CONNECTION_H
