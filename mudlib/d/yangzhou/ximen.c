// Room: /u/swordman/yangzhou/ximen
inherit ROOM;

void create ()
{
  set ("short", "扬州西门");
  set ("long", @LONG
由于这一带的劫匪比较多，官府正在剿匪，所以一般西门都不开。
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/d/quanzhou/npc/bing" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xijie2",
]));
  set("outdoors", "/u/swordman");

  setup();
}
