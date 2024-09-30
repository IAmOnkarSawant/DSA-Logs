class CustomStack {
public:
    vector<int>st;
    int max_size;
    int top;

    CustomStack(int maxSize) 
    {
        max_size = maxSize;
        st.resize(max_size);
        top = -1;
    }
    
    void push(int x) 
    {
        if(top == max_size-1)
            return;
        st[++top] = x;
    }
    
    int pop() 
    {
        if(top == -1)
            return -1;
        return st[top--];
    }
    
    void increment(int k, int val) 
    {
        if(top+1 <= k)
            k = top+1;
        
        // vector<int>temp(st.begin(), st.begin()+top+1);
        for(int i = 0; i < top+1; i++)
        {
            if(i < k)
                st[i] = st[i] + val;
            else
                st[i] = st[i];
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */