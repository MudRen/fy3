// for 南宫

#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("碧水剑", ({ "bishuijian", "jian", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一口断金削铁的宝剑，它是上好的乌金煅制而成的\n");                       
                set("value", 8000);
                set("material", "steel");
                set("weapon_prop/personality", 15);
                set("wield_msg", "$N「唰」的一声抽出一柄寒光闪闪的$n握在手中。\n
");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(50);
        setup();
}
