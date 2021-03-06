// Room: /u/swordman/yangzhou/guangchang.c

inherit ROOM;

void create ()
{
  set ("short", "中央广场");
  set ("long", @LONG
这里是城市的正中心，一个很宽阔的广场，铺着青石地面。一些游手好闲
的人在这里溜溜达达，经常有艺人在这里表演。中央有一棵大榕树，盘根错节，
据传已有千年的树龄，是这座城市的历史见证。你可以看到北边有来自各地的
行人来来往不时地传来朗朗的读书声，西边则见不到几个行人，一片肃静。 
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shusheng.c" : 1,
  __DIR__"npc/liumang" : 2,
]));
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ddajie",
  "west" : __DIR__"xijie",
  "north" : __DIR__"beijie",
  "south" : __DIR__"nandaj1",
]));
  set("outdoors", "/u/swordman");
  set("light_up", 1);

  setup();
}
