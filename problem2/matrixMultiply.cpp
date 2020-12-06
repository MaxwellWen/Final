#include "matrixMultiply.h"
using namespace std;
// Part 1
Matrix matrixMultiply1(const Matrix & matrix_1, const Matrix & matrix_2){
    int n1=matrix_1.size();
    if(!n1 ) return {{-1}};  //throw INVALIDARGUMENT();
    int m1=matrix_1[0].size();
    int n2=matrix_2.size();
    if(!n2 ) return {{-1}};  //throw INVALIDARGUMENT();
    int m2=matrix_2[0].size();
    if(m1!=n2) return {{-1}};  //throw INVALIDARGUMENT();

    Matrix MulMatrix(n1,Array(m2));
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            int tmp=0;
            for(int k=0;k<m1;k++){
                tmp+=matrix_1[i][k]*matrix_2[k][j];
            }
            MulMatrix[i][j]=tmp;
        }
    }
    return MulMatrix;
}

// Part 2
Matrix transpose(const Matrix & A) {
    Matrix v(A[0].size(),Array(A.size(),0));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            v[j][i]=A[i][j];
        }
    }
    return v;
}
Matrix matrixMultiply2(const Matrix & matrix_1, const Matrix & matrix_2){
    int n1=matrix_1.size();
    if(!n1 ) return {{-1}};  //throw INVALIDARGUMENT();
    int m1=matrix_1[0].size();
    int n2=matrix_2.size();
    if(!n2 ) return {{-1}};  //throw INVALIDARGUMENT();
    int m2=matrix_2[0].size();
    if(m1!=n2) return {{-1}};  //throw INVALIDARGUMENT();

    Matrix MulMatrix(n1,Array(m2));
    Matrix v=transpose(matrix_2);
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            int tmp=inner_product(begin(matrix_1[i]), end(matrix_1[i]), begin(v[j]), 0);
//            cout<<"tmp: "<<tmp;
            MulMatrix[i][j]=tmp;
        }
    }
    return MulMatrix;
}

// Part 3
int Array_sum(const Array& a){
    int sum=0;
    for(int i=0;i<a.size();i++)
        sum+=a[i];
    return sum;
}
int op_mul(int i,int j){
    return i*j;
}
void print_a(const Array& a){
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
}
Matrix matrixMultiply3(const Matrix & matrix_1, const Matrix & matrix_2){
    int n1=matrix_1.size();
    if(!n1 ) return {{-1}};  //throw INVALIDARGUMENT();
    int m1=matrix_1[0].size();
    int n2=matrix_2.size();
    if(!n2 ) return {{-1}};  //throw INVALIDARGUMENT();
    int m2=matrix_2[0].size();
    if(m1!=n2) return {{-1}};  //throw INVALIDARGUMENT();

    Matrix MulMatrix(n1,Array(m2));
    Matrix v=transpose(matrix_2);
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            Array a(m1,0);
            transform(matrix_1[i].begin(), matrix_1[i].end(), v[j].begin(),a.begin(), op_mul);
            int tmp=Array_sum(a);
//            cout<<"tmp: "<<tmp;
//            print_a(a);
            MulMatrix[i][j]=tmp;
        }
    }
    return MulMatrix;
}

