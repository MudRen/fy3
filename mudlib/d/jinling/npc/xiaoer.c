// music   yangzhou's 店小二

inherit NPC;

void create()
{
	set_name("店小二", ({ "xiaoer", "xiao", "waiter","xiao er","er" }) );
	set("gender", "男性" );
	set("age", 20);
	set("long",
		"眉清目秀的小伙计，整天笑嘻嘻的，忙得不亦乐乎。\n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

if( !wizardp(ob) )
    {
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "店小二打量了"+this_player()->query("name")+
   "一会，笑道：这位" + RANK_D->query_respect(ob)+ "，可能不是本地人吧？\n");
			break;
		case 1:
			say( "店小二将桌椅仔细擦了擦，说道：这位" + RANK_D->query_respect(ob)
				+ "，请坐请坐。\n");
			break;
                           }
   }
else
  {
  say("店小二满脸堆笑道: 是" + 
  ob->query("name")+RANK_D->query_respect(ob) + "来啦?\n");
  say("店小二塞给"+ob->query("name")+"一枚天山雪莲。\n");
  clone_object(__DIR__"obj/xuelian")->move(ob);
  }
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 100) 
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，楼上有请。\n");

		who->set_temp("rent_paid",1);

// for if back money to who post in wizroom

		return 1;
	}

	return 0;
}
