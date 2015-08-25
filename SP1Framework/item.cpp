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

<<<<<<< HEAD
void keys_locations( int &keyY, int &keyX)
=======
void keys_locations( int keyY, int keyX, int KeyType)
>>>>>>> 8e50f5c39ec1e2c7b4793b9cb2c3c300e7a7cd53
{
    if ( KeyType == 0)
    {
        Keys[KeyType].KeysLocation[check_no_of_keys].Y = keyY;
        Keys[KeyType].KeysLocation[check_no_of_keys].X = keyX;
    }
    else if ( KeyType == 1 )
    {
        Keys[KeyType].KeysLocation[check_no_of_keys].Y = keyY;
        Keys[KeyType].KeysLocation[check_no_of_keys].X = keyX;
    }
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
    for ( int keytypes =0; keytypes < how_Many_keys_types; ++keytypes) {
        for ( int h = 0; h < check_no_of_keys; ++h)
        {
            if ( (charLocation.X) == (Keys[keytypes].KeysLocation[h].X) && (charLocation.Y) == (Keys[keytypes].KeysLocation[h].Y) )
            {
                Keys[keytypes].collected[h] = true;
            }
        }
        for ( int k = 0; k < check_no_of_keys; ++k)
        {
            if (Keys[keytypes].collected[k] == true)
            {
                Keys[keytypes].check_collected_keys[k] = true;
                continue;
            }
            else {
                Keys[keytypes].check_collected_keys[k] = false;
                break;
            }
        }

    for ( int i = 0; i < check_no_of_keys; ++i)
        {
            if (Keys[keytypes].collected[i] == true)
            {
                console.writeToBuffer( Keys[keytypes].KeysLocation[i], " ", 0x1A);
            }
            else
            {
                console.writeToBuffer( Keys[keytypes].KeysLocation[i], "K", 0xF0);
            }
        }
    }
}

void gate_location( int GateY, int GateX, int GateType)
{
    if ( GateType == 0)
    {
        Gates[GateType].KeysLocation[check_no_of_gates].Y = GateY;
        Gates[GateType].KeysLocation[check_no_of_gates].X = GateX;
    }
}

void display_gate()
{
    for (int gatetype = 0; gatetype < how_Many_keys_types; ++gatetype)
    {
        if ( Keys[gatetype].check_collected_keys[gatetype] == true)
        {
            for ( int j = 0; j < check_no_of_gates; ++j)
            {
                g_map[Gates[gatetype].KeysLocation[j].Y][Gates[gatetype].KeysLocation[j].X] = 0;
                console.writeToBuffer(Gates[gatetype].KeysLocation[j], " ", 0x1A);
            }
        }
        else {
            for ( int i = 0; i < check_no_of_gates; ++i)
            {
                g_map[Gates[gatetype].KeysLocation[i].Y][Gates[gatetype].KeysLocation[i].X] = 1;
                console.writeToBuffer(Gates[gatetype].KeysLocation[i] , "G", 0x0C);
            }
        }
    }
}