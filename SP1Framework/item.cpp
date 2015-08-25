#include "item.h"

#define MAX_ITEMS 10

extern Console console;
extern COORD charLocation;
extern size_t g_map[140][100];
COORD display_inventorysystem;

int display_inventory_row = 0;
int display_inventory_col = 0;
char display_inventoryarr[200][200];
Items Keys[MAX_ITEMS];
Items Gates[MAX_ITEMS];
extern int check_no_of_keys;
extern int check_no_of_gates;
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

void keys_locations( int keyY, int keyX)
{
    Keys[check_no_of_keys].KeysLocation.Y = keyY;
    Keys[check_no_of_keys].KeysLocation.X = keyX;
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
    for ( int h = 0; h < check_no_of_keys; ++h)
    {
        if ( (charLocation.X) == (Keys[h].KeysLocation.X) && (charLocation.Y) == (Keys[h].KeysLocation.Y) )
        {
            Keys[h].collected[h] = true;
        }
    }
    for ( int k = 0; k < check_no_of_keys; ++k)
    {
        if (Keys[k].collected[k] == true)
        {
            collected_keys = true;
            continue;
        }
        else {
            collected_keys = false;
            break;
        }
    }

    //if ( collected_keys == false )
    //{
    //    for ( int i = 0; i < check_no_of_keys; ++i) {
    //        console.writeToBuffer( Keys[i].KeysLocation, "K", 0xF0);
    //    }
    //}
    //else if ( collected_keys == true)
    //{
    //    for ( int i = 0; i < check_no_of_keys; ++i) {
    //        console.writeToBuffer( Keys[i].KeysLocation, " ", 0x1A);
    //    }
    //}
    for ( int i = 0; i < check_no_of_keys; ++i)
    {
        if (Keys[i].collected[i] == true)
        {
            console.writeToBuffer( Keys[i].KeysLocation, " ", 0x1A);
        }
        else
        {
            console.writeToBuffer( Keys[i].KeysLocation, "K", 0xF0);
        }
    }
    
}

void gate_location( int GateY, int GateX)
{
    Gates[check_no_of_gates].KeysLocation.Y = GateY;
    Gates[check_no_of_gates].KeysLocation.X = GateX;
}

void display_gate()
{
    if ( collected_keys == true)
    {
        for ( int j = 0; j < check_no_of_gates; ++j)
        {
            g_map[Gates[j].KeysLocation.Y][Gates[j].KeysLocation.X] = 0;
            console.writeToBuffer(Gates[j].KeysLocation, " ", 0x1A);
        }
    }
    else {
        for ( int i = 0; i < check_no_of_gates; ++i)
        {
            g_map[Gates[i].KeysLocation.Y][Gates[i].KeysLocation.X] = 1;
            console.writeToBuffer(Gates[i].KeysLocation , "G", 0x0C);
        }
    }
}