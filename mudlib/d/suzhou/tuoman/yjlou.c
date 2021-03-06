// Room: /d/suzhou/tuoman/yjlou.c

inherit ROOM;

void create()
{
	set("short", "云锦楼");
	set("long", @LONG
你穿过花林，过石桥，穿小径，来到一座小楼之前。但见小楼檐下一块匾额，
写着“云锦楼”三个墨绿篆字，楼下前后左右种的都是茶花。但这些茶花不过是
三四流货色，和这精致的楼阁亭榭相比，未免不衬。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north":__DIR__"ru1",
		"up" :__DIR__"loushang",
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
