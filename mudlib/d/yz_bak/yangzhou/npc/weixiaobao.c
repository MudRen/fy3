// music   yangzhou's 韦小宝

inherit NPC;

void create()
{
	set_name("韦小宝", ({ "xiaobao", "wxb","xiao bao" }));
	set("gender", "男性");
	set("age", 18);
	set("long", "扬州城里有名的混混，整天吹牛赌博，不务正业。\n");
	
        set("title","花差花差");
	set("combat_exp", 300);
	set("mingwang", 0);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
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
}

void greeting(object ob)
{
	if(ob->query("age")<=14 && !wizardp(ob))	{
		say("小宝冲着"+ob->query("name")+"点了点头道：“这儿正在召募志愿巫师，不知这位"+	RANK_D->query_respect(ob)+"可有意否？”\n");
	}
	else	{
		switch(random(2))	{
			case 0:	command("welcome "+ob->query("id"));
				break;
			case 1: command("nod "+ob->query("id"));
				break;
		}
	}
	return;
}
