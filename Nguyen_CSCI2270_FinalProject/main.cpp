#include <iostream>
#include "FinalProject.h"
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    roStore store = roStore();
    ifstream inFile;
    string data;
    inFile.open("roStore.txt");
    if (inFile.good())
    {
        int index=0;
        int number=1;
        while(getline(inFile, data))
        {
            string title; int attribute; int cost; int quantity;
            string data2;
            stringstream text(data);
            while(getline(text, data2, ','))
            {
                if (number==1)
                {

                    title = data2; ///For strings
                    number++;
                }
                else if (number==2)
                {
                    istringstream(data2)>>attribute;  ///converts number to string
                    number++;
                }
                else if (number==3)
                {
                    istringstream(data2)>>cost;

                    number++;
                }

                else if (number==4)
                {
                    istringstream(data2)>>quantity;
                    number=1;
                }

            }
            store.addMovieNode(title, attribute, cost, quantity);
            index++;
        }
    }

    else
        cout<<"file unsuccessfully opened"<<endl;
    inFile.close();


    ifstream newFile;
    string playerData;
    newFile.open("inventory.txt");
    if (newFile.good())
    {
        int playerIndex=0;
        int playerNumber=1;
        while(getline(newFile, playerData))
        {
            string itemName; int itemStats; int itemCost; int itemQuantity;
            string playerData2;
            stringstream plyaerText(playerData);
            while(getline(plyaerText, playerData2, ','))
            {
                if (playerNumber==1)
                {

                    itemName = playerData2; ///For strings
                    playerNumber++;
                }
                else if (playerNumber==2)
                {
                    istringstream(playerData2)>>itemStats;  ///converts number to string
                    playerNumber++;
                }
                else if (playerNumber==3)
                {
                    istringstream(playerData2)>>itemCost;

                    playerNumber++;
                }

                else if (playerNumber==4)
                {
                    istringstream(playerData2)>>itemQuantity;
                    playerNumber=1;
                }

            }
            store.addPlayerNode(itemName, itemStats, itemCost, itemQuantity);
            playerIndex++;
        }
    }

    else
        cout<<"file unsuccessfully opened"<<endl;
    newFile.close();


    int n=0;
    while (n==0)
    {
        int choice;
        cout<<"====== Ragnarok's Store ======\n"
        "1. Store Inventory\n"
        "2. Your Inventory\n"
        "3. Buy Item\n"
        "4. Sell Item\n"
        "5. Item Description\n"
        "6. Quit!"<<endl;

        cin>>choice;
        cin.ignore(1000, '\n');

        switch (choice)
        {
        case 1:
            {
                store.printstoreInventory();
                break;

            }
        case 2:
            {
                store.printPlayerInventory();
                break;

            }
        case 3:
            {
                string title;
                int itemStats;
                int itemCost;
                int itemQuantity;
                cout<<"Enter item you wish to purchase:"<<endl;
                getline(cin, title);
                store.rentMovie(title);
                store.addPlayerInventory(title);
                break;
            }
        case 4:
            {
                string title;
                cout<<"Enter Item To Sell:"<<endl;
                getline(cin, title);
                store.sellItem(title);
                break;
            }
        case 5:
            {
                string title;
                cout<<"Enter item name for description:"<<endl;
                getline(cin, title);
                store.findMovie(title);
                break;

            }
        case 6:
            {
                cout<<"Goodbye!"<<endl;
                n++;
                return 0;
                break;

            }

        }

    }
}





