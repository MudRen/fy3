// Room: /d/city2/bridge2.c

inherit ROOM;

void create()
{
	set("short", "桥底西侧");
	set("long", @LONG
这里是小桥西侧，一股寒风吹过，冷得你瑟瑟发抖，只想离开。
桥底下是急冲而过的流水,远远能看到红色的宫墙.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qigai.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "eastup" : __DIR__"bridge",
]));
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

	setup();
	replace_program(ROOM);
}
