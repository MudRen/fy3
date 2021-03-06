// NPC yupopo.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("余婆婆", ({ "yu popo", "yu", "popo" }));
	set("long",
	    "她是「灵鹫宫」九天九部中昊天部的首领.\n"+
	    "她跟随童姥多年, 出生入死,饱经风霜.\n");
	set("title", "昊天部首领");
	set("gender", "女性");
	set("age", 60);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("kee", 2000);
	set("max_kee", 2000);
	set("gin", 1500);
	set("max_gin", 1500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 50);

	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
        set_skill("sword",100);

        set_skill("tianyu-qijian",100);
	set_skill("liuyang-zhang",100);
	set_skill("yueying-wubu",100);
	set_skill("duzun-gong", 100);

	map_skill("force", "duzun-gong");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "liuyang-zhang");
   	map_skill("sword", "tianyu-qijian");
	create_family("灵鹫宫",2,"弟子");
	setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
      	carry_object("/obj/weapon/sword")->wield();
	add_money("silver",40);
}
