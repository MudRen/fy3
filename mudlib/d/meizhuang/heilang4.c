// Room: /d/suzhou/meizhuang/heilang4.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
一条四周梅树环绕的走廊。头顶上是由琉璃青瓦铺盖而成的廊檐，可
遮风蔽雨。两侧梅树随风轻摆，不时送来阵阵清香。东面一条走廊通往侧
院。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"heilang5",
  "west" : __DIR__"heilang6",
  "east" : __DIR__"zoulang",
]));
	set("no_clean_up", 0);
	set("outdoors", "meizhuang");

	setup();
	replace_program(ROOM);
}
