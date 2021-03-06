inherit NPC;

void create()
{
   set_name("卯兔", ({ "rabbit","tuzi" }) );
   set("race", "野兽");
   set("age", 9);
   set("long", "可爱的小兔子,长长的耳朵,亮红的眼珠.。\n");
   
   set("str", 10);
   set("cor", 24);
   set("combat_exp",15000);
   set("kee",500);
   set("max_kee",500);

   set("limbs", ({ "头部", "身体", "尾巴", "左前爪","右前爪" "左后爪","右后爪" }) );
   set("verbs", ({ "bite", "claw" }) );


   set_temp("apply/attack", 10);
   set_temp("apply/armor", 30);

   set("chat_chance",5);
   set("chat_msg",({
   "玉兔嘴边啃着一株翠绿的草,一边斜眼看着你.\n",
   "玉兔绕着石室跑了一圈,侧身蹲着不再理会你.\n",
   }));
   setup();
}

void die()
{
  message_vision("$N奋身一跳,在空中打了个滚,消失了.\n",this_object());
  new(__DIR__"obj/sparkler.c")->move(environment(this_object()));
  destruct(this_object());
  return;
}