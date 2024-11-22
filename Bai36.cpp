#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
#include<limits>

using namespace std;

class VeMayBay{ //checked
	private:
		int maVe;
		string khoiHanh;
		string den;
		float giaVe;
	
	public:
		void nhapThongTinVe(){
			cout << "Nhap ma ve: ";              cin >> this->maVe;
			cout << "Nhap khoi hanh: ";         cin.ignore(); getline(cin, this->khoiHanh);
			cout << "Nhap den: ";                getline(cin, this->den);
			cout << "Nhap gia ve: ";             cin >> this->giaVe;
		}
		void xuatThongTinVe() const{
			cout << setw(15) << left << this->maVe
				<< setw(20) << left << this->khoiHanh
				<< setw(20) << left << this->den
				<< setw(15) << left << this->giaVe << endl;
		}
		float getGiaVe() const{
			return this->giaVe;
		}
};

class DanhSachVe{
	private:
		VeMayBay* list;
	public:
		DanhSachVe(int n){
			list = new VeMayBay[n];
		}
		~DanhSachVe(){
			delete[] list;
		}
		void nhapDanhSachVe(int n){
			for(int i = 0; i < n; i++){
				list[i].nhapThongTinVe();
			}
		}
		void xuatDanhSachVe(int n) const{
			cout << setw(15) << left << "Ma ve"
				<< setw(20) << left << "Khoi hanh"
				<< setw(20) << left << "Den"
				<< setw(15) << left << "Gia ve" << endl;
			for(int i = 0; i < n; i++){
				list[i].xuatThongTinVe();
			}
		}
		void bubbleSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = n-1; j > i; j--){
					if(list[j-1].getGiaVe() > list[j].getGiaVe()){
						swap(list[j-1], list[j]);
					} 
				}
			}
		}

};

int isValid(){ //checked
	int n;
	while(true){
		try{
			cin >> n;
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Kieu du lieu khong hop le. Yeu cau nhap lai.");
			}
			if(n <= 0){
				throw invalid_argument("Vui long nhap so nguyen duong. Yeu cau nhap lai.");
			}
			break;
		} catch(const exception& ex){
			cout << ex.what() << endl;
		}
	}
	return n;
}

int main(){
	int n;
	cout << "Nhap n: ";
	n = isValid();
	DanhSachVe* list = new DanhSachVe(n);
	list->nhapDanhSachVe(n);
	cout << "Danh sach ve may bay vua nhap: " << endl;
	list->xuatDanhSachVe(n);
	
	list->bubbleSort(n);
	cout << "Danh sach ve may bay sau khi sap xep theo gia ve: " << endl;
	list->xuatDanhSachVe(n);
	
	delete list; 
	return 0;
}

