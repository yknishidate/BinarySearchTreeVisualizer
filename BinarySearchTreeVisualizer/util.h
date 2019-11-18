#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <QWidget>

int getNumDigits(int num){
    return std::to_string(num).length();
}

#endif // UTIL_H
