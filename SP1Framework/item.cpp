#include "item.h"

extern Console console;
extern COORD charLocation;
extern size_t g_map[140][100];
COORD display_inventorysystem;
COORD multiple_keys_location;
int display_inventory_row = 0;
int display_inventory_col = 0;
char display_inventoryarr[200][200];
Items Keys;
Items Gates[10];
int no_of_gates = 0;
bool collected_keys = false;

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
    
    if ( (charLocation.X) == (multiple_keys_location.X) && (charLocation.Y) == (multiple_keys_location.Y) )
    {
        collected_keys = true;
    }
    if ( collected_keys == false )
    {
        console.writeToBuffer( multiple_keys_location, "K", 0xF0);
    }
    else if ( collected_keys == true)
    {
        console.writeToBuffer( multiple_keys_location, " ", 0x1A);
    }
    
}

void gate_location( int &GateY, int &GateX)
{
    Gates[no_of_gates].KeysLocation.Y = GateY;
    Gates[no_of_gates].KeysLocation.X = GateX;
    ++no_of_gates;
}

void display_gate()
{
    if ( collected_keys == true)
    {
        for ( int j = 0; j < no_of_gates; ++j)
        {
            g_map[Gates[j].KeysLocation.Y][Gates[j].KeysLocation.X] = 0;
            console.writeToBuffer(Gates[j].KeysLocation, " ", 0x1A);
        }
    }
    else {
        for ( int i = 0; i < no_of_gates; ++i)
        {
            g_map[Gates[i].KeysLocation.Y][Gates[i].KeysLocation.X] = 1;
            console.writeToBuffer(Gates[i].KeysLocation , "G", 0x0C);
        }
    }
}