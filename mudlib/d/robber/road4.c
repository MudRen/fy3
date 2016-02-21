// Room: /d/robber/road4.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
一条足可容四马并驰的大路，来往的人多行色匆匆，东面不远，两山
对峙，山势险峻，山口处设了关卡。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road3",
]));
	set("outdoors", "/d/jiangnan");
	set("objects",([
		"/npc/man3":2,
	]));

	setup();
	replace_program(ROOM);
}
