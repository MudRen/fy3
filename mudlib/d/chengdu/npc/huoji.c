//bye enter

inherit NPC;

void create()
{
        set_name("伙计", ({ "huoji" }));
        set("str", 20);
        set("gender", "男性");
        set("age", 18);
        set("long", "他看起来有几分力气，做事挺勤快的。\n");
        set("combat_exp", 2500);
        set("attitude", "friendly");
        setup();
carry_object("/obj/cloth")->wear();
}
