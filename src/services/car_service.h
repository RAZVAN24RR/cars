#ifndef CAR_SERVICE_H
#define CAR_SERVICE_H

#include <string>
#include <cpprest/json.h>

class CarService {
public:
    bool insert_car(const std::string &make, const std::string &model, int year);
    web::json::value  get_all_cars();
};

#endif // CAR_SERVICE_H
