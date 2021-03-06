// Room: /d/kaifeng/road3.c

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
御街是条横贯南北的大街道，也是皇帝出巡时的要道。两边的店铺
楼阁不断，实是人间一景。抬眼望去，层层鳞鳞的房屋望不到尽头。西
面是座大的府第『天波扬府』.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fujiazi.c" : 1,
]));
	set("outdoors", "/d/kaifeng");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ciqi",
  "west" : __DIR__"yangfu",
  "south" : __DIR__"road2",
  "northup" : __DIR__"road4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
