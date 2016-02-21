// Room: /d/kaifeng/jiedao.c

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
这条道横贯南北，北到宣德门，南至南盈门，是以前皇上出巡时
常走的道，所以修得是格外平整。道两边店铺不断。向南过去不远。就
是开封府大堂。北面是大相国寺。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiedao1",
  "north" : __DIR__"xianguosi",
]));
	set("outdoors", "/d/kaifeng");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/fujiazi.c" : 1,
  __DIR__"npc/qigai.c" : 1,
	"/npc/man3":2,
]));

	setup();
	replace_program(ROOM);
}
