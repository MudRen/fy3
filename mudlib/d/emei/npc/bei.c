// bei.c 贝锦仪

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("贝锦仪", ({ "bei jinyi","bei","jinyi"}));
        set("long",
                "她是峨嵋派的第四代俗家弟子。\n");
        set("gender", "女性");
        set("age", 21);
        set("attitude", "peaceful");
        set("mingwang", 1000);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);

        set("max_kee", 1000);
        set("max_gin", 500);
        set("force", 1500);
        set("force", 1500);
        set("force_factor", 15);
        set("max_force", 1500);
        set("inquiry",([
            "倚天剑"  : "从昆仑回来后,师傅就把剑传给周师妹了.。",
            "周师妹"  : "周师妹在九老仙府修习本派上乘武功.\n",
            "九老仙府":"我在本派这么多年,只知道有这个地方,不知在哪.\n",
        ]));

        set("combat_exp", 150000);
        set("score", 1000);
	set_skill("unarmed",50);
        set_skill("parry", 50);
        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("sword", 60);
        set_skill("sixiang-zhang", 60);
        set_skill("anying-fuxiang", 85);
        set_skill("huifeng-jian", 60);
        set_skill("emei-xinfa", 80);
        map_skill("force","emei-xinfa");
        map_skill("dodge","anying-fuxiang");
        map_skill("unarmed","sixiang-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");

        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/ni-cloth")->wear();
        carry_object("/obj/armor/ni-xie")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("combat_exp") > 10000) {
                command("say 我峨嵋注重清修，对弟子要求能忍受寂寞。");
                command("say 在江湖阅历方面，" + RANK_D->query_respect(ob) +
                        "经历丰富，是否能在峨嵋修道？");
                return;
        }
        if ((int)ob->query("mingwang") < 0) {
                command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
