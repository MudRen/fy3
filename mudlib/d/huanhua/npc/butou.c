inherit NPC;
int ask_name();
void create()
{
    set_name("何昆",({"hekun","butou"}));
        set("shen_type",-1);
    set("gender","男性");
    set("combat_exp",3500);
    set("age",42);
    set("title","捕头");
    set("long","身穿差服,头戴羽翎的捕头.\n");
    set_skill("unarmed",10);
    set_skill("parry",10);
    set("inquiry",([
           "无形":(:ask_name:),
        ]));
       set_skill("dodge",20);
       set_skill("blade",15);
    setup();
add_money("coin",random(40)+10);
carry_object("/obj/cloth")->wear();
carry_object("/d/obj/weapon/blade/dandao")->wield();
}
int ask_name()
{
    command("hehe");
    command("say 不错,我就是无形,无形就是我,到底给你看出来了!\n
          但你马上也活不成了\n");
    kill_ob(this_player());
    return 1;
}
