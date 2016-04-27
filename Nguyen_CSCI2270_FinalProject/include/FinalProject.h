#ifndef FINALPROJECT_H
#define FINALPROJECT_H
#include <iostream>

struct storeNode{
    int attribute;
    std::string title;
    int cost;
    int quantity;

    storeNode *parent;
    storeNode *leftChild;
    storeNode *rightChild;

    storeNode(){};

    storeNode(std::string in_title, int in_attribute, int in_cost, int in_quantity)
    {
        title = in_title;
        quantity = in_quantity;
        attribute = in_attribute;
        cost = in_cost;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

};

struct PlayerNode{
    int itemStats;
    std::string itemName;
    int itemCost;
    int itemQuantity;

    PlayerNode *parent;
    PlayerNode *leftChild;
    PlayerNode *rightChild;

    PlayerNode(){};

    PlayerNode(std::string in_title, int in_attribute, int in_cost, int in_quantity)
    {
        itemName = in_title;
        itemQuantity = in_quantity;
        itemStats = in_attribute;
        itemCost = in_cost;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

};

class roStore
{

    public:
        roStore();
        ~roStore();
        void printstoreInventory();
        void printPlayerInventory();
        void sellItem(std::string title);
        void addMovieNode(std::string title, int stats, int price, int quantity);
        void addPlayerNode(std::string itemName, int itemStats, int itemprice, int itemQuantity);
        void findMovie(std::string title);
        void rentMovie(std::string title);
        void addPlayerInventory(std::string itemName);


    protected:

    private:
        void DeleteAll(storeNode * node); //use this for the post-order traversal deletion of the tree
        void printstoreInventory(storeNode* node);
        void printPlayerInventory(PlayerNode* node);
        storeNode* search(std::string title);
        //MovieNode* treeMinimum(MovieNode *node);
        storeNode *root;
        PlayerNode *playerRoot;
};

#endif // MOVIETREE_H
