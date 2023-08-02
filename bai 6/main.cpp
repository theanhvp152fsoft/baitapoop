#include <iostream>
#include <vector>
#include "hocsinh.h"

int main() {
    std::vector<HocSinh> danhSachHocSinh;

    // Thêm học sinh mới
    HocSinh hocSinh1("Nguyen Van A", 18, "Hanoi");
    danhSachHocSinh.push_back(hocSinh1);

    HocSinh hocSinh2("Tran Thi B", 20, "Danang");
    danhSachHocSinh.push_back(hocSinh2);

    HocSinh hocSinh3("Le Van C", 23, "Danang");
    danhSachHocSinh.push_back(hocSinh3);

    HocSinh hocSinh4("Pham Thi D", 23, "Hanoi");
    danhSachHocSinh.push_back(hocSinh4);

    // Hiển thị các học sinh 20 tuổi
    std::cout << "Cac hoc sinh 20 tuoi:" << std::endl;
    for (auto& hocSinh : danhSachHocSinh) {
        if (hocSinh.getTuoi() == 20) {
            std::cout << "- " << hocSinh.getHoTen() << std::endl;
        }
    }

    // Đếm số lượng học sinh có tuổi là 23 và quê ở Danang
    int count = 0;
    for ( auto& hocSinh : danhSachHocSinh) {
        if (hocSinh.getTuoi() == 23 && hocSinh.getQueQuan() == "Danang") {
            count++;
        }
    }
    std::cout << "So luong hoc sinh co tuoi la 23 va que o Danang: " << count << std::endl;

    return 0;
}
