//xingren1
inherit NPC;
void create()
{
	set_name("行人", ({ "xinren","ren","woman"}));
	set("gender", "女性");
	set("age", 30);
	set("long", "出来买东西的那家的媳妇\n");
	
 	set("str" ,18);
	set("combat_exp", 300);
//	set("mingwang", -1);
	set("attitude", "peaceful");
	

        set("chat_chance", 10);
        set("chat_msg", ({
	" 行人自言自语:打理一个家可不容易啊!\n",
	"行人自言自语:那死鬼又不知躲到哪里赌钱去了！\n",
		(: random_move :)
}));

//	set_skill("unarmed", 10);
//	set_skill("dodge", 30);
//	set_temp("apply/attack", 5);
	set_temp("apply/defense",15);
	setup();
	carry_object("/obj/cloth")->wear();
        add_money("silver",1); 
}
