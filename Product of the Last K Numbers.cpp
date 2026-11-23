class ProductOfNumbers {
private:
    vector<int> datas;
public:
    ProductOfNumbers() {
        datas.assign(1, 1);
    }
    
    void add(int num) {
        num == 0 ? datas.assign(1, 1) : datas.push_back(datas.back() * num);
    }
    
    int getProduct(int k) {
        return k < datas.size() ? datas.back() / datas.rbegin()[k] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
