#ifndef KHACHSAN_H
#define KHACHSAN_H

#include <vector>
#include "nguoi.h"

class KhachSan {
private:
    struct Phong {
        int soNgayThue;
        char loaiPhong; // A, B, C
        Nguoi* khachThue;
    };

    std::vector<Phong> danhSachPhong;

public:
    KhachSan();
    void themPhong(int soNgayThue, char loaiPhong, Nguoi* khachThue);
    bool xoaKhachTheoCMND(std::string soCMND);
    int tinhTienThuePhong(std::string soCMND);
};

#endif // KHACHSAN_H
