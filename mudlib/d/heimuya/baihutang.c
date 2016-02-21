// Room: /d/heimuya/baihutang.c

inherit ROOM;

void create()
{
	set("short", "白虎堂大厅");
	set("long", @LONG
此处是日月教第二大堂-[白虎堂],青砖铺地，正中一张猛虎图栩栩如生。
两边的兵器架上摆满了各类武器，堂内气氛肃杀，向北穿过大厅，是个池塘。
北面是条长长的走廊.
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/baihudizi.c" : 2,
  __DIR__"npc/shanggy" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"chitang",
  "north" : __DIR__"baistep2",
]));

	setup();
	replace_program(ROOM);
}
