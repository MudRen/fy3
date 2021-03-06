#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string do_yaoqing();
void create()
{
        set_name("江上游", ({"jiang shangyou", "jiang", "shangyou"}));
        set("title", "丐帮五袋弟子");
        set("gender", "男性");
        set("age", 19);
        set("long",
                "这是位丐帮五袋弟子，看来是个英雄人物。\n");
        set("attitude", "peaceful");
        set("class", "beggar");
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("max_kee", 220);
        set("max_gin", 200);
        set("force",250);
        set("banghui","丐帮");
        set("shen_type",1);
        set("max_force", 250);
        set("force_factor",25);
        set("combat_exp", 50000);
        set_skill("force", 50);
        set_skill("huntian-qigong", 50);
        set_skill("unarmed", 50);
        set_skill("xianglong-zhang", 50);
        set_skill("dodge", 50);
        set_skill("xiaoyaoyou", 50);
        set_skill("parry", 50);
        set("inquiry",([
        "加入丐帮":(:do_yaoqing:),
        ]));

        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        create_family("丐帮", 20, "弟子");
        setup();
   carry_object("/obj/cloth")->wear();
   carry_object(__DIR__"obj/zhuzhang")->wield();
}
void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	string banghui;
	if(!ob || environment(ob)!=environment()) return;
	banghui=(string)ob->query("banghui");
	if(! banghui || banghui!=(string)query("banghui"))
	message_vision("$N懒洋洋的对$n道：可是来"+YEL+"加入丐帮"+NOR+"的?\n",
	this_object(),ob);
	else   
	message_vision("$N冲着$n咧嘴笑了笑。\n",this_object(),ob);
}                                                                                
string do_yaoqing()
{
	object ob;
	string banghui;
	ob=this_player();
	banghui=(string)ob->query("banghui");
	if(! banghui)	{
		ob->set_temp("oldsix/target",this_object());
		return "你既然有心加入我丐帮，我就为你引介(jiaru jiang).";
	}
	else if(banghui !=(string)query("banghui"))	{
		return "你既然入了"+banghui+",又想加入我帮，作卧底啊你!";
	}
	else	return "你已是丐帮弟子，还想从头来过啊.";
}
