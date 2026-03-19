#include <iostream>
using namespace std;

class PhanSo {
private:
    int iTu, iMau;

public:
    void Nhap() {
        cout << "Nhap tu: ";
        cin >> iTu;
        cout << "Nhap mau: ";
        cin >> iMau;

        while (iMau == 0) {
            cout << "Mau phai khac 0. Nhap lai: ";
            cin >> iMau;
        }
    }

    void Xuat() {
        cout << iTu << "/" << iMau << endl;
    }

    // So sánh bằng nhân chéo
    int SoSanh(PhanSo ps) {
        int a = iTu * ps.iMau;
        int b = ps.iTu * iMau;

        if (a > b) return 1;
        if (a == b) return 0;
        return -1;
    }
};

int main() {
    PhanSo a, b;

    cout << "=== BAI 2: TIM PHAN SO LON NHAT ===" << endl;

    cout << "Nhap phan so thu nhat:\n";
    a.Nhap();

    cout << "Nhap phan so thu hai:\n";
    b.Nhap();

    int kq = a.SoSanh(b);

    if (kq == 1) {
        cout << "Phan so lon nhat la: ";
        a.Xuat();
    } else if (kq == -1) {
        cout << "Phan so lon nhat la: ";
        b.Xuat();
    } else {
        cout << "Hai phan so bang nhau" << endl;
    }

    return 0;
}
