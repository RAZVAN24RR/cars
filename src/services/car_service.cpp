#include "car_service.h"
#include "../db_connection/db_connection.h"
#include <iostream>
#include <cpprest/json.h>


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

web::json::value CarService::get_all_cars() {
    web::json::value cars_json = web::json::value::array(); 
    MYSQL *conn;

    if (connect_to_database(conn)) {
        
        std::string query = "SELECT id, make, model, year FROM car";
        if (mysql_query(conn, query.c_str())) {
            std::cerr << "Failed to retrieve data: " << mysql_error(conn) << std::endl;
        } else {
            MYSQL_RES *res = mysql_store_result(conn); 
            MYSQL_ROW row;
            int index = 0;

            while ((row = mysql_fetch_row(res))) {
                web::json::value car_json;
                car_json[U("id")] = web::json::value::number(std::stoi(row[0]));
                car_json[U("make")] = web::json::value::string(row[1]);
                car_json[U("model")] = web::json::value::string(row[2]);
                car_json[U("year")] = web::json::value::number(std::stoi(row[3]));

                cars_json[index] = car_json;
                index++;
            }
            mysql_free_result(res);
        }
        close_database_connection(conn);
    }

    return cars_json;
}