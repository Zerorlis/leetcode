#include <stack>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { s2.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // 当s1空的时候，s2给丢到s1中去
        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        int tmp = s1.top();
        s1.pop();
        return tmp;
    }

    /** Get the front element. */
    int peek() {
        // 当s1空的时候，s2给丢到s1中去
        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        int tmp = s1.top();
        return tmp;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return s1.empty() && s2.empty(); }

private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
