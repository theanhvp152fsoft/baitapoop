#include <iostream>
#include "khachsan.h"

int main() {
    KhachSan khachSan;

    // Thêm khách vào phòng
    Nguoi* khach1 = new Nguoi("Nguyen Van A", 30, "123456789");
    khachSan.themPhong(5, 'A', khach1);

    Nguoi* khach2 = new Nguoi("Tran Thi B", 25, "987654321");
    khachSan.themPhong(3, 'B', khach2);

    // Tính tiền thuê phòng cho khách
    std::string cmndKhach1 = "123456789";
    int tienKhach1 = khachSan.tinhTienThuePhong(cmndKhach1);
    std::cout << "Tien khach " << khach1->getHoTen() << " can tra: $" << tienKhach1 << std::endl;

    std::string cmndKhach2 = "987654321";
    int tienKhach2 = khachSan.tinhTienThuePhong(cmndKhach2);
    std::cout << "Tien khach " << khach2->getHoTen() << " can tra: $" << tienKhach2 << std::endl;

    // Xoá khách theo số chứng minh nhân dân
    std::string cmndXoa = "987654321";
    if (khachSan.xoaKhachTheoCMND(cmndXoa)) {
        std::cout << "Da xoa khach co CMND " << cmndXoa << std::endl;
    } else {
        std::cout << "Khong tim thay khach co CMND " << cmndXoa << std::endl;
    }

    // Tính tiền lại sau khi xoá khách
    int tienKhach1_sauXoa = khachSan.tinhTienThuePhong(cmndKhach1);
    std::cout << "Tien khach " << khach1->getHoTen() << " can tra sau khi xoa: $" << tienKhach1_sauXoa << std::endl;

    delete khach1;
    delete khach2;

    return 0;
}
