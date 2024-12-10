template<typename Key, typename Val>
class Node
{
private:
    Key key;
    Val val;
    Node* left;
    Node* right;
};

template<typename Key, typename Val>
class BST
{
public:
    static void PreOrder(Node<Key, Val> root);
};

template<typename Key, typename Val>
void BST<Key, Val>::PreOrder(Node<Key, Val> root)
{
     
     
}
