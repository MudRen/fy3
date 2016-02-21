// daodejing-ii.c

inherit ITEM;

void create()
{
	set_name("道德经",({"daodejing","daode jing","jing","book","shu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
	set("long","一本有关道家修炼的书。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
		"name":"daoxuexinde",
		"sen_cost":20+random(11),
		"max_skill":50,
		]) );
	}
}
