#include "car_dto.h"

CarDTO::CarDTO(int id, const std::string& make, const std::string& model, int year)
: id(id), make(make), model(model), year(year) {};

int CarDTO::get_id() const {
    return id;
};

const std::string& CarDTO::get_make() const {
    return make;
}

const std::string& CarDTO::get_model() const {
    return model;
}

int CarDTO::get_year() const {
    return year;
}

void CarDTO::set_id(int id){
    this->id = id;
}

void CarDTO::set_make(const std::string& make){
    this->make = make;
}
void CarDTO::set_model(const std::string& model){
    this->model = model;
}

void CarDTO::set_year(int year){
    this->year = year;
}