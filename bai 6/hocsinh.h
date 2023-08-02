#ifndef HOCSINH_H
#define HOCSINH_H

#include <string>

class HocSinh {
private:
    std::string hoTen;
    int tuoi;
    std::string queQuan;

public:
    HocSinh();
    HocSinh(std::string hoTen, int tuoi, std::string queQuan);
    std::string getHoTen();
    int getTuoi();
    std::string getQueQuan();
    void setHoTen(std::string hoTen);
    void setTuoi(int tuoi);
    void setQueQuan(std::string queQuan);
};

#endif // HOCSINH_H
