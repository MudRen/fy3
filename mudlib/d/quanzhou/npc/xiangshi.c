// dizi.c

inherit NPC;

void create()
{
	int skill;

	set_name("算命相士", ({ "xiangshi", "suanming"}) );
	set("gender", "男性" );
	set("age", 40+random(30));

	set("combat_exp",30000);
       set_skill("parry",40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
        set("chat_chance", 8);
        set("chat_msg", ({
                "善言祸福吉凶,能知过去未来!\n",
                (: random_move :), 
                "天机不可泄漏.人事怎能妄言.\n",
                (: random_move :), 
                "凭我胸中之学,与汝消难解灾!\n",
                (: random_move :) 
        }) );

set("inquiry",([
"算命":"给钱就算,不论多寡.\n",
]));
	setup();
	carry_object("/obj/cloth")->wear();
            add_money("silver",10);
}
int accept_object(object who,object item)
{ 
   object ob;
       ob=this_object();
      if (item->query("money_id"))
      switch (random(4))
   { case 1:
      message_vision("$N对$n仔细看了看,道:阁下天庭饱满,两耳垂肩,后福无穷哪!\n",ob,who);
      return 1;
     case 2:
          message_vision("$N扳着手指算了半天,挠着后脑勺疑惑
地对$n道:阁下这命,可真是奇哉怪也,山人算不出来!\n",ob,who);
          return 1;
         case 3:
        message_vision("$N闭着眼睛,对$n混身上下一阵乱摸道:我这
摸骨神算是鬼谷绝学,对一般人绝不施展!",ob,who);
         return 1;
         case 4:
         message_vision("$N连叹了三口长气,对$n道:阁下灾星照命,面
带晦纹,看来凶多吉少,还需多加小心!\n",ob,who);
         return 1;
    }
   else
    command("say 山人爱财,聚之有道,这东西你自己保管吧!\n");
return 0;
}
