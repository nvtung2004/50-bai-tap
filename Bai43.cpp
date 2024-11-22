#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct NhanVien {
    int maNV;           
    string hoTen;        
    string ngaySinh;    
    float luong;        
};

struct Node {
    NhanVien data;
    Node* left;
    Node* right;
};


Node* khoiTaoCay() {
    return nullptr;
}

Node* taoNode(NhanVien nv) {
    Node* newNode = new Node;
    newNode->data = nv;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* chenNode(Node* root, NhanVien nv) {
    if (root == nullptr) {
        return taoNode(nv);
    }

    if (nv.maNV < root->data.maNV) {
        root->left = chenNode(root->left, nv);
    } else {
        root->right = chenNode(root->right, nv);
    }

    return root;
}

Node* timKiem(Node* root, int maNV) {
    if (root == nullptr || root->data.maNV == maNV) {
        return root;
    }

    if (maNV < root->data.maNV) {
        return timKiem(root->left, maNV);
    } else {
        return timKiem(root->right, maNV);
    }
}

void duyetCay(Node* root) {
    if (root != nullptr) {
        duyetCay(root->left);
        cout << "Ma NV: " << root->data.maNV << ", Ho ten: " << root->data.hoTen
             << ", Ngay sinh: " << root->data.ngaySinh << ", Luong: " << root->data.luong << " trieu dong" << endl;
        duyetCay(root->right);
    }
}

void nhapCay(Node*& root, int n) {
    for (int i = 0; i < n; i++) {
        NhanVien nv;
        cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
        cout << "Ma nhan vien: ";
        cin >> nv.maNV;
        cin.ignore();
        cout << "Ho ten nhan vien: ";
        getline(cin, nv.hoTen);
        cout << "Ngay sinh (dd/mm/yyyy): ";
        getline(cin, nv.ngaySinh);
        cout << "Luong (trieu dong): ";
        cin >> nv.luong;
        cin.ignore();

        root = chenNode(root, nv);
    }
}

void hienThiDanhSach(Node* root) {
    duyetCay(root);
}

void timNhanVien(Node* root, int maNV) {
    Node* result = timKiem(root, maNV);
    if (result != nullptr) {
        cout << "Nhan vien tim thay: " << endl;
        cout << "Ma NV: " << result->data.maNV << ", Ho ten: " << result->data.hoTen
             << ", Ngay sinh: " << result->data.ngaySinh << ", Luong: " << result->data.luong << " trieu dong" << endl;
    } else {
        cout << "Khong tim thay nhan vien co ma so " << maNV << endl;
    }
}

int main() {
    Node* root = khoiTaoCay();  

    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore();

    nhapCay(root, n);

    cout << "\nDanh sach nhan vien trong cay:\n";
    hienThiDanhSach(root);

    int maNV;
    cout << "\nNhap ma nhan vien can tim: ";
    cin >> maNV;
    timNhanVien(root, maNV);

    return 0;
}

