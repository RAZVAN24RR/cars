#include "car_controller.h"
#include "../services/car_service.h"
#include <iostream>

CarController::CarController() {}

void CarController::create_car(web::http::http_request request) {
    ucout << "Received a POST request\n";
    
    request.extract_json().then([=](json::value json_data) {
        if (!json_data.is_null()) {
            
            std::string make = json_data[U("make")].as_string();
            std::string model = json_data[U("model")].as_string();
            int year = json_data[U("year")].as_integer();

            CarService car_service;

            bool result = car_service.insert_car(make, model, year);

            if (result) {
                request.reply(status_codes::OK, json::value::string(U("Car inserted successfully")));
            } else {
                request.reply(status_codes::InternalError, U("Failed to insert car"));
            }
        } else {
            request.reply(status_codes::BadRequest, U("Invalid JSON data"));
        }
    }).wait();
}


