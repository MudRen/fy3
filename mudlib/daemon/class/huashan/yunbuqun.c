inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("岳不群", ({ "yue buqun", "master", "yue" }) );
        set("title", "华山派现任掌门");
        set("nickname", "君子剑");        
	set("gender", "男性");
        set("age", 47);
        set("long",
 "他就是华山派的现任掌门人，江湖上人称“君子剑”的岳不群。他看上去\n"
 "是个和善的中年人，对人总是彬彬有礼，很有一代宗师的风范。\n" );
        set("inquiry", ([
                "紫霞秘籍": "对不起，你来晚了，紫霞秘籍并不在我这里。\n",
                "手令": "手令，你想进我的书房偷东西吗，抓贼啊。"
]) );        
	set("attitude", "peaceful");
        set("str", 28);
        set("int", 28);
        set("spi", 25);
        set("per", 28);
        set("cps", 30);
        set("force", 4500);
        set("max_force", 4500);
        set("force_factor",75);
        set("rank_info/respect", "岳掌门");        
          set("combat_exp",1950000);
        set("score",150000);
        set_skill("unarmed", 130);
        set_skill("sword", 130);
        set_skill("force", 130);
        set_skill("blade", 130);
        set_skill("parry", 130);
        set_skill("dodge", 130);
set_skill("literate", 150);
set_skill("huashan-jianfa",130);
 set_skill("huashan-zhangfa", 130);
set_skill("zixia-shengong", 130);
set_skill("huashan-shenfa", 130);
        map_skill("dodge", "huashan-steps");
        map_skill("unarmed", "huashan-strike");
        map_skill("force", "zixia-shengong");
        map_skill("sword", "huashan-sword");
        create_family("华山派", 13, "掌门人");
        setup();
carry_object("/obj/weapon/sword")->wield();
//        carry_object(__DIR__"obj/cloth")->wear()
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "男性" )
                command("say 我不收女弟子的，姑娘还是另访名师吧。");
        else {
                command("nod");
                command("say " + RANK_D->query_respect(ob) + "日后必成大器 ！\n");                command("recruit " + ob->query("id") );
             }
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
}
