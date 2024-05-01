//
// Created by cuishi on 24-4-23.
//

#include "Conf.h"

std::string Conf::getValue(std::string key) {
    return nullptr;
}



void Conf::readProperties(const std::string& file) {
    file_reader_.open("../../conf" + file);
    if (file_reader_.is_open()) {

    } else {
        throw std::runtime_error("can not find " + file + ".properties");
    }
}

Conf::~Conf() {
    if (file_reader_) {
        file_reader_.close();
    }
}

