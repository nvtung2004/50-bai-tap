#include<iostream>
#include<string>
#include<iomanip>
#include <stdexcept>
#include<limits>
using namespace std;

/*
    Question 1: Define a structure Project with the following fields: Project ID (integer), Project Name (string), Total Funding (float in trillion dong).
*/
class Project {
private:
    int projectID;
    string projectName;
    float totalFunding;

public:
    void inputInfo() {
        cout << "Enter project ID: ";        cin >> this->projectID;
        cout << "Enter project name: ";     cin.ignore(); getline(cin, this->projectName);
        cout << "Enter total funding: ";    cin >> this->totalFunding;
    }

    void displayInfo() const {
        cout << setw(30) << left << this->projectID
             << setw(30) << left << this->projectName
             << setw(30) << left << this->totalFunding << endl;
    }

    float getTotalFunding() const {
        return this->totalFunding;
    }
};

// Question 2: Write a function to input an array of n projects.
Project* inputArray(int n) {
    Project* arr = new Project[n];
    if (arr == nullptr) {
        exit(1);
    } else {
        for (int i = 0; i < n; i++) {
            arr[i].inputInfo();
        }
        return arr;
    }
}

// Question 3: Write a function to display an array of n projects.
void displayArray(const Project* arr, int n) {
    cout << setw(30) << left << "Project ID"
         << setw(30) << left << "Project Name"
         << setw(30) << left << "Total Funding (trillion dong)" << endl;
    for (int i = 0; i < n; i++) {
        arr[i].displayInfo();
    }
}

//Câu 4. (2 -) Sử dụng phương pháp sắp xếp chèn trực tiếp(inserttion sort), viết hàm sắp xếp các dự án theo chiều tăng dần của tổng kinh phí
//chèn trực tiếp
void interchangeSortByTongKinhPhi(Project* arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i].getTotalFunding()>arr[j].getTotalFunding()){
                swap(arr[i], arr[j]);
            }
        }
    }
}

//chọn trực tiếp
void selectionSortByTongKinhPhi(Project* arr, int n){
    for(int i = 0; i < n-1; i++){
        int t = i;
        for(int j = i+1; j < n; j++){
            if(arr[t].getTotalFunding()>arr[j].getTotalFunding()){
                t = j;
            }
        }
        if(i != t){
            swap(arr[i], arr[t]);
        }
    }
}

//nổi bọt
void bubbleSortByTongKinhPhi(Project* arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = n-1; j>i; j--){
            if(arr[j].getTotalFunding() < arr[j-1].getTotalFunding()){
                swap(arr[j], arr[j-1]);
            }
        }
    }
}

// chèn trực tiếp
void insertionSortByTongKinhPhi(Project* arr, int n){
    for(int i = 1; i < n; i++){
        int pos = i-1;
        Project tmp = arr[i];
        while(pos>=0 && arr[pos].getTotalFunding()>tmp.getTotalFunding()){
            arr[pos+1] = arr[pos];
            pos-=1;
        }
        arr[pos+1] = tmp;
    }
}


//quick sort
int partition(Project* arr, int low, int high) {
    int pivot = high;  
    int i = low - 1;  

    for (int j = low; j < high; j++) {
        if (arr[j].getTotalFunding() < arr[pivot].getTotalFunding()) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}


void quickSort(Project* arr, int low, int high) { 
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*
    Question 6: Write the main function to:
    - Input n projects and display the projects just input
    - Sort n projects in ascending order of total funding.
*/
void checkPositiveInteger(int value) {
    if (value <= 0) {
        throw std::invalid_argument("Value must be a positive integer."); // throw used to throw an error (exception), when encountering the throw command, it automatically directs to the nearest catch
    }
}

int handleException() {
    int n;
    while (true) {
        try {
            cin >> n;
            // Check data type of n
            if (cin.fail()) { // Check the state of cin. If in error state, it cannot be operated on
                cin.clear(); // Clear the error state of cin to continue operating.
                cin.ignore();
                // At this point, there is an input error that needs to be thrown as an exception
                throw std::invalid_argument("Input must be an integer.");
            }
            checkPositiveInteger(n);

            break; // Exit the loop after not encountering any throw commands
        } catch (const std::exception& e) {
            cerr << "errors: " << e.what() << endl;
            cout << "Please enter a positive integer: ";
        }
    }
    return n;
}

int main() {
    int n;
    cout << "Enter the number of array elements (must be a positive integer): ";
    do{
        cin>>n;
    }while(n<=0);
    Project* arr = inputArray(n);
    cout<<"Hien thi mang vua nhap: "<<endl;
    displayArray(arr, n);
    cout<<"Sap xep mang du an tang dan theo tong kinh phi: "<<endl;
    quickSort(arr, 0, n-1);
    displayArray(arr, n);
    delete[] arr;
	return 0;
}


