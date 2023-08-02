#ifndef NGUOI_H
#define NGUOI_H

#include <string>

class Nguoi {
private:
    std::string hoTen;
    int tuoi;
    std::string soCMND;

public:
    Nguoi();
    Nguoi(std::string hoTen, int tuoi, std::string soCMND);
    std::string getHoTen();
    int getTuoi();
    std::string getSoCMND();
    void setHoTen(std::string hoTen);
    void setTuoi(int tuoi);
    void setSoCMND(std::string soCMND);
};

#endif // NGUOI_H
