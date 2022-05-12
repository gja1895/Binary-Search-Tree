//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Grant Allen
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

// Internal structure for tree node
struct Node {
    Bid bid;

    // create the key for the given bid
    unsigned int key = hash(atoi(bidId.c_str()));
    Node* node = &(nodes.at(key));

    // Aren't these two going to be required even though we aren't suppoed to 
    // Change anything up here?
    Node* left;
    Node* right;

    // if entry found for the key
    if (node != nullptr && node->key != UINT_MAX
            && node->bid.bidId.compare(bidId) == 0) {
        return node->bid;
    }

    // if no entry found for the key
    if (node == nullptr || node->key == UINT_MAX) {
        return bid;
    }

    while (node != nullptr) {
        // if the current node matches, return it
        if (node->key != UINT_MAX && node->bid.bidId.compare(bidId) == 0) {
            return node->bid;
        }
        node = node->next;
    }

    return bid;

};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    Node* removeNode(Node* node, string bidId);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    // FixMe (1): initialize housekeeping variables
    //root is equal to nullptr
    root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    // FixMe (2): In order root
    // call inOrder fuction and pass root 
    inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
    // FixMe (3): Post order root
    // postOrder root
    postOrder(root);
    
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
    // FixMe (4): Pre order root
    // preOrder root
    preOrder(root);
}

/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Bid bid) {
    // FIXME (5) Implement inserting a bid into the tree
    // if root equarl to null ptr
    if (root == nullptr)
    {
        // root is equal to new node bid
        root = new Node;
    }
    
    // else
    else
    {
        // add Node root and bid
        addNode(root, bid);
    }
}

/**
 * Remove a bid
 */
void BinarySearchTree::Remove(string bidId) {
    // FIXME (6) Implement removing a bid from the tree
    // remove node root bidID
    removeNode(root, bidId);   
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(string bidId) {
    // FIXME (7) Implement searching the tree for a bid
    // set current node equal to root
    Node* currentNode = root;
    
    // keep looping downwards until bottom reached or matching bidId found
    while (currentNode != nullptr)
    {
        if (currentNode->bid.bidId == bidId)
        {
            // if match found, return current bid
            return currentNode->bid;
        }
        
        // if bid is smaller than current node then traverse left
        if (currentNode->bid.bidId < bidId)
        {
            currentNode = currentNode->left;
        }
        
        // else larger so traverse right
        else
        {
            currentNode = currentNode->right;
        }
    }
        

        
        
    Bid bid;
    return bid;
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
    // FIXME (8) Implement inserting a bid into the tree
    // if node is larger then add to left
    if (node->key > root->key)
    {
        // if no left node
        if (root->left == nullptr)
        {
            // this node becomes left
            root->left = node;
        }
        // else recurse down the left node
        else
        {
            addNode(root->left, bid);
        }
    }
    // else
    else
    {
        // if no right node
        if (root->right == nullptr)
        {
            // this node becomes right
            root->right = node;
        }
        //else
        else
        {
            // recurse down the left node
            addNode(root->right, bid);
        }
    }    
}
void BinarySearchTree::inOrder(Node* node) {
      // FixMe (9): Pre order root
      //if node is not equal to null ptr
      if (node != nullptr)
      {
          //InOrder not left
          // it says not left but the other says right???
          inOrder(node->left);

          //output bidID, title, amount, fund
          cout << "bidID: " << node->bid.bidId << endl;
          cout << "Title: " << node->bid.title << endl;
          cout << "Amount: " << node->bid.amount << endl;
          cout << "Fund: " << node->bid.fund << endl;

          //InOrder right
          inOrder(node->right);
      }
}
void BinarySearchTree::postOrder(Node* node) {
      // FixMe (10): Pre order root
      //if node is not equal to null ptr
      if (node != nullptr)
      {
          //postOrder left
          postOrder(left);
          
          //postOrder right
          postOrder(right);
          
          //output bidID, title, amount, fund
          cout << "bidID: " << node->bid.bidId << endl;
          cout << "Title: " << node->bid.title << endl;
          cout << "Amount: " << node->bid.amount << endl;
          cout << "Fund: " << node->bid.fund << endl;
      }
      

}

void BinarySearchTree::preOrder(Node* node) {
      // FixMe (11): Pre order root
      //if node is not equal to null ptr
      if (node != nullptr)
      {
          //output bidID, title, amount, fund
          cout << "bidID: " << node->bid.bidId << endl;
          cout << "Title: " << node->bid.title << endl;
          cout << "Amount: " << node->bid.amount << endl;
          cout << "Fund: " << node->bid.fund << endl;
          
      }
      //postOrder left
      // Shouldn't this preOrder left and right instead?
      // then we would call preOrder instead of postOrder?
      postOrder(node->left);

      //postOrder right     
      postOrder(node->right);
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
    return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, BinarySearchTree* bst) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bst->Insert(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
        bidKey = "98109";
    }

    // Define a timer variable
    clock_t ticks;

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst;

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bst = new BinarySearchTree();

            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(csvPath, bst);

            //cout << bst->Size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bst->InOrder();
            break;

        case 3:
            ticks = clock();

            bid = bst->Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
            	cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 4:
            bst->Remove(bidKey);
            break;
        }
    }

    cout << "Good bye." << endl;

	return 0;
}
