#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
#include<limits>

using namespace std;
class SinhVien{
	private:	
		int maSV;
		string tenSV, lop;
		float diemTongKet;
	
	public:
		void nhapThongTin(){
			cout<<"Nhap ma sinh vien: ";	cin>>this->maSV;
			cout<<"Nhap ten sinh vien: ";	cin.ignore(numeric_limits<streamsize>::max(), '\n');	getline(cin, this->tenSV);
			cout<<"Nhap lop: ";				getline(cin, this->lop);
			cout<<"Nhap diem tong ket: ";	cin>>this->diemTongKet;
		}
		
		void hienThi(){
			cout<<setw(20)<<left<<this->maSV
				<<setw(20)<<left<<this->tenSV
				<<setw(10)<<left<<this->lop
				<<setw(20)<<left<<this->diemTongKet<<endl;
		}
		
		float getDiemTongKet(){
			return this->diemTongKet;
		}
};

class MangSinhVien{
	private:
		SinhVien* arr;
	
	public:
		MangSinhVien(int n){
			arr = new SinhVien[n];
		}
		
		void nhapMang(int n){
			for(int i = 0; i < n; i++){
				arr[i].nhapThongTin();
			}
		}
		void hienThiMang(int n){
			cout<<setw(20)<<left<<"Ma sinh vien"
				<<setw(20)<<left<<"Ten sinh vien"
				<<setw(10)<<left<<"Lop"
				<<setw(20)<<left<<"Diem tong ket"<<endl;
			for(int i = 0; i < n; i++){
				arr[i].hienThi();
			}
		}
		
		//sx doi cho truc tiep
		void interchangeSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = i+1; j < n; j++){
					if(arr[i].getDiemTongKet()>arr[j].getDiemTongKet()){
						swap(arr[i], arr[j]);
					}
				}
			}
		}
		//sx chon truc tiep
		void selectionSort(int n){
			for(int i = 0; i < n-1; i++){
				int tmp = i;
				for(int j = i+1; j < n; j++){
					if(arr[tmp].getDiemTongKet()>arr[j].getDiemTongKet()){
						tmp = j;
					}
				}
				if(tmp != i){
					swap(arr[i], arr[tmp]);
				}
			}
		}
		
		//sx chen truc tiep
		void insertionSort(int n){
			for(int i = 1; i<n; i++){
				SinhVien tmp = arr[i];
				int pos = i-1;
				while(pos >= 0 && arr[pos].getDiemTongKet()>tmp.getDiemTongKet()){
					arr[pos+1] = arr[pos];
					pos -= 1;
				}
				arr[pos+1] = tmp;
			}
		}
		
		//sx noi bot
		void bubbleSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = n-1; j>i; j--){
					if(arr[j].getDiemTongKet() < arr[j-1].getDiemTongKet()){
						swap(arr[j], arr[j-1]);
					}
				}
			}
		}
		
		// sx quicksort
		int partition( int low, int high){
			int pivot = high; // gan pivot = final index
			int i = low - 1;
			for(int j = low; j < high; j++){
				if(arr[j].getDiemTongKet() < arr[pivot].getDiemTongKet()){
					i+=1;
					swap(arr[i], arr[j]);
			}
			}
			swap(arr[i+1], arr[pivot]);
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

// handle exception bien n
int isValid(){
	int n = 0;
	while(true){
		try{
			cout<<"Nhap gia tri n (n>0): ";
			cin>>n;
			if(cin.fail()){
				cin.clear(); // xoa trang thai errors, cho phep tiep tuc thao tac nhap
				cin.ignore(numeric_limits<streamsize>::max(), '\n');// xoa bo nho dem cua gia tri loi
				throw invalid_argument("Kieu du lieu khong hop le. Yeu cau nhap lai.");
			}
			if(n<=0){
				throw invalid_argument("Gia tri khong thoa man. Yeu cau nhap so nguyen duong.");
			}
			break;	
		}
		catch(const exception& ex){
			cout<<ex.what()<<endl;
		}	
	}
	return n;  
}

int main(){
	int n = isValid();
	MangSinhVien* arr = new MangSinhVien(n);
	
	cout<<"Nhap mang sinh vien: "<<endl;
	arr->nhapMang(n);
	cout<<"Hien thi mang vua nhap: "<<endl;
	arr->hienThiMang(n);
	//cout<<"Sap xep tang dan theo phuong phap interchange sort: "<<endl;
	//arr->interchangeSort(n);
	
	//cout<<"Sap xep tang dan theo phuong phap selection sort: "<<endl;
	//arr->selectionSort(n);
	
	//cout<<"Sap xep theo phuong phap insertion sort: "<<endl;
	//arr->insertionSort(n);
	
	//cout<<"Sap xep theo phuong phap bubble sort: "<<endl;
	//arr->bubbleSort(n);
	
	cout<<"Sap xep theo phuong phap quick sort: "<<endl;
	arr->quickSort(0, n-1);
	arr->hienThiMang( n);
	delete[] arr;
	return 0;
}
