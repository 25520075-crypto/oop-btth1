#include <iostream>
using namespace std;

// Hàm tìm UCLN
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

class LopPhanSo {
private:
    int iTu, iMau;

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

void LopPhanSo::Nhap() {
    cout << "Nhap tu: ";
    cin >> iTu;
    do {
        cout << "Nhap mau (khac 0): ";
        cin >> iMau;
    } while (iMau == 0);
}

void LopPhanSo::Xuat() {
    cout << iTu << "/" << iMau << endl;
}

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

LopPhanSo LopPhanSo::Tong(const LopPhanSo& phanso) {
    LopPhanSo kq;
    kq.iTu = iTu * phanso.iMau + phanso.iTu * iMau;
    kq.iMau = iMau * phanso.iMau;
    kq.RutGon();
    return kq;
}

LopPhanSo LopPhanSo::Hieu(const LopPhanSo& phanso) {
    LopPhanSo kq;
    kq.iTu = iTu * phanso.iMau - phanso.iTu * iMau;
    kq.iMau = iMau * phanso.iMau;
    kq.RutGon();
    return kq;
}

LopPhanSo LopPhanSo::Tich(const LopPhanSo& phanso) {
    LopPhanSo kq;
    kq.iTu = iTu * phanso.iTu;
    kq.iMau = iMau * phanso.iMau;
    kq.RutGon();
    return kq;
}

LopPhanSo LopPhanSo::Thuong(const LopPhanSo& phanso) {
    LopPhanSo kq;
    kq.iTu = iTu * phanso.iMau;
    kq.iMau = iMau * phanso.iTu;
    kq.RutGon();
    return kq;
}

bool LopPhanSo::SoSanh(const LopPhanSo& phanso) {
    return (iTu * phanso.iMau == phanso.iTu * iMau);
}

// ================= MAIN =================

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
