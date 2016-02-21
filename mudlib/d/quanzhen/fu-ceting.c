// Room: /d/quanzhen/fu-ceting.c

inherit ROOM;

void create()
{
	set("short", "侧厅");
	set("long", @LONG
	这是正堂旁边的一间小厅，本来是用作书房的，只是侯员外家
实在找不出多少书来装点门面，所以就整治成了招待熟客的地方。厅中
摆放着一张八仙桌和几把椅子，桌上刚沏好的茶还在冒着热气。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/hangzhou/npc/man.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fu-huating",
  "west" : __DIR__"fu-datang",
]));

	setup();
	replace_program(ROOM);
}
