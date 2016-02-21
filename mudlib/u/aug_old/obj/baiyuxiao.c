// baiyuxiao.c                
// 97.7.18 by Aug

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIW"玉箫"NOR, ({ "yuxiao", "xiao" }) );
	set_weight(3000);

	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "把");
		set("long", HIW"这是一把通体洁白的玉箫，这是萧中极品，用它吹出的曲子也特别的动听。\n"NOR);
		set("value", 12000);		
		set("material", "steel");
		set("sing_level",9);
		set("can_sing","yes");
	}
	init_sword(50);

	set("wield_msg", HIW"$N「唰」地一声从衣领中抽出一把$n"+HIW+"握在手中。\n"NOR);
	set("unwield_msg", HIW"$N将手中的$n"+HIW+"插回衣领。\n"NOR);

	setup();
}
