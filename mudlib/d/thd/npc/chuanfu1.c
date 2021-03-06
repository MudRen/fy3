// chuanfu1.c
// 97.7.13  by Aug

#include "thd.h"
inherit NPC;

void create()
{
	set_name("船夫", ({ "chuan fu" }) );
//	set("title", "江南陆家庄家丁");
	set("gender", "男性");
	set("age", 45);
//	set_race("human");
//	set_level(12);
	set("class","taohua");

	set("long","这是个温顺的哑巴船夫。\n");
	set("rank_info", "船夫");

	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);

	set("max_atman", 600);
	set("atman", 600);
	set("max_force", 600);
	set("force", 600);
	set("max_mana", 600);
	set("mana", 600);

	set("str", 30);
	set("cor", 30);
	set("cps", 30);
	set("spi", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 20);
	set("per", 30);

	set("combat_exp", 50000);
	set("score",10000);
	
      set_skill("unarmed", 20);
	set_skill("force", 13);
	set_skill("parry", 13);
	set_skill("dodge", 13);
	set_skill("sword", 13);
	
//	gain_score("mortal sin", -100);
	
	setup();
	carry_object("/obj/cloth")->wear();
}

int accept_fight(object who)
{
//	do_chat("家丁说道：还请手下留情。\n");
	return 0;
}

int accept_kill(object who)
{
//	do_chat("家丁叫到：你吃了熊心豹胆了，敢在陆家庄杀人！\n");
}


void init()
{
    add_action("do_ask", "ask");
}

void on_board()
{
	object * all,ob,room;
	int i,j;

	ob=this_object();
	i=0;
	all = all_inventory(environment(ob));
	        
	for (j=0; j<sizeof(all); j++) 
	{
		if( all[j]==this_object() ||!all[j]->is_character()) continue;
		{ i=1; }
	}
	
      room = load_object(NOWDIR+"duchuan1");
	room->delete("exits/out");
      room = load_object(NOWDIR+"dukou_thd");
	room->delete("exits/enter");

	if(i==1)
	{
		message("vision", "船夫把踏脚板收了起来，划起桨来，扁舟向波涛汹涌的大海中驶去。\n",room );	
		message_vision("船夫把踏脚板收了起来，划起桨来，扁舟向波涛汹涌的大海中驶去。\n",this_object());	

		if( clonep(this_object()) ) call_out("arrive", 20, 1);
	}
	else
	{
		this_object()->move(NOWDIR+"dukou_thd");
	}	
}

void arrive()
{
	object *all,ob,room;
	int i;

	room = load_object(NOWDIR+"dukou_jx");
      message_vision("船夫把一块踏脚板搭上堤岸，双手一指意思是目的地到了。\n",this_object());
      message("vision", "大海中摇来一艘小船，小船慢慢的停在了港边。船夫把一块踏脚板搭上堤岸。\n",room);

	ob=this_object();
	all = all_inventory(environment(ob));	        
	for (i=0; i<sizeof(all); i++) 
	{
		if( all[i]==this_object() ||!all[i]->is_character()) continue;
		{
			message_vision("$N顺着踏脚板走上岸去。\n",all[i]);
			message("vision",all[i]->name()+"顺着踏脚板走上岸来。\n",room);

			all[i]->move(NOWDIR+"dukou_jx");
		}
	}


      message("vision", "船夫收起踏脚板，慢慢的把小船驶向大海。\n",room);

	this_object()->move(NOWDIR+"dukou_thd");
}

int do_ask(string arg)
{
	object me,room;

	me=this_player();	
	
      if((arg!="chuan fu about out")&&(arg!="chuan fu about 回去"))
	{
		message_vision("船夫脸上露出迷茫的神色，双手比划着什么，显然不知道$N在说什么。\n",me);		
		return 1;
	}

	message_vision("船夫快步走上停在港中的一艘小船，不一会儿就把船摇到$N面前。\n",me);

	load_object(NOWDIR+"dukou_thd")->set("exits/enter", NOWDIR+"duchuan1");
	this_object()->move(NOWDIR+"duchuan1");
	load_object(NOWDIR+"duchuan1")->set("exits/out", NOWDIR+"dukou_thd");

	if( clonep(this_object()) ) call_out("on_board", 10, 1);

      return 1;
}


 