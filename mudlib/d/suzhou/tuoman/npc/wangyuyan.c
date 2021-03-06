// guard.c

#include <ansi.h>

inherit NPC;
mapping valid_types = ([
        "unarmed":      "拳脚",
        "sword":        "剑法",
        "blade":        "刀法",
        "stick":        "棍法",
        "staff":        "杖法",
        "throwing":     "暗器",
        "parry":        "招架",
        "dodge":        "轻功",
        "move":         "行动",
		"whip":         "鞭法",
]);

void create()
{
	set_name("王语嫣",({"wang yuyan","wang","yuyan"}));
	set("mingwang",1);
	set("title","人间仙子");
	set("gender","女性");
	set("age",18);
	set("str",20);
	set("per",50);
	set("cor", 30);
	set("cps", 30);
	set("int",30);
	set("con",30);
	set("long",
		"天仙般的人物，直令世人倾倒。\n"
	);
	set("combat_exp",50);
	set("attitude","peace");
	set_skill("parry",10);
	set_skill("dodge",10);
	set_skill("unarmed",10);
	setup();
	carry_object(__DIR__"obj/silk")->wear();
}
void init()
{
object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
		}
//	add_action("do_ask","ask");
}
int do_ask(string str)
{
	string dest,topic,*skill;
	int i,count;
	object me;
	me=this_player();
	if(!str|| sscanf(str, "%s about %s", dest, topic)!=2 )	{
		return 0;
								}
	if(dest!="yuyan") return 0;
	if(me->query("kee")<50||me->query("sen")<50||me->query("gin")<50)	{
		tell_object(me,"你的精气神太差了，还是等会再讨教吧！\n");
		return 1;
	}
	if(!me->query_skill(topic,1))	{
		message_vision("王语嫣对$N说道：你即然不会这门功夫，又让我如何指点呢？\n",me);
		return 1;
					}
	if(!undefinedp(valid_types[topic])) {
		message_vision("王语嫣对$N叹道："+to_chinese(topic)+"是所有"+
		valid_types[topic]+"的基础，还得靠"+RANK_D->query_respect(me)+
		"自己苦练。\n",me);
	return 1;
					}
	if(topic=="force"||SKILL_D(topic)->valid_enable("force"))	{
	message_vision("王语嫣对着$N摇了摇头道："+to_chinese(topic)+
	"只凭看是看不出什么的。\n"+
		"还得由"+RANK_D->query_respect(me)+"自己多练才行啊。\n",me);
	return 1;
	}
	if(topic=="literate"||SKILL_D(topic)->valid_enable("literate"))	{
	message_vision("王语嫣对着$N轻笑道："+to_chinese(topic)+
	"我可是一窃不通，"+
		"看样子你只好找别人了。\n",me);
		return 1;
		}
	if(me->query("potential")-me->query("learned_points")<1)
	{
	message_vision("王姑娘轻笑道：还是去积累点潜能再说吧！\n",me);
	return 1;
	}
	count=0;
	skill=keys(valid_types);
	for(i=0;i<sizeof(skill);i++)	{
		count +=SKILL_D(topic)->valid_enable(skill[i]);
					}
	if (count>0)	{
	message_vision("$N将"+to_chinese(topic)+"在王语嫣面前演练了一翻。\n",me);
	message_vision("王语嫣低声对着$N耳语了一阵。\n",me);
	if(random(me->query_int())>25)	{
		message_vision("$N默默的思索了一阵，似乎有所领悟。\n",me);
	me->improve_skill(topic,random(me->query("int")*10));
					}
	else
		{
			message_vision("$N默默的思索了一阵，但无法领会要绝。\n",me);
		}
	me->receive_damage("sen",50);
	me->receive_damage("kee",50);
	me->receive_damage("gin",50);
	me->set("learned_points",me->query("learned_points")+1);
	return 1;
		}
	message_vision("王语嫣说道：对于"+to_chinese(topic)+
	"这种旁门左道的功夫我没有研究过。\n"+
RANK_D->query_respect(me)+"还是找别人去问一问吧。\n",me);
	return 1;
}
void greeting(object ob)
{
 	if( !ob || environment(ob) != environment() ) return;
	say("只听那少女幽幽地叹了口气：\n"+
		"不知表哥现在何处，是否还记挂着我。\n");
}
