#include <iostream>

using std::cout;
using std::endl;
class Node {
    friend class BST;
    private:
        int time;
        Node *parent; // pointer to parent
        Node *left_c; //pointer to left child node
        Node *right_c; // pointer to right child node
    public:
        Node(){};
        Node(int time, Node *parent, Node *left_c, Node *right_c):time(time),parent(parent),left_c(left_c),right_c(right_c) {};
        ~Node() {};

        bool has_children(){
            if(left_c == nullptr && right_c == nullptr)
                return false;
            else
                return true;
        }
};

class BST{
    private:
        Node *nodes;
        int size;
        int number_of_nodes;
    public:
        BST(){
           size = 100;
           number_of_nodes = 0;
           nodes = new Node[size]; 
        }
        ~BST(){
            delete []nodes;
        }

        bool insert_node(int time){
            //if number_of_nodes == 0 then we are adding the root
            if (number_of_nodes == 0)
                nodes[number_of_nodes].left_c = nullptr;
                nodes[number_of_nodes].right_c = nullptr;
                nodes[number_of_nodes].parent = nullptr;
                nodes[number_of_nodes].time= time;
                number_of_nodes++;
                return true;

            ///get parent node
            Node* parent = search_node(time, nodes);
            //copy
            Node new_node(time, parent,nullptr, nullptr);
            nodes[number_of_nodes] = new_node;
            // attach new node to parent
            if(time < parent->time)
                parent->left_c= (nodes+number_of_nodes);
            if(time > parent->time)
                parent->right_c= (nodes+number_of_nodes);

            number_of_nodes++;
            print_success();
            return true;

        }
        Node* search_node(int time, Node* root)const{ //search_node with the purpose to insert a new one
           //case 1: there is no node
           if(root->left_c == nullptr && root->right_c == nullptr){
                return root;
           }else{
             //case 2  and case 3:  time is smaller or greater than than root->time  
             //left subtre 
             if(time < root->time){ 
                if(!(root->left_c->has_children()))
                    return root->left_c;
                else if(root->left_c->has_children())
                    search_node(time,root->left_c);
            }

            //right subtree
            if(time > root->time){
                if(!(root->right_c->has_children()))
                    return root->right_c;
                else if(root->right_c->has_children())
                    search_node(time, root->right_c);
            }

           } 
            
        }
        void print_failure(){
        }
        void print_success(){
            cout << "SUCCESSFUL" << endl;
            print_tree();
        }
        void print_tree(){
            for(int i=0; i < number_of_nodes; i++){
                cout<< i << " " << nodes[i].time << endl;
            }
        }
};
int main(int argc, char const *argv[])
{
    int time = 56;
    BST requests;
    requests.insert_node(time);
    requests.insert_node(45);
    requests.insert_node(58);
    requests.print_tree();
    return 0;
}