#include "item.h"

extern Console console;
extern COORD charLocation;
extern size_t g_map[200][200];
COORD display_inventorysystem;
COORD Display_Items_You_Need;

int display_inventory_row = 0;
int display_inventory_col = 0;
char display_inventoryarr[200][200];
Items Keys[MAX_ITEMS];
Items Gates[MAX_ITEMS];
extern int check_no_of_keys;
extern int check_no_of_gates;
extern bool onPlate;
int how_Many_keys_types = 0;
int check_numKeys_arr[MAX_ITEMS] = {0};

char *NoItem;
stringstream sos;
stringstream sis;

const WORD colorforGateandKeys[] =
{
    0x0E, 0xF0
};

void initinventorysystem()
{
    display_inventorysystem.X = 100;
    display_inventorysystem.Y = 1;
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
    Display_Items_You_Need.X = 100;
    Display_Items_You_Need.Y = 10;
    NoItem = "THERE ARE NO GATES TO OPEN";
    sis.str("");
    sis << "YOU ARE CLEAR TO PASS THROUGH G";
}

void keys_locations( int keyY, int keyX, int KeyType)
{
    int KeyNum = check_numKeys_arr[KeyType];
    --KeyNum;
    Keys[KeyType].KeysLocation[KeyNum].Y = keyY;
    Keys[KeyType].KeysLocation[KeyNum].X = keyX;
    if ( how_Many_keys_types <= KeyType)
    {
        how_Many_keys_types = KeyType;
        ++how_Many_keys_types;
    }
}

void displayinventory()
{
    Display_Items_You_Need.X = 100;
    Display_Items_You_Need.Y = 8;

    display_inventorysystem.Y = 1;
    for ( int i = 0 ; i  < display_inventory_row; ++i)
    {
        display_inventorysystem.X = 98;
        for ( int j = 0; j < display_inventory_col; ++j)
        {
            console.writeToBuffer( display_inventorysystem, display_inventoryarr[i][j], 0x0F);
            display_inventorysystem.X += 1;
        }
        display_inventorysystem.Y += 1;
    }
    if ( check_no_of_gates == 0 || check_no_of_keys == 0)
    {
        console.writeToBuffer( Display_Items_You_Need, NoItem, 0x0F);
    }
    else
    {
        for ( int i = 0; i < how_Many_keys_types; ++i)
        {
            if ( Keys[i].check_collected_keys == true)
            {
                string itemDisplay = sis.str();
                WORD FINDCOLOR = colorforGateandKeys[i];
                console.writeToBuffer( Display_Items_You_Need, itemDisplay , FINDCOLOR);
            }
            else {
                sos.str("");
                sos << "YOU NEED ";
                int number_OF_KEYS = Keys[i].num_of_Keys_ineachType;
                sos << number_OF_KEYS << " MORE K TO OPEN G";
                string itemDisplay = sos.str();
                WORD FINDCOLOR = colorforGateandKeys[i];
                console.writeToBuffer( Display_Items_You_Need, itemDisplay , FINDCOLOR);
            }
            Display_Items_You_Need.Y += 2;
        }
    }
}

void display_keys()
{   
    for ( int keytypes = 0; keytypes < how_Many_keys_types; ++keytypes) {
        int numKeys = check_numKeys_arr[keytypes];
        for ( int i = 0; i < numKeys; ++i)
        {
            if ( Keys[keytypes].collected[i] != true )
            {
                WORD colour = colorforGateandKeys[keytypes];
                console.writeToBuffer( Keys[keytypes].KeysLocation[i], "K", colour);
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
        if ( Keys[gatetype].check_collected_keys != true) {
            for ( int i = 0; i < check_no_of_gates; ++i)
            {
                WORD colour = colorforGateandKeys[gatetype];
                console.writeToBuffer(Gates[gatetype].KeysLocation[i] , "G", colour);
            }
        }
    }
}

void update_keys()
{
    for ( int keytypes = 0; keytypes < how_Many_keys_types; ++keytypes) {
        int numKeys = check_numKeys_arr[keytypes];
        for ( int h = 0; h < numKeys; ++h)
        {
            if ( (charLocation.X) == (Keys[keytypes].KeysLocation[h].X) && (charLocation.Y) == (Keys[keytypes].KeysLocation[h].Y) )
            {
                Keys[keytypes].collected[h] = true;
                --Keys[keytypes].num_of_Keys_ineachType;
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
		if (Keys[gatetype].check_collected_keys == true)
		{
			for (int j = 0; j < check_no_of_gates; ++j)
			{
				g_map[Gates[gatetype].KeysLocation[j].Y][Gates[gatetype].KeysLocation[j].X] = 0;
			}
		}
		else
		{
			for (int i = 0; i < check_no_of_gates; ++i) {
				g_map[Gates[gatetype].KeysLocation[i].Y][Gates[gatetype].KeysLocation[i].X] = 1;
			}
		}
	}
}

void restart_keys_and_gates()
{
    for ( int i = 0; i < how_Many_keys_types; ++i)
    {
        check_numKeys_arr[i] = 0;
    }
    how_Many_keys_types = 0;
    check_no_of_keys = 0;
    check_no_of_gates = 0;
}

void restart_level_forKeysAndGates()
{
    for ( int i = 0; i < how_Many_keys_types; ++i)
    {
        int numKeys = check_numKeys_arr[i];
        for ( int j = 0; j < numKeys; ++j)
        {
            Keys[i].collected[j] = false;
        }
        Keys[i].check_collected_keys = false;
        Keys[i].num_of_Keys_ineachType = check_numKeys_arr[i];
    }
}

void populate_keyArr( int KeyType)
{
    ++check_numKeys_arr[KeyType];
    Keys[KeyType].num_of_Keys_ineachType = check_numKeys_arr[KeyType];
}