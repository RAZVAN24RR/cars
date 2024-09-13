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
};


#endif // !CONTROLLERS