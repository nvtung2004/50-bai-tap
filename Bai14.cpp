#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct date{
	int day, month, year;
};
struct HangHoa{
	string maHangHoa, tenHangHoa;
	date ngayXuatHang;
	float giaXuatHangDi;
};

void nhapThongTin(HangHoa* hh){
	cout<<"Nhap ma hang hoa: ";				cin.ignore();	getline(cin, hh->maHangHoa);
	cout<<"Nhap ten hang hoa: ";			getline(cin, hh->tenHangHoa);
	cout<<"Nhap ngay xuat hang d/m/y: ";	cin>>hh->ngayXuatHang.day>>hh->ngayXuatHang.month>>hh->ngayXuatHang.year;
	cout<<"Nhap gia xuat hang di: ";		cin>>hh->giaXuatHangDi;
}

HangHoa* nhapMang(int n){
	HangHoa* array = new HangHoa[n];
	if(array == NULL){
		return NULL;
	}
	else{
		cout<<"Nhap thong tin: "<<endl;
		for(int i = 0; i < n; i++){
			cout<<"Nhap thong tin hang hoa thu "<<i+1<<endl;
			nhapThongTin(&array[i]);
		}
		return array;
	}
}

void xuatThongTin(HangHoa* hh){
	string ngayXuat = to_string(hh->ngayXuatHang.day) + "/" + 
                      to_string(hh->ngayXuatHang.month) + "/" + 
                      to_string(hh->ngayXuatHang.year);
	cout<<setw(30)<<left<<hh->maHangHoa<<setw(30)<<left<<hh->tenHangHoa
		<<setw(30)<<left<<ngayXuat
		<<setw(20)<<left<<hh->giaXuatHangDi<<endl;
}
void xuatMang(HangHoa* array, int n){
	cout<<"Xuat thong tin: "<<endl;
	cout<<setw(30)<<left<<"Ma hang hoa"<<setw(30)<<left<<"Ten hang hoa"<<setw(30)<<left<<"Ngay xuat hang"<<setw(20)<<left<<"Gia xuat hang di"<<endl;
	for(int i = 0; i < n; i++){
		xuatThongTin(&array[i]);
	}
}

void insertionSort_giaXuat(HangHoa* array,int n){
	for(int i = 1; i < n; i++){
		HangHoa tmp = array[i];
		int j = i-1;
		while(j>=0 && array[j].giaXuatHangDi>tmp.giaXuatHangDi){
			array[j+1] = array[j];
			j-= 1;
		}
		array[j+1] = tmp;
	}
}

void interchangeSort_giaXuat(HangHoa* array, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(array[i].giaXuatHangDi>array[j].giaXuatHangDi){
				swap(array[i], array[j]);
			}
		}
	}
}

void selectionSort_giaXuat(HangHoa* array, int n){
	for(int i = 0; i < n-1; i++){
		int min = i;
		for(int j = i+1; j < n; j++){
			if(array[min].giaXuatHangDi > array[j].giaXuatHangDi){
				min = j;
			}
			if(min != i ){
				swap(array[min], array[i]);
			}
		}
	}
}

void bubbleSort_giaXuat(HangHoa* array, int n){
	for(int i = 0; i < n-1;i++){
		for(int j = n-1; j>i; j--){
			if(array[j-1].giaXuatHangDi>array[j].giaXuatHangDi){
				swap(array[j-1], array[j]);
			}
		}
	}
}
int main(){
	int n;
	do{
		cout<<"Nhap so luong hang hoa: ";
		cin>>n;
	}while(n<=0);
	HangHoa* dsHangHoa = nhapMang(n);
	xuatMang(dsHangHoa, n);
//	insertionSort_giaXuat(dsHangHoa,n);
//	interchangeSort_giaXuat(dsHangHoa, n);
//	selectionSort_giaXuat(dsHangHoa, n);
	bubbleSort_giaXuat(dsHangHoa, n);
	xuatMang(dsHangHoa, n);
	delete[] dsHangHoa;
	return 0;
}
