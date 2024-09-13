#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "db_connection/db_connection.h"
#include "controllers/car_controller.h"


using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;


int main() {
    uri_builder uri(U("http://localhost:3001/api/cars"));
    auto addr = uri.to_uri().to_string();
    http_listener listener(addr);

    CarController car_controller;

    listener.support(methods::POST, std::bind(&CarController::create_car, &car_controller, std::placeholders::_1));
  
    listener.support(methods::GET, std::bind(&CarController::get_all_cars, &car_controller, std::placeholders::_1));

    try {
        listener
            .open()
            .then([&listener]() { ucout << "Starting to listen at: " << listener.uri().to_string() << std::endl; })
            .wait();

        std::string line;
        std::getline(std::cin, line);
    } catch (const std::exception &e) {
        std::cerr << "Something went wrong: " << e.what() << std::endl;
    }

    return 0;
}
