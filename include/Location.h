#ifndef LOCATION_H
#define LOCATION_H

#include <ostream>

struct Location {
    int _row;
    int _col;

    Location operator+(const Location& other) const;

    Location operator-(const Location& other) const;

    bool operator==(const Location& other) const;

    bool operator!=(const Location& other) const;

    Location& operator+=(const Location& other);

    Location& operator-=(const Location& other);

    friend std::ostream& operator<<(std::ostream& os, const Location& location);
};

#endif /* LOCATION_H */