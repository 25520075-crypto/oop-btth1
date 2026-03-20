#include <iostream>
using namespace std;

// Lớp biểu diễn ngày tháng năm
class NgayThangNam {
private:
    int iNgay, iThang, iNam; // ngày, tháng, năm

public:
    void Nhap();
    void Xuat();
    bool NamNhuan(int iNam);
    void NgayThangNamTiepTheo();
};

// ===== CÀI ĐẶT =====

/*
Hàm Nhap()
- Chức năng: Nhập ngày, tháng, năm từ bàn phím
- Đầu vào: 3 số nguyên (ngày, tháng, năm) từ cin
- Đầu ra: Không trả về (gán giá trị cho iNgay, iThang, iNam)
*/
void NgayThangNam::Nhap() {
    cout << "Nhap ngay thang nam: ";
    cin >> iNgay >> iThang >> iNam;
}

/*
Hàm Xuat()
- Chức năng: Xuất ngày tháng năm ra màn hình
- Đầu vào: Không có
- Đầu ra: Không trả về (in dạng dd/mm/yyyy)
*/
void NgayThangNam::Xuat() {
    cout << iNgay << "/" << iThang << "/" << iNam << endl;
}

/*
Hàm NamNhuan(int iNam)
- Chức năng: Kiểm tra một năm có phải năm nhuận hay không
- Đầu vào:
    + iNam: năm cần kiểm tra
- Đầu ra:
    + true  nếu là năm nhuận
    + false nếu không phải
- Quy tắc:
    + Chia hết cho 4 và không chia hết cho 100
    + Hoặc chia hết cho 400
*/
bool NgayThangNam::NamNhuan(int iNam) {
    return (iNam % 4 == 0 && iNam % 100 != 0) || (iNam % 400 == 0);
}

/*
Hàm NgayThangNamTiepTheo()
- Chức năng: Tính ngày kế tiếp của ngày hiện tại
- Đầu vào: Không có (dùng iNgay, iThang, iNam)
- Đầu ra: Không trả về (cập nhật lại ngày tháng năm)

- Xử lý:
    + Các tháng có 31 ngày
    + Các tháng có 30 ngày
    + Tháng 2 (28 hoặc 29 ngày tùy năm nhuận)
    + Chuyển tháng và năm khi cần
*/
void NgayThangNam::NgayThangNamTiepTheo() {

    // Trường hợp tháng có 31 ngày
    if ((iNgay == 31) &&
       (iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7 ||
        iThang == 8 || iThang == 10 || iThang == 12)) {

        iNgay = 1;
        iThang++;

        // Nếu vượt quá tháng 12 → sang năm mới
        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }

    // Trường hợp tháng có 30 ngày
    else if ((iNgay == 30) &&
            (iThang == 4 || iThang == 6 || iThang == 9 || iThang == 11)) {

        iNgay = 1;
        iThang++;
    }

    // Tháng 2 - năm không nhuận (28 ngày)
    else if (iNgay == 28 && iThang == 2 && !NamNhuan(iNam)) {
        iNgay = 1;
        iThang++;
    }

    // Tháng 2 - năm nhuận (28 -> 29)
    else if (iNgay == 28 && iThang == 2 && NamNhuan(iNam)) {
        iNgay = 29;
    }

    // Tháng 2 - ngày 29 năm nhuận
    else if (iNgay == 29 && iThang == 2 && NamNhuan(iNam)) {
        iNgay = 1;
        iThang++;
    }

    // Các trường hợp còn lại: tăng ngày bình thường
    else {
        iNgay++;
    }
}

// ===== MAIN =====

/*
Hàm main()
- Chức năng: Chạy chương trình chính
- Đầu vào: Nhập ngày tháng năm
- Đầu ra: In ra ngày kế tiếp
*/
int main() {
    NgayThangNam a;

    a.Nhap();

    cout << "Ngay ke tiep la: ";
    a.NgayThangNamTiepTheo();
    a.Xuat();

    return 0;
}
