#ifndef CONTROLLERS
#define CONTROLLERS

#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

class CarController{
    public:
    CarController();
    void create_car(web::http::http_request request);
    void get_all_cars(web::http::http_request request);
    void get_car_by_id(web::http::http_request request, int car_id);
    void delete_car_by_id(web::http::http_request request, int car_id);
    void update_car_year_by_id(web::http::http_request request, int car_id);
};


#endif // !CONTROLLERS