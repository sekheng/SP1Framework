#include "item.h"

extern Console console;
extern COORD charLocation;
COORD display_inventorysystem;
COORD multiple_keys_location;
COORD multiple_gates_location;
int display_inventory_row = 0;
int display_inventory_col = 0;
char display_inventoryarr[200][200];
int no_of_keys = 0;
Items Keys;
Items Gates;

void initinventorysystem()
{
    display_inventorysystem.X = 60;
    display_inventorysystem.Y = 11;
    ifstream in_Text;
    in_Text.open("displayInventory_text.txt");
    string text;
    while ( !in_Text.eof() && getline(in_Text, text) )
    {
        display_inventory_col = 0;
        for ( size_t j = 0; j < text.size(); ++j)
        {
            display_inventoryarr[display_inventory_row][display_inventory_col] = text[j];
            ++display_inventory_col;
        }
        ++display_inventory_row;
    }
    in_Text.close();
}

void keys_locations( int &keyY, int & keyX)
{
    multiple_keys_location.Y = keyY;
    multiple_keys_location.X = keyX;
}

void displayinventory( int no_of_items)
{
    display_inventorysystem.Y = 11;
    for ( int i = 0 ; i  < display_inventory_row; ++i)
    {
        display_inventorysystem.X = 60;
        for ( int j = 0; j < display_inventory_col; ++j)
        {
            console.writeToBuffer( display_inventorysystem, display_inventoryarr[i][j], 0x0F);
            display_inventorysystem.X += 1;
        }
        display_inventorysystem.Y += 1;
    }
}

void display_keys()
{   
   console.writeToBuffer( multiple_keys_location, "K", 0xF0);
}

void gate_location( int &GateY, int &GateX)
{
    multiple_gates_location.Y = GateY;
    multiple_gates_location.X = GateX;
}

void display_gate()
{
    console.writeToBuffer( multiple_gates_location, "G", 0x0C);
}