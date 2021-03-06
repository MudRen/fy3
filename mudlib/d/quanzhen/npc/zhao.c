// zhao.c 赵志敬


inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("赵志敬", ({"zhao zhijing", "zhao"}));
	set("gender", "男性");
	set("age", 26);
	set("long", 
		"他就是全真教第三代弟子中的好手，王处一的大弟子赵志敬。\n"
		"他相貌端正，但眉宇间似乎隐藏着一丝狡猾的神色。\n"
);
	set("attitude", "friendly");
	set("shen_type",-1);
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 25);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.ju" :),
                (: perform_action, "sword.ju" :),
                (: perform_action, "sword.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
	}));

	set("kee", 1500);
	set("max_kee", 1500);
	set("gin", 800);
	set("max_gin", 800);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 60);
	
	set("combat_exp", 160000);
	set("score", 100000);
	 
	set_skill("force", 80);
	set_skill("xiantian-qigong", 80);    //先天气功
	set_skill("sword", 80);             
	set_skill("quanzhen-jian",80);  //全真剑
	set_skill("dodge", 70);
	set_skill("jinyan-gong", 70);   //金雁功
	set_skill("parry", 80);
	set_skill("unarmed",80);
	set_skill("haotian-zhang", 80);    //昊天掌
	set_skill("literate",60);
	set_skill("daoxuexinde",60);

	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("unarmed", "haotian-zhang");

	create_family("全真教", 3, "弟子");

        set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
        ]) );

	setup();
	
        carry_object("/obj/weapon/sword")->wield();
	carry_object(__DIR__"obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}

