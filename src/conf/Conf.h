//
// Created by cuishi on 24-4-23.
//

#ifndef MYRTC_CONF_H
#define MYRTC_CONF_H

#include <iostream>
#include <fstream>
class Conf {
public:
    explicit Conf() = default;
    ~Conf();
    void readProperties(const std::string& file);
    static std::string getValue(std::string key);
private:
    std::ifstream file_reader_;
};


#endif //MYRTC_CONF_H
