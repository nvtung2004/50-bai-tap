#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <limits>

using namespace std;

class VanDongVien { //checked
	private:
	    int maVDV;
	    string tenVDV;
	    int tuoi;
	    float luong;
	
	public:
	    void nhapThongTinVanDongVien() {
	        cout << "Nhap ma van dong vien: ";        cin >> this->maVDV;
	        cout << "Nhap ten van dong vien: ";       cin.ignore(); getline(cin, this->tenVDV);
	        cout << "Nhap tuoi: ";                     cin >> this->tuoi;
	        cout << "Nhap luong (trieu dong): ";      cin >> this->luong;
	    }
	    
	    void xuatThongTinVanDongVien() const {
	        cout << setw(15) << left << this->maVDV
	             << setw(20) << left << this->tenVDV
	             << setw(10) << left << this->tuoi
	             << setw(15) << left << this->luong << endl;
	    }
	    
	    float getLuong() const {
	        return this->luong;
	    }
};

class DanhSachVanDongVien {
	private:
	    VanDongVien* list;
	
	public:
	    DanhSachVanDongVien(int n) {
	        list = new VanDongVien[n];
	    }
	    
	    ~DanhSachVanDongVien() {
	        delete[] list;
	    }
	    
	    void nhapDanhSachVanDongVien(int n) {
	        for (int i = 0; i < n; i++) {
	            list[i].nhapThongTinVanDongVien();
	        }
	    }
	    
	    void xuatDanhSachVanDongVien(int n) const {
	        cout << setw(15) << left << "Ma VDV"
	             << setw(20) << left << "Ten VDV"
	             << setw(10) << left << "Tuoi"
	             << setw(15) << left << "Luong" << endl;
	        for (int i = 0; i < n; i++) {
	            list[i].xuatThongTinVanDongVien();
	        }
	    }
	    
	    void bubbleSort(int n) {
	        for (int i = 0; i < n - 1; i++) {
	            for (int j = n - 1; j > i; j--) {
	                if (list[j - 1].getLuong() > list[j].getLuong()) {
	                    swap(list[j - 1], list[j]);
	                }
	            }
	        }
	    }
    
};

int isValid() { //checked
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
    cout << "Nhap n: ";
    n = isValid();
    
    DanhSachVanDongVien* list = new DanhSachVanDongVien(n);
    list->nhapDanhSachVanDongVien(n);
    cout << "Danh sach van dong vien vua nhap: " << endl;
    list->xuatDanhSachVanDongVien(n);
    
    list->bubbleSort(n);
    cout << "Danh sach van dong vien sau khi sap xep theo luong: " << endl;
    list->xuatDanhSachVanDongVien(n);
    
    
    delete list; 
    return 0;
}

