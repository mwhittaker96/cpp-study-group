#include <memory>
// For now each node will hold an int as data and 2 pointers
// an extension of this problem might be to template the class

class Node
{
public:
    Node(int newData) {m_data = newData;}
    bool isLeaf() { return m_left == nullptr && m_right == nullptr;}
    int GetData() {return m_data;}
    Node* GetLeft() {return m_left.get();}
    Node* GetRight() {return m_right.get();}
    void SetLeft(int newData) {m_left = std::make_unique<Node>(newData);}
    void SetRight(int newData) {m_right = std::make_unique<Node>(newData);}
private:

    int m_data;

    std::unique_ptr<Node> m_left = nullptr;
    std::unique_ptr<Node> m_right = nullptr;

};