// rou.c
// 97.7.14 by Aug

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("白切肉", ({ "rou" }) );
	set_weight(150);
	if( clonep() ) 
		set_default_object(__FILE__);
	else 
	{
		set("unit", "盘");
		set("value", 10);
		set("food_remaining", 3);
		set("food_supply", 30);
		set("long", "一盘刚切好的白切肉，看着就叫人流口水。\n");
	}
	setup();
}


