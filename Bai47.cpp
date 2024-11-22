#include <iostream>
#include <string>
using namespace std;

struct VanDongVien {
    int maVdv;             
    string tenVdv;        
    int tuoi;             
    float luong;           
};

struct Node {
    VanDongVien data;     
    Node* left;           
    Node* right;          
};


Node* khoiTaoCay() {
    return nullptr;
}

Node* taoNode(VanDongVien vdv) {
    Node* newNode = new Node;
    newNode->data = vdv;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* chenNode(Node* root, VanDongVien vdv) {
    if (root == nullptr) {
        return taoNode(vdv);
    }

    if (vdv.maVdv < root->data.maVdv) {
        root->left = chenNode(root->left, vdv);
    } else {
        root->right = chenNode(root->right, vdv);
    }

    return root;
}

Node* timKiem(Node* root, int maVdv) {
    if (root == nullptr || root->data.maVdv == maVdv) {
        return root;
    }

    if (maVdv < root->data.maVdv) {
        return timKiem(root->left, maVdv);
    } else {
        return timKiem(root->right, maVdv);
    }
}

void duyetCay(Node* root) {
    if (root != nullptr) {
        duyetCay(root->left);
        cout << "Ma VDV: " << root->data.maVdv << ", Ten VDV: " << root->data.tenVdv
             << ", Tuoi: " << root->data.tuoi << ", Luong: " << root->data.luong << " trieu dong" << endl;
        duyetCay(root->right);
    }
}

void nhapCay(Node*& root, int n) {
    for (int i = 0; i < n; i++) {
        VanDongVien vdv;
        cout << "Nhap thong tin VDV thu " << i + 1 << endl;
        cout << "Ma VDV: ";
        cin >> vdv.maVdv;
        cin.ignore();
        cout << "Ten VDV: ";
        getline(cin, vdv.tenVdv);
        cout << "Tuoi: ";
        cin >> vdv.tuoi;
        cout << "Luong: ";
        cin >> vdv.luong;
        cin.ignore();

        root = chenNode(root, vdv);
    }
}

void hienThiDanhSach(Node* root) {
    duyetCay(root);
}

void timVdv(Node* root, int maVdv) {
    Node* result = timKiem(root, maVdv);
    if (result != nullptr) {
        cout << "VDV tim thay: " << endl;
        cout << "Ma VDV: " << result->data.maVdv << ", Ten VDV: " << result->data.tenVdv
             << ", Tuoi: " << result->data.tuoi << ", Luong: " << result->data.luong << " trieu dong" << endl;
    } else {
        cout << "Khong tim thay VDV co ma so " << maVdv << endl;
    }
}

int main() {
    Node* root = khoiTaoCay();  

    int n;
    cout << "Nhap so luong VDV: ";
    cin >> n;
    cin.ignore();

    nhapCay(root, n);

    cout << "\nDanh sach VDV trong cay:\n";
    hienThiDanhSach(root);

    int maVdv;
    cout << "\nNhap ma VDV can tim: ";
    cin >> maVdv;
    timVdv(root, maVdv);

    return 0;
}

