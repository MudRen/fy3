// Room: /d/suzhou/meizhuang/caofang.c

inherit ROOM;

void create()
{
	set("short", "草亭");
	set("long", @LONG
一个小草亭，虽然简陋但四周的风景却十分怡人。庄主们时常于此饮
酒谈天。草亭中央的石几上有本大庄主亲手编制的“梅花录”，以供本庄
弟子刨诗。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"heilang1",
]));
	set("valid_startroom",1);
	set("no_clean_up", 0);
	set("outdoors", "meizhuang");

	setup();
	call_other("/obj/board/meizhuangboard","???");
	replace_program(ROOM);
}
