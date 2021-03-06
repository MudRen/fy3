// music   yangzhou's 李逵
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("李逵", ({ "likui", "li", "li kui" }) );
	set("gender", "男性" );
	set("age", 40);
        set("title","赌场保镖");
	set("long",
		"李逵瞪了你一眼，冷笑了一声。\n");
	set("mingwang", -10000);
	set("nickname", HIR "黑面神"  NOR);
	set("area_name","赌场");
	set("combat_exp", 580000);
	set("money_need",10000);
        set("str", 50);
        set("cps",50);
        set("cor",50);
        set("max_kee",1200+random(2000));
        set("max_force",1000+random(1000));
        set("force",1000+random(1000));
        set("force_factor",50+random(100));
        set_skill("unarmed",100+random(120));
        set_skill("dodge",100+random(120));
        set_skill("parry",100+random(120));
        set_skill("force",120+random(100));
        set_skill("axe",200);
        set_skill("miejue-fu",150+random(80));
        set_skill("shaolin-shenfa",100+random(120));
        set_skill("huntian-qigong",120+random(100));
        map_skill("dodge","shaolin-shenfa");
        map_skill("parry","miejue-fu");
        map_skill("axe","miejue-fu");
        map_skill("force","huntian-qigong");

        create_family("梁山", 1, "豪杰");
	setup();
        carry_object("/obj/weapon/banfu")->wear();
        carry_object("/d/yeyangzai/npc/obj/wujinfu")->wield();
        carry_object("/d/yeyangzai/npc/obj/jinsijia")->wear();
	add_money("gold", 2);
}
void init()
{
        object ob,area;
        area=new("/obj/area");
	area->create(query("area_name"));
        set("banghui",(string)area->query("banghui"));
        destruct(area);
	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_ask","ask");
}
int do_ask(string str)
{
	string banghui;
	object me;
	string sb,sth;
	if(! str)	return 0;
	me=this_player();
	if(! living(me))	return 0;
	if(sscanf(str,"%s about %s",sb,sth)!=2)	return 0;
	if(sb!=this_object()->query("id"))	return 0;
	if(sth!="规矩")			return 0;
	banghui=(string)me->query("banghui");
        if(! banghui || query("banghui")!=banghui)   {
		if(me->query_temp("have_asked"))	{
		message_vision("$N一瞪眼道："+me->query("name")+
		"！问个没完没了，分明是不想掏钱，让我送你去鬼门关再问吧！\n",
		this_object());
		me->delete_temp("have_asked");
		kill_ob(me);
		me->fight_ob(this_object());
		return 1;
		}
		command("hehe");
		message_vision("$N说道：便宜你了"+me->query("name")+
		"就付(pay)我一两黄金吧。\n",this_object());
		me->set_temp("have_asked",1);
		return 1;
	}
	message_vision("$N拍了拍$n的肩膀道：都是帮中兄弟，进赌场赌钱免费。\n",this_object(),me);
	return 1;
}

void greeting(object ob)
		{
	string banghui;			
	if( !ob || environment(ob) != environment() ) return;
	banghui=(string) ob->query("banghui");
        if(! banghui || query("banghui")!=banghui)   {
		say("赌场的规矩你懂不懂？\n");
		return;
		}
	command("say 这位"+RANK_D->query_respect(ob)+"，帮主身体可好？\n");
        command("guard weichunhua");
	return;
}                        
void attempt_apprentice(object ob)
{
		if((int) ob->query("force_factor") < 150)
	{
	 message_vision("李逵既不属于任何门派，也没有开山立派，不能拜师。
\n",
        this_object());
                return;
        }
        
       if( random(10) || random((int)ob->query("kar")) <  25 || query("already"))
	{
	message_vision("$N大笑说道：不要开玩笑，我可不想误人子弟。你想做梁山好汉还要多加磨练。\n",
	this_object());
                return;
        }
        command("chat* laugh");
        command("chat 想不到现在还有人愿意当土匪。");
        command("recruit " + ob->query("id"));
                ob->set("class", "herosim");        

}


