// Npc: /kungfu/class/shaolin/seng-bing.c
// Date: YZC 96/01/19

inherit NPC;

void create()
{
	set_name("����", ({
		"da shou",
		"da",
		"shou",
	}));
	set("long",
		"����һλ�����Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�\n"
		"����ȴ���൱�ýݣ������ƺ�ѧ��һ���书��\n"
	);


	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("spi", 20);
	set("max_kee", 500);
	set("max_gin", 300);
	set("force", 500);
	set("max_force", 500);
	set("pursuer", 1);
	set("combat_exp", 2000);
	set("score", 1);

	set_skill("force", 25);
	set_skill("hunyuan-yiqi", 25);
	set_skill("dodge", 25);
	set_skill("shaolin-shenfa", 25);
	set_skill("unarmed", 25);
	set_skill("banruo-zhang", 25);
	set_skill("parry", 25);
	set_skill("sword", 25);
	set_skill("damo-jian", 25);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "banruo-zhang");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	setup();
}