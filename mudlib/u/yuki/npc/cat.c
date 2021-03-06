inherit NPC;

void create()
{
        set_name("小白猫", ({ "cat" }));
        set("long","一只娇小的白色长毛小白猫，蓝汪汪的眼睛，神情十分娇柔。\n");
        set("race", "野兽");
        set("age", 2);
        set("int", 30);
        set("kee", 300);
        set("max_kee", 300);
        set("gin", 100);
        set("max_gin", 100);
        set("shen_type", 0);
        set("combat_exp",50000);
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体", "爪子","尾巴" }) );
        set("verbs", ({ "bite","hoof" }) );
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

        setup();
         set("chat_chance",2);
        set("chat_msg", ({
                "小白猫懒洋洋的看了看你，转身去追打刚刚飞过的蝴蝶。\n",
                "小白猫用爪子去捅地上的小石头。\n",
                "小白猫把脑袋趴在地上匍匐前进，似乎发现了什么东西。\n"
        }) );
}

void die()
{
        object ob;
         message_vision(name()+"凄惨地叫了两声，倒在地上 ... \n",this_object());
/*
        ob = new("/u/yuki/npc/corpse");
        ob->move(environment(this_object()));
*/
//          destruct(this_object());
              ::die();
}
