#include <iostream>
#include <string>
using namespace std;

struct VeMayBay {
    int maVe;          
    string khoiHanh;   
    string den;        
    float giaVe;       
};

struct Node {
    VeMayBay data;    
    Node* left;        
    Node* right;      
};


Node* khoiTaoCay() {
    return nullptr;
}

Node* taoNode(VeMayBay ve) {
    Node* newNode = new Node;
    newNode->data = ve;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* chenNode(Node* root, VeMayBay ve) {
    if (root == nullptr) {
        return taoNode(ve);
    }

    if (ve.maVe < root->data.maVe) {
        root->left = chenNode(root->left, ve);
    } else {
        root->right = chenNode(root->right, ve);
    }

    return root;
}

Node* timKiem(Node* root, int maVe) {
    if (root == nullptr || root->data.maVe == maVe) {
        return root;
    }

    if (maVe < root->data.maVe) {
        return timKiem(root->left, maVe);
    } else {
        return timKiem(root->right, maVe);
    }
}

void duyetCay(Node* root) {
    if (root != nullptr) {
        duyetCay(root->left);
        cout << "Ma ve: " << root->data.maVe << ", Khoi hanh: " << root->data.khoiHanh
             << ", Den: " << root->data.den << ", Gia ve: " << root->data.giaVe << endl;
        duyetCay(root->right);
    }
}

void nhapCay(Node*& root, int n) {
    for (int i = 0; i < n; i++) {
        VeMayBay ve;
        cout << "Nhap thong tin ve may bay thu " << i + 1 << endl;
        cout << "Ma ve: ";
        cin >> ve.maVe;
        cin.ignore();
        cout << "Khoi hanh: ";
        getline(cin, ve.khoiHanh);
        cout << "Den: ";
        getline(cin, ve.den);
        cout << "Gia ve: ";
        cin >> ve.giaVe;
        cin.ignore();

        root = chenNode(root, ve);
    }
}

void hienThiDanhSach(Node* root) {
    duyetCay(root);
}

void timVeMayBay(Node* root, int maVe) {
    Node* result = timKiem(root, maVe);
    if (result != nullptr) {
        cout << "Ve may bay tim thay: " << endl;
        cout << "Ma ve: " << result->data.maVe << ", Khoi hanh: " << result->data.khoiHanh
             << ", Den: " << result->data.den << ", Gia ve: " << result->data.giaVe << endl;
    } else {
        cout << "Khong tim thay ve may bay co ma so " << maVe << endl;
    }
}

int main() {
    Node* root = khoiTaoCay();  

    int n;
    cout << "Nhap so luong ve may bay: ";
    cin >> n;
    cin.ignore();


    nhapCay(root, n);

    cout << "\nDanh sach ve may bay trong cay:\n";
    hienThiDanhSach(root);

    int maVe;
    cout << "\nNhap ma ve may bay can tim: ";
    cin >> maVe;
    timVeMayBay(root, maVe);

    return 0;
}

