#include "khachsan.h"

KhachSan::KhachSan() {}

void KhachSan::themPhong(int soNgayThue, char loaiPhong, Nguoi* khachThue) {
    Phong phong;
    phong.soNgayThue = soNgayThue;
    phong.loaiPhong = loaiPhong;
    phong.khachThue = khachThue;
    danhSachPhong.push_back(phong);
}

bool KhachSan::xoaKhachTheoCMND(std::string soCMND) {
    for (auto it = danhSachPhong.begin(); it != danhSachPhong.end(); ++it) {
        if (it->khachThue->getSoCMND() == soCMND) {
            danhSachPhong.erase(it);
            return true;
        }
    }
    return false;
}

int KhachSan::tinhTienThuePhong(std::string soCMND) {
    int tongTien = 0;
    for (const auto& phong : danhSachPhong) {
        if (phong.khachThue->getSoCMND() == soCMND) {
            switch (phong.loaiPhong) {
                case 'A':
                    tongTien += phong.soNgayThue * 500;
                    break;
                case 'B':
                    tongTien += phong.soNgayThue * 300;
                    break;
                case 'C':
                    tongTien += phong.soNgayThue * 100;
                    break;
                default:
                    break;
            }
        }
    }
    return tongTien;
}
