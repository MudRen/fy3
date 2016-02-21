// Room: /d/huanggon/ndajie1.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
北大街横贯东西,从皇宫的后门穿过.这条街道位于京城的北面,店铺
较少,所住的都是些穷苦人.来往的人多面带菜色.街道北面是家肉庄,伙计
们在店中大声吆喝生意.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/huanggon");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"ndajie",
  "west" : __DIR__"guangchang1",
  "north" : __DIR__"qianrouzhuang",
]));

	setup();
	replace_program(ROOM);
}
