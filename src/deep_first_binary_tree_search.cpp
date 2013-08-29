#include <iostream>
#include <stack>
#include <queue>
#include <stdlib.h>
using std::endl;
using std::cin;
using std::cout;

typedef struct node {
    int data;
    node *left;
    node *right;
}node;

node *create_tree(int size)
{
    node* nodes = (node *)malloc(sizeof(node)*size);
    for(int i=0; i<size; ++i) {
        nodes[i].data = i;
        int child = i*2+1;
        if(child < size) {
            nodes[i].left = &nodes[child];
        } else {
            nodes[i].left = NULL;
        }
        ++child;
        if(child < size) {
            nodes[i].right = &nodes[child];
        } else {
            nodes[i].right = NULL;
        }
    }
        return nodes;
}

void deep_first_binary_tree_search_no_recursion(node *tree)
{
    std::stack<node *>visited, unvisited;
    unvisited.push(&tree[0]);

    node *current = NULL;
    while(!unvisited.empty()){
        current = unvisited.top();
        unvisited.pop();
        if(current->right)
            unvisited.push(current->right);
        if(current->left)
            unvisited.push(current->left);
        visited.push(current);
        cout<<current->data<<endl;
    }
}
void breadth_first_binary_tree_search_no_recursion(node *tree)
{
    std::queue<node *>visited, unvisited;
    unvisited.push(&tree[0]);
    node *current = NULL;
    while(!unvisited.empty()) {
        current = unvisited.front();
        unvisited.pop();
         if(current->left)
            unvisited.push(current->left);
        if(current->right)
            unvisited.push(current->right);

        cout<<current->data<<endl;
    }
}
void deep_first_binary_tree_search_recursion(node *tree)
{
    if(!tree)
        return;
    cout<<tree->data<<endl;
    deep_first_binary_tree_search_recursion(tree->left);
    deep_first_binary_tree_search_recursion(tree->right);
}

int main(void) 
{
    node *tree = create_tree(10);
    cout<<"deep no recursion:"<<endl;
    deep_first_binary_tree_search_no_recursion(tree);
    
    cout<<"deep recursion:"<<endl;
    deep_first_binary_tree_search_recursion(tree);
    //omit the free action
    
    cout<<"breadth recursion:"<<endl;
    breadth_first_binary_tree_search_no_recursion(tree);

    return 0;
}


