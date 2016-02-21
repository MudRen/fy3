#include <ansi.h>
inherit NPC;
void chan(); 
void create()
{
        set_name(RED"大蜘蛛"NOR, ({ "zhizhu"}));
        set("race", "野兽");
        set("age", 4);
        set("long",
                "一只全身雪红的大蜘蛛,。\n");
	set("str", 26);
	set("cor", 30);
	set("chat_chance", 40);
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尖嘴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 5);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 5);
        setup();
}
void init()
{
    object ob;
    ::init();
    if (interactive(ob=this_player())&&!is_fighting())
         {  set_leader(ob);
message_vision("$N从嘴里吐出一道长长的白色蛛丝,向$n飞卷而去!\n",this_object(),ob);
    if (random(ob->query("cps"))<16)
           {  message_vision("结果把$N缠个正着,顿时动弹不得!\n",ob);
              ob->start_busy(2);
              kill_ob(ob);
              return;
           }
    else
    message_vision("结果被$N敏捷地躲过,并趁势还击.\n",ob);
    ob->kill_ob(this_object());
    start_busy(1);

          }
}
