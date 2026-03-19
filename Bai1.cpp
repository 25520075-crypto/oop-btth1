#include <iostream>
using namespace std;

class PhanSo {
private:
    int iTu, iMau;

public:
    // Nhập phân số
    void Nhap() {
        cout << "Nhap tu: ";
        cin >> iTu;
        cout << "Nhap mau: ";
        cin >> iMau;

        // kiểm tra mẫu khác 0
        while (iMau == 0) {
            cout << "Mau phai khac 0. Nhap lai: ";
            cin >> iMau;
        }
    }

    // Xuất phân số
    void Xuat() {
        cout << iTu << "/" << iMau << endl;
    }

    // Tìm UCLN (thuật toán Euclid)
    int UCLN(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    // Rút gọn phân số
    void RutGon() {
        int g = UCLN(iTu, iMau);
        iTu /= g;
        iMau /= g;

        // đảm bảo mẫu luôn dương
        if (iMau < 0) {
            iTu = -iTu;
            iMau = -iMau;
        }
    }
};

int main() {
    PhanSo ps;

    cout << "=== BAI 1: RUT GON PHAN SO ===" << endl;

    ps.Nhap();
    ps.RutGon();

    cout << "Phan so sau khi rut gon: ";
    ps.Xuat();

    return 0;
}
