inherit NPC;
void create()
{
    set_name("秤千金",({"chen","chenqianjin"}));
        set("shen_type",-1);
    set("gender","男性");
    set("title","金银钱庄管家");
    set("combat_exp",4000);
    set("age",52);
    set("str",25);
    set("long","铁腕神魔傅天义的手下.\n");
    set_skill("parry",20);
    set_skill("dodge",20);
    set_skill("unarmed",20);
    set_skill("force",25);
    set_skill("hammer",40);
    setup();
add_money("silver",2);
carry_object(__DIR__"obj/suanpan")->wield();
}
