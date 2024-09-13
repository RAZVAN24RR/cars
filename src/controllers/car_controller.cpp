#include "car_controller.h"
#include "../services/car_service.h"
#include <iostream>
#include "car_dto.h"
#include <cpprest/json.h>


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

void CarController::get_all_cars(web::http::http_request request){
    ucout<< "Trimit prin GET toate vehiculele\n";

    CarService car_service;
    std::vector<CarDTO>  cars = car_service.get_all_cars();

    web::json::value cars_json = web::json::value::array(); 
    int index = 0;

    for (const auto& car : cars) {
        web::json::value car_json;
        car_json[U("id")] = web::json::value::number(car.get_id());
        car_json[U("make")] = web::json::value::string(car.get_make());
        car_json[U("model")] = web::json::value::string(car.get_model());
        car_json[U("year")] = web::json::value::number(car.get_year());

        cars_json[index++] = car_json;
    }

    request.reply(web::http::status_codes::OK, cars_json);

}

void CarController::get_car_by_id(web::http::http_request request, int car_id) {
    ucout << "Received GET request for car with ID: " << car_id << "\n";

    CarService car_service;
    CarDTO car = car_service.get_car_by_id(car_id);

    if (car.get_id() != -1) {
        web::json::value car_json;
        car_json[U("id")] = web::json::value::number(car.get_id());
        car_json[U("make")] = web::json::value::string(car.get_make());
        car_json[U("model")] = web::json::value::string(car.get_model());
        car_json[U("year")] = web::json::value::number(car.get_year());

        request.reply(web::http::status_codes::OK, car_json);
    } else {
        request.reply(web::http::status_codes::NotFound, U("Car not found"));
    }
}
