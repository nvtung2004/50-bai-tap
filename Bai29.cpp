#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <limits>

using namespace std;

class VanDongVien {
    private:
        int maVdv;
        string tenVdv;
        int tuoi;
        float luong;
    public:
        void nhapThongTinVdv() {
            cout << "Nhap ma van dong vien: ";
            cin >> this->maVdv;
            cout << "Nhap ten van dong vien: ";
            cin.ignore();
            getline(cin, this->tenVdv);
            cout << "Nhap tuoi: ";
            cin >> this->tuoi;
            cout << "Nhap luong (trieu dong): ";
            cin >> this->luong;
        }
        void xuatThongTinVdv() const {
            cout << setw(15) << left << this->maVdv
                 << setw(30) << left << this->tenVdv
                 << setw(10) << left << this->tuoi
                 << setw(15) << left << this->luong << endl;
        }
        float getLuong() const {
            return this->luong;
        }
};

class DanhSachVdv {
    private:
        VanDongVien* list;
    public:
        DanhSachVdv(int n) {
            list = new VanDongVien[n];
        }
        ~DanhSachVdv() {
            delete[] list;
        }
        void nhapDanhSach(int n) {
            for (int i = 0; i < n; i++) {
                cout << "Nhap thong tin van dong vien thu " << i + 1 << ":" << endl;
                list[i].nhapThongTinVdv();
            }
        }
        void xuatDanhSach(int n) const {
            cout << setw(15) << left << "Ma VDV"
                 << setw(30) << left << "Ten VDV"
                 << setw(10) << left << "Tuoi"
                 << setw(15) << left << "Luong" << endl;
            for (int i = 0; i < n; i++) {
                list[i].xuatThongTinVdv();
            }
        }
		//pp sx doi cho truc tiep
		void interchangeSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = i+1; j < n; j++){
					if(list[i].getLuong() > list[j].getLuong()){
						swap(list[i], list[j]);
					}
				}
			}
		}
		//pp sx chon truc tiep
		void selectionSort(int n){
			for(int i = 0; i < n-1; i++){
				int tmp = i;
				for(int j = i+1; j < n; j++){
					if(list[tmp].getLuong() > list[j].getLuong()){
						tmp = j;
					}
				}
				if(tmp != i){
					swap(list[i], list[tmp]);
				}
			}
		}
		//pp sx chen truc tiep
		void insertionSort(int n){
			for(int i = 1; i < n; i++){
				VanDongVien tmp = list[i];
				int pos = i-1;
				while(pos>=0 && tmp.getLuong() < list[pos].getLuong()){
					list[pos+1] = list[pos];
					pos-=1;
				}
				list[pos+1] = tmp;
			}
		}
		//pp sx noi bot
		void bubbleSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = n-1; j>i; j--){
					if(list[j].getLuong() < list[j-1].getLuong()){
						swap(list[j], list[j-1]);
					}
				}
			}
		}
		//pp sx nhanh
		int partition(int low, int high){
			int pivot = high;
			int i = low-1;
			for(int j = low; j < high; j++){
				if(list[j].getLuong() < list[pivot].getLuong()){
					i+=1;
					swap(list[i], list[j]);
				}
			}
			swap(list[i+1], list[pivot]);
			return i+1;
		}
		void quickSort(int low, int high){
			if(low < high){
				int x = partition(low, high);
				quickSort(low, x-1);
				quickSort(x+1, high);
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
    cout << "Nhap so luong van dong vien: ";
    n = isValid();
    DanhSachVdv* danhSach = new DanhSachVdv(n);
    danhSach->nhapDanhSach(n);
    cout << "\nDanh sach van dong vien vua nhap:" << endl;
    danhSach->xuatDanhSach(n);

    cout << "\nSap xep danh sach van dong vien theo luong tang dan:" << endl;
    danhSach->selectionSort(n);
    danhSach->xuatDanhSach(n);

    delete danhSach;
    return 0;
}

