#ifndef CAR_SERVICE_H
#define CAR_SERVICE_H

#include <string>
#include <cpprest/json.h>
#include <vector>
#include "models/car_dto.h"

class CarService {
public:
    bool insert_car(const std::string &make, const std::string &model, int year);
    std::vector<CarDTO>  get_all_cars();
    CarDTO get_car_by_id(int car_id);
    bool delete_car_by_id(int car_id);
};

#endif // CAR_SERVICE_H
