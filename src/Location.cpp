#ifndef LOCATION_CPP
#define LOCATION_CPP

#include "Location.h"



    Location Location::operator+(const Location& other) const {
        return { _row + other._row, _col + other._col };
    }

    Location Location::operator-(const Location& other) const {
        return { _row - other._row, _col - other._col };
    }

    bool Location::operator==(const Location& other) const {
        return _row == other._row && _col == other._col;
    }

    bool Location::operator!=(const Location& other) const {
        return !(*this == other);
    }

    Location& Location::operator+=(const Location& other) {
        _row += other._row;
        _col += other._col;
        return *this;
    }

    Location& Location::operator-=(const Location& other) {
        _row -= other._row;
        _col -= other._col;
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Location& location) {
        os << "(" << location._row << "," << location._col << ")";
        return os;
    }

#endif /* LOCATION_CPP */