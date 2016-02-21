// Room: /d/robber/hill.c

inherit ROOM;

void create()
{
	set("short", "小土岗");
	set("long", @LONG
稍高于平地的一个小土岗,到处是杂草,草丛中散落着一些黄表纸,不远
处树上的一只老鸦[嘎嘎]地叫起来,你心头蒙上一层阴影.南面是一条黄
泥小路.
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"mudroad1",
  "north" : __DIR__"tomb",
]));

	setup();
	replace_program(ROOM);
}
