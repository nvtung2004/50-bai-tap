#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
using namespace std;

class MonHoc{
	private:
		string maMH, tenMH;
		int soTinChi, soTietDaGiangDay;
	
	public:
		void nhapThongTin(){
			cout<<"Nhap ma mon hoc: ";
			cin.ignore();
			getline(cin, this->maMH);
			cout<<"Nhap ten mon hoc: ";
			getline(cin, this->tenMH);
			cout<<"Nhap so tin chi: ";
			cin>>this->soTinChi;
			cout<<"Nhap so tiet da giang day: ";
			cin>>this->soTietDaGiangDay;
		}
		
		void xuatThongTin(){
			cout<<setw(20)<<left<<this->maMH
				<<setw(20)<<left<<this->tenMH
				<<setw(20)<<left<<this->soTinChi
				<<setw(20)<<left<<this->soTietDaGiangDay<<endl;
		}
		
		int getSoTietGiangDay(){
			return this->soTietDaGiangDay;
		}
};

// kiem tra tinh hop le cua n(n la so luong phan tu cua mang)
int isValid(){
	int n;
	while(true){
		try{
			cin>>n;
			if(cin.fail()){
				cin.clear(); // xoa trang thai loi nhap du lieu khong hop le de tiep tuc xu ly
				cin.ignore(); // xoa cac ky tu du thua
				throw invalid_argument("Du lieu dau vao khong hop le. Yeu cau nhap so nguyen duong.");
			}
			if(n <= 0){
				throw invalid_argument("Gia tri dau vao khong hop le. Yeu cau nhap so nguyen duong.");
			}
			break;
		} catch(const exception& ex){
			cout<<ex.what()<<endl;
		}
	}
	return n;
}

//tao mang de luu thong tin
MonHoc* taoMang(int n){
	MonHoc* arr = new MonHoc[n];
	if(arr == NULL){
		cout<<"Loi cap phat bo nho.";
		exit(01);
	} else{
		for(int i = 0; i < n; i++){
			arr[i].nhapThongTin();
		}
		return arr;
	}
}

// hien thi mang
void xuatMang(MonHoc* arr, int n){
	for(int i = 0; i < n; i++){
		arr[i].xuatThongTin();
	}
}

//pp sx doi cho truc tiep
void interchangeSort(MonHoc* arr, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j<n; j++){
			if(arr[i].getSoTietGiangDay() > arr[j].getSoTietGiangDay()){
				swap(arr[i], arr[j]);
			}
		}
	}
}

// pp sx chon truc tiep
void selectionSort(MonHoc* arr, int n){
	for(int i = 0; i < n-1; i++){
		int x = i;
		for(int j = i+1; j<n; j++){
			if(arr[x].getSoTietGiangDay()>arr[j].getSoTietGiangDay()){
				x = j;
			}
		}
		if( x != i){
			swap(arr[i], arr[x]);
		}
	}
}

// pp sx chen truc tiep
void insertionSort(MonHoc* arr, int n){
	for(int i = 1; i < n; i++){
		MonHoc tmp = arr[i];
		int pos = i-1;
		while(pos>=0 && arr[pos].getSoTietGiangDay()>tmp.getSoTietGiangDay()){
			arr[pos+1] = arr[pos];
			pos -=1;
		}
		arr[pos+1] = tmp;
	}
}

//bubble sort
void bubbleSort(MonHoc* arr, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j<n-1-i; j++){
			if(arr[j].getSoTietGiangDay() > arr[j+1].getSoTietGiangDay()){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

//quick sort
int partition (MonHoc* arr, int low, int high){
	int pivot = high;
	int i = low -1;
	for(int j = low; j < high; j++){
		if(arr[j].getSoTietGiangDay()<arr[pivot].getSoTietGiangDay()){
			i+=1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[pivot], arr[i+1]);
	return i+1;
}

void quickSort(MonHoc* arr, int low, int high){
	if(low < high){
		int x = partition(arr, low, high);
		quickSort(arr, low, x-1);
		quickSort(arr, x+1, high);
	}
}

int main(){
	int n;
	cout<<"Nhap n (n>0): ";
	n = isValid();
	
	cout<<"----Nhap mang---- "<<endl;
	MonHoc* arr = taoMang(n);
	
	cout<<"----Hien thi mang vua nhap---- "<<endl;
	cout<<setw(20)<<left<<"Ma mon hoc"
		<<setw(20)<<left<<"Ten mon hoc"
		<<setw(20)<<left<<"So tin chi"
		<<setw(20)<<left<<"So tiet giang day"<<endl;
	xuatMang(arr, n);
	
	//cout<<"----Phuong phap sap xep interchange sort----"<<endl;
	//interchangeSort(arr, n);
	
	//cout<<"----Phuong phap sap xep selection sort----"<<endl;
	//selectionSort(arr, n);
	
	//cout<<"----Phuong phap sap xep chen truc tiep----"<<endl;
	//insertionSort(arr, n);
	
	//cout<<"----Phuong phap sap xep bubble sort----"<<endl;
	//bubbleSort(arr, n);

	cout<<"----Phuong phap sap xep quick sort----\n";
	quickSort(arr, 0, n-1);
	cout<<setw(20)<<left<<"Ma mon hoc"
		<<setw(20)<<left<<"Ten mon hoc"
		<<setw(20)<<left<<"So tin chi"
		<<setw(20)<<left<<"So tiet giang day"<<endl;
	xuatMang(arr, n);
	
	
	return 0;
}

