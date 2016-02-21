// Room: /d/quanzhou/duchuan 
inherit ROOM; 
 
void create ()
{
  set ("short", "楼船");
  set ("long", @LONG
一艘三层高的楼船,两支大白帆鼓足了风,几个水手正忙着起锚,船并
不雕龙画凤,却显得格外结实,正是那种经得起大风浪的海船.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chuanfu.c" : 1,
]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("outdoors", "/d/quanzhou");

  setup();
}
void init()
{
  if (!this_player()->query_temp("luyin/target")&&this_player()->query("id")!="chuan fu")
      {  
        tell_object(this_player(),"船上有人一脚把你踹了下来.\n");
        this_player()->set_temp("block_msg/all",1);
        this_player()->move(__DIR__"haigang");
        this_player()->delete_temp("block_msg/all");
      }
 return;
}