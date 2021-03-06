// /NPC fumy.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("符敏仪", ({ "fu mingyi", "fu"}));
	set("long",
	    "她是「灵鹫宫」九天九部中阳天部的首领.\n"+
	    "她号称「针神」.\n");
	set("title", "阳天部首领");
	set("gender", "女性");
	set("nickname", HIR "针神" NOR);
	set("age", 20);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("kee", 800);
	set("max_kee", 800);
	set("gin", 500);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);

	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	set_skill("liuyang-zhang",80);
	set_skill("yueying-wubu",80);
	set_skill("duzun-gong", 70);
	set_skill("tianyu-qijian",70);

	map_skill("force", "duzun-gong");
        map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword","tianyu-qijian");
	create_family("灵鹫宫",3,"弟子");
	setup();

        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/obj/weapon/sword")->wield();
        add_money("silver",20);
}

