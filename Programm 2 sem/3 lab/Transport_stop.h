#pragma once

#include <iostream>
#include <vector>
#include "pugixml.hpp"

class Transport_stop {
public:
    explicit Transport_stop(pugi::xml_node_iterator);

    Transport_stop() = default;

    Transport_stop update(pugi::xml_node_iterator);

    [[nodiscard]] std::vector<std::string> get_type_of_vehicle() const;

    [[nodiscard]] std::vector<std::string> get_the_official_name() const;

    [[nodiscard]] std::vector<std::string> get_location() const;

    [[nodiscard]] std::vector<std::pair<double, double>> make_coordinates_double() const;

private:
    std::vector<std::string> type_of_vehicle;
    std::vector<std::string> number;
    std::vector<std::string> object_type;
    std::vector<std::string> name_stopping;
    std::vector<std::string> the_official_name;
    std::vector<std::string> location;
    std::vector<std::string> coordinates;
};