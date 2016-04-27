#include "FinalProject.h"
#include <sstream>


using namespace std;

roStore::roStore()
{
    //ctor
    root=NULL;
}

///Deletes all the nodes after you quit the game////////////////
void roStore::DeleteAll(storeNode* node)
{
    if (node->leftChild!=NULL)
		DeleteAll(node->leftChild);
	if (node->rightChild!=NULL)
		DeleteAll(node->rightChild);
	///cout<<"Deleting: "<<node->title<<endl;
	delete node;
}
///1/////////////////////////////////////////////////////////



roStore::~roStore()
{
    //dtor
    DeleteAll(root);
}


///ADDs the initial nodes into the tree, we get the items from the text file/////////////////////
void roStore::addMovieNode(std::string title, int attribute, int cost, int quantity)
{
    storeNode* tmp=root;
    storeNode* parent=NULL;
    storeNode* node=new storeNode(title, attribute, cost, quantity);
    node->title=title;
    node->leftChild=NULL;
    node->rightChild=NULL;
    while (tmp!=NULL)
    {
        parent=tmp;
        if (node->title.compare(tmp->title)>0)
            tmp=tmp->rightChild;
        else if (node->title.compare(tmp->title)<0)
            tmp=tmp->leftChild;
    }
    if (root==NULL)
        root=node;
    else if (node->title.compare(parent->title)<0)
    {
        parent->leftChild=node;
        node->parent=parent;
    }
    else
    {
        parent->rightChild=node;
        node->parent=parent;
    }
}
///1//////////////////////////////////////////////////////////////

///Adds the player inventory Initialize///////////////////////////////////////////////////////////////////
void roStore::addPlayerNode(std::string itemName, int itemStats, int itemCost, int itemQuantity)
{
    PlayerNode* tmp=playerRoot;
    PlayerNode* parent=NULL;
    PlayerNode* node=new PlayerNode(itemName, itemStats, itemCost, itemQuantity);
    node->itemName=itemName;
    node->leftChild=NULL;
    node->rightChild=NULL;
    while (tmp!=NULL)
    {
        parent=tmp;
        if (node->itemName.compare(tmp->itemName)>0)
            tmp=tmp->rightChild;
        else if (node->itemName.compare(tmp->itemName)<0)
            tmp=tmp->leftChild;
    }
    if (playerRoot==NULL)
        playerRoot=node;
    else if (node->itemName.compare(parent->itemName)<0)
    {
        parent->leftChild=node;
        node->parent=parent;
    }
    else
    {
        parent->rightChild=node;
        node->parent=parent;
    }
}
///1/////////////////////////////////////////////////////////////////////////////


///Adds the item into the players inventory after buying it from store/////////////
void roStore::addPlayerInventory(std::string itemName){

    PlayerNode* node=playerRoot;
    bool found;
	while (node!=NULL)
	{
		if (node->itemName.compare(itemName)>0)
			node=node->leftChild;
		else if (node->itemName.compare(itemName)<0)
			node=node->rightChild;
		else if (node->itemName==itemName)
        {
            found=true;
            break;
        }
        else
        {
            found=false;
            break;
        }
	}
	if (found==true)
    {
        node->itemQuantity++;

    }

    else if (found==false){
        ///Need to edit this part
        int index=0;
        int number=1;
        int itemStats = 0;
        int itemCost = 0;
        int itemQuantity = 1;
            std::string data2;
            stringstream text(itemName);
            while(getline(text, data2, ','))
            {
                if (number==1)
                {
                    itemName = data2; ///For strings
                    number++;
                }
                else if (number==2)
                {
                    istringstream(data2)>>itemStats;  ///converts number to string
                    number++;
                }
                else if (number==3)
                {
                    istringstream(data2)>>itemCost;

                    number++;
                }

                else if (number==4)
                {
                    istringstream(data2)>>itemQuantity;
                    number=1;
                }
            }


            addPlayerNode(itemName, itemStats, itemCost, itemQuantity);
            index++;
        }


}
///1/////////////////////////////////////////////////////////////////////


