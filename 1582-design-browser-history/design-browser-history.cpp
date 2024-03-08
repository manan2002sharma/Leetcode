struct Node{
    Node(string x){
        url=x;
        next=nullptr;
        prev=nullptr;
    }
    string url;
    Node* next;
    Node* prev;
};

class BrowserHistory {
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr= new Node(homepage);
    }
    
    void visit(string url) {
        curr->next=new Node(url);
        curr->next->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(curr->prev&&steps>0){
            curr=curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next&&steps>0){
            curr=curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */