#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int iNgay, iThang, iNam;

public:
    void Nhap();
    void Xuat();
    bool NamNhuan(int iNam);
    void NgayThangNamTiepTheo();
};

// ===== CÀI ĐẶT =====

void NgayThangNam::Nhap() {
    cout << "Nhap ngay thang nam: ";
    cin >> iNgay >> iThang >> iNam;
}

void NgayThangNam::Xuat() {
    cout << iNgay << "/" << iThang << "/" << iNam << endl;
}

bool NgayThangNam::NamNhuan(int iNam) {
    return (iNam % 4 == 0 && iNam % 100 != 0) || (iNam % 400 == 0);
}

void NgayThangNam::NgayThangNamTiepTheo() {

    if ((iNgay == 31) &&
       (iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7 ||
        iThang == 8 || iThang == 10 || iThang == 12)) {
        iNgay = 1;
        iThang++;

        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
    else if ((iNgay == 30) &&
            (iThang == 4 || iThang == 6 || iThang == 9 || iThang == 11)) {

        iNgay = 1;
        iThang++;
    }
    else if (iNgay == 28 && iThang == 2 && !NamNhuan(iNam)) {
        iNgay = 1;
        iThang++;
    }

    else if (iNgay == 28 && iThang == 2 && NamNhuan(iNam)) {
        iNgay = 29;
    }

    else if (iNgay == 29 && iThang == 2 && NamNhuan(iNam)) {
        iNgay = 1;
        iThang++;
    }
    else {
        iNgay++;
    }
}

// ===== MAIN =====

int main() {
    NgayThangNam a;

    a.Nhap();

    cout << "Ngay ke tiep la: ";
    a.NgayThangNamTiepTheo();
    a.Xuat();

    return 0;
}
