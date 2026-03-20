#include <iostream>
#include <string>
using namespace std;

// Lớp HocSinh dùng để lưu trữ và xử lý thông tin học sinh
class HocSinh {
private:
    string hoTen;       // Họ tên học sinh
    float diemToan;     // Điểm môn Toán
    float diemVan;      // Điểm môn Văn

public:
    void Nhap();
    float TinhDiemTB();
    void Xuat();
};

/*
Hàm Nhap()
- Chức năng: Nhập thông tin học sinh từ bàn phím
- Đầu vào:
    + hoTen (string)
    + diemToan (float)
    + diemVan (float)
- Đầu ra: Không trả về (gán giá trị cho các thuộc tính)
- Lưu ý: dùng getline(cin >> ws, hoTen) để nhập chuỗi có khoảng trắng
*/
void HocSinh::Nhap() {
    cout << "Nhap ho ten: ";
    getline(cin >> ws, hoTen);

    cout << "Nhap diem Toan: ";
    cin >> diemToan;

    cout << "Nhap diem Van: ";
    cin >> diemVan;
}

/*
Hàm TinhDiemTB()
- Chức năng: Tính điểm trung bình của học sinh
- Công thức: (Toán + Văn) / 2
- Đầu vào: Không có (dùng dữ liệu trong lớp)
- Đầu ra:
    + Trả về giá trị float là điểm trung bình
*/
float HocSinh::TinhDiemTB() {
    return (diemToan + diemVan) / 2;
}

/*
Hàm Xuat()
- Chức năng: Hiển thị thông tin học sinh
- Đầu vào: Không có
- Đầu ra: Không trả về (in ra màn hình)
*/
void HocSinh::Xuat() {
    cout << "\nThong tin hoc sinh:\n";
    cout << "Ho ten: " << hoTen << endl;
    cout << "Diem Toan: " << diemToan << endl;
    cout << "Diem Van: " << diemVan << endl;
    cout << "Diem trung binh: " << TinhDiemTB() << endl;
}

/*
Hàm main()
- Chức năng: Chạy chương trình chính
- Đầu vào: Nhập thông tin 1 học sinh
- Đầu ra: In thông tin và điểm trung bình
*/
int main() {
    HocSinh hs;

    cout << "=== BAI 5: THONG TIN HOC SINH ===" << endl;

    hs.Nhap();  // Nhập dữ liệu
    hs.Xuat();  // Xuất dữ liệu

    return 0;
}
