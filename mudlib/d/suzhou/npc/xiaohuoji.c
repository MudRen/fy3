// music   yangzhou's 店小二

inherit KZZNPC;
inherit F_VENDOR;

string query_save_file() { return DATA_DIR + "npc/萧狐齐"; }

void create()
{
#include <kzznpc.h>

	set("long",
		"眉清目秀的小伙计，整天笑嘻嘻的，忙得不亦乐乎。\n");
	set("zhengzhao",2+random(2));
	set("area_name","苏州松鹤楼");
	set("area_file","/d/suzhou/songhelou.c");
	set_temp("apply/defense",10);
	set("attitude", "friendly");
	set("rank_info/respect","小兄弟");

	set_temp("apply/defense",10);
	set("vendor_goods", ([
                "包子" : __DIR__"obj/baozi",
		"鸡腿" :__DIR__"obj/jitui",
		"jiuhu":__DIR__"obj/jiuhu",
		"hulu":__DIR__"obj/hulu",
	]));
	setup();
	carry_object("/obj/std/armor/pikui")->wear();
	carry_object("/obj/std/armor/pixue")->wear();
	carry_object("/obj/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
		message_vision("萧狐齐走上前来，对着$N说道：这位"+
		RANK_D->query_respect(ob)+"楼上请。\n",ob);
			break;
		case 1:
		message_vision("萧狐齐正忙的不可开交，并没有注意到$N进来。\n",ob);
			break;
                           }
}
