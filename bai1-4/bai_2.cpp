#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TaiLieu {
protected:
    string maTaiLieu;
    string nhaXuatBan;
    int soBanPhatHanh;

public:
    // Phương thức để truy cập matailieu
    string gettailieu() const {
        return maTaiLieu;
    }
    // khai bao constructor
    TaiLieu(string ma, string nxb, int sbph) : maTaiLieu(ma), nhaXuatBan(nxb), soBanPhatHanh(sbph) {}
    virtual void nhap(){
        cout << "nhap ma tai lieu: ";
        getline (cin, maTaiLieu);
        cin.ignore();
        cout << " nhap nha xuat ban: ";
        getline (cin, nhaXuatBan);
        cin.ignore();
        cout <<" nhap so ban phat hanh: ";
        cin >> soBanPhatHanh;
    }

    virtual void hienThi() {
        cout << " ma tai lieu: " << maTaiLieu << endl;
        cout << "nha xuat ban: " << nhaXuatBan << endl;
        cout << "so ban phat hanh: " << soBanPhatHanh << endl;
    }
};

//Yêu cầu 1: Xây dựng các lớp để quản lý tài liệu cho thư viện một cách hiệu quả.

class Sach : public TaiLieu {
private:
    string tenTacGia;
    int soTrang;

public:
    Sach(string ma, string nxb, int sbph, string tacGia, int soTrang)
        : TaiLieu(ma, nxb, sbph), tenTacGia(tacGia), soTrang(soTrang) {}
    void nhap() override{
        TaiLieu::nhap();
        cout << "nhap ten tac gia: ";
        getline (cin, tenTacGia);
        cin.ignore();
        cout << "nhap so trang: ";
        cin >> soTrang;
    }
    // override lai chuc nang hien thi
    void hienThi() override{
        TaiLieu::hienThi();
        cout << " ten tac gia la: " << tenTacGia << endl;
        cout << " so trang la: "<< soTrang << endl;
    }
};

class TapChi : public TaiLieu {
private:
    int soPhatHanh;
    int thangPhatHanh;

public:
    TapChi(string ma, string nxb, int sbph, int soPH, int thangPH)
        : TaiLieu(ma, nxb, sbph), soPhatHanh(soPH), thangPhatHanh(thangPH) {}

    void nhap() override{
        TaiLieu::nhap();
        cout << "nhap so phat hanh: ";
        cin>> soPhatHanh;
        cout << "nhap so thang phat hanh: ";
        cin >> thangPhatHanh;
    }
    // override lai chuc nang hien thi
    void hienThi() override {
        TaiLieu::hienThi();
        cout << " so phat hanh la: " << soPhatHanh << endl;
        cout << " thang phat hanh: "<< thangPhatHanh << endl;
    }
    
};

class Bao : public TaiLieu {
private:
    string ngayPhatHanh;

public:
    Bao(string ma, string nxb, int sbph, string ngayPH)
        : TaiLieu(ma, nxb, sbph), ngayPhatHanh(ngayPH) {}
    void nhap() override{
        TaiLieu::nhap();
        cout << "nhap ngay phat hanh: ";
        getline (cin, ngayPhatHanh);
    }
    // override lai chuc nang hien thi
    void hienThi() override {
        TaiLieu::hienThi();
        cout << " ngay phat hanh la: " << ngayPhatHanh << endl;
    }
    
};

// Yêu cầu 2: Xây dựng lớp QuanLySach có các chức năng
class QuanLySach {
private:
    // dung vecto tuong tu nhu bai 1
    vector<TaiLieu*> danhSachTaiLieu;
public:
    void themtailieu(TaiLieu* taiLieu) {
        danhSachTaiLieu.push_back(taiLieu);
    }
    // xóa tài liệu: ý tưởng là duyệt đến phần tử thứ i chứa mã tài liệu rồi xóa
void xoaTaiLieu(string maTaiLieu) {
        for (size_t i = 0; i < danhSachTaiLieu.size(); i++) {
            if (danhSachTaiLieu[i]->gettailieu() == maTaiLieu) {
                delete danhSachTaiLieu[i];
                danhSachTaiLieu.erase(danhSachTaiLieu.begin() + i);
                cout << "Xoa tai lieu thanh cong!" << endl;
                return;
            }
        }
        cout << "Khong tim thay tai lieu co ma " << maTaiLieu << endl;
    }

    void hienThiTaiLieu() {
        // su dung auto để tự động có kiểu dữ liệu khi tailieu truy cap tới
        for (const auto& taiLieu : danhSachTaiLieu) {
            taiLieu->hienThi();
            cout << endl;
        }
    }

    void timKiemTaiLieuTheoLoai(string loai) {
        cout << "Danh sach tai lieu loai " << loai << ":" << endl;
        for (const auto& taiLieu : danhSachTaiLieu) {
            if (loai == "Sach" && dynamic_cast<Sach*>(taiLieu) != nullptr) {
                // Ép kiểu biến taiLieu thành kiểu con trỏ Sach* trỏ đến lớp Sach
                taiLieu->hienThi();
                cout << endl;
            } else if (loai == "TapChi" && dynamic_cast<TapChi*>(taiLieu) != nullptr) {
                taiLieu->hienThi();
                cout << endl;
            } else if (loai == "Bao" && dynamic_cast<Bao*>(taiLieu) != nullptr) {
                taiLieu->hienThi();
                cout <<endl;
            }
        }
    }

    ~QuanLySach() {
        for (const auto& taiLieu : danhSachTaiLieu) {
            delete taiLieu;
        }
    }
};

int main() {
    QuanLySach quanLy;
    int luaChon;
    while (true) {
        cout << "--Bai tap 2--" << endl;
        cout << "1. Them tai lieu" << endl;
        cout << "2. Xoa tai lieu" << endl;
        cout << "3. Hien thi tai lieu" << endl;
        cout << "4. Tim kiem tai lieu theo loai" << endl;
        cout << "5. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore();
        switch (luaChon) {
        case 1: {
            cout << "1. Them sach" << endl;
            cout << "2. Them tap chi" << endl;
            cout << "3. Them bao" << endl;
            cout << "Nhap lua chon cua ban: ";
            int luaChonThem;
            cin >> luaChonThem;
            switch (luaChonThem) {
            case 1: {
                Sach* sach = new Sach("", "", 0, "", 0);
                sach->nhap();
                quanLy.themtailieu(sach);
                break;
            }
            case 2: {
                TapChi* tapChi = new TapChi("", "", 0, 0, 0);
                tapChi->nhap();
                quanLy.themtailieu(tapChi);
                break;
            }
            case 3: {
                Bao* bao = new Bao("", "", 0, "");
                bao->nhap();
                quanLy.themtailieu(bao);
                break;
            }
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
            break;
        }
        case 2: {
            string maTaiLieu;
            cout << "Nhap ma tai lieu can xoa: ";
            cin >> maTaiLieu;
            quanLy.xoaTaiLieu(maTaiLieu);
            break;
        }
        case 3: {
            quanLy.hienThiTaiLieu();
            break;
        }
        case 4: {
            cout << "Nhap loai tai lieu can tim kiem (Sach/TapChi/Bao): ";
            string loai;
            cin >> loai;
            quanLy.timKiemTaiLieuTheoLoai(loai);
            break;
        }
        case 5:
            cout << "Thoat chuong trinh." << endl;
            return 0;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    }
}
