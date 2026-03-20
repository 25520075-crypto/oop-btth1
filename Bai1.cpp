#include <iostream>
using namespace std;

// Lớp PhanSo dùng để biểu diễn và xử lý phân số
class PhanSo {
private:
    int iTu, iMau; // iTu: tử số, iMau: mẫu số

public:
    /*
    Hàm Nhap()
    - Chức năng: Nhập tử số và mẫu số từ bàn phím
    - Đầu vào: Không có tham số (nhập trực tiếp từ cin)
    - Đầu ra: Không trả về giá trị, cập nhật iTu và iMau
    - Lưu ý: Kiểm tra mẫu số phải khác 0
    */
    void Nhap() {
        cout << "Nhap tu: ";
        cin >> iTu;

        cout << "Nhap mau: ";
        cin >> iMau;

        // Kiểm tra mẫu khác 0
        while (iMau == 0) {
            cout << "Mau phai khac 0. Nhap lai: ";
            cin >> iMau;
        }
    }

    /*
    Hàm Xuat()
    - Chức năng: Xuất phân số ra màn hình dưới dạng a/b
    - Đầu vào: Không có
    - Đầu ra: Không trả về giá trị (in ra màn hình)
    */
    void Xuat() {
        cout << iTu << "/" << iMau << endl;
    }

    /*
    Hàm UCLN(int a, int b)
    - Chức năng: Tính ước chung lớn nhất (UCLN) của hai số nguyên
    - Thuật toán: Euclid
    - Đầu vào:
        + a: số nguyên thứ nhất
        + b: số nguyên thứ hai
    - Đầu ra:
        + Trả về UCLN của a và b
    */
    int UCLN(int a, int b) {
        // Đưa về số không âm
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        // Thuật toán Euclid
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    /*
    Hàm RutGon()
    - Chức năng: Rút gọn phân số về dạng tối giản
    - Đầu vào: Không có (sử dụng iTu, iMau)
    - Đầu ra: Không trả về giá trị (cập nhật iTu, iMau đã rút gọn)
    - Các bước:
        + Tìm UCLN của tử và mẫu
        + Chia cả tử và mẫu cho UCLN
        + Đảm bảo mẫu luôn dương
    */
    void RutGon() {
        int g = UCLN(iTu, iMau); // tìm UCLN

        iTu /= g;
        iMau /= g;

        // Đảm bảo mẫu số luôn dương
        if (iMau < 0) {
            iTu = -iTu;
            iMau = -iMau;
        }
    }
};

/*
Hàm main()
- Chức năng: Chạy chương trình chính
- Đầu vào: Nhập phân số từ người dùng
- Đầu ra: In phân số sau khi rút gọn
*/
int main() {
    PhanSo ps;

    cout << "=== BAI 1: RUT GON PHAN SO ===" << endl;

    ps.Nhap();      // Nhập phân số
    ps.RutGon();    // Rút gọn phân số

    cout << "Phan so sau khi rut gon: ";
    ps.Xuat();      // Xuất kết quả

    return 0;
}
