// Room: /d/xxy/yangwu 
inherit ROOM; 
 
void create ()
{
  set ("short", "武级考场");
  set ("long", @LONG
这是武级考场,凡比武胜过考官者,可得银牌一块,凭此可进武级宿处.
房间中空空荡荡,便于施展手脚.比武之中,若有死伤,各按天命.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/train3.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yongdao1",
]));

  setup();
}
