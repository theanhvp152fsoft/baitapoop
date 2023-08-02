#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Yêu cầu 1: Hãy xây dựng lớp Nguoi để quản lý thông tin của mỗi cá nhân
class Nguoi {
private:
    string hoTen;
    int tuoi;
    string ngheNghiep;
    string soCMND;
public:
    Nguoi() {}

    Nguoi(string ten, int tuoi, string ngheNghiep, string cmnd): hoTen(ten), tuoi(tuoi), ngheNghiep(ngheNghiep), soCMND(cmnd) {}

    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();
        cout << "Nhap nghe nghiep: ";
        getline(cin, ngheNghiep);
        cout << "Nhap so CMND: ";
        getline(cin, soCMND);
    }

    void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Nghe nghiep: " << ngheNghiep << endl;
        cout << "So CMND: " << soCMND << endl;
    }
};
//Yêu cầu 2: Xây dựng lớp HoGiaDinh để quản lý thông tin của từng hộ gia đình.
class HoGiaDinh {
private:
    int soThanhVien;
    int soNha;
    vector<Nguoi> danhSachNguoi;
public:
    HoGiaDinh() {}

    HoGiaDinh(int soTV, int soNha): soThanhVien(soTV), soNha(soNha) {}

    void nhap() {
        cout << "Nhap so thanh vien trong gia dinh: ";
        cin >> soThanhVien;
        cout << "Nhap so nha: ";
        cin >> soNha;
        cin.ignore();
        for (int i = 0; i < soThanhVien; i++) {
            Nguoi nguoi;// tác dụng của dòng 14 khi khởi tạo constructor mặc định, ko cần đối số
            cout << "Nhap thong tin nguoi thu " << i + 1 << endl;
            nguoi.nhap();
            danhSachNguoi.push_back(nguoi);
        }
    }

    void xuat() {
        cout << "Thong tin ho gia dinh" << endl;
        cout << "So thanh vien trong gia dinh: " << soThanhVien << endl;
        cout << "So nha: " << soNha << endl;
        for (auto& nguoi : danhSachNguoi) {
            nguoi.xuat();
            cout << endl;
        }
    }
};

class KhuPho {
private:
    vector<HoGiaDinh> danhSachHoGiaDinh;
public:
    void nhap(int n) {
        for (int i = 0; i < n; i++) {
            HoGiaDinh hoGiaDinh;
            cout << "Nhap thong tin ho gia dinh thu " << i + 1 << endl;
            hoGiaDinh.nhap();
            danhSachHoGiaDinh.push_back(hoGiaDinh);
        }
    }

    void hienThiThongTinKhuPho() {
        for (auto& hoGiaDinh : danhSachHoGiaDinh) {
            hoGiaDinh.xuat();
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Nhap so ho dan: ";
    cin >> n;
    KhuPho khuPho;
    khuPho.nhap(n);
    khuPho.hienThiThongTinKhuPho();
    return 0;
}
