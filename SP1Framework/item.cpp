#include "item.h"

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
int how_Many_keys_types = 0;

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

void keys_locations( int keyY, int keyX, int KeyType)
{
    Keys[KeyType].KeysLocation[check_no_of_keys].Y = keyY;
    Keys[KeyType].KeysLocation[check_no_of_keys].X = keyX;
    ++Keys[KeyType].num_of_Keys_ineachType;
    if ( how_Many_keys_types <= KeyType)
    {
        how_Many_keys_types = KeyType;
        ++how_Many_keys_types;
    }
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
    for ( int keytypes = 0; keytypes < how_Many_keys_types; ++keytypes) {
        int numKeys = Keys[keytypes].num_of_Keys_ineachType;
        for ( int i = 0; i < check_no_of_keys; ++i)
        {
            if ( Keys[keytypes].collected[i] != true )
            {
                console.writeToBuffer( Keys[keytypes].KeysLocation[i], "K", 0xF0);
            }
        }
    }
}

void gate_location( int GateY, int GateX, int GateType)
{
    Gates[GateType].KeysLocation[check_no_of_gates].Y = GateY;
    Gates[GateType].KeysLocation[check_no_of_gates].X = GateX;
}

void display_gate()
{
    for (int gatetype = 0; gatetype < how_Many_keys_types; ++gatetype)
    {
        int numKeys = Keys[gatetype].num_of_Keys_ineachType;

        if ( Keys[gatetype].check_collected_keys != true) {
            for ( int i = 0; i < check_no_of_gates; ++i)
            {
                console.writeToBuffer(Gates[gatetype].KeysLocation[i] , "G", 0x0C);
            }
        }
    }
}

void update_keys()
{
    for ( int keytypes = 0; keytypes < how_Many_keys_types; ++keytypes) {
        int numKeys = Keys[keytypes].num_of_Keys_ineachType;
        for ( int h = 0; h < check_no_of_keys; ++h)
        {
            if ( (charLocation.X) == (Keys[keytypes].KeysLocation[h].X) && (charLocation.Y) == (Keys[keytypes].KeysLocation[h].Y) )
            {
                Keys[keytypes].collected[h] = true;
            }
        }

        for ( int k = 0; k < numKeys; ++k)
        {
            if (Keys[keytypes].collected[k] == true)
            {
                Keys[keytypes].check_collected_keys = true;
            }
            else {
                Keys[keytypes].check_collected_keys = false;
                break;
            }
        }
    }
}

void update_gates()
{
    for (int gatetype = 0; gatetype < how_Many_keys_types; ++gatetype)
    {
        int numKeys = Keys[gatetype].num_of_Keys_ineachType;
        if ( Keys[gatetype].check_collected_keys == true )
        {
            for ( int j = 0; j < check_no_of_gates; ++j)
            {
                g_map[Gates[gatetype].KeysLocation[j].Y][Gates[gatetype].KeysLocation[j].X] = 0;
            }
        }
        else
        {
            for ( int i = 0; i < check_no_of_gates; ++i) {
                g_map[Gates[gatetype].KeysLocation[i].Y][Gates[gatetype].KeysLocation[i].X] = 1;
            }
        }
    }
}

void restart_keys_and_gates()
{
    for ( int i = 0; i < how_Many_keys_types; ++i)
    {
        Keys[i].num_of_Keys_ineachType = 0;
    }
    how_Many_keys_types = 0;
    check_no_of_keys = 0;
    check_no_of_gates = 0;
}

void restart_level_forKeysAndGates()
{
    for ( int i = 0; i < how_Many_keys_types; ++i)
    {
        int numKeys = Keys[i].num_of_Keys_ineachType;
        for ( int j = 0; j <= numKeys; ++j)
        {
            Keys[i].collected[j] = false;
        }
        Keys[i].check_collected_keys = false;
    }
}