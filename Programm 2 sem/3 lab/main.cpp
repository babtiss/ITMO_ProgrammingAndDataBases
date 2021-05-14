#include "pugixml.hpp"
#include "Transport_stop.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

int main() {
    system("chcp 65001");

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("tree.xml");
    pugi::xml_node iter = doc.child("dataset");
    std::vector<std::string> rout;
    std::map<std::string, Transport_stop> mp;//<routs, class with all information>

    for (pugi::xml_node_iterator iterat = iter.begin(); iterat != iter.end(); ++iterat) {
        int64_t r = 0;
        std::string routes = iterat->child("routes").text().as_string();
        for (int j = 0; j < routes.length(); j++) { // parse routs, routs could be separated "," or "."
            if (routes[j] == '.' || routes[j] == ',') {
                rout.push_back(routes.substr(r, j - r));
                r = j + 1;
            }
        }

        rout.push_back(routes.substr(r, routes.length() - r));

        for (auto& k : rout) {
            if (mp.count(k) == 0) {
                mp.insert({k, Transport_stop(iterat)});
            } else {
                mp[k] = mp[k].update(iterat);
            }
        }
        rout.clear();
    }

//    std::unordered_map<int, int> x{};
    std::map<std::string, int> counter_of_types;
    std::map<std::string, std::map<std::string, int>> max_stops; //<type_of_vehicle,<routes,count_of_stops>>

    for (auto &[cur_rout, cur_stop] : mp) {
        std::vector<std::string> vehicles = cur_stop.get_type_of_vehicle();
        for (auto & vehicle : vehicles) {
            if (counter_of_types.count(vehicle) == 0) {
                counter_of_types.insert({vehicle, 1});
            } else {
                counter_of_types[vehicle] += 1;
            }
        }
        for (auto &[current_type, counter] : counter_of_types) {

            if (max_stops.count(current_type) == 0) {
                max_stops[current_type][cur_rout] = counter;
            } else {
                if (counter > max_stops[current_type].begin()->second) {
                    max_stops.erase(current_type);
                    max_stops[current_type][cur_rout] = counter;
                }
            }
        }
        counter_of_types.clear();
    }

    // Answer 1 part
    std::cout << "TASK 1" << std::endl;
    for (auto &[type_of_vehicle, cur_stop] : max_stops) {
        std::cout << type_of_vehicle << std::endl;
        std::cout << "Most stops on the route №" << cur_stop.begin()->first << ", quantity =  "
                  << cur_stop.begin()->second << std::endl;
        std::vector<std::string> veh = mp[cur_stop.begin()->first].get_type_of_vehicle();
        std::vector<std::string> names = mp[cur_stop.begin()->first].get_the_official_name();
        for (int i = 0; i < veh.size(); i++) {
            if (veh[i] == type_of_vehicle) {
                std::cout << "->" << names[i];
            }

        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    // 2 part of exercise
    std::map<std::string, double> counter_of_routs;
    std::map<std::string, std::map<std::string, double>> longest_rout;
    for (auto &[cur_rout, cur_stop] : mp) {
        std::vector<std::string> vehicles = cur_stop.get_type_of_vehicle();
        std::vector<std::pair<double, double>> coord = mp[cur_rout].make_coordinates_double();
        for (int j = 0; j < vehicles.size() - 1; j++) {
            double dist = sqrt((coord[j + 1].first - coord[j].first) * (coord[j + 1].first - coord[j].first)
                               + (coord[j + 1].second - coord[j].second) * (coord[j + 1].second - coord[j].second));
            if (counter_of_routs.count(vehicles[j]) == 0) {
                counter_of_routs.insert({vehicles[j], dist});
            } else {
                counter_of_routs[vehicles[j]] += dist;
            }
        }

        for (auto &[current_type, counter] : counter_of_routs) {

            if (longest_rout.count(current_type) == 0) {
                longest_rout[current_type][cur_rout] = counter;
            } else {
                if (counter > longest_rout[current_type].begin()->second) {
                    longest_rout.erase(current_type);
                    longest_rout[current_type][cur_rout] = counter;
                }
            }
        }
        counter_of_routs.clear();

    }
    std::cout << "TASK 2" << std::endl;
    for (auto &[cur_rout, current_type] : longest_rout) {
        std::cout << cur_rout << std::endl;
        std::cout << current_type.begin()->first << " " << current_type.begin()->second << std::endl;
        std::vector<std::string> veh = mp[current_type.begin()->first].get_type_of_vehicle();
        std::vector<std::string> names = mp[current_type.begin()->first].get_the_official_name();
        for (int i = 0; i < veh.size(); i++) {
            if (veh[i] == cur_rout) {
                std::cout << "->" << names[i];
            }
        }
        std::cout << std::endl;
        std::cout << "-------------------------" << std::endl;
    }

    std::map<std::string, int> count_of_streets;
    std::cout << "TASK 3" << std::endl;
    for (auto &[cur_rout, cur_stop] : mp) {
        std::vector<std::string> streets = cur_stop.get_location();

        for (auto & street : streets) {
            int r = 0;
            for (int j = 0; j < street.length(); j++) {

                if (street[j] == ',') {
                    std::string str = street.substr(r, j - r);
                    r = j + 1;
                    if (count_of_streets.count(str) == 0 && (str.find("ул.") != -1 || str.find("улица") != -1)) {
                        count_of_streets[str] = 1;
                    } else {
                        if ((str.find("ул.") != -1 || str.find("улица") != -1))
                            count_of_streets[str] += 1;
                    }

                }

            }

            if (r != street.length()) {
                std::string str = street.substr(r, street.length() - r);
                if (count_of_streets.count(str) == 0 && (str.find("ул.") != -1 || str.find("улица") != -1)) {
                    count_of_streets[str] = 1;
                } else {
                    if ((str.find("ул.") != -1 || str.find("улица") != -1))
                        count_of_streets[str] += 1;
                }
            }
        }
    }

    int max_of_all = 0;
    std::string mv_street;

    for (auto &[cur_street, counter] : count_of_streets) {
        if (counter > max_of_all) {
            max_of_all = counter;
            mv_street = cur_street;
        }
    }
    std::cout << "Most valuable street is " << mv_street << " meets " << max_of_all << " times" << std::endl;
}