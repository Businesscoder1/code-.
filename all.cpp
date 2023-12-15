// #include <iostream>
// using namespace std;
// #define SIZE 20
// class Deque {
//     int dequeArr[20],f,r;
//     public:
//     Deque(){
//         f=-1;
//         r=-1;

//     }
//     void inserteF(int);
//     void inserteR(int);
//     void deleteF();
//     void deleteR();
//     void display();

// };

// void Deque::inserteF(int i){
//     if(f==-1){
//         f=0;
//         dequeArr[f];
//     }
//     else if(f!=0){
//         f--;
//         dequeArr[f];
//     }

// }

// void Deque::inserteR(int x){
//      if(r>=SIZE-1){
//         cout<<"Insertion is not possible here "<<endl;

//      }
//      else if(f==-1){
//           f++;
//           r++;
//           dequeArr[r];
//      }
//      else{
//        r++;
//        dequeArr[r];
//      }
// }

// void Deque::deleteF(){
//     if(f==-1){
//         cout<<"Deletion is not possiblr"<<endl;
//         return;
//     }
//     else if(f==r){
//         f=r=-1;
//         return;

//     }
//     else{
//         f=f+1;

//     }
// }


// void Deque::deleteR(){
//     if(f==-1){
//         cout<<"Deletion is not possiblr"<<endl;
//         return;
//     }
//     else if(f==r){
//         f=r=-1;
//         return;

//     }
//     else{
//         r=r-1;

//     }
// }

// void Deque::display(){
//     if(f==-1){
//         cout<<"Dequeue is empty"<<endl;

//     }
//     else{
//         for (int i = f; i <=r; i++)
//         {
//             cout<<dequeArr[i]<<" ";
//         }
        
//     }
// }

// int main(){
//     Deque d1;
//     d1.inserteF(23);
//     d1.inserteF(56);
//     d1.inserteR(45);
//     d1.display();
// }
#include <iostream>
using namespace std;

#define SIZE 20

class Deque {
    int dequeArr[SIZE];
    int f, r;

public:
    Deque() {
        f = -1;
        r = -1;
    }

    void inserteF(int);
    void inserteR(int);
    void deleteF();
    void deleteR();
    void display();
};

void Deque::inserteF(int x) {
    if (f == 0 && r == SIZE - 1) {
        cout << "Insertion at the front is not possible (Deque is full)" << endl;
        return;
    } else if (f == -1) {
        f = r = 0;
        dequeArr[f] = x;
    } else if (f > 0) {
        f--;
        dequeArr[f] = x;
    } else {
        // cout << "Insertion at the front is not possible (Deque is full)" << endl;
    }
}

void Deque::inserteR(int x) {
    if (f == 0 && r == SIZE - 1) {
        cout << "Insertion at the rear is not possible (Deque is full)" << endl;
        return;
    } else if (r == -1) {
        f = r = 0;
        dequeArr[r] = x;
    } else if (r < SIZE - 1) {
        r++;
        dequeArr[r] = x;
    } else {
        cout << "Insertion at the rear is not possible (Deque is full)" << endl;
    }
}

void Deque::deleteF() {
    if (f == -1) {
        cout << "Deletion at the front is not possible (Deque is empty)" << endl;
        return;
    } else if (f == r) {
        f = r = -1;
    } else {
        f++;
    }
}

void Deque::deleteR() {
    if (r == -1) {
        cout << "Deletion at the rear is not possible (Deque is empty)" << endl;
        return;
    } else if (f == r) {
        f = r = -1;
    } else {
        r--;
    }
}

void Deque::display() {
    if (f == -1) {
        cout << "Deque is empty" << endl;
    } else {
        for (int i = f; i <= r; i++) {
            cout << dequeArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Deque d1;
    d1.inserteF(23);
    d1.inserteF(56);
    d1.inserteF(34);
    // d1.inserteR(45);
    d1.display();
    d1.inserteR(22);
    d1.deleteF();
    d1.display();
    return 0;
}
