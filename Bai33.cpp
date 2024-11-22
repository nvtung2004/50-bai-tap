#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <limits>

using namespace std;

class KhachHang {
    private:
        int maKH;
        string tenKH;
        string soDienThoai;
        float tongTienThanhToan;
    public:
        void nhapThongTinKhachHang() {
            cout << "Nhap ma khach hang: ";
            cin >> this->maKH;
            cout << "Nhap ten khach hang: ";
            cin.ignore();
            getline(cin, this->tenKH);
            cout << "Nhap so dien thoai: ";
            getline(cin, this->soDienThoai);
            cout << "Nhap tong tien thanh toan: ";
            cin >> this->tongTienThanhToan;
        }
        void xuatThongTinKhachHang() const {
            cout << setw(15) << left << this->maKH
                 << setw(30) << left << this->tenKH
                 << setw(20) << left << this->soDienThoai
                 << setw(15) << left << this->tongTienThanhToan << endl;
        }
        float getTongTienThanhToan() const {
            return this->tongTienThanhToan;
        }
};

class DanhSachKhachHang {
    private:
        KhachHang* list;
    public:
        DanhSachKhachHang(int n) {
            list = new KhachHang[n];
        }
        ~DanhSachKhachHang() {
            delete[] list;
        }
        void nhapDanhSach(int n) {
            for (int i = 0; i < n; i++) {
                cout << "Nhap thong tin khach hang thu " << i + 1 << ":" << endl;
                list[i].nhapThongTinKhachHang();
            }
        }
        void xuatDanhSach(int n) const {
            cout << setw(15) << left << "Ma KH"
                 << setw(30) << left << "Ten KH"
                 << setw(20) << left << "So Dien Thoai"
                 << setw(15) << left << "Tong Tien" << endl;
            for (int i = 0; i < n; i++) {
                list[i].xuatThongTinKhachHang();
            }
        }
        // Phuong phap sap xep noi bot (Bubble sort) theo tong tien thanh toan
        void bubbleSort(int n) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = n - 1; j > i; j--) {
                    if (list[j].getTongTienThanhToan() < list[j - 1].getTongTienThanhToan()) {
                        swap(list[j], list[j - 1]);
                    }
                }
            }
        }
};

int isValid() {
    int n;
    while (true) {
        try {
            cin >> n;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Kieu du lieu khong hop le. Yeu cau nhap lai.");
            }
            if (n <= 0) {
                throw invalid_argument("Vui long nhap so nguyen duong. Yeu cau nhap lai.");
            }
            break;
        } catch (const exception& ex) {
            cout << ex.what() << endl;
        }
    }
    return n;
}

int main() {
    int n;
    cout << "Nhap so luong khach hang: ";
    n = isValid();
    DanhSachKhachHang* danhSach = new DanhSachKhachHang(n);
    danhSach->nhapDanhSach(n);
    
    cout << "\nDanh sach khach hang vua nhap:" << endl;
    danhSach->xuatDanhSach(n);

    cout << "\nSap xep danh sach khach hang theo tong tien thanh toan tang dan:" << endl;
    danhSach->bubbleSort(n);
    danhSach->xuatDanhSach(n);

    delete danhSach;
    return 0;
}

