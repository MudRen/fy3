//qiying
inherit NPC;

void create()
{
	set_name("弃婴", ({ "qiying" ,"kid" }));
	set("gender", "男性");
	set("age", 3);
	set("long",
		"不知是谁家小姐的私生子，不要了丢在街上。\n");
 	set("combat_exp", 5);
	set("attitude", "friendly");
	setup();
}
