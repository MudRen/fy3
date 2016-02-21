// damen.c 大门


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "全真教大门");
	set("long", @LONG
	这里是全真教重阳宫的大门，两扇漆红大门开启着，气势不凡。门
上挂着一块匾(bian)，门前的石柱上挂着一副对联(duilian)。
LONG
	);

	set("exits", ([
		"east" : __DIR__"datang1",
		"westdown" : __DIR__"jiaobei",
	]));

	set("item_desc", ([
        "bian": HIG"
＊＊＊＊＊＊＊＊＊＊＊＊＊
＊＊　　　　　　　　　＊＊
＊＊　全　真　古　教  ＊＊
＊＊　　　　　　　　　＊＊
＊＊＊＊＊＊＊＊＊＊＊＊＊
\n"NOR,
	"duilian": BLINK+HIW"
一生二二生三三生万物\n
地法天天法道道法自然
\n"NOR
	]) );

	set("objects",([
		__DIR__"npc/zhike" : 1,
	]));

	setup();
	replace_program(ROOM);
}