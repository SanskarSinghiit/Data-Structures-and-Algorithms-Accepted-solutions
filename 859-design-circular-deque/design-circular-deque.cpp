class MyCircularDeque {
private:
    int i = 1999;
    int j = 2000;
    // i points to the index where a new value can be added in front
    // j points to the index where a new value can be added in back
    // i+1 points to the front element;
    // j-1 points to the last element;
    vector<int> vec;  // Declare the vector here without initialization
    
public:
    MyCircularDeque(int k) : vec(5001, -1) {  // Initialize the vector here
        vec[5000] = k;  // Store k in the last element to represent max size
    }
    
    bool insertFront(int value) {
        int k = vec[5000];
        if(j-i-1<k){vec[i]=value; i--; return true;}
        return false;
    }
    
    bool insertLast(int value) {
        int k = vec[5000];
        if(j-i-1<k){vec[j]=value; j++;  return true;}
        return false;
        
    }
    
    bool deleteFront() {
        if(j-i==1){return false;}
        // return false;
        i++; return true;
    }
    
    bool deleteLast() {
        if(j-i==1){return false;}
        // return false;
        j--; return true;
    }
    
    int getFront() {
        if(j-i==1){return -1;}
        // return -1;
        return vec[i+1];
    }
    
    int getRear() {
        if(j-i==1){return -1;}
        // return false;
        return vec[j-1];
    }
    
    bool isEmpty() {
        if(j-i==1){return true;}
        return false;
    }
    
    bool isFull() {
        int k = vec[5000];
        if(j-i-1==k){return true;}
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */