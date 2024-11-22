#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct HangHoa {
    int maHH;          
    string tenHH;      
    string ngayXuat;   
    float giaXuat;    
};

struct Node {
    HangHoa data;
    Node* left;
    Node* right;
};


Node* khoiTaoCay() {
    return nullptr;
}

Node* taoNode(HangHoa hh) {
    Node* newNode = new Node;
    newNode->data = hh;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* chenNode(Node* root, HangHoa hh) {
    if (root == nullptr) {
        return taoNode(hh);
    }

    if (hh.maHH < root->data.maHH) {
        root->left = chenNode(root->left, hh);
    } else {
        root->right = chenNode(root->right, hh);
    }

    return root;
}

Node* timKiem(Node* root, int maHH) {
    if (root == nullptr || root->data.maHH == maHH) {
        return root;
    }

    if (maHH < root->data.maHH) {
        return timKiem(root->left, maHH);
    } else {
        return timKiem(root->right, maHH);
    }
}

void duyetCay(Node* root) {
    if (root != nullptr) {
        duyetCay(root->left);
        cout << "Ma HH: " << root->data.maHH << ", Ten: " << root->data.tenHH
             << ", Ngay xuat: " << root->data.ngayXuat << ", Gia xuat: " << root->data.giaXuat << " tri?u d?ng" << endl;
        duyetCay(root->right);
    }
}

void nhapCay(Node*& root, int n) {
    for (int i = 0; i < n; i++) {
        HangHoa hh;
        cout << "Nhap thong tin hang hoa thu " << i+1 << endl;
        cout << "Ma hang hoa: ";
        cin >> hh.maHH;
        cin.ignore();
        cout << "Ten hang hoa: ";
        getline(cin, hh.tenHH);
        cout << "Ngay xuat (dd/mm/yyyy): ";
        getline(cin, hh.ngayXuat);
        cout << "Gia xuat (trieu dong): ";
        cin >> hh.giaXuat;
        cin.ignore();

        root = chenNode(root, hh);
    }
}

void hienThiDanhSach(Node* root) {
    duyetCay(root);
}

void timHangHoa(Node* root, int maHH) {
    Node* result = timKiem(root, maHH);
    if (result != nullptr) {
        cout << "Hang hoa tim thay: " << endl;
        cout << "Ma HH: " << result->data.maHH << ", Ten: " << result->data.tenHH
             << ", Ngay xuat: " << result->data.ngayXuat << ", Gia xuat: " << result->data.giaXuat << " tri?u d?ng" << endl;
    } else {
        cout << "Khong tim thay hang hoa co ma so " << maHH << endl;
    }
}

int main() {
    Node* root = khoiTaoCay(); 

    int n;
    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    cin.ignore();

    nhapCay(root, n);

    cout << "\nDanh sach hang hoa trong cay:\n";
    hienThiDanhSach(root);


    int maHH;
    cout << "\nNhap ma hang hoa can tim: ";
    cin >> maHH;
    timHangHoa(root, maHH);

    return 0;
}

