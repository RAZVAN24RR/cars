#include "car_service.h"
#include "car_dto.h"
#include "../db_connection/db_connection.h"
#include <iostream>
#include <cpprest/json.h>
#include <vector>



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

std::vector<CarDTO>  CarService::get_all_cars() {
    std::vector<CarDTO> cars;
    MYSQL *conn;

    if (connect_to_database(conn)) {
        
        std::string query = "SELECT id, make, model, year FROM car";
        if (mysql_query(conn, query.c_str())) {
            std::cerr << "Failed to retrieve data: " << mysql_error(conn) << std::endl;
        } else {
            MYSQL_RES *res = mysql_store_result(conn); 
            MYSQL_ROW row;

            while((row = mysql_fetch_row(res))){
                CarDTO car(std::stoi(row[0]), row[1], row[2], std::stoi(row[3]) );
                cars.push_back(car);
            }

            mysql_free_result(res);
        }
        close_database_connection(conn);
    }

    return cars;

}

CarDTO CarService::get_car_by_id(int car_id) {
    CarDTO car;
    MYSQL *conn;

    if (connect_to_database(conn)) {
        std::string query = "SELECT id, make, model, year FROM car WHERE id = " + std::to_string(car_id);
        if (mysql_query(conn, query.c_str())) {
            std::cerr << "Failed to retrieve data: " << mysql_error(conn) << std::endl;
        } else {
            MYSQL_RES *res = mysql_store_result(conn);
            MYSQL_ROW row = mysql_fetch_row(res);

            if (row) {
                car.set_id(std::stoi(row[0]));
                car.set_make(row[1]);
                car.set_model(row[2]);
                car.set_year(std::stoi(row[3]));
            } else {
                car.set_id(-1);
            }
            mysql_free_result(res);
        }
        close_database_connection(conn);
    }

    return car;
}