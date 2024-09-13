#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "db_connection/db_connection.h"
#include "controllers/car_controller.h"


using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;


int main() {
   // Listener pentru ambele rute: /api/cars și /api/cars/{id}
    uri_builder uri(U("http://localhost:3001/api/cars"));
    auto addr = uri.to_uri().to_string();
    http_listener listener(addr);

    CarController car_controller;

    listener.support(methods::POST, std::bind(&CarController::create_car, &car_controller, std::placeholders::_1));

     listener.support(methods::GET, [&](http_request request) {
        auto path = uri::split_path(uri::decode(request.relative_uri().path()));

        if (path.empty()) {
            car_controller.get_all_cars(request);
        } 
        else if (path.size() == 1) {
            try {
                int car_id = std::stoi(path[0]);
                car_controller.get_car_by_id(request, car_id);
            } catch (const std::exception &e) {
                request.reply(status_codes::BadRequest, U("Invalid ID format"));
            }
        } else {
            request.reply(status_codes::BadRequest, U("Invalid request path"));
        }
    });

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
