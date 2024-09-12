#include "db_connection.h"
#include <iostream>

bool connect_to_database(MYSQL *&conn){
    const char *server = "localhost";
    const char *user = "cars_user";
    const char *password = "cars_password";
    const char *database = "cars_db";

    conn = mysql_init(nullptr);
    if(!mysql_real_connect(conn,server,user,password,database,0,nullptr,0)){
        std::cerr <<"Failled to connect to database: Error: " <<mysql_error(conn) << std::endl;
        return false;
    }
    std::cout<<"Connected to database seccessfully!" << std::endl;
    return true;

}

void close_database_connection(MYSQL *conn) {
    if(conn){
        mysql_close(conn);
        std::cout << "Database connection closed." << std::endl;
    }
}