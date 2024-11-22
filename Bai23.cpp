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
		string hienThiNgay() const{ // ham nay k lam thay doi du lieu attribute
			return to_string(ngay)+"/"+to_string(thang)+"/"+to_string(nam);
		}
};
class HangHoa{ // checked
	private:
		string maHH, tenHH;
		Date ngayXuatHang;
		float giaXuatHang;
	
	public:
		void nhapThongTinHangHoa(){
			
			cout<<"Nhap ma hang hoa: ";	cin.ignore();	getline(cin, this->maHH);
			cout<<"Nhap ten hang hoa: ";	getline(cin, this->tenHH);
			ngayXuatHang.nhapNgay();
			cout<<"Nhap gia xuat hang: ";	cin>>this->giaXuatHang;
		}
		void xuatThongTinHangHoa(){
			cout<<setw(15)<<left<<this->maHH
				<<setw(15)<<left<<this->tenHH
				<<setw(20)<<left<<this->ngayXuatHang.hienThiNgay()
				<<setw(35)<<left<<this->giaXuatHang<<endl;
		}
		float getGiaXuatHangHoa(){
			return this->giaXuatHang;
		}
};

class DanhSachHangHoa{ //checked
	private:
		HangHoa* list;
	public:
		DanhSachHangHoa(int n){
			this->list = new HangHoa[n];
		}
		
		~DanhSachHangHoa(){
			delete[] list;
		}
		void nhapDanhSach(int n){
			for(int i = 0; i < n; i++){
				list[i].nhapThongTinHangHoa();
			}
		}
		void xuatDanhSach(int n){
			cout<<setw(15)<<left<<"Ma hang hoa"
				<<setw(15)<<left<<"Ten hang hoa"
				<<setw(20)<<left<<"Ngay xuat hang"
				<<setw(35)<<left<<"Gia xuat hang(trieu)"<<endl;
			for(int i = 0; i < n; i++){
				list[i].xuatThongTinHangHoa();
			}
		}
		//pp sx doi cho truc tiep
		void interchangeSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = i+1; j < n; j++){
					if(list[i].getGiaXuatHangHoa() > list[j].getGiaXuatHangHoa()){
						swap(list[i], list[j]);
					}
				}
			}
		}
		
		// pp sx chon truc tiep
		void selectionSort(int n){
			for(int i = 0; i < n-1; i++){
				int tmp = i;
				for(int j = i+1; j < n; j++){
					if(list[tmp].getGiaXuatHangHoa()>list[j].getGiaXuatHangHoa()){
						tmp = j;
					}
				}
				if(tmp != i){
					swap(list[i], list[tmp]);
				}
			}
		}
		
		// pp sx chen truc tiep
		void insertionSort(int n){
			for(int i = 1; i < n; i++){
				HangHoa tmp = list[i];
				int pos = i-1;
				while(pos>=0 && list[pos].getGiaXuatHangHoa() > tmp.getGiaXuatHangHoa()){
					list[pos+1] = list[pos];
					pos-=1;
				}
				list[pos+1] = tmp;
			}
		}
		
		// pp sx noi bot
		void bubbleSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = n-1; j>i; j--){
					if(list[j].getGiaXuatHangHoa() < list[j-1].getGiaXuatHangHoa()){
						swap(list[j], list[j-1]);
					}
				}
			}
		}
		
		// pp sx nhanh
		int partition(int low, int high){
			int pivot = high;
			int i = low-1;
			for(int j = low; j < high; j++){
				if(list[j].getGiaXuatHangHoa() < list[pivot].getGiaXuatHangHoa()){
					i+=1;
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
	
	DanhSachHangHoa* list = new DanhSachHangHoa(n);
	cout<<"Nhap danh sach hang hoa: "<<endl;
	list->nhapDanhSach(n);
	cout<<"Xuat danh sach hang hoa: "<<endl;
	list->xuatDanhSach(n);
	
	cout<<"Sap xep danh sach hang hoa tang dan theo gia xuat hang: "<<endl;
	//list->interchangeSort(n);
	//list->selectionSort(n);
	//list->insertionSort(n);
	//list->bubbleSort(n);
	list->quickSort(0, n-1);
	list->xuatDanhSach(n);
	

	return 0;
}
