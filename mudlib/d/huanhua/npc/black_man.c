inherit NPC;
void create()
{
    set_name("黑老汉",({"oldman","man"}));
    set("gender","男性");
    set("combat_exp",1500);
    set("age",56);
    set("long","脸色黝黑的江上渔民.\n");
    set_skill("unarmed",10);
    set_skill("parry",20);
    setup();
add_money("coin",random(40)+10);
carry_object("/obj/cloth")->wear();
}
int accept_fight(object me)
{
    command("say 老汉的事情多着呢,没空陪你玩!\n");
    return 0;
}