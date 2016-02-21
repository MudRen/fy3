// Room: /u/swordman/yangzhou/wuguan1
inherit ROOM;

void create ()
{
  set ("short", "武馆大厅");
  set ("long", @LONG
扬州武馆的内堂，一切都安安静静，屋里没有点烛，什么也看不清楚。
隐约看到两排长椅，在两旁有几个弟子站着。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wuguan",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lidayong" : 1,
]));

  setup();
}
