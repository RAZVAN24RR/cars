#ifndef CAR_SERVICE_H
#define CAR_SERVICE_H

#include <string>

class CarService {
public:
    bool insert_car(const std::string &make, const std::string &model, int year);
};

#endif // CAR_SERVICE_H
