#include "nguoi.h"

Nguoi::Nguoi() {}

Nguoi::Nguoi(std::string hoTen, int tuoi, std::string soCMND)
    : hoTen(hoTen), tuoi(tuoi), soCMND(soCMND) {}

std::string Nguoi::getHoTen() {
    return hoTen;
}

int Nguoi::getTuoi() {
    return tuoi;
}

std::string Nguoi::getSoCMND() {
    return soCMND;
}

void Nguoi::setHoTen(std::string hoTen) {
    this->hoTen = hoTen;
}

void Nguoi::setTuoi(int tuoi) {
    this->tuoi = tuoi;
}

void Nguoi::setSoCMND(std::string soCMND) {
    this->soCMND = soCMND;
}
