#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
struct KhachHang{
	int maKH;
	string tenKH, soDT;
	float tongTienThanhToan;
};

void nhapThongTin(KhachHang* kh){
	cout<<"Nhap ma khach hang: ";			cin>>kh->maKH;
	cout<<"Nhap ten khach hang: ";			cin.ignore();	getline(cin, kh->tenKH);
	cout<<"Nhap so dien thoai: ";			getline(cin, kh->soDT);
	cout<<"Nhap tong tien thanh toan: ";	cin>>kh->tongTienThanhToan;
}

KhachHang* nhapMang(int n){
	KhachHang* array = new KhachHang[n];
	if(array == NULL){
		return NULL;
	}
	else{
		cout<<"Nhap thong tin: "<<endl;
		for(int i = 0; i < n; i++){
			cout<<"Nhap thong tin khach hang thu "<<i+1<<endl;
			nhapThongTin(&array[i]);
		}
		return array;
	}
}

void xuatThongTin(KhachHang* kh){
	cout<<setw(30)<<left<<kh->maKH
		<<setw(30)<<left<<kh->tenKH
		<<setw(20)<<left<<kh->soDT
		<<setw(20)<<left<<kh->tongTienThanhToan<<endl;
}

void xuatMang(KhachHang* array, int n){
	cout<<"Xuat thong tin: "<<endl;
	cout<<setw(30)<<left<<"Ma KH"
		<<setw(30)<<left<<"Ten KH"
		<<setw(20)<<left<<"SDT"
		<<setw(20)<<left<<"Tong tien thanh toan"<<endl;
	for(int i = 0; i < n; i++){
		xuatThongTin(&array[i]);
	}
}

// Đổi chỗ trực tiếp
void interchangeSort_tongTienThanhToan(KhachHang* arr, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(arr[i].tongTienThanhToan > arr[j].tongTienThanhToan){
				swap(arr[i], arr[j]);
			}
		}
	}
}

// chọn trực tiếp
void selectionSort_tongTienThanhToan(KhachHang* arr, int n){
	for(int i = 0; i < n-1; i++){
		int tmp = i;
		for(int j = 1+1; j<n; j++){
			if(arr[tmp].tongTienThanhToan>arr[j].tongTienThanhToan){
				tmp = j;
			}
		}
		if(tmp != i){
			swap(arr[i], arr[tmp]);
		}
		
	}
}

//nổi bọt
void bubbleSort_tongTienThanhToan(KhachHang* arr, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = n-1; j > i; j--){
			if(arr[j-1].tongTienThanhToan > arr[j].tongTienThanhToan){
				swap(arr[j-1], arr[j]);
			}
		}
	}
}


// chèn trực tiếp
void insertionSort_tongTienThanhToan(KhachHang* array, int n){
	for(int i = 1; i < n; i++){
		int j = i-1;
		KhachHang tmp = array[i];
		while(j >= 0 && array[i].tongTienThanhToan > tmp.tongTienThanhToan){
			array[i+1] = array[i];
			j-=1;
		}
		array[j+1] = tmp;
	}
}
int main(){
	int n;
	do{
		cout<<"Nhap so khach hang: ";
		cin>>n;
	}while(n<=0);
	KhachHang* dsKhachHang = nhapMang(n);
	xuatMang(dsKhachHang, n);
	insertionSort_tongTienThanhToan(dsKhachHang, n);
	//xuatMang(dsKhachHang, n);
	delete[] dsKhachHang;
	return 0;
}
