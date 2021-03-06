// /d/lingjiu/npc/tbjun.c 钧天部 程清霜
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>

inherit NPC;

string ask_me(string name);
void create()
{
	set_name("程青霜", ({ "cheng qingshuang", "cheng"}));
	set("long",
	    "她是"+HIC"「灵鹫宫」"NOR+"九天九部中钧天部的副首领。\n"+
	    "负责守卫「灵鹫宫」。\n");
	set("title", HIC"钧天部副首领"NOR);
	set("gender", "女性");
	set("age", 20);
        set("shen_type",-1);
	set("attitude", "peaceful");

	set("per", 23);
	set("class", "scholar");
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("kee", 1300);
	set("max_kee", 1300);
	set("gin", 500);
	set("max_gin", 500);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 80);

	set("combat_exp",700000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);


	set_skill("liuyang-zhang",80);
	set_skill("yueying-wubu",80);
        set_skill("duzun-gong", 70);
        set_skill("tianyu-qijian", 70);

	map_skill("force", "duzun-gong");

	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword","tianyu-qijian");

        set("inquiry", ([
		"独尊剑" : (: ask_me, "ljjian1" :),
		"天羽奇剑" : "那是尊主的佩剑！\n",
		"飘渺剑" : "那是四姝姐妹的佩剑\n",
		"剑" : "这里只有独尊剑！\n",
		"武器" : "你需要什么武器呢？\n",
        ]));
	set("wuqi_count", 1);

	create_family("灵鹫宫",4,"弟子");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "strike.zhong" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "sword.san" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
            }) );
	setup();
 	carry_object("/obj/weapon/sword")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        carry_object("/d/lingjiu/obj/jiudai");
        add_money("silver",25);
}
string ask_me(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有这样武器吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("wuqi_count") < 1)
		return "抱歉，你来得不是时候，武器已经发完了。";

	ob = new("/d/lingjiu/obj/" + name);
	ob->move(this_player());

	add("wuqi_count", -1);

	message_vision("程青霜给$N一件" + ob->query("name") + "。\n", this_player());

	return "拿去吧。好好练功，保卫灵鹫宫。";
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
        mapping fam;

        if (interactive(ob)
        && !environment(ob)->query("no_fight")
        && ((fam = ob->query("family")) && fam["family_name"] != "灵鹫宫" ))
        {
                if( !ob->query_temp("warned") ) {
                command("say 尊主有令：外人不得进入灵鹫宫，速速离开！");
                        ob->set_temp("warned", 1);
        }
                else if( ob->query_temp("warned")<5 ) ob->add_temp("warned",1);
                else {
                        command("say 大胆狂徒，竟敢擅闯灵鹫宫！！！\n");
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                }
        }
}
