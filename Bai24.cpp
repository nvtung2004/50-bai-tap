#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
#include<limits>

using namespace std;

class KhachHang{ //checked
	private:
		int maKH;
		string tenKH;
		int sdt;
		float tongTienThanhToan;
	
	public:
		void nhapThongTinKhachHang(){
			cout<<"Nhap ma khach hang: ";			cin>>this->maKH;
			cout<<"Nhap ten khach hang: ";			cin.ignore();	getline(cin, this->tenKH);
			cout<<"Nhap so dien thoai: ";			cin>>this->sdt;
			cout<<"Nhap tong tien thanh toan: ";	cin>>this->tongTienThanhToan;
		}
		void xuatThongTinKhachHang() const{
			cout<<setw(15)<<left<<this->maKH
				<<setw(20)<<left<<this->tenKH
				<<setw(15)<<left<<this->sdt
				<<setw(20)<<left<<this->tongTienThanhToan<<endl;
		}
		float getTongTienThanhToan() const{
			return this->tongTienThanhToan;
		}
};

class DanhSachKhachHang{
	private:
		KhachHang* list;
	public:
		DanhSachKhachHang(int n){
			list = new KhachHang[n];
		}
		~DanhSachKhachHang(){
			delete[] list;
		}
		void nhapDanhSachKhachHang(int n){
			for(int i = 0; i < n; i++){
				list[i].nhapThongTinKhachHang();
			}
		}
		void xuatDanhSachKhachHang(int n) const{
			cout<<setw(15)<<left<<"Ma khach hang"
				<<setw(20)<<left<<"Ten khach hang"
				<<setw(15)<<left<<"So dien thoai"
				<<setw(20)<<left<<"Tong tien thanh toan"<<endl;
			for(int i = 0; i < n; i++){
				list[i].xuatThongTinKhachHang();
			}
		}
		//pp sx doi cho truc tiep
		void interchangeSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = i+1; j<n; j++){
					if(list[i].getTongTienThanhToan()>list[j].getTongTienThanhToan()){
						swap(list[i], list[j]);
					}
				}
			}
		}
		//pp sx chon truc tiep
		void selectionSort(int n){
			for(int i = 0; i < n-1; i++){
				int tmp = i;
				for(int j = i+1; j<n; j++){
					if(list[tmp].getTongTienThanhToan() > list[j].getTongTienThanhToan()){
						tmp = j;
					}
				}
				if(tmp != i){
					swap(list[i] , list[tmp]);
				}
			}
		}
		//pp sx chen truc tiep
		void insertionSort(int n){
			for(int i = 1; i < n; i++){
				KhachHang tmp = list[i];
				int pos = i-1;
				while(pos >= 0 && tmp.getTongTienThanhToan() < list[pos].getTongTienThanhToan()){
					list[pos+1] = list[pos];
					pos-=1;
				}
				list[pos+1] = tmp;
			}
		}
		//pp sx noi bot
		void bubbleSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = n-1; j > i; j--){
					if(list[j-1].getTongTienThanhToan() > list[j].getTongTienThanhToan()){
						swap(list[j-1], list[j]); 
					} 
				}
			}
		}
		//pp sx nhanh
		int partition(int low, int high){
			int pivot = high;
			int i = low-1;
			for(int j = low; j < high; j++){
				if(list[j].getTongTienThanhToan() < list[pivot].getTongTienThanhToan()){
					i += 1;
					swap(list[i], list[j]);
				}
			}
			swap(list[i+1], list[pivot]);
			return i+1;
		}
		void quickSort(int low, int high){
			if(low<high){
				int x = partition(low, high);
				quickSort(low, x-1);
				quickSort(x+1, high);
			}
		}	
};

int isValid(){ //checked
	int n;
	while(true){
		try{
			cin>>n;
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
			cout<<ex.what()<<endl;
		}
	}
	return n;
}
int main(){
	int n;
	cout<<"Nhap n: ";
	n = isValid();
	DanhSachKhachHang*  list = new DanhSachKhachHang(n);
	list->nhapDanhSachKhachHang(n);
	list->xuatDanhSachKhachHang(n);
	cout<<"Sap xep danh sach khach hang tang dan theo tong tien thanh toan: "<<endl;
	//list->interchangeSort(n);
	//list->selectionSort(n);
	//list->insertionSort(n);
	//list->bubbleSort(n);
	list->quickSort(0, n-1);
	list->xuatDanhSachKhachHang(n);
	return 0;
}
