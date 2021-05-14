#include "Transport_stop.h"
#include "pugixml.hpp"
#include <vector>
#include <map>
#include <sstream>

//std::vector<std::pair<int, int>> vctr{};
//vctr.push_back(std::make_pair(1, 1));
//vctr.emplace_back(1, 1);

Transport_stop::Transport_stop(pugi::xml_node_iterator it) {
    number.emplace_back(it->child("number").text().as_string());
    object_type.emplace_back(it->child("object_type").text().as_string());
    name_stopping.emplace_back(it->child("name_stopping").text().as_string());
    the_official_name.emplace_back(it->child("the_official_name").text().as_string());
    location.emplace_back(it->child("location").text().as_string());
    coordinates.emplace_back(it->child("coordinates").text().as_string());
    type_of_vehicle.emplace_back(it->child("type_of_vehicle").text().as_string());
};

Transport_stop Transport_stop::update(pugi::xml_node_iterator it) {
    number.emplace_back(it->child("number").text().as_string());
    object_type.emplace_back(it->child("object_type").text().as_string());
    name_stopping.emplace_back(it->child("name_stopping").text().as_string());
    the_official_name.emplace_back(it->child("the_official_name").text().as_string());
    location.emplace_back(it->child("location").text().as_string());
    coordinates.emplace_back(it->child("coordinates").text().as_string());
    type_of_vehicle.emplace_back(it->child("type_of_vehicle").text().as_string());
    return *this;
}

std::vector<std::string> Transport_stop::get_type_of_vehicle() const{
    return type_of_vehicle;
}

std::vector<std::string> Transport_stop::get_the_official_name() const{
    return the_official_name;
}

std::vector<std::string> Transport_stop::get_location() const{
    return location;
}

std::vector<std::pair<double, double>> Transport_stop::make_coordinates_double() const{
    std::vector<std::pair<double, double>> coord;
    double x = 0;
    double y = 0;
    int k = 0;

    for (const auto & coordinate : coordinates) {
        for (int j = 0; j < coordinate.length(); j++) {
            if (coordinate[j] == ',') {
                std::stringstream ss(coordinate.substr(0, j));
                k = j;
                ss >> x;
            }
        }
        std::stringstream ss(coordinate.substr(k + 1));
        ss >> y;

        coord.emplace_back(x, y);
    }
    return coord;
};