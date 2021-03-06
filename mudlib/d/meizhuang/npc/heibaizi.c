// master.c

inherit NPC;
inherit F_MASTER;
int do_ask();
void create()
{
	object ob;
	set_name("黑白子",({"heibai zi","heibaizi","zi"}));
	set("nickname","二庄主");
        set("gender", "男性" );
	set("age",40);
        set("str", 27);
        set("cor", 30);
        set("cps", 27);
	set("mingwang",1);
        set("int", 24);
    set("max_kee",1000);
    set("eff_kee",1000);
    set("kee",1000);
    set("max_sen",500);
    set("eff_sen",500);
    set("sen",500);
    set("max_gin",500);
    set("eff_gin",500);
    set("gin",500);
	set("key",1);
	        set("inquiry",([
		"内室":	(: do_ask :),
	]));
        set("max_force", 1500);
        set("force", 1500);
	set_skill("foxuexinde",80);
	set_skill("daoxuexinde",80);
	set("force_factor",80);

	set("rank_info/respect","二庄主");

        set("long",
                
	"脸色泛白，使人感到一阵凉意。\n");

	create_family("孤山梅庄",1,"庄主");
	set("title","孤山梅庄");

	set("combat_exp",800000);
        set("score", 200000);


	set_skill("throwing",150);
	set_skill("unarmed",150);
	set_skill("parry",150);
	set_skill("dodge",150);
	set_skill("force",150);
	set_skill("literate",100);
	set_skill("xuantian-neigong",150);
	set_skill("xuantian-bu",150);
	set_skill("xuantian-quan",150);
	set_skill("mantianxing",150);
	map_skill("unarmed","xuantian-quan");
	map_skill("force","xuantian-neigong");
	map_skill("dodge","xuantian-bu");
	map_skill("throwing","mantianxing");
	map_skill("parry","mantianxing");
        setup();
	ob=carry_object(__DIR__"obj/weiqizi");
	ob->set_amount(200);
	ob->wield();
	carry_object(__DIR__"obj/sipao")->wear();
	add_money("gold",3);
}

void attempt_apprentice(object ob)
{
	if(ob->query_skill("xuantian-neigong",1)<50)	{
		command("say 这位"+RANK_D->query_respect(ob)+"的「玄天内功」还不够熟练啊。\n");
		return;
	}
        command("say 很好，" + RANK_D->query_respect(ob) + 
"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
			ob->set("class","xiake");
}
int do_ask()
{
	object me,key;
	me=this_player();
	if(me->query("family/family_name")!="孤山梅庄")	{
		command("sigh");
		command("say 这是本庄的私事，实不足为外人道也。");
		return 1;
	}
	if(me->query("family/master_id")!="heibai zi")	{
		command("sneer");
		command("say 你不是"+me->query("family/master_name")+"的好徒弟吗？来问我干什么！");
		return 1;
	}
	if(!me->query_temp("oldsix_flag/ask"))	{
		command("dunno");
		say("说罢，黑白子眼珠乱转不知在想些什么。\n");
		return 1;
	}
	if(query("key")==0)	{
		command("say 你来的太迟了，我已把东西给别人了。");
		say("说完之后，回过头去不再理你了。\n");
		return 1;
	}
	if(random(me->query_kar())>20)	{
		command("sigh");
		command("say 那好吧，你可要替为师保密啊。");
		tell_object(me,"说罢，黑白子从怀中掏出把钥匙交给了你。\n");
		key=new(__DIR__"obj/yaoshi.c");
		key->move(me);
	set("key",0);
		return 1;
	}
	say("黑白子口中吱吱唔唔，也不知说些什么。\n");
	return 1;
}
