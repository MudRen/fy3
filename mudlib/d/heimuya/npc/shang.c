//shang.c
inherit NPC;

void greeting(object);
void init();
void create()
{
	set_name("桑三娘", ({ "shang sanniang", "shang", "sanniang"}) );
	set("gender", "女性" );
	set("age", 45);
	set("banghui", "日月教");
	set("bh_rank","天香堂长老");
	set("long", "身情古怪，面无丝毫微笑，面容却相当清秀。 \n"
                    );
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 24);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);

	set("max_kee", 1000);
	set("max_gin",1000);
	set("force", 2000);
	set("max_force", 2000);
	set("combat_exp", 350000);
	set("score", 30000);
	set("force_factor", 200);
	set_skill("force", 140);
	set_skill("dodge", 130);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-jian", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	
	map_skill("parry", "taiji-jian");
	map_skill("blade", "taiji-jian");

	setup();
        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/card4");
}

