inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("谢璎", ({ "xie ying","girl", "dizi" }));
	set("age", 16);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("str", 34);
	set("dex", 36);
       set("title","雁荡女弟子");
	set("combat_exp", 90000);
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("force", 120);
	set_skill("luoyan-jianfa", 120);
	set_skill("yuxuan-guizhen", 120);
	set_skill("tianfeng-xuan", 120);
        set("shen_type",1);
	set_skill("tiangang-zhi", 120);
	map_skill("force", "yuxuan-guizhen");
       map_skill("dodge","tianfeng-xuan");
      map_skill("sword","luoyan-jianfa");
       map_skill("parry","tiangang-zhi");
       map_skill("unarmed","tiangang-zhi");
create_family("雁荡派",2,"弟子");
	setup();
	carry_object("obj/weapon/sword")->wield();
	carry_object("obj/cloth")->wear();
}
void attempt_apprentice(object ob)
 {  if (ob->query("gender")=="女性")   {
      if (ob->query_skill("yuxuan-guizhen",1)>50)  {   
 	 command("say " + RANK_D->query_respect(ob) + 
 "，你既然诚心拜我为师,我就收你作个弟子吧！。\n");
        command("recruit " + ob->query("id") );
        return;
   }
    command("say 你的玉玄归真还不到家,先跟我师妹学吧.\n");
    return;
 }	
 else command("say 我可不像他们几个,你是男的耶.\n");
 return;
}
