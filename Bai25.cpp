#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
#include<limits>

using namespace std;

class Date{ //checked
	private:
		int ngay, thang, nam;
	public:
		void nhapNgay(){
			cout<<"Nhap ngay: ";	cin>>this->ngay;
			cout<<"Nhap thang: ";	cin>>this->thang;
			cout<<"Nhap nam: ";		cin>>this->nam;
		}
		string xuatNgay() const{
			return to_string(this->ngay)+"/"+to_string(this->thang)+"/"+to_string(this->nam);
		}
};
class NhanVien{ //checked
	private:
		int maNV;
		string hoTenNV;
		Date ngaySinh;
		float luong;
	public:
		void nhapThongTinNhanVien(){
			cout<<"Nhap ma nhan vien: ";		cin>>this->maNV;
			cout<<"Nhap ho ten nhan vien: ";	cin.ignore();	getline(cin, this->hoTenNV);
			this->ngaySinh.nhapNgay();
			cout<<"Nhap luong: ";				cin>>this->luong;
		}	
		void xuatThongTinNhanVien() const{
			cout<<setw(15)<<left<<this->maNV
				<<setw(20)<<left<<this->hoTenNV
				<<setw(15)<<left<<this->ngaySinh.xuatNgay()
				<<setw(15)<<left<<this->luong<<endl;
		}
		float getLuong() const{
			return this->luong;
		}
};

class DanhSachNhanVien{ // checked 
	private:
		NhanVien* list;
	public:
		DanhSachNhanVien(int n){
			list = new NhanVien[n];
		}
		~DanhSachNhanVien(){
			delete[] list;
		}
		void nhapDanhSach(int n){
			for(int i = 0; i < n; i++){
				list[i].nhapThongTinNhanVien();
			}
		}
		void xuatDanhSach(int n){
			cout<<setw(15)<<left<<"Ma nhan vien"
				<<setw(20)<<left<<"Ho ten"
				<<setw(15)<<left<<"Ngay sinh"
				<<setw(15)<<left<<"Luong(trieu)"<<endl;
			for(int i = 0; i<n; i++){
				list[i].xuatThongTinNhanVien();
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
				NhanVien tmp = list[i];
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

int isValid(){ // checked
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
	DanhSachNhanVien* list = new DanhSachNhanVien(n);
	list->nhapDanhSach(n);
	list->xuatDanhSach(n);
	cout<<"Sap xep danh sach nhan vien tang dan theo luong: "<<endl;
	//list->interchangeSort(n);
	//list->selectionSort(n);
	//list->insertionSort(n);
	//list->bubbleSort(n);
	list->quickSort(0, n-1); 
	list->xuatDanhSach(n);
	return 0;
}
