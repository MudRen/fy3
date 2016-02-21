// Room: /d/jinling/duchang.c

inherit ROOM;

void create ()
{
  set ("short", "明窝堂-地黄厅");
  set ("long", @LONG
原来这里是一个大赌场，场里笑声哭声叫骂声，加上烟味酒味脂粉味
混乱到了极点。北边斗鸡，东面压签，西边骰子，楼上赛龟。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dashou1.c" : 2,
]));
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"duchang2.c",
  "east" : __DIR__"duchang1.c",
  "up" : __DIR__"duchang4.c",
  "south" : __DIR__"mingwotang.c",
]));

  setup();
}
