class Segment{
public:
    Segment* left = nullptr,*right = nullptr;
    bool booked = false,lazy = false;
    ~Segment(){
        delete left;
        delete right;
    }
};
class MyCalendar {
public:
    MyCalendar() {root = new Segment;}
    bool book(int startTime, int endTime) {
        if(query(root,0,this->maxSize,startTime,endTime -1)) return false;
        update(root,0,this->maxSize,startTime,endTime -1);
        return true;
    }
    bool query(Segment* node,int l , int r,int targetLeft,int targetRight){
        if(not node or (r < targetLeft or l > targetRight)) return false;
        if(node->booked) return true;
        if(l == r) return node->booked;
        int mid = l + ((r - l) >> 1);
        return query(node->left,l,mid,targetLeft,targetRight) or query(node->right,mid + 1,r,targetLeft,targetRight);
    }
    
    void update(Segment* node,int l ,int r ,int targetLeft,int targetRight){
        if(!node or targetLeft > r or targetRight < l) return;
        if(targetLeft <= l and r <= targetRight){
            node->lazy = true;
            node->booked = true;
            return;
        }
        push_down(node);
        int mid = l + ((r - l )>> 1);
        update(node->left,l,mid,targetLeft,targetRight);
        update(node->right,mid + 1,r,targetLeft,targetRight);
    }

    void push_down(Segment* node){
        if(not node->left) node->left = new Segment();
        if(not node->right) node->right = new Segment();
        if(node->lazy){
            node->left->lazy = node->right->lazy = true;
            node->left->booked = node->right->booked = true;
            node->lazy = false;
        }
    }
private:
    Segment* root;
    const int maxSize = 1e9 + 5;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */