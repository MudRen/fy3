inherit NPC;
void create()
{
  set_name("温有方",({"wen youfang"}));
  set("age",21);
  set("gender","中性");
  set("mingwang",100);
  set("combat_exp",10000);
  set_skill("unarmed",30);
  set_skill("parry",30);
  set_skill("dodge",30);
  set_skill("force",30);
  set("chat_chance",4);
  set("chat_msg",({
  "温有方道:这些天老是有人到书房来乱翻,讨厌.\n",
  "温有方道:兄弟这几天也很神秘,有时半夜还起来.\n",
  "温有方拿起拂尘打扫起来.\n",
  }));
  set("force",100);
  set("max_force",100);
  set("force_factor",5);
  
  setup();
  add_money("coin",30);
  }
  