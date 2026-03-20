#include <iostream>
using namespace std;

// Lớp PhanSo biểu diễn một phân số
class PhanSo {
private:
    int iTu, iMau; // iTu: tử số, iMau: mẫu số

public:
    /*
    Hàm Nhap()
    - Chức năng: Nhập tử số và mẫu số từ bàn phím
    - Đầu vào: Không có tham số (dữ liệu nhập từ cin)
    - Đầu ra: Không trả về (gán giá trị cho iTu và iMau)
    - Lưu ý: Mẫu số phải khác 0
    */
    void Nhap() {
        cout << "Nhap tu: ";
        cin >> iTu;

        cout << "Nhap mau: ";
        cin >> iMau;

        // Kiểm tra mẫu số hợp lệ
        while (iMau == 0) {
            cout << "Mau phai khac 0. Nhap lai: ";
            cin >> iMau;
        }
    }

    /*
    Hàm Xuat()
    - Chức năng: Xuất phân số ra màn hình dạng a/b
    - Đầu vào: Không có
    - Đầu ra: Không trả về (in ra màn hình)
    */
    void Xuat() {
        cout << iTu << "/" << iMau << endl;
    }

    /*
    Hàm SoSanh(PhanSo ps)
    - Chức năng: So sánh 2 phân số
    - Phương pháp: Nhân chéo để tránh chia số thực
    - Đầu vào:
        + ps: phân số cần so sánh với phân số hiện tại
    - Đầu ra:
        + Trả về 1  nếu phân số hiện tại > ps
        + Trả về 0  nếu hai phân số bằng nhau
        + Trả về -1 nếu phân số hiện tại < ps
    */
    int SoSanh(PhanSo ps) {
        int a = iTu * ps.iMau;   // tử1 * mẫu2
        int b = ps.iTu * iMau;   // tử2 * mẫu1

        if (a > b) return 1;
        if (a == b) return 0;
        return -1;
    }
};

/*
Hàm main()
- Chức năng: Chạy chương trình chính
- Đầu vào: Nhập 2 phân số từ người dùng
- Đầu ra: In ra phân số lớn nhất hoặc thông báo nếu bằng nhau
*/
int main() {
    PhanSo a, b;

    cout << "=== BAI 2: TIM PHAN SO LON NHAT ===" << endl;

    cout << "Nhap phan so thu nhat:\n";
    a.Nhap();

    cout << "Nhap phan so thu hai:\n";
    b.Nhap();

    int kq = a.SoSanh(b); // so sánh 2 phân số

    if (kq == 1) {
        cout << "Phan so lon nhat la: ";
        a.Xuat();
    } 
    else if (kq == -1) {
        cout << "Phan so lon nhat la: ";
        b.Xuat();
    } 
    else {
        cout << "Hai phan so bang nhau" << endl;
    }

    return 0;
}
