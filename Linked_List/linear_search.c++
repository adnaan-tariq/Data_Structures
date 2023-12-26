#include <iostream>
using namespace std;
int main() {
    int array1[5] = {10, 20, 30, 40, 50};
    int i;
    int key;
    int loc= -1;
    cout<<"Enter value to find: ";
    cin>>key;
    for(i =0; i<5; i++){
        if(array1[i] == key)
        loc =i;
    }
    if (loc  == -1){
        cout<<"Value not found";
    }
    else
    {cout<<"Value found at index "<<loc<<endl;}
    return 0;
}
