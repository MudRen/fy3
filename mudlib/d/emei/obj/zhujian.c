// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("竹剑", ({ "zhujian","sword" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把精巧的竹剑，虽然没有长剑锋利但它比长剑要轻的多。\n");
		set("material", "steel");
	}
	init_sword(15);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

// The setup() is required.

	setup();
}
