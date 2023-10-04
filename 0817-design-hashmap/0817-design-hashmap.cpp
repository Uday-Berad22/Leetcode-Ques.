vector<int> v(1000000);
class MyHashMap {
    unordered_map<int,int> m; 
public:
    MyHashMap() {
        for(int i=0;i<1000000;i++){
            v[i]=0;
        }
    }
    
    void put(int key, int value) {
        m[key]= value;
    }
    
    int get(int key) {
        return m.find(key)==m.end()?-1:m[key];
    }
    
    void remove(int key) {
        if(m.find(key)!=m.end())
        m.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */