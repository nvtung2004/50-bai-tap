#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Cau 1: Dinh nghia cau truc Sinh vien
struct SinhVien {
    int maSV;
    string tenSV;
    string lop;
    float tongKet;
    string hanhKiem;
};

// Cau truc cay nhi phan tim kiem
struct Node {
    SinhVien data;
    Node* left;
    Node* right;
};

// Cau 2: Cac thao tac voi cay nhi phan tim kiem

// 1. Khoi tao cay
Node* khoiTaoCay() {
    return nullptr;
}

// 2. Tao moi mot nut chua du lieu
Node* taoNode(SinhVien sv) {
    Node* newNode = new Node;
    newNode->data = sv;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// 3. Chen nut vao cay
Node* chenNode(Node* root, SinhVien sv) {
    if (root == nullptr) {
        return taoNode(sv);
    }

    if (sv.maSV < root->data.maSV) {
        root->left = chenNode(root->left, sv);
    } else {
        root->right = chenNode(root->right, sv);
    }

    return root;
}

// 4. Tim kiem phan tu trong cay
Node* timKiem(Node* root, int maSV) {
    if (root == nullptr || root->data.maSV == maSV) {
        return root;
    }

    if (maSV < root->data.maSV) {
        return timKiem(root->left, maSV);
    } else {
        return timKiem(root->right, maSV);
    }
}

// 5. Duyet cay 
void duyetCay(Node* root) {
    if (root != nullptr) {
        duyetCay(root->left);
        cout << "Ma SV: " << root->data.maSV << ", Ten: " << root->data.tenSV
             << ", Lop: " << root->data.lop << ", Tong ket: " << root->data.tongKet
             << ", Hanh kiem: " << root->data.hanhKiem << endl;
        duyetCay(root->right);
    }
}

// Cau 3: Nhap cay nhi phan
void nhapCay(Node*& root, int n) {
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        cout << "Nhap thong tin sinh vien thu " << i+1 << endl;
        cout << "Ma sinh vien: ";
        cin >> sv.maSV;
        cin.ignore(); 
        cout << "Ten sinh vien: ";
        getline(cin, sv.tenSV);
        cout << "Lop: ";
        getline(cin, sv.lop);
        cout << "Tong ket: ";
        cin >> sv.tongKet;
        cin.ignore(); 
        cout << "Hanh kiem: ";
        getline(cin, sv.hanhKiem);

        root = chenNode(root, sv);
    }
}

// Cau 4: Duyet cay va hien thi danh sach sinh vien
void hienThiDanhSach(Node* root) {
    duyetCay(root);
}

// Cau 5: Tim kiem sinh vien theo ma so
void timSinhVien(Node* root, int maSV) {
    Node* result = timKiem(root, maSV);
    if (result != nullptr) {
        cout << "Sinh vien tim thay: " << endl;
        cout << "Ma SV: " << result->data.maSV << ", Ten: " << result->data.tenSV
             << ", Lop: " << result->data.lop << ", Tong ket: " << result->data.tongKet
             << ", Hanh kiem: " << result->data.hanhKiem << endl;
    } else {
        cout << "Khong tim thay sinh vien co ma so " << maSV << endl;
    }
}


int main() {
    Node* root = khoiTaoCay();  // Khoi tao cay

    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();  

    // Cau 3: Nhap vao cay nhi phan tim kiem
    nhapCay(root, n);

    // Cau 4: Duyet cay va hien thi danh sach sinh vien
    cout << "\nDanh sach sinh vien trong cay:\n";
    hienThiDanhSach(root);

    // Cau 5: Tim kiem sinh vien theo ma so
    int maSV;
    cout << "\nNhap ma sinh vien can tim: ";
    cin >> maSV;
    timSinhVien(root, maSV);

    return 0;
}

