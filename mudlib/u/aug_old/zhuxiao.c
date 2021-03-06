// zhuxiao.c                
// 97.7.18 by Aug

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(GRN"竹萧"NOR, ({ "zhuxiao", "xiao" }) );
	set_weight(500);

	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "把");
		set("long", GRN"这是一把用竹子做成的竹萧。\n"NOR);
		set("value", 100);		
		set("material", "bamboo");
		set("sing_level",1);
		set("can_sing","yes");
	}
	init_sword(15);

	set("wield_msg", GRN"$N「唰」地一声从衣领中抽出一把$n"+GRN+"握在手中。\n"NOR);
	set("unwield_msg", GRN"$N将手中的$n"+GRN+"插回衣领。\n"NOR);

	setup();
}
