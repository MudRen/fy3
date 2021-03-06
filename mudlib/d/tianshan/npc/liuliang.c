inherit NPC;
void create()
{
   set_name("流浪者",({"liulang zhe"}));
   set("gender","男性");
   set("age",34);
   set("long","满鬓风霜的流浪人,弹起曲子,唱着歌儿.\n");
   set("combat_exp",200);
   set_skill("dodge",20);
   set_skill("hammer",20);
   set_skill("unarmed",20);
   set("chat_chance",5);
   set("chat_msg",({
   "流浪者弹起马头琴,悠远的琴声在草原上飘过.\n",
   "圣峰的冰川象大河倒挂，你听那流水浮动轻轻的响
   ——象是姑娘的巧手弹起了东不拉。
   她在问那流浪的旅人：你还要攀过几座冰山，经历几许风砂？
   啦啦.......
   流浪的旅人呀，草原的兀鹰也不能终日盘旋不下，
   你们尽是走呀，走呀，走呀...
   要走到那年那月，才肯停下你们的马？\n",
   }));
   setup();
   carry_object(__DIR__"obj/matouqin.c")->wield();
   carry_object(__DIR__"obj/zangpao.c")->wear();
   add_money("silver",1);
}