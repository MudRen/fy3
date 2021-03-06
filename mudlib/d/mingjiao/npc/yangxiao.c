// YangXiao.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;

string ask_me();
string ask_ling();

void create()
{
    set_name("杨逍", ({"yang xiao","yang","xiao",}));
	set("long",
        "他是一位中年书生，身穿白布长袍。\n"
        "他相貌俊雅，只是双眉略向下垂，嘴边露出几条深深的皱纹，不免略带衰老凄苦\n"
        "之相。他不言不动，神色漠然，似乎心驰远方，正在想什么事情。\n"
	);

	set("banghui","明教");
	set("bh_rank","光明左使");
	set("level",11);
	set("gender", "男性");
	set("attitude", "peaceful");
	
	set("age", 42);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_kee", 3500);
	set("max_gin", 1500);
	set("force", 3000);
	set("max_force", 3000);
       set("force_factor",90);
      set("combat_exp",800000);
    set("score",20000);

        set_skill("force",190);
        set_skill("sanyang-shengong",190);
         set_skill("dodge",190);
         set_skill("tianlong-bu",190);
	set_skill("unarmed",190);
	set_skill("fengyun-shou", 190);
        set_skill("parry",190);
       set_skill("qiankundanuoyi",100);
	set_skill("literate", 150);


       map_skill("force", "sanyang-shengong");
	map_skill("unarmed", "fengyun-shou");
       map_skill("parry","qiankundanuoyi");
      map_skill("dodge","tianlong-bu");


	set("inquiry", 
	([
//        	"光明圣火阵"	: (: ask_me :),
//        	"铁焰令"     	: (: ask_ling :)
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform qianlibingfeng") :),
	}) );

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}


string ask_ling()
{
	mapping party, skl; 
	string *sname;
	object ob;
	int i;
	
	if ( !(party = this_player()->query("party")) || party["party_name"] != HIG "明教" NOR )
		return RANK_D->query_respect(this_player()) + "与本教素无来往，不知此话从何谈起？";

	skl = this_player()->query_skills();
	sname  = sort_array( keys(skl), (: strcmp :) );

	for(i=0; i<sizeof(skl); i++) 
	{
		if (skl[sname[i]] < 30) 
		return RANK_D->query_respect(this_player()) + 
		"功力不够，不能领取铁焰令。";
	}

	ob = new("d/mingjiao/obj/tieyanling");
	ob->move(this_player());
	message_vision("$N要得一面铁焰令。\n",this_player());

	return "好吧，凭这面铁焰令，你可自由向你的尊长挑战。";

}

int recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：你我非亲非故，"+
                RANK_D->query_self(this_object())+"如何敢当。\n");
	if(ob->query("score")<2500)
                return notify_fail(query("name")+"道：你还是多为本教做些实事吧。
\n");
        return 1;
}

