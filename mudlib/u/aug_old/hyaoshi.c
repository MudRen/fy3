// huang_yaoshi.c
// 97.9.20 by Aug

inherit NPC;
inherit F_MASTER;

void autorecover();
void autoheal();

void create()
{
	set_name("黄药师", ({ "huang yaoshi","huang" }) );
	set("title", "桃花岛岛主");
	set("nickname","东邪");	
	set("gender", "男性");
	set("age", 61);
	set("class","taohua");

	set("long","黄药师是个形相清瘦，风姿隽爽，萧疏轩举，堪然若神的老人。\n");
	set("rank_info/respect", "桃花岛岛主");

	set("max_gin", 3000);
	set("max_kee", 5000);
	set("max_sen", 3000);

	set("max_atman", 3000);
	set("atman", 3000);
	set("max_force", 10000);
	set("force", 10000);
	set("max_mana", 3000);
	set("mana", 3000);

        set("str", 50);
	set("cor", 35);
	set("cps", 35);
	set("spi", 35);
        set("int", 100);
        set("con", 40);
	set("kar", 50);
        set("per", 35);

	set("combat_exp", 1000000);
	set("score",100000);

	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("sword", 200);
        set_skill("literate", 200);
        set_skill("unarmed", 200);

        set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action,"unarmed.tanzhi" :),
                (: autorecover :),
	}) );

        set("chat_chance", 5);
        set("chat_msg",  ({
                (: autoheal :) ,
        }) );

//	set_temp("apply/attack", 100);
//	set_temp("apply/defense", 100);
//	set_temp("apply/armor", 100);
//	set_temp("apply/damage", 100);

      set_skill("suiyu-force",200);
      set_skill("luoying-sword",200);
      set_skill("luoying-strike",200);
      set_skill("bagua-steps",200);
      set_skill("lanhua-finger",200);
//      set_skill("medicine",200);
	
	map_skill("dodge",  "bagua-steps");
	map_skill("unarmed","lanhua-finger");
	map_skill("parry",  "luoying-sword");
	map_skill("force",  "suiyu-force");
        map_skill("sword",  "luoying-sword");
	
	create_family("桃花岛", 1,"岛主");

//	set("family/family_name","桃花岛");
//	set("family/generation",1);
//	set("family/title","掌门人");
//	set("family/priv",-1);

	setup();

	add_money("gold", 10);
	carry_object(__DIR__"obj/changshan")->wear();
        carry_object(__DIR__"obj/baiyuxiao")->wield();
        carry_object(__DIR__"obj/changshan");
        carry_object(__DIR__"obj/changshan");
        carry_object(__DIR__"obj/baiyuxiao");
        carry_object(__DIR__"obj/baiyuxiao");
        carry_object(__DIR__"obj/jiuhua");
        carry_object(__DIR__"obj/jiuhua");
        carry_object(__DIR__"obj/jiuhua");
        carry_object(__DIR__"obj/jiuhua");
        carry_object(__DIR__"obj/jiuhua");
}

void autorecover()
{
        object me,ob;

        me=this_player();

        if( (me->query("force")<300) || (me->query("eff_kee") < (me->query("max_kee")/2)) )
        {
                ob=present("jiuhua",me);
                if(objectp(ob))
                {
                        command("eat jiuhua");
                }
        }

        if(me->query("kee")<me->query("eff_kee"))
        {
                command("yun recover");
	}

        if( !me->query_temp("weapon") )
        {
                ob=present("yuxiao",me);
                if(objectp(ob))
                {
                        command("wield yuxiao");
                }                
        }

        if( !me->query_temp("armor") )
        {
                ob=present("cloth",me);
                if(objectp(ob))
                {
                        command("wear cloth");
                }                
        }

}

void autoheal()
{
	object me;
	int i;

	me=this_object();

        if( me->query("eff_kee") > (me->query("max_kee")/2) )
        {
                for(i=0;(me->query("eff_kee")<me->query("max_kee"));i=i)
                {
                        command("yun heal");
                }
        }

        if(me->query("kee")<me->query("eff_kee"))
        {
                command("yun recover");
	}
}

int accept_fight(object ob)
{
	command("say 那我们就来比试一番。");
	return 1;
}

int accept_kill(object ob)
{
	command("say 你要找死么？");
	return 1;
}

void attempt_apprentice(object me)
{
	object ob;
	int i;

      ob = present("letter", me);
	if(objectp(ob)) 
	{
		destruct(ob);

		message_vision(
"黄岛主接过$N递上的推荐信。
高兴的说：$N是我归云庄的优秀弟子，希望还能再接再厉发扬本派武学。\n",me);

//                me->set("potential",me->query("potential")+300);

	}
	else
	{
		message_vision(
"黄岛主看到$N高兴的说：$N不用引导就能进到这里，真是不可多得的人才啊！\n"
,me);

//                me->set("potential",me->query("potential")+600);         
	}

	message_vision("$N呵呵笑道：我就收下$n作个徒弟吧！\n", this_object(),me);

	command("recruit " + me->query("id") );

	command("chat* haha");
	command("chat 没想到老夫在这迟暮之年又得"+me->name()+"这样的可造之才。");
}

void recruit_apprentice(object me)
{
	if( ::recruit_apprentice(me) )
		me->set("class1", "taohua");
}


