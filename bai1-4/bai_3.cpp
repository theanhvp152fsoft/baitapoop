#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Tương tự bài 1,2

class ThiSinh {
protected:
    string soBaoDanh;
    string hoTen;
    string diaChi;
    int mucUuTien;
public:

    string getSoBaoDanh() const {
        return soBaoDanh;
    }

    ThiSinh(string sbd, string ten, string diaChi, int uuTien)
        : soBaoDanh(sbd), hoTen(ten), diaChi(diaChi), mucUuTien(uuTien) {}

    virtual void nhap() {
        cout << "Nhap so bao danh: ";
        cin >> soBaoDanh;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap muc uu tien: ";
        cin >> mucUuTien;
    }

    virtual void hienthi() {
        cout << "So bao danh: " << soBaoDanh << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Muc uu tien: " << mucUuTien << endl;
    }

    
};
//Yêu cầu 1: Xây dựng các lớp để quản lý các thi sinh dự thi đại học.

class ThiSinhKhoiA : public ThiSinh {
public:
    ThiSinhKhoiA(string sbd, string ten, string diaChi, int uuTien)
        : ThiSinh(sbd, ten, diaChi, uuTien) {}

    void hienthi() override {
        ThiSinh::hienthi();
        cout << "Khoi thi: A (Toan, Ly, Hoa)" << endl;
    }
};

class ThiSinhKhoiB : public ThiSinh {
public:
    ThiSinhKhoiB(string sbd, string ten, string diaChi, int uuTien)
        : ThiSinh(sbd, ten, diaChi, uuTien) {}

    void hienthi() override {
        ThiSinh::hienthi();
        cout << "Khoi thi: B (Toan, Hoa, Sinh)" << endl;
    }
};

class ThiSinhKhoiC : public ThiSinh {
public:
    ThiSinhKhoiC(string sbd, string ten, string diaChi, int uuTien)
        : ThiSinh(sbd, ten, diaChi, uuTien) {}

    void hienthi() override {
        ThiSinh::hienthi();
        cout << "Khoi thi: C (Van, Su, Dia)" << endl;
    }
};

class TuyenSinh {
private:
    vector<ThiSinh*> danhSachThiSinh;
public:
    // thêm thí sinh
    void themThiSinh(ThiSinh* thiSinh) {
        danhSachThiSinh.push_back(thiSinh);
    }
    // hiển thị thông tin thí sinh
    void hienThiThongTinThiSinh() {
        for (const auto& thiSinh : danhSachThiSinh) {
            thiSinh->hienthi();
            cout << endl;
        }
    }
    // tìm kiếm theo số báo danh
    void timKiemTheoSoBaoDanh(string soBaoDanh) {
        for (const auto& thiSinh : danhSachThiSinh) {
            if (thiSinh->getSoBaoDanh() == soBaoDanh) {
                thiSinh->hienthi();
                return;
            }
        }
        cout << "Khong tim thay thi sinh co so bao danh " << soBaoDanh << endl;
    }
    // Ham huy lop tuyensinh
    ~TuyenSinh() {
        for (const auto& thiSinh : danhSachThiSinh) {
            delete thiSinh;
        }
    }
};

int main() {
    TuyenSinh tuyenSinh;
    int luaChon;
    while (true) {
        cout << "--bai tap 3--" << endl;
        cout << "1. Them thi sinh" << endl;
        cout << "2. Hien thi thong tin thi sinh" << endl;
        cout << "3. Tim kiem theo so bao danh" << endl;
        cout << "4. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
        case 1: {
            cout << "1. Them thi sinh Khoi A" << endl;
            cout << "2. Them thi sinh Khoi B" << endl;
            cout << "3. Them thi sinh Khoi C" << endl;
            cout << "Nhap lua chon cua ban: ";
            int luaChonThem;
            cin >> luaChonThem;
            // switch case lồng nhau được sử dụng để thêm thí sinh khối nào
            switch (luaChonThem) {
            case 1: {
                ThiSinhKhoiA* thiSinh = new ThiSinhKhoiA("", "", "", 0);
                thiSinh->nhap();
                tuyenSinh.themThiSinh(thiSinh);
                break;
            }
            case 2: {
                ThiSinhKhoiB* thiSinh = new ThiSinhKhoiB("", "", "", 0);
                thiSinh->nhap();
                tuyenSinh.themThiSinh(thiSinh);
                break;
            }
            case 3: {
                ThiSinhKhoiC* thiSinh = new ThiSinhKhoiC("", "", "", 0);
                thiSinh->nhap();
                tuyenSinh.themThiSinh(thiSinh);
                break;
            }
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
            break;
        }
        case 2: {
            tuyenSinh.hienThiThongTinThiSinh();
            break;
        }
        case 3: {
            string soBaoDanh;
            cout << "Nhap so bao danh can tim kiem: ";
            cin >> soBaoDanh;
            tuyenSinh.timKiemTheoSoBaoDanh(soBaoDanh);
            break;
        }
        case 4:
            cout << "Thoat chuong trinh." << endl;
            return 0;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    }
}
