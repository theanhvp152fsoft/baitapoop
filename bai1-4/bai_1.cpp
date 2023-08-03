#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Lớp cơ sở CanBo
class CanBo {
protected:
    string ho_ten;
    int tuoi;
    string gioi_tinh;
    string dia_chi;
    // khai bao kieu protected để các lop con kế thừa
public:
    
    // khai bao constructor
    CanBo(string ho_ten, int tuoi, string gioi_tinh, string dia_chi)
    : ho_ten(ho_ten), tuoi(tuoi), gioi_tinh(gioi_tinh), dia_chi(dia_chi) {}

    // Phương thức để truy cập hoTen dùng cho phần dưới
    string getHoTen() const {
        return ho_ten;
    }
    // dung virtual de co the ghi đè tai cac lop con
    virtual void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, ho_ten);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();
        cout << "Nhap gioi tinh (nam/nu/khac): ";
        getline(cin, gioi_tinh);
        cout << "Nhap dia chi: ";
        getline(cin, dia_chi);
    }

    virtual void hienThi() {
        cout << "Ho ten: " << ho_ten << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Gioi tinh: " << gioi_tinh << endl;
        cout << "Dia chi: " << dia_chi << endl;
    }
};

// Yeu cau 1: Xây dựng các lớp CongNhan, KySu, NhanVien kế thừa từ lớp CanBo.

// Lớp CongNhan 
class CongNhan : public CanBo {
private:
    int bac;

public:
    CongNhan(string ho_ten, int tuoi, string gioi_tinh, string dia_chi, int bac)
        : CanBo(ho_ten, tuoi, gioi_tinh, dia_chi), bac(bac) {}

    // override lại hàm nhap và thêm bac
    void nhap() override {
        CanBo::nhap();
        cout << "Nhap bac cong nhan (tu 1 den 10): ";
        cin >> bac;
        cin.ignore();
    }

    void hienThi() override {
        CanBo::hienThi();
        cout << "Bac: " << bac << endl;
    }
};

// Lớp KySu 
class KySu : public CanBo {
private:
    string nganh_dao_tao;

public:
    KySu(string ho_ten, int tuoi, string gioi_tinh, string dia_chi, string nganh_dao_tao)
        : CanBo(ho_ten, tuoi, gioi_tinh, dia_chi), nganh_dao_tao(nganh_dao_tao) {}

    void nhap() override {
        CanBo::nhap();
        cout << "Nhap nganh dao tao: ";
        getline(cin, nganh_dao_tao);
    }

    void hienThi() override {
        CanBo::hienThi();
        cout << "Nganh dao tao: " << nganh_dao_tao << endl;
    }
};

// Lớp NhanVien 
class NhanVien : public CanBo {
private:
    string cong_viec;

public:
    NhanVien(string ho_ten, int tuoi, string gioi_tinh, string dia_chi, string cong_viec)
        : CanBo(ho_ten, tuoi, gioi_tinh, dia_chi), cong_viec(cong_viec) {}

    void nhap() override {
        CanBo::nhap();
        cout << "Nhap cong viec: ";
        getline(cin, cong_viec);
    }

    void hienThi() override {
        CanBo::hienThi();
        cout << "Cong viec: " << cong_viec << endl;
    }
};

// Yeu cau 2: Xây dựng lớp QLCB(quản lý cán bộ) cài đặt các phương thức thực hiện các chức năng 

// Lớp quản lý cán bộ (QLCB)
class QLCB {
private:
    vector<CanBo*> danhSachCanBo;// tro den cac doi tuong cua CanBo
    // su dung vecto de linh hoat trong viec cap phat bộ nhớ khi so lương can bo thay doi,done!
public:
    void themCanBo() {
        int loaiCanBo;
        cout << "Chon loai can bo (1: Cong nhan, 2: Ky su, 3: Nhan vien): ";
        cin >> loaiCanBo;
        cin.ignore();

        string ho_ten, gioi_tinh, dia_chi;
        int tuoi;
        cout << "Nhap thong tin can bo:" << endl;
        cout << "Nhap ho ten: ";
        getline(cin, ho_ten);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();
        cout << "Nhap gioi tinh (nam/nu/khac): ";
        getline(cin, gioi_tinh);
        cout << "Nhap dia chi: ";
        getline(cin, dia_chi);

        // dung cau truc re nhanh 
        switch (loaiCanBo) {
            case 1: {
                int bac;
                cout << "Nhap bac cong nhan (tu 1 den 10): ";
                cin >> bac;
                cin.ignore();
                CanBo* congNhan = new CongNhan(ho_ten, tuoi, gioi_tinh, dia_chi, bac);
                danhSachCanBo.push_back(congNhan);// them can bo kieu congnhan vao cuoi danhsachcanbo
                break;
            }
            case 2: {
                string nganh_dao_tao;
                cout << "Nhap nganh dao tao: ";
                getline(cin, nganh_dao_tao);
                CanBo* kySu = new KySu(ho_ten, tuoi, gioi_tinh, dia_chi, nganh_dao_tao);
                danhSachCanBo.push_back(kySu);
                break;
            }
            case 3: {
                string cong_viec;
                cout << "Nhap cong viec: ";
                getline(cin, cong_viec);
                CanBo* nhanVien = new NhanVien(ho_ten, tuoi, gioi_tinh, dia_chi, cong_viec);
                danhSachCanBo.push_back(nhanVien);
                break;
            }
            default:
                cout << "Loai can bo khong hop le!" << endl;
                break;
        }
    }
    // tìm kiếm theo họ tên
    void timkiemtheohoten() {
        string hoTenCanTim;
        cout << "Nhap ho ten can tim: ";
        getline(cin, hoTenCanTim);
    // check
        bool timThay = false;
        CanBo* CanBo ;
            if (CanBo->getHoTen() == hoTenCanTim) {
                CanBo->hienThi();
                timThay = true;
            }
        

        if (!timThay) {
            cout << "Khong tim thay can bo nao co ho ten: " << hoTenCanTim << endl;
        }
    }
    // hiển thị danh sách cán bộ
    void hienThiDanhSachCanBo() {
        if (danhSachCanBo.empty()) {
            cout << "Danh sach can bo rong!" << endl;
        } else {
            cout << "Danh sach can bo:" << endl;
            CanBo* canBo;
                canBo->hienThi();
                cout << endl;
            }
        }
    };


int main() {
    QLCB qlcb;
    int choice;

    do {
        cout << "--Bai tap 1--" << endl;
        cout << "1. Them moi can bo" << endl;
        cout << "2. Tim kiem theo ho ten" << endl;
        cout << "3. Hien thi danh sach can bo" << endl;
        cout << "4. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                qlcb.themCanBo();
                break;
            case 2:
                qlcb.timkiemtheohoten();
                break;
            case 3:
                qlcb.hienThiDanhSachCanBo();
                break;
            case 4:
                cout << "Tam biet!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}
