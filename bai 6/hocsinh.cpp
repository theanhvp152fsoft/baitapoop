#include "hocsinh.h"

HocSinh::HocSinh() {}

HocSinh::HocSinh(std::string hoTen, int tuoi, std::string queQuan)
    : hoTen(hoTen), tuoi(tuoi), queQuan(queQuan) {}

std::string HocSinh::getHoTen() {
    return hoTen;
}

int HocSinh::getTuoi() {
    return tuoi;
}

std::string HocSinh::getQueQuan() {
    return queQuan;
}

void HocSinh::setHoTen(std::string hoTen) {
    this->hoTen = hoTen;
}

void HocSinh::setTuoi(int tuoi) {
    this->tuoi = tuoi;
}

void HocSinh::setQueQuan(std::string queQuan) {
    this->queQuan = queQuan;
}
