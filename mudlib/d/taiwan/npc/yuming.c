inherit NPC;
void create()
{
      set_name("渔民",({"yuming","fisher","man"}));
      if (random(2)==1) 
      set("gender","男性");
      else set("gender","女性");
      set("age",15+random(50));
      set("str",10+random(20));
      set("combat_exp",1000+random(1000));
      set("chat_chance",2);
      set("chat_msg",({
            "财主说这些海域都是他家祖宗盖房时挖出来的.\n",
            "师爷说既然我们祖祖代代都是张家的仆人,我们也就是张财主的仆人?\n",
            "辛辛苦苦出海打的鱼都要先交个财主!\n",
         }));
     set_skill("dodge",20);
     set_skill("parry",20);
     set_skill("unarmed",20);
     setup();
     carry_object("/obj/cloth")->wear();
     add_money("coin",10+random(20));
}