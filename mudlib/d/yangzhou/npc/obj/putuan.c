// Mr.music yangzhou 蒲团


#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("蒲团", ({ "putuan" ,"tuan"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个特制的蒲团，可能能做其他用。\n");
                set("unit", "只");
                set("base_unit", "只");
                set("base_weight", 200);
                set("base_value", 1);
                set("value", 0);
              }
        set_amount(1);
        init_throwing(2);
        setup();
}
