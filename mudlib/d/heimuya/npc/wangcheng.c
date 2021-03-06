// wangcheng.c
#include <ansi.h>

inherit NPC;
string do_yaoqing();


void create()
{
	set_name("王诚", ({ "wang cheng","wang"}) );
	set("gender", "男性" );
	set("banghui", "日月教");
	set("bh_rank","风雷堂旗主");
	set("age", 65);
	set("long", "此人身材矮胖，满脸堆笑，其实为人十分狠毒。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
        set("inquiry", ([
		"加入日月教" : (:do_yaoqing:),
        ]));

	set("max_kee", 1000);
	set("max_gin",1000);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 150);
	set("combat_exp", 350000);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("sword",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-jian", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");

	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	setup();
carry_object("/obj/weapon/sword")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
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
	message_vision("$N对$n道："+RANK_D->query_respect(ob)+
	"难道也是慕名来"+YEL"加入日月教"NOR+"的吧。\n",this_object(),ob);
	else
	message_vision("$N大声道：日月神教，攻无不克战无不胜！\n",
	this_object());
}

string do_yaoqing()
{
        object ob;
        string banghui;
        ob=this_player();
        banghui=(string)ob->query("banghui");
        if(! banghui)   {
        if((int)ob->query("have_banghui")<=4)   {
                ob->set_temp("oldsix/target",this_object());
		return "想好了真的要入本教吗？(jiaru wang)";
	}
	else	return "本教不欢迎你这种见异思迁的人。";
	}
	else if(banghui !=(string)query("banghui"))     {
		return "你得先脱离了"+banghui+"！";
	}
	else	return "都是自己弟兄，不用开这种玩笑。";
}


