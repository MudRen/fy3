// Room: /d/emei/cangjinge.c

inherit ROOM;

void create()
{
	set("short", "藏经楼");
	set("long", @LONG
该楼依山而建,居高临下,是全寺的最高点,楼中藏有该寺自建寺以来
所收藏的各种佛家典籍,有许多已是孤本,千金难求,当然,这些经书寺内
秘不示人,寻常人是见不到的.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/daoming.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"qifodian",
]));

	setup();
	replace_program(ROOM);
}
