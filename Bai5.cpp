#include <iostream>
#include <string>
using namespace std;

class HocSinh {
private:
    string hoTen;
    float diemToan, diemVan;

public:
    void Nhap() {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen);

        cout << "Nhap diem Toan: ";
        cin >> diemToan;

        cout << "Nhap diem Van: ";
        cin >> diemVan;
    }

    float TinhDiemTB() {
        return (diemToan + diemVan) / 2;
    }

    void Xuat() {
        cout << "\nThong tin hoc sinh:\n";
        cout << "Ho ten: " << hoTen << endl;
        cout << "Diem Toan: " << diemToan << endl;
        cout << "Diem Van: " << diemVan << endl;
        cout << "Diem trung binh: " << TinhDiemTB() << endl;
    }
};

int main() {
    HocSinh hs;

    cout << "=== BAI 5: THONG TIN HOC SINH ===" << endl;

    hs.Nhap();
    hs.Xuat();

    return 0;
}

