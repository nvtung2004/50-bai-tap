#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <limits>

using namespace std;

class HangHoa {
    private:
        int maHH;
        string tenHH;
        string ngayXuat;
        float giaXuat;
    public:
        void nhapThongTinHangHoa() {
            cout << "Nhap ma hang hoa: ";
            cin >> this->maHH;
            cout << "Nhap ten hang hoa: ";
            cin.ignore();
            getline(cin, this->tenHH);
            cout << "Nhap ngay xuat hang (dd/mm/yyyy): ";
            getline(cin, this->ngayXuat);
            cout << "Nhap gia xuat hang (trieu dong): ";
            cin >> this->giaXuat;
        }
        void xuatThongTinHangHoa() const {
            cout << setw(15) << left << this->maHH
                 << setw(30) << left << this->tenHH
                 << setw(15) << left << this->ngayXuat
                 << setw(10) << left << this->giaXuat << endl;
        }
        float getGiaXuat() const {
            return this->giaXuat;
        }
};

class DanhSachHangHoa {
    private:
        HangHoa* list;
    public:
        DanhSachHangHoa(int n) {
            list = new HangHoa[n];
        }
        ~DanhSachHangHoa() {
            delete[] list;
        }
        void nhapDanhSach(int n) {
            for (int i = 0; i < n; i++) {
                cout << "Nhap thong tin hang hoa thu " << i + 1 << ":" << endl;
                list[i].nhapThongTinHangHoa();
            }
        }
        void xuatDanhSach(int n) const {
            cout << setw(15) << left << "Ma HH"
                 << setw(30) << left << "Ten HH"
                 << setw(15) << left << "Ngay Xuat"
                 << setw(10) << left << "Gia Xuat" << endl;
            for (int i = 0; i < n; i++) {
                list[i].xuatThongTinHangHoa();
            }
        }
        // Phuong phap sap xep noi bot (Bubble sort) theo gia xuat
        void bubbleSort(int n) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = n - 1; j > i; j--) {
                    if (list[j].getGiaXuat() < list[j - 1].getGiaXuat()) {
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
    cout << "Nhap so luong hang hoa: ";
    n = isValid();
    DanhSachHangHoa* danhSach = new DanhSachHangHoa(n);
    danhSach->nhapDanhSach(n);
    
    cout << "\nDanh sach hang hoa vua nhap:" << endl;
    danhSach->xuatDanhSach(n);

    cout << "\nSap xep danh sach hang hoa theo gia xuat tang dan:" << endl;
    danhSach->bubbleSort(n);
    danhSach->xuatDanhSach(n);

    delete danhSach;
    return 0;
}

