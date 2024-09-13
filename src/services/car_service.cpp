#include "car_service.h"
#include "../db_connection/db_connection.h"
#include <iostream>


bool CarService::insert_car(const std::string &make, const std::string &model, int year) {
    MYSQL *conn;
    if (connect_to_database(conn)) {
        std::string query = "INSERT INTO car (make, model, year) VALUES ('" + make + "', '" + model + "', " + std::to_string(year) + ")";
        if (mysql_query(conn, query.c_str())) {
            std::cerr << "Failed to insert data: " << mysql_error(conn) << std::endl;
            close_database_connection(conn);
            return false;
        } else {
            std::cout << "Car inserted successfully: " << make << " " << model << " " << year << std::endl;
            close_database_connection(conn);
            return true;
        }
    }
    return false;
}
