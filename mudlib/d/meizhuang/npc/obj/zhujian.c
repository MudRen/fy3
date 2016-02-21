//Oldsix's 竹剑

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("竹剑",({"zhujian","zhu jian","jian","sword"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("long","青竹削制成的短剑，杀伤力较小。\n");
	set("material","bamboo");
	set("value",500);
	}
	init_sword(10);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

	setup();
}
