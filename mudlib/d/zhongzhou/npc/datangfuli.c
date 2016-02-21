// zhongzhou 休闲中心付理
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("大堂经理",({"datang jingli","jingli"}));
	set("gender","女性");
	set("age", 20);
	set("long",
	"这是本休闲中心的大堂付理，专门接待客人。\n");
	set("combat_exp", 100000);
	set_temp("apply/defense",10);
	set_temp("apply/attack",5);
	set("attitude", "friendly");
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

	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
	command("say 里间的小姐个个玲珑剔透，多花点银子也值啊！");
			break;
		case 1:
	command("say 每个房间都有标牌，您可千万不要走错地方哦！");
			break;
                           }
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 5000)
	{
	tell_object(who,CYN"这位老板请进，到里间自然有小姐接待你！\n"NOR);

		who->set_temp("to_girls",1);


		return 1;
	}

	return 0;
}
