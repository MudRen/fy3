inherit NPC;
void create()
{
  set_name("城卫兵",({"guard"}));
  set("gender","男性");
  set("age",20+random(30));
  set("long","看守城门的士兵\n");
  set("combat_exp",10000);
  
  set_skill("unarmed",40);
  set_skill("dodge",40);
  set_skill("parry",40);
  set_skill("spear",40);
  
  setup();
  carry_object("/obj/weapon/tiespear")->wield();
  carry_object("/obj/std/armor/pijia")->wear();
  add_money("silver",4);
}
  