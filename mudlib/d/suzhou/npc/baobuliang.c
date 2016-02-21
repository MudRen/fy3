// woodcutter.c

inherit NPC;

void create()
{
	set_name("包不靓",({"bao buliang","bao","buliang"}));
	set("gender","女性");
	set("age",12);
	set("long","包不同的小闺女，是包庄主的掌上明珠。\n");
	set_skill("sword",40);
	set_skill("dodge",40);
	set("per",30);
	set("combat_exp",9000);
	set_temp("apply/attack",30);
	set("mingwang",1);
	set_temp("apply/defense",40);
	set_temp("apply/damage",10);
	set("str",15);
	setup();
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	if(ob->query("gender")=="女性")	{
	message_vision("包不靓跑上前来握住$N的手说道：“你是来和我玩的吗？”\n",ob);
	}else
	message_vision("包不靓撅着嘴对$N道：“干嘛没事老往人家屋子里钻呀！”\n",ob);
}
