// Room: /u/swordman/yangzhou/ycsz3
inherit ROOM;

void create ()
{
  set ("short", "荷花池");
  set ("long", @LONG
你现在正站在风景秀丽，碧波荡漾的荷花池边，每年夏季，池中
荷花盛开，娇艳多姿，令无数游人驻足，更使文人墨客留恋忘返。轻风
吹来，池面泛起一阵涟漪，使你有一种想跳下去的冲动。池边是一大片
绿草坪，是门徒们休息和学习的地方。
LONG);

  set("light_up", 1);
set("sleep_room",1);
set("no_fight",0+random(1));
set("resource/water",1);
  set("outdoors", "/u/swordman");
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ycsz2",
]));

  setup();
}
void init()
{
    add_action("do_drink", "drink");
    add_action("do_drink", "he");
}

int do_drink(string sss)
{

object ob;
ob=this_player();
if ((sss!="chi")&&(sss!="shui")&&(sss!="water"))
  {
   return 0;
  }
if(ob->query("water")> ((int)ob->query("str")-10)*10+150 )
 {
  tell_object(ob,"你喝足了还要喝啊！\n");
  return 1;
 } 
else
 {  
 say(ob->query("name")+"趴在水池边，一口气喝了够饱. \n");
 tell_object(ob,"你趴在水池边，一口气喝了够饱. \n");
 ob->set("water",((int)ob->query("str")-10)*10+200);

  return 1;
 }

}
