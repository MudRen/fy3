// zhangli.c 掌理道长


inherit NPC;
string ask_me();

void create()
{
	set_name("掌理道长", ({"zhangli"}));
	set("gender", "男性");
	set("age", 22);
	set("long",
		"这是一位年纪很轻的道人，他精明能干，是全真教第四代弟子\n"
		"中出类拔瘁的人物，前辈真人们分派他来掌理全教上下的杂务。\n"
);
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 22);
	set("int", 22);
	set("con", 22);
	set("dex", 22);

	set("kee", 600);
	set("max_kee", 600);
	set("gin", 400);
	set("max_gin", 400);
	set("force", 600);
	set("max_force", 600);
	set("force_factor", 0);
	
	set("combat_exp", 30000);
	set("score", 20000);
	 
	set_skill("force", 60);
	set_skill("xiantian-qigong", 50);    //先天气功
	set_skill("sword", 60);             
	set_skill("quanzhen-jian",60);  //全真剑
	set_skill("dodge", 50);
	set_skill("jinyan-gong", 50);   //金雁功
	set_skill("parry", 60);
	set_skill("unarmed",60);
	set_skill("haotian-zhang", 50);    //昊天掌
	set_skill("literate",50);
	set_skill("daoxuexinde",40);

	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("unarmed", "haotian-zhang");

	create_family("全真教", 4, "弟子");
	
	set("book_count",1);
        set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
		"道德经" : (: ask_me :),
        ]) );

	setup();
	
        carry_object("/obj/weapon/sword")->wield();
	carry_object(__DIR__"obj/grayrobe")->wear();

}


string ask_me()
{
	mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "全真教")
                return RANK_D->query_respect(this_player()) + 
                "与本教毫无瓜葛，你这话可叫我弄不明白了。";
        if (query("book_count") < 1)
                return "你来晚了，道德经已经被人取走了。";
        add("book_count", -1);
        ob = new(__DIR__"obj/daodejing2");
        ob->move(this_player());
        return "好吧，这本「道德经」你拿回去好好研读。";

}