///Sells items back to the store///////////////////////////////////
void roStore::sellItem(std::string title)
{
    storeNode* node=root;
    bool found;
	while (node!=NULL)
	{
		if (node->title.compare(title)>0)
			node=node->leftChild;
		else if (node->title.compare(title)<0)
			node=node->rightChild;
		else if (node->title==title)
        {
            found=true;
            break;
        }
        else
        {
            found=false;
            break;
        }
	}

	if (found==true)
    {
        cout<< endl;
        cout<<node->title << " has been sold!"<<endl;
        node->quantity++;
        cout<<"==========="<<endl;
        cout<<"|Item info|"<<endl;
        cout<<"==========="<<endl;
        cout<<"Item: "<<node->title<<endl;
        cout<<"cost: "<<node->cost<<endl;
        cout<<"Quantity: "<<node->quantity<<endl;
        cout<<"==========="<<endl;
        cout<< endl;

    }
    else if (found==false){
        cout<<"Item not found."<<endl;
        cout<<"Please only type in items that are in the list"<<endl;
    }

}
///1////////////////////////////////////////////////////////////////////


///Finds a specific item in the store, giving details about it////////////////
void roStore::findMovie(std::string title)
{
    storeNode* node=root;
    bool found;
	while (node!=NULL)
	{
		if (node->title.compare(title)>0)
			node=node->leftChild;
		else if (node->title.compare(title)<0)
			node=node->rightChild;
		else if (node->title==title)
        {
            found=true;
            break;
        }
        else
        {
            found=false;
            break;
        }
	}
	if (found==true)
    {
        cout<< endl;
        cout<<"==========="<<endl;
        cout<<"Item Info"<<endl;
        cout<<"==========="<<endl;
        cout<<"Item: "<<node->title<<endl;
        cout<<"Attribute: +"<<node->attribute<<endl;
        cout<<"Cost: "<<node->cost<<" gp"<<endl;
        cout<<"Quantity: "<< node->quantity<<endl;
        cout<<"==========="<<endl;
        cout<< endl;
    }

    if (found==false)
        cout<<"Item not found."<<endl;
}
///1//////////////////////////////////////////////////////////


///Buys item from the store/////////////////////////////////////
void roStore::rentMovie(std::string title)
{
    storeNode* node=root;
    bool found;
	while (node!=NULL)
	{
		if (node->title.compare(title)>0)
			node=node->leftChild;
		else if (node->title.compare(title)<0)
			node=node->rightChild;
		else if (node->title==title)
        {
            found=true;
            break;
        }
        else
        {
            found=false;
            break;
        }
	}

	if (found==true && node->quantity!=0)
    {
        cout<< endl;
        cout<<node->title << " has been sold!"<<endl;
        node->quantity--;
        cout<<"==========="<<endl;
        cout<<"Item info"<<endl;
        cout<<"==========="<<endl;
        cout<<"Item: "<<node->title<<endl;
        cout<<"cost: "<<node->cost<<endl;
        cout<<"Quantity: "<<node->quantity<<endl;
        cout<<"==========="<<endl;
        cout<< endl;

    }
    else if (found==true && node->quantity==0)
    {
        cout<< endl;
        cout<< node->title<< " x 0" <<endl;
        cout<< "Unfortunately We Are Out Of " << node->title <<endl;
        cout<< endl;
    }
    else if (found==false){
        cout<<"Item not found."<<endl;
    }

}
///1////////////////////////////////////////////////////////////////////


///Prints out the inventory in the store(Helper)/////////////////////////////////
void roStore::printstoreInventory()
{
    cout<<endl;
    cout<<"========================"<<endl;
    cout<<"Items In The store"<<endl;
    cout<<"========================"<<endl;
    printstoreInventory(root);
    cout<<"========================"<<endl;
    cout<<endl;
}
///1//////////////////////////////////////////////////////////////////


///Prints out inventory////////////////////////////////////////////
void roStore::printstoreInventory(storeNode* node)
{

    if (node->leftChild!=NULL){
        printstoreInventory(node->leftChild);
    }
    if (node->rightChild!=NULL){
        printstoreInventory(node->rightChild);
    }
    cout<< "- " <<node->title<<" x "<<node->quantity<<endl;
}
///1/////////////////////////////////////////////////////////

///Print Player Inventory//////////////////////////////////
void roStore::printPlayerInventory()
{
    cout<<endl;
    cout<<"========================"<<endl;
    cout<<"Items In Your Inventory"<<endl;
    cout<<"========================"<<endl;
    printPlayerInventory(playerRoot);
    cout<<"========================"<<endl;
    cout<<endl;
}
///1////////////////////////////////////////////////////////

///Prints the players Inventory!!!/////////////////////////
void roStore::printPlayerInventory(PlayerNode* node)
{

    if (node->leftChild!=NULL){
        printPlayerInventory(node->leftChild);
    }
    if (node->rightChild!=NULL){
        printPlayerInventory(node->rightChild);
    }
    cout<< "- " <<node->itemName<<" x "<<node->itemQuantity<<endl;
}
///1///////////////////////////////////////////////////////////




