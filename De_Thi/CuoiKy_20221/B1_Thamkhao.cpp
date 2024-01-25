//Tao sua code chat GPT thoi nhe
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Delivery {
    string trip_code;
    string customer_code;
    string date;
    string time;
    int qty;
};

map<string, vector<Delivery>> trips;
map<string, int> customer_qty;

void processInput() {
    string line;
    while (getline(cin, line) && line != "***") {
        if (line == "*") {
            // Read part 2
            while (getline(cin, line) && line != "***") {
                istringstream iss(line);
                Delivery delivery;
                iss >> delivery.trip_code >> delivery.customer_code >> delivery.date >> delivery.time >> delivery.qty;

                // Add delivery to the corresponding trip
                trips[delivery.trip_code].push_back(delivery);

                // Update customer_qty
                customer_qty[delivery.customer_code] += delivery.qty;
            }
        }
    }
}

int getTotalQty() {
    int total_qty = 0;
    for (const auto& trip : trips) {
        for (const auto& delivery : trip.second) {
            total_qty += delivery.qty;
        }
    }
    return total_qty;
}

int getQtyCustomer(const string& customer_code) {
    return customer_qty[customer_code];
}

int getQtyMaxPeriod(const string& from_date, const string& from_time, const string& to_date, const string& to_time) {
    int max_qty = 0;
    string max_date, max_time;

    for (const auto& trip : trips) {
        for (const auto& delivery : trip.second) {
            if (delivery.date >= from_date && (delivery.date + " " + delivery.time) >= (from_date + " " + from_time) &&
                delivery.date <= to_date && (delivery.date + " " + delivery.time) <= (to_date + " " + to_time)) {
                if (customer_qty[delivery.customer_code] > max_qty) {
                    max_qty = customer_qty[delivery.customer_code];
                    max_date = delivery.date;
                    max_time = delivery.time;
                }
            }
        }
    }

    return max_qty;
}

int getTotalTrips() {
    return trips.size();
}

string getTravelTimeTrip(const string& trip_code) {
    int total_time_seconds = 0;
    for (const auto& delivery : trips[trip_code]) {
        // Assume all deliveries in the same trip have the same date
        string delivery_time = delivery.date + " " + delivery.time;
        tm tm = {};
        istringstream ss(delivery_time);
        ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
        total_time_seconds += tm.tm_hour * 3600 + tm.tm_min * 60 + tm.tm_sec;
    }

    int hours = total_time_seconds / 3600;
    int minutes = (total_time_seconds % 3600) / 60;
    int seconds = total_time_seconds % 60;

    ostringstream oss;
    oss << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds;
    return oss.str();
}

int getMaxConflictTrips() {
    int max_conflict_count = 0;

    for (const auto& trip1 : trips) {
        for (const auto& trip2 : trips) {
            if (trip1.first != trip2.first) {
                bool has_conflict = false;
                for (const auto& delivery1 : trip1.second) {
                    for (const auto& delivery2 : trip2.second) {
                        if (delivery1.date == delivery2.date && delivery1.time == delivery2.time) {
                            has_conflict = true;
                            break;
                        }
                    }
                    if (has_conflict) {
                        break;
                    }
                }
                if (!has_conflict) {
                    max_conflict_count = max(max_conflict_count, static_cast<int>(trip1.second.size() + trip2.second.size()));
                }
            }
        }
    }

    return max_conflict_count;
}

int main() {
    processInput();

    string query;
    while (getline(cin, query) && query != "***") {
        if (query == "TOTAL_QTY") {
            cout << getTotalQty() << endl;
        } else if (query.substr(0, 12) == "QTY_CUSTOMER") {
            string customer_code = query.substr(13);
            cout << getQtyCustomer(customer_code) << endl;
        } else if (query.substr(0, 13) == "QTY_MAX_PERIOD") {
            istringstream iss(query);
            string cmd, from_date, from_time, to_date, to_time;
            iss >> cmd >> from_date >> from_time >> to_date >> to_time;
            cout << getQtyMaxPeriod(from_date, from_time, to_date, to_time) << endl;
        } else if (query == "TOTAL_TRIPS") {
            cout << getTotalTrips() << endl;
        } else if (query.substr(0, 17) == "TRAVEL_TIME_TRIP") {
            string trip_code = query.substr(18);
            cout << getTravelTimeTrip(trip_code) << endl;
        } else if (query == "MAX_CONFLICT_TRIPS") {
            cout << getMaxConflictTrips() << endl;
        }
    }

    return 0;
}
