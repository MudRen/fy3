#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("白练分水剑", ({"sword","bailian","fengshui","fenshui","jian"}));
   set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把通体雪白的长剑。\n");
                set("unit", "把");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(30);
        setup();
}

