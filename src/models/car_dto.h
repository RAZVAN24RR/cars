#ifndef  CAR_DTO_H
#define CAR_DTO_H

#include <string>

class CarDTO{
    public:
    CarDTO() = default;
    CarDTO(int id, const std::string& make, const std::string& model, int year);

    int get_id() const;
    const std::string& get_make() const;
    const std::string& get_model() const;
    int get_year() const;

    void set_id(int id);
    void set_make(const std::string& make);
    void set_model(const std::string& model);
    void set_year(int year);

    private:
    int id;
    std::string make;
    std::string model;
    int year;
};

#endif // ! CAR_DTO_H