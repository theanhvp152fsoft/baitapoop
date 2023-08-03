#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class VanBan {
private:
    string text;

public:
    // Yêu cầu 1: Hàm khởi tạo
    VanBan() {
        text = "";
    }

    VanBan(string st) {
        text = st;
    }

    // Yêu cầu 2: Phương thức đếm số từ của văn bản
    int demSoTu() {
        int count = 0;
        int i = 0;
        while (i < text.length()) {
            // kiểm tra kí tự có phải khoảng trắng không
            while (i < text.length() && !isspace(text[i])) {
                i++;
            }
            if (i == text.length()) {
                break;
            }
            count++;

            // Đếm từ bằng cách tìm ký tự khoảng trắng tiếp theo
            // while (i < text.length() && !isspace(text[i])) {
            //     i++;
            // }
        }
        return count;
    }

    // Yêu cầu 3: Phương thức đếm số lượng ký tự 'A' (không phân biệt hoa thường) của văn bản
    int demSoLuongKyTuA() {
        int count = 0;
        for (char c : text) {
            if (toupper(c) == 'A') {
                count++;
            }
        }
        return count;
    }

    // Yêu cầu 4: Chuẩn hoá văn bản
    void chuanHoaVanBan() {
        // Xóa các ký tự trống ở đầu và cuối xâu
        while (!text.empty() && isspace(text.front())) {
            text.erase(0, 1);
        }
        while (!text.empty() && isspace(text.back())) {
            text.pop_back();
        }

        // Chuẩn hoá các ký tự khoảng trắng trong xâu
        int i = 0;
        while (i < text.length()) {
            // Bỏ qua các ký tự khoảng trắng kiền kề nhau
            while (i < text.length() && isspace(text[i]) && isspace(text[i + 1])) {
                text.erase(i, 1);
            }
            i++;
        }
    }

    // Phương thức in văn bản
    void inVanBan() {
        cout << text << endl;
    }
};

int main() {
    string str;
    cout << "Nhap vao van ban: ";
    getline(cin, str);

    VanBan vb(str);

    cout << "So tu cua van ban: " << vb.demSoTu() << endl;
    cout << "So luong ky tu 'A' (khong phan biet hoa thuong) cua van ban: " << vb.demSoLuongKyTuA() << endl;

    cout << "Van ban sau khi chuan hoa:" << endl;
    vb.chuanHoaVanBan();
    vb.inVanBan();

    return 0;
}
