// Room: /d/new/huanhua/tingyulou.c

inherit ROOM;

void create()
{
	set("short", "听雨楼二楼");
	set("long", @LONG
听雨楼取名于[小楼一夜听春雨],是萧西楼平时栖息之所.楼仅二层, 
却是剑庐内最高的一栋建筑.四面的敞轩可以了望院内的一切.高高的香木 
柜摆满了各类古董,室中的桌子上摆着一副残棋. 
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/zhuxiawu.c" : 1,
  __DIR__"npc/xxilou.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tingyu",
]));

	setup();
set("valid_startroom",1);
	replace_program(ROOM);
}
