inherit NPC;
#include <ansi.h>
void create()
{
    set_name("乾公",({"qian gong"}));
    set("title","["+HIY+"乾坤二奇"+NOR+"]");
    set("age",65);
    set("gender","男性");
    set("long","高大的身躯，足足九尺以上，腰大十围，
臂粗如碗，手中的大铡刀，长过六尺，宽过一尺二寸。\n");
    set("str",45);
    set("max_kee",1500);
    set("kee",1500);
    set("max_force",1400);
    set("force",1400);
    set("force_factor",80);
    set("combat_exp",100000);
    set_skill("dodge",40);
    set_skill("force",80);
    set_skill("blade",80);
    set_skill("unarmed",80);
    set_skill("parry",60);
    setup();
carry_object("/obj/cloth")->wear();
carry_object("/d/sandboy/obj/zhadao")->wield();
  add_money("gold",1);
}
void init()
{
    ::init();

    add_action("do_agree", "yuanyi");
    add_action("do_agree", "agree");
}
int do_agree(string arg)
{
    object me=this_player(), npc=this_object(), ob;
    string myname=me->name(), myrude=RANK_D->query_rude(me);

    if (!me->query_temp("sandboy/to_be_hit_1"))
   return 0;
    me->delete_temp("sandboy/to_be_hit_1");
    set("force", 2*query("max_force"));
    set("force_factor", 100);
    if (!(ob=query_temp("weapon"))
     || ob->query_temp("skill_type") != "blade")
    {
   destruct(ob);
   ob=new("/d/sandboy/obj/zhadao");
   ob->move(npc);
   command("wield blade");
    }
    command("say 哈哈，有胆子！");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
   command("say 嘿嘿，"+myrude+"一家伙都经不住，还是回去多练两年吧！");
   return 1;
    }
    command("say 不错，有点意思，再看这一招！");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
   command("say "+myrude+"能经住我一下子已经不容易了，我早就看出来这第二下子你受不了了！");
   return 1;
    }
    command("say 咦，你小子武功果然不错！");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
   command("say 哈哈，我说"+myrude+"挡不过老子三招吧。");
   return 1;
    }
    me->add_temp("sandboy/可以过去", 1);
    command("say "+myname+"武功不错，老子看得上眼，过去吧。");

    return 1;
}
int accept_fight(object me)
{
    command("say 老子哪有闲情逗你玩，去!去!去!滚一边去!\n");
    return 0;
}
 