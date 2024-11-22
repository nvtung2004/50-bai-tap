#include<iostream>
#include<string>
#include<iomanip>
//https://howkteam.vn/course/khoa-hoc-lap-trinh-c-can-ban/nhap-xuat-va-dinh-dang-du-lieu-trong-c-input-and-output-36
using namespace std;
//cau 1
struct SinhVien
{
	int maSinhVien;
	string tenSinhVien, lop;
	float tongKet;
};

void nhapThongTin(SinhVien* sv){
	cout<<"Nhap ma sinh vien: ";	cin>>sv->maSinhVien;	
	cout<<"Nhap ten sinh vien: ";	cin.ignore();	getline(cin, sv->tenSinhVien);
	cout<<"Nhap lop: ";				getline(cin, sv->lop);
	cout<<"Nhap diem tong ket: ";	cin>>sv->tongKet;
}
//cau 2: Viet ham nhap thong tin mang gom n sinh vien.
SinhVien* nhapMangSinhVien(int n){
	SinhVien* arraySV = new SinhVien[n];
	if(arraySV==NULL){
		return NULL;
	}
	else{
		return arraySV;		
	}
}
//cau 3: Viet ham xuat hien thi thong tin mang gom n sinh vien vua nhap.
void hienThiMangSinhVien(SinhVien* sv){
	cout<<setw(20)<<left<<sv->maSinhVien<<setw(30)<<left<<sv->tenSinhVien<<setw(15)<<left<<sv->lop<<setw(10)<<left<<sv->tongKet<<endl;
}

//chèn trực tiếp là đi so sánh 1 phần tử nằm liền sau đoạn đoạn đã sắp xếp sau đo đi so sanh với từng phần tử trong đoạn 
// rồi chèn vào chỗ hợp lý sau đó dịch các phần tử về sau 1 index
void insertionSort_tongKet(SinhVien* a, int n){
	SinhVien tmp;
	for(int i = 1; i < n; i++){
		int pos = i-1;
		tmp = a[i];
		while(pos >= 0 && a[pos].tongKet>tmp.tongKet){
			a[pos+1] = a[pos];
			pos-=1;
		}
		a[pos+1] = tmp;
	}
}
// đổi chỗ trực tiếp: so sánh 2 vị trí rồi đổi chỗ nếu vi phạm
void interchangeSort_tongKet(SinhVien* a, int n){
	for(int i = 0; i < n-1;i++){
		for(int j = i+1; j < n; j++){
			if(a[i].tongKet>a[j].tongKet){
				swap(a[i], a[j]);
			}
		}
	}
}
// chọn trực tiếp : chọn ra phần tử có giá trị lớn nhất hoặc nhỏ nhất trong đoạn j rồi đổi chỗ với phần tử i hiện tại nếu vi phạm
void selectionSort_tongKet(SinhVien* a, int n){
	for(int i = 0; i < n-1; i++){
		int min = i;
		for(int j = i+1; j<n;j++){
			if(a[min].tongKet > a[j].tongKet){
				min = j;
			}
		}
		if(min != i){
			swap(min, i);
		}
		
	}
}

// nổi bọt: là duyệt vòng j từ cuối duyệt lại so sánh trong vòng j, còn vòng i đi đến đâu là chỗ đó đã sắp xếp
// hoặc có thể duyệt vòng j từ đầu nhưng giới hạn sẽ là n -i -1, vì khi vòng j sắp xếp thì nó sẽ đẩy min hoặc max về cuối
void bubbleSort_tongKet(SinhVien* array, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = n-1; j > i; j--){
			if(array[j-1].tongKet > array[j].tongKet){
				swap(array[j-1], array[j]);
			}
		}
	}
}

//cau 5: ap dung chien luoc chia de tri ( bang thuat toan tim kiem nhi phan). Viet ham tim kiem sinh vien co tong ket la x( voi x nhap tu ban phim).

int main(){
	int n;
	cout<<"Nhap so luong sinh vien: ";
	cin>>n;
	SinhVien* dsSinhVien = nhapMangSinhVien(n);
	cout<<"Nhap thong tin cho sinh vien: "<<endl;
	for(int i = 0; i < n; i++){
		cout<<"Nhap thong tin cho sinh vien thu "<<i+1<<endl;
		nhapThongTin(&dsSinhVien[i]);
	}
	cout<<"Hien thi thong tin: "<<endl;
	cout<<setw(20)<<left<<"MSV"<<setw(30)<<left<<"Ten"<<setw(15)<<left<<"Lop"<<setw(10)<<left<<"Tong ket"<<endl;
	for(int i = 0; i < n; i++){
		hienThiMangSinhVien(&dsSinhVien[i]);
	}
	insertionSort_tongKet(dsSinhVien, n);
	cout<<"Mang sinh vien sau khi sap xep tang dan theo tong ket theo phương pháp sắp xếp insertion sort (chèn trực tiếp): "<<endl;
	cout<<setw(20)<<left<<"MSV"<<setw(30)<<left<<"Ten"<<setw(15)<<left<<"Lop"<<setw(10)<<left<<"Tong ket"<<endl;
	for(int i = 0; i < n; i++){
		hienThiMangSinhVien(&dsSinhVien[i]);
	}
//	interchangeSort_tongKet(dsSinhVien, n);
//	selectionSort_tongKet(dsSinhVien, n);
	bubbleSort_tongKet(dsSinhVien, n);
	cout<<"Mang sinh vien sau khi sap xep tang dan theo tong ket: "<<endl;
	cout<<setw(20)<<left<<"MSV"<<setw(30)<<left<<"Ten"<<setw(15)<<left<<"Lop"<<setw(10)<<left<<"Tong ket"<<endl;
	for(int i = 0; i < n; i++){
		hienThiMangSinhVien(&dsSinhVien[i]);
	}
	
	delete[] dsSinhVien;
	return 0;
}



