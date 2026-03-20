#include <iostream>
using namespace std;

/*
Hàm UCLN(int a, int b)
- Chức năng: Tìm ước chung lớn nhất của 2 số nguyên
- Thuật toán: Euclid
- Đầu vào:
    + a, b: hai số nguyên
- Đầu ra:
    + Trả về UCLN của a và b
*/
int UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Lớp biểu diễn phân số
class LopPhanSo {
private:
    int iTu, iMau; // tử số và mẫu số

public:
    void Nhap();
    void Xuat();
    void RutGon();

    LopPhanSo Tong(const LopPhanSo& phanso);
    LopPhanSo Hieu(const LopPhanSo& phanso);
    LopPhanSo Tich(const LopPhanSo& phanso);
    LopPhanSo Thuong(const LopPhanSo& phanso);
    bool SoSanh(const LopPhanSo& phanso);
};

// ================= CÀI ĐẶT =================

/*
Hàm Nhap()
- Chức năng: Nhập phân số từ bàn phím
- Đầu vào: Không có (dùng cin)
- Đầu ra: Không trả về (gán giá trị cho iTu, iMau)
- Lưu ý: Mẫu số phải khác 0
*/
void LopPhanSo::Nhap() {
    cout << "Nhap tu: ";
    cin >> iTu;

    do {
        cout << "Nhap mau (khac 0): ";
        cin >> iMau;
    } while (iMau == 0);
}

/*
Hàm Xuat()
- Chức năng: Xuất phân số ra màn hình
- Đầu vào: Không có
- Đầu ra: Không trả về (in dạng a/b)
*/
void LopPhanSo::Xuat() {
    cout << iTu << "/" << iMau << endl;
}

/*
Hàm RutGon()
- Chức năng: Rút gọn phân số về tối giản
- Đầu vào: Không có (dùng iTu, iMau)
- Đầu ra: Không trả về (cập nhật lại phân số)
*/
void LopPhanSo::RutGon() {
    int g = UCLN(iTu, iMau);

    iTu /= g;
    iMau /= g;

    // Đưa dấu về tử
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

/*
Hàm Tong()
- Chức năng: Tính tổng 2 phân số
- Đầu vào:
    + phanso: phân số thứ hai
- Đầu ra:
    + Trả về phân số kết quả
*/
LopPhanSo LopPhanSo::Tong(const LopPhanSo& phanso) {
    LopPhanSo kq;

    kq.iTu = iTu * phanso.iMau + phanso.iTu * iMau;
    kq.iMau = iMau * phanso.iMau;

    kq.RutGon();
    return kq;
}

/*
Hàm Hieu()
- Chức năng: Tính hiệu 2 phân số
- Đầu vào:
    + phanso: phân số thứ hai
- Đầu ra:
    + Trả về phân số kết quả
*/
LopPhanSo LopPhanSo::Hieu(const LopPhanSo& phanso) {
    LopPhanSo kq;

    kq.iTu = iTu * phanso.iMau - phanso.iTu * iMau;
    kq.iMau = iMau * phanso.iMau;

    kq.RutGon();
    return kq;
}

/*
Hàm Tich()
- Chức năng: Tính tích 2 phân số
- Đầu vào:
    + phanso: phân số thứ hai
- Đầu ra:
    + Trả về phân số kết quả
*/
LopPhanSo LopPhanSo::Tich(const LopPhanSo& phanso) {
    LopPhanSo kq;

    kq.iTu = iTu * phanso.iTu;
    kq.iMau = iMau * phanso.iMau;

    kq.RutGon();
    return kq;
}

/*
Hàm Thuong()
- Chức năng: Tính thương 2 phân số
- Đầu vào:
    + phanso: phân số thứ hai
- Đầu ra:
    + Trả về phân số kết quả
- Lưu ý: Không kiểm tra chia cho 0 (có thể bổ sung)
*/
LopPhanSo LopPhanSo::Thuong(const LopPhanSo& phanso) {
    LopPhanSo kq;

    kq.iTu = iTu * phanso.iMau;
    kq.iMau = iMau * phanso.iTu;

    kq.RutGon();
    return kq;
}

/*
Hàm SoSanh()
- Chức năng: Kiểm tra 2 phân số có bằng nhau không
- Phương pháp: Nhân chéo
- Đầu vào:
    + phanso: phân số cần so sánh
- Đầu ra:
    + true  nếu bằng nhau
    + false nếu khác nhau
*/
bool LopPhanSo::SoSanh(const LopPhanSo& phanso) {
    return (iTu * phanso.iMau == phanso.iTu * iMau);
}

// ================= MAIN =================

/*
Hàm main()
- Chức năng: Chạy chương trình chính
- Đầu vào: Nhập 2 phân số
- Đầu ra:
    + In tổng, hiệu, tích, thương
    + Kiểm tra 2 phân số có bằng nhau không
*/
int main() {
    LopPhanSo a, b;

    cout << "Nhap phan so thu nhat:\n";
    a.Nhap();

    cout << "Nhap phan so thu hai:\n";
    b.Nhap();

    cout << "\nTong: ";
    a.Tong(b).Xuat();

    cout << "Hieu: ";
    a.Hieu(b).Xuat();

    cout << "Tich: ";
    a.Tich(b).Xuat();

    cout << "Thuong: ";
    a.Thuong(b).Xuat();

    if (a.SoSanh(b))
        cout << "Hai phan so bang nhau\n";
    else
        cout << "Hai phan so khong bang nhau\n";

    return 0;
}
